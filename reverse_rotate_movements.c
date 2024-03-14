/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_movements.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracurul <fracurul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 19:05:46 by fracurul          #+#    #+#             */
/*   Updated: 2024/03/13 13:25:32 by fracurul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rrotation(t_stack *stack)
{
	t_node	*prev_node;
	t_node	*r_rotation;

	if (!stack || !stack->head || !stack->head->next)
		return ;
	prev_node = NULL;
	r_rotation = stack->head;
	while (r_rotation->next)
	{
		prev_node = r_rotation;
		r_rotation = r_rotation->next;
	}
	prev_node->next = NULL;
	r_rotation->next = stack->head;
	stack->head = r_rotation;
}

void	rra_mov(t_stack *stack_a)
{
	ft_rrotation(stack_a);
	write(1, "rra\n", 4);
}

void	rrb_mov(t_stack *stack_b)
{
	ft_rrotation(stack_b);
	write(1, "rrb\n", 4);
}

void	rrr_mov(t_stack *stack_a, t_stack *stack_b)
{
	ft_rrotation(stack_a);
	ft_rrotation(stack_b);
	write(1, "rrr\n", 4);
}
