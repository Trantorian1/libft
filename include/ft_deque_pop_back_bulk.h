/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deque_pop_back_bulk.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 14:14:37 by                   #+#    #+#             */
/*   Updated: 2023/01/20 14:14:37 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DEQUE_POP_BACK_BULK_H
# define FT_DEQUE_POP_BACK_BULK_H

# include <stddef.h>
# include "s_deque.h"

int	*ft_deque_pop_back_bulk(t_s_deque *deque, size_t n);

#endif
