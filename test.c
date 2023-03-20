/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliot <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 17:43:24 by eliot             #+#    #+#             */
/*   Updated: 2023/03/20 11:01:33 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <errno.h>
#include <float.h>
#include <stdlib.h>
#include <stdio.h>

int	main(int argc, const char *argv[])
{
	char	*endptr;
	double	d;

#if 1
	if (argc < 2)
		return (EXIT_FAILURE);
	endptr = "";
	d = ft_str_to_d(argv[1], &endptr);
	printf("%f\n", d);
	d = strtod(argv[1], &endptr);
	printf("%f\n", d);
# else
	endptr = "";
	d = ft_str_to_d("-12.3e3", &endptr);
	printf("%f, %d\n", d, errno);
	d = strtod("-12.3e3", &endptr);
	printf("%f, %d\n", d, errno);
#endif
}
