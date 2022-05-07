#! /usr/bin/python3

import random
import string

def main():
	pool = string.ascii_letters + string.digits + "\t "
	for i in range(0, 200):
		l = random.randint(1, 512)
		ran_a = ''.join(random.choices(pool, k = l))
		print(f"char	*test{i:04} = \"{ran_a}\";")
		n = random.randint(1,l)
		print(f"test_ft_strncpy_one(test{i:04}, {n}, &current, total);")
		n = random.randint(1,l)
		print(f"test_ft_strncpy_one(test{i:04}, {n}, &current, total);")
		n = random.randint(l, l + l // 2)
		print(f"test_ft_strncpy_one(test{i:04}, {n}, &current, total);")
		n = random.randint(l, l + l // 2)
		print(f"test_ft_strncpy_one(test{i:04}, {n}, &current, total);")

if __name__ == '__main__':
	main()