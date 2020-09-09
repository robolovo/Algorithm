/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junslee <junslee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 15:31:56 by junslee           #+#    #+#             */
/*   Updated: 2020/03/12 15:34:32 by junslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void free_stack(t_stack *stack, void (*free_data)(void *))
{
	if (!stack)
		return ;
	stack_clear(stack, free_data);
	free(stack);
}
