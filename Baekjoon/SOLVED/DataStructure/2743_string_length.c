#include <stdio.h>

int main(void)
{
	char str[101];
	int i;

	scanf("%s", str);
	i = 0;
	while (str[i])
	{
		i++;
	}
	printf("%d\n", i);
	return (0);
}
