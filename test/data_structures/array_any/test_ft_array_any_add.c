/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_array_any_add.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:46:44 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/26 12:05:23 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unity.h"
#include "ft_array_any_create.h"
#include "ft_array_any_destroy.h"
#include "ft_array_any_add.h"
#include "ft_closest_power_ul.h"
#include "ft_m_any.h"
#include <stdlib.h>

#define SIZE 10

static t_s_array_any	*g_array;

void	test_ft_array_any_create(void)
{
	g_array = ft_array_any_create(SIZE);
	TEST_ASSERT_NOT_NULL(g_array);
	TEST_ASSERT_NOT_NULL(g_array->data);
	TEST_ASSERT_EQUAL_INT(ft_closest_power_ul(SIZE, 2), g_array->footprint);
}

void	test_ft_array_any_add(void)
{
	size_t	footprint;
	size_t	i;
	int		**mock;

	footprint = g_array->footprint;
	mock = ft_mock_any_create(footprint);
	TEST_ASSERT_NOT_NULL(mock);
	printf("ADD ANY\n");
	i = (size_t)(-1);
	while (++i < footprint)
	{
		ft_array_any_add(g_array, mock[i]);
		printf("%d\n", *((int *)g_array->data[i]));
		TEST_ASSERT_EQUAL_INT(i, *((int *)g_array->data[i]));
	}
	TEST_ASSERT_EQUAL_INT(footprint, g_array->footprint);
	free(mock);
}

void	test_ft_array_any_add_bulk(void)
{
	size_t	footprint;
	size_t	target;
	size_t	i;
	int		**mock;

	footprint = g_array->footprint;
	target = footprint * 2 + 1;
	mock = ft_mock_any_create(target - footprint);
	TEST_ASSERT_NOT_NULL(mock);
	i = footprint - 1;
	ft_array_any_add_bulk(g_array, (void **)mock, target - footprint);
	printf("ADD ANY BULK\n");
	while (++i < target)
	{
		printf("%d\n", *((int *)g_array->data[i]));
		TEST_ASSERT_EQUAL_INT(i - footprint, *((int *)g_array->data[i]));
	}
	TEST_ASSERT_EQUAL_INT(footprint * 4, g_array->footprint);
	free(mock);
}

void	test_ft_array_destroy(void)
{
	ft_array_any_destroy(g_array, &free);
}
