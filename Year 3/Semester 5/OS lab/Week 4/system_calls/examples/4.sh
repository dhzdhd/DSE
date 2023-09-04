#!/bin/bash

echo "testing wait command1" &
process_id=$!

echo "testing wait command2" &
wait $process_id

echo Job 1 exited with status $?
wait $!

echo Job 2 exited with status $?

# testing wait command1
# testing wait command2
# Job 1 exited with status 0
# Job 2 exited with status 0
