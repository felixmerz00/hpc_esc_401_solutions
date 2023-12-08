# General
```bash
module swap PrgEnv-cray PrgEnv-pgi/6.0.8
module load daint-gpu
module load cudatoolkit
module load craype-accel-nvidia60
```

# Exercise 1
I added this line where the TODO is.
```
#pragma acc parallel loop pcopyin(x[0:n]) pcopy(y[0:n])
```
The CPU version is faster. Doing a linear combination is super simple. Copying the values into the memory of the GPU for this is not worth it. These are two of my outputs. The whole output can be found in the file slurm-50384181.out.
```
memcopy and daxpy test of size 2
-------
timings
-------
axpy (openmp): 9.53674e-07 s
axpy (openacc): 0.000228167 s

============ PASSED
memcopy and daxpy test of size 4
-------
timings
-------
axpy (openmp): 0 s
axpy (openacc): 0.000226021 s
```

I cannot start an interactive session.
```
srun -p debug -n 1 -C gpu -t 0.01.00 -A uzg2 axpy.openacc 1
```

# Exercise 2
## a
I added these lines below the TODO tatks.
```
#pragma acc routine seq
#pragma acc parallel loop pcopyin(in[0:n]) pcopyout(buffer[1:n-2])
#pragma acc parallel loop pcopyin(buffer[0:n]) pcopyout(out[2:n-4])
```
I ran the file as a slurm job with the script called "script". It worked (see slurm-50384926.out). The problem with this approach is that the buffer is not stored on the GPU. At the end of the first parallel region I need to copy the array called "buffer" onto the CPU and then back onto the GPU for the second parallel region. It would be smarter to the data on the GPU between the two parallel regions.

Note to myself: The first value in pcopyout is the index where to start, second value is for the length.

## b
I created a region to store the in, buffer and out array on the GPU.
```c
#pragma acc data pcopyin(in[0:n]) pcopy(out[0:n]) pcreate(buffer[0:n])
```
Inside the region I parallelized the three loops with this line.
```c
#pragma acc parallel loop
```
Further down I changed the code so it would call the nocopies function.
```c
blur_twice_gpu_nocopies(x0, x1, n, nsteps);
```
I got it running (see slurm-50385896.out).
