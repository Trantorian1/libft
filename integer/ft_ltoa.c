/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 14:05:46 by emcnab            #+#    #+#             */
/*   Updated: 2022/12/06 14:39:15 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_ltoa(long l)
{
	long	l_abs;
	size_t	l_len;
	char	*str;

	if (l == LONG_MIN)
		l = LONG_MIN + 1;
	l_abs = ft_abslong(l);
	l_len = ft_longlen(l_abs) + (l < 0) - (1 * l == LONG_MIN);
	str = ft_stralloc(l_len);
	if (!str)
		return (NULL);
	str[l_len] = ft_todigit((int) LONG_MIN % 10);
	if (l < 0)
		str[0] = '-';
	while (l_abs >= 10)
	{
		str[--l_len] = (char)ft_todigit(l_abs % 10);
		l_abs /= 10;
	}
	str[l < 0] = (char)ft_todigit((int) l_abs);
	return (str);
}
