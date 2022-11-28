/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:14:27 by emcnab            #+#    #+#             */
/*   Updated: 2022/11/28 16:14:17 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

/*
 * @brief Creates a new linked list.
 *
 * @param content (t_any): the data initially containted in the linked list.
 *
 * @return (t_list): the head of the new linked list.
 */
t_list	*ft_lst_new(t_any content)
{
	t_list	*head;

	if (!(head = malloc(sizeof(*head))))
		return (NULL);
	head -> content = content;
	head -> next = NULL;
	return (head);
}
