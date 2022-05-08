/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 22:48:42 by jnovotny          #+#    #+#             */
/*   Updated: 2022/05/08 20:05:07 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief The strncat() function is similar to strcat(), except that
 * 			*  it will use at most n bytes from src; and
 * 			*  src does not need to be null-terminated if it contains n or more bytes.
 * 		  As with strcat(), the resulting string in dest is always null-terminated.
 * 
 * 		  If src contains n or more bytes, strncat() writes n+1 bytes to dst
 * 		  (n from src plus the terminating null byte).  Therefore, the size
 * 		  of dst must be at least strlen(dst)+n+1.
 * 
 * @param dst destination buffer pointer
 * @param src source string pointer
 * @param n maximum number of src bytes to copy
 * @return char* pointer to dst
 */
char	*ft_strncat(char *dst, const char *src, size_t n)
{
	register size_t	start;
	register size_t	end;

	start = ft_strlen(dst);
	end = ft_strlen(src);
	if (n < end)
		end = n;
	ft_memcpy(dst + start, src, end);
	dst[start + end] = '\0';
	return (dst);
}
