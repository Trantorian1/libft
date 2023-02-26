/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_message.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 09:54:27 by emcnab            #+#    #+#             */
/*   Updated: 2023/02/26 16:16:03 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_error_message.h"

#include "e_error.h"
#include "ft_array_any_create.h"
#include "ft_array_any_destroy.h"
#include "ft_array_any_add.h"
#include "ft_array_any_get.h"
#include <stddef.h>
#include <stdlib.h>

void	ft_error_add(int error_code, const char *error_msg)
{
	(void)error_code;
	(void)error_msg;
}

const char	*ft_error_msg(int error_code)
{
	(void)error_code;
	return (NULL);
}
