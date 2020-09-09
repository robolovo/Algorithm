#include "includes/list.h"

int	list_remove(t_node **begin_list, int n)
{
	int i;
	t_node *curr;

	i = 0;
	if (*begin_list == *curr)
		*begin_list = curr->next;
	else
	{	
		t_node *curr = *begin_list;
		while (i < n)
		{
			curr = curr->next;
			i++;
		}
		curr = curr->next->next;
	}	
}
