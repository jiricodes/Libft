/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 14:23:32 by jnovotny          #+#    #+#             */
/*   Updated: 2022/05/07 11:41:37 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief The  memcmp()  function  compares  the first n bytes
 * 		  (each interpreted as unsigned char) of the memory areas s1 and s2.
 * 
 * 		  The memcmp() function returns an integer less than, equal to,
 * 		  or greater than zero if the first n bytes of s1 is found, respectively,
 * 		  to be less than, to match, or be greater than the first n bytes of s2.
 * 
 * 		  For a nonzero return value, the sign is determined by the sign of the
 * 		  difference between the first pair of bytes (interpreted
 * 		  as unsigned char) that differ in s1 and s2.
 * 
 * 		  If n is zero, the return value is zero.
 * 
 * @param s1 pointer to first memory area
 * @param s2 pointer to second memory area
 * @param n number of bytes to compare
 * @return int 0 if they are equal, else diff value of first non-equal symbol
 */
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	register unsigned char	*a;
	register unsigned char	*b;

	if (s1 == s2 || n == 0)
		return (0);
	a = (unsigned char *)s1;
	b = (unsigned char *)s2;
	while (n-- && !(*a ^ *b))
	{
		a++;
		b++;
	}
	return (*a - *b);
}
