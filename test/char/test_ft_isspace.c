/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isspace.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 13:48:26 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/13 13:53:43 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unity.h"
#include "ft_isspace.h"

void	test_ft_isspace_spaces(void)
{
	TEST_ASSERT_TRUE(ft_isspace('\t'));
	TEST_ASSERT_TRUE(ft_isspace('\r'));
	TEST_ASSERT_TRUE(ft_isspace(' '));
}

void	test_ft_isspace_alphanum(void)
{
	TEST_ASSERT_FALSE(ft_isspace('a'));
	TEST_ASSERT_FALSE(ft_isspace('z'));
	TEST_ASSERT_FALSE(ft_isspace('A'));
	TEST_ASSERT_FALSE(ft_isspace('Z'));
}

void	test_ft_isspace_edge(void)
{
	TEST_ASSERT_FALSE(ft_isspace('\t' - 1));
	TEST_ASSERT_FALSE(ft_isspace('\r' + 1));
}
