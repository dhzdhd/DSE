# !/bin/bash

read -p "Enter file" f

if [ -f $f ] || [ -d $f ]; then
    if [ -f $f ]; then
        $(cat $f)

    else

    fi
else
    echo "Does not exist"
fi
