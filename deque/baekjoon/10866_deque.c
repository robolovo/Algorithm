#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_node
{
	int				data;
	struct s_node 	*next;
	struct s_node 	*prev;
}					t_node;

typedef struct s_deque
{
	unsigned int 	size;	
	t_node			*front;
	t_node			*back;
}					t_deque;

t_node	*create_elem(int data)
{
	t_node	*node;

	if (!(node = (t_node *)malloc(sizeof(t_node))))
		return (0);
	node->data = data;
	node->next = 0;
	node->prev = 0;
	return (node);
}

t_deque	*deque_init()
{
	t_deque *deque;

	if (!(deque = (t_deque *)malloc(sizeof(t_deque))))
		return (0);
	deque->size = 0;
	deque->front = 0;
	deque->back = 0;
	return (deque);
}

void push_front(t_deque *deque, int X)
{
	t_node	*new;

	if (!deque || !(new = create_elem(X)))
		return ;
	new->next = deque->front;
	if (deque->size == 0)
		deque->back = new;
	else
		deque->front->prev = new;
	deque->front = new;
	deque->size++;
}

void push_back(t_deque *deque, int X)
{
	t_node	*new;

	if (!deque || !(new = create_elem(X)))
		return ;
	new->prev = deque->back;
	if (deque->size == 0)
		deque->front = new;
	else
		deque->back->next = new;
	deque->back = new;
	deque->size++;
}

void pop_front(t_deque *deque)
{
	if (deque->front == 0)
	{	
		printf("-1\n");
		return ;
	}
	printf("%d\n", deque->front->data);
	deque->front = deque->front->next;
	deque->size--;
	if (deque->size == 0)
		deque->back = 0;
	else
		deque->front->prev = 0;
}

void pop_back(t_deque *deque)
{
	if (deque->back == 0)
	{	
		printf("-1\n");
		return ;
	}
	printf("%d\n", deque->back->data);
	deque->back = deque->back->prev;
	deque->size--;
	if (deque->size == 0)
		deque->front = 0;
	else
		deque->back->next = 0;
}

void deque_size(t_deque *deque)
{
	printf("%d\n", deque->size);
}

void is_empty(t_deque *deque)
{
	if (deque->size == 0)
		printf("1\n");
	else
		printf("0\n");
}

void front(t_deque *deque)
{
	if (deque->front == 0)
		printf("-1\n");
	else
		printf("%d\n", deque->front->data);
}

void back(t_deque *deque)
{
	if (deque->back == 0)
		printf("-1\n");
	else
		printf("%d\n", deque->back->data);
}

int main(void)
{
	t_deque *deque;
	int	N, X;
	char str[11];

	deque = deque_init();
	scanf("%d", &N);
	while(N--)
	{
		scanf("%s", str);
		if (strcmp(str, "push_front") == 0)
		{	
			scanf("%d", &X);
			push_front(deque, X);
		}
		if (strcmp(str, "push_back") == 0)
		{	
			scanf("%d", &X);
			push_back(deque, X);
		}
		if (strcmp(str, "pop_front") == 0)
			pop_front(deque);
		if (strcmp(str, "pop_back") == 0)
			pop_back(deque);
		if (strcmp(str, "size") == 0)
			deque_size(deque);
		if (strcmp(str, "empty") == 0)
			is_empty(deque);
		if (strcmp(str, "front") == 0)
			front(deque);
		if (strcmp(str, "back") == 0)
			back(deque);
	}
}
