/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 22:48:31 by jnovotny          #+#    #+#             */
/*   Updated: 2022/05/07 12:04:55 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief The strlen() function calculates the length of the string
 * 		  pointed to by s, excluding the terminating null byte ('\0').
 * 
 * 		  Note: the function doesn't check if the pointer is NULL.
 * 
 * @param s pointer to the string s
 * @return size_t the number of bytes in the string pointed to by s
 */
size_t	ft_strlen(const char *s)
{
	register size_t	i;
	register char	*ptr;

	i = 0;
	ptr = (char *)s;
	while (*ptr)
	{
		ptr++;
		i++;
	}
	return (i);
}
