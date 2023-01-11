/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_islower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:07:14 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/11 16:47:09 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_islower.h"

#include <stdbool.h>

#define LOWER_START 'a'
#define LOWER_STOP 'z'

/*
 * @brief check for a lowercase letter
 *
 * @para c (int): the character to check
 *
 * @return (int): 1 if c is a lowercase letter, 0 otherwise
 */
bool	ft_islower(unsigned char c)
{
	return (c >= LOWER_START && c <= LOWER_STOP);
}
