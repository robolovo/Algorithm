#include "list.h"

int	list_size(t_linked_list *list)
{
	int	size;
		
	size = 0;
	if (list == 0)
		return (0);
	while (list->head != 0)
	{
		list->head = list->head->next;
		size++;
	}
	return (size);
}
/*
#include <stdio.h>

int	main(void)
{
	t_linked_list	*lst;

	lst = list_init();
//	lst->head = create_elem(100);
//	lst->head->next = create_elem(1000);
	lst->size = list_size(lst);
	printf("%d\n", lst->size);
}
*/
