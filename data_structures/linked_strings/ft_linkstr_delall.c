/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_linkstr_delall.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:21:53 by emcnab            #+#    #+#             */
/*   Updated: 2022/11/28 16:22:04 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

/*
 * @brief Deletes all the contents of a linked string and frees up all memory
 * 	allocated to it.
 *
 * @param linkstr (t_linkstr *): the linked string to delete.
 * @param f_free (void (void *)): function used to free the strings in
 * 	[linkstr]. Pass NULL if the strings in [linkstr] don't need to be freed.
 *
 * @return (void *): NULL.
 */
void	*ft_linkstr_delall(t_linkstr *linkstr, void (*f_free)(void *))
{
	t_list	*node_current;
	t_list	*node_previous;
	size_t	i;

	if (!linkstr)
		return (NULL);
	node_current = linkstr->strs_first;
	i = 0;
	while (i < linkstr->i)
	{
		if (i && i % linkstr->linksize == 0)
		{
			node_previous = node_current;
			node_current = node_current->next;
			ft_lst_delone(node_previous, &free);
		}
		if (f_free)
			f_free(((char **)node_current->content)[i % linkstr->linksize]);
		i++;
	}
	ft_lst_delone(node_current, &free);
	linkstr->strs_first = NULL;
	free(linkstr);
	return (NULL);
}
