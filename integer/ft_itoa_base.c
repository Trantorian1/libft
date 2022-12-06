/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:44:37 by emcnab            #+#    #+#             */
/*   Updated: 2022/12/06 17:42:53 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

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
static ssize_t	ft_validate_base(char *base)
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

/**
 * @brief Converts a long integer to a new ASCII [base].
 *
 * Base must be valid for the conversion to take place. See
 * ft_validate_base(char *).
 *
 * @param base (char *): the base to convert [l] to.
 * @param l (long): the number to convert to a new [base].
 *
 * @return (char *): representation of the number [l] a new ASCII [base].
 *
 * @author Eliot McNab
 * @date 12/06/2022
 */
char	*ft_itoa_base(long l, char *base)
{
	size_t	base_len;
	long	l_abs;
	size_t	l_len;
	char	*str;

	base_len = ft_validate_base(base);
	if (!base_len)
		return (NULL);
	l_abs = ft_abslong(l * (l != LONG_MIN) + (LONG_MIN + 1) * (l == LONG_MIN));
	l_len = ft_longlen(l_abs) + (l < 0);
	str = ft_stralloc(l_len);
	if (!str)
		return (NULL);
	if (l == LONG_MIN)
	{
		str[--l_len] = base[-(l % base_len)];
		l_abs /= base_len;
	}
	str[0] = '-';
	while ((size_t) l_abs >= base_len)
	{
		str[--l_len] = base[l_abs % base_len];
		l_abs /= base_len;
	}
	str[l < 0] = base[l_abs % base_len];
	return (str);
}
