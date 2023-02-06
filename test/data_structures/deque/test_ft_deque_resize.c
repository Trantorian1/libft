/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_deque_resize.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 15:50:10 by emcnab            #+#    #+#             */
/*   Updated: 2023/02/06 13:06:22 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_error_handle.h"
#include "unity.h"
#include "ft_deque.h"
#include "ft_deque_pop_front.h"
#include "ft_deque_pop_front_bulk.h"
#include "ft_deque_poll_front.h"
#include "ft_deque_pop_back.h"
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

void	test_ft_deque_grow_top(void)
{
	size_t	size_data;
	size_t	bottom;
	int		i;

	size_data = g_deque->size_data;
	bottom = g_deque->bottom;
	i = ft_deque_poll_front(g_deque) + 1;
	TEST_ASSERT_EQUAL_INT(16, g_deque->size_data);
	while (g_deque->size_data == size_data)
	{
		ft_deque_push_front(g_deque, i++);
		TEST_ASSERT_FALSE(ft_error_occurred());
	}
	TEST_ASSERT_EQUAL_INT(bottom, g_deque->bottom);
	TEST_ASSERT_EQUAL_INT(32, g_deque->size_data);
}

void	test_ft_deque_shrink_top(void)
{
	int	i;

	i = ft_deque_poll_front(g_deque);
	while (g_deque->top > g_deque->size_data / SHRINK_FACTOR)
		TEST_ASSERT_EQUAL_INT(i--, ft_deque_pop_front(g_deque));
	TEST_ASSERT_EQUAL_INT(i--, ft_deque_pop_front(g_deque));	
	TEST_ASSERT_EQUAL_INT(16, g_deque->size_data);
}

void	test_ft_reset(void)
{
	int	i;

	i = ft_deque_poll_front(g_deque) + 1;
	while (i <= SIZE)
	{
		ft_deque_push_front(g_deque, i++);
		TEST_ASSERT_FALSE(ft_error_occurred());
	}
	TEST_ASSERT_EQUAL_INT(SIZE, ft_deque_poll_front(g_deque));
}

void	test_ft_deque_grow_bottom(void)
{
	size_t	size_data;
	size_t	space_top;
	int		i;

	size_data = g_deque->size_data;
	space_top = g_deque->size_data - g_deque->top;
	i = ft_deque_poll_back(g_deque) - 1;
	TEST_ASSERT_EQUAL_INT(16, g_deque->size_data);
	while (g_deque->size_data == size_data)
	{
		ft_deque_push_back(g_deque, i--);
		TEST_ASSERT_FALSE(ft_error_occurred());
	}
	TEST_ASSERT_EQUAL_INT(space_top, g_deque->size_data - g_deque->top);
	TEST_ASSERT_EQUAL_INT(32, g_deque->size_data);
}

void	test_ft_deque_shrink_bottom(void)
{
	int	i;

	i = ft_deque_poll_back(g_deque);
	while (g_deque->size_data - g_deque->bottom >=
		g_deque->size_data / SHRINK_FACTOR)
		TEST_ASSERT_EQUAL_INT(i++, ft_deque_pop_back(g_deque));
	TEST_ASSERT_EQUAL_INT(i++, ft_deque_pop_back(g_deque));	
	TEST_ASSERT_EQUAL_INT(16, g_deque->size_data);
}

void	test_ft_deque_destroy(void)
{
	TEST_ASSERT_NOT_NULL_MESSAGE(g_deque, MSG_NULL_DEQUE);
	ft_deque_destroy(g_deque, &free);
	free(g_data);
}
