/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_any_add.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 14:18:53 by                   #+#    #+#             */
/*   Updated: 2023/02/26 16:19:49 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ARRAY_ANY_ADD_H
# define FT_ARRAY_ANY_ADD_H

# include "s_array_any.h"
# include <stddef.h>

void	ft_array_any_add(t_s_array_any *array, const void *any);
void	ft_array_any_add_at(
			t_s_array_any *array,
			const void *any,
			size_t index);
void	ft_array_any_add_bulk(
			t_s_array_any *array,
			const void **data,
			size_t size);

#endif
