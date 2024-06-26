/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_movements.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracurul <fracurul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 19:58:43 by fracurul          #+#    #+#             */
/*   Updated: 2024/05/02 16:12:11 by fracurul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	ft_rotate(t_stack **stack)
{
	t_node	*node;
	t_node	*rotation;
	t_node 	*start;

	if (!(*stack) || !(*stack)->head || !(*stack)->head->next)
		return ;
	node = (*stack)->head->next;
	start = node;
	rotation = (*stack)->head;
	while (node->next)
		node = node->next;
	node->next = rotation;
	rotation->next = NULL;
	(*stack)->head = start;
}


void	ra_mov(t_stack **stack_a)
{

	ft_rotate(stack_a);
	write(1, "ra\n", 3);
}

void	rb_mov(t_stack **stack_b)
{
	ft_rotate(stack_b);
	write(1, "rb\n", 3);
}

void	rr_mov(t_stack **stack_a, t_stack **stack_b)
{
	ft_rotate(stack_a);
	ft_rotate(stack_b);
	write(1, "rr\n", 3);
}

void	r_both(t_stack **stack_a, t_stack **stack_b, t_node *cheapest)
{
	t_node	*aux_a;
	t_node	*aux_b;

	aux_a = (*stack_a)->head;
	aux_b = (*stack_b)->head;
	while ((*stack_b)->head != cheapest->target_node && (*stack_a)->head != cheapest)
	{
		rr_mov(stack_a, stack_b);
	}
	current_average(*stack_a);
	current_average(*stack_b);
}
