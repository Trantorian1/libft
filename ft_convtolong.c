/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convtolong.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 15:13:53 by emcnab            #+#    #+#             */
/*   Updated: 2022/11/12 15:19:13 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * @brief Sets long conversion inside of a Converter.
 *
 * @param conv (t_conv *): value converter to update.
 * @param f_tolong (long(t_any)): conversion function to long value.
 */
void	ft_convtolong(t_conv *conv, long (*f_tolong)(t_any))
{
	conv -> f_tolong = f_tolong;
}
