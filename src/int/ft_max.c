/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:24:36 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/12 16:14:27 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_max.h"

#include <stddef.h>

/*
 * @brief determines the largerst of two number
 *
 * @param a (size_t): the first number
 * @param b (size_t): the second number
 *
 * @return (size_t): the largest number between a and b
 */
size_t	ft_max(size_t a, size_t b)
{
	if (a >= b)
		return (a);
	return (b);
}
