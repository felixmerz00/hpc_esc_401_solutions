## Exercise 1

```
gcc -fopenmp -o serial serial.c
./serial OMP_NUM_THREADS=128
```

```
[eiger][fmerz@eiger-ln001 race_conditions]$ gcc -fopenmp -o serial serial.c
[eiger][fmerz@eiger-ln001 race_conditions]$ ./serial OMP_NUM_THREADS=128
Size of integer array/file: 1000000
max number in file: 38747
number of 0s in file: 646016
true number of 0s in file: 646016
[eiger][fmerz@eiger-ln001 race_conditions]$ ./serial
Size of integer array/file: 1000000
max number in file: 38747
number of 0s in file: 646016
true number of 0s in file: 646016
```

I did not run into a race condition. I think using `#pragma omp critical` in this case is a bad idea. I could wrap `if (numbers[i] > maxval) maxval = numbers[i];` into a critical block. But because it is inside a loop, the performance would suffer. 

`#pragma omp atomic` probably can't be applied here either, because I need to execute two operations in isolation: the comparison inside the if clause and the assignment of the new maxval.

I already used `#pragma omp reduction` from the beginning. I think this is the best option for this specific case.
