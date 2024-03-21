/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracurul <fracurul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 18:49:22 by fracurul          #+#    #+#             */
/*   Updated: 2024/03/21 20:15:36 by fracurul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief looks for the median value in the stack
 *
 * @param stack
 */
void	current_median(t_stack *stack)
{
	int	i;
	int median;

	i = 0;
	if (!stack)
		return ;
	median = stack->size / 2;
	while (stack->head)
	{
		stack->head->max_value = i;
		if (i <= median)
			stack->head->median = 1;
		else
			stack->head->median = 0;
		stack->head = stack->head->next;
		i++;
	}
}
/**
 * @brief Set the target object to a from stack_b.
 *
 * @param stack_a
 * @param stack_b
 */
void	set_target_a(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*current_b;
	t_stack	*target;
	int		match;

	while (stack_a)
	{
		match = INT_MIN;
		current_b = stack_b;
		while (current_b)
		{
			if (current_b->head->value < stack_a->head->value
				&& current_b->head->value > match)
			{
				match - current_b->head->value;
				target = current_b;
			}
			current_b = current_b->head->next;
		}
		if (match == INT_MIN)
			stack_a->head->target_node = find_max(stack_b);
		else
			stack_a->head->target_node = target;
		stack_a->head = stack_a->head->next;
	}
}
/**
 * @brief calculate pus_cost for each stack_a node.
 *
 * @param stack_a
 * @param stack_b
 */
void	cost_analysis(t_stack *stack_a, t_stack *stack_b)
{
	int	size_a;
	int size_b;

	size_a = stack_a->size;
	size_b = stack_b->size;
	while (stack_a->head)
	{
		stack_a->head->push_cost = stack_a->head->max_value;
		if (!(stack_a->head->median))
			stack_a->head->push_cost = size_a - (stack_a->head->max_value);
		if (stack_a->head->target_node->median)
			stack_a->head->push_cost = stack_a->head->target_node->max_value;
		else
			stack_a->head->push_cost += size_b - (stack_a->head->target_node->max_value);
		stack_a->head = stack_a->head->next;
	}
}
/**
 * @brief looks for the node with the cheapest push_cost
 * and put cheapest node at true.
 *
 * @param stack
 */
void	set_cheapest(t_stack *stack)
{
	int	cheapest_value;
	t_stack	*cheapest_stack;

	if (!stack->head)
		return ;
	cheapest_value = INT_MIN;
	while (stack->head)
	{
		if (stack->head->push_cost > cheapest_value)
		{
			cheapest_value = stack->head->push_cost;
			cheapest_stack = stack;
		}
		stack->head = stack->head->next;
	}
	cheapest_stack->head->cheapest = 1;
}

void	get_node_push(t_stack **stack, t_stack *top_node, char *name)
{
	if (name == "stack_a")
	{
		if (top_node->head->median)
			ra_mov(stack);
		else
			rra_mov(stack);
	}
	else if (name == "stack_b")
	{
		if (top_node->head->median)
			rb_mov(stack);
		else
			rrb_mov(stack);
	}
}