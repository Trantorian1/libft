/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:47:43 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/09 15:58:36 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/str.h"

/*
 * @brief Determines the number of splits needed to split [to_split] at every
 * 	[splitter] character.
 *
 * @param to_split (t_str): the string to split.
 * @param splitter (char): the character to split [to_split] at.
 *
 * @return (size_t): the number of splits necessary to split [to_split].
 */
static size_t	ft_split_size(t_str to_split, char splitter)
{
	size_t	split_size;

	split_size = 0;
	while (*to_split)
	{
		if (*to_split++ != splitter)
		{
			split_size++;
			while (*to_split && *to_split != splitter)
				to_split++;
		}
	}
	return (split_size);
}

/*
 * @brief Frees up all memory allocated by ft_split if an allocation fails
 * 	midway along the split.
 *
 * @param split_start (char **): pointer to the start of the split.
 * @param split_current (char **): pointer to the last element to have been
 * 	allocated.
 *
 * @return (void *): NULL.
 */
static void	*ft_split_free(char **split_start, char **split_current)
{
	char	**split_cpy;

	split_cpy = split_start;
	while (split_start < split_current)
		free(*split_start++);
	free(split_cpy);
	return (NULL);
}

/*
 * @brief Creates a copy of all non-split charcters from the charcter pointed
 * 	to by [to_split] and increments [to_split] to the next charcter matching
 * 	[splitter].
 *
 * @param to_split (t_str *): pointer to the first charcter to copy. Will be
 * 	updated inside the function to point to the next splitter charcter or the
 * 	end of the string to split.
 * @param splitter (char): the character to split [to_split] at.
 *
 * @return (char *): A copy of all non_split character from the character
 * 	pointed to by [to_split].
 */
static char	*ft_split_copy(t_str *to_split, char splitter)
{
	t_str	to_split_cpy;

	to_split_cpy = *to_split;
	while (**to_split && **to_split != splitter)
		(*to_split)++;
	return (ft_substr(to_split_cpy, 0, (size_t)(*to_split - to_split_cpy)));
}

/*
 * @brief Splits a string [to_split] into multiple non-empty substrings at every
 * 	[splitter] charcter. Resulting arrray of strings will allways have NULL as
 * 	its last element for end-detection.
 *
 * @param to_split (t_str): the string to split.
 * @param splitter (char): the character to split [to_split] at.
 *
 * @return (char **): Array of split strings, terminated by NULL to indicate the
 * 	end of the array.
 */
char	**ft_split(t_str to_split, char splitter)
{
	size_t	split_size;
	char	**split;
	char	**split_cpy;

	if (to_split == NULL)
		to_split = "";
	split_size = ft_split_size(to_split, splitter);
	split = malloc((split_size + 1) * sizeof(*split));
	split_cpy = split;
	if (!split)
		return (NULL);
	*(split + split_size) = NULL;
	while (split_size--)
	{
		while (*to_split && *to_split == splitter)
			to_split++;
		if (*to_split && *to_split != splitter)
		{
			*split = ft_split_copy(&to_split, splitter);
			if (!split++)
				return (ft_split_free(split_cpy, split));
		}
	}
	return (split_cpy);
}

/*
 * @brief Determines the number of splits needed to split [to_split] at every
 * 	[splitter] character.
 *
 * @param to_split (t_str): the string to split.
 * @param splitter (char): the character to split [to_split] at.
 *
 * @return (size_t): the number of splits necessary to split [to_split].
 */
/* static size_t	ft_split_size(t_str to_split, char splitter)
{
	size_t	split_size = 0;
	size_t	i          = 0;

	if (!to_split)
		return (0);
	while (to_split[i])
	{
		if (to_split[i++] != splitter)
		{
			split_size++;
			while (to_split[i] && to_split[i] != splitter)
				i++;
		}
	}
	return (split_size);
} */

/*
 * @brief Frees up all memory allocated for the split.
 *
 * @param split (char**): the split string.
 * @param allocated (size_t): the number of splits so far.
 *
 * @return (void *): NULL.
 */
/* static void	*ft_split_free(char **split, size_t allocated)
{
	size_t	i = 0;

	if (allocated)
		while (i < allocated)
			free(split[i++]);
	free(split);
	return (NULL);
} */

/*
 * @brief Splits a string [to_split] into multiple non-empty substrings at every
 * 	[splitter] charcter. Resulting arrray of strings will allways have NULL as
 * 	its last element for end-detection.
 *
 * @param to_split (t_str): the string to split.
 * @param splitter (char): the character to split [to_split] at.
 *
 * @return (char **): Array of split strings, terminated by NULL to indicate the
 * 	end of the array.
 */
/* char	**ft_split(t_str to_split, char splitter)
{
	char	**split;
	size_t	split_size = ft_split_size(to_split, splitter);
	size_t	i          = 0;
	size_t	j          = 0;
	size_t	len        = 0;

	if (!to_split)
		return (NULL);
	if (!(split = malloc((split_size + 1) * sizeof(*split))))
		return (NULL);
	while (split_size--)
	{
		while (to_split[i] && to_split[i] == splitter)
			i++;
		while (to_split[i + len] && to_split[i + len] != splitter)
			len++;
		if (len && !(split[j++] = ft_substr(to_split, i, len)))
			return (ft_split_free(split, j));
		i += len > 0 ? len : 1;
		len = 0;
	}
	split[j] = NULL;
	return (split);
} */
