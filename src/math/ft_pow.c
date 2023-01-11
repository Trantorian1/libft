/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 08:51:59 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/11 16:50:06 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pow.h"

#include "ft_abs.h"

/*
 * @brief Raises the number [a] to the power [b].
 *
 * @param a (int): number to raise to the power of [b].
 * @param b (int): number to raise [a] to.
 *
 * return (double): [a]^[b].
 */
double	ft_pow(int a, int b)
{
	int	b_abs;
	int	pow;
	int	i;

	b_abs = ft_abs(b);
	pow = 1;
	i = 0;
	while (i <= b_abs)
	{
		pow *= a;
		i++;
	}
	if (b < 0)
		return (1.0 / pow);
	return (pow);
}
