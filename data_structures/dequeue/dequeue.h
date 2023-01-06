/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dequeue.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 10:19:03 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/06 14:55:10 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEQUEUE_H
# define DEQUEUE_H

#include <stddef.h>
#include <stdlib.h>
#include "../../libft.h"

typedef struct s_dequeue
{
	size_t	bottom; 
	size_t	top;
	size_t	size_data;
	size_t	size_actual;
	int		*data;
}	t_s_dequeue;

t_s_dequeue*	ft_dequeue_new(int *data, size_t size);
void			*ft_dequeue_destroy(t_s_dequeue *dequeue);
int				ft_dequeue_make_space(t_s_dequeue *dequeue);
bool			ft_dequeue_should_make_space(t_s_dequeue *dequeue);
bool			ft_dequeue_is_empty(t_s_dequeue *dequeue);
int				ft_dequeue_add_front(t_s_dequeue *dequeue, int n);
int				ft_dequeue_add_back(t_s_dequeue *dequeue, int n);
int				ft_dequeue_pop_front(t_s_dequeue *dequeue);
int				ft_dequeue_pop_back(t_s_dequeue *dequeue);
int				ft_dequeue_poll_front(t_s_dequeue *dequeue);
int				ft_dequeue_poll_back(t_s_dequeue *dequeue);
int				ft_dequeue_rotate(t_s_dequeue *dequeue);
int				ft_dequeue_reverse_rotate(t_s_dequeue *dequeue);

#endif
