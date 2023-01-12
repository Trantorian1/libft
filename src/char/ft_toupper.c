/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 11:00:55 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/12 16:12:06 by emcnab           ###   ########.fr       */
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
char	ft_toupper(char c)
{
	if (ft_islower(c))
		return (c - UPPER);
	return (c);
}
