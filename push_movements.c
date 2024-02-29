/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_movements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracurul <fracurul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:17:24 by fracurul          #+#    #+#             */
/*   Updated: 2024/02/29 19:12:18 by fracurul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	ft_push(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*swap;

	if (!stack_a || !stack_a->head || stack_a->head->next)
		return ;
	swap = stack_a->head;
	stack_a->head = stack_a->head->next;
	stack_b = swap;
	swap->next = NULL;
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
