/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:27:47 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/12 16:14:40 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_min.h"

#include <stddef.h>

/*
 * @brief determines the smallest of two number
 *
 * @param a (size_t): the first number
 * @param b (size_t): the second number
 *
 * @return (size_t): the smallest number between a and b
 */
size_t	ft_min(size_t a, size_t b)
{
	if (a <= b)
		return (a);
	return (b);
}
