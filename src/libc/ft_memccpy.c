/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 22:46:05 by jnovotny          #+#    #+#             */
/*   Updated: 2022/04/30 12:46:54 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libc.h"

/**
 * @brief The  memccpy()  function  copies no more than n bytes
 * 			from memory area src to memory area dest, stopping
 * 			when the character c is found.
 * 			If the memory areas overlap, the results are undefined.
 * 			The memccpy() function returns a pointer to the next character
 * 			in dest after c, or NULL if c was not found in the first
 * 			n characters of src.
 * 
 * @param dst pointer to destination memory area
 * @param src pointer to source memory area
 * @param c character to stop at
 * @param n lenght of the area to be copied
 * @return void* pointer to dst after c or NULL
 */
void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	register unsigned char			*dst_ptr;
	register const unsigned char	*src_ptr;
	register size_t					l;
	register unsigned char			ch;

	dst_ptr = dst;
	src_ptr = src;
	l = 0;
	ch = c;
	while (n - l)
	{
		*dst_ptr = *src_ptr;
		l++;
		if (*dst_ptr == ch)
			return ((void *)(dst + l));
		dst_ptr++;
		src_ptr++;
	}
	return (NULL);
}
