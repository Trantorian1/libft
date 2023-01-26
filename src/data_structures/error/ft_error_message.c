/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_message.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 09:54:27 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/26 10:03:22 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "e_error.h"
#include "ft_array_create.h"
#include "ft_array_destroy.h"
#include <stddef.h>

static const char	*error_msgs[E_ERROR_SIZE] = {
	"Error: no error occurred",
	"Error: an error occurred"
}

static void	ft_error_init(void)
{
	static t_s_array	*error_msg = NULL;
	size_t				i;

	if (error_msg == NULL)
		error_msg = ft_array_create(E_ERROR_SIZE);
	i = (size_t)(-1);
	while (++i < E_ERROR_SIZE)
		
}
