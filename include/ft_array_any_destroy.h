/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_any_destroy.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 12:02:08 by                   #+#    #+#             */
/*   Updated: 2023/01/26 12:02:08 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ARRAY_ANY_DESTROY_H
# define FT_ARRAY_ANY_DESTROY_H

# include "s_array_any.h"

void	*ft_array_any_destroy(t_s_array_any *array, void (*f_free)(void *));

#endif
