/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_clear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junslee <junslee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 15:28:54 by junslee           #+#    #+#             */
/*   Updated: 2020/03/12 15:48:35 by junslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void stack_clear(t_stack *stack, void (*free_data)(void *))
{
	unsigned int	i;

	if (!stack)
		return ;
	i = 0;
	while (i < stack->size)
	{
		(*free_data)(stack->top->data);
		stack->top = stack->top->next;
		i++;
	}
	stack->size = 0;
}
