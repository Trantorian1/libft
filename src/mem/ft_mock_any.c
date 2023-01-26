/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mock_any.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 10:28:18 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/26 12:08:47 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mock_any.h"

#include <stdlib.h>

int	**ft_generate_any_create(size_t size)
{
	int		**any;
	int		*data;
	size_t	i;

	any = malloc(size * sizeof(*any));
	if (!any)
		return (NULL);
	i = (size_t)(-1);
	while (++i < size)
	{
		data = malloc(sizeof(*data));
		if (!data)
			return (ft_mock_any_destroy(any, i));
		*data = (int)i;
		any[i] = data;
	}
	return (any);
}

void	*ft_mock_any_destroy(int **mock, size_t until)
{
	size_t	i;

	i = (size_t)(-1);
	while (++i < until)
		free(mock[i]);
	free(mock);
	return (NULL);
}
