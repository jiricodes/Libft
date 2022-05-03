# include <sys/types.h>
# include <stdint.h>
# include <stdio.h>
#include <string.h>
#include <stdlib.h>
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	register unsigned char			*dst_ptr;
	register const unsigned char	*src_ptr;

	if (dst == src || !n)
		return (dst);
	dst_ptr = dst;
	src_ptr = src;
	while (n--)
	{
		*dst_ptr++ = *src_ptr++;
	}
	return (dst);
}

static void *ft_memcpy_rev(void *dst, const void *src, size_t n)
{
	register unsigned char			*dst_ptr;
	register const unsigned char	*src_ptr;

	printf("memmove backward\n");
	dst_ptr = dst;
	src_ptr = src;
	dst_ptr += (n - 1);
	src_ptr += (n - 1);
	while (n--)
	{
		*dst_ptr-- = *src_ptr--;
	}
	return (dst);
}

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	if (dst == src || !n)
		return (dst);
	if (src < dst && src + n > dst)
	{
		return (ft_memcpy_rev(dst, src, n));
	}
	else
	{
		return (ft_memcpy(dst, src, n));
	}
}

int main(int argc, char **argv) {
	char *chars = argv[1];
	size_t len = strlen(chars);
	char *dst = (char *)malloc(len + 3);
	memset(dst, 'x', len + 3);
	dst[len + 2] = '\0';
	size_t dlen = strlen(chars);

	printf("%zu: %s\n", len, chars);
	printf("%zu: %s\n", dlen, dst);

	ft_memcpy_rev(dst, chars, 5);
	printf("%zu: %s\n", dlen, dst);

}