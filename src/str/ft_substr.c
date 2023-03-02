/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 09:57:45 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/02 16:33:39 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_substr.h"

#include "ft_malloc.h"
#include <stddef.h>

/*
 * @brief Goes to the start of the substr at index [start_index] in [str].
 *
 * @param str (t_str *): pointer to the original string, so that it can be
 * 	incemented to point to the start of the substring.
 * @param start_index (size_t): index at which the substring starts.
 *
 * @return (t_str): pointer to the start of the substring in [str] or the end of
 * 	[str] if [start_index] > strlen([str]).
 */
static const char	*ft_substr_start(const char **str, size_t start_index)
{
	const char	*str_cpy;

	str_cpy = *str;
	while (**str && *str < str_cpy + start_index)
		(*str)++;
	return (*str);
}

/*
 * @brief Determines the length of a substring in a string pointing to the start
 * 	of the substring.
 *
 * @param str (t_str): pointer to the start of the substring.
 * @param max_size (size_t): maximum possible size of the substring.
 *
 * @return (size_t): size of the substring from [str]. Will be less than
 * 	[max_size] if [max_size] > strlen([str]).
 */
static size_t	ft_substrlen(const char *str, size_t max_size)
{
	const char	*str_cpy;

	str_cpy = str;
	while (*str && str < str_cpy + max_size)
		str++;
	return ((size_t)(str - str_cpy));
}

char	*ft_substr(const char *str, size_t start_index, size_t max_size)
{
	char		*substr;
	char		*substr_cpy;
	const char	*str_cpy;

	if (!str)
		return (NULL);
	str_cpy = ft_substr_start(&str, start_index);
	substr = ft_malloc((ft_substrlen(str_cpy, max_size) + 1) * sizeof(*substr));
	substr_cpy = substr;
	if (!substr)
		return (NULL);
	while (*str && str < str_cpy + max_size)
		*substr++ = *str++;
	*substr = '\0';
	return (substr_cpy);
}
