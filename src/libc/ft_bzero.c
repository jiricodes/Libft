/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 12:57:49 by jnovotny          #+#    #+#             */
/*   Updated: 2022/04/30 11:57:20 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>
#include <sys/types.h>

/**
 * @brief The bzero() function writes `len` zeroed bytes to the memory block `b`
 *	If `len` is zero, bzero() does nothing.
 * 
 * @param b memory area to be filled
 * @param len length of memory area to be filled
 */
void	ft_bzero(void *b, size_t len)
{
	register unsigned char	*b_ptr;

	b_ptr = b;
	while (len--)
		*b_ptr++ = 0;
}
