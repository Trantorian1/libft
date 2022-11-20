/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 10:51:03 by emcnab            #+#    #+#             */
/*   Updated: 2022/11/20 18:06:46 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <unistd.h>

/*
 * @brief Puts a cahracter [c] onto the output pointed to by the given file 
 * 	descriptor [file_desc].
 *
 * @param c (char): the cahracter to add to the output.
 * @param file_desc (int): file descriptor pointing to the output.
 */
void	ft_putchar_fd(char c, int file_desc)
{
	write(file_desc, &c, 1);
}
