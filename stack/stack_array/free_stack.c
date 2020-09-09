#include "stack.h"

void	free_stack(t_stack *stack, void (*free_data)(void *))
{
	int	i;

	i = 0;
	if (!stack || !free_data)
		return ;
	stack_clear(stack, free_data);
	free(stack);
}
