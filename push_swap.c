/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracurul <fracurul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:17:13 by fracurul          #+#    #+#             */
/*   Updated: 2024/05/03 19:21:49 by fracurul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static void	free_stack(t_stack **stack)
{
	t_stack	*node;
	t_stack	*tmp;
	if (!(*stack))
		return ;
	node = *stack;
	tmp = node;
	while (node->head)
	{
		tmp->head = node->head->next;
		node->head->value = 0;
		node->head->max_value = 0;
		node->head->push_cost = 0;
		node->head->abv_avg = 0;
		node->head->cheapest = 0;
		if (node->head->target_node)
			free(node->head->target_node);
		free(node->head);
		node = tmp;
	}
	if (node)
		free(node);
	
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = malloc(sizeof(t_stack));
	stack_b = malloc(sizeof(t_stack));
	stack_init(stack_a);
	stack_init(stack_b);
	if (!check_parameters(argc, argv, stack_a))
		ps_algorithm(stack_a, stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
