/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 22:45:46 by jnovotny          #+#    #+#             */
/*   Updated: 2021/04/14 01:44:45 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Checks if given character is printable
 * 
 * @param c Character to test
 * @return int 1/0 ~ true/false
 */

int	ft_isprint(int c)
{
	return ((c > 31 && c < 127));
}
