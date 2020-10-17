/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc_gc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtriston <mtriston@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 13:07:34 by mtriston          #+#    #+#             */
/*   Updated: 2020/10/17 13:34:38 by mtriston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

void	*realloc_gc(void *ptr, size_t size)
{
	size_t	old_size;
	void	*new_ptr;

	if (ptr == NULL)
		return (malloc_gc(size));
	old_size = sizeof(ptr);
	if (old_size >= size)
		return (ptr);
	new_ptr = malloc_gc(size);
	ft_memcpy(new_ptr, ptr, old_size);
	free_gc(ptr);
	return (new_ptr);
}
