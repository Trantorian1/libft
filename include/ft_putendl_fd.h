/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:05:31 by                   #+#    #+#             */
/*   Updated: 2023/01/12 16:05:31 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUTENDL_FD_H
# define FT_PUTENDL_FD_H

# include <stddef.h>
# include <unistd.h>

ssize_t	ft_putendl_fd(char *str, int file_desc);

#endif
