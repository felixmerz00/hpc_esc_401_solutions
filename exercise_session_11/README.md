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

In the cuda code the time measurement is done outside the loop. In the openacc code the time measurement is done outside the loop.

# Exercise 3
```
nvcc --gpu-architecture=sm_60 -o cpi_cuda-approach-2 cpi_cuda-approach-2.cu gettime.c
sbatch script
```
I get the following measurements.
```
Num blocks: 60, num threads: 16, computation time: 0.1599 seconds
Num blocks: 60, num threads: 32, computation time: 0.07737 seconds
Num blocks: 60, num threads: 48, computation time: 0.04941 seconds
Num blocks: 60, num threads: 64, computation time: 0.03707 seconds
Num blocks: 60, num threads: 80, computation time: 0.03007 seconds
Num blocks: 60, num threads: 96, computation time: 0.02507 seconds
Num blocks: 60, num threads: 112, computation time: 0.022 seconds
Num blocks: 60, num threads: 128, computation time: 0.01923 seconds
Num blocks: 60, num threads: 144, computation time: 0.01777 seconds
Num blocks: 60, num threads: 160, computation time: 0.01601 seconds
Num blocks: 120, num threads: 16, computation time: 0.07326 seconds
Num blocks: 120, num threads: 32, computation time: 0.03665 seconds
Num blocks: 120, num threads: 48, computation time: 0.02492 seconds
Num blocks: 120, num threads: 64, computation time: 0.01871 seconds
Num blocks: 120, num threads: 80, computation time: 0.01598 seconds
Num blocks: 120, num threads: 96, computation time: 0.01334 seconds
Num blocks: 120, num threads: 112, computation time: 0.01192 seconds
Num blocks: 120, num threads: 128, computation time: 0.01045 seconds
Num blocks: 120, num threads: 144, computation time: 0.01316 seconds
Num blocks: 120, num threads: 160, computation time: 0.01187 seconds
Num blocks: 180, num threads: 16, computation time: 0.04886 seconds
Num blocks: 180, num threads: 32, computation time: 0.02446 seconds
Num blocks: 180, num threads: 48, computation time: 0.01705 seconds
Num blocks: 180, num threads: 64, computation time: 0.01282 seconds
Num blocks: 180, num threads: 80, computation time: 0.01112 seconds
Num blocks: 180, num threads: 96, computation time: 0.009288 seconds
Num blocks: 180, num threads: 112, computation time: 0.01132 seconds
Num blocks: 180, num threads: 128, computation time: 0.009944 seconds
Num blocks: 180, num threads: 144, computation time: 0.01131 seconds
Num blocks: 180, num threads: 160, computation time: 0.0102 seconds
Num blocks: 240, num threads: 16, computation time: 0.03723 seconds
Num blocks: 240, num threads: 32, computation time: 0.01866 seconds
Num blocks: 240, num threads: 48, computation time: 0.01326 seconds
Num blocks: 240, num threads: 64, computation time: 0.009983 seconds
Num blocks: 240, num threads: 80, computation time: 0.01184 seconds
Num blocks: 240, num threads: 96, computation time: 0.009901 seconds
Num blocks: 240, num threads: 112, computation time: 0.01083 seconds
Num blocks: 240, num threads: 128, computation time: 0.009516 seconds
Num blocks: 240, num threads: 144, computation time: 0.01099 seconds
Num blocks: 240, num threads: 160, computation time: 0.009921 seconds
Num blocks: 300, num threads: 16, computation time: 0.02994 seconds
Num blocks: 300, num threads: 32, computation time: 0.01501 seconds
Num blocks: 300, num threads: 48, computation time: 0.01107 seconds
Num blocks: 300, num threads: 64, computation time: 0.008338 seconds
Num blocks: 300, num threads: 80, computation time: 0.01079 seconds
Num blocks: 300, num threads: 96, computation time: 0.009043 seconds
Num blocks: 300, num threads: 112, computation time: 0.01042 seconds
Num blocks: 300, num threads: 128, computation time: 0.009154 seconds
Num blocks: 300, num threads: 144, computation time: 0.01019 seconds
Num blocks: 300, num threads: 160, computation time: 0.009211 seconds
Num blocks: 360, num threads: 16, computation time: 0.02548 seconds
Num blocks: 360, num threads: 32, computation time: 0.01279 seconds
Num blocks: 360, num threads: 48, computation time: 0.0116 seconds
Num blocks: 360, num threads: 64, computation time: 0.008748 seconds
Num blocks: 360, num threads: 80, computation time: 0.01102 seconds
Num blocks: 360, num threads: 96, computation time: 0.009238 seconds
Num blocks: 360, num threads: 112, computation time: 0.01015 seconds
Num blocks: 360, num threads: 128, computation time: 0.008945 seconds
Num blocks: 360, num threads: 144, computation time: 0.01018 seconds
Num blocks: 360, num threads: 160, computation time: 0.009228 seconds
Num blocks: 420, num threads: 16, computation time: 0.02195 seconds
Num blocks: 420, num threads: 32, computation time: 0.01103 seconds
Num blocks: 420, num threads: 48, computation time: 0.01132 seconds
Num blocks: 420, num threads: 64, computation time: 0.008551 seconds
Num blocks: 420, num threads: 80, computation time: 0.01039 seconds
Num blocks: 420, num threads: 96, computation time: 0.008705 seconds
Num blocks: 420, num threads: 112, computation time: 0.009961 seconds
Num blocks: 420, num threads: 128, computation time: 0.008776 seconds
Num blocks: 420, num threads: 144, computation time: 0.009761 seconds
Num blocks: 420, num threads: 160, computation time: 0.008845 seconds
Num blocks: 600, num threads: 16, computation time: 0.01659 seconds
Num blocks: 600, num threads: 32, computation time: 0.008383 seconds
Num blocks: 600, num threads: 48, computation time: 0.01103 seconds
Num blocks: 600, num threads: 64, computation time: 0.008353 seconds
Num blocks: 600, num threads: 80, computation time: 0.01035 seconds
Num blocks: 600, num threads: 96, computation time: 0.0087 seconds
Num blocks: 600, num threads: 112, computation time: 0.009665 seconds
Num blocks: 600, num threads: 128, computation time: 0.008563 seconds
Num blocks: 600, num threads: 144, computation time: 0.009669 seconds
Num blocks: 600, num threads: 160, computation time: 0.008782 seconds
```
