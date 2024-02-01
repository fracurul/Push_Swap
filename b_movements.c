/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_movements.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracurul <fracurul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:17:24 by fracurul          #+#    #+#             */
/*   Updated: 2024/02/01 20:09:30 by fracurul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb_mov(t_stack *stack_b)
{
	t_node	*swap;

	if (!stack_b || !stack_b->head || stack_b->head->next)
		return ;
	swap = stack_b->head;
	stack_b->head = stack_b->head->next;
	stack_b->head->next = swap;
	swap->next = NULL;
}

void	pb_mov(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*swap;

	if (!stack_a || !stack_a->head || stack_a->head->next)
		return ;
	swap = stack_a->head;
	stack_a->head = stack_a->head->next;
	stack_b = swap;
	swap->next = NULL;
}

void	rb_mov(t_stack *stack_b)
{
	t_node	*swap;
	t_node	*rotation;

	if (!stack_b || !stack_b->head || stack_b->head->next)
		return ;
	swap = stack_b->head;
	rotation = stack_b->head;
	while (rotation->next)
		rotation = rotation->next;
	rotation->next = swap;
	swap->next = NULL;
}

void	rrb_mov(t_stack *stack_b)
{
	t_node	*prev_node;
	t_node	*r_rotation;

	if (!stack_b || !stack_b->head || stack_b->head->next)
		return ;
	prev_node = NULL;
	r_rotation = stack_b->head;
	while (r_rotation->next)
	{
		prev_node = r_rotation;
		r_rotation = r_rotation->next;
	}
	prev_node->next = NULL;
	r_rotation->next = stack_b->head;
	stack_b->head = r_rotation;
}
