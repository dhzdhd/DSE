# !/bin/bash

user=`whoami`
numusers=`who | wc -l`
echo "Hi $user! There are $numusers logged on."





# !/bin/bash

i=2
i=`expr \( $i \* 3 \)`
echo "$i"

echo "Enter height of rectangle: "
read height
echo "Enter width of rectangle: "
read width
area=`expr $height \* $width`
echo "Area is $area"





# !/bin/bash

echo "Hello world"





# !/bin/bash

a=6
b=6
if [ $a -eq $b ]
then
        echo "EQUAL!"
fi





# !/bin/bash

echo "Enter name: "
read name
echo "How many friends do you have? "
read number
echo "$name has \$$number friends!"





# !/bin/bash

clear
echo "Options"
echo "1. date"
echo "2. who"
echo "3. ls"
echo "4. pwd"

read option

if [ $option -eq 1 ]
then
        echo `date`
elif [ $option -eq 2 ]
then
        echo `who`
elif [ $option -eq 3 ]
then
        echo `ls`
elif [ $option -eq 4 ]
then
        echo `pwd`
fi





# !/bin/bash

number=25
name="Jeff Bezos"
echo "$number $name"