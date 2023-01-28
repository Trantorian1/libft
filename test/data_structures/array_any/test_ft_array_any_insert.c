/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_array_any_insert.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:42:17 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/26 18:52:49 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unity.h"
#include "ft_m_array_any.h"
#include "ft_m_any.h"
#include "ft_array_any_destroy.h"
#include "ft_array_any_insert.h"
#include "ft_closest_power_ul.h"
#include "ft_error_handle.h"
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

void	test_ft_array_insert_invalid(void)
{
    ft_array_any_insert(g_array, (size_t)-1, NULL);
    TEST_ASSERT_TRUE(ft_error_catch(ERROR_INDEX_OUT_OF_BOUNDS));
    ft_array_any_insert(g_array, SIZE, NULL);
    TEST_ASSERT_TRUE(ft_error_catch(ERROR_INDEX_OUT_OF_BOUNDS));
}

void	test_ft_array_insert_valid(void)
{
	int		**mock;
	size_t	i;

	TEST_ASSERT_NOT_NULL(g_array);
	mock = ft_mock_any_create(SIZE);
	i = (size_t)(-1);
	while (++i < SIZE)
	{
		free(g_array->data[i]);
        ft_array_any_insert(g_array, i, mock[i]);
        TEST_ASSERT_FALSE(ft_error_occurred());
	}
	i = (size_t)(-1);
	printf("INSERT VALID\n");
	while (++i < SIZE)
	{
		printf("%d\n", *(int *)g_array->data[i]);
		TEST_ASSERT_EQUAL_INT(i, *(int *)g_array->data[i]);
	}
	ft_mock_any_destroy(mock, SIZE);
}

void	test_ft_array_insert_bulk_invalid(void)
{
	int		**mock;

	TEST_ASSERT_NOT_NULL(g_array);
	mock = ft_mock_any_create(SIZE);
	TEST_ASSERT_NOT_NULL(mock);
    ft_array_any_insert_bulk(g_array, (size_t)(-1), (void **)mock, SIZE);
    TEST_ASSERT_TRUE(ft_error_catch(ERROR_INDEX_OUT_OF_BOUNDS));
    ft_array_any_insert_bulk(g_array, SIZE, (void **)mock, SIZE);
    TEST_ASSERT_TRUE(ft_error_catch(ERROR_INDEX_OUT_OF_BOUNDS));
	ft_mock_any_destroy(mock, SIZE);
}

void	test_ft_array_insert_bulk_valid(void)
{
	int		**mock;
	size_t	i;

	TEST_ASSERT_NOT_NULL(g_array);
	mock = ft_mock_any_create(SIZE);
	TEST_ASSERT_NOT_NULL(mock);
    ft_array_any_insert_bulk(g_array, 0, (void **)mock, SIZE);
    TEST_ASSERT_TRUE(ft_error_catch(ERROR_INDEX_OUT_OF_BOUNDS));
	i = (size_t)(-1);
	printf("INSERT BULK VALID\n");
	while (++i < SIZE)
	{
		printf("%d\n", *(int *)g_array->data[i]);
		TEST_ASSERT_EQUAL_INT(i, *(int *)g_array->data[i]);
	}
	free(mock);
}

void	test_ft_array_destroy(void)
{
	ft_array_any_destroy(g_array, &free);
}
