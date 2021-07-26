/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 11:26:24 by jnovotny          #+#    #+#             */
/*   Updated: 2021/07/26 12:44:08 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Allocate (with malloc(3)) and returns a “fresh” string ending with ’\0’
** representing the integer n given as argument.
** Negative numbers must be supported. If the allocation fails,
** the function returns NULL.
*/

static short	ft_intlen(int n)
{
	short	cnt;

	if (n <= 0)
	{
		cnt = 1;
	}
	else
	{
		cnt = 0;
	}
	while (n != 0)
	{
		n = n / 10;
		cnt = cnt + 1;
	}
	return (cnt);
}

char	*ft_itoa(int n)
{
	char	*res;
	short	len;
	short	i;
	short	sign;

	len = ft_intlen(n);
	res = ft_strnew(len);
	if (!res)
		return (NULL);
	i = 0;
	sign = 1;
	if (n == 0)
		res[i] = '0';
	if (n < 0)
	{
		res[i] = '-';
		sign = -1;
	}
	while (n != 0)
	{
		res[len - 1] = (sign * (n % 10)) + 48;
		n = n / 10;
		len = len - 1;
	}
	return (res);
}
