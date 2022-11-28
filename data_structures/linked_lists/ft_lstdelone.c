/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:58:56 by emcnab            #+#    #+#             */
/*   Updated: 2022/11/28 16:08:43 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

/*
 * @brief Frees up memory taken by a node in a linked list.
 *
 * @param node (t_list *): the node to free.
 * @param f_free (void(t_any)): function used to free the content of [node].
 */
void	ft_lstdelone(t_list *node, void (*f_free)(t_any))
{
	if (!node || !(node -> content) || !f_free)
		return ;
	f_free(node -> content);
	node -> next = NULL;
	free(node);
}
