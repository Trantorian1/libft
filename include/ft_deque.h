/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deque.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 14:14:35 by                   #+#    #+#             */
/*   Updated: 2023/01/20 14:14:35 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DEQUE_H
# define FT_DEQUE_H

# include <stddef.h>
# include "s_deque.h"

t_s_deque	*ft_deque_new(size_t size);
void		*ft_deque_destroy(t_s_deque *deque);

#endif
