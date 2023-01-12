/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 09:44:20 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/12 15:28:34 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strdup.h"

#include <stddef.h>
#include "ft_strlen.h"
#include "ft_stralloc.h"
#include "ft_memcpy.h"

char	*ft_strdup(const char *str_src)
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
