#!/bin/bash

# enter the source file as param e.g.,
# ./extract-temperature.sh measured/measurements3.txt

# Initialize variables for sum and count
sum_temperature=0
count_temperature=0

# Create a new file "out.txt" and append the temperature and time data to it
> out.txt
echo "temperature, time" >> out.txt

# Process the input data
while read line; do
  if [[ $line == *Temperature* ]]; then
    # echo $line
    # Extract temperature and time values
    temperature=$(echo "$line" | awk -F' ' '{print $2}')
    time=$(echo "$line" | awk -F' ' '{print $6}')

    # Append the data to "out.txt"
    echo "$temperature, $time" >> out.txt

    # Add temperature to the sum and increment the count
    sum_temperature=$(echo "$sum_temperature + $temperature" | bc)
    count_temperature=$((count_temperature + 1))
    fi
done < $1

# Calculate the average temperature
average_temperature=$(echo "scale=2; $sum_temperature / $count_temperature" | bc)

# Print the average temperature
echo "Average Temperature: $average_temperature"

# Done
