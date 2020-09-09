#include <stdio.h>
#include <stdlib.h>

typedef struct s_heap
{
	unsigned int 	max_size;
	unsigned int 	size;
	int				*data;
}					t_heap;

t_heap *heap_init()
{
	t_heap	*heap;

	if (!(heap = (t_heap *)malloc(sizeof(t_heap))))
		return (0);
	heap->max_size = 100000;
	heap->size = 0;
	if (!(heap->data = malloc(sizeof(int) * (heap->max_size + 1))))
	{
		free(heap);
		return (0);
	}
	return (heap);
}

void	heap_push(t_heap *heap, int data)
{
	int i;
	int ret;
	int temp;

	i = ++heap->size;
	heap->data[i] = data;
	if (i == 1)
		return ;
	while (i / 2 > 0 && abs(heap->data[i / 2]) >= abs(heap->data[i]))
	{
		if (abs(heap->data[i / 2]) == abs(heap->data[i]))
		{	
			if (heap->data[i / 2] < heap->data[i])
				break;
		}
		temp = heap->data[i / 2];
		heap->data[i / 2] = heap->data[i];
		heap->data[i] = temp;
		i /= 2;
	}
}

void	heap_pop(t_heap *heap)
{
	int parent, left, right;
	int ret, rtn, i, temp;

	if (heap->size == 0)
	{
		printf("0\n");
		return ;
	}
	rtn = heap->data[1];
	heap->data[1] = heap->data[heap->size--];
	i = 1;
	while (2 * i <= heap->size)
	{
		parent = i;
		left = 2 * parent;
		right = 2 * parent + 1;
		if (left <= heap->size && right <= heap->size)
		{
			if (abs(heap->data[left]) == abs(heap->data[right]))
				ret = heap->data[left] <= heap->data[right]	? left : right;
			else		
				ret = abs(heap->data[left]) < abs(heap->data[right]) ? left : right;
		}
		else if (left <= heap->size && right > heap->size)
			ret = left;
		if ((abs(heap->data[parent]) == abs(heap->data[ret]) && 
			heap->data[parent] < heap->data[ret]) || (abs(heap->data[parent]) < abs(heap->data[ret])))
			break;
		temp = heap->data[parent];
		heap->data[parent] = heap->data[ret];
		heap->data[ret] = temp;
		i = ret;
	}
	printf("%d\n", rtn);
}

int main(void)
{
	t_heap	*heap;
	int	N, x;

	scanf("%d", &N);
	getchar();
	heap = heap_init();
	while(N--)
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
