#include <stdio.h>
#include <stdbool.h>

int	board[9][9];

bool check_col_row(int x, int y, int n)
{
	for (int i = 0; i < 9; i++)
	{
		if (n == board[x][i])
			return (false);
		if (n == board[i][y])
			return (false);
	}
	return (true);
}

bool check_box(int x, int y, int n)
{
	int i;
	int j;
	int a = x / 3;
    int b = y / 3;

    a *= 3;
    b *= 3;
    for (i = 0; i < 3; i++) 
	{
        for (j = 0; j < 3; j++) 
		{	
            if (board[a + i][b + j] == n)
				return (false);
        }
    }
    return (true);
}

bool	dfs()
{
	int x, y;
	bool flag;

	flag = true;
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (board[i][j] == 0)	
			{
				flag = false;	
				x = i;
				y = j;
				break;
			}
		}
		if (!flag)
			break;
	}
	if (flag)
		return (true);
	for (int n = 1; n <= 9; n++)	
	{
		if (check_col_row(x, y, n) && check_box(x, y, n))
		{
			board[x][y] = n;	
			if (dfs())
				return (true);
		}
		board[x][y] = 0;
	}
	return (false);
}

int main(void)
{
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			scanf("%d", &board[i][j]);
	dfs();
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
			printf("%d ", board[i][j]);
		printf("\n");
	}
	return (0);
}
