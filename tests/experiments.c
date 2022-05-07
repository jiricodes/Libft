
# include <stdio.h>
typedef struct s_vec2 {
	int x, y;
}				t_vec2;

t_vec2 new(int x, int y) {
	t_vec2 new = {x, y};
	return (new);
}

t_vec2 sum(t_vec2 a, t_vec2 b) {
	t_vec2 sum = {a.x + b.x, a.y + b.y};
	return (sum);
}

void test(t_vec2 *a) {
	a->x += 1;
}

int main(int argc, char **argv) {

	t_vec2 a = new(1, 2);
	t_vec2 b = new(1, 2);
	t_vec2 c = sum(a, b);
	test(&a);
	printf("a: %d %d\n", a.x, a.y);
	printf("b: %d %d\n", b.x, b.y);
	printf("c: %d %d\n", c.x, c.y);
}