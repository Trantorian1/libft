/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkstr.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:39:54 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/09 16:36:03 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINKSTR_H
# define LINKSTR_H

# include "str.h"
# include "linklst.h"

typedef struct s_linkstr
{
	t_list	*strs_first;
	t_list	*strs_last;
	size_t	linksize;
	size_t	i;
}	t_linkstr;

t_linkstr	*ft_linkstr_new(size_t linksize);
void	ft_linkstr_add(t_linkstr *linkstr, char *str);
size_t	ft_linkstr_size(t_linkstr *linkstr);
char	*ft_linkstr_collect(t_linkstr *linkstr);
void	*ft_linkstr_delall(t_linkstr *linkstr, void (*f_free)(void *));

#endif
