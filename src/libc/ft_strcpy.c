/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 22:48:00 by jnovotny          #+#    #+#             */
/*   Updated: 2022/05/07 12:31:10 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief The strcpy() function copies the string pointed to by src, including
 * 		  the terminating null byte ('\0'), to the buffer pointed to by dst.
 * 		  The strings may not overlap, and the destination string dst must be
 * 		  large enough to receive the copy. Beware of buffer overruns!
 * 
 * 		  The strcpy() functions return a pointer to the destination string dst.
 * 
 * @param dst destionation buffer pointer
 * @param src source string pointer
 * @return char* pointer to dst
 */
char	*ft_strcpy(char *dst, const char *src)
{
	ft_memcpy(dst, src, ft_strlen(src) + 1);
	return (dst);
}
