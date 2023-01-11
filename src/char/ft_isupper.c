/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:05:29 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/11 16:47:09 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_isupper.h"

#include <stdbool.h>

#define UPPER_START 'A'
#define UPPER_STOP 'Z'

/*
 * @brief check for an uppercase letter
 *
 * @para c (int): the character to check
 *
 * @return (int): 1 if c is an uppercase letter, 0 otherwise
 */
bool	ft_isupper(unsigned char c)
{
	return (c >= UPPER_START && c <= UPPER_STOP);
}
