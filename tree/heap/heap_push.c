#include "heap.h"

int	heap_push(t_heap *heap, void *data)
{	
	int		i;
	int		ret;
	void	*temp;

	if (!heap || heap->size >= heap->max_size)
		return (0);
	i = ++heap->size;
	heap->data[i] = data;
	if (i == 1)
		return (1);
	while (i / 2 > 0 && heap->cmp(heap->data[i / 2], heap->data[i]) > 0)
	{
		temp = heap->data[i / 2];
		heap->data[i / 2] = heap->data[i];
		heap->data[i] = temp;
		i /= 2;
	}
	return (1);
}
