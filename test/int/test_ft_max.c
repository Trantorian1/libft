/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_max.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 17:18:03 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/13 11:35:40 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unity.h"
#include "ft_max.h"

#include "ft_max.h"

#include <limits.h>

void	test_max_first(void)
{
	TEST_ASSERT_EQUAL_INT(12, ft_max(0, 12));
	TEST_ASSERT_EQUAL_INT(INT_MAX, ft_max(12, INT_MAX));
}

void	test_max_last(void)
{
	TEST_ASSERT_EQUAL_INT(12, ft_max(12, 0));
	TEST_ASSERT_EQUAL_INT(INT_MAX, ft_max(12, INT_MAX));
	TEST_ASSERT_EQUAL_INT(INT_MAX, ft_max(INT_MAX, INT_MAX));
}
