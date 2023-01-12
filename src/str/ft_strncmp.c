/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:02:56 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/12 14:52:15 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strncmp.h"

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
int	ft_strncmp(const char *str_a, const char *str_b, size_t n)
{
	size_t			i;
	unsigned char	char_diff;
	unsigned char	char_a;
	unsigned char	char_b;

	i = 0;
	while (n--)
	{
		char_a = (unsigned char)str_a[i];
		char_b = (unsigned char)str_b[i];
		char_diff = char_a - char_b;
		if (!str_a[i] || !str_b[i] || char_diff)
			return (char_diff);
		i++;
	}
	return (0);
}
