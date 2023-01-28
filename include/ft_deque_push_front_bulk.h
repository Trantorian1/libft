/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deque_push_front_bulk.h                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 17:30:32 by                   #+#    #+#             */
/*   Updated: 2023/01/28 17:30:32 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DEQUE_PUSH_FRONT_BULK_H
# define FT_DEQUE_PUSH_FRONT_BULK_H

# include <stddef.h>
# include "s_deque.h"

void	ft_deque_push_front_bulk(t_s_deque *deque, int *data, size_t n);

#endif
