/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_todigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 08:43:47 by emcnab            #+#    #+#             */
/*   Updated: 2022/11/20 15:16:54 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * @brief Converts any numerical character back to its int value.
 *
 * @param c (int): the numerical character to convert.
 *
 * @return (int): int value associated to [c].
 */
int	ft_todigit(int c)
{
	return (c + '0');
}
