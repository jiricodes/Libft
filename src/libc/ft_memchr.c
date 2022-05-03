/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 14:01:26 by jnovotny          #+#    #+#             */
/*   Updated: 2022/05/03 18:03:58 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief The memchr() function scans the initial n bytes of the memory area
 * 		  pointed to by s for the first instance of c. Both c and the bytes
 * 		  of the memory area pointed to by s are interpreted as unsigned char.
 * 
 * @param s memory area to check
 * @param c instance to search for
 * @param n number of bytes t search
 * @return void* pointer to the matching byte or NULL if the character
 * 			does not occur in the given memory area.
 */
void	*ft_memchr(const void *s, int c, size_t n)
{
	register unsigned char	*ptr;
	register unsigned char	ch;

	ptr = (unsigned char *)s;
	ch = (unsigned char)c;
	while (n--)
	{
		if (*ptr == ch)
			return ((void *)ptr);
		ptr++;
	}
	return (NULL);
}
