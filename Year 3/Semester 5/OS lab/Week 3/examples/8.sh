#!/bin/bash

clear
val1=10

if ((val1 ** 2 > 90)); then
    echo "inside if"
    ((val2 = val1 ** 2))
    echo $val2
else
    ((val2 = val1 ** 2))
    echo "The square of $val1 is $val2"
fi
((val3 = val2 * 4))
echo "The final solution is $val3"
