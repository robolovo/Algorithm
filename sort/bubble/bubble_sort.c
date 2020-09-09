#include <stdio.h>
#include <stdlib.h>

void	bubble_sort(void **items, int size, int (*cmp)(void *, void *))
{
	void	*temp;
	int		i, j;

	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (cmp(items[j], items[j + 1]) > 0)
			{
				temp = items[j];
				items[j] = items[j + 1];
				items[j + 1] = temp;
			}
		}
	}
}
