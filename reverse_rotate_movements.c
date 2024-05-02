/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_movements.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracurul <fracurul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 19:05:46 by fracurul          #+#    #+#             */
/*   Updated: 2024/05/02 16:11:52 by fracurul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rrotation(t_stack **stack)
{
	t_node	*rotation;
	if (!(*stack) || !(*stack)->head)
		return ;
	rotation = (*stack)->head;
	while (rotation->next->next)
		rotation = rotation->next;
	rotation->next->next = (*stack)->head;
	(*stack)->head = rotation->next;
	rotation->next = NULL;
}

void	rra_mov(t_stack **stack_a)
{
	ft_rrotation(stack_a);
	write(1, "rra\n", 4);
}

void	rrb_mov(t_stack **stack_b)
{
	ft_rrotation(stack_b);
	write(1, "rrb\n", 4);
}

void	rrr_mov(t_stack **stack_a, t_stack **stack_b)
{
	ft_rrotation(stack_a);
	ft_rrotation(stack_b);
	write(1, "rrr\n", 4);
}

void	rr_both(t_stack **stack_a, t_stack **stack_b, t_node *cheapest)
{
	t_node	*aux_a;
	t_node	*aux_b;

	aux_a = (*stack_a)->head;
	aux_b = (*stack_b)->head;
	while ((*stack_b)->head != cheapest->target_node && (*stack_a)->head != cheapest)
	{
		rrr_mov(stack_a, stack_b);
	}
	current_average(*stack_a);
	current_average(*stack_b);
}
