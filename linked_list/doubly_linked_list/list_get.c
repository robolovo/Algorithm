#include "list.h"

t_node	*list_get(t_linked_list *list, int n)
{
	int		i;
	t_node	*curr;

	curr = list->head;
	if (list->size <= n || list == 0 || n < 0)
		return (0);
	i = 0;
	while (i < n)
	{
		curr = curr->next;
		i++;
	}
	return (curr);
}
/*
#include <stdio.h>
int main(void)
{
	t_linked_list	*lst;
	t_node			*curr;

	lst = list_init();
	lst->head = create_elem(10);
	lst->size++;
	lst->head->next = create_elem(100);
	lst->size++;
	lst->head->next->next = create_elem(1000);
	lst->size++;

	if (!(curr = list_get(lst, 3)))
		return (0);
	printf("%d\n", curr->data); // 1000
	printf("%d\n", lst->head->data); // 10

}*/
