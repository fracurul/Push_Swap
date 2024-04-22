/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_movements.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracurul <fracurul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 19:05:46 by fracurul          #+#    #+#             */
/*   Updated: 2024/04/22 17:31:45 by fracurul         ###   ########.fr       */
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
