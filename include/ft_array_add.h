/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_add.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 11:12:21 by                   #+#    #+#             */
/*   Updated: 2023/01/26 11:12:21 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ARRAY_ADD_H
# define FT_ARRAY_ADD_H

# include "s_array.h"
# include <stddef.h>

void	ft_array_add(t_s_array *array, int n);
void	ft_array_add_bulk(t_s_array *array, int *data, size_t size);

#endif
