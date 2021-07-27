#!/bin/bash
n=$1

for i in `seq 0 $n`
do
	x=$(python -S -c "import random; print random.randrange(0,18446744073709551615)")
	echo -e "num = ${x}U;"
	echo -e "test_ft_ultoa_one(num, \"$x\", &current, total);"
	echo -e "test_ft_ultoa_one_buf(num, \"$x\", &current, total);"
done