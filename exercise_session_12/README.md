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
