#include <stdlib.h>
#include "includes/list.h"
    
t_node *create_elem(int data)
{
	t_node *elem;

	if(!(elem = malloc(sizeof(t_node))))
		return (0);
	elem->data = data;
	elem->next = NULL;
	return (elem);
}

int	list_add1(t_node **begin_list, int data)
{
	int 	i;
	t_node	*newNode;
	t_node	*curr;
	
	if (!(newNode = create_elem(data)))
		return (-1);
	i = 0;
	if (*begin_list == NULL)
		*begin_list = create_elem(data);
	else
	{
		curr = *begin_list;
		while (curr->next != NULL)
		{	
			curr = curr->next;
			i++;
		}
		curr->next = newNode;
	}
	return (i);
}
