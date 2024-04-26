/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracurul <fracurul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 18:49:28 by fracurul          #+#    #+#             */
/*   Updated: 2024/04/26 15:52:13 by fracurul         ###   ########.fr       */
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

void	nodes_init_a(t_stack *stack_a, t_stack *stack_b)
{
	current_average(stack_a);
	current_average(stack_b);
	set_target_a(stack_a, stack_b);
	cost_analysis(stack_a, stack_b);
	set_cheapest(stack_a);
}

void	nodes_init_b(t_stack *stack_a, t_stack *stack_b)
{
	current_average(stack_a);
	current_average(stack_b);
	set_target_b(stack_a, stack_b);
}