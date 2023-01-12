/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:33:08 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/12 17:38:05 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lst_size.h"

#include <stddef.h>

/*
 * @brief Determines the size of a linked lists.
 *
 * @param head (t_s_list *): the head of the linked list.
 *
 * @return (int): the size of the linked list.
 */
size_t	ft_lst_size(t_s_list *head)
{
	t_s_list	*node;
	size_t		size;

	node = head;
	size = 1;
	if (!node)
		return (0);
	while (node -> next)
	{
		node = node -> next;
		size++;
	}
	return (size);
}
