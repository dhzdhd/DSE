# !/bin/bash

read -p "Enter first " a
read -p "Enter second " b
read -p "Enter third " c

echo "Largest is"
if [ $a -ge $b ]; then
    if [ $a -ge $c ]; then
        echo "$a"
    else
        echo "$c"
    fi
else
    if [ $b -ge $c ]; then
        echo "$b"
    else
        echo "$c"

    fi
fi
