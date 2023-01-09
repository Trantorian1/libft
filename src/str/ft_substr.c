/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 09:57:45 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/09 15:58:37 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/str.h"

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
static t_str	ft_substr_start(t_str *str, size_t start_index)
{
	t_str	str_cpy;

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
static size_t	ft_substrlen(t_str str, size_t max_size)
{
	t_str	str_cpy;

	str_cpy = str;
	while (*str && str < str_cpy + max_size)
		str++;
	return (str - str_cpy);
}

/*
 * @brief Creates a copy of a string from index start_index and of max size
 * max_size. If max_size is greater than strlen(string), copy will stop at the
 * end of string. Resulting copy will always be null-teminated.
 *
 * @param string (t_str): the string from which to get the substring
 * @param start_index (unsigned int): index from which to start copying
 * 	the substring.
 * * @param max_size (size_t): amount of characters to copy from the string.
 *
 * @return (char *): substring in [str] from index [start_index] to 
 * 	[start_index + max_size].
 */
char	*ft_substr(t_str str, t_uint start_index, size_t max_size)
{
	char	*substr;
	char	*substr_cpy;
	t_str	str_cpy;

	if (!str)
		return (NULL);
	str_cpy = ft_substr_start(&str, start_index);
	substr = malloc((ft_substrlen(str_cpy, max_size) + 1) * sizeof(*substr));
	substr_cpy = substr;
	if (!substr)
		return (NULL);
	while (*str && str < str_cpy + max_size)
		*substr++ = *str++;
	*substr = '\0';
	return (substr_cpy);
}
