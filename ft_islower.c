/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_islower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:07:14 by emcnab            #+#    #+#             */
/*   Updated: 2022/11/18 17:43:54 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define LOWER_START 'a'
#define LOWER_STOP 'z'

/*
 * @brief check for a lowercase letter
 *
 * @para c (int): the character to check
 *
 * @return (int): 1 if c is a lowercase letter, 0 otherwise
 */
int	ft_islower(int c)
{
	c = ft_tochar(c);
	return (c >= LOWER_START && c <= LOWER_STOP);
}
