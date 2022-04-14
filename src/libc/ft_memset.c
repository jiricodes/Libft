/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 22:46:31 by jnovotny          #+#    #+#             */
/*   Updated: 2022/04/14 23:53:07 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>
#include <sys/types.h>

static inline void	ft_memset_fill(void *b, int c, size_t len)
{
	register unsigned char	*dst;

	dst = b;
	while (len != 0)
	{
		*dst++ = (unsigned char)c;
		len--;
	}
	return (b);
}

/**
 * @brief memset
 * 
 * 	Inspired by:
 * 	https://github.com/freebsd/freebsd-src/blob/main/lib/libc/string/memset.c
 * 
 * @param b 
 * @param c 
 * @param len 
 * @return void* 
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
	t = (int)dst & 7;
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
	t = len & 7;
	if (t != 0)
		ft_memset_fill(dst, c, t);
	return (b);
}
