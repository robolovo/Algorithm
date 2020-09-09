#include "stack.h"

t_pos	*stack_pop(t_stack *stack)
{
	t_pos	*rtn;

	if (!stack)
		return (0);
	rtn = stack->pos[stack->top_index];
	free(stack->pos[stack->top_index]);
	stack->top_index--;
	return (rtn);
}
