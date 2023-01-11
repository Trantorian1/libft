/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abslong.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 14:07:08 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/11 16:50:08 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_abslong.h"

/**
 * @brief Calculates the absolute value of a long integer.
 *
 * Does not handle long overflows, therefore passing LONG_MIN as a parameter
 * will still return LONG_MIN.
 *
 * @param n (long): the long to get the absolute value of
 *
 * @return (long): absolute value of [n].
 */
long	ft_abslong(long n)
{
	if (n < 0)
		return (-n);
	return (n);
}
