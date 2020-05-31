/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtriston <mtriston@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 23:09:07 by mtriston          #+#    #+#             */
/*   Updated: 2020/05/09 17:10:14 by mtriston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;

	if (!s)
		return (NULL);
	if (ft_strlen(s) <= start)
		return (substr = ft_calloc(1, sizeof(char)));
	if (len > ft_strlen(s) - start)
			len = ft_strlen(s) - start;
	if (!(substr = malloc((len + 1) * sizeof(char))))
		return (NULL);
	ft_strlcpy(substr, s + start, len + 1);
	return (substr);
}
