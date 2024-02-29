/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_movements.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracurul <fracurul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 19:05:46 by fracurul          #+#    #+#             */
/*   Updated: 2024/02/29 19:19:51 by fracurul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rrotation(t_stack *stack_a)
{
	t_node	*prev_node;
	t_node	*r_rotation;

	if (!stack_a || !stack_a->head || !stack_a->head->next)
		return ;
	prev_node = NULL;
	r_rotation = stack_a->head;
	while (r_rotation->next)
	{
		prev_node = r_rotation;
		r_rotation = r_rotation->next;
	}
	prev_node->next = NULL;
	r_rotation->next = stack_a->head;
	stack_a->head = r_rotation;
}

void	rra_mov(t_stack *stack_a)
{
	ft_rrotation(stack_a);
	write(1, "rra\n", 4);
}

void	rrb_mov(t_stack *stack_a)
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