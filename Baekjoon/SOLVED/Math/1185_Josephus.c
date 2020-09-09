#include <stdio.h>
#include <stdlib.h>

typedef struct s_node
{
	int	n;
	struct s_node	*next;
	struct s_node	*prev;
}				t_node;

typedef struct s_list
{
	t_node	*head;
}			t_list;

t_list	*list_init(void)
{
	t_list	*list;

	list = malloc(sizeof(t_list));
	list->head = 0;
	return (list);
}

t_node 	*create_elem(int n)
{
	t_node *node;

	node = malloc(sizeof(t_node));
	node->n = n;
	node->next = 0;
	node->prev = 0;
	return (node);
}

void list_add_last(t_list *list, int n)
{
	t_node	*new;
	t_node	*curr;

	new = create_elem(n);
	if (list->head == 0)
	{
		list->head = new;
		new->next = new;
		new->prev = new;
		return ;
	}
	curr = list->head;
	new->prev = curr->prev;
	curr->prev->next = new;
	new->next = curr;
	curr->prev = new;
}

int	 list_remove(t_list *list, t_node *curr)
{
	int rtn;

	rtn = curr->n;
	if (curr == list->head)
	{
		list->head = curr->next;
	}
	curr->prev->next = curr->next;
	curr->next->prev = curr->prev;
	free(curr);
	curr = NULL;
	return (rtn);
}

int main(void)
{
	t_list 	*list;
	t_node	*curr;
	t_node	*temp;
	int N, K, res;

	list = list_init();
	curr = list->head;
	scanf("%d %d", &N, &K);
	int n = 0;
	while (n < N)
	{
		list_add_last(list, n + 1);
		n++;
	}
	curr = list->head;
	printf("<");
	n = 0;
	while (n < N)
	{
		int i = 0;	
		while (i < K - 1)
		{	
			curr = curr->next;
			i++;
		}
		temp = curr;
		curr = curr->next;
		res = list_remove(list, temp);
		printf("%d", res);
		if (n < N - 1)
			printf(", ");
		n++;
	}
	printf(">");
	printf("\n");
	return (0);
}
