/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_iter.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 19:43:02 by                   #+#    #+#             */
/*   Updated: 2023/01/12 19:43:02 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LST_ITER_H
# define FT_LST_ITER_H

# include "s_list.h"

void	ft_lst_iter(t_s_list *head, void (*f_iter)(void *));

#endif
