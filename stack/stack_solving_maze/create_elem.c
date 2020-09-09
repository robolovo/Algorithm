#include "stack.h"

t_pos	*create_elem(int x, int y)
{
	t_pos	*new_pos;

	if (!(new_pos = malloc(sizeof(t_pos))))
		return (0);
	new_pos->x = x;
	new_pos->y = y;
	return (new_pos);
}
