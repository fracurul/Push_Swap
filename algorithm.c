/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracurul <fracurul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 18:49:16 by fracurul          #+#    #+#             */
/*   Updated: 2024/04/24 21:38:38 by fracurul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Get the max value object.
 *
 * @param stack
 * @return int with the max value.
 */
int	get_max_value(t_stack *stack)
{
	int		max_value;
	t_node *current;

	current = stack->head;
	max_value = current->max_value;
	while(current)
	{
		if(current->value > max_value)
			max_value = current->value;
		current = current->next;
	}
	return (max_value);
}

int	is_sorted(t_stack *stack)
{
	t_node	*aux;

	if (!stack && !stack->head)
		return (1);
	aux = stack->head;
	while(aux && aux->next)
	{
		if (aux->value > aux->next->value)
			return (0);
		aux = aux->next;
	}
	return (1);
}

void	sort3(t_stack **stack)
{
	int current;

	current = get_max_value(*stack);
	if (current == (*stack)->head->value)
		ra_mov(stack);
	if ((*stack)->head->next->value == current)
		rra_mov(stack);
	if ((*stack)->head->value > (*stack)->head->next->value)
		sa_mov(stack);
}

void	sort_stacks(t_stack **stack_a, t_stack **stack_b)
{

	if((*stack_a)->size > 3 && !is_sorted(*stack_a))
		pb_mov(stack_a, stack_b);
	if((*stack_a)->size > 3 && !is_sorted(*stack_a))
		pb_mov(stack_a, stack_b);
	while((*stack_a)->size > 3 && !is_sorted(*stack_a))
	{
		nodes_init_a(*stack_a, *stack_b);
		move_to_b(stack_a, stack_b);
	}
	if ((*stack_a)->size == 3)
		sort3(stack_a);
	print_stack((*stack_b)->head);
	while((*stack_b)->size)
	{
		nodes_init_b(*stack_a, *stack_b);
		move_to_a(stack_a, stack_b);
	}
	current_average(*stack_a);
	min_to_top(stack_a);
}
