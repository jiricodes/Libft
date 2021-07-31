#!/bin/bash

if (( $# < 2 ))
then
	echo "Scripts requires 2 arguments - printf log and ft_printf log"
	exit 1
fi

p=$1
f=$2

pr=$(tail -n 1 $p | awk '{print $2}')
fr=$(tail -n 1 $f | awk '{print $2}')
prc=$(printf %.3f $(echo "scale=6;($fr / $pr) * 100" | bc))
printf "\t\t%12f %%\n" $prc