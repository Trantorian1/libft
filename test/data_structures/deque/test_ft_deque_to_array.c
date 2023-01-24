/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_deque_to_array.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 14:35:54 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/24 14:43:18 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unity.h"

#include "ft_deque_to_array.h"
#include "ft_deque_mock.h"
#include "ft_deque.h"
#include <stdlib.h>

#define MIN 0
#define MAX 10

static t_s_deque	*g_deque;

void	test_create(void)
{
	g_deque = ft_deque_mock(MIN, MAX);
	TEST_ASSERT_NOT_NULL(g_deque);
}

void	test_ft_deque_to_array(void)
{
	int	*expected;
	int	i;

	expected = malloc((MAX - MIN) * sizeof(*expected));
	TEST_ASSERT_NOT_NULL(expected);
	i = MIN - 1;
	while (++i < MAX)
		expected[i - MIN] = i;
	TEST_ASSERT_EQUAL_INT_ARRAY(expected, ft_deque_to_array(g_deque), MAX - MIN);
}

void	test_detroy(void)
{
	ft_deque_destroy(g_deque);
}
