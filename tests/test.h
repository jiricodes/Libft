/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 22:09:47 by jnovotny          #+#    #+#             */
/*   Updated: 2021/04/13 22:18:08 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIBFT_TEST_H
# define FT_LIBFT_TEST_H

/*
** Includes ********************************************************************
*/

#include <assert.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "libft.h"

/*
** DEFINES **********************************************************************
*/

#ifndef VERBOSE
# define VERBOSE 0
#endif

#define COLOR_RED "\033[31m"
#define COLOR_BLUE "\033[34m"
#define COLOR_GREEN "\033[32m"
#define EOC "\033[0m"

/*
** Macros **********************************************************************
*/

#define CATEGORY(s)		if (VERBOSE) printf("\nTEST: %s\n", s)
#define STATUS(c, t)	if (VERBOSE) printf("%s%4d / %4d [%s%3.0f%%"EOC"]\n", \
								c != 1 ? "\033[1A\r" : "", \
								c, t, c >= t ? COLOR_GREEN : "",\
								((float)c/(float)t) * 100)

/*
** Function Prototypes *********************************************************
*/

#endif // FT_LIBFT_TEST_H