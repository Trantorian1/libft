/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deque_add_back_bulk.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 10:18:43 by                   #+#    #+#             */
/*   Updated: 2023/01/16 10:18:43 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DEQUE_ADD_BACK_BULK_H
# define FT_DEQUE_ADD_BACK_BULK_H

# include <stddef.h>
# include "s_deque.h"

int	ft_deque_add_back_bulk(t_s_deque *deque, int *data, size_t n);

#endif
