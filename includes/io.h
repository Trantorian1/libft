/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:00:57 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/09 16:37:46 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IO_H
# define IO_H

# include <unistd.h>
# include <limits.h>
# include "typedefs.h"
# include "linkstr.h"
# include "str.h"
# include "mem.h"

# define BUFFER_SIZE 256
# define ARRAY_SIZE 32
# define STDOUT 1
# define STDERR 2

// _Pragma("GCC diagnostic push")
// _Pragma("GCC diagnostic ignored \"-Wpadded\"")

typedef struct s_line
{
	size_t	i;
	char	buffer[BUFFER_SIZE + 1];
}	t_line;

// _Pragma("GCC diagnostic pop")

ssize_t	ft_putchar_fd(char c, int file_desc);
ssize_t	ft_putstr_fd(char *str, int file_desc);
ssize_t	ft_putendl_fd(char *str, int file_desc);
ssize_t	ft_putnbr_fd(int n, int file_desc);
char	*ft_get_next_line(int fd);

#endif
