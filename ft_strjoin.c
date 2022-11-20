/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 11:30:20 by emcnab            #+#    #+#             */
/*   Updated: 2022/11/20 16:11:33 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * @brief Joins two strings togther and null-terminates the result.
 *
 * @param str_a (t_str): prefixed string.
 * @param str_b (t_str): postfixed string.
 *
 * @return (char *): string joining [str_a] and [str_b].
 */
char	*ft_strjoin(t_str str_a, t_str str_b)
{
	size_t	len_a = ft_strlen(str_a);
	size_t	len_b = ft_strlen(str_b);
	size_t	i     = 0;
	char	*str_join;

	if (!str_a || !str_b)
		return (NULL);
	if (!(str_join = ft_stralloc(len_a + len_b)))
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
