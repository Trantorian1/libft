/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_array_size.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 19:08:38 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/26 13:38:04 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unity.h"
#include "ft_m_array.h"
#include "ft_m_data.h"
#include "ft_array_destroy.h"
#include "ft_array_size.h"
#include "ft_array_add.h"
#include "ft_closest_power_ul.h"
#include "errors.h"
#include <stdlib.h>

#define SIZE 10

static t_s_array	*g_array;

void	test_ft_array_create(void)
{
	g_array = ft_mock_array(0, SIZE);
	TEST_ASSERT_NOT_NULL(g_array);
	TEST_ASSERT_NOT_NULL(g_array->data);
	TEST_ASSERT_EQUAL_INT(ft_closest_power_ul(SIZE, 2), g_array->footprint);
}

void	test_ft_array_size_base(void)
{
	TEST_ASSERT_NOT_NULL(g_array);
	TEST_ASSERT_EQUAL_INT(SIZE, ft_array_size(g_array));
}

void	test_ft_array_size_add(void)
{
	TEST_ASSERT_NOT_NULL(g_array);
	ft_array_add(g_array, 12);
	TEST_ASSERT_EQUAL_INT(SIZE + 1, ft_array_size(g_array));
}

void	test_ft_array_size_add_bulk(void)
{
	int	*data;

	TEST_ASSERT_NOT_NULL(g_array);
	data = ft_mock_data(0, SIZE);
	TEST_ASSERT_NOT_NULL(data);
	ft_array_add_bulk(g_array, data, SIZE);
	TEST_ASSERT_EQUAL_INT(SIZE * 2 + 1, ft_array_size(g_array));
	free(data);
}

void	test_ft_array_destroy(void)
{
	ft_array_destroy(g_array);
}
