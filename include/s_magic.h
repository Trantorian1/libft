/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_magic.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 12:18:12 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/12 15:24:37 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_MAGIC_H
# define S_MAGIC_H

typedef struct s_magic
{
	unsigned long int	lomagic;
	unsigned long int	himagic;
	unsigned long int	crmagic;
}	t_s_magic;

typedef struct s_all_magic
{
	unsigned long int	lomagic;
	unsigned long int	himagic;
	unsigned long int	*crmagic;
}	t_s_allmagic;

typedef unsigned long int	t_lword;
typedef const t_lword		*t_lphrase;

#endif
