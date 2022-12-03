/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_longword_search.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 16:00:08 by emcnab            #+#    #+#             */
/*   Updated: 2022/12/03 16:47:41 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * @brief Creates a new instance of t_magic.
 *
 * A magic structure is a collection of longwords used in bitwise operations to
 * search for the byte [to_find].
 *
 * @param to_find (char): the byte to search using the generate magic.
 *
 * @return (t_magic): new magic instance.
 */
static t_magic	ft_magic(char to_find)
{
	t_magic	magic;
	size_t	i;

	magic.lomagic = 0x01L;
	magic.himagic = 0x80L;
	magic.crmagic = (t_lword) to_find;
	i = 0;
	while (i < sizeof(t_lword))
	{
		magic.lomagic |= magic.lomagic << i * 8;
		magic.himagic |= magic.himagic << i * 8;
		magic.crmagic |= magic.crmagic << i * 8;
		i *= 2;
	}
	magic.crmagic = ~magic.crmagic;
	return (magic);
}

/**
 * @brief Searches the bytes in a longword using bitwise operations specified in
 *        [magic].
 *
 * Let us suppose the current C implementation supports 32bit longwords, but
 * this algorithm will function for any longword size.
 *
 * --------------------------- [ STARTING BYTES ] ----------------------------
 *
 * bits :	10010011 01001000 00000000 00110010
 * bytes:	AAAAAAAA BBBBBBBB CCCCCCCC DDDDDDDD
 *       	         ^^^^^^^^
 * we are looking for value Ox48 located in byte B.
 *
 * ----------------------------- [ MAGIC BYTES ] -----------------------------
 *
 * lomagic:	00000001 00000001 00000001 00000001
 * himagic: 10000000 10000000 10000000 10000000
 * crmagic: 10110111 10110111 10110111 10110111
 *
 * notice that crmagic is made up of the binary one complement to the value we 
 * are looking for (0x48).
 *
 * -------------------------- [ BITWISE OPERATIONS ] -------------------------
 *
 * step 1: lword & crmagic
 * -> this has the effect of nullifying ONLY the bytes which were equal to
 *    0x48. Notice that previous 0x0 bytes are now considered the same as
 *    0x48: this allows us to look for a specific byte while still checking
 *    for null-bytes at the end of a string.
 * result:	10010011 00000000 00000000 00110010
 *
 * step 2: lword - lomagic
 * -> removes all first bits in every bytes and propagates the result to the
 *    left. This has the effect of rolling arounf all 0x0 bytes to 0xFF.
 *    Importantly, now all 0x0 bytes in step 1 have a valid 8th bit. This will
 *    be taken advantage of to detect the bytes we are looking for.
 * result:	10010001 11111110 11111111 00110001
 *
 * step 3: lword & ~lword_initial
 * -> in step 2 we cannot use the 8th bit of each byte to detect the bytes we
 *    are looking for, because these are also present in bytes we are not
 *    interesed in. Note that the bytes we are interested in (byte B and C)
 *    did not initially have a valid 8th bit, whereas other bytes did. So by
 *    performing a binary AND with the complement to the initial lword we can
 *    remove most eroneous 8th bits and only keep those in the bytes we are
 *    looking for.
 * result:	00000000 10110110 11111111 00000001
 *
 * step 4: lword & himagic
 * -> keeps only the bytes with a valid 8th bit. Because of the manipulations
 *    in step 3, this mostly includes only the bytes we are interested in,
 *    although there might be some cases wher bytes we are not interested in
 *    still have a valid 8th byte if they gained one as a result of step 1 &
 *    2. Notice that the result of this operation with not be 0x0 ONLY IF
 *    there were bytes with a valid 8th bit, aka: the return of this fucntion
 *    will be true only if there is a higher than 0 probability that the byte
 *    we were looking for was contained in [lword].
 * result:	00000000 10000000 10000000 00000000
 * 
 * @param lwords (t_longword): the longword to search.
 * @param magic (t_magic): structure of longwords used for bitwise operations.
 *
 * @returns (bool): true if [lword] MIGHT contain the byte represented by the
 *          longwords in [magic].
 */
bool	ft_lword_check(t_lword lword, t_magic magic)
{
	lword &= magic.crmagic;
	if ((lword - magic.lomagic) & ~lword & magic.himagic)
		return (true);
	return (false);
}

/**
 * @brief Searches for a bytes [to_find] in a longword array.
 *
 * [lwords] should be a longword representation of a string. search will stop at
 * the first byte found to match [to_find] or the first null-byte contained in a
 * longword in [lwords].
 *
 * @param lwords (t_longword *): array of longwords to find.
 * @param magic (t_magic): structure of longwords used to find byte [to_find].
 * @param to_find (unsigned char): the byte to find in [lwords].
 *
 * @return (t_longword *): pointer to the first longword to contain a null-byte
 *         or the byte [to_find].
 */
t_lword	*ft_byte_search(t_lword *lwords, t_magic magic, unsigned char to_find)
{
	size_t		i;
	char		*str;

	while (true)
	{
		if (!ft_lword_check(*lwords++, magic))
			continue ;
		str = (char *)(lwords - 1);
		i = 0;
		while (i < sizeof(t_lword))
		{
			if (!str[i] || str[i] == to_find)
				return (lwords - 1);
			i++;
		}
	}
}

/**
 * @brief Searches a longword representation of a string for a single byte or
 *        the end of the string.
 *
 * @param lword (t_longword *): longword representation of the string to search.
 * @param to_find (char): the character to find in [lword].
 *
 * @return (t_longword *): the longword in which [to_find] or then end of the
 *         string is located.
 */
t_lword	*ft_lword_search(t_lword *lwords, unsigned char to_find)
{
	t_magic	magic;

	magic = ft_magic(to_find);
	return (ft_byte_search(lwords, magic, to_find));
}
