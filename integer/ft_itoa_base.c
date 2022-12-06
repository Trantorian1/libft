/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:44:37 by emcnab            #+#    #+#             */
/*   Updated: 2022/12/06 19:43:56 by emcnab           ###   ########.fr       */
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
static long	ft_validate_base(char *base)
{
	long	len;
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
 * @brief Normed implentation of ft_itoa_base.
 *
 * @param l (long): the number to convert to a new [base].
 * @param l_abs (long): absolute value of [l]. If l == LONG_MIN, l_abs will be
 *        truncated to LONG_MIN + 1 to still write the first digits of
 *        LONG_MIN in [base], while the last digit will be manually truncated.
 *        This allows ft_itoa_base to function on different c architectures
 *        rather than relying on a hardcoded LONG_MIN string.
 * @param base_len (long): number of characters in [base]
 * @param base (char *): the base to convert [l] to.
 *
 * @return (char *): representation of the number [l] a new ASCII [base].
 *
 * @author Eliot McNab
 * @date 12/06/2022
 */
static char	*ft_to_base(long l, long l_abs, long base_len, char *base)
{
	size_t	str_len;
	char	*str_base;

	str_len = ft_baselen(l_abs, base_len) + (l < 0);
	str_base = ft_stralloc(str_len);
	if (!str_base)
		return (NULL);
	if (l == LONG_MIN)
	{
		str_base[--str_len] = base[-(l % base_len)];
		l_abs /= base_len;
	}
	str_base[0] = '-';
	while (l_abs >= base_len)
	{
		str_base[--str_len] = base[l_abs % base_len];
		l_abs /= base_len;
	}
	str_base[l < 0] = base[l_abs % base_len];
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
char	*ft_itoa_base(long l, char *base)
{
	long	base_len;
	long	l_abs;

	base_len = ft_validate_base(base);
	if (!base_len)
		return (NULL);
	l_abs = ft_abslong(l * (l != LONG_MIN) + (LONG_MIN + 1) * (l == LONG_MIN));
	return (ft_to_base(l, l_abs, base_len, base));
}
