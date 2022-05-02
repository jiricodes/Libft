/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_test_main.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 12:58:07 by jnovotny          #+#    #+#             */
/*   Updated: 2022/05/02 11:57:59 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Includes ********************************************************************
*/

#include "libft_test.h"

/*
** main ************************************************************************
*/

int main(int argc, char **argv) {
	if (argc != 2) {
		printf("Wrong number of arguments - usage: ./%s <file_to_test_gnl>\n", argv[0]);
		exit(1);
	}
	if (VERBOSE)
		printf(COLOR_BLUE"UNIT TEST FOR LIBFT\n"EOC);

	test_ft_memset();
	test_ft_bzero();
	test_ft_memcpy();
	test_ft_memccpy();
	fflush(NULL);
}