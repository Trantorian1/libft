/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 19:47:27 by                   #+#    #+#             */
/*   Updated: 2023/03/09 11:21:42 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdint.h>
# include <stdbool.h>
# include <unistd.h>

typedef struct s_magic
{
	unsigned long int	lomagic;
	unsigned long int	himagic;
	unsigned long int	crmagic;
}	t_s_magic;

typedef struct s_all_magic
{
	unsigned long int	lomagic;
	unsigned long int	himagic;
	unsigned long int	*crmagic;
}	t_s_allmagic;

typedef unsigned long int	t_lword;
typedef const t_lword		*t_lphrase;

typedef struct s_array
{
	size_t	footprint;
	size_t	index;
	int		*data;
}	t_s_array;

typedef struct s_array_any
{
	size_t		footprint;
	size_t		index;
	const void	**data;
}	t_s_array_any;

typedef struct s_deque
{
	size_t	bottom;
	size_t	top;
	size_t	size_data;
	size_t	size_actual;
	size_t	size_min;
	int		*data;
}	t_s_deque;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_s_list;

typedef struct s_vec2d
{
	int32_t	x;
	int32_t	y;
}	t_s_vec2d;

typedef struct s_vec2d_d
{
	double	x;
	double	y;
}	t_s_vec2d_d;

int				ft_memcmp(const void *mem_a, const void *mem_b, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_calloc(size_t elem_count, size_t elem_size);
void			ft_freeset(void *to_free, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t n);
void			ft_bzero(void *mem, size_t n);
void			*ft_memset(void *memory, int byte, size_t n);
int				**ft_mock_any_create(size_t size);
void			*ft_mock_any_destroy(int **mock, size_t until);
size_t			*ft_pack(size_t argc, ...);
void			*ft_malloc(size_t size);
void			*ft_realloc(void *ptr, size_t size_new);
void			*ft_free(void *ptr);
void			*ft_free_all(void);
void			*ft_memchr(const void *src, int8_t to_find, size_t n);
char			*ft_memstr(int8_t *mem, size_t mem_size);
bool			ft_isalpha(char c);
bool			ft_isalnum(char c);
bool			ft_isdigit(char c);
bool			ft_isprint(char c);
char			ft_tolower(char c);
char			ft_toupper(char c);
int				ft_todigit(char c);
bool			ft_isascii(char c);
bool			ft_isspace(char c);
bool			ft_islower(char c);
bool			ft_isupper(char c);
bool			ft_lword_check(t_lword lword, t_s_magic magic);
t_lphrase		ft_byte_search(t_lphrase lwords, t_s_magic magic, uint8_t to_find);
t_lphrase		ft_lword_search(t_lphrase lwords, uint8_t to_find);
const char		*ft_strrev(char *str, size_t from, size_t until);
const char		*ft_strnstr(const char *source, const char *substr, size_t len);
char			*ft_strtrim(const char *to_trim, const char *trim_set);
int				ft_strcmp(const char *str_a, const char *str_b);
int				ft_strncmp(const char *str_a, const char *str_b, size_t n);
size_t			ft_strlen(const char *str);
char			*ft_substr(const char *str, size_t start_index, size_t max_size);
char			*ft_strmapi(const char *str, char (*mapping_f)(unsigned int, char));
char			*ft_strchr(char *str, unsigned char c);
size_t			ft_strnsum(const char *str, size_t n);
int				ft_atoi(const char *str_int);
char			*ft_strjoin(const char *str_a, const char *str_b);
char			**ft_split(const char *to_split, char splitter);
const char		*ft_quickfind(const char *str, char to_find);
char			*ft_strrchr(char *str, unsigned char c);
void			ft_striteri(char *str, void (*f)(unsigned int, char *));
char			*ft_strdup(const char *str_src);
char			*ft_stralloc(size_t n);
size_t			ft_strsum(const char *str);
long			ft_abslong(long n);
double			ft_pow(int a, int b);
int				ft_abs(int a);
size_t			ft_closest_power_ul(size_t n, unsigned int pow);
int				ft_closest_power(int n, unsigned int pow);
int32_t			max(int32_t a, int32_t b);
double			max_d(double a, double b);
int32_t			abs(int32_t a);
char			*ft_ltoa(long l);
char			*ft_ultoa_base(unsigned long l, char *base);
size_t			ft_min(size_t a, size_t b);
size_t			ft_max(size_t a, size_t b);
size_t			ft_longlen(long l);
size_t			ft_baselen(unsigned long l, size_t base);
char			*ft_itoa(int n);
int				ft_sign(int n);
int				*ft_mock_data(int min, int max);
size_t			ft_intlen(int n);
t_s_vec2d		*vec2d_new(int32_t x, int32_t y);
t_s_vec2d		*vec2d_scale_int(t_s_vec2d vec, int32_t scalar);
t_s_vec2d		*vec2d_add(t_s_vec2d *a, t_s_vec2d *b);
t_s_vec2d		*vec2d_sub(t_s_vec2d *a, t_s_vec2d *b);
t_s_vec2d_d		*vec2d_new_d(double x, double y);
t_s_vec2d_d		*vec2d_copy_d(t_s_vec2d_d *dest, t_s_vec2d_d source);
t_s_vec2d_d		*vec2d_mult_d(t_s_vec2d_d *source, double scalar);
t_s_vec2d_d		*vec2d_combine_d(t_s_vec2d_d *dest, t_s_vec2d_d source);
t_s_array		*ft_array_create(size_t size);
bool			ft_array_insert(t_s_array *array, size_t index, int n);
void			ft_array_add(t_s_array *array, int n);
void			ft_array_add_bulk(t_s_array *array, const int *data, size_t size);
int				ft_array_get(t_s_array *array, size_t index);
size_t			ft_array_size(t_s_array *array);
void			*ft_array_destroy(t_s_array *array);
t_s_array		*ft_mock_array(int min, int max);
int				*ft_deque_pop_front_bulk(t_s_deque *deque, size_t n);
int				*ft_deque_to_array(t_s_deque *deque);
void			ft_deque_reverse_rotate(t_s_deque *deque);
void			ft_deque_push_back(t_s_deque *deque, int n);
int				ft_deque_poll_front(t_s_deque *deque);
int				*ft_deque_poll_back_bulk(t_s_deque *deque, size_t n);
int				ft_deque_pop_front(t_s_deque *deque);
t_s_deque		*ft_deque_new(size_t size);
void			*ft_deque_destroy(t_s_deque *deque, void (*f_free)(void *));
t_s_deque		*ft_mock_deque(int min, int max);
int				ft_deque_swap(t_s_deque *deque);
void			ft_deque_push_back_bulk(t_s_deque *deque, int *data, size_t n);
void			ft_deque_push_front(t_s_deque *deque, int n);
int				*ft_deque_poll_front_bulk(t_s_deque *deque, size_t n);
int				ft_deque_poll_back(t_s_deque *deque);
void			ft_deque_rotate(t_s_deque *deque);
size_t			ft_deque_size(t_s_deque *deque);
void			ft_deque_push_front_bulk(t_s_deque *deque, int *data, size_t n);
bool			ft_deque_is_empty(t_s_deque *deque);
int				ft_deque_pop_back(t_s_deque *deque);
int				*ft_deque_pop_back_bulk(t_s_deque *deque, size_t n);
void			ft_lst_iter(t_s_list *head, void (*f_iter)(void *));
size_t			ft_lst_size(t_s_list *head);
void			ft_lst_add_front(t_s_list **list, t_s_list *node);
t_s_list		*ft_lst_last(t_s_list *head);
void			ft_lst_clear(t_s_list **head, void (*f_free_content)(void *));
t_s_list		*ft_lst_new(void *content);
void			ft_lst_delone(t_s_list *node, void (*f_free)(void *));
void			ft_lst_add_back(t_s_list **head, t_s_list *node_new);
t_s_array_any	*ft_array_any_create(size_t size);
void			*ft_array_any_destroy(t_s_array_any *array, void (*f_free)(void *));
t_s_array_any	*ft_mock_array_any(int min, int max);
void			ft_array_any_add(t_s_array_any *array, const void *any);
void			ft_array_any_add_at(t_s_array_any *array, const void *any, size_t index);
void			*ft_array_any_get(t_s_array_any *array, size_t index);
void			ft_array_any_insert(t_s_array_any *array, size_t index, void *any);
size_t			ft_array_any_size(t_s_array_any *array);
ssize_t			ft_putendl_fd(const char *str, int file_desc);
ssize_t			ft_putstr_fd(const char *str, int file_desc);
ssize_t			ft_putchar_fd(char c, int file_desc);
ssize_t			ft_putnbr_fd(int n, int file_desc);

#endif
