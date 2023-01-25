/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:08:28 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/25 16:13:03 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unity.h"
#include "ft_array_create.h"
#include "ft_array_destroy.h"

#define SIZE 10

static t_s_array	*g_array;

void	test_ft_array_create(void)
{
	g_array = ft_array_create(SIZE);
	TEST_ASSERT_NOT_NULL(g_array);
	TEST_ASSERT_NOT_NULL(g_array->data);
	TEST_ASSERT_EQUAL_INT(16, g_array->footprint);
}

void	test_ft_array_destroy(void)
{
	ft_array_destroy(g_array);
}
