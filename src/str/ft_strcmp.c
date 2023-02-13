/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 09:29:22 by emcnab            #+#    #+#             */
/*   Updated: 2023/02/13 10:39:25 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strcmp.h"

#include <stdbool.h>

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
int	ft_strcmp(const char *str_a, const char *str_b)
{
	char	char_dif;
	char	char_a;
	char	char_b;

	while (true)
	{
		char_a = *(str_a);
		char_b = *(str_b);
		char_dif = char_a - char_b;
		if (!*str_a++ || !*str_b++ || char_dif)
			return (char_dif);
	}
}
