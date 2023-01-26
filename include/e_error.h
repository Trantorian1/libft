/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_error_code.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 09:55:04 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/26 09:56:50 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef E_ERROR_H
# define E_ERROR_H

typedef enum e_error
{
	ERROR_NONE,
	ERROR_OCCURRED,
	E_ERROR_SIZE,
}	t_e_error;

#endif
