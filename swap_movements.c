/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_movements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracurul <fracurul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:17:34 by fracurul          #+#    #+#             */
/*   Updated: 2024/02/29 19:10:55 by fracurul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stack *stack_a)
{
	t_node	*swap;

	if (!stack_a ||!stack_a->head || !stack_a ->head->next)
		return ;
	swap = stack_a ->head;
	stack_a->head = stack_a->head->next;
	stack_a->head->next = swap;
	swap->next = NULL;
}

void	sa_mov(t_stack *stack_a)
{
	ft_swap(stack_a);
	write(1, "sa\n", 3)
}

void	sb_mov(t_stack *stack_b)
{
	ft_swap(stack_b);
	write(1, "sb\n", 3);
}

void	ss_mov(t_stack *stack_a, t_stack *stack_b)
{
	ft_swap(stack_a);
	ft_swap(stack_b);
	write(1, "ss\n", 3);
}


