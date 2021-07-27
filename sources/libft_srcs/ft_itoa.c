/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 11:26:24 by jnovotny          #+#    #+#             */
/*   Updated: 2021/07/26 21:51:50 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define ITOA_BUF_LEN 16

/*
** Allocate (with malloc(3)) and returns a “fresh” string ending with ’\0’
** representing the integer n given as argument.
** Negative numbers must be supported. If the allocation fails,
** the function returns NULL.
*/

char	*ft_itoa(int n)
{
	char	buf[ITOA_BUF_LEN];
	uint8_t	i;
	int		sign;

	sign = 1;
	if (n == 0)
		return (ft_strdup("0"));
	else if (n < 0)
		sign = -1;
	i = ITOA_BUF_LEN - 1;
	buf[i] = '\0';
	i--;
	while (n)
	{
		buf[i] = (sign * (n % 10)) + 48;
		n = n / 10;
		i--;
	}
	if (sign == -1)
		buf[i] = '-';
	else
		i++;
	return (ft_strdup(&buf[i]));
}

/*
** @brief	ITOA into presented buffer, null terminated. Expects the buffer
**			to be sufficient otherwise undefined behaviour occurs.
** 
** @param	n			The desired number to translate
** @param	buf 		The destination of the result
** @param	buf_len		Length of buffer on input, actual len on output
** 
*/

static inline uint8_t	ft_intlen(int n)
{
	short	cnt;

	if (n <= 0)
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

void	ft_itoa_into_buf(int n, char *buf, size_t *buf_len)
{
	uint8_t	i;
	int		sign;

	sign = 1;
	if (n == 0)
	{
		ft_memcpy(buf, "0\0", 2);
		*buf_len = 1;
		return ;
	}
	else if (n < 0)
	{
		sign = -1;
		buf[0] = '-';
	}
	i = ft_intlen(n);
	*buf_len = i;
	buf[i] = '\0';
	while (n)
	{
		i--;
		buf[i] = (sign * (n % 10)) + 48;
		n = n / 10;
	}
	return ;
}
