/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 10:56:12 by emcnab            #+#    #+#             */
/*   Updated: 2022/11/20 18:07:01 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
 * @brief Puts a string [str] onto the output pointed to by the given file 
 * 	descriptor [file_desc].
 *
 * @param str (char *): the string to add to the output.
 * @param file_desc (int): file descriptor pointing to the output.
 */
void	ft_putstr_fd(char *str, int file_desc)
{
	if (!str)
		return ;
	write(file_desc, str, ft_strlen(str));
}
