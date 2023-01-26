/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_any_insert.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 11:12:23 by                   #+#    #+#             */
/*   Updated: 2023/01/26 11:12:23 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ARRAY_ANY_INSERT_H
# define FT_ARRAY_ANY_INSERT_H

# include <stddef.h>
# include "s_array_any.h"

int	ft_array_any_insert(t_s_array_any *array, size_t index, void *any);
int	ft_array_any_insert_bulk(t_s_array_any *array, size_t index, void **data, size_t size);

#endif
