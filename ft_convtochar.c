/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convtochar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 15:10:32 by emcnab            #+#    #+#             */
/*   Updated: 2022/11/12 15:18:59 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * @brief Sets char conversion inside of a Converter.
 *
 * @param conv (t_conv *): value converter to update.
 * @param f_tochar (char(t_any)): conversion function to char value.
 */
void	ft_convtochar(t_conv *conv, char (*f_tochar)(t_any))
{
	conv -> f_tochar = f_tochar;
}
