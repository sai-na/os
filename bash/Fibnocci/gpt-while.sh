#!/bin/bash

echo "Enter the number of terms to generate in Fibonacci series:"
read n

# initialize the first two terms of the series
a=0
b=1
count=0

echo "Fibonacci series up to $n terms:"

# loop to generate and print the series using while loop
while [ $count -lt $n ]
do
    echo -n "$a "
    fn=$((a + b))
    a=$b
    b=$fn
    count=$((count + 1))
done

echo
