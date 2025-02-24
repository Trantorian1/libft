/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnsum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 09:17:17 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/12 15:06:26 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strnsum.h"

/*
 * @brief sums up the ascii values of the n first charcters in a string
 *
 * @param str (const char *): the string to sum up
 * @param n (size_t): max number of characters to sum up
 *
 * @return (size_t): sum of the ascii values of the n first characters in str
 */
size_t	ft_strnsum(const char *str, size_t n)
{
	size_t	i;
	size_t	sum;

	i = 0;
	sum = 0;
	while (str[i] && i < n)
	{
		sum += (size_t) str[i];
		i++;
	}
	return (sum);
}
