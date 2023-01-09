/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_lists.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:35:00 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/09 15:38:55 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINKED_LISTS_H
# define LINKED_LISTS_H

# include <stdlib.h>
# include "typedefs.h"

typedef struct s_list
{
	t_any			content;
	struct s_list	*next;
}	t_list;

t_list	*ft_lst_new(t_any content);
t_list	*ft_lst_last(t_list *head);
t_list	*ft_lst_map(t_list *head, t_any (*f_map)(t_any), void (*f_free)(t_any));
int		ft_lst_size(t_list *head);
void	ft_lst_add_front(t_list **list, t_list *node);
void	ft_lst_iter(t_list *head, void (*f)(t_any));
void	ft_lstadd_back(t_list **head, t_list *node_new);
void	ft_lst_delone(t_list *node, void (*f)(t_any));
void	ft_lst_clear(t_list **head, void (*f)(t_any));

#endif
