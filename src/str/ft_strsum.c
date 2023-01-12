/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsum.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 09:25:43 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/12 14:58:13 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strsum.h"

#include <stddef.h>

/*
 * @brief sum up the ASCII values of every character in a string.
 *
 * @param str (t_str): the string to sum up.
 *
 * @return (size_t): sum of all ASCII characters in [str].
 */
size_t	ft_strsum(const char *str)
{
	size_t	i;
	size_t	sum;

	i = 0;
	sum = 0;
	while (str[i])
	{
		sum += (size_t)str[i];
		i++;
	}
	return (sum);
}
