/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convtoint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 15:06:57 by emcnab            #+#    #+#             */
/*   Updated: 2022/11/20 18:01:47 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
 * @brief Sets intiger conversion inside of a Converter.
 *
 * @param conv (t_conv *): value converter to update.
 * @param f_toint (int(t_any)): conversion function to int value.
 */
void	ft_convtoint(t_conv *conv, int (*f_toint)(t_any))
{
	conv -> f_toint = f_toint;
}
