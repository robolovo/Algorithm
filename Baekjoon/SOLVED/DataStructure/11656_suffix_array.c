#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *a, const void *b)
{
	return (strcmp((char *)a, (char *)b));
}

int main(void)
{
	char str[1001];
	int i, j, len;

	scanf("%s", str);
	
	len = strlen(str);

	char suffix_arr[len][len + 1];

	i = 0;
	while (i < len)
	{
		j = 0;	
		while (i + j < len)	
		{	
			suffix_arr[i][j] = str[i + j];
			j++;
		}
		suffix_arr[i][j] = '\0';
		i++;
	}

	qsort(suffix_arr, sizeof(suffix_arr) / sizeof(suffix_arr[0]), sizeof(suffix_arr[0]), cmp);

	i = 0;
	while (i < len)
		printf("%s\n", suffix_arr[i++]);
	return (0);
}
