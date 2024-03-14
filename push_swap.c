/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracurul <fracurul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:17:13 by fracurul          #+#    #+#             */
/*   Updated: 2024/03/14 20:56:52 by fracurul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void print_stack(t_stack *stack)
{
	t_node *current = stack->head;
	while (current->next != NULL)
	{
		printf("value: %d", current->value);
		current = current->next;
	}
}

int main(int argc, char **argv)
{
	ft_split_checker(argc, argv);
	return 0;
}
/*int main(int argc, char **argv)
{
	t_stack	*stack_a;
	int		*values;

	stack_a = NULL;
	stack_init(stack_a);
	ft_split_checker(argc, argv);
	values = ft_parsing(argc, argv);
	stack_fill(stack_a, values, argc - 1);
	printf("Before swapping:\n");
	print_stack(stack_a);
	sa_mov(stack_a);
	printf("After swapping:\n");
	print_stack(stack_a);

	return 0;
}*/