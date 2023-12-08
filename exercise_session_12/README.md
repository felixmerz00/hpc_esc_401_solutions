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
I got it running (see slurm-50385896.out). So now I test it for different values for N and nstep. For N I test the values 10, 20, 40. For nstep I use the values 50, 100, 200. According to my output, increasing N makes a big difference. Increasig nstep makes a difference too, but not as much. Example output for N = 40. I have other outputs in the file slurm-50386487.out.
```
N: 40, nstep: 50
Host version took 3.91006e-05 s (7.82013e-07 s/step)
GPU version took 0.00119495 s (2.38991e-05 s/step)
dispersion 1D test of length n = 260 : 0.00198364MB
==== success ====
N: 40, nstep: 100
Host version took 6.19888e-05 s (6.19888e-07 s/step)
GPU version took 0.00214219 s (2.14219e-05 s/step)
dispersion 1D test of length n = 260 : 0.00198364MB
==== success ====
N: 40, nstep: 200
Host version took 0.000113964 s (5.6982e-07 s/step)
GPU version took 0.00404501 s (2.0225e-05 s/step)
```

# Exercise 3
The code is prone to race conditions because when I parallelize it multiple threads try to increase the sum at the same time. To avoid this I used the keyword "reduction". I added these lines below the TODO. They ensure that operations on the sum variable are safe.
```c
#pragma acc parallel
#pragma acc loop reduction(+:sum)
```
I run the script with the inputs 2, 4, 8, and 16.
For my inputs the GPU performs worse than the CPU. Here an example. The other outputs are in the file slurm-50386991.out.
```
dot product OpenACC of length n = 65536 : 0.5MB
expected 588374 got 588374: success
Host kernel took 6.50883e-05 s
GPU kernel took 0.018348 s
```
