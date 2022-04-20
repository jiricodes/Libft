# include <sys/types.h>
# include <stdint.h>
# include <stdio.h>

int main(int argc, char **argv) {
	printf("%zu\n", sizeof(uintptr_t));
}