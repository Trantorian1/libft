/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_todigit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 13:56:29 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/13 14:00:40 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unity.h"
#include "ft_todigit.h"

void	test_ft_todigit_digit(void)
{
	TEST_ASSERT_EQUAL_INT(ft_todigit('0'), 0);
	TEST_ASSERT_EQUAL_INT(ft_todigit('9'), 9);
}

void	test_ft_todigit_edge(void)
{
	TEST_ASSERT_EQUAL_INT(ft_todigit('0' - 1), -1);
	TEST_ASSERT_EQUAL_INT(ft_todigit('9' + 1), 10);
}
