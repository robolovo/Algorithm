#include "heap.h"

void	free_heap(t_heap *heap, void (*free_data)(void *))
{
	int	i;

	if (!heap || !free_data)
		return ;
	i = 1;
	while (heap->data[i])
	{
		free_data(heap->data[i]);
		i++;
	}
	free(heap_data);
	free(heap);
}
