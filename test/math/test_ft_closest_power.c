/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_closest_power.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:05:50 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/13 16:25:21 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unity.h"
#include <limits.h>
#include "ft_closest_power.h"

void	test_ft_closest_power_positive(void)
{
	TEST_ASSERT_EQUAL_INT(ft_closest_power(2, 0), 1);
	TEST_ASSERT_EQUAL_INT(ft_closest_power(2, 2), 2);
	TEST_ASSERT_EQUAL_INT(ft_closest_power(10, 2), 16);
}

void	test_ft_closest_power_negative(void)
{
	TEST_ASSERT_EQUAL_INT(ft_closest_power(-12, 0), 1);
	TEST_ASSERT_EQUAL_INT(ft_closest_power(-2, 2), 1);
	TEST_ASSERT_EQUAL_INT(ft_closest_power(-2, 3), 1);
}

void	test_ft_closest_power_edge(void)
{
	TEST_ASSERT_EQUAL_INT(ft_closest_power(INT_MAX, 2), 1073741824);
	TEST_ASSERT_EQUAL_INT(ft_closest_power(0, 12), 0);
	TEST_ASSERT_EQUAL_INT(ft_closest_power(0, 0), 1);
}
