/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_array_add.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:46:44 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/26 12:50:11 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unity.h"
#include "ft_array_create.h"
#include "ft_array_destroy.h"
#include "ft_array_add.h"
#include "ft_closest_power_ul.h"
#include "ft_m_data.h"
#include <stdlib.h>

#define SIZE 10

static t_s_array	*g_array;

void	test_ft_array_create(void)
{
	g_array = ft_array_create(SIZE);
	TEST_ASSERT_NOT_NULL(g_array);
	TEST_ASSERT_NOT_NULL(g_array->data);
	TEST_ASSERT_EQUAL_INT(ft_closest_power_ul(SIZE, 2), g_array->footprint);
}

void	test_ft_array_add(void)
{
	size_t	closest_power;
	size_t	i;

	TEST_ASSERT_NOT_NULL(g_array);
	closest_power = ft_closest_power_ul(SIZE, 2);
	i = (size_t)(-1);
	while (++i < closest_power)
		ft_array_add(g_array, i);
	TEST_ASSERT_EQUAL_INT(closest_power, g_array->index);
	i = (size_t)(-1);
	printf("ADD\n");
	while (++i < closest_power)
	{
		printf("%d\n", g_array->data[i]);
		TEST_ASSERT_EQUAL_INT(i, g_array->data[i]);
	}
}

void	test_ft_array_add_bulk(void)
{
	size_t	index;
	size_t	footprint;
	size_t	i;
	int		*data;

	TEST_ASSERT_NOT_NULL(g_array);
	index = g_array->index;
	footprint = g_array->footprint;
	i = index - 1;
	data = ft_mock_data((int)index, (int)(footprint * 2));
	TEST_ASSERT_NOT_NULL(data);
	ft_array_add_bulk(g_array, data, footprint * 2 - index);
	printf("ADD BULK\n");
	while (++i < g_array->index)
	{
		printf("%d\n", g_array->data[i]);
		TEST_ASSERT_EQUAL_INT(i, g_array->data[i]);
	}
	free(data);
}

void	test_ft_array_destroy(void)
{
	ft_array_destroy(g_array);
}
