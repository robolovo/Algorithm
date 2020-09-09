#include <stdio.h>
#include <stdlib.h>

int	get_length(char *s)
{
	int i = 0;

	while (s[i])
		i++;
	return (i);
}

int cmp(const void *a, const void *b)
{
	return (*(char *)b - *(char *)a);
}

int main(void)
{
	char number[11];
	int  len;

	scanf("%s", number);
	len = get_length(number);
	
	qsort(number, len, sizeof(char), cmp);

	printf("%s\n", number);	
	return (0);
}
