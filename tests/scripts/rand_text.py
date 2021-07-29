#! /usr/bin/python3

import random
import string

def main():
	for i in range(1000):
		l = random.randint(5, 32)
		sentence = ''.join(random.choices(string.ascii_letters + string.digits + " ", k=l))
		# letter = random.choice(sentence)
		# words = sentence.split(letter)
		# print(f"char *expected{i}[] = {{", end="")
		# for n, w in enumerate(words):
		# 	if n != len(words) - 1:
		# 		if (w == ""):
		# 			continue
		# 		print(f"\"{w}\", ", end="")
		# 	else:
		# 		if (w == ""):
		# 			print(f"NULL}}; ")
		# 		else:
		# 			print(f"\"{w}\", NULL}}; ")
		print(f"test_ft_atoi_one(\"{sentence}\", atoi(\"{sentence}\"), &current, total);")

		n = random.randrange(-2147483648, 2147483647)
		print(f"test_ft_atoi_one(\"{n}\", {n}, &current, total);")

if __name__ == '__main__':
	main()