/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 08:51:59 by emcnab            #+#    #+#             */
/*   Updated: 2022/11/20 15:42:11 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
	int	b_abs = ft_abs(b);
	int	pow   = 1;
	int	i     = 0;

	while (i <= b_abs)
	{
		pow *= a;
		i++;
	}
	if (b < 0)
		return (1.0 / pow);
	return (pow);
}
