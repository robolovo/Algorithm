#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int 	front;
int 	deque[200001];
char	command[100001];
char	array[200001];

void	reverse_array(int last)
{
	int i;
	int arr[200001];

	i = 0;
	while (i <= last)
	{	
		arr[i] = deque[i];
		i++;
	}
	i = 0;
	while (i <= last)
	{	
		deque[i] = arr[last - i];
		i++;
	}
}

int		pop_front(int size)
{
	if (size == 0)
		return (-1);
	deque[front] = '\0';
	front++;
	return (--size);
}

int main(void)
{
	int 	T, i, size, tmp_size, flag;

	scanf("%d", &T);
	while (T--)
	{
		flag = 1;
		front = 0;	
		scanf("%s %d %s", command, &size, array);
		if (size > 0)
		deque[0] = atoi(strtok(array, "[,]"));
		i = 1;
		while (i < size)
			deque[i++] = atoi(strtok(NULL, "[,]"));
		i = 0;
		while (command[i] != '\0')
		{
			if (command[i] == 'R')
				reverse_array(size - 1);
			else if (command[i] == 'D')
			{	
				tmp_size = pop_front(size);
				if (tmp_size == 0 || size == 0)
				{	
					printf("error\n");
					flag = 0;
					break;
				}
			}
			i++;
		}
		if (flag)
		{
			printf("[");
			for (int j = front; j < size ; j++)
			{	
				printf("%d", deque[j]);
				if (j != size - 1)
					printf(",");
			}
			printf("]\n");
		}
	}
}
