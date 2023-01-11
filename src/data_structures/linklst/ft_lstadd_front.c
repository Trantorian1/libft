/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:19:45 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/11 10:38:15 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/linklst.h"

/*
 * @brief Prepends a new node at the front of a linked list.
 *
 * @param list (t_s_list **): pointer to the head of the linked list.
 * @param node (t_s_list *): the node to preprend to [list].
 */
void	ft_lst_add_front(t_s_list **list, t_s_list *node)
{
	if (!list)
		return ;
	if (node)
		node -> next = *list;
	*list = node;
}
