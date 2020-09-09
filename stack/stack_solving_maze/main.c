#include "stack.h"
#include <stdbool.h>

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

static void	move_to(t_pos *pos, int dir)
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

static bool	movable(t_pos *curr, int dir)
{
	if (dir == 0)
	{
		if (maze[curr->x - 1][curr->y] == 0 && curr->x - 1 > -1 && 
						curr->y > -1 &&	curr->x - 1 < n && curr->y < n)
			return (true);
	}
	else if (dir == 1)
	{
		if (maze[curr->x][curr->y + 1] == 0 && curr->x > -1 && 
						curr->y + 1 > -1 && curr->x < n && curr->y + 1 < n)
			return (true);
	}
	else if (dir == 2)
	{
		if (maze[curr->x + 1][curr->y] == 0 && curr->x + 1 > -1 &&
						curr->y > -1 && curr->x + 1 < n && curr->y < n)
			return (true);
	}
	else 
	{
		if (maze[curr->x][curr->y - 1] == 0 && curr->x > -1 && 
						curr->y - 1 > -1 && curr->x < n && curr->y - 1 < n)
			return (true);
	}
	return (false);
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

int main(void)
{
	t_stack *stack;
	t_pos	*curr;

	if (!(stack = stack_init(100)))
		return (-1);
	print_maze();
	printf("==========================\n");
	curr = create_elem(0, 0);
	stack_push(stack, curr);

	while (1)
	{
		maze[curr->x][curr->y] = VISITED;
		//printf("current position : %d   %d\n", curr->x, curr->y);
		if (curr->x == n - 1 && curr->y == n - 1)
		{
			printf("Found the exit.\n");
			break;
		}

		bool forwarded = false;
		for (int dir = 0; dir < 4; dir++)
		{
			if (movable(curr, dir))
			{
				curr = create_elem(curr->x, curr->y);
				stack_push(stack, curr);
				move_to(curr, dir);
				forwarded = true;
				break;
			}
		}
		if (!forwarded)
		{
			maze[curr->x][curr->y] = BACKTRACKED;
			if (is_empty(stack))
			{
				printf("No path exists.\n");
				break;
			}
			curr = stack_pop(stack);
		}
	}
	print_maze();
	return (0);
}
