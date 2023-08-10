# !/bin/bash

read -p "Enter number " num

if [ `expr $num % 2` -eq 0 ]
then
        echo "Even"
else
        echo "Odd"
fi





# !/bin/bash

read -p "Enter user name " user

if [ $user = "Alice" ]
then
        echo "Good morning"
elif [ $user = "Peter" ]
then
        echo "Good night"
fi





# !/bin/bash

read -p "Enter CGPA " cgpa

if [ $cgpa -eq 7 ]
then
        echo "Grade C"
elif [ $cgpa -eq 8 ]
then
        echo "Grade B"
elif [ $cgpa -eq 9 ]
then
        echo "Grade A"
elif [ $cgpa -eq 10 ]
then
        echo "Grade A+"
else
        echo "Grade D"
fi