#! /usr/bin/python3

import random
import string

def main():
	pool = string.ascii_letters + string.digits + "\t "
	for i in range(0, 1000):
		l = random.randint(1, 1024)
		ran = ''.join(random.choices(pool, k = l))
		c = random.choice(pool)
		print(f"char	*test{i:04} = \"{ran}\";")
		print(f"test_ft_memchr_one(test{i:04}, \'{c}\', {l}, &current, total);")

if __name__ == '__main__':
	main()