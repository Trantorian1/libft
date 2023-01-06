/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_closest_power.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 11:21:38 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/06 12:03:51 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_closest_power(int n, int pow)
{
	int	result;

	result = 1;
	while (result < n)
	{
		result *= pow;
	}
	return (result);
}
