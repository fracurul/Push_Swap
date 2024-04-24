/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracurul <fracurul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:43:19 by fracurul          #+#    #+#             */
/*   Updated: 2024/04/24 20:03:34 by fracurul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Create a node object and put a value into it.
 *
 * @param value.
 * @return t_node.
 */
t_node	*create_node(int value)
{
	t_node	*new;

	new = ft_calloc(1, sizeof(t_node));
	if (!new)
		return (NULL);
	new->value = value;
	return (new);
}

/**
 * @brief moves a node at the top of the stack.
 *
 * @param stack target.
 * @param node value we need to move.
 */
void	node_to_head(t_stack *stack, t_node *node)
{
	if(!node || !stack)
		return ;
	if (!stack->head)
			stack->head = node;
	else
		node->next = stack->head;
		stack->head = node;
		stack->size++;
}

/**
 * @brief moves a node at the end fo the stack.
 *
 * @param stack target.
 * @param node value we need to move.
 */
void	node_to_tail(t_stack *stack, t_node *node)
{
	t_node *aux;

	if(!node || !stack)
		return ;
	if (stack->head == NULL)
		stack->head = node;
	else
	{
		aux = stack->head;
		while (aux->next)
			aux = aux->next;
		aux->next = node;
	}
	stack->size++;
}

void	delete_node(t_node *node)
{
	free (node);
}