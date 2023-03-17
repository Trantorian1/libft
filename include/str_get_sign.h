/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_get_sign.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:02:07 by                   #+#    #+#             */
/*   Updated: 2023/03/17 16:02:27 by eliot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STR_GET_SIGN_H
# define STR_GET_SIGN_H

# include <stdint.h>

#define POSITIVE 1
#define NEGATIVE -1

int8_t	str_get_sign(const char *str, char **endptr);

#endif
