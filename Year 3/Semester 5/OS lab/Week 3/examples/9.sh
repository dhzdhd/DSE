#!/bin/bash

name="andrea"
if [[ name == p?? ]]; then
    echo "Hello $USER"
else
    echo "System detects a new user $name"
fi
