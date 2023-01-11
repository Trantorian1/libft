/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:39:31 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/11 16:47:09 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_isprint.h"

#include <stdbool.h>

#define PRINT_START 32
#define PRINT_STOP 126

/*
 * @brief checks for any printable character including space. This includes
 * characters between ascii codes 33 and 126 included
 * 
 * @param c (int): the character to check
 *
 * @return (int): 1 if c is printable, 0 otheriwise
 */
bool	ft_isprint(unsigned char c)
{
	return (c >= PRINT_START && c <= PRINT_STOP);
}
