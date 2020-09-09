#include <stdio.h>
#include <stdlib.h>

typedef struct s_score
{
	float           score;
	struct s_score  *next;    
}                   t_score;

t_score *create_elem(double data)
{	
	t_score *new_node;
			  
	if (!(new_node = malloc(sizeof(t_score))))
		return (0);
	new_node->score = data;
	new_node->next = 0;
	return (new_node);
}

void list_add(t_score **begin_list, int data)
{	
	t_score    *curr;
	t_score    *new_node;

	if (begin_list == 0 || (new_node = create_elem(data)) == 0)
		return ;
	if (*begin_list == 0)
	{
		*begin_list = new_node;
		return ;
	}	
	curr = *begin_list;
	while (curr->next)
		curr = curr->next;
	curr->next = new_node;
}

int main()
{
	int         N, n, value;
	float       max = 0, sum = 0;
	t_score     *curr;
	t_score		**head;				    
	
	scanf("%d\n", &N);
	n = N;    
	if (!(head = (t_score **)malloc(sizeof(t_score *))))
		return (0);
	while (N--)
	{
		scanf("%d", &value);
		if(value > max)
			max = value;
		list_add(head, value);
	}
	curr = *head;
	while (curr)
	{
		sum = sum + ((curr->score / max) * 100);
		curr = curr->next;
	}
	printf("%.2f", sum / n);
	return (0);
}
