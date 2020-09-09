#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int N = 8;
int cols[8];

void	print_board(void)
{
	int x;

	x = 1;
	while (x <= N)
	{
		printf("%d ", cols[x]);
		x++;
	}
	printf("\n");
}

bool promising(int level)
{
	int i;

	i = 1;
	while (i < level)
	{
		if (cols[i] == cols[level])
			return (false);
		else if ((level - i) == abs(cols[level] - cols[i]))
			return (false);
		i++;
	}
	return (true);
}

bool queen(int level)
{	
	if (!promising(level))
		return (false);
	else if (level == N)
		print_board();	
	for (int i = 1; i <= N; i++)	
	{
		cols[level + 1] = i;	
		if (queen(level + 1))
			return (true);		
	}
	return (false);
}		

int main(void)
{
	queen(0);
	return (0);
}
