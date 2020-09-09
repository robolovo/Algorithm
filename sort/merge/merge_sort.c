#include "merge.h"

void	merge(void **items, int m, int middle, int n, int (*cmp)(void *, void *))
{
	int 	i, j, k;
	void	**sorted;

	sorted = malloc(sizeof(void *) * (n));

	i = m;
	j = middle + 1;
	k = m;

	while (i <= middle && j <= n)
	{
		if (cmp(items[i], items[j]) <= 0)
		{
			sorted[k] = items[i];
			i++;
		}
		else
		{
			sorted[k] = items[j];
			j++;
		} 
		k++;
	}

	if (i > middle)
	{
		for (int t = j; t <= n; t++)
		{
			sorted[k] = items[t];
			k++;
		}	
	}
	else
	{
		for (int t = i; t <= middle; t++)
		{
			sorted[k] = items[t];
			k++;
		}
	}

	for (int t = m; t <= n; t++)
		items[t] = sorted[t]; 
}

void	sort(void **items, int m, int n, int (*cmp)(void *, void *))
{
	int middle;

	if (m < n)
	{
		middle = (m + n) / 2; 
		sort(items, m, middle, cmp);
		sort(items, middle + 1, n, cmp);
		merge(items, m, middle, n, cmp);
	}
} 

int	merge_sort(void **items, int size, int (*cmp)(void *, void *))
{
	if (!items || size < 1 || !cmp)	
		return (0);
	sort(items, 0, size - 1, cmp);
	return (1);
}
