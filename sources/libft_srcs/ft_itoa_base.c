/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 15:36:22 by jnovotny          #+#    #+#             */
/*   Updated: 2021/04/14 03:01:08 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

/**
 * @brief Converts given integer into given base and returns it as a string.
 * 		Negative values are converted only for base 10.
 * 
 * @param value Number to convert
 * @param base Desired base
 * @param upcase Upper case indicator (0 == lowercase, 1 == upcase)
 * @return char* Converted result (allocated)
 */

char	*ft_itoa_base(int value, int base, int upcase)
{
	int			i;
	char		buf[66];
	const char	ref[2][16] = {"0123456789abcdef", "0123456789ABCDEF"};

	if (base == 10)
		return (ft_itoa(value));
	if (base > 16 || base < 2 || value < 0)
		return (NULL);
	i = 64;
	buf[65] = '\0';
	if (value == 0)
		return (ft_strdup("0"));
	upcase = (upcase != 0);
	while (value != 0)
	{
		buf[i] = ref[upcase][value % base];
		value = value / base;
		i--;
	}
	return (ft_strdup(&buf[i + 1]));
}

char	*_ft_itoa_base(int value, int base, int upcase)
{
	char	*str;
	long	len;

	if (base > 16 || base < 2 || (base != 10 && value < 0))
		return (NULL);
	if (base == 10)
		return (ft_itoa(value));
	len = ft_base_len(value, base);
	str = ft_strnew(len);
	str[len] = '\0';
	while (len-- > 0)
	{
		if (base > 10 && (value % base >= 10) && upcase)
			str[len] = (value % base) + 55;
		else if (base > 10 && (value % base >= 10))
			str[len] = (value % base) + 87;
		else
			str[len] = (value % base) + 48;
		value = value / base;
	}
	return (str);
}
