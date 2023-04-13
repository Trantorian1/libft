/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoui.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 17:20:12 by emcnab            #+#    #+#             */
/*   Updated: 2023/04/13 17:26:37 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_atoui.h"

#include <stddef.h>
#include <stdint.h>

#include "ft_isspace.h"
#include "ft_isdigit.h"

unsigned int	ft_atoui(const char *str_int)
{
	size_t			index;
	unsigned int	result;

	index = 0;
	result = 0;
	while (ft_isspace((uint8_t)str_int[index]))
		index++;
	if (str_int[index] == '+')
		index++;
	while (ft_isdigit((uint8_t)str_int[index]))
	{
		result = result * 10 + (str_int[index] - '0');
		index++;
	}
	return (result);
}
