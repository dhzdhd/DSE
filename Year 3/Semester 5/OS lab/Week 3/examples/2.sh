 #!/bin/bash
 if [ `who | grep Mark | wc -l` -ge 1 -a `whoami` != “Bill” ]
 then
        echo “Who else but Mark is loading down the machine again!“
 else
        echo "All is well!“
 fi
