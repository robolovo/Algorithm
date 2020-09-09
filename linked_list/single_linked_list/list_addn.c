#include "includes/list.h"
#include <stdlib.h>

t_node *create_elem(int data)
{
	t_node *elem;

	if(!(elem = malloc(sizeof(t_node))))
		return (0);
	elem->data = data;
	return (elem);
}

int	list_addn(t_node **begin_list, int data, int n)
{
	int i;
	int size;
	t_node *curr = *begin_list;

	i = 0;
	size = 0;
	while (curr)
	{
		curr = curr->next;
		size++;
	}
	if (size < n)
	{
		curr = create_elem(data);
		return (size);
	}
	else 
	{
		t_node *curr = *begin_list;
		while (i < n)
		{
			curr = curr->next;			
			i++;
		}
		curr = create_elem(data);
		return (i);
	}
}
