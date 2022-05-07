/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 22:47:45 by jnovotny          #+#    #+#             */
/*   Updated: 2022/05/07 13:52:04 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief The  strcat()  function  appends the src string to the dst string,
 * 		  overwriting the terminating null byte ('\0') at the end of dst,
 * 		  and then adds a terminating null byte. The strings may not overlap,
 * 		  and the dst string must have enough space for the result. If dst
 * 		  is not large enough, program behavior is unpredictable.
 *
 * 		  The strcat() function return a pointer to the resulting string dst.
 * 
 * @param dst destionation buffer pointer
 * @param src source string pointer
 * @return char* pointer to dst
 */
char	*ft_strcat(char *dst, const char *src)
{
	register size_t	start;

	start = ft_strlen(dst);
	ft_memcpy(dst + start, src, ft_strlen(src) + 1);
	return (dst);
}
