/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junslee <junslee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 14:05:12 by junslee           #+#    #+#             */
/*   Updated: 2020/03/12 15:37:59 by junslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_stack	*stack_init(void)
{
	t_stack *rtn_stack;
	
	if (!(rtn_stack = (t_stack *)malloc(sizeof(t_stack))))
		return (0);
	rtn_stack->size = 0;
	rtn_stack->top = 0;
	return (rtn_stack);
}
