/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_array_any.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 10:06:56 by emcnab            #+#    #+#             */
/*   Updated: 2023/02/06 18:24:19 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef H_S_ARRAY_INT
# define H_S_ARRAY_INT

# include <stddef.h>

typedef struct s_array_any
{
	size_t		footprint;
	size_t		index;
	const void	**data;
}	t_s_array_any;

#endif
