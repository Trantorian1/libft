/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isalnum.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 09:00:14 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/13 11:37:50 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_isalnum.h"
#include "unity.h"

void	test_ft_isalnum_with_alphabetic_characters(void)
{
	TEST_ASSERT_TRUE(ft_isalnum('A'));
	TEST_ASSERT_TRUE(ft_isalnum('Z'));
	TEST_ASSERT_TRUE(ft_isalnum('a'));
	TEST_ASSERT_TRUE(ft_isalnum('z'));
}

void	test_ft_isalnum_with_numeric_characters(void)
{
	TEST_ASSERT_TRUE(ft_isalnum('0'));
	TEST_ASSERT_TRUE(ft_isalnum('9'));
}

void	test_ft_isalnum_with_special_characters(void)
{
	TEST_ASSERT_FALSE(ft_isalnum(' '));
	TEST_ASSERT_FALSE(ft_isalnum('$'));
	TEST_ASSERT_FALSE(ft_isalnum('!'));
}
