/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 10:59:13 by emcnab            #+#    #+#             */
/*   Updated: 2022/11/11 14:59:09 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * @brief Puts a string [str] onto the output pointed to by the given file 
 * 	descriptor [file_desc], followd by a new line.
 *
 * @param str (char *): the string to add to the output.
 * @param file_desc (int): file descriptor pointing to the output.
 */
void	ft_putendl_fd(char *str, int file_desc)
{
	ft_putstr_fd(str, file_desc);
	ft_putchar_fd('\n', file_desc);
}
