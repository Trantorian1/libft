/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_closest_power.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 11:21:38 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/13 16:25:04 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_closest_power.h"

int	ft_closest_power(int n, unsigned int pow)
{
	int	result;

	if (pow == 0)
		return (1);
	if (n == 0)
		return (0);
	result = 1;
	while (result < n)
	{
		if ((int)(result * pow) < result)
			return (result);
		result *= pow;
	}
	return (result);
}
