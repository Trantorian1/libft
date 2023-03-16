/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 14:57:39 by                   #+#    #+#             */
/*   Updated: 2023/03/16 14:57:39 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MALLOC_H
# define FT_MALLOC_H

# include <stddef.h>

void	*ft_malloc(size_t size);
void	*ft_realloc(void *ptr, size_t size_new);
void	*ft_free(void *ptr);
void	*ft_free_all(void);
void	ft_onexit(void (*f)(void));

#endif
