/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convtostr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 15:12:20 by emcnab            #+#    #+#             */
/*   Updated: 2022/11/28 16:07:49 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

/*
 * @brief Sets string conversion inside of a Converter.
 *
 * @param conv (t_conv *): value converter to update.
 * @param f_tostr (char *(t_any)): conversion function to string value.
 */
void	ft_convtostr(t_conv *conv, char *(*f_tostr)(t_any))
{
	conv -> f_tostr = f_tostr;
}
