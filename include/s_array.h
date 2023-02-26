/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_array.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 14:00:08 by emcnab            #+#    #+#             */
/*   Updated: 2023/02/26 16:23:15 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_ARRAY_H
# define S_ARRAY_H

# include <stddef.h>

typedef struct s_array
{
	size_t	footprint;
	size_t	index;
	int		*data;
}	t_s_array;

#endif
