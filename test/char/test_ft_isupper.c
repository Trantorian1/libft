/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isupper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 13:54:32 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/13 13:56:22 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unity.h"
#include "ft_isupper.h"

void	test_ft_isupper_upper(void)
{
	TEST_ASSERT_TRUE(ft_isupper('A'));
	TEST_ASSERT_TRUE(ft_isupper('Z'));
}

void	test_ft_isupper_lower(void)
{
	TEST_ASSERT_FALSE(ft_isupper('a'));
	TEST_ASSERT_FALSE(ft_isupper('z'));
}

void	test_ft_isupper_edge(void)
{
	TEST_ASSERT_FALSE(ft_isupper('A' - 1));
	TEST_ASSERT_FALSE(ft_isupper('Z' + 1));
}
