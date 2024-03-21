/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracurul <fracurul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 20:22:31 by fracurul          #+#    #+#             */
/*   Updated: 2024/03/21 20:51:17 by fracurul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_target_b(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*current_a;
	t_stack	*target;
	int		match;

	match = INT_MAX;
	current_a = stack_a;
	while (stack_b)
	{
		while (current_a->head)
		{
			if (current_a->head->value > stack_b->head->value
				&& current_a->head->value < match)
			{
				match = current_a->head->value;
				target = current_a;
			}
			current_a->head = current_a->head->next;
		}
	}
	if (match == INT_MAX)
		stack_b->head->target_node = find_min(stack_a);
	else
		stack_b->head->target_node = target;
	stack_b = stack_b->head->next;
}
