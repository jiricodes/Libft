/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 22:46:14 by jnovotny          #+#    #+#             */
/*   Updated: 2022/04/20 16:30:30 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_libc.h"


/**
 * @brief The `ft_memcpy` function copies `n` bytes from memory area `src`
 *		to memory area `dst`. The memory areas must not overlap.
 *		Use `ft_memmove` if the memory areas do overlap.
 *
 * 		Implementation based on:
 * 		https://github.com/freebsd/freebsd-src/blob/main/lib/libc/string/bcopy.c
 * 		However lacks portability due to 64bit os assumption.
 * 		Also it considers definition of memset in man, where collision of
 *		memory blocks is not checked and behaviour is undefined in such cases.
 * 
 * @param dst destination memory block
 * @param src source memory block
 * @param n number of bytes to copy
 * @return void* pointer to `dst`
 */
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	register unsigned char			*dst_ptr;
	register const unsigned char	*src_ptr;
	register size_t					t;

	if (dst == src || n == 0)
		return (dst);
	dst_ptr = dst;
	src_ptr = src;
	t = (uintptr_t)src_ptr;
	if ((t | (uintptr_t)dst_ptr) & 7)
	{
		if((t ^ (uintptr_t)dst_ptr) & 7 || n < 8)
			t = n;
		else
			t = 8 - (t & 7);
		n -= t;
		while (t-- > 0)
		{
			*dst_ptr++ = *src_ptr++;
		}
	}
	t = n / 8;
	while (t-- > 0)
	{
		*(intptr_t *)(void *)dst_ptr = *(const intptr_t *)(const void *)src_ptr;
		src_ptr += 8;
		dst_ptr += 8;
	}
	t = n & 7;
	while (t-- > 0)
	{
		*dst_ptr++ = *src_ptr++;
	}
	return (dst);
}
