/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 22:44:01 by jnovotny          #+#    #+#             */
/*   Updated: 2021/08/04 20:05:29 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long long int	adjust_index(const char *str, size_t *i)
{
	long long int	sign;

	sign = 1;
	while (ft_isspace(str[*i]))
		*i = *i + 1;
	if (str[*i] == '-')
		sign = -1;
	if (str[*i] == '+' || str[*i] == '-')
		*i = *i + 1;
	return (sign);
}

int	ft_atoi(const char *str)
{
	size_t			i;
	long long int	sign;
	long long int	rslt;

	i = 0;
	rslt = 0;
	sign = adjust_index(str, &i);
	while (ft_isdigit(str[i]))
	{
		if ((rslt >= 922337203685477580) && (str[i] - '0') > 7)
		{
			if (sign == 1)
				return (-1);
			else
				return (0);
		}
		rslt = rslt * 10 + (long long int)(str[i] - 48);
		i = i + 1;
	}
	return (sign * rslt);
}

/*
** @brief	Atoi, but also returns the index value after the number ended.
** 
** @param	str		Given string containing the number
** @param	index	Output of index where number ended
** 
** @return	int		Number extracted from the string
*/

int	ft_atoi_and_index(const char *str, size_t *index)
{
	size_t			i;
	long long int	sign;
	long long int	rslt;

	i = 0;
	rslt = 0;
	sign = adjust_index(str, &i);
	while (ft_isdigit(str[i]))
	{
		if ((rslt >= 922337203685477580) && (str[i] - '0') > 7)
		{
			if (sign == 1)
				return (-1);
			else
				return (0);
		}
		rslt = rslt * 10 + (long long int)(str[i] - 48);
		i = i + 1;
	}
	*index = i;
	return (sign * rslt);
}
