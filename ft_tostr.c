/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tostr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:50:32 by emcnab            #+#    #+#             */
/*   Updated: 2022/11/09 13:54:07 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * @brief Converts a character to a string.
 *
 * @param c (int): the character to convert.
 *
 * @return (t_str): a string containing only the character [c].
 */
t_str	ft_tostr(int c)
{
	char	*string;

	string = ft_stralloc(1);
	string[0] = c;
	return (string);
}
