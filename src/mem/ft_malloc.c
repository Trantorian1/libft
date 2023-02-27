/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 14:14:59 by emcnab            #+#    #+#             */
/*   Updated: 2023/02/27 15:58:13 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

#include "e_error.h"
#include "s_linkmem.h"
#include "ft_memcpy.h"
#include "ft_min.h"
#include <stdlib.h>

static t_s_linkmem	*g_last = NULL;

void	*ft_malloc(size_t size)
{
	t_s_linkmem			*node;
	void				*data;

	node = malloc(sizeof(*node) + size);
	if (!node)
	{
		ft_free_all();
		exit(ERROR_MALLOC);
	}
	node->size = size;
	node->prev = NULL;
	node->next = NULL;
	if (!g_last)
		g_last = node;
	else
	{
		node->prev = g_last;
		g_last->next = node;
		g_last = node;
	}
	data = (void *)((size_t)node + sizeof(*node));
	return (data);
}

void	*ft_realloc(void *ptr, size_t size_new)
{
	t_s_linkmem	*node_old;
	void		*data_new;

	if (!ptr)
		return (NULL);
	node_old = (t_s_linkmem *)((size_t)ptr - sizeof(*node_old));
	if (node_old->size == size_new)
		return (ptr);
	data_new = ft_malloc(size_new);
	ft_memcpy(data_new, ptr, ft_min(node_old->size, size_new));
	ft_free(ptr);
	return (data_new);
}

void	*ft_free(void *ptr)
{
	t_s_linkmem	*node;

	if (!ptr)
		return (NULL);
	node = (t_s_linkmem *)((size_t)ptr - sizeof(*node));
	if (node->prev)
		node->prev->next = node->next;
	if (node->next)
		node->next->prev = node->prev;
	if (node == g_last)
		g_last = NULL;
	free(node);
	return (NULL);
}

void	*ft_free_all(void)
{
	t_s_linkmem	*node_curr;
	t_s_linkmem	*node_prev;

	node_curr = g_last;
	while (node_curr)
	{
		node_prev = node_curr->prev;
		node_curr->next = NULL;
		node_curr->prev = NULL;
		free(node_curr);
		node_curr = node_prev;
	}
	g_last = NULL;
	return (NULL);
}
