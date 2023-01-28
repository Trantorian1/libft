/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_message.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 09:54:27 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/28 17:02:25 by emcnab           ###   ########.fr       */
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

static const char	*g_error_std[E_ERROR_SIZE] = {
	"Error: no error occurred",
	"Error: an error occurred",
	"Error: index out of bounds",
	"Error: parameter was NULL",
	"Error: malloc failed"
};

static t_s_array_any	*ft_error_init(void);

static void	at_exit_free(void)
{
	ft_array_any_destroy(ft_error_init(), NULL);
}

static t_s_array_any	*ft_error_init(void)
{
	static t_s_array_any	*errors = NULL;

	if (errors != NULL)
		return (errors);
	errors = ft_array_any_create(E_ERROR_SIZE);
	ft_array_any_add_bulk(errors, (void **)g_error_std, E_ERROR_SIZE);
	atexit(&at_exit_free);
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
