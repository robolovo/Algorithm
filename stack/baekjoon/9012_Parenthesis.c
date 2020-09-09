#include <stdio.h>

int	get_topIndex(char *stack)
{
	int idx;

	idx = 0;
	while (stack[idx])
		idx++;
	return (idx);
}

int main(void)
{
	char stack[51];
	int top;
	int	N, i;

	scanf("%d", &N);
	while (N--)
	{
		scanf("%s", stack);
		top = get_topIndex(stack);
		i = top;
		while (1 <= i)
		{	
			if (stack[i] == ')' && stack[i - 1] == '(')
			{	
				stack[i] = '\0';
				stack[i - 1] ='\0';
				while (i <= top)	
				{	
					stack[i - 1] = stack[i + 1];
					i++;
				}
				top -= 2;
				i = top;
			}
			else
				i--;
		}
		if (stack[0] == '(' || stack[0] == ')')
			printf("NO\n");
		else
			printf("YES\n");	
	}
	return (0);
}
