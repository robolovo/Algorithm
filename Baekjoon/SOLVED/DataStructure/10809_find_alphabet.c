#include <stdio.h>

int main(void)
{
	int	alpha[26];
	char str[101];
	int i;

	scanf("%s", str);
	
	i = 0;
	while (i < 26)
	{
		alpha[i] = -1;
		i++;
	}

	i = 0;
	while (str[i])
	{
		if (alpha[str[i] - 'a'] == -1)	
			alpha[str[i] - 'a'] = i;
		i++;
	}

	i = 0;
	while (i < 26)
	{	
		printf("%d ", alpha[i]);
		i++;
	}
	printf("\n");
	return (0);
}
