#include <stdio.h>
#include <stdbool.h>

double stack[101];
int	top = -1;

int main(void)
{
	int N, i;
	char exp[101];
	double op[26];
	double a, b;

	scanf("%d", &N);
	scanf("%s", exp);
	i = 0;
	while (i < N)
		scanf("%lf", &op[i++]);
	i = 0;
	while (exp[i])
	{
		if (exp[i] == '*' || exp[i] == '+' || exp[i] == '-' || exp[i] == '/')
		{	
			a = stack[top--];
			b = stack[top--];
			if (exp[i] == '*')
				stack[++top] = b * a;
			else if (exp[i] == '/')
				stack[++top] = b / a;
			else if (exp[i] == '+')
				stack[++top] = b + a;
			else if (exp[i] == '-')
				stack[++top] = b - a;
		}
		else
			stack[++top] = op[exp[i] - 'A'];
		i++;
	}
	res = stack[0];
	printf("%.2f\n", res);
	return (0);
}

