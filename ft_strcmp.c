/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 09:29:22 by emcnab            #+#    #+#             */
/*   Updated: 2022/11/20 15:53:06 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * @brief compares two strings.
 *
 * @param str_a (t_str): the first string to compare.
 * @param str_b (t_str): the second string to compare.
 *
 * @return (int):
 * 	- 0 if [str_a] contains the same characters as [str_b].
 * 	- < 0 if [str_a] is before [str_b] in ascii order.
 * 	- > 0 if [str_a] is after [str_b] in ascii order.
 */
int	ft_strcmp(t_str str_a, t_str str_b)
{
	size_t	i        = 0;
	int		char_dif = 0;

	do
	{
		char_dif = (t_uchar)str_a[i] - (t_uchar)str_b[i];
		if (char_dif)
			return (char_dif);
	}
	while (str_a[i] && str_b[i]);
	return (char_dif);
}
