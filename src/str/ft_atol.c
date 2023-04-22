/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 12:06:03 by emcnab            #+#    #+#             */
/*   Updated: 2023/04/22 16:11:22 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_atol.h"

#include <stddef.h>

#include "ft_isspace.h"
#include "ft_isdigit.h"

long	ft_atol(const char *str_int)
{
	size_t	index;
	int		sign;
	long	result;

	index = 0;
	sign = 1;
	result = 0;
	while (ft_isspace(str_int[index]))
		index++;
	if (str_int[index] == '+')
		index++;
	if (str_int[index] == '-')
	{
		sign = -1;
		index++;
	}
	while (ft_isdigit(str_int[index]))
	{
		result = result * 10 + (str_int[index] - '0');
		index++;
	}
	return (result * sign);
}
