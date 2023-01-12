/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 10:56:12 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/12 16:05:26 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_putstr_fd.h"

#include "ft_strlen.h"

/**
 * @brief Puts a string [str] onto the output pointed to by the given file 
 *        descriptor [file_desc].
 *
 * @param str (char *): the string to add to the output.
 * @param file_desc (int): file descriptor pointing to the output.
 *
 * @return (ssize_t): number of bytes written, negative if a write error
 *         occurred.
 */
ssize_t	ft_putstr_fd(const char *str, int file_desc)
{
	if (!str)
		return (-1);
	return (write(file_desc, str, ft_strlen(str)));
}
