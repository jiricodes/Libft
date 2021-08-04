/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_orig_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 03:27:54 by jnovotny          #+#    #+#             */
/*   Updated: 2021/08/04 09:55:05 by jnovotny         ###   ########.fr       */
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
	char		text[] = "et facilisis non, facilisis ac mi. Nunc vulputate, erat eget pharetra porttitor\n, leo neque dignissim nisi, rutrum aliquam nulla augue ut est. Nam molestie varius lorem eu\n tincidunt. In metus nisl, luctus at eros at, porttitor cursus lectus. Pellentesque commodo id\n  tortor quis tincidunt. Integer non porttitor libero, a facilisis purus. Donec in orci malesuada sapien\n   lobortis dapibus sed quis ipsum. Interdum et malesuada fames ac ante ipsum primis in faucibus. Pellentesque suscipit mauris in faucibus \n   laoreet. Sed porttitor diam non risus varius, vel ullamcorper urna convallis. Nunc venenatis risus vel gravida dictum.\nMauris pharetra dapibus lectus non gravida. Proin elementum quis massa ut scelerisque. Ut eleifend lacus\n purus, quis consequat nunc sagittis a. Vivamus et volutpat purus. Vivamus id leo consectetur\n  elit fringilla aliquet. Duis orci enim, convallis ac\n";
	int			time_limit = 30;
	int			cnt = 0;
	if (argc > 1)
		time_limit = atoi(argv[1]);

	time = clock();
	while ((double)time / CLOCKS_PER_SEC < time_limit)
	{
		printf("\n");
		printf("%s\n", text);
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
		printf("%.20d\n", -123);
		printf("%-16.12f\n%s %jd %zd %u %o %#08x\n", 123456789.123456789, text,  im, (size_t)i, i, 40, 42);
		time = clock();
		cnt++;
	}
	cnt *= 14;
	double sec = (double)time / CLOCKS_PER_SEC;
	printf("PRINTF\t\t%12d lines in %f (%f LPS)\n", cnt, sec, cnt / sec);
	return (0);
}