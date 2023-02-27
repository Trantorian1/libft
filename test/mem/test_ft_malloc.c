/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_malloc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 14:34:26 by emcnab            #+#    #+#             */
/*   Updated: 2023/02/27 15:58:47 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unity.h"
#include "ft_malloc.h"

#define SIZE 10

void	test_ft_single_malloc_free(void)
{
	int		*line;
	size_t	i;

	line = ft_malloc(SIZE * sizeof(*line));
	TEST_ASSERT_NOT_NULL(line);
	i = (size_t)(-1);
	while (++i < SIZE)
		line[i] = (int)i;
	ft_free(line);
}

void	test_multiple_malloc_free(void)
{
	int	*a;
	int	*b;
	int	*c;

	a = ft_malloc(sizeof(*a));
	b = ft_malloc(sizeof(*b));
	c = ft_malloc(sizeof(*c));
	TEST_ASSERT_NOT_NULL(a);
	TEST_ASSERT_NOT_NULL(b);
	TEST_ASSERT_NOT_NULL(c);
	a[0] = 1;
	b[0] = 1;
	c[0] = 1;
	ft_free(a);
	ft_free(b);
	ft_free(c);
}

void	test_multiple_malloc_free_all(void)
{
	int		**board;
	int		*line;
	size_t	i;
	size_t	j;

	board = ft_malloc(SIZE * sizeof(*board));
	i = (size_t)(-1);
	while (++i < SIZE)
	{
		board[i] = ft_malloc(SIZE * sizeof(*board[i]));
		line = board[i];
		j = (size_t)(-1);
		while (++j < SIZE)
			line[j] = (int)j;
	}
	ft_free_all();
}

void	test_realloc_bigger(void)
{
	int		*line;
	size_t	i;

	line = ft_malloc(SIZE * sizeof(*line));
	TEST_ASSERT_NOT_NULL(line);
	i = (size_t)(-1);
	while (++i < SIZE)
		line[i] = (int)i;
	line = ft_realloc(line, SIZE * 2 * sizeof(*line));
	TEST_ASSERT_NOT_NULL(line);
	i = (size_t)(SIZE - 1);
	while (++i < SIZE * 2)
		line[i] = (int)i;
	i = (size_t)(-1);
	while (++i < SIZE * 2)
		TEST_ASSERT_EQUAL_INT((int)i, line[i]);
	ft_free(line);
}

void	test_realloc_smaller(void)
{
	int		*line;
	size_t	i;

	line = ft_malloc(SIZE * sizeof(*line));
	TEST_ASSERT_NOT_NULL(line);
	i = (size_t)(-1);
	while (++i < SIZE)
		line[i] = (int)i;
	line = ft_realloc(line, SIZE / 2 * sizeof(*line));
	TEST_ASSERT_NOT_NULL(line);
	i = (size_t)(-1);
	while (++i < SIZE / 2)
		TEST_ASSERT_EQUAL_INT((int)i, line[i]);
	ft_free(line);
}

void	test_realloc_same(void)
{
	int		*line;
	size_t	i;

	line = ft_malloc(SIZE * sizeof(*line));
	TEST_ASSERT_NOT_NULL(line);
	i = (size_t)(-1);
	while (++i < SIZE)
		line[i] = (int)i;
	line = ft_realloc(line, SIZE * sizeof(*line));
	TEST_ASSERT_NOT_NULL(line);
	i = (size_t)(-1);
	while (++i < SIZE)
		TEST_ASSERT_EQUAL_INT((int)i, line[i]);
	ft_free(line);
}
