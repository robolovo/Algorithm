#include <stdio.h>

#define BACKGROUND_PIXEL 0
#define IMAGE_PIXEL 1
#define COUNTED 2

int tab[8][8] = {
	{1,0,0,0,0,0,0,1},
	{0,1,1,0,0,1,0,0},
	{1,1,0,0,1,0,1,0},
	{0,0,0,0,0,1,0,0},
	{0,1,0,1,0,1,0,0},
	{0,1,0,1,0,1,0,0},
	{1,0,0,0,1,0,0,1},
	{0,1,1,0,0,1,1,1}
};
int n = 8;

void	print_tab(void)
{
	int x, y;

	x = 0;
	while (x < n)
	{
		y = 0;
		while (y < n)
		{
			printf("%d", tab[x][y]);
			y++;
		}
		printf("\n");
		x++;
	}
}

int	count_cells(int x, int y)
{
//	printf("x : %d y : %d\n", x ,y);
	if (x < 0 || y < 0 || x >= n || y >= n)
		return (0);
	else if (tab[x][y] != IMAGE_PIXEL)
		return (0);
	else
	{
		tab[x][y] = COUNTED;
		return (1 + count_cells(x - 1, y) + count_cells(x - 1, y + 1) + count_cells(x, y + 1) +
					count_cells(x + 1, y + 1) + count_cells(x + 1, y) + count_cells(x + 1, y - 1) +
					count_cells(x, y - 1) + count_cells(x - 1, y - 1));
	}
}

int main(void)
{
	int x, y;
	int	result;

	printf("Enter x, y coordinates : ");
	scanf("%d %d", &x, &y);
	
	printf("===================\n");
	print_tab();
	printf("=================================================\n");
	printf("0:BACKGROUND   1:IMAGE_PIXEL   2:COUNTED_PIXEL\n");
	printf("=================================================\n");
	result = count_cells(x, y);
	print_tab();
	printf("===================\n");
	printf("result : %d\n", result);
	return (0);
}
