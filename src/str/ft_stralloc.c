/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stralloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:06:09 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/02 16:32:01 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stralloc.h"

#include "ft_malloc.h"

/*
 * @brief Allocates space in memory for a mutable string of n charcters and
 * 	null-terminates the result.
 *
 * @param n (size_t): the number of charcters to allocate space for.
 *
 * @return (char *): null-terminated mutable string with space for [n]
 * 	characters.
 */
char	*ft_stralloc(size_t n)
{
	char	*string;

	string = ft_malloc((n + 1) * sizeof(*string));
	if (!string)
		return (NULL);
	string[n] = '\0';
	return (string);
}
