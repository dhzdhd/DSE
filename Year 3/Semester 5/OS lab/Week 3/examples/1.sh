 
#!/bin/bash
if [ -f letter1 ] #letter1 is the filename
then
      echo "We have found the evidence, here it is!"
      cat letter1
else
      echo "Keep looking!"
fi