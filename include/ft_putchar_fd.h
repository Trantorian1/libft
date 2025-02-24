/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 11:12:24 by                   #+#    #+#             */
/*   Updated: 2023/01/26 11:12:24 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUTCHAR_FD_H
# define FT_PUTCHAR_FD_H

# include <stddef.h>
# include <unistd.h>

ssize_t	ft_putchar_fd(char c, int file_desc);

#endif
