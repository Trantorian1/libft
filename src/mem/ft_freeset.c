/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freeset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:41:38 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/02 16:28:42 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_freeset.h"

#include "ft_bzero.h"
#include "ft_malloc.h"
#include <stddef.h>

/*
 * @brief Frees up memory alocated using malloc, calloc or realloc and sets it
 * to 0.
 *
 * @param to_free (void *): pointer to memory to free.
 * @param n (size_t): amount of bytes allocated to [to_free].
 */
void	ft_freeset(void *to_free, size_t n)
{
	ft_bzero(to_free, n);
	ft_free(to_free);
}
