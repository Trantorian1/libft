/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:14:27 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/11 10:38:16 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/linklst.h"

/*
 * @brief Creates a new linked list.
 *
 * @param content (t_any): the data initially containted in the linked list.
 *
 * @return (t_s_list): the head of the new linked list.
 */
t_s_list	*ft_lst_new(t_any content)
{
	t_s_list	*head;

	head = malloc(sizeof(*head));
	if (!head)
		return (NULL);
	head -> content = content;
	head -> next = NULL;
	return (head);
}
