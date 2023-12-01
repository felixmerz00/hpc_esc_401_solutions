#!/bin/bash

# Define the values for NUM_BLOCK and NUM_THREAD
NUM_BLOCK_VALUES=(60 120 180 240 300 360 420 600)
NUM_THREAD_VALUES=(16 32 48 64 80 96 112 128 144 160)

# Loop through the combinations of NUM_BLOCK and NUM_THREAD
for NUM_BLOCK in "${NUM_BLOCK_VALUES[@]}"; do
  for NUM_THREAD in "${NUM_THREAD_VALUES[@]}"; do
    # Compile the CUDA program
    nvcc -o your_program your_program.cu -DNUM_BLOCK=$NUM_BLOCK -DNUM_THREAD=$NUM_THREAD

    # Run the compiled program
    ./your_program

    # Clean up the compiled program
    rm your_program
  done
done
