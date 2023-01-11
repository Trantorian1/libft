/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pack.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:16:31 by emcnab            #+#    #+#             */
/*   Updated: 2023/01/11 17:02:25 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pack.h"

#include <stddef.h>
#include <stdarg.h>
#include <stdlib.h>

/*
 * @brief Packs a variable amount of arguments of any type into an array.
 *
 * @param argc (size_t): number of arguments to pack.
 * @param ... (any): arguments to pack.
 *
 * @return (size_t *): array of all elements in [...].
 */
size_t	*ft_pack(size_t argc, ...)
{
	size_t	i;
	size_t	*packed;
	va_list	varargs;

	i = 0;
	packed = malloc(argc * sizeof(*packed));
	if (!packed)
		return (NULL);
	__builtin_va_start(varargs, argc);
	while (i < argc)
		packed[i++] = __builtin_va_arg(varargs, size_t);
	__builtin_va_end(varargs);
	return (packed);
}
