/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isascii.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 11:39:29 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/13 13:27:42 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unity.h"
#include "ft_isascii.h"
#include <limits.h>

void	test_ft_isascii_alphanumeric_characters(void)
{
	TEST_ASSERT_TRUE(ft_isascii('A'));
	TEST_ASSERT_TRUE(ft_isascii('Z'));
	TEST_ASSERT_TRUE(ft_isascii('a'));
	TEST_ASSERT_TRUE(ft_isascii('z'));
	TEST_ASSERT_TRUE(ft_isascii('0'));
	TEST_ASSERT_TRUE(ft_isascii('9'));
}

void	test_ft_isascii_edge_chracters(void)
{
	TEST_ASSERT_TRUE(ft_isascii('\0'));
	TEST_ASSERT_TRUE(ft_isascii('~'));
}

void	test_ft_isascii_extended_ascii_characters(void)
{
	TEST_ASSERT_FALSE(ft_isascii(UCHAR_MAX));
	TEST_ASSERT_FALSE(ft_isascii(CHAR_MIN));
}
