# !/bin/bash

for f in "$@"; do            # Command line args
    if [ -e "$f" ]; then     # If exists
        if [ -f "$f" ]; then # If file
            echo "$f is an ordinary file."
            echo "Content of the file:"
            cat "$f"

            if [ -x "$f" ]; then # If executable
                echo "$f has execute permission."
            else
                echo "$f does not have execute permission."
            fi

        elif [ -d "$f" ]; then # If dir
            echo "$f is a directory."

            num_files=$(ls -1 "$f" | wc -l)
            echo "Number of files in the directory: $num_files"
        fi

    else
        echo "$f does not exist."
    fi
done
