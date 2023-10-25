#!/bin/bash

# reads an argument and checks whether the number given is prime
# run the script with "time ./is-prime.sh 12345" to measure the time

# Check if an argument is provided
if [ $# -ne 1 ]; then
    echo "Please provide a positive integer."
    exit 1
fi

# Check if the argument is a positive integer
if ! [[ $1 =~ ^[1-9][0-9]*$ ]]; then
    echo "Invalid input. Please provide a positive integer."
    exit 1
fi

wordcount=$(gfactor $1 | wc -w)

if [ "$wordcount" -gt 2 ]; then
    echo "$1 is composite"
else
    echo "$1 is prime"
fi

# Done
