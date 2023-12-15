For all exercises I loaded the daint GPU and the cuda toolkit.
```bash
module load daint-gpu
module load cudatoolkit
```

# Exercise 2
All threads are in one big list. I find out the global index of the current thread based on the index of the block, the block siize and the local index of the thread. Local meaning the index inside my block. I move the index to where all indices of my block are with blockIdx.x * blockDim.x. Then I increase the index by the index of the thread inside the block.
```c
i = threadIdx.x + blockIdx.x * blockDim.x;
if(i<n) gpu_ptr[i] = value;
```


Adjust the documentation. 
```bash
salloc -A uzg2 --constraint=gpu --time=00:30:00 --partition=debug
nvcc hello_world.cu
srun ./a.out
```

I got the following output.
```
11.000000	11.000000	11.000000	11.000000	11.000000	11.000000	11.000000	11.000000	11.000000	11.000000	
11.000000	11.000000	11.000000	11.000000	11.000000	11.000000	11.000000	11.000000	11.000000	11.000000	
PASSED !!
```

# Exercise 3
I filled in some code and then ran these commands.

```bash
salloc -A uzg2 --constraint=gpu --time=00:30:00 --partition=debug
nvcc hello_world.cu
srun ./a.out
```
I got the output that I passed.

## Bonus
I filled in the code. Then I ran these commands. 
```
nvcc addongpu-bonus.cu 
srun ./a.out
```
The program failed. I might try again later.

# Exercise 4
I filled in the missing code. Then I ran these commands.
```bash
make
salloc -A uzg2 --constraint=gpu --time=00:30:00 --partition=debug
srun ./a.out
```
When I ran the program the first time it failed. I got the following output.
```
Convolution took  0.000096 sec. on GPU
Convolution took  0.008832 sec. on CPU
FAILED: 5160 errors
```
I adjusted the tolerance in the main.c file from 1e-7 to 1e-6. With this adjustment the program passed. I got the following output.
```
Convolution took  0.000098 sec. on GPU
Convolution took  0.008930 sec. on CPU
PASSED
```
