/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 10:35:48 by emcnab            #+#    #+#             */
/*   Updated: 2022/11/20 18:05:23 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

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
	t_uint	i = 0;

	if (!str)
		return (NULL);
	if (!(mapped = ft_strdup(str)))
		return (NULL);
	while (mapped[i])
	{
		mapped[i] = mapping_f(i, mapped[i]);
		i++;
	}
	return (mapped);
}
