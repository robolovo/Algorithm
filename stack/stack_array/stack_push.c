#include "stack.h"

int	stack_push(t_stack *stack, void *data)
{
	if (!stack || (unsigned int)stack->top_index + 1 >= stack->max_size)
		return (0);
	stack->top_index++;	
	stack->data[stack->top_index] = data;
	return (1);
}
