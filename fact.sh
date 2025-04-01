#!/bin/bash

echo "enter a non negative number"

read a

echo "Factorial :"

if [ $a -lt 0 ]; then
	echo "wrong wrong, heh"
	exit 1
fi

fact=1
i=1

while [ $i -le $a ]; do
	fact=$((fact * i))
	i=$((i + 1))
done

echo "$fact"






