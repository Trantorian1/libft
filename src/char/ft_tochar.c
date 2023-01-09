/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tochar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 08:48:09 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/09 14:43:23 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/char.h"

/*
 * @brief Converts an integer value to the value range of a char.
 *
 * @param n (int): int value to convert to char.
 *
 * @return (int): value of [n] in the range of values of a char.
 */
int	ft_tochar(int n)
{
	return ((unsigned char) n);
}
