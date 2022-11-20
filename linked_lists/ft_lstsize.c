/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:33:08 by emcnab            #+#    #+#             */
/*   Updated: 2022/11/20 18:03:11 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
 * @brief Determines the size of a linked lists.
 *
 * @param head (t_list *): the head of the linked list.
 *
 * @return (int): the size of the linked list.
 */
int	ft_lstsize(t_list *head)
{
	t_list	*node = head;
	size_t	size  = 1;

	if (!node)
		return (0);
	while ((node = node -> next))
		size++;
	return (size);
}
