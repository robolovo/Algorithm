#include <stdio.h>

int main(void)
{
	int	 alphabet[26];
	char str[101];
	int		i;

	scanf("%s", str);

	i = 0;
	while (i < 26)
	{
		alphabet[i] = 0;
		i++;
	}
	
	i = 0;
	while (str[i])
	{
		alphabet[str[i] - 'a'] += 1;
		i++;
	}

	i = 0;
	while (i < 26)
		printf("%d ", alphabet[i++]);
	printf("\n");
	return (0);
}
