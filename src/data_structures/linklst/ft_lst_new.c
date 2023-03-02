/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:14:27 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/02 16:26:23 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lst_new.h"

#include "ft_malloc.h"

/*
 * @brief Creates a new linked list.
 *
 * @param content (t_any): the data initially containted in the linked list.
 *
 * @return (t_s_list): the head of the new linked list.
 */
t_s_list	*ft_lst_new(void *content)
{
	t_s_list	*head;

	head = ft_malloc(sizeof(*head));
	head -> content = content;
	head -> next = NULL;
	return (head);
}
