/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_baselen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 17:48:19 by emcnab            #+#    #+#             */
/*   Updated: 2022/12/06 17:55:07 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_baselen(long l, long base)
{
	size_t	digit_count;
	long	l_abs;

	if (l == LONG_MIN)
		l = LONG_MAX;
	l_abs = ft_abslong(l);
	digit_count = 1;
	while (l_abs >= base)
	{
		digit_count++;
		l_abs /= base;
	}
	return (digit_count);
}
