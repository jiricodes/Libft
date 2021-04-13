/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 22:45:37 by jnovotny          #+#    #+#             */
/*   Updated: 2021/04/14 01:39:56 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Checks if given character is a digit
 * 
 * @param c Character to test
 * @return int 1/0 ~ true/false
 */

int	ft_isdigit(int c)
{
	return ((c > 47 && c < 58));
}
