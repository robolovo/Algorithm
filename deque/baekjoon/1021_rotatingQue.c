#include <stdio.h>
#include <stdlib.h>

typedef struct s_node
{
	int				data;	
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

typedef struct s_deque
{
	unsigned int 	size;
	t_node			*front;
	t_node			*back;
}					t_deque;

t_deque	*deque_init(void)
{
	t_deque	*deque;

	if (!(deque = malloc(sizeof(t_deque))))
		return (0);
	deque->size = 0;
	deque->front = 0;
	deque->back = 0;
	return (deque);
}

t_node	*create_elem(int data)
{
	t_node	*node;

	if (!(node = malloc(sizeof(t_node))))
		return (0);
	node->data = data;
	node->next = 0;
	node->prev = 0;
	return (node);
}

t_node	*pop_front(t_deque *deque)
{
	t_node	*node;

	node = deque->front;
	deque->front = node->next;
	deque->size--;
	if (deque->size == 0)
		deque->back = 0;
	else
		deque->front->prev = 0;
	return (node);
}

t_node	*pop_back(t_deque *deque)
{
	t_node	*node;

	node = deque->back;
	deque->back = node->prev;
	deque->size--;
	if (deque->size == 0)
		deque->front = 0;
	else
		deque->back->next = 0;
	return (node);
}

void	push_front(t_deque *deque, t_node *node)
{
	node->next = deque->front;	
	if (deque->size == 0)
		deque->back = node;
	else
		deque->front->prev = node;
	deque->front = node;
	deque->size++;
}

void	push_back(t_deque *deque, t_node *node)
{
	node->prev = deque->back;
	if (deque->size == 0)
		deque->front = node;
	else
		deque->back->next = node;
	deque->back = node;
	deque->size++;
}

int	func(t_deque *deque, int target)
{
	t_node	*curr;
	int		min1 = 0, num1;
	int		min2 = 0, num2;

	if (target == deque->front->data)
	{
		pop_front(deque);	
		return (0);
	}
	curr = deque->front;	
	while (target != curr->data)
	{
		curr = curr->next;
		min1++;
	}
	curr = deque->back;
	while (target != curr->data)
	{
		curr = curr->prev;
		min2++;
	}
	min2++;
	num1 = min1;
	num2 = min2;
	if (min2 <= min1)
	{
		while (num2--)	
			push_front(deque, pop_back(deque));
		pop_front(deque);
	}
	else
	{
		while (num1--)	
			push_back(deque, pop_front(deque));
		pop_front(deque);
	}
	if (min2 <= min1)
		return (min2);
	else
		return (min1);
}

int	main(void)
{
	t_deque	*deque;
	t_node	*new;
	int N, M, i;
	int	target, count = 0;

	scanf("%d", &N);
	deque = deque_init();
	i = 1;
	while (i <= N)
	{
		new = create_elem(i);
		push_back(deque, new);
		i++;
	}
	scanf("%d", &M);
	deque->size = M;
	while (M--)
	{
		scanf("%d", &target);
		count += func(deque, target);
	}
	printf("%d\n", count);
}
