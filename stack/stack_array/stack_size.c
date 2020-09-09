#include "stack.h"

int	stack_size(t_stack *stack)
{
	if (stack == 0)
		return (0);
	return (stack->top_index + 1);
}
