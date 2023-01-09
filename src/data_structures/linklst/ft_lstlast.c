/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:45:14 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/09 15:50:06 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/linklst.h"

/*
 * @brief Gets the last element in a linked list.
 *
 * @param head (t_list *): the start of the linked list.
 * @param (t_list *): the last element of the linked list.
 */
t_list	*ft_lst_last(t_list *head)
{
	t_list	*node;

	node = head;
	if (!head)
		return (head);
	while (node -> next)
		node = node -> next;
	return (node);
}
