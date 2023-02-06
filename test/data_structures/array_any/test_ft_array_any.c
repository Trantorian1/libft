/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_array_any.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:08:28 by emcnab            #+#    #+#             */
/*   Updated: 2023/02/06 13:28:50 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_deque_poll_back.h"
#include "ft_deque_size.h"
#include "ft_deque_to_array.h"
#include "ft_error_queu.h"
#include "unity.h"
#include "ft_array_any_create.h"
#include "ft_array_any_destroy.h"
#include "ft_error_handle.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define SIZE 10

static t_s_array_any	*g_array;

void	test_ft_array_any_create(void)
{
	g_array = ft_array_any_create(SIZE);
	TEST_ASSERT_FALSE(ft_error_occurred());
	TEST_ASSERT_NOT_NULL(g_array);
	TEST_ASSERT_NOT_NULL(g_array->data);
	TEST_ASSERT_EQUAL_INT(16, g_array->footprint);
}

void    test_ft_array_any_destroy_invalid(void)
{
    ft_array_any_destroy(NULL, 0);
    TEST_ASSERT_TRUE(ft_error_catch(ERROR_NULL_PARAM));
    TEST_ASSERT_FALSE(ft_error_occurred());
}

void	test_ft_array_any_destroy(void)
{
	ft_array_any_destroy(g_array, &free);
}
