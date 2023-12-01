# Exercise 1
```
module swap PrgEnv-cray PrgEnv-pgi/6.0.8
module load daint-gpu
module load cudatoolkit
module load craype-accel-nvidia60
module swap cray-mpich cray-mpich/7.7.15
cc -ta=tesla,cc60 -o cpi_openacc cpi_openacc.c gettime.c
sbatch script
```

I get this output. The times are not the same. The first run is slower. The data needs to be offloaded to the GPU, which takes time. But when it is done it gets much faster.
```
PI = 3.141592653589793 computed in 0.2197 seconds
PI = 3.141592653589793 computed in 0.01419 seconds
PI = 3.141592653589793 computed in 0.01417 seconds
PI = 3.141592653589793 computed in 0.01406 seconds
PI = 3.141592653589793 computed in 0.01407 seconds
```

# Exercise 2
```
module load daint-gpu
module load cudatoolkit
nvcc -o cpi_cuda cpi_cuda.cu gettime.c --gpu-architecture=sm_60
sbatch script
```
When running the original version of the file I get only one output, as expected (slurm-50289410.out).
```
PI = 3.14159265358979 computed in 0.08539 seconds
```

I implemented the for loop.
```
nvcc -o cpi_cuda cpi_cuda.cu gettime.c --gpu-architecture=sm_60
sbatch script
```
With cuda the times of each iteration are the same (slurm-50289530.out). They need less execution time than the first iteration from exercise 1, but more time than the subsequent iterations from exercise 1. With five iterations the total execution time is higher than the total execution time from exercise 1.
```
PI = 3.14159265358979 computed in 0.086 seconds
PI = 3.141592656731382 computed in 0.07935 seconds
PI = 3.141592656731382 computed in 0.07722 seconds
PI = 3.141592656731382 computed in 0.07738 seconds
PI = 3.141592656731382 computed in 0.07746 seconds
```
