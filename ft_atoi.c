/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 08:39:58 by emcnab            #+#    #+#             */
/*   Updated: 2022/11/20 15:30:03 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * @brief Converts a string representation of an integer back to its int value.
 * 	Stops at the first non-digit character and only allows a single sign 
 * 	character. Does not handle buffer overflows.
 *
 * @param str_int (t_str): string representation of the the integer to 
 * 	retrieve.
 *
 * @return (int): integer value of str_int.
 */
int	ft_atoi(t_str str_int)
{
	size_t	i      = 0;
	int		sign   = 1;
	int		result = 0;

	while (ft_isspace(str_int[i]))
		i++;
	if (str_int[i] == '+')
		i++;
	else if (str_int[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (ft_isdigit(str_int[i]))
	{
		result = result * 10 + (str_int[i] - '0');
		i++;
	}
	return (result * sign);
}
