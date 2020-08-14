#include "libft.h"

void	free_gc(void *ptr)
{
	memory_manager(ptr, M_REMOVE);
}
