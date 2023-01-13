/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_toupper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 14:06:31 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/13 14:09:30 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unity.h"
#include "ft_toupper.h"

void	test_ft_toupper_lower(void)
{
	TEST_ASSERT_EQUAL_CHAR(ft_toupper('a'), 'A');
	TEST_ASSERT_EQUAL_CHAR(ft_toupper('z'), 'Z');
}

void	test_ft_toupper_upper(void)
{
	TEST_ASSERT_EQUAL_CHAR(ft_toupper('A'), 'A');
	TEST_ASSERT_EQUAL_CHAR(ft_toupper('Z'), 'Z');
}
