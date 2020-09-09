#include <stdio.h>
#include <stdbool.h>

# define MAX 1000000

int stack[MAX];
int id_stack[MAX];
int res[MAX];
int	top = -1;

int main(void)
{
	int arr[MAX];
	int	N, index, i;
	bool flag;

	scanf("%d", &N);
	index = 0;
	while (index < N)
		scanf("%d", &arr[index++]);
	index = 0;
	i = 0;
	while (index < N)
	{
		while (top >= 0 && stack[top] < arr[index])
		{
			res[i] = arr[index];
			top--;
			i++;
		}
		
		stack[++top] = arr[index];
		index++;
	}
	res[i] = -1;
	i = 0;
	while (i < N)
		printf("%d ", res[i++]);
	printf("\n");
}
