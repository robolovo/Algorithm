#include <stdio.h>
#include <stdlib.h>

typedef struct s_node
{
	char			c;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

typedef struct s_list
{
	t_node	*head;
	t_node	*tail;
}			t_list;

t_list	*list_init()
{
	t_list	*list;

	list = malloc(sizeof(t_list));
	list->head = 0;
	list->tail = 0;
	return (list);
}

t_node	*create_node(char c)
{
	t_node	*node;

	if (!(node = malloc(sizeof(t_node))))
		return (0);
	node->c = c;
	node->next = 0;
	node->prev = 0;
	return (node);
}

void		list_add_last(t_list *list, char data)
{
	t_node *new;
	t_node *curr;

	if ((new = create_node(data)) == 0)
		return ;
	if (!list->head)
	{
		list->head = new;
		list->tail = new;
		return ;
	}
	curr = list->tail;
	if (!curr)
		list->head = new;
	else
	{
		new->prev = curr;
		curr->next = new;
	}
	list->tail = new;
}

void	list_remove(t_list *list, t_node *curr)
{
	if (curr->next == 0)
	{
		list->tail = curr->prev;	
		free(curr);
		curr = NULL;
		return ;
	}
	curr->prev = curr->next;
	curr->next->prev = curr->prev;
	curr = 0;
	free(curr);
}

void	list_add(t_list *list, t_node *curr, char c)
{
	t_node *new;

	new = create_node(c);
	if (curr->next == 0)
	{
		new->prev = curr;
		curr->next = new;
		list->tail = new;
		return ;
	}
	if (curr->prev == 0)
	{
		new->next = curr;	
		curr->prev = new;
		list->head = new;
		return ;
	}
	new->next = curr->next;
	new->prev = curr;
	curr->next->prev = new;
	curr->next = new;
}

int main(void)
{
	t_list	*list;
	t_node	*curr;
	t_node	*temp;
	char	str[100000];
	int		T, i, flag;
	char 	command, add;

	scanf("%s", str);
	list = list_init();
	i = 0;
	while(str[i])
	{
		list_add_last(list, str[i]);
		i++;
	}
	scanf("%d", &T);
	getchar();
	curr = list->tail;
	i = 0; 
	while (i < T)
	{
		scanf("%c", &command);
		getchar();
		flag = 0;
		if (command == 'L')
		{	
			if (curr->prev)
				curr = curr->prev;
		}
		else if (command == 'D')
		{
			if (curr->next)
				curr = curr->next;
		}
		else if (command == 'B')
		{
		//	if (curr->prev)
		//	{
				temp = curr;
				curr = curr->prev;
				curr->next = temp->next;
				if (temp->next)
					temp->next->prev = curr;
		//	}
		}
		else
		{
			scanf("%c", &add);
			getchar();
			if (curr == list->head)
				flag = 1;
			list_add(list, curr, add);
			curr = curr->next;
			if (flag)
				curr = curr->prev;	
		}		
		i++;
	}
	curr = list->head;
	while (curr)
	{
		printf("%c", curr->c);
		curr = curr->next;
	}
	printf("\n");
}
