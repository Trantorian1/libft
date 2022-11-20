/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 09:54:07 by emcnab            #+#    #+#             */
/*   Updated: 2022/11/20 14:55:26 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define DIGIT_START '0'
#define DIGIT_STOP '9'

/*
 * @brief checks for a digit (0 through 9)
 *
 * @param c (int): the character to check
 *
 * @return (int): 1 if c is a digit, 0 otherwise
 */
int	ft_isdigit(int c)
{
	c = ft_tochar(c);
	return (c >= DIGIT_START && c <= DIGIT_STOP);
}
