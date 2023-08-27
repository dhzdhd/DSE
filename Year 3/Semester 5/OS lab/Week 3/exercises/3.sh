# !/bin/bash

read -p "Enter number " n
num=$n
buf=0

while [ $num -gt 0 ]; do
    rem=$(expr $num % 10)
    num=$(expr $num / 10)
    buf=$(expr $buf \* 10 + $rem)
done

echo "$buf"
