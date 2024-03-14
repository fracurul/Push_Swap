/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracurul <fracurul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:43:19 by fracurul          #+#    #+#             */
/*   Updated: 2024/03/14 20:33:16 by fracurul         ###   ########.fr       */
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

	new = malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->value = value;
	new->next = NULL;
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
	t_node *aux;

	if (!stack || !node)
		return ;
	aux = stack->head;
	stack->head = node;
	stack->head->next = aux;
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

	if (!stack || !node)
		return ;
	aux = stack->head;
	while (aux->next)
		aux = aux->next;
	aux->next = node;
	node->next = NULL;
	stack->size++;
}

void	delete_node(t_node *node)
{
	free (node);
}