/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_islower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:07:14 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/12 16:12:46 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_islower.h"

#include <stdbool.h>

#define LOWER_START 'a'
#define LOWER_STOP 'z'

bool	ft_islower(char c)
{
	return (c >= LOWER_START && c <= LOWER_STOP);
}
