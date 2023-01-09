/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 10:59:13 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/09 16:03:13 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/io.h"

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
ssize_t	ft_putendl_fd(char *str, int file_desc)
{
	ssize_t	write_count;

	write_count = 0;
	write_count += ft_putstr_fd(str, file_desc);
	write_count += ft_putchar_fd('\n', file_desc);
	return (write_count);
}
