#ifndef STACK_H
# define STACK_H

# define PATH 0
# define WALL 1
# define VISITED 2
# define BACKTRACKED 3

#include <stdio.h>
#include <stdlib.h>

typedef struct s_pos
{
	int 	x;
	int 	y;
}			t_pos;

typedef struct s_stack
{
	int		max_size;
	int		top_index;
	t_pos	**pos;
}			t_stack;

t_stack *stack_init(int max_size);
int	stack_push(t_stack *stack, t_pos *new_pos);
t_pos	*stack_pop(t_stack *stack);
int	is_empty(t_stack *stack);
t_pos	*create_elem(int x, int y);

#endif
