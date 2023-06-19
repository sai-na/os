echo "enter first number"
read a
echo "enter second number"
read b

echo "Choose an option:"
echo "1. Addition"
echo "2. Subtraction"
echo "3. Multiplication"
echo "4. Division"

read c

case $c in
 1) echo Sum: $(expr $a + $b);;
 2) echo Difference: $(expr $a - $b);;
 3) echo Product: $(expr $a \* $b);;
 4) echo Quotient: $(expr $a / $b);;
 *) echo Invalid choice
esac
