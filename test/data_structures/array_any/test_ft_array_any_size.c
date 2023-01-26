/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_array_any_size.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 19:08:38 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/26 12:47:46 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unity.h"
#include "ft_m_array_any.h"
#include "ft_m_any.h"
#include "ft_array_any_destroy.h"
#include "ft_array_any_size.h"
#include "ft_array_any_add.h"
#include "ft_closest_power_ul.h"
#include "errors.h"
#include <stdlib.h>

#define SIZE 10

static t_s_array_any	*g_array;

void	test_ft_array_create(void)
{
	g_array = ft_mock_array_any(0, SIZE);
	TEST_ASSERT_NOT_NULL(g_array);
	TEST_ASSERT_NOT_NULL(g_array->data);
	TEST_ASSERT_EQUAL_INT(ft_closest_power_ul(SIZE, 2), g_array->footprint);
}

void	test_ft_array_size_base(void)
{
	TEST_ASSERT_NOT_NULL(g_array);
	TEST_ASSERT_EQUAL_INT(SIZE, ft_array_any_size(g_array));
}

void	test_ft_array_size_add(void)
{
	int	**mock;

	TEST_ASSERT_NOT_NULL(g_array);
	mock = ft_mock_any_create(1);
	TEST_ASSERT_NOT_NULL(mock);
	ft_array_any_add(g_array, *mock);
	TEST_ASSERT_EQUAL_INT(SIZE + 1, ft_array_any_size(g_array));
	free(mock);
}

void	test_ft_array_size_add_bulk(void)
{
	int	**mock;

	TEST_ASSERT_NOT_NULL(g_array);
	mock = ft_mock_any_create(SIZE);
	TEST_ASSERT_NOT_NULL(mock);
	ft_array_any_add_bulk(g_array, (void**)mock, SIZE);
	TEST_ASSERT_EQUAL_INT(SIZE * 2 + 1, ft_array_any_size(g_array));
	free(mock);
}

void	test_ft_array_destroy(void)
{
	ft_array_any_destroy(g_array, &free);
}
