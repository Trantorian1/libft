/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_islower.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 13:28:03 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/13 13:36:27 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unity.h"
#include "ft_islower.h"

void	test_ft_islower_lower(void)
{
	TEST_ASSERT_TRUE(ft_islower('a'));
	TEST_ASSERT_TRUE(ft_islower('z'));
}

void	test_ft_islower_upper(void)
{
	TEST_ASSERT_FALSE(ft_islower('A'));
	TEST_ASSERT_FALSE(ft_islower('Z'));
}

void	test_ft_islower_edge(void)
{
	TEST_ASSERT_FALSE(ft_islower('a' - 1));
	TEST_ASSERT_FALSE(ft_islower('z' + 1));
	TEST_ASSERT_FALSE(ft_islower('\0'));
	TEST_ASSERT_FALSE(ft_islower('~'));
}
