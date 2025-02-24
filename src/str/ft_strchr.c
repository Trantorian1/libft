/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 11:17:27 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/12 14:24:20 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strchr.h"

#include <stddef.h>

/*
 * @brief searches for the first occurrence of a character in a string
 *
 * @param str (const char *): the string to scan for the character
 * @param c (unsigned character): the character we are looking for
 *
 * @return a pointer to the first occurrence of c or NULL if c is not found
 */
char	*ft_strchr(char *str, unsigned char c)
{
	size_t	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	if (str[i] == c)
		return ((char *)str + i);
	return (NULL);
}
