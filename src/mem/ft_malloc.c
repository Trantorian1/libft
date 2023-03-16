/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 14:14:59 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/16 14:56:36 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

#include "e_error.h"
#include "s_linkmem.h"
#include "ft_memcpy.h"
#include "ft_min.h"
#include "ft_lst_new.h"
#include "ft_lst_add_front.h"
#include "ft_lst_iter.h"
#include <stdlib.h>

static t_s_linkmem	*g_lst_mem = NULL;
static t_s_list		*g_lst_exit = NULL;

// TODO: implement other strategies for handling allocation errors.
/**
 * @brief Allocates space in memory for a pointer.
 *
 * Allocations are stored as part of a linked list, where the pointer to a node
 * shares memory with the allocated pointer. This way, a single malloc / free is
 * necesary to allocate / free the node and its associated memory.
 *
 * @param size (size_t): The number of bytes to allocate.
 * 
 * @return (void *): Pointer to allocated space in memory.
 * @warning Frees all previous allocations and exits program in case of
 * allocation failure. This guarantees that the function can never return NULL.
 */
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
	if (!g_lst_mem)
		g_lst_mem = node;
	else
	{
		node->prev = g_lst_mem;
		g_lst_mem->next = node;
		g_lst_mem = node;
	}
	data = (void *)((size_t)node + sizeof(*node));
	return (data);
}

/**
 * @brief Reallocates space in memory for a pointer, copying over its initial
 * data.
 *
 * Note that if the amount of bytes to resize the pointer to is smaller that its
 * current size, then not all bytes will be copied. While this might work for
 * arrays, it should not be used for other data types such as structures.
 *
 * @param ptr (void *): Pointer to reallocate.
 * @param size_new (size_t): Amount of bytes to resize the pointer to.
 *
 * @return (void *): Resized pointer.
 */
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

/**
 * @brief Frees up allocated space in memory.
 *
 * In freeing the pointer, also frees the associates node and updates the
 * allocation list.
 *
 * @param ptr (void *): Pointer to free.
 *
 * @return (void): NULL
 *
 * @warning This function only accepts pointers that have been allocated using
 * ft_malloc.
 */
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
	if (node == g_lst_mem)
		g_lst_mem = NULL;
	free(node);
	return (NULL);
}

/**
 * @brief Frees all memory allocated with ft_malloc.
 *
 * @return (void *): NULL
 */
void	*ft_free_all(void)
{
	t_s_list	*node_curr_list;
	t_s_linkmem	*node_curr_mem;
	t_s_linkmem	*node_prev_mem;

	node_curr_list = g_lst_exit;
	while (node_curr_list != NULL)
	{
		((void (*)(void))node_curr_list->content)();
		node_curr_list = node_curr_list->next;
	}
	node_curr_mem = g_lst_mem;
	while (node_curr_mem != NULL)
	{
		node_prev_mem = node_curr_mem->prev;
		node_curr_mem->next = NULL;
		node_curr_mem->prev = NULL;
		free(node_curr_mem);
		node_curr_mem = node_prev_mem;
	}
	g_lst_mem = NULL;
	return (NULL);
}

void	ft_onexit(void (*f)(void))
{
	if (g_lst_mem == NULL)
		g_lst_exit = ft_lst_new(f);
	else
		ft_lst_add_back(g_lst_exit, f);
}
