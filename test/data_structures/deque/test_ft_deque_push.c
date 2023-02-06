/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_deque_push.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:17:06 by emcnab            #+#    #+#             */
/*   Updated: 2023/02/06 12:56:41 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_error_handle.h"
#include "unity.h"
#include "ft_deque.h"
#include "ft_deque_pop_front.h"
#include "ft_deque_pop_front_bulk.h"
#include "ft_deque_poll_front.h"
#include "ft_deque_pop_back_bulk.h"
#include "ft_deque_poll_back.h"
#include "ft_deque_push_front.h"
#include "ft_deque_push_front_bulk.h"
#include "ft_deque_push_back.h"
#include "ft_deque_push_back_bulk.h"
#include "ft_deque_size.h"
#include "ft_deque_is_empty.h"
#include "errors.h"
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <sys/types.h>

#define SIZE 10
#define MSG_NULL_DATA "failed to create deque data due to malloc error"
#define MSG_NULL_DEQUE "failed to create deque struct due to malloc error"

static int			*g_data = NULL;
static t_s_deque	*g_deque = NULL;

void	test_ft_data_create(void)
{
	unsigned int	n;

	n = SIZE;
	g_data = malloc(n * sizeof(*g_data));
	TEST_ASSERT_NOT_NULL_MESSAGE(g_data, MSG_NULL_DATA);
	while (n--)
	{
		g_data[n] = (int) n;
	}
}

void	test_ft_deque_create(void)
{
	TEST_ASSERT_NOT_NULL_MESSAGE(g_data, MSG_NULL_DEQUE);
	g_deque = ft_deque_new(SIZE);
	ft_deque_push_front_bulk(g_deque, g_data, SIZE);
	TEST_ASSERT_FALSE(ft_error_occurred());
	TEST_ASSERT_NOT_NULL_MESSAGE(g_deque, MSG_NULL_DEQUE);
	TEST_ASSERT_EQUAL_INT(SIZE, g_deque->size_actual);
}

void	test_ft_deque_add_front(void)
{
	int	data_bulk[] = { 10, 11, 12, 13, 14, 15 };
	int	*data;

	TEST_ASSERT_NOT_NULL_MESSAGE(g_deque, MSG_NULL_DEQUE);
	ft_deque_push_front(g_deque, 10);
	TEST_ASSERT_FALSE(ft_error_occurred());
	ft_deque_push_front(g_deque, 11);
	TEST_ASSERT_FALSE(ft_error_occurred());
	ft_deque_push_front(g_deque, 12);
	TEST_ASSERT_FALSE(ft_error_occurred());
	ft_deque_push_front(g_deque, 13);
	TEST_ASSERT_FALSE(ft_error_occurred());
	ft_deque_push_front(g_deque, 14);
	TEST_ASSERT_FALSE(ft_error_occurred());
	ft_deque_push_front(g_deque, 15);
	TEST_ASSERT_FALSE(ft_error_occurred());
	TEST_ASSERT_EQUAL_INT(16, ft_deque_size(g_deque));
	data = ft_deque_pop_front_bulk(g_deque, 6);
	TEST_ASSERT_EQUAL_INT_ARRAY(data_bulk, data, 6);
	free(data);
}

void	test_ft_deque_add_back(void)
{
	int	data_bulk[] = { -6, -5, -4, -3, -2, -1 };
	int	*data;

	TEST_ASSERT_NOT_NULL_MESSAGE(g_deque, MSG_NULL_DEQUE);
	ft_deque_push_back(g_deque, -1);
	TEST_ASSERT_FALSE(ft_error_occurred());
	ft_deque_push_back(g_deque, -2);
	TEST_ASSERT_FALSE(ft_error_occurred());
	ft_deque_push_back(g_deque, -3);
	TEST_ASSERT_FALSE(ft_error_occurred());
	ft_deque_push_back(g_deque, -4);
	TEST_ASSERT_FALSE(ft_error_occurred());
	ft_deque_push_back(g_deque, -5);
	TEST_ASSERT_FALSE(ft_error_occurred());
	ft_deque_push_back(g_deque, -6);
	TEST_ASSERT_FALSE(ft_error_occurred());
	TEST_ASSERT_EQUAL_INT(16, ft_deque_size(g_deque));
	data = ft_deque_pop_back_bulk(g_deque, 6);
	TEST_ASSERT_EQUAL_INT_ARRAY(data_bulk, data, 6);
	free(data);
}

void	test_ft_deque_destroy(void)
{
	TEST_ASSERT_NOT_NULL_MESSAGE(g_deque, MSG_NULL_DEQUE);
	ft_deque_destroy(g_deque, &free);
	free(g_data);
}
