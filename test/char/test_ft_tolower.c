/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_tolower.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 14:04:12 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/13 14:06:11 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unity.h"
#include "ft_tolower.h"

void	test_ft_tolower_upper(void)
{
	TEST_ASSERT_EQUAL_CHAR(ft_tolower('A'), 'a');
	TEST_ASSERT_EQUAL_CHAR(ft_tolower('Z'), 'z');
}

void	test_ft_tolower_lower(void)
{
	TEST_ASSERT_EQUAL_CHAR(ft_tolower('a'), 'a');
	TEST_ASSERT_EQUAL_CHAR(ft_tolower('z'), 'z');
}
