/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convcmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 15:15:56 by emcnab            #+#    #+#             */
/*   Updated: 2022/11/28 16:07:52 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

/*
 * @brief Sets comparison function inside of a Converter.
 *
 * @param conv (t_conv *): value converter to update.
 * @param f_cmp (int(t_any, t_any)): comparison function to link to [conv].
 */
void	ft_convcmp(t_conv *conv, int (*f_cmp)(t_any, t_any))
{
	conv -> f_cmp = f_cmp;
}
