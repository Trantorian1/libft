/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 17:42:24 by emcnab            #+#    #+#             */
/*   Updated: 2022/11/29 11:56:07 by emcnab           ###   ########.fr       */
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
 * @brief Keeps reading the file described by [fd] until the current line has
 * 	been read.
 * 
 * @warning: [fd] must point to file opened with read permissions.
 *
 * @param fd (int): file descriptor used to read file.
 * @param linkstr (t_linkstr *): linked string in which to store the line
 *
 * @return (char *): current line in the file described by [fd] or NULL if read
 * 	failed.
 */
static char	*ft_grab_line(int fd, t_line l, t_linkstr *linkstr)
{
	char			*l_end;
	char			*l_current;

	l_end = "";
	l_current = NULL;
	while (*l_end != '\n')
	{
		if (!l.i && !saferead(fd, l.buffer))
			return (ft_linkstr_delall(linkstr, &free));
		if (!l.buffer[l.i])
			return (NULL);
		l_end = ft_quickfind(l.buffer + l.i, '\n');
		if (*l_end == '\n')
			l_current = ft_substr(l.buffer + l.i, 0, l_end - l.buffer + 1);
		else
			l_current = ft_substr(l.buffer + l.i, 0, l_end - l.buffer);
		l.i = (size_t)((l_end - l.buffer) % (BUFFER_SIZE));
		ft_linkstr_add(linkstr, l_current);
	}
	l.i = l.i + (BUFFER_SIZE > 1);
	return (ft_linkstr_collect(linkstr));
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
	char			*line_current;
	t_linkstr		*linkstr;

	linkstr = ft_linkstr_new(ARRAY_SIZE);
	line_current = ft_grab_line(fd, line, linkstr);
	if (!line_current)
		return (NULL);
	ft_linkstr_delall(linkstr, &free);
	return (line_current);
}
