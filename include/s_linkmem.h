/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_linkmem.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 14:12:12 by emcnab            #+#    #+#             */
/*   Updated: 2023/02/27 14:59:21 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_LINKMEM_H
# define S_LINKMEM_H

typedef struct s_linkmem
{
	struct s_linkmem	*prev;
	struct s_linkmem	*next;
}	t_s_linkmem;

#endif
