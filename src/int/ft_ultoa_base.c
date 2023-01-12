/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 09:12:50 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/12 16:30:54 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ultoa_base.h"

#include <stddef.h>
#include <limits.h>
#include <stdbool.h>
#include "ft_bzero.h"
#include "ft_isprint.h"
#include "ft_baselen.h"
#include "ft_stralloc.h"

/**
 * @brief Checks the validity of a base string.
 *
 * A base string is valid if:
 * - it contains no duplicate characters
 * - its length is at least 2
 * - it contains only visible characters as defined byt ft_isprint(int)
 *
 * @param base (char *): the base string to check.
 *
 * @return (size_t): the length of the base, 0 if the base is invalid. If the
 * length of the base is less than 2, it will be truncated to 0.
 *
 * @author Eliot McNab
 * @date 12/06/2022
 */
static size_t	ft_validate_base(char *base)
{
	size_t	len;
	char	occurrences[CHAR_MAX];

	if (!base)
		return (false);
	ft_bzero(occurrences, CHAR_MAX);
	len = 0;
	while (base[len])
	{
		if (occurrences[(int)base[len]] || !ft_isprint(base[len]))
			return (0);
		occurrences[(int)base[len]] = 1;
		len++;
	}
	if (len < 2)
		len = 0;
	return (len);
}

static char	*ft_to_base(unsigned long l, size_t base_len, char *base)
{
	size_t	str_len;
	char	*str_base;

	str_len = ft_baselen(l, base_len);
	str_base = ft_stralloc(str_len);
	if (!str_base)
		return (NULL);
	while ((size_t)l >= base_len)
	{
		str_base[--str_len] = base[l % base_len];
		l /= base_len;
	}
	str_base[0] = base[l % base_len];
	return (str_base);
}

/**
 * @brief Converts a long integer to a new ASCII [base].
 *
 * Base must be valid for the conversion to take place. See
 * ft_validate_base(char *).
 *
 * @param l (long): the number to convert to a new [base].
 * @param base (char *): the base to convert [l] to.
 *
 * @return (char *): representation of the number [l] a new ASCII [base].
 *
 * @author Eliot McNab
 * @date 12/06/2022
 */
char	*ft_ultoa_base(unsigned long l, char *base)
{
	size_t	base_len;

	base_len = ft_validate_base(base);
	if (!base_len)
		return (NULL);
	return (ft_to_base(l, base_len, base));
}
