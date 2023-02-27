/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_insert.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 13:59:41 by                   #+#    #+#             */
/*   Updated: 2023/02/27 13:59:41 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ARRAY_INSERT_H
# define FT_ARRAY_INSERT_H

# include <stddef.h>
# include <stdbool.h>
# include "s_array.h"

bool	ft_array_insert(t_s_array *array, size_t index, int n);
bool	ft_array_insert_bulk(t_s_array *array, size_t index, int *data, size_t size);

#endif
