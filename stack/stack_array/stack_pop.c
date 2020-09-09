#include "stack.h"

void	*stack_pop(t_stack *stack)
{
	void	*rtn;
	
	if (stack == 0 || stack->data == 0 || is_empty(stack))
		return (0);
	rtn = stack->data[stack->top_index];
	stack->data[stack->top_index] = 0;
	stack->top_index--;
	return (rtn);
}
