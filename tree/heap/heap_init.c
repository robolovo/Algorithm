#include "heap.h"

t_heap *heap_init(unsigned int max_size, int (*cmp)(void *, void *))
{
	t_heap	*heap;

	if (max_size < 1 || !cmp)
		return (0);
	if (!(heap = (t_heap *)malloc(sizeof(t_heap))))
		return (0);
	heap->max_size = max_size;
	heap->size = 0;
	heap->cmp = cmp;
	if (!(heap->data = (void **)malloc(sizeof(void *) * (max_size + 1))))
	{
		free(heap);
		return (0);
	}
	return (heap);
}
