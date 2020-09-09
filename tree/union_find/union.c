#include "union_find.h"

t_node	*union_func(t_node *node1, t_node *node2)
{
	t_node	*root1;
	t_node	*root2;

	root1 = find(node1);
	root2 = find(node2);
	if (!node1 || !node2)	
		return (0);
	if (!is_disjoint(node1, node2)) //node1, node2가 이미 같은 트리. 
		return (find(node1)); 
	return (root2->parent = root1); //node1의 root node가 두집합의 root node가 되도록 합침.
}

/*
t_node	*union_func(t_node *node1, t_node *node2)
{
	if (!node1 || !node2)
		return (0);
	if (!is_disjoint(node1, node2))
		return (find(node1));
	return (find(node2)->parent = find(node1));
}*/
