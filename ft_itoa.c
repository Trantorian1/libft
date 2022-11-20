/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 08:41:27 by emcnab            #+#    #+#             */
/*   Updated: 2022/11/20 15:30:47 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * @brief Determine the number of digits composing [n_abs].
 *
 * @param n_abs (int): absolute value of the number to get the length of.
 *
 * @return (size_t): the number of digits in [n_abs].
 */
static size_t	ft_num_len(int n_abs)
{
	size_t	digit_count = 1;

	while (n_abs >= 10)
	{
		digit_count++;
		n_abs /= 10;
	}
	return (digit_count);
}

/*
 * @brief Converts an integer [n] into its ASCII represenation.
 *
 * @param n (int): the integer to convert.
 *
 * @return (char *): ASCII represenation of [n].
 */
char	*ft_itoa(int n)
{
	int		n_abs = ft_abs(n);
	size_t	n_len = ft_num_len(n_abs) + (n < 0);
	char	*str;

	if (n_abs < 0)
		return (ft_strdup("-2147483648"));
	if (!(str = ft_stralloc(n_len)))
		return (NULL);
	if (n < 0)
		str[0] = '-';
	while (n_abs >= 10)
	{
		str[--n_len] = ft_todigit(n_abs % 10);
		n_abs /= 10;
	}
	str[n < 0] = ft_todigit(n_abs);
	return (str);
}
