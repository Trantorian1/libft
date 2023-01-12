/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 08:39:58 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/12 15:03:42 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_atoi.h"

#include <stddef.h>
#include "ft_isspace.h"
#include "ft_isdigit.h"

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
int	ft_atoi(const char *str_int)
{
	size_t	i;
	int		sign;
	int		result;

	i = 0;
	sign = 1;
	result = 0;
	while (ft_isspace((unsigned char)str_int[i]))
		i++;
	if (str_int[i] == '+')
		i++;
	else if (str_int[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (ft_isdigit((unsigned char)str_int[i]))
	{
		result = result * 10 + (str_int[i] - '0');
		i++;
	}
	return (result * sign);
}
