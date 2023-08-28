# !/bin/bash

for f in "$@"; do
    if [ -e "$f" ]; then
        if [ -f "$f" ]; then
            echo "$f is an ordinary file."
            echo "Content of the file:"
            cat "$f"

            if [ -x "$f" ]; then
                echo "$f has execute permission."
            else
                echo "$f does not have execute permission."
            fi

        elif [ -d "$f" ]; then
            echo "$f is a directory."

            num_files=$(ls -1 "$f" | wc -l)
            echo "Number of files in the directory: $num_files"
        fi

    else
        echo "$f does not exist."
    fi
done
