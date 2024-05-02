/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracurul <fracurul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:43:19 by fracurul          #+#    #+#             */
/*   Updated: 2024/05/02 16:17:32 by fracurul         ###   ########.fr       */
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

void	nodes_init_a(t_stack *stack_a, t_stack *stack_b)
{
	current_average(stack_a);
	current_average(stack_b);
	set_target_a(stack_a, stack_b);
	cost_analysis(stack_a, stack_b);
	set_cheapest(stack_a);
}

void	nodes_init_b(t_stack *stack_a, t_stack *stack_b)
{
	current_average(stack_a);
	current_average(stack_b);
	set_target_b(stack_a, stack_b);
}

void	array_free(char **array)
{
	int	i;

	i = -1;
	while (array[++i])
		free(array[i]);
	free(array);
}