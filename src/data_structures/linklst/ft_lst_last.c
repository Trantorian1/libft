/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_last.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:45:14 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/12 17:35:18 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lst_last.h"

t_s_list	*ft_lst_last(t_s_list *head)
{
	t_s_list	*node;

	node = head;
	if (!head)
		return (head);
	while (node -> next)
		node = node -> next;
	return (node);
}
