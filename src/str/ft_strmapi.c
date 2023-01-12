/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 10:35:48 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/12 14:47:06 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strmapi.h"

#include <stdlib.h>
#include "ft_strdup.h"

/*
 * @brief Maps every character in a string to a new value specified by a
 * 	mapping function.
 *
 * @param str (t_str): the string to map.
 * @param mapping_f (char(t_uint, char)): the mapping function to apply to 
 * 	every character in [str].
 *
 * @return (char *): Mapped copy of [str] using [mapping_f].
 */
char	*ft_strmapi(const char *str, char (*mapping_f)(unsigned int, char))
{
	char			*mapped;
	unsigned int	i;

	i = 0;
	if (!str)
		return (NULL);
	mapped = ft_strdup(str);
	if (!str)
		return (NULL);
	while (mapped[i])
	{
		mapped[i] = mapping_f(i, mapped[i]);
		i++;
	}
	return (mapped);
}
