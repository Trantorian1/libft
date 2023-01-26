/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_deque_to_array.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 14:35:54 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/26 20:21:38 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unity.h"

#include "ft_deque_to_array.h"
#include "ft_m_deque.h"
#include "ft_deque.h"
#include <stdlib.h>
#include <unistd.h>

#define MIN 0
#define MAX 10

static t_s_deque	*g_deque;

void	test_create(void)
{
	g_deque = ft_mock_deque(MIN, MAX);
	TEST_ASSERT_NOT_NULL(g_deque);
}

void	test_ft_deque_to_array(void)
{
	int	*expected;
	int	i;
	int	*data;

	expected = malloc((MAX - MIN) * sizeof(*expected));
	TEST_ASSERT_NOT_NULL(expected);
	i = MIN - 1;
	while (++i < MAX)
		expected[i - MIN] = i;
	data = ft_deque_to_array(g_deque);
	TEST_ASSERT_EQUAL_INT_ARRAY(expected, data, MAX - MIN);
	free(data);
	free(expected);
}

void	test_detroy(void)
{
	ft_deque_destroy(g_deque, &free);
}
