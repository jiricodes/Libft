/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 22:44:10 by jnovotny          #+#    #+#             */
/*   Updated: 2021/04/14 01:29:13 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Checks if given character is alpha-numerical
 * 
 * @param c Checked character
 * @return int 1 on true | 0 on false
 */

int	ft_isalnum(int c)
{
	return ((c > 64 && c < 91) || (c > 96 && c < 123) || (c > 47 && c < 58));
}
