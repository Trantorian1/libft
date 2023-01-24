/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 08:41:27 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/24 19:12:26 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_itoa.h"

#include <stddef.h>
#include <limits.h>
#include "ft_abs.h"
#include "ft_intlen.h"
#include "ft_stralloc.h"
#include "ft_todigit.h"

/*
 * @brief Converts an integer [n] into its ASCII representation.
 *
 * Handles any c implementation of the long data type, isn't only bound to
 * 64-bit compilers.
 *
 * @param n (int): the integer to convert.
 *
 * @return (char *): ASCII represenation of [n].
 */
char	*ft_itoa(int n)
{
	int		n_abs;
	size_t	n_len;
	char	*str;

	n_abs = ft_abs(n * (n != INT_MIN) + (INT_MIN + 1) * (n == INT_MIN));
	n_len = ft_intlen(n_abs) + (n < 0);
	str = ft_stralloc(n_len);
	if (!str)
		return (NULL);
	if (n == INT_MIN)
	{
		str[--n_len] = (char)(-(n % 10) + '0');
		n_abs /= 10;
	}
	str[0] = '-';
	while (n_len > (n < 0))
	{
		str[--n_len] = (char)(n_abs % 10 + '0');
		n_abs /= 10;
	}
	return (str);
}
