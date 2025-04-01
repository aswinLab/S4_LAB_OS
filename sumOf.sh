#!/bin/bash

echo "enter the limit"

read n

sum=0
i=0
while [ $i -le $n ]; do
	sum=$((sum + i))
	i=$((i + 1))
done

echo "sum of $n numbers : $sum" 
