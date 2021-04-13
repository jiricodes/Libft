/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 22:44:01 by jnovotny          #+#    #+#             */
/*   Updated: 2019/10/21 14:24:00 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Transforms string numbers into int.
 * 
 * Discards whitespace characters from the beginning of the string
 * 		- whitespace characeters are those for which isspace() is true
 * Recognizes the optional "+" or "-" sign
 * Parses the immediately following maximal string of base-10 digits
 * and converts it into a numerical value
 * Additional non-numerich characters are ignored
 * Invalid number or no number results in a result of 0
 * No overflow protection
 * 
 * @param str input string
 * @return int Integer value
 */

int	ft_atoi(const char *str)
{
	size_t			i;
	long long int	sign;
	long long int	rslt;
	uint8_t			digit;

	i = 0;
	sign = 1;
	rslt = 0;
	while (str[i] == ' ' || str[i] == '\r' || str[i] == '\n' || \
		str[i] == '\f' || str[i] == '\v' || str[i] == '\t')
		i = i + 1;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '+' || str[i] == '-')
		i = i + 1;
	digit = (uint8_t)(str[i] - 48);
	while (digit <= 9)
	{
		rslt = rslt * 10 + digit;
		i = i + 1;
		digit = (uint8_t)(str[i] - 48);
	}
	return (sign * rslt);
}
