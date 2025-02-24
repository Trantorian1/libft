/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 10:51:03 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/12 15:58:25 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_putchar_fd.h"

/**
 * @brief Puts a cahracter [c] onto the output pointed to by the given file 
 *        descriptor [file_desc].
 *
 * @param c (char): the cahracter to add to the output.
 * @param file_desc (int): file descriptor pointing to the output.
 *
 * @return (ssize_t): number of bytes written, negative if a write error
 *         occurred.
 */
ssize_t	ft_putchar_fd(char c, int file_desc)
{
	return (write(file_desc, &c, 1));
}
