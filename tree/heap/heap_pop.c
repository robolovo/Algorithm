#include "heap.h"

void	*heap_pop(t_heap *heap)
{
	void	*rtn;
	void	*temp;
	int		Parent;
	int		leftChild;
	int		rightChild;
	int		i;
	int		ret;

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
			ret = heap->data[leftChild] <= heap->data[rightChild] ? leftChild : rightChild;
		else if (leftChild <= heap->size && rightChild > heap->size)
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
/*
void print_heap(t_heap *heap)
{
		for (unsigned int i = 1; i <= heap->size; ++i) {
				printf("%u -> %d\n", i, *(int *)heap->data[i]);
		}
		printf("\n");
}

int cmp(void *a, void *b)
{
		return (*(int *)a - *(int *)b);
}

void free_data(void *a)
{
		printf("free %d\n", *(int *)a);
}

int	main(void)
{
	t_heap	*heap;
	int data[101];

	for (int i = 1; i <= 100; i++) 
		data[i] = i;
	
	heap = heap_init(10, cmp);
	
	heap_push(heap, &data[13]);
	heap_push(heap, &data[17]);
	heap_push(heap, &data[76]);
	heap_push(heap, &data[88]);
	heap_push(heap, &data[35]);
	heap_push(heap, &data[100]);
	printf("heap_size: %d\n", heap->size);
	print_heap(heap);
	heap_pop(heap);
	printf("heap_size: %d\n", heap->size);
	print_heap(heap);
}*/
