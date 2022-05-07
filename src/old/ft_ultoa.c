/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 11:42:27 by jnovotny          #+#    #+#             */
/*   Updated: 2021/07/27 13:21:54 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define ULTOA_BUF_LEN 32

/*
** Allocate (with malloc(3)) and returns a “fresh” string ending with ’\0’
** representing the unsigned long n given as argument.
** If the allocation fails, the function returns NULL.
*/

char	*ft_ultoa(unsigned long n)
{
	char	buf[ULTOA_BUF_LEN];
	uint8_t	i;

	if (n == 0)
		return (ft_strdup("0"));
	i = ULTOA_BUF_LEN - 1;
	buf[i] = '\0';
	while (n)
	{
		i--;
		buf[i] = (n % 10) + 48;
		n = n / 10;
	}
	return (ft_strdup(&buf[i]));
}

/*
** @brief	ULTOA into presented buffer, null terminated. Expects the buffer
**			to be sufficient otherwise undefined behaviour occurs.
** 
** @param	n			The desired number to translate
** @param	buf 		The destination of the result
** @param	buf_len		Length of buffer on input, actual len on output
** 
*/

static inline uint8_t	ft_uintlen(unsigned long n)
{
	short	cnt;

	if (n == 0)
		cnt = 1;
	else
		cnt = 0;
	while (n != 0)
	{
		n = n / 10;
		cnt = cnt + 1;
	}
	return (cnt);
}

void	ft_ultoa_into_buf(unsigned long n, char *buf, size_t *buf_len)
{
	uint8_t	i;

	if (n == 0)
	{
		ft_memcpy(buf, "0\0", 2);
		*buf_len = 1;
		return ;
	}
	i = ft_uintlen(n);
	*buf_len = i;
	buf[i] = '\0';
	while (n)
	{
		i--;
		buf[i] = (n % 10) + 48;
		n = n / 10;
	}
	return ;
}
