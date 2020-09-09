#include "stack.h"

int	stack_push(t_stack *stack, t_pos *new_pos)
{
	if (!stack || !new_pos)
		return (0);
	if (stack->top_index >= stack->max_size - 1)
		return (0);
	stack->top_index++;
	stack->pos[stack->top_index] = new_pos;
	return (1);
}
