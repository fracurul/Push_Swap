/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracurul <fracurul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 18:31:48 by fracurul          #+#    #+#             */
/*   Updated: 2024/03/14 21:54:58 by fracurul         ###   ########.fr       */
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
	parsed_value = ft_parsing(1, argv);
	if (!parsed_value)
		return(free(parsed_value), 0);
	while (++i < argc)
	{
		if(!ft_isnbr(argv[i]))
			return (free(parsed_value), 0);
	}
	if (!ft_isdup(argv))
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
			return (ft_del_matrix(spld_values), free(parsed_values), 0);
		while (spld_values[++i])
		{
			if (!ft_isnbr(spld_values[i]))
				return (ft_del_matrix(spld_values), free(parsed_values), 0);
		}
		if (!ft_isdup(spld_values))
			return (ft_del_matrix(spld_values), free(parsed_values), 0);
		return(ft_del_matrix(spld_values), free(parsed_values), 1);
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
	int	j;

	i = argc;
	j = 0;
	size = 0;
	while (argv[size])
		size++;
	values = (int *)malloc(size * sizeof(int));
	if (!values)
		return (values);
	while (i < size)
	{
		if (ft_atol(argv[i]) > INT_MIN || ft_atol(argv[i]) < INT_MAX)
			return (free(values), NULL);
		else
			values[i++] = (int)ft_atol(argv[j++]);
	}
	return (values);
}
