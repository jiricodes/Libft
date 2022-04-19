/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 22:46:31 by jnovotny          #+#    #+#             */
/*   Updated: 2022/04/19 13:17:54 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>
#include <sys/types.h>

/**
 * @brief Helper ft_memset function that fills misaligned bytes
 * 			with the constant byte `c`
 * 
 * @param b memory area to be filled
 * @param c constant byte
 * @param len length of memory area to be filled
 */
static inline void	ft_memset_fill(void *b, int c, size_t len)
{
	register unsigned char	*dst;

	dst = b;
	while (len != 0)
	{
		*dst++ = (unsigned char)c;
		len--;
	}
}

/**
 * @brief The ft_memset() function fills the first `len` bytes of the memory area
 *			pointed to by `b` with the constant byte `c`.
 * 
 * 	Inspired by:
 * 	https://github.com/freebsd/freebsd-src/blob/main/lib/libc/string/memset.c
 * 
 * @param b memory area to be filled
 * @param c constant byte
 * @param len length of memory area to be filled
 * @return void* a pointer to the memory area `b`
 */
void	*ft_memset(void *b, int c, size_t len)
{
	register unsigned char	*dst;
	register u_int64_t		c_local;
	register size_t			t;

	dst = b;
	c_local = (unsigned char)c;
	if (len < 3 * 8)
		return (ft_memset_fill(b, c, len), b);
	c_local = (c_local << 32) | (c_local << 16) | (c_local << 8) | c_local;
	t = (u_int64_t)dst & 7;
	if (t != 0)
	{
		t = 8 - t;
		len -= t;
		ft_memset_fill(dst, c, t);
		dst += t;
	}
	t = len / 8;
	while (t-- != 0)
	{
		*(u_int64_t *)dst = c_local;
		dst += 8;
	}
	ft_memset_fill(dst, c, len & 7);
	return (b);
}
