/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_message.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 15:18:34 by                   #+#    #+#             */
/*   Updated: 2023/01/26 15:18:34 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ERROR_MESSAGE_H
# define FT_ERROR_MESSAGE_H

void		ft_error_add(int error_code, const char *error_msg);
const char	*ft_error_msg(int error_code);
void		ft_error_destroy(void);

#endif
