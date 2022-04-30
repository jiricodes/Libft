# include <sys/types.h>
# include <stdint.h>
# include <stdio.h>
# include "v1_0_functions.h"
# include "libft_test.h"

// gcc; mem size = 10485760; 1000 loops; 25 warmup
// name				optimization		ops/sec
// v1_0_ft_memset		n/a				3.88
// v1_0_ft_memset		O1				28.96
// v1_0_ft_memset		O2				236.43
// v1_0_ft_memset		O3				236.69
// ft_memset			n/a				113.47
// ft_memset			O1				118.22
// ft_memset			O2				109.21
// ft_memset			O3				109.35
// memset				n/a				233.41
// memset				O1				236.26
// memset				O2				237.01
// memset				O3				237.61

int main(int argc, char **argv) {
	char *chars = argv[1];
	size_t len_chars = strlen(chars);

	char	*mem;

	CATEGORY("v1_0_ft_memset performance");

	size_t len = 104857600;
	size_t iter = 1000;

	clock_t start = 0;

	mem = (char *)malloc(sizeof(char) * len);

	for (int i = 0; i < iter + 25; i++) {
		if (i == 24)
			start = clock();
		v1_0_ft_memset(mem, chars[i % len_chars], len);
	}
	clock_t end = clock();
	double ft_time = (double)(end - start) / CLOCKS_PER_SEC;
	SPEEDRES_NAME(iter / ft_time, "v1_0_ft_memset");
	free(mem);
}