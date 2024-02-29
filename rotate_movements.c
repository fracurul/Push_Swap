/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_movements.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracurul <fracurul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 19:58:43 by fracurul          #+#    #+#             */
/*   Updated: 2024/02/29 19:11:56 by fracurul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_stack *stack_a)
{
	t_node	*swap;
	t_node	*rotation;

	if (!stack_a || !stack_a->head || !stack_a->head->next)
		return ;
	swap = stack_a->head;
	rotation = stack_a->head;
	while (rotation->next)
		rotation = rotation->next;
	rotation->next = swap;
	swap->next = NULL;
}

void	ra_mov(t_stack *stack_a)
{
	ft_rotate(stack_a);
	write(1, "ra\n", 3);
}

void	rb_mov(t_stack *stack_b)
{
	ft_rotate(stack_b);
	write(1, "rb\n", 3);
}

void	rr_mov(t_stack *stack_a, t_stack *stack_b)
{
	ft_rotate(stack_a);
	ft_rotate(stack_b);
	write(1, "rr\n", );
}
