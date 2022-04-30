/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 22:46:31 by jnovotny          #+#    #+#             */
/*   Updated: 2022/04/30 11:55:53 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>
#include <sys/types.h>

/**
 * @brief The ft_memset() function fills the first `len` bytes of the memory area
 *			pointed to by `b` with the constant byte `c`.
 * 
 * 
 * @param b memory area to be filled
 * @param c constant byte
 * @param len length of memory area to be filled
 * @return void* a pointer to the memory area `b`
 */
void	*ft_memset(void *b, int c, size_t len)
{
	register unsigned char	ch;
	register unsigned char	*b_ptr;

	ch = c;
	b_ptr = b;
	while (len--)
	{
		*b_ptr++ = ch;
	}
	return (b);
}
