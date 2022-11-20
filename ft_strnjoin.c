/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 14:17:02 by emcnab            #+#    #+#             */
/*   Updated: 2022/11/20 16:44:39 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * @brief Collects all varargs into an array of strings.
 *
 * @param argc (size_t): the number of string to collect.
 * @param varargs (va_list): string varargs to pack together.
 *
 * @return (t_str *): array of strings collect from [varargs].
 */
static t_str	*ft_pack_arg(size_t argc, va_list varargs)
{
	t_str	*packed;
	size_t	i;

	packed = malloc(argc * sizeof(*packed));
	if (!packed)
	{
		return (NULL);
	}
	i = 0;
	while (i < argc)
	{
		packed[i] = __builtin_va_arg(varargs, t_str);
		i++;
	}	
	return (packed);
}

/*
 * @brief Calculates the cumulative length of every string in an array of
 * 	strings.
 *
 * @param n (size_t): the number of strings in the array.
 * @param strs (t_str *): the array of strings.
 *
 * @return (size_t): summed length of every string in [strs].
 */
static size_t	ft_strlen_array(size_t n, t_str *strs)
{
	size_t	i;
	size_t	len_tot;

	i = 0;
	len_tot = 0;
	while (i < n)
	{
		len_tot += ft_strlen(strs[i]);
		i++;
	}
	return (len_tot);
}

/*
 * @brief Pastes the contents of every string in an array into a single string
 * 	while there is still enough space left.
 *
 * @param n (size_t): the number of characters in [dest].
 * @param dest (char *): null-terminated destination string to paste the 
 * 	contents of [src] into.
 * @param src (t_str *): the array of strings to paste.
 */
static void	ft_strpaste_array(size_t n, char *dest, t_str *src)
{
	size_t	i = 0;
	size_t	j = 0;
	size_t	k = 0;

	while (i < n)
	{
		k = 0;
		while (src[j][k])
		{
			dest[i] = src[j][k];
			i++;
			k++;
		}
		j++;
	}
}

/*
 * @brief Joins a variable number of strings into a single string.
 *
 * @param argc (size_t): number of strings to join.
 * @param ... (t_str)
 *
 * @return (t_str): all strings in [...] joined into a single string.
 */
char	*ft_strnjoin(size_t argc, ...)
{
	va_list	varargs;
	t_str	*argv;
	size_t	strlen_array;
	char	*joined;

	__builtin_va_start(varargs, argc);
	argv = ft_pack_arg(argc, varargs);
	__builtin_va_end(varargs);
	if (!argv)
	{
		return (NULL);
	}
	strlen_array = ft_strlen_array(argc, argv);
	joined = ft_stralloc(strlen_array);
	if (!joined)
	{
		return (NULL);
	}
	ft_strpaste_array(strlen_array, joined, argv);
	free(argv);
	return (joined);
}
