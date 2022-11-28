/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:45:54 by emcnab            #+#    #+#             */
/*   Updated: 2022/11/28 16:52:33 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h" 

/*
 * @brief calculates the length of the string pointed to by s, excluding the 
 * terminating null byte ('\0')
 *
 * @param str(const char*): the string to get the length of
 *
 * @return (unisgned int): the number of bytes in the string pointed to by str
 */
size_t	ft_strlen(t_str str)
{
	return ((size_t)(ft_quickfind((char *)str, '\0') - str));
}
