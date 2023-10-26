#!/bin/bash

# Check if one or more given numbers are prime.
# Example: ./are-prime.sh 12 13 19 20

# Check if an argument is provided
if [ $# -eq 0 ]; then
    echo "Please provide at least one positive integer."
    exit 1
fi


while [ $# -gt 0 ]; do
  # Check if the argument is a positive integer
  if [[ $1 =~ ^[1-9][0-9]*$ ]]; then
    wordcount=$(gfactor $1 | wc -w)
    if [ "$wordcount" -gt 2 ]; then
        echo "$1 is composite"
    else
        echo "$1 is prime"
    fi

  else
    echo "$1 is not a valid input. Please provide positive integers."
  fi

  shift

done

# Done
