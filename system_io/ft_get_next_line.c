/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 17:42:24 by emcnab            #+#    #+#             */
/*   Updated: 2022/11/28 17:49:06 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
 * @brief Reads BUFFER_SIZE bytes from the file described by [fd] into [buffer].
 *	guarantees to null-terminate [buffer] after the last read character.\
 *
 * @param fd (int): file descriptor of the file to read.
 * @param buffer (char *): the buffer to copy the contents of the file to.
 *
 * @return (ssize_t): the numbers of characters read into [buffer].
 */
static ssize_t	saferead(int fd, char *buffer)
{
	ssize_t	i;

	i = read(fd, buffer, BUFFER_SIZE);
	buffer[i] = '\0';
	return (i);
}

/*
 * @brief Gets the next line in the file corresponding to the given file 
 * 	directory [fd]. Starts at the beggining of the file and returns the 
 * 	following line on each successive function call. Currently only handles one
 * 	file at a time.
 *
 * @param fd (int): file directory of the file to read. Must point to a file
 * 	wich was opened with read permissions enabled.
 *
 * @return (char *): the next line in the file corresponding to [fd].
 */
char	*get_next_line(int fd)
{
	static t_line	line = {0, };
	char			*line_end;
	char			*line_current;
	t_linkstr		*linkstr;
	char			*substr;

	line_end = "";
	linkstr = ft_linkstr_new(ARRAY_SIZE);
	line_current = NULL;
	while (*line_end != '\n')
	{
		if (!line.i && !saferead(fd, line.buffer))
			return (ft_linkstr_delall(linkstr, &free));
		if (!line.buffer[line.i])
			return (NULL);
		line_end = ft_quickfind(line.buffer + line.i, '\n');
		substr = ft_substr(line.buffer + line.i, 0, line_end - line.buffer);
		line.i = (size_t)((line_end - line.buffer) % (BUFFER_SIZE));
		ft_linkstr_add(linkstr, substr);
	}
	line_current = ft_linkstr_collect(linkstr);
	ft_linkstr_delall(linkstr, &free);
	line.i = line.i + (BUFFER_SIZE > 1);
	return (line_current);
}
