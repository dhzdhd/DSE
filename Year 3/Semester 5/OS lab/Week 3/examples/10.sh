#!/bin/bash

read -p "Enter value of variable:" x
case $x in
    dozen) echo "12";;
    score) echo "20"
esac
