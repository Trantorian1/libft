/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:45:54 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/12 15:28:39 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strlen.h"

#include "ft_quickfind.h"

size_t	ft_strlen(const char *str)
{
	return ((size_t)(ft_quickfind(str, '\0') - str));
}
