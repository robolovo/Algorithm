#include "list.h"

t_linked_list	*list_init(void)
{
	t_linked_list	*lst;

	if (!(lst = (t_linked_list *)malloc(sizeof(t_linked_list))))
		return (0);
	lst->size = 0;
	lst->head = 0;
	lst->tail = 0;
	return (lst);
}
