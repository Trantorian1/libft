/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:28:05 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/11 10:38:15 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/linklst.h"

/*
 * @brief Applies a function [f] to every node in a linked list.
 *
 * @param head (t_s_list *): the head of the linked list to iterate over.
 * @param f (void(t_any)): the function to apply to every node in the linked
 * 	list beggining with [head].
 */
void	ft_lst_iter(t_s_list *head, void (*f_iter)(t_any))
{
	t_s_list	*node_current;

	node_current = head;
	if (!head || !f_iter)
		return ;
	while (node_current)
	{
		f_iter(node_current -> content);
		node_current = node_current -> next;
	}
}
