/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_m_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 11:35:38 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/26 11:59:02 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_m_data.h"

#include <stdlib.h>
#include <stddef.h>

int	*ft_mock_data(int min, int max)
{
	int	*data;
	int	i;

	data = malloc((size_t)(max - min) * sizeof(*data));
	if (!data)
		return (NULL);
	i = min - 1;
	while (++i < max)
		data[i - min] = i;
	return (data);
}
