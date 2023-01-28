/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_error.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 09:55:04 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/28 18:37:43 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef E_ERROR_H
# define E_ERROR_H

# ifndef ERROR_LOG
#  define ERROR_LOG 0
# endif

typedef enum e_error
{
	ERROR_NONE,
	ERROR_OCCURRED,
	ERROR_INDEX_OUT_OF_BOUNDS,
	ERROR_SIZE,
	ERROR_MALLOC,
	ERROR_NULL_PARAM,
	E_ERROR_SIZE,
}	t_e_error;

#endif
