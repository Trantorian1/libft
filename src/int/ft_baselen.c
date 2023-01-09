/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_baselen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 17:48:19 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/09 15:54:18 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/int.h"

size_t	ft_baselen(unsigned long l, size_t base)
{
	size_t	digit_count;

	digit_count = 1;
	while ((size_t)l >= base)
	{
		digit_count++;
		l /= base;
	}
	return (digit_count);
}
