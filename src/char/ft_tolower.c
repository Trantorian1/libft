/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 11:10:27 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/12 16:11:59 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tolower.h"

#include "ft_isupper.h"

#define UPPER 'a' - 'A'

/*
 * @brief lowercases a character if a lowercase equivalent exists in the ASCII
 * table which is not c
 *
 * @param c (int): the character to lowercase
 *
 * @return (int): lowercase equivalent of c, or c if no lowercase equivalent
 * exists or c is already lowercase
 */
char	ft_tolower(char c)
{
	if (ft_isupper(c))
		return (c + UPPER);
	return (c);
}
