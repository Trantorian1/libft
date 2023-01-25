/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_closest_power_ul.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 14:07:17 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/25 14:08:41 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_closest_power_ul.h"

size_t	ft_closest_power_ul(size_t n, unsigned int pow)
{
	size_t	result;

	if (pow == 0)
		return (1);
	if (n == 0)
		return (0);
	result = 1;
	while (result < n)
	{
		if ((result * pow) < result)
			return (result);
		result *= pow;
	}
	return (result);
}
