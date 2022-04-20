/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 12:57:49 by jnovotny          #+#    #+#             */
/*   Updated: 2022/04/20 12:31:44 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>
#include <sys/types.h>

/**
 * @brief Helper function that fills misaligned bytes
 * 			with zeroed byte.
 * 
 * @param b memory area to be filled
 * @param len length of memory area to be filled
 */
static inline void	ft_bzero_fill(void *b, size_t len)
{
	register unsigned char	*dst;

	dst = b;
	while (len != 0)
	{
		*dst++ = 0;
		len--;
	}
}

/**
 * @brief The bzero() function writes `len` zeroed bytes to the memory block `b`
 *	If `len` is zero, bzero() does nothing.
 * 	Inspired by:
 * 	https://github.com/freebsd/freebsd-src/blob/main/lib/libc/string/memset.c
 * 
 * @param b memory area to be filled
 * @param len length of memory area to be filled
 */
void	ft_bzero(void *b, size_t len)
{
	register unsigned char	*dst;
	register size_t			t;

	dst = b;
	if (len < 3 * 8)
		return (ft_bzero_fill(b, len));
	t = (u_int64_t)dst & 7;
	if (t != 0)
	{
		t = 8 - t;
		len -= t;
		ft_bzero_fill(dst, t);
		dst += t;
	}
	t = len / 8;
	while (t-- != 0)
	{
		*(u_int64_t *)dst = 0;
		dst += 8;
	}
	return (ft_bzero_fill(dst, len & 7));
}
