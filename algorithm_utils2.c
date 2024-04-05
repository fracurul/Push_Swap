/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracurul <fracurul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 18:49:28 by fracurul          #+#    #+#             */
/*   Updated: 2024/03/26 17:50:24 by fracurul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_to_b(t_stack **stack_a, t_stack **stack_b)
{
	t_node	*cheapest;

	cheapest = get_cheapest(*stack_a);
	if (cheapest->median && cheapest->target_node->median)
		r_both(stack_a, stack_b, cheapest);
	else if (!(cheapest->median)
		&& !(cheapest->target_node->cheapest))
		rr_both(stack_a, stack_b, cheapest);
	get_node_push(stack_a, cheapest, "stack_a");
	get_node_push(stack_b, cheapest->target_node, "stack_b");
	pb_mov(*stack_b, *stack_a);

}

void	move_to_a(t_stack **stack_a, t_stack **stack_b)
{
	get_node_push(stack_a, (*stack_b)->head->target_node, "stack_a");
	pa_mov(*stack_a, *stack_b);
}

void	min_to_top(t_stack **stack_a)
{
	t_node *aux;

	aux = find_min(*stack_a);
	while ((*stack_a)->head->value != aux->value)
	{
		if (aux->median)
			ra_mov(*stack_a);
		else
			rra_mov(*stack_a);
	}
}

void	nodes_init_a(t_stack *stack_a, t_stack *stack_b)
{
	current_median(stack_a);
	current_median(stack_b);
	set_target_a(stack_a, stack_b);
	cost_analysis(stack_a, stack_b);
	set_cheapest(stack_a);
}

void	nodes_init_b(t_stack *stack_a, t_stack *stack_b)
{
	current_median(stack_a);
	current_median(stack_b);
	set_target_b(stack_a, stack_b);
}