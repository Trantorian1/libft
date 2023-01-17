/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deque_add_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 17:41:21 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/17 18:47:32 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_deque_add_front.h"

#include "ft_deque_ensure_space_top.h"
#include "errors.h"

/**
 * @brief Adds an element to the front of the deque.
 *
 * @param deque A pointer to the deque.
 * @param n The element to be added.
 *
 * @return NO_ERROR if the element was successfully added, MALLOC_ERROR if an
 * error occurred.
 *
 * The function first checks if the deque needs to make space using the
 * ft_deque_should_make_space() function, and if it does, it calls the 
 * ft_deque_make_space() function to do so. If either function returns an
 * error, the function returns MALLOC_ERROR. Otherwise, it adds the element to
 * the front of the deque by incrementing the top index and storing the element
 * in the deque's data array at that index. It then increments the size of the
 * deque.
 */
int	ft_deque_add_front(t_s_deque *deque, int n)
{
	int	error_code;

	error_code = ft_deque_ensure_space_top(deque);
	if (error_code)
		return (error_code);
	deque->data[++deque->top] = n;
	deque->size_actual++;
	return (NO_ERROR);
}
