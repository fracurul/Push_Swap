/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracurul <fracurul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 18:31:48 by fracurul          #+#    #+#             */
/*   Updated: 2024/05/02 17:15:47 by fracurul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/**
 * @brief checks parameters if there are more than 2 argc
 *
 * @param argc pnumber of arguments
 * @param argv amount of values we need to check
 * @return int 1 = valid paraneters || 0 = invalid parameters.
 */
int	ft_parse_checker(int argc, char **argv)
{
	int		*parsed_value;
	int		i;

	i = 0;
	parsed_value = ft_parsing(0, argv +  1);
	if (!parsed_value)
		return(free(parsed_value), 0);
	while (++i < argc)
	{
		if(!ft_isnbr(argv[i]))
			return (free(parsed_value), 0);
	}
	if (!ft_isdup(argv + 1))
		return (free(parsed_value), 0);
	return (free(parsed_value), 1);
}

/**
 * @brief check for correct parameters.
 *
 * @param argc number of arguments.
 * @param argv amount ofvalues we need to check.
 * @return int 1 = valid parameters || 0 = invalid parameters.
 */
int	ft_split_checker(int argc, char **argv)
{
	char	**spld_values;
	int		i;
	int		*parsed_values;

	i = -1;
	if (argc == 2)
	{
		spld_values = ft_split(argv[1], ' ');
		parsed_values = ft_parsing(0, spld_values);
		if (!spld_values || !parsed_values)
			return (array_free(spld_values), free(parsed_values), 0);
		while (spld_values[++i])
		{
			if (!ft_isnbr(spld_values[i]))
				return (array_free(spld_values), free(parsed_values), 0);
		}
		if (!ft_isdup(spld_values))
			return (array_free(spld_values), free(parsed_values), 0);
		return(array_free(spld_values), free(parsed_values), 1);
	}
	return (ft_parse_checker(argc, argv));
}

/**
 * @brief This functions converts the parameters into int types.
 *
 * @param argc the list of values we are going to check, it has to be 1.
 * argc 0 = executable.
 * @param argv values within our list, that we´re going to convert into
 * int type.
 * @return int* the list of values we need.
 */
int	*ft_parsing(int argc, char **argv)
{
	int	i;
	int	size;
	int	*values;

	i = argc;
	size = 0;
	while (argv[size])
		size++;
	values = (int *)malloc(size * sizeof(int));
	if (!values)
		return (values);
	while (i < size)
	{
		if (ft_atol(argv[i]) < INT_MIN || ft_atol(argv[i]) > INT_MAX)
			return (free(values), NULL);
		else
			values[i] = (int)ft_atol(argv[i]);
		i++;
	}
	return (values);
}

int	check_parameters(int argc, char **argv, t_stack *stack_a)
{
	char	**argv_cpy;
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
				stack_fill(stack_a, ft_parsing(0, argv + 1), argc - 1);
	}
	return (0);
}