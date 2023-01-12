/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 15:17:40 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/12 17:36:10 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lst_map.h"

#include <stdio.h>
#include "ft_lst_new.h"
#include "ft_lst_clear.h"

/*
 * @brief Maps the contents of a linked list to a new linked list.
 *
 * @param head (t_s_list *): pointer to the start of the linked list to map.
 * @param f_map (t_any(t_any)): mapping function.
 * @param f_free (void(t_any)): function used to free the content of individual
 * 	nodes in the linked list pointed to by [head].
 *
 * @return (t_s_list *): linked list mapping of [head] or NULL if allocation
 * 	fails.
 */
t_s_list	*ft_lst_map(t_s_list *head, void *(*f_map)(void *), void (*f_free)(void *))
{
	t_s_list	*map;
	t_s_list	*map_start;

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
