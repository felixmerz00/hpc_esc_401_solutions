#!/bin/bash

# Check the number in a given range are prime.
# Example ./range-prime.sh 40 50


# Check if an argument is provided
if [ $# -nq 2 ]; then
    echo "Please provide two positive integers as boundaries for your range."
    exit 1
fi

# Check if the argument is a positive integer
if ! [[ $1 =~ ^[1-9][0-9]*$ ]] || ! [[ $2 =~ ^[1-9][0-9]*$ ]]; then
    echo "Invalid input. Please provide positive integers."
    exit 1
fi

range=$(seq $1 $2)
echo $range

for arg in $range; do
  wordcount=$(gfactor $arg | wc -w)
  if [ "$wordcount" -gt 2 ]; then
      echo "$arg is composite"
  else
      echo "$arg is prime"
  fi
done

# Done
