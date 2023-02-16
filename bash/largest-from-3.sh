echo "Enter the number a"
read a
echo "Enter the number b"
read b
echo "Enter the number c"
read c

if test $a -gt $b && test $a -gt $c
then 
	echo "$a is the largest number" 
elif test $b -gt $a && test $b -gt $c
then 
	echo "$b is the largest number"
else
	echo "$c is the largest number"
	fi
