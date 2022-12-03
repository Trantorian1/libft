/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 09:44:20 by emcnab            #+#    #+#             */
/*   Updated: 2022/12/03 16:59:49 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
 * @brief Creates a copy of an existing string which can be freed with free(3).
 *
 * @param str_original (t_str): the string to copy.
 *
 * @return (t_str): a duplicate of str_original, allocated with malloc(3).
 */
char	*ft_strdup(t_str str_src)
{
	size_t	str_size;
	char	*str_dest;

	str_size = ft_strlen(str_src);
	str_dest = ft_stralloc(str_size);
	if (!str_dest)
		return (NULL);
	ft_memcpy(str_dest, str_src, str_size + 1);
	return (str_dest);
}
