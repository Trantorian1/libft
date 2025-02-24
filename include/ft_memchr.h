/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 11:12:19 by                   #+#    #+#             */
/*   Updated: 2023/01/26 11:12:19 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MEMCHR_H
# define FT_MEMCHR_H

# include <stddef.h>
# include <stdint.h>

void	*ft_memchr(const void *src, int8_t to_find, size_t n);

#endif
