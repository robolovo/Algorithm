#include <stdlib.h>
#include "includes/list.h"

t_node *create_elem(int data)
{
	t_node *elem;

	if(!(elem = malloc(sizeof(t_node))))
		return (0);
	elem->data = data;
	return (0);
}
