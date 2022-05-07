#! /usr/bin/python3

import random
import string

def main():
	pool = string.ascii_letters + string.digits + "\t "
	for i in range(0, 1000):
		l = random.randint(1, 512)
		ran_a = ''.join(random.choices(pool, k = l))
		print(f"char	*test{i:04} = \"{ran_a}\";")
		print(f"test_ft_strlen_one(test{i:04}, &current, total);")

if __name__ == '__main__':
	main()