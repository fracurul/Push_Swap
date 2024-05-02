/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracurul <fracurul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 18:49:28 by fracurul          #+#    #+#             */
/*   Updated: 2024/05/02 16:18:05 by fracurul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_to_b(t_stack **stack_a, t_stack **stack_b)
{
	t_node	*cheapest;

	cheapest = get_cheapest(*stack_a);
	if (cheapest->abv_avg && cheapest->target_node->abv_avg)
		r_both(stack_a, stack_b, cheapest);
	else if (!(cheapest->abv_avg)
		&& !(cheapest->target_node->cheapest))
		rr_both(stack_a, stack_b, cheapest);
	get_node_push(stack_a, cheapest, 1);
	get_node_push(stack_b, cheapest->target_node, 2);
	pb_mov(stack_a, stack_b);
}

void	move_to_a(t_stack **stack_a, t_stack **stack_b)
{
	get_node_push(stack_a, (*stack_b)->head->target_node, 1);
	pa_mov(stack_a, stack_b);
}

void	min_to_top(t_stack **stack_a)
{
	t_node *aux;

	aux = find_min(*stack_a);
	while ((*stack_a)->head->value != aux->value)
	{
		if (aux->abv_avg)
			ra_mov(stack_a);
		else
			rra_mov(stack_a);
	}
}

void	set_target_b(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*current_a;
	t_node	*aux_b;
	long	match;

	aux_b = stack_b->head;
	while (aux_b)
	{
		match = LONG_MAX;
		current_a = stack_a->head;
		while (current_a)
		{
			if (current_a->value > aux_b->value
				&& (long)current_a->value < match)
			{
				match = current_a->value;
				aux_b->target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (match > INT_MAX)
			aux_b->target_node = find_min(stack_a);
		aux_b = aux_b->next;
	}
}

int	matrix_size(char **argv)
{
	int	i;

	i = -1;
	while (argv[++i])
		;
	return (i);
}