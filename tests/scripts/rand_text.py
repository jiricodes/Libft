#! /usr/bin/python3

import random
import string

def main():
	for _ in range(1000):
		l = random.randint(1, 10240)
		print(f"test_ft_bzero_one({l}, &current, total);")

if __name__ == '__main__':
	main()