#include "libft_test.h"

static void test_ft_memchr_one(void *s, int c, size_t len, int *current, int total) {
	
	*current += 1;
	unsigned char *ft = (unsigned char *)ft_memchr(s, c, len);
	unsigned char *org = (unsigned char *)memchr(s, c, len);
	assert(org == ft);
	STATUS(*current, total);
}


#ifdef SPEEDTEST
static void test_ft_memchr_speed()
{
	char	*s;

	CATEGORY("ft_memchr performance");

	size_t len = 1048576;
	size_t iter = 1000;

	clock_t start = 0;
	s = (char *)malloc(sizeof(char) * len);
	memset(s, 'x', len);
	s[(len / 4) * 3] = 'Z';
	for (int i = 0; i < iter + 25; i++) {
		if (i == 24)
			start = clock();
		memchr(s, 'Z', len);
	}
	clock_t end = clock();
	double org_time = (double)(end - start) / CLOCKS_PER_SEC;
	SPEEDRES_NAME(iter / org_time, "memchr");

	for (int i = 0; i < iter + 25; i++) {
		if (i == 24)
			start = clock();
		ft_memchr(s, 'Z', len);
	}
	end = clock();
	double ft_time = (double)(end - start) / CLOCKS_PER_SEC;
	SPEEDRES_NAME(iter / ft_time, "ft_memchr");
	SPEEDCMP((org_time / ft_time) * 100, "memchr");
	free(s);
}
#endif // SPEEDTEST

void test_ft_memchr() {
	int current = 0;
	int total = 1001;

	CATEGORY("ft_memchr");
	char *simple = "x";
	test_ft_memchr_one(simple, 'x', 2, &current, total);
	char *no_a = "xxxx";
	test_ft_memchr_one(no_a, 'a', 2, &current, total);

#ifdef SPEEDTEST
	test_ft_memchr_speed();
#endif // SPEEDTEST
}
