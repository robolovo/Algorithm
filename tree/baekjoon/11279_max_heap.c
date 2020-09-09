#include <stdio.h>
#include <stdlib.h>

typedef struct s_heap
{
	unsigned int	max_size;	
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
	heap->max_size = 100001;
	heap->size = 0;
	if (!(heap->data = malloc(sizeof(t_heap) * heap->max_size)))
	{
		free(heap);
		return (0);
	}
	return (heap);
}

void	heap_push(t_heap *heap, int data)
{
	int	i;
	int	ret;
	int	temp;

	i = ++heap->size;
	heap->data[i] = data;
	if (i == 1)
		return ;
	while (i / 2 > 0 && cmp(heap->data[i], heap->data[i / 2]) > 0)
	{
		temp = heap->data[i / 2];
		heap->data[i / 2] = heap->data[i];
		heap->data[i] = temp;
		i /= 2;
	}
}

void	heap_pop(t_heap *heap)
{
	int	parent;
	int	left;
	int	right;
	int temp;
	int ret;
	int rtn;
	int	i;

	if (heap->size == 0)
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
		parent = i;
		left = 2 * parent;
		right = 2 * parent + 1;
		if (left <= heap->size && right <= heap->size)
			ret = heap->data[left] >= heap->data[right] ? left : right;
		else if (left <= heap->size && right > heap->size)
			ret = left;
		if (cmp(heap->data[ret], heap->data[parent]) > 0)
		{
			temp = heap->data[parent];
			heap->data[parent] = heap->data[ret];
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

	scanf("%d", &N);
	getchar();
	heap = heap_init();
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
