/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_space.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliot <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 17:03:16 by eliot             #+#    #+#             */
/*   Updated: 2023/03/17 17:08:23 by eliot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "skip_space.h"

#include "ft_isspace.h"
#include <stddef.h>

const char	*skip_space(const char *str)
{
	size_t		index;
	const char	*skipped;

	index = 0;
	while (ft_isspace(str[index]))
		index++;
	skipped = &str[index];
	return (skipped);
}
