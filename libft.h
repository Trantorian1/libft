/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 14:38:51 by                   #+#    #+#             */
/*   Updated: 2023/01/20 14:38:51 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdint.h>
# include <stdbool.h>
# include "s_magic.h"
# include "s_deque.h"
# include "s_list.h"
# include <unistd.h>

int			ft_memcmp(const void *mem_a, const void *mem_b, size_t n);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		*ft_calloc(size_t elem_count, size_t elem_size);
void		ft_freeset(void *to_free, size_t n);
void		*ft_memmove(void *dst, const void *src, size_t n);
void		ft_bzero(void *mem, size_t n);
void		*ft_memset(void *memory, int byte, size_t n);
size_t		*ft_pack(size_t argc, ...);
void		*ft_memchr(const void *src, int8_t to_find, size_t n);
char		*ft_memstr(int8_t *mem, size_t mem_size);
bool		ft_isalpha(char c);
bool		ft_isalnum(char c);
bool		ft_isdigit(char c);
bool		ft_isprint(char c);
char		ft_tolower(char c);
char		ft_toupper(char c);
int			ft_todigit(char c);
bool		ft_isascii(char c);
bool		ft_isspace(char c);
bool		ft_islower(char c);
bool		ft_isupper(char c);
bool		ft_lword_check(t_lword lword, t_s_magic magic);
t_lphrase	ft_byte_search(t_lphrase lwords, t_s_magic magic, uint8_t to_find);
t_lphrase	ft_lword_search(t_lphrase lwords, uint8_t to_find);
const char	*ft_strrev(char *str, size_t from, size_t until);
const char	*ft_strnstr(const char *source, const char *substr, size_t len);
char		*ft_strtrim(const char *to_trim, const char *trim_set);
int			ft_strcmp(const char *str_a, const char *str_b);
int			ft_strncmp(const char *str_a, const char *str_b, size_t n);
size_t		ft_strlen(const char *str);
char		*ft_substr(const char *str, size_t start_index, size_t max_size);
char		*ft_strmapi(const char *str, char (*mapping_f)(unsigned int, char));
char		*ft_strchr(char *str, unsigned char c);
size_t		ft_strnsum(const char *str, size_t n);
int			ft_atoi(const char *str_int);
char		*ft_strjoin(const char *str_a, const char *str_b);
char		**ft_split(const char *to_split, char splitter);
const char	*ft_quickfind(const char *str, char to_find);
char		*ft_strrchr(char *str, unsigned char c);
void		ft_striteri(char *str, void (*f)(unsigned int, char *));
char		*ft_strdup(const char *str_src);
char		*ft_stralloc(size_t n);
size_t		ft_strsum(const char *str);
long		ft_abslong(long n);
double		ft_pow(int a, int b);
int			ft_abs(int a);
int			ft_closest_power(int n, unsigned int pow);
char		*ft_ltoa(long l);
char		*ft_ultoa_base(unsigned long l, char *base);
size_t		ft_min(size_t a, size_t b);
size_t		ft_max(size_t a, size_t b);
size_t		ft_longlen(long l);
size_t		ft_baselen(unsigned long l, size_t base);
char		*ft_itoa(int n);
int			ft_sign(int n);
size_t		ft_intlen(int n);
int			ft_deque_ensure_fit_front(t_s_deque *deque);
int			*ft_deque_pop_front_bulk(t_s_deque *deque, size_t n);
int			ft_deque_ensure_space(t_s_deque *deque);
int			ft_deque_reverse_rotate(t_s_deque *deque);
int			ft_deque_push_back(t_s_deque *deque, int n);
int			ft_deque_poll_front(t_s_deque *deque);
int			*ft_deque_poll_back_bulk(t_s_deque *deque, size_t n);
int			ft_deque_pop_front(t_s_deque *deque);
t_s_deque	*ft_deque_new(size_t size);
void		*ft_deque_destroy(t_s_deque *deque);
int			ft_deque_ensure_space_top_bulk(t_s_deque *deque, size_t n);
int			ft_deque_swap(t_s_deque *deque);
int			ft_deque_push_back_bulk(t_s_deque *deque, int *data, size_t n);
int			ft_deque_push_front(t_s_deque *deque, int n);
int			*ft_deque_poll_front_bulk(t_s_deque *deque, size_t n);
int			ft_deque_ensure_space_back_bulk(t_s_deque *deque, size_t n);
int			ft_deque_ensure_space_back(t_s_deque *deque);
int			ft_deque_poll_back(t_s_deque *deque);
int			ft_deque_rotate(t_s_deque *deque);
size_t		ft_deque_size(t_s_deque *deque);
int			ft_deque_push_front_bulk(t_s_deque *deque, int *data, size_t n);
bool		ft_deque_is_empty(t_s_deque *deque);
int			ft_deque_pop_back(t_s_deque *deque);
int			*ft_deque_pop_back_bulk(t_s_deque *deque, size_t n);
int			ft_deque_ensure_fit_back(t_s_deque *deque);
int			ft_deque_ensure_space_top(t_s_deque *deque);
t_s_list	*ft_lst_map(t_s_list *head, void *(*f_map)(void *), void (*f_free)(void *));
void		ft_lst_iter(t_s_list *head, void (*f_iter)(void *));
size_t		ft_lst_size(t_s_list *head);
void		ft_lst_add_front(t_s_list **list, t_s_list *node);
t_s_list	*ft_lst_last(t_s_list *head);
void		ft_lst_clear(t_s_list **head, void (*f_free_content)(void *));
t_s_list	*ft_lst_new(void *content);
void		ft_lst_delone(t_s_list *node, void (*f_free)(void *));
void		ft_lst_add_back(t_s_list **head, t_s_list *node_new);
ssize_t		ft_putendl_fd(char *str, int file_desc);
ssize_t		ft_putstr_fd(const char *str, int file_desc);
ssize_t		ft_putchar_fd(char c, int file_desc);
ssize_t		ft_putnbr_fd(int n, int file_desc);

#endif
