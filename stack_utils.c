/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracurul <fracurul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 12:44:33 by fracurul          #+#    #+#             */
/*   Updated: 2024/03/21 19:02:12 by fracurul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief initialize a stack.
 *
 * @param stack already initialized.
 */
void	stack_init(t_stack *stack)
{
	stack->head = NULL;
	stack->size = 0;
}
/**
 * @brief fill the stack with the number we recieve.
 *
 * @param stack to be fill.
 * @param parsing value content to fill.
 * @param size number of values we've.
 */
void	stack_fill(t_stack *stack, int *parsing, int size)
{
	int i;

	i = 1;
	while(i < size)
	{
		node_to_tail(stack, create_node(parsing[i++]));
	}
}
/**
 * @brief delete stack.
 *
 * @param stack
 */
void	delete_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*aux;

	if((!stack && !stack->head) || !stack->head)
		return ;
	current = stack->head;
	while(current)
	{
		aux = current->next;
		delete_node(current);
		current = aux;
	}
	stack->head = NULL;
}
/**
 * @brief get stack size.
 *
 * @param stack
 * @return int size of the stack.
 */
int	stack_size(t_stack *stack)
{
	int	size;

	size = 0;
	if (!stack)
		return (0);
	while(stack)
	{
		stack->head = stack->head->next;
		size++;
	}
	return (size);
}
/**
 * @brief find the max value.
 *
 * @param stack
 * @return t_stack
 */
t_node	*find_max(t_stack *stack)
{
	int		max;
	t_node	*max_node;

	if (!stack)
		return (NULL);
	max = INT_MIN;
	while (stack->head)
	{
		if (stack->head->value > max)
		{
			max = stack->head->value;
			max_node = max;
		}
		stack->head = stack->head->next;
	}
	return (max_node);
}