/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_array.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 14:00:08 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/25 16:40:52 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef H_ARRAY
# define H_ARRAY

#include <stddef.h>

typedef struct s_array
{
	size_t	footprint;
	size_t	index;
	int		*data;
}	t_s_array;

#endif
