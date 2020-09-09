#include <stdio.h>

char stack[101];
int top = -1;

int main(void)
{
	char form[101];
	char res[101];
	int i, j;

	scanf("%s", form);
	i = 0;
	j = 0;
	while (form[i])
	{
		if (form[i] >= 'A' && form[i] <= 'Z')
		{
			res[j] = form[i];
			j++;
		}
		else
		{	
			stack[++top] = form[i];
			if (form[i] == ')')
			{	
				top--;
				while (stack[top] != '(')	
				{	
					res[j] = stack[top];
					j++;
					top--;
				}
				top--;
			}
		}
		i++;
	}
	while (top >= 0)
	{	
		res[j] = stack[top];
		top--;
		j++;
	}
	res[j] = '\0';
	printf("%s\n", res);
	return(0);
}
