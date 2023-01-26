/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_array_insert.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:42:17 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/26 13:36:22 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unity.h"
#include "ft_m_array.h"
#include "ft_m_data.h"
#include "ft_array_destroy.h"
#include "ft_array_insert.h"
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

void	test_ft_array_insert_invalid(void)
{
	TEST_ASSERT_EQUAL_INT(SIZE_ERROR, ft_array_insert(g_array, (size_t)-1, 12));
	TEST_ASSERT_EQUAL_INT(SIZE_ERROR, ft_array_insert(g_array, SIZE, 12));
}

void	test_ft_array_insert_valid(void)
{
	size_t	i;

	TEST_ASSERT_NOT_NULL(g_array);
	i = (size_t)(-1);
	while (++i < SIZE)
		TEST_ASSERT_EQUAL_INT(NO_ERROR, ft_array_insert(g_array, i, (int)i));
	i = (size_t)(-1);
	printf("INSERT VALID\n");
	while (++i < SIZE)
	{
		printf("%d\n", g_array->data[i]);
		TEST_ASSERT_EQUAL_INT(i, g_array->data[i]);
	}
}

void	test_ft_array_insert_bulk_invalid(void)
{
	int	*data;

	TEST_ASSERT_NOT_NULL(g_array);
	data = ft_mock_data(0, SIZE);
	TEST_ASSERT_NOT_NULL(data);
	TEST_ASSERT_EQUAL_INT(
		SIZE_ERROR, ft_array_insert_bulk(g_array, (size_t)(-1), data, SIZE));
	TEST_ASSERT_EQUAL_INT(
		SIZE_ERROR, ft_array_insert_bulk(g_array, SIZE, data, SIZE));
	TEST_ASSERT_EQUAL_INT(
		SIZE_ERROR, ft_array_insert_bulk(g_array, 1, data, SIZE));
	free(data);
}

void	test_ft_array_insert_bulk_valid(void)
{
	int		*data;
	size_t	i;

	TEST_ASSERT_NOT_NULL(g_array);
	data = ft_mock_data(0, SIZE);
	TEST_ASSERT_NOT_NULL(data);
	TEST_ASSERT_EQUAL_INT(
		NO_ERROR, ft_array_insert_bulk(g_array, 0, data, SIZE));
	i = (size_t)(-1);
	printf("INSERT BULK VALID\n");
	while (++i < SIZE)
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
