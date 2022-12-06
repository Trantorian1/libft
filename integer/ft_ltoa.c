/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 14:05:46 by emcnab            #+#    #+#             */
/*   Updated: 2022/12/06 17:13:32 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * @brief Converts a long [l] into its ASCII representation
 *
 * Handles any c implementation of the long data type, isn't only bound to
 * 64-bit compilers.
 *
 * @param l (long): the long to convert.
 *
 * @return (char *): ASCII representation of [l].
 */
char	*ft_ltoa(long l)
{
	long	l_abs;
	size_t	l_len;
	char	*str;

	l_abs = ft_abslong(l * (l != LONG_MIN) + (LONG_MIN + 1) * (l == LONG_MIN));
	l_len = ft_longlen(l_abs) + (l < 0);
	str = ft_stralloc(l_len);
	if (!str)
		return (NULL);
	if (l == LONG_MIN)
	{
		str[--l_len] = ft_todigit(-(l % 10));
		l_abs /= 10;
	}
	str[0] = '-';
	while (l_len > (l < 0))
	{
		str[--l_len] = (char)ft_todigit(l_abs % 10);
		l_abs /= 10;
	}
	return (str);
}
