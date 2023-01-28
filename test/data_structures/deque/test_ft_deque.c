/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_deque.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 15:50:10 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/28 17:13:32 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unity.h"
#include "ft_deque.h"
#include "ft_deque_push_front_bulk.h"
#include "ft_error_handle.h"
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <sys/types.h>

#define SIZE 10
#define MSG_NULL_DATA "failed to create deque data due to malloc error"
#define MSG_NULL_DEQUE "failed to create deque struct due to malloc error"

static int			*g_data = NULL;
static t_s_deque	*g_deque = NULL;

void	test_ft_data_create(void);
void	test_ft_deque_create(void);
void	test_ft_deque_destroy(void);

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

void	test_ft_deque_destroy(void)
{
	TEST_ASSERT_NOT_NULL_MESSAGE(g_deque, MSG_NULL_DEQUE);
	ft_deque_destroy(g_deque, &free);
	free(g_data);
}
