/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_array_any_get.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:25:01 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/26 12:17:55 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unity.h"
#include "ft_m_array_any.h"
#include "ft_array_any_destroy.h"
#include "ft_array_any_get.h"
#include <stdlib.h>

#define SIZE 10

static t_s_array_any	*g_array;

void	test_ft_array_create(void)
{
	g_array = ft_mock_array_any(0, SIZE);
	TEST_ASSERT_NOT_NULL(g_array);
	TEST_ASSERT_NOT_NULL(g_array->data);
	TEST_ASSERT_EQUAL_INT(16, g_array->footprint);
}

void	test_ft_array_get(void)
{
	size_t	i;

	TEST_ASSERT_NOT_NULL(g_array);
	i = (size_t)(-1);
	printf("GET ANY\n");
	while (++i < SIZE * 2)
	{
		printf("%d\n", *(int *)ft_array_any_get(g_array, i));
		TEST_ASSERT_EQUAL_INT(i % g_array->index, *(int *)ft_array_any_get(g_array, i));
	}
}

void	test_ft_array_destroy(void)
{
	ft_array_any_destroy(g_array, &free);
}
