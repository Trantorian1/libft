/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deque_poll_front_bulk.h                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:38:03 by                   #+#    #+#             */
/*   Updated: 2023/01/16 14:38:03 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DEQUE_POLL_FRONT_BULK_H
# define FT_DEQUE_POLL_FRONT_BULK_H

# include <stddef.h>
# include "s_deque.h"

int	*ft_deque_poll_front_bulk(t_s_deque *deque, size_t n);

#endif
