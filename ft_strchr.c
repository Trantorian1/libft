/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 11:17:27 by emcnab            #+#    #+#             */
/*   Updated: 2022/11/20 15:47:08 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * @brief searches for the first occurrence of a character in a string
 *
 * @param str (const char *): the string to scan for the character
 * @param c (int): the character we are looking for
 *
 * @return a pointer to the first occurrence of c or NULL if c is not found
 */
char	*ft_strchr(t_str str, int c)
{
	size_t	i = 0;

	c = ft_tochar(c);
	while (str[i] && str[i] != c)
		i++;
	if (str[i] == c)
		return ((char *)(str + i * sizeof(char)));
	return (NULL);
}
