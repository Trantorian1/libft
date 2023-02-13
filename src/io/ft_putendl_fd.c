/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 10:59:13 by emcnab            #+#    #+#             */
/*   Updated: 2023/02/06 18:16:43 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_putendl_fd.h"

#include "ft_putstr_fd.h"
#include "ft_putchar_fd.h"

/**
 * @brief Puts a string [str] onto the output pointed to by the given file 
 *        descriptor [file_desc], followd by a new line.
 *
 * @param str (char *): the string to add to the output.
 * @param file_desc (int): file descriptor pointing to the output.
 *
 * @return (ssize_t): number of bytes written, negative if a write error
 *         occurred.
 */
ssize_t	ft_putendl_fd(const char *str, int file_desc)
{
	ssize_t	write_count;

	write_count = 0;
	write_count += ft_putstr_fd(str, file_desc);
	write_count += ft_putchar_fd('\n', file_desc);
	return (write_count);
}
