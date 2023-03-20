/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_to_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:31:17 by eliot             #+#    #+#             */
/*   Updated: 2023/03/20 11:36:22 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str_to_d.h"

#include "skip_space.h"
#include "str_get_sign.h"
#include "ft_str_to_i.h"
#include "ft_todigit.h"
#include "ft_isdigit.h"
#include <float.h>
#include <errno.h>
#include <stddef.h>
#include <stdint.h>
#include <math.h>

static double	get_fractional(const char *str, char **endptr)
{
	size_t	index;
	int64_t	value_curr;
	int64_t	value_delta;
	double	value_final;

	if (*str == '.')
		index = 1;
	else
		return (0);
	value_curr = 0;
	while (ft_isdigit(str[index]))
	{
		value_delta = ft_todigit(str[index]);
		if ((double)value_curr > (DBL_MAX - (double)value_delta) / 10.0)
		{
			*endptr = (char *)(&str[index]);
			errno = ERANGE;
			return ((double)value_curr / pow(10.0, (double)(index - 1)));
		}
		value_curr = value_curr * 10 + value_delta;
		index ++;
	}
	*endptr = (char *)(&str[index]);
	value_final = (double)value_curr / pow(10.0, (double)(index - 1));
	return (value_final);
}

static double	get_exponent(const char *str, char **endptr)
{
	int		exponent;

	if (*str != 'e' && *str != 'E')
		return (1);
	exponent = ft_str_to_i(&str[1], endptr);
	return (pow(10, (double)exponent));
}

static double	value_increment(const char *str, char **endptr)
{
	size_t	index;
	int64_t	value_curr;
	int64_t	value_delta;
	double	value_final;

	index = 0;
	value_curr = 0;
	while (ft_isdigit(str[index]))
	{
		value_delta = ft_todigit(str[index]);
		if ((double)value_curr > (DBL_MAX - (double)value_delta) / 10.0)
		{
			*endptr = (char *)(&str[index]);
			errno = ERANGE;
			return ((double)value_curr);
		}
		value_curr = value_curr * 10 + value_delta;
		index++;
	}
	*endptr = (char *)(&str[index]);
	value_final = (double)value_curr + get_fractional(*endptr, endptr);
	value_final *= get_exponent(*endptr, endptr);
	if (**endptr != '\0')
		errno = EINVAL;
	return (value_final);
}

static double	value_decrement(const char *str, char **endptr)
{
	size_t	index;
	int64_t	value_curr;
	int64_t	value_delta;
	double	value_final;

	index = (size_t)(-1);
	value_curr = 0;
	while (ft_isdigit(str[++index]))
	{
		value_delta = ft_todigit(str[index]);
		if ((double)value_curr > (DBL_MIN + (double)value_delta) / 10.0)
		{
			*endptr = (char *)(&str[index]);
			errno = ERANGE;
			return ((double)value_curr);
		}
		value_curr = value_curr * 10 - value_delta;
	}
	*endptr = (char *)(&str[index]);
	value_final = (double)(value_curr - 1);
	value_final += (1.0 - get_fractional(*endptr, endptr));
	value_final *= get_exponent(*endptr, endptr);
	if (**endptr != '\0')
		errno = EINVAL;
	return (value_final);
}

/**
 * @brief Convert a string to a double, taking overflows and exponential
 *        notation into account.
 *
 * This function converts a string pointed to by @p str to a double value. It
 * handles optional leading whitespace, an optional sign (+ or -), a sequence of
 * digits, an optional decimal point followed by another sequence of digits, and
 * an optional exponent part (e or E followed by an optional sign and a sequence
 * of digits). The conversion stops when the first unrecognized character is
 * encountered.
 *
 * Upon successful conversion, the function stores the address of the first
 * unrecognized character in the object pointed to by @p endptr.
 *
 * The function sets errno to the appropriate error codes under the following
 * circumstances:
 * - EINVAL: The input string does not represent a valid number, or the input
 *           pointers are NULL.
 * - ERANGE: The converted value is too large or too small to be represented as
 *           a double.
 *
 * @param str      A pointer to the null-terminated string to be converted.
 * @param endptr   A pointer to a char pointer that will be updated to point to
 *                 the first unrecognized character.
 * @return The converted double value, or 0 in case of an error.
 */
double	ft_str_to_d(const char *str, char **endptr)
{
	int8_t	sign;

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
	if (sign == POSITIVE)
		return (value_increment(*endptr, endptr));
	else
		return (value_decrement(*endptr, endptr));
}
