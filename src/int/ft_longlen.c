/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_longlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 14:20:14 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/11 16:44:35 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <limits.h>

/**
 * @brief Determine the number of digits composing [l].
 * 
 * @param l (long): the number to get the length of.
 *
 * @return (size_t): the number of digits in [l].
 */
size_t	ft_longlen(long l)
{
	size_t	digit_count;
	long	l_abs;

	if (l == LONG_MIN)
		l = LONG_MAX;
	l_abs = ft_abslong(l);
	digit_count = 1;
	while (l_abs >= 10)
	{
		digit_count++;
		l_abs /= 10;
	}
	return (digit_count);
}
