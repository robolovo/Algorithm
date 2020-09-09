#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct s_node
{
	struct s_node	*parent;
	int				data;
}				t_node;

t_node	*create_elem(int data)
{
	t_node	*node;

	if (!(node = malloc(sizeof(t_node))))
		return (0);
	node->parent = 0;
	node->data = data;
	return (node);
}

t_node	*find(t_node *node)
{
	if (!node)
		return (0);
	if (!node->parent)
		return (node);
	node->parent = find(node->parent);
	return (node->parent);
}

bool	is_disjoint(t_node *node1, t_node *node2)
{
	if (!node1 || !node2)
		return (true);
	if (find(node1) == find(node2))
		return (false);
	return (true);
}

t_node	*union_func(t_node *node1, t_node *node2)
{
	t_node	*root1;
	t_node	*root2;

	root1 = find(node1);
	root2 = find(node2);
	if (!node1 || !node2)
		return (0);
	if (!is_disjoint(node1, node2))
		return (find(node1));
	return (root2->parent = root1); 
}

int main(void)
{
	t_node	*set[1000000];	
	int		n, m, i;
	int		command, a, b;
	bool	ret;

	scanf("%d %d", &n, &m);
	getchar();
	i = 0;
	while (i <= n)
	{	
		set[i] = create_elem(i);
		i++;
	}
	while (m--)
	{
		scanf("%d %d %d", &command, &a, &b);
		getchar();
		if (command == 0)
			union_func(set[a], set[b]);
		else if (command == 1)
		{	
			ret = is_disjoint(set[a], set[b]);
			if (ret == true)
				printf("NO\n");
			else
				printf("YES\n");
		}
		else 
		{
			printf("Invalid input.\n");
			m++;
		}
	}
	return (0);
}
