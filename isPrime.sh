#!/bin/bash

echo "enter a number to check"

read n

if [ $n -le 1 ]; then
	echo "number is not prime"
	exit 1
fi

isPrime=1
i=2

while [ $((i * i)) -le $n ]; do
	if [ $((n % i)) -eq 0 ]; then
		isPrime=0
		break
	fi
done

if [ $isPrime -eq 0 ]; then
	echo "$n is not prime"
else 
	echo "$n is prime"
fi
