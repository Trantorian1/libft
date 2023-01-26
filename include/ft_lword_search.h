/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lword_search.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 11:12:20 by                   #+#    #+#             */
/*   Updated: 2023/01/26 11:12:20 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LWORD_SEARCH_H
# define FT_LWORD_SEARCH_H

# include <stdbool.h>
# include "s_magic.h"
# include <stdint.h>

bool		ft_lword_check(t_lword lword, t_s_magic magic);
t_lphrase	ft_byte_search(t_lphrase lwords, t_s_magic magic, uint8_t to_find);
t_lphrase	ft_lword_search(t_lphrase lwords, uint8_t to_find);

#endif
