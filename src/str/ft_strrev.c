/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 15:26:30 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/09 15:58:37 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/str.h"

/*
 * @brief Reverses a string between the indexes [from] and [until] by muating it
 * 	directly.
 *
 * @param str (char *): the string to reverse.
 * @param from (size_t): index fronm which to start reversing [str].
 * @param until (size_t): index until which to start reversing [str].
 *
 * @return (char *): pointer to [str].
 */
char	*ft_strrev(char *str, size_t from, size_t until)
{
	size_t	i;
	char	tmp;

	i = 0;
	if (until < from || until > ft_strlen(str))
		return (str);
	while (i < from + (until - from + 1) / 2)
	{
		tmp = str[i];
		str[i] = str[until - 1 - i + from];
		str[until - 1 - i + from] = tmp;
		i++;
	}
	return (str);
}
