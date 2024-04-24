/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracurul <fracurul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 20:22:31 by fracurul          #+#    #+#             */
/*   Updated: 2024/04/24 21:31:09 by fracurul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_target_b(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*current_a;
	t_node	*aux_b;
	long	match;

	aux_b = stack_b->head;
	while (aux_b)
	{
		match = LONG_MAX;
		current_a = stack_a->head;
		while (current_a)
		{
			if (current_a->value > aux_b->value
				&& (long)current_a->value < match)
			{
				match = current_a->value;
				aux_b->target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (match > INT_MAX)
			aux_b->target_node = find_min(stack_a);
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
