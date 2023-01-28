/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_handle.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 16:54:52 by                   #+#    #+#             */
/*   Updated: 2023/01/26 16:54:52 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ERROR_HANDLE_H
# define FT_ERROR_HANDLE_H

# include "e_error.h"
# include <stdbool.h>

void	ft_error_throw_fd(int error_code, int fd);
void	ft_error_throw(int error_code);
void	test(void);
bool	ft_error_occurred(void);
bool	ft_error_catch(int error_code);

#endif
