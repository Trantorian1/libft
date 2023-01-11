/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_linkstr_new.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:13:13 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/11 10:28:37 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/linkstr.h"

/*
 * @brief Creates a new linked string instance.
 * 
 * Linked strings are designed to avoid the overhead of resizing strings
 * by storing consecutive strings in arrays in linkedlists. Strings are then
 * concatenated all at once when the ft_s_linkstr_collect(1) function is called,
 * avoiding multiple resizes.
 *
 * @param linksize (size_t): the number of strings each linkedlist node will
 * 	hold.
 *
 * @return (t_s_linkstr *): new linked string.
 */
t_s_linkstr	*ft_linkstr_new(size_t linksize)
{
	t_s_linkstr	*linkstr;

	linkstr = malloc(sizeof(*linkstr));
	if (!linkstr || !linksize)
		return (NULL);
	linkstr->strs_first = ft_lst_new(malloc(linksize * sizeof(char *)));
	if (!linkstr->strs_first)
	{
		free(linkstr);
		return (NULL);
	}
	linkstr->strs_last = linkstr->strs_first;
	linkstr->linksize = linksize;
	linkstr->i = 0;
	return (linkstr);
}
