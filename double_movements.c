/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_movements.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracurul <fracurul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 19:58:43 by fracurul          #+#    #+#             */
/*   Updated: 2024/02/01 21:08:10 by fracurul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss_mov(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*a_swap;
	t_node	*b_swap;

	if (!stack_a || !stack_a->head || stack_a->head->next
		|| !stack_b || !stack_b->head || stack_b->head->next)
		return ;
	a_swap = stack_a->head;
	stack_a->head = stack_a->head->next;
	stack_a->head->next = swap;
	a_swap->next = NULL;
	b_swap = stack_b->head;
	stack_b->head = stack_b->head->next;
	stack_b->head->next = b_swap;
	b_swap->next = NULL;
}

void	rr_mov(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*a_swap;
	t_node	*a_rotation;
	t_node	*b_swap;
	t_node	*b_rotation;

	if (!stack_a || !stack_a->head || stack_a->head->next
		|| !stack_b || !stack_b->head || stack_b->head->next)
		return ;
	a_swap = stack_a->head;
	a_rotation = stack_a->head;
	b_swap = stack_b->head;
	b_rotation = stack_b->head;
	while (a_rotation->next || b_rotation->next)
	{
		while (a_rotation->next)
			a_rotation = a_rotation->next;
		while (b_rotation->next)
			b_rotation = b_rotation->next;
	}
	a_rotation->next = a_swap;
	a_swap->next = NULL;
	b_rotation->next = b_swap;
	b_swap->next = NULL;
}

void	rrr_mov(t_stack *stack_a, t_stack *stack_b)
{
	rra_mov(stack_a);
	rrb_mov(stack_b);
}
