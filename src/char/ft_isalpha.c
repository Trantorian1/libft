/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 09:35:48 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/11 16:47:09 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_isalpha.h"

#include <stdbool.h>
#include "ft_isupper.h"
#include "ft_islower.h"

/*
 * @brief checks for an alphabetic character; in the standard "C" locale, 
 * it is equivalent to (isupper(c) || islower(c))
 *
 * @param c (int): the character to check
 *
 * @return (int): 1 if c is an alphabetic character, 0 otherwise
 */
bool	ft_isalpha(char c)
{
	return ((ft_isupper(c) || ft_islower(c)));
}
