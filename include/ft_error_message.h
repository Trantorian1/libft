/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_message.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 14:23:07 by                   #+#    #+#             */
/*   Updated: 2023/01/26 14:23:07 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ERROR_MESSAGE_H
# define FT_ERROR_MESSAGE_H

# include <stddef.h>

void		ft_error_add(size_t error_code, const char *error_msg);
const char	*ft_error_msg(size_t error_code);

#endif
