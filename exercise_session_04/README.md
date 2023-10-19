## Exercise 2

- It stores the number 42 in the place before the array. This should be avoided.
- p is the memory address of the first element of the array. *p represents the value stored at the address p, i.e. the first value of the integer array. &p also a memory address. &p is the location where p is stored.
- *(p+1) is the second value of the integer array. *p+1 is the first value of the integer array incremented by 1.
- q[0] is the value stored at the place one before p. *(q+10) is the last value of the integer array p. *(q+11) is the value stored directly after the integer array p.
- The pointers to M[0] and M[1] are stored next to each other in memory, but not the arrays. Hence *(M[0]+5) == M[1][0] is false.

- M is a pointer to a pointer. *M is a pointer to an array of integers. **M is the first element in the integer array; i.e. 0.
- M[1][3] points to the fourth element in the second integer array. i.e., 8
- *(M[0]+1) is the second element in the first integer array. i.e., 1
- *(*(M+1)+3) is the fourth element in the second integer array. i.e., 8
