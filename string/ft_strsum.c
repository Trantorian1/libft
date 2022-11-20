/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsum.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 09:25:43 by emcnab            #+#    #+#             */
/*   Updated: 2022/11/20 18:05:58 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stddef.h>

/*
 * @brief sum up the ASCII values of every character in a string.
 *
 * @param str (t_str): the string to sum up.
 *
 * @return (size_t): sum of all ASCII characters in [str].
 */
size_t	ft_strsum(t_str str)
{
	size_t	i;
	size_t	sum;

	i = 0;
	sum = 0;
	while (str[i])
	{
		sum += str[i];
		i++;
	}
	return (sum);
}
