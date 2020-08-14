#include "libft.h"

void	*malloc_gc(size_t size)
{
	void *ptr;

	ptr = malloc(size);
	memory_manager(ptr, ADD);
	return (ptr);
}

void	*calloc_gc(size_t nmemb, size_t size)
{
	void *ptr;

	ptr = ft_calloc(nmemb, size);
	memory_manager(ptr, ADD);
	return (ptr);
}	
