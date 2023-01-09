/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 10:45:43 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/09 15:58:36 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/str.h"
#include <stddef.h>

/*
 * @brief Applies a function [f] to every character in a string [str].
 *
 * @param str (char *): the string to apply [f] to.
 * @param f (void(t_uint, char *)): the function to apply to every character in
 * 	[str].
 */
void	ft_striteri(char *str, void (*f)(t_uint, char *))
{
	t_uint	i;

	i = 0;
	if (!str || !f)
		return ;
	while (str[i])
	{
		f(i, str + i);
		i++;
	}
}
