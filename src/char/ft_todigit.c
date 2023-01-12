/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_todigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 08:43:47 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/12 16:11:47 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_todigit.h"

/*
 * @brief Converts any numerical character back to its int value.
 *
 * @param c (int): the numerical character to convert.
 *
 * @return (int): int value associated to [c].
 */
char	ft_todigit(char c)
{
	return (c + '0');
}
