/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_deque.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 15:50:10 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/13 19:35:52 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_deque_add_back.h"
#include "unity.h"
#include "ft_deque.h"
#include "ft_deque_pop_front.h"
#include "ft_deque_poll_front.h"
#include "ft_deque_pop_back.h"
#include "ft_deque_poll_back.h"
#include "ft_deque_add_front.h"
#include "ft_deque_size.h"
#include "ft_deque_is_empty.h"
#include "errors.h"
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
	g_deque = ft_deque_new(g_data, SIZE);
	TEST_ASSERT_NOT_NULL_MESSAGE(g_deque, MSG_NULL_DEQUE);
	TEST_ASSERT_EQUAL_INT(SIZE, g_deque->size_actual);
}

void	test_ft_deque_add_front(void)
{
	TEST_ASSERT_NOT_NULL_MESSAGE(g_deque, MSG_NULL_DEQUE);
	TEST_ASSERT_EQUAL_INT(NO_ERROR, ft_deque_add_front(g_deque, 10));
	TEST_ASSERT_EQUAL_INT(NO_ERROR, ft_deque_add_front(g_deque, 11));
	TEST_ASSERT_EQUAL_INT(NO_ERROR, ft_deque_add_front(g_deque, 12));
	TEST_ASSERT_EQUAL_INT(NO_ERROR, ft_deque_add_front(g_deque, 13));
	TEST_ASSERT_EQUAL_INT(NO_ERROR, ft_deque_add_front(g_deque, 14));
	TEST_ASSERT_EQUAL_INT(NO_ERROR, ft_deque_add_front(g_deque, 15));
	TEST_ASSERT_EQUAL_INT(16, ft_deque_size(g_deque));
	TEST_ASSERT_EQUAL_INT(15, ft_deque_poll_front(g_deque));
	TEST_ASSERT_EQUAL_INT(15, ft_deque_pop_front(g_deque));
	TEST_ASSERT_EQUAL_INT(14, ft_deque_poll_front(g_deque));
	TEST_ASSERT_EQUAL_INT(14, ft_deque_pop_front(g_deque));
	TEST_ASSERT_EQUAL_INT(13, ft_deque_poll_front(g_deque));
	TEST_ASSERT_EQUAL_INT(13, ft_deque_pop_front(g_deque));
	TEST_ASSERT_EQUAL_INT(12, ft_deque_poll_front(g_deque));
	TEST_ASSERT_EQUAL_INT(12, ft_deque_pop_front(g_deque));
	TEST_ASSERT_EQUAL_INT(11, ft_deque_poll_front(g_deque));
	TEST_ASSERT_EQUAL_INT(11, ft_deque_pop_front(g_deque));
	TEST_ASSERT_EQUAL_INT(10, ft_deque_poll_front(g_deque));
	TEST_ASSERT_EQUAL_INT(10, ft_deque_pop_front(g_deque));
	TEST_ASSERT_EQUAL_INT(10, ft_deque_size(g_deque));
}

void	test_ft_deque_add_back(void)
{
	TEST_ASSERT_NOT_NULL_MESSAGE(g_deque, MSG_NULL_DEQUE);
	TEST_ASSERT_EQUAL_INT(NO_ERROR, ft_deque_add_back(g_deque, -1));
	TEST_ASSERT_EQUAL_INT(NO_ERROR, ft_deque_add_back(g_deque, -2));
	TEST_ASSERT_EQUAL_INT(NO_ERROR, ft_deque_add_back(g_deque, -3));
	TEST_ASSERT_EQUAL_INT(NO_ERROR, ft_deque_add_back(g_deque, -4));
	TEST_ASSERT_EQUAL_INT(NO_ERROR, ft_deque_add_back(g_deque, -5));
	TEST_ASSERT_EQUAL_INT(NO_ERROR, ft_deque_add_back(g_deque, -6));
	TEST_ASSERT_EQUAL_INT(16, ft_deque_size(g_deque));
	TEST_ASSERT_EQUAL_INT(-6, ft_deque_poll_back(g_deque));
	TEST_ASSERT_EQUAL_INT(-6, ft_deque_pop_back(g_deque));
	TEST_ASSERT_EQUAL_INT(-5, ft_deque_poll_back(g_deque));
	TEST_ASSERT_EQUAL_INT(-5, ft_deque_pop_back(g_deque));
	TEST_ASSERT_EQUAL_INT(-4, ft_deque_poll_back(g_deque));
	TEST_ASSERT_EQUAL_INT(-4, ft_deque_pop_back(g_deque));
	TEST_ASSERT_EQUAL_INT(-3, ft_deque_poll_back(g_deque));
	TEST_ASSERT_EQUAL_INT(-3, ft_deque_pop_back(g_deque));
	TEST_ASSERT_EQUAL_INT(-2, ft_deque_poll_back(g_deque));
	TEST_ASSERT_EQUAL_INT(-2, ft_deque_pop_back(g_deque));
	TEST_ASSERT_EQUAL_INT(-1, ft_deque_poll_back(g_deque));
	TEST_ASSERT_EQUAL_INT(-1, ft_deque_pop_back(g_deque));
	TEST_ASSERT_EQUAL_INT(10, ft_deque_size(g_deque));
}

void	test_ft_deque_contents_front(void)
{
	TEST_ASSERT_NOT_NULL_MESSAGE(g_deque, MSG_NULL_DEQUE);
	TEST_ASSERT_EQUAL_INT(9, ft_deque_pop_front(g_deque));
	TEST_ASSERT_EQUAL_INT(8, ft_deque_pop_front(g_deque));
	TEST_ASSERT_EQUAL_INT(7, ft_deque_pop_front(g_deque));
	TEST_ASSERT_EQUAL_INT(6, ft_deque_pop_front(g_deque));
	TEST_ASSERT_EQUAL_INT(5, ft_deque_pop_front(g_deque));
	TEST_ASSERT_EQUAL_INT(5, ft_deque_size(g_deque));
}

void	test_ft_deque_contents_back(void)
{
	TEST_ASSERT_NOT_NULL_MESSAGE(g_deque, MSG_NULL_DEQUE);
	TEST_ASSERT_EQUAL_INT(0, ft_deque_pop_back(g_deque));
	TEST_ASSERT_EQUAL_INT(1, ft_deque_pop_back(g_deque));
	TEST_ASSERT_EQUAL_INT(2, ft_deque_pop_back(g_deque));
	TEST_ASSERT_EQUAL_INT(3, ft_deque_pop_back(g_deque));
	TEST_ASSERT_EQUAL_INT(4, ft_deque_pop_back(g_deque));
	TEST_ASSERT_EQUAL_INT(0, ft_deque_size(g_deque));
}

void	test_ft_deque_destroy(void)
{
	TEST_ASSERT_NOT_NULL_MESSAGE(g_deque, MSG_NULL_DEQUE);
	ft_deque_destroy(g_deque, &free);
}
