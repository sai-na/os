#!/bin/bash

echo "Enter the number of terms to generate in Fibonacci series:"
read n

# initialize the first two terms of the series
a=0
b=1

echo "Fibonacci series up to $n terms:"

# loop to generate and print the series
for (( i=0; i<n; i++ ))
do
    echo -n "$a "
    fn=$((a + b))
    a=$b
    b=$fn
done

echo
