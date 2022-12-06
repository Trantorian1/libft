/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 08:41:27 by emcnab            #+#    #+#             */
/*   Updated: 2022/12/06 14:39:39 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
 * @brief Converts an integer [n] into its ASCII represenation.
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

	if (n == INT_MIN)
		n = INT_MIN + 1;
	n_abs = ft_abs(n);
	n_len = ft_intlen(n_abs) + (n < 0) - (n == INT_MIN);
	str = ft_stralloc(n_len);
	if (!str)
		return (NULL);
	str[n_len] = ft_todigit(INT_MIN % 10);
	if (n < 0)
		str[0] = '-';
	while (n_abs >= 10)
	{
		str[--n_len] = (char)ft_todigit(n_abs % 10);
		n_abs /= 10;
	}
	str[n < 0] = (char)ft_todigit(n_abs);
	return (str);
}
