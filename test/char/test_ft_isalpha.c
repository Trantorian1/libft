/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isalpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 18:52:27 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/12 18:56:09 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_isalpha.h"
#include "unity.h"

void	test_ft_isalpha_upper(void)
{
	TEST_ASSERT_TRUE(ft_isalpha('A'));
	TEST_ASSERT_TRUE(ft_isalpha('Z'));
}

void	test_ft_isalpha_lower(void)
{
	TEST_ASSERT_TRUE(ft_isalpha('a'));
	TEST_ASSERT_TRUE(ft_isalpha('z'));
}

void	test_ft_isalpha_digits(void)
{
	TEST_ASSERT_FALSE(ft_isalpha('0'));
	TEST_ASSERT_FALSE(ft_isalpha('9'));
}

void	test_ft_isalpha_special_chars(void)
{
	TEST_ASSERT_FALSE(ft_isalpha('!'));
	TEST_ASSERT_FALSE(ft_isalpha('@'));
}
