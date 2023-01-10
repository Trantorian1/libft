#ifndef FT_LWORD_SEARCH_H
# define FT_LWORD_SEARCH_H

# include <stdbool.h>

bool	ft_lword_check(t_lword lword, t_magic magic);
t_lword	*ft_byte_search(t_lword *lwords, t_magic magic, unsigned char to_find);
t_lword	*ft_lword_search(t_lword *lwords, unsigned char to_find);

#endif
