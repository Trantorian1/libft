/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deque_resize.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 13:28:28 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/12 17:55:46 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/deque.h"

static void	ft_deque_center(t_s_deque *deque)
{
	int		*bottom_old;
	int		*bottom_new;

	bottom_old = deque->data + deque->bottom;
	bottom_new = deque->data + (deque->size_data - deque->size_actual) / 2;
	ft_memmove(bottom_new, bottom_old, deque->size_actual);
}

/**
 * @brief Resizes the deque to twice its current size.
 *
 * @param deque A pointer to the deque.
 *
 * @return NO_ERROR if the operation was successful, MALLOC_ERROR if a memory
 * allocation error occurred.
 *
 * The function allocates a new array with twice the size of the current deque
 * and copies the elements from the old array to the new array, centered in the
 * new array. It then updates the size of the deque and frees the old array.
 */
static int	ft_deque_grow(t_s_deque *deque)
{
	size_t	size_new;
	int		*new_array;
	int		*bottom_old;
	int		*bottom_new;

	size_new = deque->size_data * 2;
	new_array = malloc(size_new * sizeof(*new_array));
	if (!new_array)
		return (MALLOC_ERROR);
	deque->size_data = size_new;
	bottom_old = deque->data + deque->bottom;
	bottom_new = new_array + (size_new - deque->size_actual) / 2;
	ft_memcpy(bottom_new, bottom_old, deque->size_actual);
	free(deque->data);
	deque->data = new_array;
	return (NO_ERROR);
}

/**
 * @brief Determines if the deque needs to be resized.
 *
 * @param deque A pointer to the deque.
 *
 * @return true if the deque needs to be resized, false otherwise.
 *
 * The function checks if the bottom index is 0 or the top index is at the end
 * of the array. If either of these conditions is true, the deque needs to be
 * resized in order to insert an element.
 */
static bool	ft_deque_should_make_space(t_s_deque *deque)
{
	return (deque->bottom = 0 || deque->top >= deque->size_data - 1);
}

/**
 * 
 * @brief Ensures that there is enough space in the deque for inserting an
 * element.
 * 
 * @param deque A pointer to the deque.
 * 
 * @return NO_ERROR if the operation was successful, MALLOC_ERROR if a memory 
 * allocation error occurred.
 *
 * This function checks if the deque needs more space to
 * store data. If it does, the function will either center the data in the 
 * deque's current allocated space or grow the deque by allocating more memory.
 * The function returns NO_ERROR if the deque was resized successfully,
 * otherwise it will return an error code.
 */
int	ft_deque_ensure_space(t_s_deque *deque)
{
	if (!ft_deque_should_make_space(deque))
		return ;
	if (deque->size_actual < deque->size_data)
	{
		ft_deque_center(deque);
		return (NO_ERROR);
	}
	return (ft_deque_grow(deque));
}
