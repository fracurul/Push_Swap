/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracurul <fracurul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 20:22:31 by fracurul          #+#    #+#             */
/*   Updated: 2024/04/12 16:38:13 by fracurul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_target_b(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*current_a;
	t_node	*target;
	t_node	*aux_b;
	int		match;

	aux_b = stack_b->head;
	while (aux_b)
	{
		match = INT_MAX;
		current_a = stack_a->head;
		while (current_a->next)
		{
			if (current_a->value > aux_b->value
				&& current_a->value < match)
			{
				match = current_a->value;
				target = current_a;
			}
			current_a = current_a->next;
		}
		aux_b->target_node = target;
		aux_b = aux_b->next;
	}
}

int	matrix_size(char **argv)
{
	int	i;

	i = -1;
	while (argv[++i])
		;
	return (i);
}
