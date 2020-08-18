/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtriston <mtriston@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 23:32:18 by mtriston          #+#    #+#             */
/*   Updated: 2020/08/18 23:23:43 by mtriston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static void		lstdelone(t_list *lst, void (*del)(void*))
{
	if (lst != NULL)
	{
		del(lst->content);
		free(lst);
	}
}

static t_list	*lstnew(void *content)
{
	t_list *elem;

	if (!(elem = malloc(sizeof(t_list))))
		return (NULL);
	elem->content = content;
	elem->next = NULL;
	return (elem);
}

static int		ptr_cmp(void *ptr1, void *ptr2)
{
	return (ptr1 != ptr2);
}

void			memory_manager(void *ptr, int action)
{
	static t_list *collector = NULL;

	if (ptr == NULL)
		ft_lstclear(&collector, &free);
	else if (action == ADD)
		ft_lstadd_front(&collector, lstnew(ptr));
	else if (action == REMOVE)
		ft_lst_remove_if(&collector, ptr, &ptr_cmp, &lstdelone);
}
