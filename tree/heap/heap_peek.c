#include "heap.h"

void	*heap_peek(t_heap *heap)
{
	if (!heap || heap->size < 1)
		return (0);
	return (heap->data[1]);
}
