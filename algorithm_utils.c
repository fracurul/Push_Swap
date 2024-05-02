/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracurul <fracurul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 18:49:22 by fracurul          #+#    #+#             */
/*   Updated: 2024/05/02 15:53:50 by fracurul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief looks for the median value in the stack
 *
 * @param stack
 */
void	current_average(t_stack *stack)
{
	int		i;
	int		avg;
	t_node	*aux;

	i = 0;
	if (!stack)
		return ;
	aux = stack->head;
	avg = stack->size / 2;
	while (aux)
	{
		aux->max_value = i;
		if (i <= avg)
			aux->abv_avg = 1;
		else
			aux->abv_avg = 0;
		aux = aux->next;
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
	t_node	*current_b;
	t_node	*aux_a;
	long	match;

	aux_a = stack_a->head;
	while (aux_a)
	{
		match = LONG_MIN;
		current_b = stack_b->head;
		while (current_b)
		{
			if (current_b->value < aux_a->value && (long)current_b->value > match)
			{
				match = current_b->value;
				aux_a->target_node = current_b;
			}
			current_b = current_b->next;
		}
		if (match == LONG_MIN)
			aux_a->target_node = find_max(stack_b);
		aux_a = aux_a->next;
	}
}

/**
 * @brief calculate the max input.
 *
 * @param a 1st value.
 * @param b 2nd value.
 * @return int max output.
 */
static int	mx(int a, int b)
{
	if (a >= b)
		return (a);
	return (b);
}
/**
 * @brief calculate pus_cost for each stack_a node.
 *
 * @param stack_a
 * @param stack_b
 */

void	cost_analysis(t_stack *stack_a, t_stack *stack_b)
{
	int		size_a;
	int		size_b;
	t_node	*aux_a;
	int		t_idx;
	int		a_idx;

	size_a = stack_size(stack_a);
	size_b = stack_size(stack_b);
	aux_a = stack_a->head;
	while (aux_a)
	{
		a_idx = aux_a->max_value;
		t_idx = aux_a->target_node->max_value;
		if (aux_a->abv_avg  && (aux_a->target_node->abv_avg || t_idx - a_idx < (size_b + 1) / 2))
			aux_a->push_cost = mx(a_idx, t_idx);
		else if (!aux_a->abv_avg && (!aux_a->target_node->abv_avg || t_idx + size_a - a_idx > (size_b + 1) / 2))
			aux_a->push_cost = mx(size_a - a_idx + 1, size_b - t_idx + 1);
		else if (aux_a->abv_avg)
			aux_a->push_cost = a_idx + (size_b - t_idx +1);
		else
			aux_a->push_cost = (size_a - a_idx + 1) + t_idx;
		aux_a = aux_a->next;
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
	long		cheapest_value;
	t_node	*cheapest_node;
	t_node	*aux;

	aux = stack->head;
	if (!aux)
		return ;
	cheapest_value = LONG_MAX;
	while (aux->next)
	{
		if ((long)aux->push_cost < cheapest_value)
		{
			cheapest_value = aux->push_cost;
			cheapest_node = aux;
		}
		aux = aux->next;
	}
	cheapest_node->cheapest = 1;
}
