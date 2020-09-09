#include "list.h"

static int	ABS(int nb)
{
		if (nb < 0)
			nb = nb * -1;
		return (nb);
}

static t_node	*get_nth_list(t_linked_list *list, int n)
{
		t_node	*curr;
		int		index;

		curr = list->head;
		index =  ABS(n) % list->size;
		if (n < 0)
			while (index--)
				curr = curr->prev;
		else
			while (index--)
				curr = curr->next;
		return (curr);
}

t_node *list_get(t_linked_list *list, int n)
{
	t_node *curr;
	
	if (list == 0 || list->head == 0 || !(curr = get_nth_list(list, n)))
		return (0);
	return (curr);
}
