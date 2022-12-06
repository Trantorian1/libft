/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_longlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 14:20:14 by emcnab            #+#    #+#             */
/*   Updated: 2022/12/06 14:23:41 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * @brief Determine the number of digits composing [l].
 *
 * @param l (long): the number to get the length of.
 *
 * @return (size_t): the number of digits in [n_abs].
 */
size_t	ft_longlen(long l)
{
	size_t	digit_count;
	long	l_abs;

	l_abs = ft_abslong(l);
	digit_count = 1;
	while (l_abs >= 10)
	{
		digit_count++;
		l_abs /= 10;
	}
	return (digit_count);
}
