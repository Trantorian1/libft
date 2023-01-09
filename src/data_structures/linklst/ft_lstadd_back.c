/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:53:31 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/09 15:50:06 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/linklst.h"

/*
 * @brief Appends a new node at the end of a linked list.
 *
 * @param head (t_list **): the head of the linked list.
 * @param node_new (t_list *): the node to append to the linked list.
 */
void	ft_lst_add_back(t_list **head, t_list *node_new)
{
	t_list	*node_last;

	if (!head)
		return ;
	node_last = ft_lst_last(*head);
	if (node_last)
		node_last -> next = node_new;
	else
		*head = node_new;
}
