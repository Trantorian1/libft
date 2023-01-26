/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_error_handle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 15:53:16 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/26 16:57:26 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unity.h"
#include "ft_error_message.h"
#include "ft_error_handle.h"
#include "ft_array_get.h"
#include "e_error.h"
#include <stddef.h>

#define SIZE 5

static const char	*g_msg[SIZE] = {
	"Error: error no1",
	"Error: error no2",
	"Error: error no3",
	"Error: error no4",
	"Error: error no5"
};

void	test_ft_error_handle_none(void)
{
	TEST_ASSERT_FALSE(ft_error_occurred());
	TEST_ASSERT_FALSE(ft_error_catch(E_ERROR_SIZE));
}

void	test_ft_error_add(void)
{
	size_t	i;

	i = E_ERROR_SIZE - 1;
	printf("ERROR MSG ADD\n");
	while (++i < E_ERROR_SIZE + SIZE)
	{
		ft_error_add((int)i, g_msg[i - E_ERROR_SIZE]);
		printf("%d -> %s\n", (int)i, ft_error_msg((int)i));
		TEST_ASSERT_EQUAL_STRING(g_msg[i - E_ERROR_SIZE], ft_error_msg((int)i));
	}
}

void	test_ft_error_handle_error(void)
{
	ft_error_throw(E_ERROR_SIZE);
	TEST_ASSERT_TRUE(ft_error_occurred());
	TEST_ASSERT_TRUE(ft_error_catch(E_ERROR_SIZE));
	TEST_ASSERT_FALSE(ft_error_catch(E_ERROR_SIZE + 1));
}

void	test_ft_error_destroy(void)
{
	ft_error_destroy();
}
