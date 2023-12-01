# Exercise 1
```
module swap PrgEnv-cray PrgEnv-pgi/6.0.8
module load daint-gpu
module load cudatoolkit
module load craype-accel-nvidia60
module swap cray-mpich cray-mpich/7.7.15
cc -ta=tesla,cc60 -o cpi_openacc cpi_openacc.c gettime.c
```

I get this output. The times are not the same. The first run is slower. The data needs to be offloaded to the GPU, which takes time. But when it is done it gets much faster.
```
PI = 3.141592653589793 computed in 0.2197 seconds
PI = 3.141592653589793 computed in 0.01419 seconds
PI = 3.141592653589793 computed in 0.01417 seconds
PI = 3.141592653589793 computed in 0.01406 seconds
PI = 3.141592653589793 computed in 0.01407 seconds
```
