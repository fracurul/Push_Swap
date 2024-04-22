/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracurul <fracurul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 18:53:31 by fracurul          #+#    #+#             */
/*   Updated: 2024/04/16 13:00:56 by fracurul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*find_min(t_stack *stack)
{
	int	min;
	t_node *min_node;

	if (!stack)
		return (NULL);
	min = INT_MAX;
	while (stack)
	{
		if (stack->head->value < min)
		{
			min = stack->head->value;
			min_node = stack->head;
		}
		stack->head = stack->head->next;
	}
	return (min_node);
}

t_node	*get_cheapest(t_stack *stack)
{
	if (!stack)
		return(NULL);
	while(stack->head)
	{
		if (stack->head->cheapest)
			return (stack->head);
		stack->head = stack->head->next;
	}
	return (NULL);
}
void	r_both(t_stack **stack_a, t_stack **stack_b, t_node *cheapest)
{
	t_node	*aux_a;
	t_node	*aux_b;

	aux_a = (*stack_a)->head;
	aux_b = (*stack_b)->head;
	while (aux_b != cheapest->target_node && aux_a != cheapest)
	{
		rr_mov(stack_a, stack_b);
		aux_a = aux_a->next;
		aux_b = aux_b->next;
	}
	current_average(*stack_a);
	current_average(*stack_b);
}

void	rr_both(t_stack **stack_a, t_stack **stack_b, t_node *cheapest)
{
	t_node	*aux_a;
	t_node	*aux_b;

	aux_a = (*stack_a)->head;
	aux_b = (*stack_b)->head;
	while (aux_b != cheapest->target_node && aux_a != cheapest)
	{
		rrr_mov(stack_a, stack_b);
		aux_a = aux_a->next;
		aux_b = aux_b->next;
	}
	current_average(*stack_a);
	current_average(*stack_b);
}