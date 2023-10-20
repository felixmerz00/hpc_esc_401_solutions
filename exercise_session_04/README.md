## Exercise 1
I can't compile my .cpp file using cc or CC. I can use
```g++ vector-addition.cpp -o vector-addition``` to compile my code.

## Exercise 2

- It stores the number 42 in the place before the array. This should be avoided.
- p is the memory address of the first element of the array. \*p represents the value stored at the address p, i.e. the first value of the integer array. &p also a memory address. &p is the location where p is stored.
- \*(p+1) is the second value of the integer array. \*p+1 is the first value of the integer array incremented by 1.
- q[0] is the value stored at the place one before p. \*(q+10) is the last value of the integer array p. \*(q+11) is the value stored directly after the integer array p.
---
- The pointers to M[0] and M[1] are stored next to each other in memory, but not the arrays. Hence \*(M[0]+5) == M[1][0] is false.
- M is a pointer to a pointer. \*M is a pointer to an array of integers. \*\*M is the first element in the integer array; i.e. 0.
- M[1][3] points to the fourth element in the second integer array. i.e., 8
- \*(M[0]+1) is the second element in the first integer array. i.e., 1
- \*(\*(M+1)+3) is the fourth element in the second integer array. i.e., 8

## Exercise 3

What are these routines supposed to do?
init_f() initializes the matrix which represents the function f. The user can choose one out of two functions. init_f generates the matrix f based on the users selection. Both functions differ between border cells of the matrix and inner cells. The actual values of the cells are calculated in the given functions boundary() and source_term().

jacobi_step() calculates the values of the new iteration in our approximation of the Poisson problem. It updates all inner cells of our matrix based on formula (4). To calculate the new values I use the values from the last iteration and the values from the matrix f.

norm_diff() is needed for one of our stopping criterias. Our approximation should stop iterating when the norm of a certain difference is below a given threshold. norm_diff() calculates the norm of that difference.
