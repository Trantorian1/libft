/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:45:14 by emcnab            #+#    #+#             */
/*   Updated: 2022/11/20 15:32:00 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * @brief Gets the last element in a linked list.
 *
 * @param head (t_list *): the start of the linked list.
 * @param (t_list *): the last element of the linked list.
 */
t_list	*ft_lstlast(t_list *head)
{
	t_list	*node = head;

	if (!head)
		return (head);
	while (node -> next)
		node = node -> next;
	return (node);
}
