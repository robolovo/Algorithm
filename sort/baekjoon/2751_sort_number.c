#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) 
{
	return (*(int *)a - *(int *)b);
}

int main(void)
{
	int N, i;
	int array[1000000];

	scanf("%d", &N);
	i = 0;
	while (i < N)
		scanf("%d", &array[i++]);
	qsort(array, N, sizeof(int), cmp);
	i = 0;
	while (i < N)
		printf("%d\n", array[i++]);
}
