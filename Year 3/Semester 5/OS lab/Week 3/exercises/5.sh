# !/bin/bash

read -p "Enter file name " f
read -p "Number of lines " num
read -p "Enter head(h) or tail(t) " ht

if [ -f f ]; then
    if [[ $ht == "h" ]]; then
        head -$num $f
    else
        tail -$num $f
    fi
fi
