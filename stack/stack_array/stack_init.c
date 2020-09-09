#include "stack.h"

t_stack	*stack_init(unsigned int max_size)
{
	t_stack *rtn_stack;

	if (!(rtn_stack = (t_stack *)malloc(sizeof(t_stack))))
		return (0);
	rtn_stack->max_size = max_size;
	rtn_stack->top_index = -1;
	if(!(rtn_stack->data = (void **)malloc(sizeof(void *) * max_size)))
	{
		free(rtn_stack);	
		return (0);
	}
	return (rtn_stack);
}
