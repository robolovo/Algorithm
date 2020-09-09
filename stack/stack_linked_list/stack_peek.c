/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_peek.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junslee <junslee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 15:18:25 by junslee           #+#    #+#             */
/*   Updated: 2020/03/12 15:39:33 by junslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_node *stack_peek(t_stack *stack)
{
	if (!stack || is_empty(stack))
		return (0);
	return (stack->top);
}
