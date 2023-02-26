/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_handle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 14:27:13 by emcnab            #+#    #+#             */
/*   Updated: 2023/02/26 16:15:45 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_error_handle.h"

#include "ft_error_message.h"
#include "ft_error_queu.h"
#include "ft_deque_push_back.h"
#include "ft_deque_poll_back.h"
#include "ft_deque_pop_back.h"
#include "ft_deque_size.h"
#include "ft_putendl_fd.h"
#include "e_error.h"
#include <stdbool.h>
#include <unistd.h>

void	ft_error_throw_fd(int error_code, int fd)
{
	(void)error_code;
	(void)fd;
}

void	ft_error_throw(int error_code)
{
	(void)error_code;
}

bool	ft_error_occurred(void)
{
	return (false);
}

bool	ft_error_catch(int error_code)
{
	(void)error_code;
	return (false);
}
