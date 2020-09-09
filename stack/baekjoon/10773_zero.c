#include <stdio.h>

int main(void)
{
	int	K, num, i = 0, sum = 0;
	int stack[100001];
	int top = 0;

	scanf("%d\n", &K);
	while (K--)
	{
		scanf("%d", &num);
		if (num == 0)
			stack[top--] = 0;
		else
			stack[top++] = num;
	}
	while (i < top)
		sum += stack[i++];
	printf("%d\n", sum);
	return (0);
}
