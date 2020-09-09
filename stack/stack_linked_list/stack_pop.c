/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_pop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junslee <junslee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 15:20:01 by junslee           #+#    #+#             */
/*   Updated: 2020/03/12 15:47:37 by junslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_node *stack_pop(t_stack *stack)
{
	t_node	*rtn;

	if (!stack || is_empty(stack))
		return (0);
	rtn = stack->top;
	stack->top = stack->top->next;
	rtn->next = 0;
	stack->size--;
	return (rtn);
}
