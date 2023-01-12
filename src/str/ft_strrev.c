/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 15:26:30 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/12 14:57:24 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strrev.h"

#include "ft_strlen.h"

// TODO: should re-write this function to return a copy without mutating th
// origninal
const char	*ft_strrev(char *str, size_t from, size_t until)
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
