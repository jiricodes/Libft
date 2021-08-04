/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 11:23:15 by jnovotny          #+#    #+#             */
/*   Updated: 2021/08/04 11:38:09 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** @brief	Returns length of an interger number including minus sign.
** 
** @param	nb Number to measure
** 
** @return	unsigned int  Length of given number
*/

static inline unsigned int	ret_length(long nb, unsigned int count)
{
	if (nb >= 100)
	{
		count += 2;
		nb /= 100;
	}
	if (nb >= 10)
		count += 1;
	return (count);
}

unsigned int	int_length(long nb)
{
	unsigned int	count;

	if (nb < 0)
	{
		count = 2;
		nb = nb * -1;
	}
	else
		count = 1;
	if (nb >= 100000000)
	{
		count += 8;
		nb /= 100000000;
	}
	if (nb >= 10000)
	{
		count += 4;
		nb /= 10000;
	}
	return (ret_length(nb, count));
}
