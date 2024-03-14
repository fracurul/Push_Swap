/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_movements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracurul <fracurul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:17:24 by fracurul          #+#    #+#             */
/*   Updated: 2024/03/14 15:47:21 by fracurul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*push;

	if (!stack_a || !stack_a->head || stack_a->head->next)
		return ;
	push = stack_a->head;
	stack_a->head = stack_a->head->next;
	stack_b->head = push;
	push->next = NULL;
}

void	pa_mov(t_stack *stack_a, t_stack *stack_b)
{
	ft_push(stack_b, stack_a);
	write(1, "pa\n", 3);
}

void	pb_mov(t_stack *stack_a, t_stack *stack_b)
{
	ft_push(stack_a, stack_b);
	write(1, "pb\n", 3);
}
