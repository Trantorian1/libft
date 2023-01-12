/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 09:54:07 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/12 16:12:23 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_isdigit.h"

#include <stdbool.h>

#define DIGIT_START '0'
#define DIGIT_STOP '9'

/*
 * @brief checks for a digit (0 through 9)
 *
 * @param c (int): the character to check
 *
 * @return (int): 1 if c is a digit, 0 otherwise
 */
bool	ft_isdigit(char c)
{
	return (c >= DIGIT_START && c <= DIGIT_STOP);
}
