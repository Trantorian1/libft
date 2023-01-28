/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_handle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 14:27:13 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/26 17:00:11 by emcnab           ###   ########.fr       */
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
#include <unistd.h>

void	ft_error_throw_fd(int error_code, int fd)
{
	t_s_deque	*error_queu;

	error_queu = ft_error_queu();
	ft_deque_push_back(error_queu, error_code);
	if (ERROR_LOG)
		ft_putendl_fd(ft_error_msg(error_code), fd);
}

void	ft_error_throw(int error_code)
{
	ft_error_throw_fd(error_code, STDOUT_FILENO);
}

bool	ft_error_occurred(void)
{
	t_s_deque	*error_queu;

	error_queu = ft_error_queu();
	return (ft_deque_size(error_queu) > 0);
}

bool	ft_error_catch(int error_code)
{
	t_s_deque	*error_queu;

	error_queu = ft_error_queu();
    if (ft_deque_poll_back(error_queu) == error_code)
    {
        ft_deque_pop_back(error_queu);
        return (true);
    }
    return (true);
}
