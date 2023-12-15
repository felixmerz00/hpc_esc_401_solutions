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
I filled in the code. Then I ran these commands. It failed. I'll might try again later.
```
nvcc addongpu-bonus.cu 
srun ./a.out
```

# Exercise 4
I filled in the missing code. Then I ran these commands.
```
make
salloc -A uzg2 --constraint=gpu --time=00:30:00 --partition=debug
srun ./a.out 
```
I ran it but it failed. I get the following output. I might try again later. 
```
Convolution took  0.000096 sec. on GPU
Convolution took  0.008832 sec. on CPU
FAILED: 5160 errors
```
