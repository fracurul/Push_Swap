/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracurul <fracurul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:17:13 by fracurul          #+#    #+#             */
/*   Updated: 2024/05/02 15:52:05 by fracurul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static void	free_stack(t_stack **stack)
{
	t_stack	*node;
	t_stack	*tmp;
	if (!(*stack))
		return ;
	node = *stack;
	tmp = node;
	while (node->head)
	{
		tmp->head = node->head->next;
		node->head->value = 0;
		node->head->max_value = 0;
		node->head->push_cost = 0;
		node->head->abv_avg = 0;
		node->head->cheapest = 0;
		if (node->head->target_node)
			node->head->target_node = NULL;
		free(node->head);
		node = tmp;
	}
	if (node)
		free(node);
	*stack = NULL;
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**argv_cpy;
	int		i;

	stack_a = malloc(sizeof(t_stack));
	stack_b = malloc(sizeof(t_stack));
	stack_init(stack_a);
	stack_init(stack_b);
	i = 0;
	if (argc == 2 && !argv[1][0])
		return (write(2, "Error\n", 6), 1);
	if (argc > 1)
	{
		if (!ft_split_checker(argc, argv))
			return (write(2, "Error\n", 6), 1);
		else if (argc == 2)
		{
			argv_cpy = ft_split(argv[1], ' ');
			stack_fill(stack_a, ft_parsing(0, argv), matrix_size(argv));
			array_free(argv_cpy);
		}
		if	(argc > 2)
		{
				stack_fill(stack_a, ft_parsing(0, argv + 1), argc - 1);
		}
		if (!is_sorted(stack_a))
		{
			if(stack_a->size == 2)
				sa_mov(&stack_a);
			else if (stack_a->size == 3)
				sort_three(&stack_a);
			else
				sort_stacks(&stack_a, &stack_b);
		}
		delete_stack(stack_a);
	}
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
