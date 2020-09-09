#include <stdio.h>

char 	stack[100001];
int		top_index = -1;
int		size = 0;

int main(void)
{
	char 	input[100001];
	int		num_bar = 0;

	scanf("%s", input);
	getchar();

	int i = 0;
	while (input[i])
	{
		if (input[i] == '(' && input[i + 1] != ')')
		{
			stack[++top_index] = input[i];
			num_bar++;
		}
		else if (input[i] == '(' && input[i + 1] == ')')
		{
			stack[++top_index] = input[i];
		}
		else if (input[i] == ')' && input[i - 1] == '(')
		{
			if (top_index >= 0)
				top_index--;
			size = top_index + 1;
			num_bar += size;
		}
		else if (input[i] == ')' && input[i - 1] != '(')
		{
			top_index--;
		}
		i++;
	}
	printf("%d\n", num_bar);
	return (0);
}
