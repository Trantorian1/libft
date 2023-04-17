/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlong_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 15:38:21 by emcnab            #+#    #+#             */
/*   Updated: 2023/04/17 15:43:08 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_putlong_fd.h"

#include <limits.h>
#include "ft_bzero.h"
#include "ft_putstr_fd.h"
#include "ft_todigit.h"
#include "ft_strrev.h"

#define LONG_LEN 20

ssize_t	ft_putlong_fd(long l, int file_desc)
{
	char	l_str[LONG_LEN];
	long	l_cpy;
	size_t	i;

	ft_bzero(l_str, LONG_LEN);
	l_cpy = l;
	i = 0;
	if (l < 0)
	{
		if (l == LONG_MIN)
			return (ft_putstr_fd("-9223372036854775808", file_desc));
		l = -l;
	}
	while (l >= 10)
	{
		l_str[i++] = (char)(l % 10 + '0');
		l /= 10;
	}
	l_str[i++] = (char)(l + '0');
	if (l_cpy < 0)
		l_str[i++] = '-';
	return (ft_putstr_fd(ft_strrev(l_str, 0, i), file_desc));
}
