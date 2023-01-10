/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 09:58:48 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/10 09:13:41 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/char.h"

/*
 * @brief checks for an alphanumeric character; it is equivalent to 
 * (isalpha(c) || isdigit(c))
 *
 * @param c (int): the character to test
 *
 * @return (int): 1 if c is alphanumeric, 0 otherwise
 */
int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}
