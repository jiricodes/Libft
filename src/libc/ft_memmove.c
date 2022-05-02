/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 13:05:49 by jnovotny          #+#    #+#             */
/*   Updated: 2022/05/02 10:17:08 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Helper function, same as ft_memcpy, but reverse
 * 
 * @param dst destination memory block
 * @param src source memory block
 * @param n number of bytes to copy
 * @return void* pointer to `dst`
 */
static void *ft_memcpy_rev(void *dst, const void *src, size_t n)
{
	register unsigned char			*dst_ptr;
	register const unsigned char	*src_ptr;

	dst_ptr = dst;
	src_ptr = src;
	dst_ptr += n;
	src_ptr += n;
	while (n--)
	{
		*dst_ptr-- = *src_ptr--;
	}
	return (dst);
}

/**
 * @brief The memmove() function copies n bytes from memory area src to memory
 * 		  area dst. The memory areas may overlap: copying takes place as though
 * 		  the bytes in src are first copied into a temporary array that does not
 * 		  overlap src or dst, and the bytes are then copied from the temporary
 * 		  array to dst.
 * 
 * 		  The memmove() function returns a pointer to dst.
 * @param dst destination memory area pointer
 * @param src source memory area pointer
 * @param n number of bytes to be moved
 * @return void* pointer to dst
 */
void	*ft_memmove(void *dst, const void *src, size_t n)
{
	if (dst == src || !n)
		return (dst);
	if (src < dst && src + n > dst)
	{
		return (ft_memcpy_rev(dst, src, n));
	}
	else
	{
		return (ft_memcpy(dst, src, n));
	}
}
