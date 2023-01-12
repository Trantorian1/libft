/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:05:31 by                   #+#    #+#             */
/*   Updated: 2023/01/12 16:05:31 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUTSTR_FD_H
# define FT_PUTSTR_FD_H

# include <stddef.h>
# include <unistd.h>

ssize_t	ft_putstr_fd(const char *str, int file_desc);

#endif
