/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracurul <fracurul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 18:49:16 by fracurul          #+#    #+#             */
/*   Updated: 2024/05/02 16:14:46 by fracurul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	t_node	*aux;

	if (stack_size(stack) < 2)
		return (1);
	aux = stack->head;
	while(aux && aux->next)
	{
		if (aux->value > aux->next->value)
			return (0);
		aux = aux->next;
	}
	return (1);
}

void	stack_limits(int *min, int *max, t_node *node)
{
	int	i;
	int	min_value;
	int	max_value;

	i = 1;
	*min = 1;
	*max = 1;
	min_value = node->value;
	max_value = node->value;
	while(++i <= 3)
	{
		node = node->next;
		if (min_value > node->value)
		{
			min_value = node->value;
			*min = i;
		}
		if (max_value < node->value)
		{
			max_value = node->value;
			*max = i;
		}
	}
}

void	sort_three(t_stack **stack)
{
	t_stack	*tmp;
	int		min;
	int		max;
	int		i;

	i = 0;
	tmp = (*stack);
	if (is_sorted(*stack))
		return ;
	stack_limits(&min, &max, (*stack)->head);
	if (max == 1)
		ra_mov(stack);
	else if ((min == 1) || (max == 3))
		sa_mov(stack);
	else if (min == 3)
		rra_mov(stack);
	if (!is_sorted(*stack))
		sort_three(stack);
}

void	sort_stacks(t_stack **stack_a, t_stack **stack_b)
{

	if (stack_size(*stack_a) > 3 && !is_sorted(*stack_a))
		pb_mov(stack_a, stack_b);
	if (stack_size(*stack_a) > 3 && !is_sorted(*stack_a))
		pb_mov(stack_a, stack_b);
	while (stack_size(*stack_a) > 3 && !is_sorted(*stack_a))
	{
		nodes_init_a(*stack_a, *stack_b);
		move_to_b(stack_a, stack_b);
	}
	if (stack_size(*stack_a) == 3)
		sort_three(stack_a);
	while((*stack_b)->size)
	{
		nodes_init_b(*stack_a, *stack_b);
		move_to_a(stack_a, stack_b);
	}
	current_average(*stack_a);
	min_to_top(stack_a);
}
