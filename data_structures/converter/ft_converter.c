/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 14:35:19 by emcnab            #+#    #+#             */
/*   Updated: 2022/11/28 16:07:52 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"
#include <stdlib.h>

/*
 * @brief Createa a new converter struct instance, which can then be populate
 * 	with various type conversion and comparison functions.
 */
t_conv	*ft_converter(void)
{
	t_conv	*conv;

	if (!(conv = malloc(sizeof(*conv))))
	{
		return (NULL);
	}
	return (conv);
}
