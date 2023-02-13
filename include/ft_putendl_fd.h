/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 11:12:24 by                   #+#    #+#             */
/*   Updated: 2023/02/06 18:16:57 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUTENDL_FD_H
# define FT_PUTENDL_FD_H

# include <stddef.h>
# include <unistd.h>

ssize_t	ft_putendl_fd(const char *str, int file_desc);

#endif
