/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_clear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 15:10:27 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/02 16:24:40 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lst_clear.h"

#include <stdlib.h>
#include "ft_lst_delone.h"

/*
 * @brief Frees up memory taken up by all elements in a linked list and sets 
 * 	the [head] to NULL.
 *
 * @param head (t_s_list **): the start of the linked list.
 * @param f_free_content (void(t_any)): function used to free the content of 
 * 	individual nodes in the linked list pointed to by [head].
 */
void	ft_lst_clear(t_s_list **head, void (*f_free_content)(void *))
{
	t_s_list	*node_current;
	t_s_list	*node_previous;

	if (!head || !*head || !f_free_content)
		return ;
	node_current = *head;
	while (node_current)
	{
		node_previous = node_current;
		node_current = node_current -> next;
		ft_lst_delone(node_previous, f_free_content);
	}
	*head = NULL;
}
