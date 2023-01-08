/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dequeue.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 10:19:03 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/06 16:59:22 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEQUEUE_H
# define DEQUEUE_H

#include <stddef.h>
#include <stdlib.h>
#include "../../libft.h"

/**
 * @brief Dequeue data structure implemented using resizable arrays with a focus
 * on achieveing a minimal memory footprint while still maintining high
 * performance.
 *
 * Elements in Dequeue are stored in a data arraym. The bottom and top of the
 * Dequeue are stored in different indexes starting from the start of the data
 * array. This means that initially the Dequeue has enough space to add elements
 * to its tail and head. If there is not enough space to add new elements,
 * Dequeue will try and recenter them in the array. If that is not possible, the
 * array's size will be doubled and all its contents copied to its new center.
 * Initial array size is the closest power of 2 to the number of elements
 * initially added, so if the Dequeue starts with 10 elements, its array will
 * initialise at size 16.
 */
typedef struct s_dequeue
{
	size_t	bottom;      /** Bottom Dequeue index data array                */
	size_t	top;         /** Top Dequeue index data array                   */
	size_t	size_data;   /** Size of the Dequeue's data array               */
	size_t	size_actual; /** Number of elements added to the Dequeue so far */
	int		*data;       /** Dequeue data array                             */
}	t_s_dequeue;

t_s_dequeue*	ft_dequeue_new(int *data, size_t size);
void			*ft_dequeue_destroy(t_s_dequeue *dequeue);
int				ft_dequeue_make_space(t_s_dequeue *dequeue);
bool			ft_dequeue_should_make_space(t_s_dequeue *dequeue);
bool			ft_dequeue_is_empty(t_s_dequeue *dequeue);
int				ft_dequeue_add_front(t_s_dequeue *dequeue, int n);
int				ft_dequeue_add_back(t_s_dequeue *dequeue, int n);
int				ft_dequeue_pop_front(t_s_dequeue *dequeue);
int				ft_dequeue_pop_back(t_s_dequeue *dequeue);
int				ft_dequeue_poll_front(t_s_dequeue *dequeue);
int				ft_dequeue_poll_back(t_s_dequeue *dequeue);
int				ft_dequeue_rotate(t_s_dequeue *dequeue);
int				ft_dequeue_reverse_rotate(t_s_dequeue *dequeue);

#endif
