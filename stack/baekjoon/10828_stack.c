/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   10828_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junslee <junslee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 16:09:37 by junslee           #+#    #+#             */
/*   Updated: 2020/03/19 16:37:58 by junslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <string.h>

typedef struct s_stack
{
	unsigned int	max;
	int				top_idx;
	int				*arr;
}					t_stack;

void	stack_init(t_stack *stack)
{
	
	t_stack *stack;
    if (!(stack = (t_stack *)malloc(sizeof(t_stack))))
		return (0);
	stack->max = 10000;
	stack->top_idx = -1;
	if (!(stack->arr = (int *)malloc(sizeof(int) * 10000)))
	{    
		free(stack);
		return (0);
	}
	return (stack);
}
int is_full(t_stack *stack)
{
	if ((unsigned int)stack->top_idx + 1 >= stack->max)
		return (1);
	return (0);
}

int	is_empty(t_stack *stack)
{
	if(stack->top_idx == -1)
		return (1);
	return (0);
}

int	stack_size(t_stack *stack)
{
	return (stack->top_idx + 1);	
}

int	stack_top(t_stack *stack)
{
	if (is_empty(stack))
		return (-1);
	return (stack->arr[stack->top_idx]);
}

int	stack_pop(t_stack *stack)
{
	int rtn;

	if (is_empty(stack))
		return (-1);
	rtn = stack->arr[stack->top_idx];
	stack->top_idx--;
	return (rtn);
}

void	stack_push(t_stack *stack, int x)
{
	if (is_full(stack))
		return ;
	stack->top_idx++;
	stack->arr[stack->top_idx] = x;
}

int	main(void)
{
	t_stack *stack;
	int		i, N, num;
	char	str[6];
	
	scanf("%d\n", &N);
	stack = stack_init();
	while (N--)
	{
		scanf("%s", str);
		if (!strcmp(str, "push"))
		{
			scanf("%d", &num);
			stack_push(stack, num);
		}
		else if (!strcmp(str, "pop"))
			printf("%d\n", stack_pop(stack));	
		else if (!strcmp(str, "empty"))
			printf("%d\n", is_empty(stack));	
		else if (!strcmp(str, "size"))
			printf("%d\n", stack_size(stack));	
		else if (!strcmp(str, "top"))
			printf("%d\n", stack_top(stack));
	}		
	return (0);
}
