/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_to_i.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliot <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 14:26:50 by eliot             #+#    #+#             */
/*   Updated: 2023/03/17 17:20:04 by eliot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str_to_i.h"

#include "skip_space.h"
#include "str_get_sign.h"
#include "ft_isdigit.h"
#include "ft_todigit.h"
#include <asm-generic/errno-base.h>
#include <stdint.h>
#include <limits.h>
#include <stddef.h>
#include <errno.h>

static int	value_increment(const char *str, char **endptr)
{
	size_t	index;
	int		value_curr;
	int		value_delta;

	index = 0;
	value_curr = 0;
	while (ft_isdigit(str[index]))
	{
		value_delta = ft_todigit(str[index]);
		if (value_curr < (INT_MIN - value_delta) / 10)
		{
			*endptr = (char *)(&str[index]);
			errno = ERANGE;
			return (value_curr);
		}
		value_curr = value_curr * 10 + value_delta;
		index++;
	}
	*endptr = (char *)(&str[index]);
	if (**endptr != '\0')
		errno = EINVAL;
	return (value_curr);
}

static int	value_decrement(const char *str, char **endptr)
{
	size_t	index;
	int		value_curr;
	int		value_delta;

	index = 0;
	value_curr = 0;
	while (ft_isdigit(str[index]))
	{
		value_delta = ft_todigit(str[index]);
		if (value_curr < (INT_MIN + value_delta) / 10)
		{
			*endptr = (char *)(&str[index]);
			errno = ERANGE;
			return (value_curr);
		}
		value_curr = value_curr * 10 - value_delta;
		index++;
	}
	*endptr = (char *)(&str[index]);
	if (**endptr != '\0')
		errno = EINVAL;
	return (value_curr);
}

static int	get_value(const char *str, char **endptr, int8_t sign)
{
	if (sign == POSITIVE)
		return (value_increment(str, endptr));
	else
		return (value_decrement(str, endptr));
}

/**
 * @brief Convert a string to an integer, taking overflows into account.
 *
 * This function converts a string pointed to by @p str to an integer value. It
 * handles optional leading whitespace, an optional sign (+ or -), and a 
 * sequence of digits. The conversion stops when the first unrecognized 
 * character is encountered.
 *
 * Upon successful conversion, the function stores the address of the first
 * unrecognized character in the object pointed to by @p endptr.
 *
 * The function sets errno to the appropriate error codes under the following
 * circumstances:
 * - EINVAL: The input string does not represent a valid number, or the input
 *           pointers are NULL.
 * - ERANGE: The converted value is too large or too small to be represented as
 *           an integer.
 *
 * @param str      A pointer to the null-terminated string to be converted.
 * @param endptr   A pointer to a char pointer that will be updated to point to
 *                 the first unrecognized character.
 * @return The converted integer value, or 0 in case of an error.
 */
int	ft_str_to_i(const char *_Nonnull str, char *_Nonnull *_Nullable endptr)
{
	int8_t	sign;
	int		value;

	if (str == NULL || endptr == NULL)
	{
		errno = EINVAL;
		return (0);
	}
	*endptr = (char *)skip_space(str);
	sign = str_get_sign(*endptr, endptr);
	if (sign == 0)
	{
		errno = EINVAL;
		return (0);
	}
	value = get_value(*endptr, endptr, sign);
	return (value);
}
