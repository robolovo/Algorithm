#include "list.h"

static int	ABS(int nb)
{
	if (nb < 0)
		nb = nb * -1;
	return (nb);
}

static t_node	*get_nth_list(t_linked_list *list, int n)
{
	t_node			*curr;
	int				index;

	curr = list->head;
	index = ABS(n) % list->size;
	if (n < 0)
		while (index--)
			curr = curr->prev;
	else
		while (index--)
			curr = curr->next;
	return (curr);
}

int	list_add(t_linked_list *list, void *data, int n)
{
	t_node 	*curr;
	t_node	*new_node;
	
	if (list == 0 || (new_node = create_elem(data)) == 0) 
		return (-1);
	if (list->size == 0 || list->head == 0)
	{	
		list->head = new_node;
		list->size++;
		return (0);
	}
	else if (list->size == 1)
	{
		new_node->next = list->head;
		new_node->prev = list->head;
		list->head->next = new_node;
		list->head->prev = new_node;
		list->size++;
		return (1);
	}
	else if (list->size > 1 && (curr = get_nth_list(list, n)))
	{
		new_node->next = curr;
		new_node->prev = curr->prev;
		curr->prev->next = new_node;
		curr->prev = new_node;
		list->size++;
		if (n < 0)
			return (list->size - (ABS(n) % list->size));
		if (n == 0)
			return (list->size - 1);
		if (n < (int)list->size)			
			return (n);
		if (n >= (int)list->size)
			return (n % list->size);
	}
	return (-1);
}
