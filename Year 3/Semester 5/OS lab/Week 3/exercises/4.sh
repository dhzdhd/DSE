# !/bin/bash

read -p "Enter number " num
sum=0

while [ $num -gt 0 ]; do
    sum=$(expr $sum + $num % 10)
    num=$(expr $num / 10)
done

echo "$sum"
