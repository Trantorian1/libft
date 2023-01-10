#ifndef DEQUE_H
# define DEQUE_H

# include <stddef.h>
# include "s_deque.h"

t_s_deque	*ft_deque_new(int *data, size_t size);
void	*ft_deque_destroy(t_s_deque *deque);

#endif
