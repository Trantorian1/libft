/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_array_any.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 10:06:56 by emcnab            #+#    #+#             */
/*   Updated: 2023/02/26 16:22:20 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_ARRAY_ANY_H
# define S_ARRAY_ANY_H

# include <stddef.h>

typedef struct s_array_any
{
	size_t		footprint;
	size_t		index;
	const void	**data;
}	t_s_array_any;

#endif
