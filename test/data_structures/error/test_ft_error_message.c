/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_error_message.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 15:19:10 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/28 14:34:16 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unity.h"
#include "ft_error_message.h"
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
