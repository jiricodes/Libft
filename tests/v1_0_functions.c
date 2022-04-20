/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v1_0_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 22:50:10 by jnovotny          #+#    #+#             */
/*   Updated: 2022/04/20 12:14:01 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/**
 * @brief Collection of discarded functions from version 1.0
 * 
 * 			This will be used just to compare performance of new vs old
 * @date 2022-04-14
 */

# include "v1_0_functions.h"

/*
** ft_memset *******************************************************************
*/

void	*v1_0_ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	ch;
	char			*rslt;

	ch = c;
	i = 0;
	rslt = b;
	while (i < len)
	{
		rslt[i] = ch;
		i = i + 1;
	}
	return (b);
}

/*
** ft_bzero ********************************************************************
*/

void	v1_0_ft_bzero(void *s, size_t n)
{
	v1_0_ft_memset(s, 0, n);
}