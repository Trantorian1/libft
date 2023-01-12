/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:05:29 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/12 16:12:50 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_isupper.h"

#include <stdbool.h>

#define UPPER_START 'A'
#define UPPER_STOP 'Z'

bool	ft_isupper(char c)
{
	return (c >= UPPER_START && c <= UPPER_STOP);
}
