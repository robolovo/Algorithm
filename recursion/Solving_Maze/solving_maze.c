#include "maze.h"

int maze[7][7] = {
	{0,0,0,0,1,0,0},
	{0,1,1,0,1,0,1},
	{0,0,1,0,0,0,0},
	{1,0,1,1,1,1,1},
	{0,0,0,0,0,0,0},
	{1,0,1,1,1,1,0},
	{1,1,1,1,1,1,0}
};
int n = 7;

bool is_movable(t_pos *pos)
{
	if (maze[pos->x][pos->y] == PATH && pos->x < n && pos->x >= 0 && pos->y < n && pos->y >= 0)
		return (true);
	return (false);
}

bool is_exit(t_pos *pos)
{
	if (pos->x == n - 1 && pos->y == n - 1)
		return (true);
	return (false);
}

void	move_to(t_pos *pos, int dir)
{
	if (dir == 0)
		pos->x -= 1;
	else if (dir == 1)
		pos->y += 1;
	else if (dir == 2)
		pos->x += 1;
	else
		pos->y -= 1;
}

void	init_pos(t_pos *pos, int dir)
{
	if (dir == 0)
		pos->x += 1;
	else if (dir == 1)
		pos->y -= 1;
	else if (dir == 2)
		pos->x -= 1;
	else
		pos->y += 1;
}

void	print_maze(void)
{
	int x, y;

	x = 0;
	while (x < n)
	{
		y = 0;
		while (y < n)
		{
			printf("%d", maze[x][y]);
			y++;
		}
		printf("\n");
		x++;
	}
}

bool find_path(t_pos *pos)
{
	
	if (is_exit(pos))
	{
		maze[pos->x][pos->y] = EXIT;
		return (true);
	}
	else if (!is_movable(pos))
		return (false);
	else
	{
		//printf("current position: %d  %d\n", pos->x, pos->y);	
		maze[pos->x][pos->y] = VISITED;
		for (int dir = 0; dir < 4; dir++)
		{
			move_to(pos, dir);	
			if (find_path(pos))
				return (true);
			else
				init_pos(pos, dir);
		}
	}
	return (false); 
}

int main(void)
{
	t_pos *pos;
	bool state;	
	if (!(pos = malloc(sizeof(t_pos))))
		return (0);
	pos->x = 0;
	pos->y = 0;
	printf("============================================\n");
	print_maze();
	printf("============================================\n");
	printf("0: PATH_WAY   1: WALL   2:VISITED   3:EXIT\n");
	printf("============================================\n");
	state = find_path(pos);
	print_maze();
	printf("============================================\n");
	printf("Result : ");
	if (state)
		printf("Found the exit!\n");
	else
		printf("No path exits.\n");
	printf("============================================\n");
	return (0);
}
