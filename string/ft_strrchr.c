/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 12:24:34 by emcnab            #+#    #+#             */
/*   Updated: 2022/11/21 10:09:35 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
 * @brief searches for the last occurrence of a character in a string
 *
 * @param str (const char *): the string to scan for the character
 * @param c (int): the character we are looking for
 *
 * @return a pointer to the last occurrence of c or NULL if c is not found
 */
char	*ft_strrchr(t_str str, int c)
{
	int	i          = 0;
	int	last_index = 0;

	c = ft_tochar(c);
	while (str[i])
	{
		if (str[i] == c)
			last_index = i;
		i++;
	}
	if (str[i] == c)
	{
		last_index = i;
	}
	if (str[last_index] == c)
	{
		return ((char *)(str + last_index * sizeof(char)));
	}
	return (NULL);
}
