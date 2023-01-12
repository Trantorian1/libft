/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_iter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:28:05 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/12 17:37:07 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lst_iter.h"

void	ft_lst_iter(t_s_list *head, void (*f_iter)(void *))
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
