#include "stack.h"

void	stack_clear(t_stack *stack, void (*free_data)(void *))
{
	int	index;

	index = 0;
	if (!stack || !free_data)
		return ;
	while(stack->top_index > -1)
	{
		(*free_data)(stack->data[index]);
		stack->top_index = -1;
	}
}
