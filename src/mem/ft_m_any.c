/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_m_any.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 10:28:18 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/02 16:29:28 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_m_any.h"

#include "ft_malloc.h"

int	**ft_mock_any_create(size_t size)
{
	int		**any;
	int		*data;
	size_t	i;

	any = ft_malloc(size * sizeof(*any));
	i = (size_t)(-1);
	while (++i < size)
	{
		data = ft_malloc(sizeof(*data));
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
		ft_free(mock[i]);
	ft_free(mock);
	return (NULL);
}
