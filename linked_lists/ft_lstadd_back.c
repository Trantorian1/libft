/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:53:31 by emcnab            #+#    #+#             */
/*   Updated: 2022/11/20 18:06:10 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
 * @brief Appends a new node at the end of a linked list.
 *
 * @param head (t_list **): the head of the linked list.
 * @param node_new (t_list *): the node to append to the linked list.
 */
void	ft_lstadd_back(t_list **head, t_list *node_new)
{
	t_list	*node_last;

	if (!head)
		return ;
	node_last = ft_lstlast(*head);
	if (node_last)
		node_last -> next = node_new;
	else
		*head = node_new;
}
