/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 09:35:48 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/09 14:43:23 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/char.h"

/*
 * @brief checks for an alphabetic character; in the standard "C" locale, 
 * it is equivalent to (isupper(c) || islower(c))
 *
 * @param c (int): the character to check
 *
 * @return (int): 1 if c is an alphabetic character, 0 otherwise
 */
int	ft_isalpha(int c)
{
	return ((ft_isupper(c) || ft_islower(c)));
}
