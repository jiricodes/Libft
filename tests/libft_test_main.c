/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_test_main.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 12:58:07 by jnovotny          #+#    #+#             */
/*   Updated: 2021/07/26 13:38:52 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Includes ********************************************************************
*/

#include "libft_test.h"

/*
** Constatnts ******************************************************************
*/

#define SPEED_ITERATIONS 10000

/*
** Functions *******************************************************************
*/

/*
** ft_itoa *********************************************************************
*/

static void test_ft_itoa_one(int input, char *expected, int *current, int total) {
	
	*current += 1;
	char *result = ft_itoa(input);
	assert(!strcmp(result, expected));
	free(result);
	STATUS(*current, total);
}

#ifdef SPEEDTEST
static void test_ft_itoa_speed()
{
	CATEGORY("ft_itoa performance");

	int input = -2147483648;

	clock_t start = clock();
	for (int i = 0; i < SPEED_ITERATIONS; i++)
	{
		char *result = ft_itoa(input);
		free(result);
	}
	clock_t end  = clock();
	double ft_time = (double)(end - start) / CLOCKS_PER_SEC;
	start = clock();
	for (int i = 0; i < SPEED_ITERATIONS; i++)
	{
		char *result = malloc(16);
		itoa(input, result, 10);
		free(result);
	}
	end  = clock();
	double orig_time = (double)(end - start) / CLOCKS_PER_SEC;
	printf("%f.2 %%\n", (ft_time / orig_time) * 100);
}
#endif // SPEEDTEST

static void test_ft_itoa() {
	int current = 0;
	int total = 1000;

	CATEGORY("ft_itoa");
	test_ft_itoa_one(0, "0", &current, total);
	test_ft_itoa_one(2147483647, "2147483647", &current, total);
	test_ft_itoa_one(-2147483648, "-2147483648", &current, total);

#ifdef SPEEDTEST
	test_ft_itoa_speed();
#endif // SPEEDTEST
}

/*
** main ************************************************************************
*/

int main() {
	if (VERBOSE)
		printf(COLOR_BLUE"UNIT TEST FOR FT_SSL\n"EOC);
	test_ft_itoa();
}