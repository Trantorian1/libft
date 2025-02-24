/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_clear.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 11:12:23 by                   #+#    #+#             */
/*   Updated: 2023/01/26 11:12:23 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LST_CLEAR_H
# define FT_LST_CLEAR_H

# include "s_list.h"

void	ft_lst_clear(t_s_list **head, void (*f_free_content)(void *));

#endif
