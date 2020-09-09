#include "heap.h"

int	heap_init(t_heap *heap, unsigned int max_size, int (*cmp)(void *, void*))
{
	heap->max_size = max_size;
	heap->size = 0;
	heap->cmp = cmp;
	if (!(heap->data = malloc(sizeof(void *) * (max_size + 1))))
	{
		free(heap);
		return (0);
	}
	return (1);
}

int	heap_push(t_heap *heap, void *data)
{
	int 	i;
	void	*temp;

	if (!heap || heap->size >= heap->max_size)
		return (0);
	i = ++heap->size;
	heap->data[i] = data;
	while (i / 2 > 0 && heap->cmp(heap->data[i / 2], heap->data[i]) > 0)
	{
		temp = heap->data[i / 2];
		heap->data[i / 2] = heap->data[i];
		heap->data[i] = temp;
		i /= 2;
	}
	return (1);
}

void	*heap_pop(t_heap *heap)
{
	void	*rtn, *temp;
	int		Parent, leftChild, rightChild;
	int		i, ret;

	if (!heap || heap->size < 1)
		return (0);
	rtn = heap->data[1];
	heap->data[1] = heap->data[heap->size--];
	i = 1;
	while (1)
	{
		if (i == heap->size)
			break;
		Parent = i;
		leftChild = 2 * Parent;
		rightChild = 2 * Parent + 1;
		if (leftChild <= heap->size && rightChild <= heap->size)
			ret = heap->cmp(heap->data[leftChild], heap->data[rightChild]) < 0 ? leftChild : rightChild;
		else if (leftChild <= heap->size)
			ret = leftChild;
		if (heap->cmp(heap->data[Parent], heap->data[ret]) > 0)
		{
			temp = heap->data[Parent];
			heap->data[Parent] = heap->data[ret];
			heap->data[ret] = temp;
			i = ret;
		}
		else
			break;
	}
	return (rtn);
}

int heap_sort(void **items, int size, int (*cmp)(void *, void *))
{
	t_heap 	heap;
	int		i;
	int		c, root;
	void	*temp;

	heap_init(&heap, size, cmp);
	i = 0;
	while (i < size)
	{	
		heap_push(&heap, items[i]);
		i++;
	}
	i = 0;
	while (i < size)
	{
		items[i] = heap_pop(&heap);
		i++;
	}
	return (0);
}
