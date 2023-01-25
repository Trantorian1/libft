/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_insert.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 18:43:32 by                   #+#    #+#             */
/*   Updated: 2023/01/25 18:43:32 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ARRAY_INSERT_H
# define FT_ARRAY_INSERT_H

# include <stddef.h>
# include "s_array.h"

int	ft_array_insert(t_s_array *array, size_t index, int n);
int	ft_array_insert_bulk(t_s_array *array, size_t index, int *data, size_t size);

#endif
