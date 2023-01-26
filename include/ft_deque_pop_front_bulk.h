/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deque_pop_front_bulk.h                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 11:12:22 by                   #+#    #+#             */
/*   Updated: 2023/01/26 11:12:22 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DEQUE_POP_FRONT_BULK_H
# define FT_DEQUE_POP_FRONT_BULK_H

# include <stddef.h>
# include "s_deque.h"

int	*ft_deque_pop_front_bulk(t_s_deque *deque, size_t n);

#endif
