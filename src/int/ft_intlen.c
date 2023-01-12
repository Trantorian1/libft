/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 14:18:46 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/12 16:07:25 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_intlen.h"

#include <limits.h>
#include "ft_abs.h"

/**
 * @brief Determine the number of digits composing [n].
 *
 * @param n (int): the number to get the length of.
 *
 * @return (size_t): the number of digits in [n].
 */
size_t	ft_intlen(int n)
{
	size_t	digit_count;
	int		n_abs;

	if (n == INT_MIN)
		n = INT_MAX;
	n_abs = ft_abs(n);
	digit_count = 1;
	while (n_abs >= 10)
	{
		digit_count++;
		n_abs /= 10;
	}
	return (digit_count);
}
