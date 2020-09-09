#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int get_length(char *s)
{
	int i = 0;

	while (s[i])
		i++;	
	return (i);
}

int cmp(const void *a, const void *b)
{
	int a_len = get_length(a);
	int b_len = get_length(b);

	if (a_len == b_len)
		return (strcmp((char *)a, (char *)b));
	return (a_len - b_len);
}

int main(void)
{
	int		N, i, flag;

	scanf("%d", &N);
	char	s[N][51];
	i = 0;
	while (i < N)
	{
		scanf("%s", s[i]);
		i++;
	}

	qsort(s, N, sizeof(s[0]), cmp);

	i = 0;
	while (i < N)
	{
		flag = 1;
		if (!strcmp(s[i], s[i + 1]))	
			flag = 0;
		if (flag)
			printf("%s\n", s[i]);
		i++;
	}
}
