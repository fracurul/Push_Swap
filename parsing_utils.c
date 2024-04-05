/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracurul <fracurul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 19:24:40 by fracurul          #+#    #+#             */
/*   Updated: 2024/04/05 19:11:08 by fracurul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief converts parameters into long int type.
 *
 * @param str
 * @return long int return value.
 */
long	ft_atol(const char *str)
{
	int			i;
	int			sign;
	long		result;

	i = 0;
	sign = 1;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

/**
 * @brief check the parameter contais onlyn numbers.
 *
 * @param s parameter to check.
 * @return int 1 yes | 0 no.
 */
int	ft_isnbr(char *s)
{
	int	i;

	i = 0;
	if (s[i] && (s[i] == '+' || s[i] == '-'))
		i++;
	if (!ft_isdigit(s[i]))
		return (0);
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (0);
		i++;
	}
	return (1);
}

/**
 * @brief compare values
 *
 * @param s1 1st value.
 * @param s2 2nd value.
 * @return int 0 means same value.
 */
int	ft_nbrcmp(const char *s1, const char *s2)
{

	while (s1 && (*s1 == '+' || *s1 == '-'))
		s1++;
	if (!s1)
		return (0);
	while(*s1 == '0')
		s1++;
	while (s2 && (*s2 == '+' || *s2 == '-'))
		s2++;
	if (!s2)
		return (0);
	while(*s2 == '0')
		s2++;
	return (ft_strcmp(s1, s2));
}

/**
 * @brief check for duplicate values.
 *
 * @param argv list of values.
 * @return int 1 same value.
 */
int	ft_isdup(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i])
	{
		j = i + 1;
		while(argv[j])
		{
			if (ft_nbrcmp(argv[i], argv[j]) == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_del_matrix(char **str)
{
	int	i;

	i = -1;
	if (!str)
		return ;
	while (str[++i])
		free(str[i]);
	free(str);
}
