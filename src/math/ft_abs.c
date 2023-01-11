/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 08:55:08 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/11 16:50:08 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_abs.h"

/*
 * @brief Calcualtes the absolute value of a number.
 *
 * @param a (int): the number to get the absolute value of.
 *
 * @return (int): absolute value of [a].
 */
int	ft_abs(int a)
{
	if (a < 0)
		return (-a);
	return (a);
}
