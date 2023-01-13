/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isdigit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 11:46:47 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/13 11:50:55 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unity.h"
#include "ft_isdigit.h"

void	test_ft_isdigit_numeric(void)
{
	TEST_ASSERT_TRUE(ft_isdigit('0'));
	TEST_ASSERT_TRUE(ft_isdigit('9'));
}

void	test_ft_isdigit_alphabet(void)
{
	TEST_ASSERT_FALSE(ft_isdigit('a'));
	TEST_ASSERT_FALSE(ft_isdigit('z'));
	TEST_ASSERT_FALSE(ft_isdigit('A'));
	TEST_ASSERT_FALSE(ft_isdigit('Z'));
}

void	test_ft_isdigit_edge_characters(void)
{
	TEST_ASSERT_FALSE(ft_isdigit('0' - 1));
	TEST_ASSERT_FALSE(ft_isdigit('9' + 1));
	TEST_ASSERT_FALSE(ft_isdigit('\0'));
	TEST_ASSERT_FALSE(ft_isdigit('~'));
}
