/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 22:45:25 by jnovotny          #+#    #+#             */
/*   Updated: 2021/04/14 01:39:07 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Checks if given character is within ASCII
 * 
 * @param c Character to test
 * @return int 1/0 ~ true/false 
 */

int	ft_isascii(int c)
{
	return ((c >= 0 && c <= 127));
}
