#include <stdio.h>
#include <stdlib.h>

typedef struct s_member
{
	int		age;
	char	name[101];
}				t_member;

int cmp(const void *a, const void *b)
{
	return (*(int *)a - *(int *)b);
}

int main(void)
{
	int N, i;

	scanf("%d", &N);
	t_member member[N];
	i = 0;
	while (i < N)
	{
		scanf("%d %s", &member[i].age, member[i].name);
		i++;
	}

	qsort(member, N, sizeof(t_member), cmp);

	i = 0;
	while(i < N)
	{
		printf("%d %s\n", member[i].age, member[i].name);
		i++;
	}
}
