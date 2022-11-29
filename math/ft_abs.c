/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 08:55:08 by emcnab            #+#    #+#             */
/*   Updated: 2022/11/29 11:32:55 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * @brief Calcualtes the absolute value of a number.
 *
 * @param a (double): the number to get the absolute value of.
 *
 * @return (double): absolute value of [a].
 */
double	ft_abs(double a)
{
	if (a < 0)
		return (-a);
	return (a);
}
