/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:55:39 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/09 16:41:09 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STR_H
# define STR_H

# include <stdlib.h>
# include <stdarg.h>
# include "typedefs.h"
# include "char.h"
# include "mem.h"

typedef struct s_magic
{
	unsigned long int	lomagic;
	unsigned long int	himagic;
	unsigned long int	crmagic;
}	t_magic;

typedef struct s_all_magic
{
	unsigned long int	lomagic;
	unsigned long int	himagic;
	unsigned long int	*crmagic;
}	t_allmagic;

// TODO: string functions need rethinking as to how 'const' is handled
int		ft_strncmp(t_str str_a, t_str str_b, size_t n);
int		ft_strcmp(t_str str_a, t_str str_b);
int		ft_atoi(t_str str_int);
char	*ft_strrev(char *str, size_t from, size_t until);
char	*ft_strchr(char *str, int c);
char	*ft_strrchr(char *str, int c);
t_str	ft_quickfind(const char *str, char to_find);
char	*ft_quickfind_all(char *str, char *to_find);
t_lword	*ft_lword_search(t_lword *lwords, unsigned char to_find);
char	*ft_strnstr(t_str source, t_str substr, size_t n);
char	*ft_strdup(t_str str_original);
char	*ft_substr(t_str string, t_uint start_index, size_t max_size);
char	*ft_strjoin(t_str str_a, t_str str_b);
char	*ft_strnjoin(size_t argc, ...);
char	*ft_strtrim(t_str to_trim, t_str trim_set);
char	*ft_strmapi(t_str str, char (*mapping_f)(t_uint, char));
char	**ft_split(t_str to_split, char delimiter);
size_t	ft_strlen(t_str str);
size_t	ft_strlcat(char *dest, t_str src, size_t size);
size_t	ft_strlcpy(char *dest, t_str src, size_t size);
size_t	ft_strnsum(t_str str, size_t n);
size_t	ft_strsum(t_str str);
void	ft_striteri(char *str, void (*f)(t_uint, char *));

#endif
