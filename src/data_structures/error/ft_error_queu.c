/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_queu.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 16:56:51 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/26 16:59:34 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_error_queu.h"

#include "ft_deque.h"
#include "e_error.h"

t_s_deque	*ft_error_queu(void)
{
	static t_s_deque	*error_queu = NULL;

	if (error_queu)
		return (error_queu);
	error_queu = ft_deque_new(E_ERROR_SIZE);
	return (error_queu);
}
