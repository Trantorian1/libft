/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_get_sign.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliot <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:01:14 by eliot             #+#    #+#             */
/*   Updated: 2023/03/17 16:19:33 by eliot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str_get_sign.h"

#include "ft_isdigit.h"

int8_t	str_get_sign(const char *str, char **endptr)
{
	if (*str == '-')
	{
		*endptr = (char *)(&str[1]);
		return (NEGATIVE);
	}
	else if (*str == '+')
	{
		*endptr = (char *)(&str[1]);
		return (POSITIVE);
	}
	else if (ft_isdigit(*str))
	{
		*endptr = (char *)(str);
		return (POSITIVE);
	}
	else
	{
		*endptr = (char *)(str);
		return (0);
	}
}
