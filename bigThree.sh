echo "Enter three numbers"

read a b c

if [ $a -gt $b ] && [ $a -gt $c ]; then
	echo "$a is the gratest"
else if [ $b -gt $c ]; then 
	echo "$b is greatest"
else 
	echo "$c is greatest"
fi
fi

