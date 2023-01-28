/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deque_ensure_space_top_bulk.h                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 17:29:32 by                   #+#    #+#             */
/*   Updated: 2023/01/28 17:29:32 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DEQUE_ENSURE_SPACE_TOP_BULK_H
# define FT_DEQUE_ENSURE_SPACE_TOP_BULK_H

# include <stddef.h>
# include "s_deque.h"

void	ft_deque_ensure_space_top_bulk(t_s_deque *deque, size_t n);

#endif
