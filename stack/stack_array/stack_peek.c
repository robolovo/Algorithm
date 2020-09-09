#include "stack.h"

void	*stack_peek(t_stack *stack)
{
	if (stack == 0 || is_empty(stack))
		return (0);
	return (stack->data[stack->top_index]);
}
