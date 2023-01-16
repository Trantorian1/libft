/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deque_add_front_bulk.h                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 09:39:17 by                   #+#    #+#             */
/*   Updated: 2023/01/16 09:39:17 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DEQUE_ADD_FRONT_BULK_H
# define FT_DEQUE_ADD_FRONT_BULK_H

# include <stddef.h>
# include "s_deque.h"

int	ft_deque_add_front_bulk(t_s_deque *deque, int *data, size_t n);

#endif
