/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junslee <junslee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 14:58:13 by junslee           #+#    #+#             */
/*   Updated: 2020/03/12 15:17:15 by junslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	stack_push(t_stack *stack, void *data)
{
	t_node *new;

	if (!stack)
		return (0);
	new = create_elem(data);
	if (is_empty(stack))
		stack->top = new;
	else
	{
		new->next = stack->top;
		stack->top = new;
	}
	stack->size++;
	return (1);
}
