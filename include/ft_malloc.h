/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 15:30:46 by                   #+#    #+#             */
/*   Updated: 2023/02/27 15:30:46 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MALLOC_H
# define FT_MALLOC_H

# include <stddef.h>

void	*ft_malloc(size_t size);
void	*ft_realloc(void *ptr, size_t size_new);
void	*ft_free(void *ptr);
void	*ft_free_all(void);

#endif
