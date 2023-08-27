# !/bin/bash

echo "1) List of files"
echo "2) List of all files"
echo "3) Delete files"

while [ 1 ]; do
    read -p "Enter option " op
    case $op in
    1) echo "$(ls)" ;;
    2) echo "$(ls -a)" ;;
    3)
        read -p "Enter file name " f
        $(rm $f)
        ;;
    *) echo "Invalid choice" ;;
    esac

    read -p "Do you wish to quit? " c
    if [[ $c == "y" ]]; then
        exit
    fi
done
