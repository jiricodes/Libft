/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 22:46:14 by jnovotny          #+#    #+#             */
/*   Updated: 2022/04/30 12:00:10 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libc.h"

/**
 * @brief The `ft_memcpy` function copies `n` bytes from memory area `src`
 *		to memory area `dst`. The memory areas must not overlap.
 *		Use `ft_memmove` if the memory areas do overlap.
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

	if (dst == src || !n)
		return (dst);
	dst_ptr = dst;
	src_ptr = src;
	while (n--)
	{
		*dst_ptr++ = *src_ptr++;
	}
	return (dst);
}
