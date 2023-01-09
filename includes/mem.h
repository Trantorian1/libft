/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:14:35 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/09 16:39:48 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEM_H
# define MEM_H

# include <stdlib.h>
# include <limits.h>
# include <stdarg.h>
# include "typedefs.h"
# include "char.h"

# ifdef _WIN64
#  define SIZE_MAX _UI64_MAX
# else
#  define SIZE_MAX UINT_MAX
# endif

void	ft_bzero(void *mem, size_t n);
void	ft_freeset(void *to_free, size_t n);
void	*ft_memset(void *memory, int byte, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memchr(const void *chr, int to_find, size_t n);
void	*ft_calloc(size_t elem_count, size_t elem_size);
char	*ft_stralloc(size_t n);
char	*ft_memstr(t_any mem, size_t mem_size);
int		ft_memcmp(const void *mem_a, const void *mem_b, size_t size);
size_t	*ft_pack(size_t argc, ...);

#endif
