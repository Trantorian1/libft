/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isprint.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 13:37:36 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/13 13:48:07 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unity.h"
#include "ft_isprint.h"

void	test_ft_isprint_alphanum(void)
{
	TEST_ASSERT_TRUE(ft_isprint('a'));
	TEST_ASSERT_TRUE(ft_isprint('z'));
	TEST_ASSERT_TRUE(ft_isprint('A'));
	TEST_ASSERT_TRUE(ft_isprint('Z'));
	TEST_ASSERT_TRUE(ft_isprint('0'));
	TEST_ASSERT_TRUE(ft_isprint('9'));
}

void	test_ft_isprint_special(void)
{
	TEST_ASSERT_TRUE(ft_isprint(' '));
	TEST_ASSERT_TRUE(ft_isprint('/'));
	TEST_ASSERT_TRUE(ft_isprint(':'));
	TEST_ASSERT_TRUE(ft_isprint('@'));
	TEST_ASSERT_TRUE(ft_isprint('['));
	TEST_ASSERT_TRUE(ft_isprint('`'));
	TEST_ASSERT_TRUE(ft_isprint('{'));
	TEST_ASSERT_TRUE(ft_isprint('~'));
}

void	test_ft_isprint_edge(void)
{
	TEST_ASSERT_FALSE(ft_isprint(' ' - 1));
	TEST_ASSERT_FALSE(ft_isprint('~' + 1));
}
