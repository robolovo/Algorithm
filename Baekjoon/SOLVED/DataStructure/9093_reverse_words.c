#include <stdio.h>

char stack[20];
int	 top_index;
char	to_print[1001];
int	print = 0;

void	stack_init()
{
	for (int i = 0; i < 20; i++)
		stack[i] = 0;
}

int get_space_num(char *str)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == 32)
			count++;
		i++;
	}
	return (count);
}

int main(void)
{
	char str[1001];
	int count, N;
	int i, j, k;

	scanf("%d", &N);
	getchar();
	for (int n = 0; n < N; n++)
	{
		gets(str);
		count = get_space_num(str);
		i = 0;
		k = 0;
		print = 0;
		while (i < count + 1)
		{
			j = 0;
			while (1)
			{
				if (str[k] == 32 || str[k] == '\0')
				{
					k++;
					j--;
					break;
				}
				stack[j] = str[k];
				j++;
				k++;
			}
			top_index = j;
			while (top_index >= 0)
			{
				to_print[print] = stack[top_index];
				top_index--;
				print++;
			}
			to_print[print++] = ' ';
			if (i == count)
				to_print[print] = '\0';
			stack_init();
			i++;
		}
		printf("%s\n", to_print);
	}
	return (0);
}
