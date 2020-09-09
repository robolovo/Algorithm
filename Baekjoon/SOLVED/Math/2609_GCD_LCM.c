#include <stdio.h>

int main(void)
{
	int num1, num2;
	int min, max;

	scanf("%d %d", &num1, &num2);
	
	max = num1 > num2 ? num2 : num1;
	min = num1 > num2 ? num1 : num2;

	while (1)
	{
		if (num1 % max == 0 && num2 % max == 0)
			break;
		max--;
	}

	while (1)
	{
		if (min % num1 == 0 && min % num2 == 0)
			break;
		min++;
	}

	printf("%d\n", max);
	printf("%d\n", min);
	return (0);
}
