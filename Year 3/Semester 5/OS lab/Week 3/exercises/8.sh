# !/bin/bash
read -p "Enter first string " s1
read -p "Enter second string " s2

if [[ s1 == "" ]] || [[ s2 == "" ]]; then
    echo "String is empty"
    exit
fi

if [[ s1 == s2 ]]; then
    echo "Equal"
else
    echo "Not equal"
fi
