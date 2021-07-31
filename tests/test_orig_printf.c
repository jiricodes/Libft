/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_orig_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 03:27:54 by jnovotny          #+#    #+#             */
/*   Updated: 2021/07/31 03:47:38 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <string.h>
#include <stdint.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int				ft_printf(char const *str, ...);

int				main(int argc, char **argv)
{
	clock_t		time;
	int			i = 2147483647;
	long		l = 2147483647;
	long long	ll = 9223372036854775807;
	char		c = 0;
	intmax_t	im = 9223372036854775807;
	int			time_limit = 30;
	int			cnt = 0;
	if (argc > 1)
		time_limit = atoi(argv[1]);

	time = clock();
	while ((double)time / CLOCKS_PER_SEC < time_limit)
	{
		printf("\n");
		printf("%%\n");
		printf("%d\n", 42);
		printf("%d%d\n", 42, 41);
		printf("%d%d%d\n", 42, 43, 44);
		printf("%ld\n", l);
		printf("%lld\n", ll);
		printf("%x %X %p %20.15d\n", 505, 505, &ll, 54321);
		printf("%-10d % d %+d %010d %hhd\n", 3, 3, 3, 1, c);
		printf("%jd %zd %u %o %#08x\n", im, (size_t)i, i, 40, 42);
		printf("%-16.12f\n", 123456789.123456789);
		printf("%s%s%s\n", "test", "test", "test");
		printf("%C\n", 15000);
		time = clock();
		cnt++;
	}
	cnt *= 13;
	double sec = (double)time / CLOCKS_PER_SEC;
	printf("PRINTF\t\t%12d lines in %f (%f LPS)\n", cnt, sec, cnt / sec);
	return (0);
}