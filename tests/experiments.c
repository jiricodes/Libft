#include "libft_test.h"

void	*ft_memset_old(void *b, int c, size_t len);

int main(int argc, char **argv) {
	char	*mem;

	size_t len = abs(atoi(argv[1]));
	size_t iter = abs(atoi(argv[2]));

	clock_t start = 0;
	mem = (char *)malloc(sizeof(char) * len);
	for (int i = 0; i < iter + 10; i++) {
		if (i == 9)
			start = clock();
		ft_memset_old(mem, 0, len);
	}
	clock_t end = clock();
	double ft_time = (double)(end - start) / CLOCKS_PER_SEC;
	SPEEDRES_NAME(iter / ft_time, "ft_memset_old");

	for (int i = 0; i < iter + 10; i++) {
		if (i == 9)
			start = clock();
		ft_memset(mem, 0, len);
	}
	end = clock();
	double new_time = (double)(end - start) / CLOCKS_PER_SEC;
	SPEEDRES_NAME(iter / new_time, "ft_memset");
	SPEEDCMP((ft_time / new_time) * 100, "ft_memset_old");
}