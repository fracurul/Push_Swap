/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracurul <fracurul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 12:44:33 by fracurul          #+#    #+#             */
/*   Updated: 2024/05/02 16:09:09 by fracurul         ###   ########.fr       */
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
void	 stack_fill(t_stack *stack, int *parsing, int size)
{
	int	i;

	i = -1;
	while(++i < size)
		node_to_tail(stack, create_node(parsing[i]));
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
		free(current);
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
	t_node	*aux;
	int	size;

	size = 0;
	aux = stack->head;
	if (!stack)
		return (0);
	while(stack && aux->next)
	{
		aux = aux->next;
		size++;
	}
	size++;
	return (size);
}
/**
 * @brief put the node want to move at the top of the stack.
 *
 * @param stack stack we've.
 * @param top_node nod we want to be 1st.
 * @param n flag to choose the stack we want.
 */
void	get_node_push(t_stack **stack, t_node *top_node, int n)
{
	while((*stack)->head != top_node)
	{
		if (n == 1)
		{
			if (top_node->abv_avg)
				ra_mov(stack);
			else
				rra_mov(stack);
		}
		else if (n == 2)
		{
			if (top_node->abv_avg)
				rb_mov(stack);
			else
				rrb_mov(stack);
		}
	}
}
