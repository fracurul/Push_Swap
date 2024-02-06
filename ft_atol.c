/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fracurul <fracurul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 19:18:51 by fracurul          #+#    #+#             */
/*   Updated: 2024/02/02 19:30:39 by fracurul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief converts parameters into long int type.
 * 
 * @param str 
 * @return long int return value.
 */

long int	ft_atol(const char *str)
{
	int		i;
	int		sign;
	long int	result;

	i = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * (long int)sign);
}