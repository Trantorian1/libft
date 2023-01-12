/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 11:30:20 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/12 14:45:02 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strjoin.h"

#include <stddef.h>
#include "ft_strlen.h"
#include "ft_stralloc.h"

/*
 * @brief Joins two strings togther and null-terminates the result.
 *
 * @param str_a (const char *): prefixed string.
 * @param str_b (const char *): postfixed string.
 *
 * @return (char *): string joining [str_a] and [str_b].
 */
char	*ft_strjoin(const char *str_a, const char *str_b)
{
	size_t	len_a;
	size_t	len_b;
	size_t	i;
	char	*str_join;

	len_a = ft_strlen(str_a);
	len_b = ft_strlen(str_b);
	i = 0;
	if (!str_a || !str_b)
		return (NULL);
	str_join = ft_stralloc(len_a + len_b);
	if (!str_join)
		return (NULL);
	while (str_a[i])
	{
		str_join[i] = str_a[i];
		i++;
	}
	while (str_b[i - len_a])
	{
		str_join[i] = str_b[i - len_a];
		i++;
	}
	return (str_join);
}
