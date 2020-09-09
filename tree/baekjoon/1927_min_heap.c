#include <stdio.h>
#include <stdlib.h>

typedef struct s_heap
{
	unsigned int 	max_size;	
	unsigned int	size;
	int				*data;
}				t_heap;

int	cmp(int a, int b)
{
	return (a - b);
}

t_heap	*heap_init()
{
	t_heap	*heap;

	if (!(heap = malloc(sizeof(t_heap))))
		return (0);
	heap->size = 0;
	heap->max_size = 100001;
	if (!(heap->data = malloc(sizeof(int) * heap->max_size)))
	{
		free(heap);
		return (0);
	}
	return (heap);
}

int	heap_push(t_heap *heap, int data)
{
	int		i;
	int		ret;
	int		temp;

	if (!heap || heap->size >= heap->max_size)
		return (0);
	i = ++heap->size;
	heap->data[i] = data;
	if (i == 1)
		return (1);
	while (i / 2 > 0 && cmp(heap->data[i / 2], heap->data[i]) > 0)
	{
		temp = heap->data[i / 2];
		heap->data[i / 2] = heap->data[i];
		heap->data[i] = temp;
		i /= 2;
	}
	return (1);
}

void	heap_pop(t_heap *heap)
{
	int		rtn;
	int		temp;
	int		Parent;
	int		leftChild;
	int		rightChild;
	int		i;
	int		ret;
	
	if (heap->size < 1)
	{
		printf("0\n");
		return ;
	}
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
		if (cmp(heap->data[Parent], heap->data[ret]) > 0)
		{
			temp = heap->data[Parent];
			heap->data[Parent] = heap->data[ret];
			heap->data[ret] = temp;
			i = ret;
		}
		else
			break;
	}
	printf("%d\n", rtn);
}

int	main(void)
{
	t_heap	*heap;
	int	N, x;

	heap = heap_init();
	scanf("%d", &N);
	getchar();
	while (N--)
	{
		scanf("%d", &x);
		getchar();
		if (x == 0)
			heap_pop(heap);
		else
			heap_push(heap, x);
	}
	return (0);
}
