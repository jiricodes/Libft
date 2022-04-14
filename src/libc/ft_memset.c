/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 22:46:31 by jnovotny          #+#    #+#             */
/*   Updated: 2022/04/14 23:02:26 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>
#include <sys/types.h>

void	*ft_memset_old(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	ch;
	char			*rslt;

	ch = c;
	i = 0;
	rslt = b;
	while (i < len)
	{
		rslt[i] = ch;
		i = i + 1;
	}
	return (b);
}

void	*ft_memset(void *b, int c, size_t len)
{
	register unsigned char	*dst;
	register u_int64_t		c_local;
	register size_t			t;

	dst = b;
	c_local = (unsigned char)c;
	if (len < 3 * 8)
	{
		while (len != 0)
		{
			*dst++ = (unsigned char)c;
			len--;
		}
		return (dst);
	}
	if (c_local != 0)
	{
		c_local = (c_local << 8) | c_local;
		c_local = (c_local << 16) | c_local;
		c_local = (c_local << 32) | c_local;
	}
	t = (int)dst & 7;
	if (t != 0)
	{
		t = 8 - t;
		len -= t;
		while (t != 0)
		{
			*dst++ = (unsigned char)c;
			t--;
		}
	}
	t = len / 8;
	while (t != 0)
	{
		*(u_int64_t *)dst = c_local;
		dst += 8;
		t--;
	}
	t = len & 7;
	if (t != 0)
	{
		while (t != 0)
		{
			*dst++ = (unsigned char)c;
			t--;
		}
	}
	return (dst);
}
