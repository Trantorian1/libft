/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_deque.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 17:56:49 by emcnab            #+#    #+#             */
/*   Updated: 2023/02/13 11:08:43 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_DEQUE_H
# define S_DEQUE_H

# include <stddef.h>

# define SHRINK_FACTOR 4

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
typedef struct s_deque
{
	size_t	bottom;      /** Bottom Dequeue index data array                */
	size_t	top;         /** Top Dequeue index data array                   */
	size_t	size_data;   /** Size of the Dequeue's data array               */
	size_t	size_actual; /** Number of elements added to the Dequeue so far */
	size_t	size_min;
	int		*data;       /** Dequeue data array                             */
}	t_s_deque;

#endif
