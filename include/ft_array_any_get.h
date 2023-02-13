/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_any_get.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 11:12:23 by                   #+#    #+#             */
/*   Updated: 2023/02/06 18:42:08 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ARRAY_ANY_GET_H
# define FT_ARRAY_ANY_GET_H

# include <stddef.h>
# include "s_array_any.h"

void	*ft_array_any_get(t_s_array_any *array, size_t index);

#endif
