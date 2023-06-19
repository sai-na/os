echo "enter the first number"
read a
echo "enter the second number"
read b
echo "enter the third number"
read c

if test $a -gt $b && test $a -gt $c
then
	echo $a is the largest number
elif test $b -gt $a && test $b -gt $c
then
	echo $b is the largest number
else
	echo $c is the largest number
fi
