#!/bin/bash

echo "enter number of terms"

read n

if [ $n -le 0 ]; then
	echo "error"
	exit 1
fi

a=0
b=1

echo -n "$a"

if [ $n -gt 1 ]; then
	echo -n " $b"
fi

i=3

while [ $i -le $n ]; do
	c=$((a + b))
	echo -n " $c"
	a=$b
	b=$c
	i=$((i + 1))
done
