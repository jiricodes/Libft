/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_test.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 12:59:50 by jnovotny          #+#    #+#             */
/*   Updated: 2022/05/07 12:56:20 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_TEST_H
# define LIBFT_TEST_H

/*
** Includes ********************************************************************
*/

#include <assert.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <inttypes.h>
#include <time.h>
#include <limits.h>
#include <sys/syscall.h>
#include <sys/stat.h>

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

#define SPEED_ITERATIONS 1000000

/*
** Macros **********************************************************************
*/

#define CATEGORY(s)		if (VERBOSE) printf("\nTEST: %s\n", s)
#define STATUS(c, t)	if (VERBOSE) printf("%s%4d / %4d [%s%3.0f%%"EOC"]\n", \
								c != 1 ? "\033[1A\r" : "", \
								c, t, c >= t ? COLOR_GREEN : "",\
								((float)c/(float)t) * 100)
#define SPEEDRES(f)		if (VERBOSE) printf("%.2f executions per second\n", f)
#define SPEEDRES_NAME(f, n)		if (VERBOSE) printf("%s: %.2f executions per second\n", n, f)
#define SPEEDCMP(f, o)		if (VERBOSE) printf("%.2f%% speed of %s\n", f, o)

/*
** UNITTESTS *******************************************************************
*/

void test_ft_memset();
void test_ft_bzero();
void test_ft_memcpy();
void test_ft_memccpy();
void test_ft_memmove();
void test_ft_memchr();
void test_ft_memcmp();
void test_ft_strlen();
void test_ft_strdup();
void test_ft_strcpy();
void test_ft_strncpy();

# endif // LIBFT_TEST_H