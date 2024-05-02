/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracurul <fracurul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 18:53:31 by fracurul          #+#    #+#             */
/*   Updated: 2024/05/02 16:14:10 by fracurul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief find the node with max value.
 *
 * @param stack
 * @return t_stack node with the max value.
 */
t_node	*find_max(t_stack *stack)
{
	int		max;
	t_node	*max_node;
	t_node	*aux;

	if (!stack)
		return (NULL);
	max = INT_MIN;
	aux = stack->head;
	while (aux)
	{
		if (aux->value > max)
		{
			max = aux->value;
			max_node = aux;
		}
		aux = aux->next;
	}
	return (max_node);
}

/**
 * @brief find the node with min value.
 *
 * @param stack
 * @return t_stack node with the min value.
 */
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
