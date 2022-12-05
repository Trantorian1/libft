/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 10:56:12 by emcnab            #+#    #+#             */
/*   Updated: 2022/12/05 08:54:56 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

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
ssize_t	ft_putstr_fd(char *str, int file_desc)
{
	if (!str)
		return (-1);
	return (write(file_desc, str, ft_strlen(str)));
}
