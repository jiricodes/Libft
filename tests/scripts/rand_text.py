#! /usr/bin/python3

import random
import string

def main():
	for _ in range(1000):
		l = random.randint(1, 10240)
		n = random.randrange(0, 255)
		print(f"test_ft_memset_one({l}, {n}, &current, total);")

if __name__ == '__main__':
	main()