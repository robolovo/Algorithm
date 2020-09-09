#include "stack.h"

t_stack *stack_init(int max_size)
{
	t_stack *stack;
	int		i;

	if (!(stack = malloc(sizeof(t_stack))))
		return (0);
	if (max_size < 1)
		return (0);
	stack->max_size = max_size;
	stack->top_index = -1;
	if (!(stack->pos = malloc(sizeof(t_pos) * max_size)))
	{	
		free(stack);
		return (0);
	}
/*	i = 0;
	while (i < max_size)
	{
		stack->pos[i] = 0;
		i++;
	}*/
	return (stack);
}
