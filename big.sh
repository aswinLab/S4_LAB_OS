#!/bin/bash

echo "enter first number"
read a
echo "enter the second number"
read b



if [ $a -gt $b ]; then
	echo "$a is greatest"
else 
	echo "$b is greatest"
fi
