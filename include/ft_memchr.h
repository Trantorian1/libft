/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 17:36:48 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/11 17:36:48 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MEMCHR_H
# define FT_MEMCHR_H

# include <stddef.h>

void	*ft_memchr(const void *src, int8_t to_find, size_t n);

#endif
