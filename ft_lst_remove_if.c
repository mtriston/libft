#include "libft.h"

void	ft_lst_remove_if(t_list **root, void *data, int (*cmp)(), void (*del)());
{
	t_list *node;
	t_list *temp;
	t_list *prev;

	node = *root;
	prev = node;
	while (node != NULL)
	{
		if (cmp(data, node->content) == 0)
		{
			temp = node;
			if (node == *root)
				*root = node;
			else
				prev->next = node->next;
			ft_lstdelone(temp, del);
		}
		else
			prev = prev->next;
		node = node->next;
	}
}
