/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtriston <mtriston@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 16:16:14 by mtriston          #+#    #+#             */
/*   Updated: 2020/10/31 14:52:06 by mtriston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static int	check_over(char *over, char **new_line_ptr, char **line)
{
	char	*temp;

	*new_line_ptr = NULL;
	if ((*new_line_ptr = ft_strchr(over, '\n')))
	{
		**new_line_ptr = '\0';
		if (**line)
		{
			temp = *line;
			*line = ft_strjoin(temp, over);
			free_gc(temp);
		}
		else
			*line = ft_strdup(over);
		ft_strcpy(over, ++(*new_line_ptr));
	}
	else
	{
		if (*line == NULL)
			*line = ft_strdup(over);
		else
		{
			temp = *line;
			*line = ft_strjoin(temp, over);
			free_gc(temp);
		}
		ft_bzero(over, BUFFER_SIZE);
	}
	return (1);
}

int			get_next_line(int fd, char **line)
{
	static char	over[BUFFER_SIZE + 1];
	char		buf[BUFFER_SIZE + 1];
	char		*new_line_ptr;
	char		*temp;
	int			read_bytes;

	read_bytes = 1;
	if (BUFFER_SIZE < 1 || fd < 0 || !line || (read(fd, buf, 0) != 0) || \
	!(check_over(over, &new_line_ptr, line)))
		return (-1);
	while (!new_line_ptr && ((read_bytes = read(fd, buf, BUFFER_SIZE)) > 0))
	{
		buf[read_bytes] = '\0';
		if ((new_line_ptr = ft_strchr(buf, '\n')))
		{
			*new_line_ptr = '\0';
			ft_strcpy(over, ++new_line_ptr);
		}
		temp = *line;
		if (!(*line = ft_strjoin(*line, buf)))
			return (-1);
		free_gc(temp);
	}
	return ((ft_strlen(over) || read_bytes > 0) ? 1 : read_bytes);
}
