/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:26:02 by emcnab            #+#    #+#             */
/*   Updated: 2022/11/18 17:44:40 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define ASCII_START 0
#define ASCII_STOP 127

/*
 * @brief checks whether c is a 7-bit unsigned char value that fits into the 
 * ASCII character set
 *
 * @param c (int): the int value to check
 *
 * @return (int): 1 if c is a 7-bit unsigned char value that fits into the 
 * ASCII set, 0 otherwise
 */
int	ft_isascii(int c)
{
	c = ft_tochar(c);
	return (c >= ASCII_START && c <= ASCII_STOP);
}
