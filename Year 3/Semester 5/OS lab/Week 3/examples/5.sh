 #!/bin/bash

 read -p "Enter number: “ number
 fact=1
 i=1 
 while [ $i -le $number ]
 do
       fact=`expr $fact \* $i`
       i=`expr $i + 1`
 done

 echo "The factorial of $n is $fact"
