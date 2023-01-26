/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_array_get.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:25:01 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/26 13:34:29 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_array_get.h"
#include "unity.h"
#include "ft_m_array.h"
#include "ft_array_destroy.h"
#include "ft_array_get.h"

#define SIZE 10

static t_s_array	*g_array;

void	test_ft_array_create(void)
{
	g_array = ft_mock_array(0, SIZE);
	TEST_ASSERT_NOT_NULL(g_array);
	TEST_ASSERT_NOT_NULL(g_array->data);
	TEST_ASSERT_EQUAL_INT(16, g_array->footprint);
}

void	test_ft_array_get(void)
{
	size_t	i;

	TEST_ASSERT_NOT_NULL(g_array);
	i = (size_t)(-1);
	while (++i < SIZE * 2)
	{
		printf("%d\n", ft_array_get(g_array, i));
		TEST_ASSERT_EQUAL_INT(i % g_array->index, ft_array_get(g_array, i));
	}
}

void	test_ft_array_destroy(void)
{
	ft_array_destroy(g_array);
}
