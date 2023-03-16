/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_linkmem.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 14:12:12 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/16 17:36:57 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_LINKMEM_H
# define S_LINKMEM_H

# include <stddef.h>

typedef struct s_linkmem
{
	size_t				size;
	struct s_linkmem	*prev;
	struct s_linkmem	*next;
}	t_s_linkmem;

#endif
