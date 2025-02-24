/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 11:01:30 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/01 14:51:04 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_putnbr_fd.h"

#include <limits.h>
#include "ft_bzero.h"
#include "ft_putstr_fd.h"
#include "ft_todigit.h"
#include "ft_strrev.h"

/**
 * @brief Puts a number [n] onto the output pointed to by the given file 
 *        descriptor [file_desc].
 *
 * @param n (int): the number to add to the output.
 * @param file_desc (int): file descriptor pointing to the output.
 *
 * @return (ssize_t): number of bytes written, negative if a write error
 *         occurred.
 */
ssize_t	ft_putnbr_fd(int n, int file_desc)
{
	char	str_n[12];
	int		n_cpy;
	size_t	i;

	ft_bzero(str_n, 12);
	n_cpy = n;
	i = 0;
	if (n < 0)
	{
		if (n == INT_MIN)
		{
			return (ft_putstr_fd("-2147483648", file_desc));
		}
		n = -n;
	}
	while (n >= 10)
	{
		str_n[i++] = (char)(n % 10 + '0');
		n /= 10;
	}
	str_n[i++] = (char)(n + '0');
	if (n_cpy < 0)
		str_n[i++] = '-';
	return (ft_putstr_fd(ft_strrev(str_n, 0, i), file_desc));
}
