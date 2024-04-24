/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracurul <fracurul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 18:53:31 by fracurul          #+#    #+#             */
/*   Updated: 2024/04/24 21:35:49 by fracurul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*find_min(t_stack *stack)
{
	int		min;
	t_node	*min_node;
	t_node	*aux;

	if (!stack)
		return (NULL);
	min = INT_MAX;
	aux = stack->head;
	while (aux)
	{
		if (aux->value < min)
		{
			min = aux->value;
			min_node = aux;
		}
		aux = aux->next;
	}
	return (min_node);
}

t_node	*get_cheapest(t_stack *stack)
{
	t_node *aux;
	if (!stack)
		return(NULL);
	aux = stack->head;
	while(aux)
	{
		if (aux->cheapest)
			return (aux);
		aux = aux->next;
	}
	return (NULL);
}
void	r_both(t_stack **stack_a, t_stack **stack_b, t_node *cheapest)
{
	t_node	*aux_a;
	t_node	*aux_b;

	aux_a = (*stack_a)->head;
	aux_b = (*stack_b)->head;
	while ((*stack_b)->head != cheapest->target_node && (*stack_a)->head != cheapest)
	{
		// ft_printf("cheapest: %d\n", cheapest->value);
		// print_stack((*stack_a)->head);
		// ft_printf("target: %d\n", cheapest->target_node->value);
		//print_stack((*stack_b)->head);
		rr_mov(stack_a, stack_b);
		// (*stack_a)->head = (*stack_a)->head->next;
		// (*stack_b)->head = (*stack_b)->head->next;
	}
	// (*stack_a)->head = aux_a;
	// (*stack_b)->head = aux_b;
	current_average(*stack_a);
	current_average(*stack_b);
}

void	rr_both(t_stack **stack_a, t_stack **stack_b, t_node *cheapest)
{
	t_node	*aux_a;
	t_node	*aux_b;

	aux_a = (*stack_a)->head;
	aux_b = (*stack_b)->head;
	while ((*stack_b)->head != cheapest->target_node && (*stack_a)->head != cheapest)
	{
		rrr_mov(stack_a, stack_b);
		// aux_a = aux_a->next;
		// aux_b = aux_b->next;
	}
	current_average(*stack_a);
	current_average(*stack_b);
}