#include "quick.h"

void	sort(void **items, int start, int end, int (*cmp)(void *, void *))
{
	int		pivot, i, j;
	void	*temp;

	if (start >= end)
		return ;
	pivot = start;
	i = start + 1;
	j = end;
	while (i <= j)
	{
		while (i <= end && cmp(items[i], items[pivot]) <= 0)
			i++;
		while (cmp(items[j], items[pivot]) >= 0 && j > start)
			j--; 
		if (i > j)
		{
			temp = items[j];
			items[j] = items[pivot];
			items[pivot] = temp; 
		}
		else
		{
			temp = items[j];
			items[j] = items[i];
			items[i] = temp;
		}
	}
	sort(items, start, j - 1, cmp);
	sort(items, j + 1, end, cmp);
}

int	quick_sort(void **items, int size, int (*cmp)(void *, void *))
{
	if (!items || size < 1 || !cmp)
		return (0);	
	sort(items, 0, size - 1, cmp);
	return (1);
}				
