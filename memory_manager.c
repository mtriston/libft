#include "libft.h"

static int	ptr_cmp(void *ptr1, void *ptr2)
{
	return (ptr1 != ptr2);
}

void		memory_manager(void *ptr, t_bool action)
{
	static t_list *collector = NULL;

	if (ptr == NULL)
		ft_lstclear(&collector, &pointer_free);
	else if (action == M_ADD)
		ft_lstadd_front(&collector, ft_lstnew(ptr));
	else if (action == M_REMOVE)
		ft_lst_remove_if(&collector, ptr, &ptr_cmp, &ft_lstdelone)
}
