/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junslee <junslee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 11:57:06 by junslee           #+#    #+#             */
/*   Updated: 2020/03/12 12:12:13 by junslee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(void)
{
		char *temp;
		t_stack *stack = stack_init(5);
		printf("size = %d\n", stack_size(stack));
		printf("peek->data = %s\n", stack_peek(stack));

		stack_push(stack, strdup("aa"));
		printf("size = %d\n", stack_size(stack));
		printf("peek->data = %s\n", stack_peek(stack));

		stack_push(stack, strdup("b"));
		printf("size = %d\n", stack_size(stack));
		printf("peek->data = %s\n", stack_peek(stack));

		stack_push(stack, strdup("ccc"));
		printf("size = %d\n", stack_size(stack));
		printf("peek->data = %s\n", stack_peek(stack));

		stack_push(stack, strdup("ddddd"));
		printf("size = %d\n", stack_size(stack));
		printf("peek->data = %s\n", stack_peek(stack));

		stack_push(stack, strdup("ee"));
		printf("size = %d\n", stack_size(stack));
		printf("peek->data = %s\n", stack_peek(stack));

		temp = strdup("f");
		stack_push(stack, temp);
		printf("size = %d\n", stack_size(stack));
		printf("peek->data = %s\n", stack_peek(stack));
		free(temp);

		printf("=============== pop ===============\n");
		for (int i = 0; i < 9; i++)
		{
				temp = stack_pop(stack);
				printf("pop = %s\n", temp);
				free(temp);
				printf("size = %d\n", stack_size(stack));
				printf("peek->data = %s\n", stack_peek(stack));
		}

		stack_clear(stack, free);

		stack_push(stack, strdup("e22"));
		printf("size = %d\n", stack_size(stack));
		printf("peek->data = %s\n", stack_peek(stack));

		stack_push(stack, strdup("f22"));
		printf("size = %d\n", stack_size(stack));
		printf("peek->data = %s\n", stack_peek(stack));

		free_stack(stack, free);

		system("leaks a.out > leaks_result; cat leaks_result | grep leaked");
		return (0);
}
