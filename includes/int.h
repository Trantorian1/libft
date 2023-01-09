/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:50:59 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/09 18:53:53 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INT_H
# define INT_H

# include <limits.h>
# include "typedefs.h"
# include "math.h"
# include "mem.h"

int		ft_sign(int n);
size_t	ft_max(size_t a, size_t b);
size_t	ft_min(size_t a, size_t b);
size_t	ft_intlen(int n_abs);
size_t	ft_longlen(long l);
size_t	ft_baselen(unsigned long l, size_t base);
char	*ft_itoa(int n);
char	*ft_ltoa(long l);
char	*ft_ultoa_base(unsigned long l, char *base);

#endif
