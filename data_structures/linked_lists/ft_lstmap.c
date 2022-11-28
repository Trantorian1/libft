/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 15:17:40 by emcnab            #+#    #+#             */
/*   Updated: 2022/11/28 16:16:19 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

/*
 * @brief Maps the contents of a linked list to a new linked list.
 *
 * @param head (t_list *): pointer to the start of the linked list to map.
 * @param f_map (t_any(t_any)): mapping function.
 * @param f_free (void(t_any)): function used to free the content of individual
 * 	nodes in the linked list pointed to by [head].
 *
 * @return (t_list *): linked list mapping of [head] or NULL if allocation
 * 	fails.
 */
t_list	*ft_lst_map(t_list *head, t_any (*f_map)(t_any), void (*f_free)(t_any))
{
	t_list	*map;
	t_list	*map_start;

	if (!head || !f_map || !f_free)
		return (NULL);
	map = ft_lst_new(f_map(head -> content));
	map_start = map;
	if (!map)
	{
		ft_lst_clear(&map_start, f_free);
		return (NULL);
	}
	head = head -> next;
	while (head)
	{
		map -> next = ft_lst_new(f_map(head -> content));
		map = map -> next;
		if (!map)
		{
			ft_lst_clear(&map_start, f_free);
			return (NULL);
		}
		head = head -> next;
	}
	return (map_start);
}
