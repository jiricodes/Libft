/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 22:48:51 by jnovotny          #+#    #+#             */
/*   Updated: 2022/05/07 13:02:57 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief The  strncpy() function is similar yo strcpy(), except that at most
 * 		  n bytes of src are copied.  Warning: If there is no null byte among
 * 		  the first n bytes of src, the string  placed in  dst  will  not  be
 * 		  null-terminated.
 * 
 * 		  If  the  length of src is less than  n, strncpy() writes additional
 * 		  null bytes to  dest to ensure  that a total of n bytes are written.
 * 
 * @param dst destination buffer pointer
 * @param src source string pointer
 * @param n number of bytes to copy
 * @return char* pointer to dst
 */
char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	register size_t	l;

	l = ft_strlen(src);
	if (n <= l)
	{
		ft_memcpy(dst, src, n);
	}
	else
	{
		ft_memcpy(dst, src, l);
		ft_bzero(dst + l, n - l);
	}
	return (dst);
}
