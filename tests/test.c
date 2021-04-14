/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 22:09:50 by jnovotny          #+#    #+#             */
/*   Updated: 2021/04/14 02:51:27 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Includes ********************************************************************
*/

#include "test.h"

/*
** Globals *********************************************************************
*/

int run_speedtests = 0;
int time_limit = 10;

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

static void unittest_ft_atoi_speed()
{
    clock_t		end;
    int         ret;
    double      original = 0;
    double      original_sec;
    double      custom = 0;
    double      custom_sec;
    clock_t      start;

    printf("Speed in ~%ds\r", 2*time_limit);
    fflush(stdout);
    start = clock();
    end = start;
	while ((double)(end - start) / CLOCKS_PER_SEC < time_limit)
	{
        ret = atoi("");
        ret = atoi("1");
        ret = atoi("a1");
        ret = atoi("--1");
        ret = atoi("++1");
        ret = atoi("+1");
        ret = atoi("-1");
        ret = atoi("0");
        ret = atoi("+42lyon");
        ret = atoi("+101");
        ret = atoi("2147483647");
        ret = atoi("-2147483648");
        ret = atoi("-+42");
        ret = atoi("+-42");
        ret = atoi("+\t42");
        ret = atoi("-\t42");
        ret = atoi("1\t42");
        ret = atoi("-1\t42");
        ret = atoi("\t42");
        ret = atoi("\r42");
        ret = atoi("\f42");
        ret = atoi("   \t42");
        end = clock();
        original += 22;
    }
    original_sec = ((double)(end - start) / CLOCKS_PER_SEC);
    // printf("ATOI\t\t%12.0f calls in %.2f (%f CPS)\n", original, original_sec, original / original_sec);

    start = clock();
    end = start;
	while ((double)(end - start) / CLOCKS_PER_SEC < time_limit)
	{
        ret = ft_atoi("");
        ret = ft_atoi("1");
        ret = ft_atoi("a1");
        ret = ft_atoi("--1");
        ret = ft_atoi("++1");
        ret = ft_atoi("+1");
        ret = ft_atoi("-1");
        ret = ft_atoi("0");
        ret = ft_atoi("+42lyon");
        ret = ft_atoi("+101");
        ret = ft_atoi("2147483647");
        ret = ft_atoi("-2147483648");
        ret = ft_atoi("-+42");
        ret = ft_atoi("+-42");
        ret = ft_atoi("+\t42");
        ret = ft_atoi("-\t42");
        ret = ft_atoi("1\t42");
        ret = ft_atoi("-1\t42");
        ret = ft_atoi("\t42");
        ret = ft_atoi("\r42");
        ret = ft_atoi("\f42");
        ret = ft_atoi("   \t42");
        end = clock();
        custom += 22;
    }
    custom_sec = ((double)(end - start) / CLOCKS_PER_SEC);
    // printf("FT_ATOI\t\t%12.0f calls in %.2f (%f CPS)\n", custom, custom_sec, custom / custom_sec);
    double percentage = ((custom / custom_sec) / (original / original_sec)) * 100;
    SPEED_RESULT(percentage);
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
    if (run_speedtests)
        unittest_ft_atoi_speed();
}

/*
** ft_isalnum ******************************************************************
*/

static void unittest_ft_isalnum_one(char *str, int *current, int total)
{
	int ret;
    int expected;

    while (*str)
    {
        *current += 1;
        ret = ft_isalnum(*str);
        expected = isalnum(*str);
        assert((!ret) == (!expected));
        STATUS(*current, total);
        str++;
    }
}

static void unittest_ft_isalnum_speed()
{
    clock_t		end;
    int         ret;
    double      original = 0;
    double      original_sec;
    double      custom = 0;
    double      custom_sec;
    clock_t      start;
    char    *test_string = " !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[|]^_`abcdefghijklmnopqrstuvwxyz{|}~";
    char    *ptr;
    int     step = strlen(test_string);

    printf("Speed in ~%ds\r", 2*time_limit);
    fflush(stdout);
    start = clock();
    end = start;
	while ((double)(end - start) / CLOCKS_PER_SEC < time_limit)
	{
        ptr = test_string;
        while (*ptr)
        {
            ret = isalnum(*ptr);
            ptr++;
        }
        end = clock();
        original += step;
    }
    original_sec = ((double)(end - start) / CLOCKS_PER_SEC);
    // printf("isalnum\t\t%12.0f calls in %.2f (%f CPS)\n", original, original_sec, original / original_sec);

    start = clock();
    end = start;
	while ((double)(end - start) / CLOCKS_PER_SEC < time_limit)
	{
        ptr = test_string;
        while (*ptr)
        {
            ret = ft_isalnum(*ptr);
            ptr++;
        }
        end = clock();
        custom += step;
    }
    custom_sec = ((double)(end - start) / CLOCKS_PER_SEC);
    // printf("ft_isalnum\t\t%12.0f calls in %.2f (%f CPS)\n", custom, custom_sec, custom / custom_sec);
    double percentage = ((custom / custom_sec) / (original / original_sec)) * 100;
    SPEED_RESULT(percentage);
}

static void	unittest_ft_isalnum()
{

    char    *test_string = " !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[|]^_`abcdefghijklmnopqrstuvwxyz{|}~";
	int current = 0;
	int total = strlen(test_string);
    
    CATEGORY("ft_isalnum");
    unittest_ft_isalnum_one(test_string, &current, total);
    if (run_speedtests)
        unittest_ft_isalnum_speed();
}

/*
** ft_isalpha ******************************************************************
*/

static void unittest_ft_isalpha_one(char *str, int *current, int total)
{
	int ret;
    int expected;

    while (*str)
    {
        *current += 1;
        ret = ft_isalpha(*str);
        expected = isalpha(*str);
        assert((!ret) == (!expected));
        STATUS(*current, total);
        str++;
    }
}

static void unittest_ft_isalpha_speed()
{
    clock_t		end;
    int         ret;
    double      original = 0;
    double      original_sec;
    double      custom = 0;
    double      custom_sec;
    clock_t      start;
    char    *test_string = " !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[|]^_`abcdefghijklmnopqrstuvwxyz{|}~";
    char    *ptr;
    int     step = strlen(test_string);

    printf("Speed in ~%ds\r", 2*time_limit);
    fflush(stdout);
    start = clock();
    end = start;
	while ((double)(end - start) / CLOCKS_PER_SEC < time_limit)
	{
        ptr = test_string;
        while (*ptr)
        {
            ret = isalpha(*ptr);
            ptr++;
        }
        end = clock();
        original += step;
    }
    original_sec = ((double)(end - start) / CLOCKS_PER_SEC);
    // printf("isalnum\t\t%12.0f calls in %.2f (%f CPS)\n", original, original_sec, original / original_sec);

    start = clock();
    end = start;
	while ((double)(end - start) / CLOCKS_PER_SEC < time_limit)
	{
        ptr = test_string;
        while (*ptr)
        {
            ret = ft_isalpha(*ptr);
            ptr++;
        }
        end = clock();
        custom += step;
    }
    custom_sec = ((double)(end - start) / CLOCKS_PER_SEC);
    // printf("ft_isalnum\t\t%12.0f calls in %.2f (%f CPS)\n", custom, custom_sec, custom / custom_sec);
    double percentage = ((custom / custom_sec) / (original / original_sec)) * 100;
    SPEED_RESULT(percentage);
}

static void	unittest_ft_isalpha()
{

    char    *test_string = " !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[|]^_`abcdefghijklmnopqrstuvwxyz{|}~";
	int current = 0;
	int total = strlen(test_string);
    
    CATEGORY("ft_isalpha");
    unittest_ft_isalpha_one(test_string, &current, total);
    if (run_speedtests)
        unittest_ft_isalpha_speed();
}

/*
** ft_isprint ******************************************************************
*/

static void unittest_ft_isprint_one(int c, int *current, int total)
{
	int ret;
    int expected;

    *current += 1;
    ret = ft_isprint(c);
    expected = isprint(c);
    assert((!ret) == (!expected));
    STATUS(*current, total);
}

static void unittest_ft_isprint_speed()
{
    clock_t		end;
    int         ret;
    double      original = 0;
    double      original_sec;
    double      custom = 0;
    double      custom_sec;
    clock_t      start;
    int         i;

    printf("Speed in ~%ds\r", 2*time_limit);
    fflush(stdout);
    start = clock();
    end = start;
	while ((double)(end - start) / CLOCKS_PER_SEC < time_limit)
	{
        i = 0;
        while (i < 128)
        {
            ret = isprint(i);
            i++;
        }
        end = clock();
        original += 128;
    }
    original_sec = ((double)(end - start) / CLOCKS_PER_SEC);
    // printf("isalnum\t\t%12.0f calls in %.2f (%f CPS)\n", original, original_sec, original / original_sec);

    start = clock();
    end = start;
	while ((double)(end - start) / CLOCKS_PER_SEC < time_limit)
	{
        i = 0;
        while (i < 128)
        {
            ret = ft_isprint(i);
            i++;
        }
        end = clock();
        custom += 128;
    }
    custom_sec = ((double)(end - start) / CLOCKS_PER_SEC);
    // printf("ft_isalnum\t\t%12.0f calls in %.2f (%f CPS)\n", custom, custom_sec, custom / custom_sec);
    double percentage = ((custom / custom_sec) / (original / original_sec)) * 100;
    SPEED_RESULT(percentage);
}

static void	unittest_ft_isprint()
{

    int c = -1;
	int current = 0;
	int total = 128;
    
    CATEGORY("ft_isprint");
    while (++c < 128)
        unittest_ft_isprint_one(c, &current, total);
    if (run_speedtests)
        unittest_ft_isprint_speed();
}

/*
** ft_itoa_base ****************************************************************
*/

static void unittest_ft_itoa_base_one(int value, int base, char *expected, int *current, int total)
{
	char    *ret;

    *current += 1;
    ret = ft_itoa_base(value, base, 1);
    // printf("%s\n", ret);
    assert((ret == NULL && expected == NULL) || !strcmp(ret, expected));
    free(ret);
    // STATUS(*current, total);
}

static void unittest_ft_itoa_base_speed()
{
    clock_t		end;
    char        *ret;
    double      original = 0;
    double      original_sec;
    double      custom = 0;
    double      custom_sec;
    clock_t      start;
    int         i;

    printf("Speed in ~%ds\r", 2*time_limit);
    fflush(stdout);
    start = clock();
    end = start;
	while ((double)(end - start) / CLOCKS_PER_SEC < time_limit)
	{
        ret = _ft_itoa_base(INT32_MAX, 10, 1);
        free (ret);
        ret = _ft_itoa_base(INT32_MIN, 10, 1);
        free (ret);
        ret = _ft_itoa_base(INT32_MAX, 2, 1);
        free (ret);
        ret = _ft_itoa_base(INT32_MAX, 3, 1);
        free (ret);
        ret = _ft_itoa_base(INT32_MAX, 4, 1);
        free (ret);
        ret = _ft_itoa_base(INT32_MAX, 5, 1);
        free (ret);
        ret = _ft_itoa_base(INT32_MAX, 6, 1);
        free (ret);
        ret = _ft_itoa_base(INT32_MAX, 7, 1);
        free (ret);
        ret = _ft_itoa_base(INT32_MAX, 8, 1);
        free (ret);
        ret = _ft_itoa_base(INT32_MAX, 9, 1);
        free (ret);
        ret = _ft_itoa_base(INT32_MAX, 11, 1);
        free (ret);
        ret = _ft_itoa_base(INT32_MAX, 12, 1);
        free (ret);
        ret = _ft_itoa_base(INT32_MAX, 13, 1);
        free (ret);
        ret = _ft_itoa_base(INT32_MAX, 14, 1);
        free (ret);
        ret = _ft_itoa_base(INT32_MAX, 15, 1);
        free (ret);
        ret = _ft_itoa_base(INT32_MAX, 16, 1);
        free (ret);
        end = clock();
        original += 16;
    }
    original_sec = ((double)(end - start) / CLOCKS_PER_SEC);
    // printf("_ft_itoa_base\t\t%12.0f calls in %.2f (%f CPS)\n", original, original_sec, original / original_sec);

    start = clock();
    end = start;
	while ((double)(end - start) / CLOCKS_PER_SEC < time_limit)
	{
        ret = ft_itoa_base(INT32_MAX, 10, 1);
        free (ret);
        ret = ft_itoa_base(INT32_MIN, 10, 1);
        free (ret);
        ret = ft_itoa_base(INT32_MAX, 2, 1);
        free (ret);
        ret = ft_itoa_base(INT32_MAX, 3, 1);
        free (ret);
        ret = ft_itoa_base(INT32_MAX, 4, 1);
        free (ret);
        ret = ft_itoa_base(INT32_MAX, 5, 1);
        free (ret);
        ret = ft_itoa_base(INT32_MAX, 6, 1);
        free (ret);
        ret = ft_itoa_base(INT32_MAX, 7, 1);
        free (ret);
        ret = ft_itoa_base(INT32_MAX, 8, 1);
        free (ret);
        ret = ft_itoa_base(INT32_MAX, 9, 1);
        free (ret);
        ret = ft_itoa_base(INT32_MAX, 11, 1);
        free (ret);
        ret = ft_itoa_base(INT32_MAX, 12, 1);
        free (ret);
        ret = ft_itoa_base(INT32_MAX, 13, 1);
        free (ret);
        ret = ft_itoa_base(INT32_MAX, 14, 1);
        free (ret);
        ret = ft_itoa_base(INT32_MAX, 15, 1);
        free (ret);
        ret = ft_itoa_base(INT32_MAX, 16, 1);
        free (ret);
        end = clock();
        custom += 16;
    }
    custom_sec = ((double)(end - start) / CLOCKS_PER_SEC);
    // printf("ft_itoa_base\t\t%12.0f calls in %.2f (%f CPS)\n", custom, custom_sec, custom / custom_sec);
    double percentage = ((custom / custom_sec) / (original / original_sec)) * 100;
    SPEED_RESULT(percentage);
}

static void	unittest_ft_itoa_base()
{

	int current = 0;
	int total = 17;
    char *expect_null;
    
    CATEGORY("ft_itoa_base");
    expect_null = NULL;
    unittest_ft_itoa_base_one(INT32_MAX, 10, "2147483647", &current, total);
    unittest_ft_itoa_base_one(INT32_MIN, 10, "-2147483648", &current, total);
    unittest_ft_itoa_base_one(INT32_MAX, 2, "1111111111111111111111111111111", &current, total);
    unittest_ft_itoa_base_one(INT32_MAX, 3, "12112122212110202101", &current, total);
    unittest_ft_itoa_base_one(INT32_MAX, 4, "1333333333333333", &current, total);
    unittest_ft_itoa_base_one(INT32_MAX, 5, "13344223434042", &current, total);
    unittest_ft_itoa_base_one(INT32_MAX, 6, "553032005531", &current, total);
    unittest_ft_itoa_base_one(INT32_MAX, 7, "104134211161", &current, total);
    unittest_ft_itoa_base_one(INT32_MAX, 8, "17777777777", &current, total);
    unittest_ft_itoa_base_one(INT32_MAX, 9, "5478773671", &current, total);
    unittest_ft_itoa_base_one(INT32_MAX, 11, "A02220281", &current, total);
    unittest_ft_itoa_base_one(INT32_MAX, 12, "4BB2308A7", &current, total);
    unittest_ft_itoa_base_one(INT32_MAX, 13, "282BA4AAA", &current, total);
    unittest_ft_itoa_base_one(INT32_MAX, 14, "1652CA931", &current, total);
    unittest_ft_itoa_base_one(INT32_MAX, 15, "C87E66B7", &current, total);
    unittest_ft_itoa_base_one(INT32_MAX, 16, "7FFFFFFF", &current, total);
    unittest_ft_itoa_base_one(INT32_MAX, 17, expect_null, &current, total);
    unittest_ft_itoa_base_one(0, 13, "0", &current, total);
    if (run_speedtests)
        unittest_ft_itoa_base_speed();
}

/*
** Main ************************************************************************
*/

static void process_args(int cnt, char **args)
{
    int i = 0;
    while (i  < cnt)
    {
        switch (args[i][1])
        {
        case 't':
            if (i + 1 < cnt)
            {
                time_limit = atoi(args[i + 1]);
                run_speedtests = 1;
                i++;
            }
            break;
        
        case 's':
            run_speedtests = 1;
            break;

        default:
            printf("Unknown argument: %s\n", args[i]);
            break;
        }
        i++;
    }
}

int			main(int argc, char **argv)
{
    if (argc > 1)
        process_args(argc - 1, argv + 1);
	if (VERBOSE)
		printf(COLOR_BLUE"UNIT TEST FOR LIBFT\n"EOC);
    // unittest_ft_atoi();
    // unittest_ft_isalnum();
    // unittest_ft_isalpha();
    // unittest_ft_isprint();
    unittest_ft_itoa_base();
    return (0);
}
