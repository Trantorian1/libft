/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 18:38:04 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/09 16:16:04 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mem.h"

/*
 * @brief erases the data in the n first bytes in memory starting at the 
 * 	location pointed to by mem.
 *
 * @param mem (void *): area in memory from which to erase data.
 * @param n (size_t): number of bytes to erase.
 */
void	ft_bzero(void *mem, size_t n)
{
	ft_memset(mem, '\0', n);
}
