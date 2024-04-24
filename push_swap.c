/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracurul <fracurul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:17:13 by fracurul          #+#    #+#             */
/*   Updated: 2024/04/24 21:31:48 by fracurul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

#include <stdio.h>

void	print_stack(t_node *current)
{
	while (current)
	{
		printf("valor del nodo:%d|\n ", current->value);
		// printf("mediana%d |", current->abv_avg);
		// printf("index %d |", current->max_value);
		// printf("coste%d |", current->push_cost);
		// if (current->target_node)
		// 	printf("target node %d |\n", current->target_node->value);
		// printf("cheapest %d\n", current->cheapest);
		current = current->next;
	}
	printf("\n");
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
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
			argv = ft_split(argv[1], ' ');
			stack_fill(stack_a, ft_parsing(0, argv), matrix_size(argv));
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
				sort3(&stack_a);
			else
				sort_stacks(&stack_a, &stack_b);
		}
		/*pb_mov(&stack_a, &stack_b);
		pb_mov(&stack_a, &stack_b);
		rb_mov(&stack_b);
		print_stack(stack_b->head);
		print_stack(stack_a->head);
		pa_mov(&stack_a, &stack_b);
		pa_mov(&stack_a, &stack_b);
		ra_mov(&stack_a);
		print_stack(stack_a->head);*/
		//print_stack(stack_b->head);
		delete_stack(stack_a);
	}
	return (0);
}