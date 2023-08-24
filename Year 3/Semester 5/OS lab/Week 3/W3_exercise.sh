# !/bin/bash

# Sagar Kumar 210968002

read -p "Enter first " a
read -p "Enter second " b
read -p "Enter third " c

echo "Largest is"
if [ $a -ge $b ]
then
        if [ $a -ge $c ]
        then
                echo "$a"
        else
                echo "$c"
        fi
else
        if [ $b -ge $c ]
        then
                echo "$b"
        else
                echo "$c"
        fi
fi




# !/bin/bash

a=5
while [ $a -ge 1 ]
do
        echo "$a"
        a=`expr $a - 1`
done





# !/bin/bash

read -p "Enter number " n
num=$n
buf=0

while [ $num -gt 0 ]
do
        rem=`expr $num % 10`
        num=`expr $num / 10`
        buf=`expr $buf \* 10 + $rem`
done

echo "$buf"






# !/bin/bash

read -p "Enter number " num
sum=0

while [ $num -gt 0 ]
do
        sum=`expr $sum + $num % 10`
        num=`expr $num / 10`
done

echo "$sum"








# !/bin/bash

read -p "Enter file name " f
read -p "Number of lines " num
read -p "Enter head(h) or tail(t) " ht

if [ -f f ]
then
        if [[ $ht == "h" ]]
        then
                head -$num $f
        else
                tail -$num $f
        fi
fi








# !/bin/bash

echo "1) List of files"
echo "2) List of all files"
echo "3) Delete files"

while [ 1 ]
do
        read -p "Enter option " op
        case $op in
                1) echo "`ls`" ;;
                2) echo "`ls -a`" ;;
                3) read -p "Enter file name " f
                   `rm $f` ;;
                *) echo "Invalid choice"
        esac

        read -p "Do you wish to quit? " c
        if [[ $c == "y" ]]
        then
                exit
        fi
done












# !/bin/bash

read -p "Enter file name " file
`chmod u+x $file`









# !/bin/bash
read -p "Enter first string " s1
read -p "Enter second string " s2

if [[ s1 == "" ]] || [[ s2 == "" ]]
then
        echo "String is empty"
        exit
fi


if [[ s1 == s2 ]]
then
        echo "Equal"
else
        echo "Not equal"
fi







# !/bin/bash

read -p "Enter file" f

if [ -f $f ] || [ -d $f ]
then
        if [ -f $f ]
        then
                `cat $f`

        else

        fi
else
        echo "Does not exist"
fi
