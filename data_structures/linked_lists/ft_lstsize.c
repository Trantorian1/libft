/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:33:08 by emcnab            #+#    #+#             */
/*   Updated: 2022/11/29 14:31:17 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

/*
 * @brief Determines the size of a linked lists.
 *
 * @param head (t_list *): the head of the linked list.
 *
 * @return (int): the size of the linked list.
 */
int	ft_lst_size(t_list *head)
{
	t_list	*node;
	size_t	size;

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
