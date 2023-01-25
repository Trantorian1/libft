/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_array_mock.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:20:59 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/25 16:24:41 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unity.h"
#include "ft_array_mock.h"
#include "ft_array_destroy.h"

#define SIZE 10

static t_s_array	*g_array;

void	test_ft_array_create(void)
{
	g_array = ft_array_mock(0, SIZE);
	TEST_ASSERT_NOT_NULL(g_array);
	TEST_ASSERT_NOT_NULL(g_array->data);
	TEST_ASSERT_EQUAL_INT(16, g_array->footprint);
}

void	test_ft_array_mock(void)
{
	size_t	i;

	TEST_ASSERT_NOT_NULL(g_array);
	i = (size_t)(-1);
	while (++i < SIZE)
	{
		printf("%d\n", g_array->data[i]);
		TEST_ASSERT_EQUAL_INT(i, g_array->data[i]);
	}
}

void	test_ft_array_destroy(void)
{
	ft_array_destroy(g_array);
}
