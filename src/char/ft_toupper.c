/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 11:00:55 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/11 16:47:04 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_toupper.h"

#include "ft_islower.h"

#define UPPER ('a' - 'A')

/*
 * @brief uppercases a character if an uppercase equivalent exists in the ASCII
 * table
 *
 * @param c (int): the character to uppercase
 *
 * @return (int): uppercase equivalent of c, or c if no uppercase equivalent
 * exists
 */
unsigned char	ft_toupper(unsigned char c)
{
	if (ft_islower(c))
		return (c - UPPER);
	return (c);
}
