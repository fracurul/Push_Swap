/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracurul <fracurul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 18:31:48 by fracurul          #+#    #+#             */
/*   Updated: 2024/02/02 19:42:34 by fracurul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_param_check(int argc, char **argv)
{

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

	i = 0;
	size = 0;
	while(argv[size][0])
		size++;
	values = (int *)malloc(size * sizeof(int));
	if(!values)
		return(values);
	while(argc < size)
	{
		if(ft_atol(argv[argc]) < INT_MIN || ft_atol(argv[argc]) > INT_MAX)
			return(free(values), NULL);
		else
			values[i++] = ft_atol(argv[argc++]);
	}
}
