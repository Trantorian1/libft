/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 11:00:55 by emcnab            #+#    #+#             */
/*   Updated: 2022/11/20 17:57:40 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

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
int	ft_toupper(int c)
{
	c = (unsigned char)c;
	if (ft_islower(c))
	{
		return (c - UPPER);
	}
	return (c);
}
