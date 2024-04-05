/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracurul <fracurul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:17:13 by fracurul          #+#    #+#             */
/*   Updated: 2024/04/05 18:38:17 by fracurul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

#include <stdio.h>

void	print_stack(t_node *current)
{
	while (current)
	{
		printf("%d\n", current->value);
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
	i = -1;
	if (argc == 2 && !argv[1][0])
		return (write(2, "Error\n", 6), 1);
	if (argc > 1)
	{
		if (!ft_split_checker(argc, argv))
			return (write(2, "Error\n", 6), 1);
		else if (argc == 2)
		{
			argv = ft_split(argv[1], ' ');
			stack_fill(stack_a, ft_parsing(0, argv + 1), ft_strlen(*argv) - 1);
		}
		if	(argc > 2)
		{
				stack_fill(stack_a, ft_parsing(0, argv + 1), argc - 1);
		}
		if (!is_sorted(stack_a))
		{
			if(stack_a->size == 2)
				sa_mov(stack_a);
			else if (stack_a->size == 3)
				sort3(&stack_a);
			else
				sort_stacks(&stack_a, &stack_b);
		}
		delete_stack(stack_a);
	}
	return (0);
}