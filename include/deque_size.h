#ifndef DEQUE_SIZE_H
# define DEQUE_SIZE_H

# include "s_deque.h"

int		ft_deque_make_space(t_s_deque *deque);
bool	ft_deque_should_make_space(t_s_deque *deque);
bool	ft_deque_is_empty(t_s_deque *deque);

#endif
