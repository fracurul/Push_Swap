/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracurul <fracurul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 18:49:16 by fracurul          #+#    #+#             */
/*   Updated: 2024/03/21 21:04:22 by fracurul         ###   ########.fr       */
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
	while(!current)
	{
		if(current->max_value > max_value)
			max_value = current->max_value;
		current = current->next;
	}
	return (max_value);
}

int	is_sorted(t_stack *stack)
{
	if(!stack)
		return (1);
	while(stack->head->next)
	{
		if(stack->head->value > stack->head->next->value)
			return (0);
		stack->head = stack->head->next;
	}
}

void	sort3(t_stack **stack)
{
	t_node	*current;

	current = get_max_value(*stack);
	if(current->max_value == *stack)
		ra_mov(stack);
	else if((*stack)->head->next == current->max_value)
		rra_mov(stack);
	if((*stack)->head > (*stack)->head->next)
		sa_mov(stack);
}

void	sort_stacks(t_stack **stack_a, t_stack **stack_b)
{
	int size_a;

	size_a = (*stack_a)->size;
	if(size_a-- > 3 && is_sorted(*stack_a))
		pb_mov(stack_a, stack_b);
	if(size_a-- > 3 && is_sorted(*stack_a))
		pb_mov(stack_a, stack_b);
	while(size_a-- > 3 && is_sorted(*stack_a))
	{
		nodes_init(*stack_a, *stack_b);
		move_to_b(stack_a, stack_b);
	}
	sort3(stack_a);
	while(*stack_b)
	{
		nodes_init_b(*stack_a, *stack_b);
		move_to_a(stack_a, stack_b);
	}
	current_median(*stack_a);
	min_to_top(stack_a);
}
