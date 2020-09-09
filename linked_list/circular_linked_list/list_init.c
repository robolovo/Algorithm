#include "list.h"

t_linked_list	*list_init(void)
{
	t_linked_list *list;
	
	if (!(list = (t_linked_list *)malloc(sizeof(t_linked_list))))
		return (0);
	list->size = 0;
	list->head = 0;
	return (list);
}
