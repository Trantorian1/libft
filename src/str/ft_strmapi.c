/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 10:35:48 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/09 15:58:36 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/str.h"

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
char	*ft_strmapi(t_str str, char (*mapping_f)(t_uint, char))
{
	char	*mapped;
	t_uint	i;

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
