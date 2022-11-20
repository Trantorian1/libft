/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:19:45 by emcnab            #+#    #+#             */
/*   Updated: 2022/11/18 14:55:39 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * @brief Prepends a new node at the front of a linked list.
 *
 * @param list (t_list **): pointer to the head of the linked list.
 * @param node (t_list *): the node to preprend to [list].
 */
void	ft_lstadd_front(t_list **list, t_list *node)
{
	if (!list)
		return ;
	if (node)
		node -> next = *list;
	*list = node;
}
