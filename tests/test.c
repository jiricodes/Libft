/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 22:09:50 by jnovotny          #+#    #+#             */
/*   Updated: 2021/04/13 22:41:47 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Includes ********************************************************************
*/

#include "test.h"

/*
** Functions *******************************************************************
*/

/*
** ft_atoi *********************************************************************
*/

static void unittest_ft_atoi_one(char *str, int *current, int total)
{
	int ret;
    int expected;

	*current += 1;
	ret = ft_atoi(str);
    expected = atoi(str);
	assert(ret == expected);
	STATUS(*current, total);
}

static void	unittest_ft_atoi()
{

	int current = 0;
	int total = 22;
    CATEGORY("ft_atoi");
    unittest_ft_atoi_one("", &current, total);
    unittest_ft_atoi_one("1", &current, total);
    unittest_ft_atoi_one("a1", &current, total);
    unittest_ft_atoi_one("--1", &current, total);
    unittest_ft_atoi_one("++1", &current, total);
    unittest_ft_atoi_one("+1", &current, total);
    unittest_ft_atoi_one("-1", &current, total);
    unittest_ft_atoi_one("0", &current, total);
    unittest_ft_atoi_one("+42lyon", &current, total);
    unittest_ft_atoi_one("+101", &current, total);
    unittest_ft_atoi_one("2147483647", &current, total);
    unittest_ft_atoi_one("-2147483648", &current, total);
    unittest_ft_atoi_one("-+42", &current, total);
    unittest_ft_atoi_one("+-42", &current, total);
    unittest_ft_atoi_one("+\t42", &current, total);
    unittest_ft_atoi_one("-\t42", &current, total);
    unittest_ft_atoi_one("1\t42", &current, total);
    unittest_ft_atoi_one("-1\t42", &current, total);
    unittest_ft_atoi_one("\t42", &current, total);
    unittest_ft_atoi_one("\r42", &current, total);
    unittest_ft_atoi_one("\f42", &current, total);
    unittest_ft_atoi_one("   \t42", &current, total);
}

/*
** Main ************************************************************************
*/

int			main(int argc, char **argv)
{
	if (VERBOSE)
		printf(COLOR_BLUE"UNIT TEST FOR LIBFT\n"EOC);
    unittest_ft_atoi();
    return (0);
}
