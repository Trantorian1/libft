/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_linkstr_collect.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:21:01 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/09 16:35:36 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/linkstr.h"

/*
 * @brief Concatenates all strings held in a linked string into a single string.
 *
 * @param linkstr (t_linkstr *): the linked string containing the strings.
 *
 * @return (char *): result of concatenating all the strings in [linkstr].
 */
char	*ft_linkstr_collect(t_linkstr *linkstr)
{
	char	*collect;
	t_list	*cur;
	size_t	i;
	size_t	j;
	size_t	k;

	if (!linkstr)
		return (NULL);
	collect = malloc((ft_linkstr_size(linkstr) + 1) * sizeof(*collect));
	cur = linkstr->strs_first;
	i = 0;
	j = 0;
	while (i < linkstr->i)
	{
		if (i && i % linkstr->linksize == 0)
			cur = cur->next;
		k = 0;
		while (((char **)cur->content)[i % linkstr->linksize][k])
			collect[j++] = ((char **)cur->content)[i % linkstr->linksize][k++];
		i++;
	}
	collect[j] = '\0';
	return (collect);
}
