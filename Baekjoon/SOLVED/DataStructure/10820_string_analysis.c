#include <stdio.h>

int main(void)
{
	char str[101][101];
	int	n, i, j;
	int space, num, small_a, big_a;

	n = 0;
	while (gets(str[n]))
		n++;
	
	i = 0;
	while (i < n)
	{
		small_a = 0;
		big_a = 0;
		space = 0;
		num = 0;
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] >= 'A' && str[i][j] <= 'Z')
				big_a++;
			else if (str[i][j] >= 'a' && str[i][j] <= 'z' )
				small_a++;
			else if (str[i][j] >= '0' && str[i][j] <= '9')
				num++;
			else
				space++;
			j++;	
		}
		printf("%d %d %d %d", small_a, big_a, num, space);
		printf("\n");
		i++;
	}
	return (0);
}
