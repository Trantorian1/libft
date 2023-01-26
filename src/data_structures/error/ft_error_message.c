/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_message.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 09:54:27 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/26 20:23:32 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_error_message.h"

#include "e_error.h"
#include "ft_error_queu.h"
#include "ft_deque.h"
#include "ft_array_any_create.h"
#include "ft_array_any_destroy.h"
#include "ft_array_any_add.h"
#include "ft_array_any_get.h"
#include "ft_itoa.h"
#include "ft_stralloc.h"
#include <stddef.h>
#include <stdlib.h>

static const char	*error_std[E_ERROR_SIZE] = {
	"Error: no error occurred",
	"Error: an error occurred"
};

static t_s_array_any	*ft_error_init(void)
{
	static t_s_array_any	*errors = NULL;

	if (errors != NULL)
		return (errors);
	errors = ft_array_any_create(E_ERROR_SIZE);
	ft_array_any_add_bulk(errors, (void **)error_std, E_ERROR_SIZE);
	return (errors);
}

void	ft_error_add(int error_code, const char *error_msg)
{
	t_s_array_any	*errors;

	errors = ft_error_init();
	ft_array_any_add_at(errors, error_msg, (size_t)error_code);
}

const char	*ft_error_msg(int error_code)
{
	t_s_array_any	*errors;

	errors = ft_error_init();
	return (ft_array_any_get(errors, (size_t)error_code));
}

void	ft_error_destroy(void)
{
	t_s_array_any	*errors;

	errors = ft_error_init();
	ft_array_any_destroy(errors, NULL);
	ft_deque_destroy(ft_error_queu(), &free);
}
