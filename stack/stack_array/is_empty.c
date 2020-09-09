#include "stack.h"

int	is_empty(t_stack *stack)
{
	if (stack->top_index == -1)
		return (1);
	return (0);
}
