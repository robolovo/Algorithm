/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_elem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junslee <junslee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 14:55:32 by junslee           #+#    #+#             */
/*   Updated: 2020/03/12 14:58:06 by junslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_node	*create_elem(void *data)
{
	t_node	*rtn_node;

	if (!(rtn_node = (t_node *)malloc(sizeof(t_node))))
		return (0);
	rtn_node->data = data;
	rtn_node->next = 0;
	return (rtn_node);
}
