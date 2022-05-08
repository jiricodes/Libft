/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 22:48:23 by jnovotny          #+#    #+#             */
/*   Updated: 2022/05/08 20:05:38 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief The strlcat() function concatenates strings. It appends
 * 		  the NUL-terminated string src to the end of dst. It will append
 * 		  at most size - strlen(dst) - 1 bytes, NUL-terminating the result.
 * 
 * 		  It is designed to be safer, more consistent, and less error prone
 * 		  replacement strncat(3). strlcat() takes the full size of the buffer
 * 		  (not just the length) and guarantee to NUL-terminate the result
 * 		  (as long as there is at least one byte free in dst). Note that a byte
 * 		  for the NUL should be included in size. Also note that strlcat() only
 * 		  operates on true “C” strings. This means that both src and dst must
 * 		  be NUL-terminated.
 * 
 * 		  The strlcat() function returns the total length of the string
 * 		  it tried to create. That means the initial length of dst
 * 		  plus the length of src. While this may seem somewhat confusing,
 * 		  it was done to make truncation detection simple.
 * 
 * 		  Note, however, that if strlcat() traverses size characters without
 * 		  finding a NUL, the length of the string is considered to be size
 * 		  and the destination string will not be NUL-terminated
 * 		  (since there was no space for the NUL). This keeps strlcat()
 * 		  from running off the end of a string. In practice this should
 * 		  not happen (as it means that either size is incorrect or that dst is
 * 		  not a proper “C” string).  The check exists to prevent potential
 * 		  security problems in incorrect code.
 * 
 * @param dst destination buffer pointer
 * @param src source string pointer
 * @param size size of dst buffer
 * @return size_t total attempted length
 */
size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	register size_t	src_len;
	register size_t	dst_len;

	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	if (dst_l >= dstsize)
		return (dstsize + src_l);
	if (src_l < (dstsize - dst_l))
	{
		ft_memcpy(dst + dst_l, src, src_l);
		dst[dst_l + src_l] = '\0';
	}
	else
	{
		ft_memcpy(dst + dst_l, src, dstsize - dst_l - 1);
		dst[dstsize - 1] = '\0';
	}
	return (dst_l + src_l);
}
