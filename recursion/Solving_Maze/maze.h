#ifndef MAZE_H
# define MAZE_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

# define PATH 0
# define WALL 1
# define VISITED 2
# define EXIT 3

typedef struct s_pos
{
	int x;
	int y;
}				t_pos;

#endif
