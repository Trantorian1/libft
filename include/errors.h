/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 11:45:11 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/24 16:51:26 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

typedef enum e_errors
{
	NO_ERROR,
	MALLOC_ERROR,
	NULL_ERROR,
	SIZE_ERROR,
	PARSE_ERROR,
	OVERFLOW_ERROR,
	OCCURRENCE_ERROR
}	t_e_errors;

#endif
