/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:01:58 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/11 16:47:09 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_isspace.h"

#include <stdbool.h>

#define SPACE_START '\t'
#define SPACE_END '\r'

/*
 * @brief Determines if a character is a space as defined by isspace(3)'
 *
 * @param c (int): character to check.
 * 
 * @return (int): true if [c] is a space, 0 otherwise.
 */
bool	ft_isspace(unsigned char c)
{
	return ((c >= SPACE_START && c <= SPACE_END) || c == ' ');
}
