/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:02:56 by emcnab            #+#    #+#             */
/*   Updated: 2022/11/20 16:13:55 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * @brief compares (at most) the first n bytes of the strings str_a and str_b
 *
 * @param str_a (const char *): the first string to compare
 * @param str_b (const char *): the second string to compare
 *
 * @return (int):
 * 	- 0 if the first n bytes of each string are equal
 * 	- < 0 if the first n bytes of str_a are before the first n bytes of str_b 
 * 		in ascii order
 * 	- > 0 if the first n bytes of str_a are after the first n bytes of str_b 
 * 		in ascii order
 */
int	ft_strncmp(t_str str_a, t_str str_b, size_t n)
{
	int		char_diff;
	size_t	i = 0;

	while (n--)
	{
		char_diff = (t_uchar)str_a[i] - (t_uchar)str_b[i];
		if (!str_a[i] || !str_b[i] || char_diff)
			return (char_diff);
		i++;
	}
	return (0);
}
