#include <stdio.h>

void swapArray(int **M, int sizeOuter, int sizeInner){
  int **M2 = new int* [2];
  M2[0] = new int[5];
  M2[1] = new int[5];

  for(int i = 0; i < sizeOuter; i++){
    for(int j = 0; j < sizeInner; j++){
      M2[i][j] = M[sizeOuter - 1 - i][sizeInner - 1 - j];
    }
  }

  for(int i = 0; i < sizeOuter; i++){
    for(int j = 0; j < sizeInner; j++){
      printf("%d ", M2[i][j]);
    }
    printf("\n");
  }

  // somehow i cannot free the memory
  // error: use of undeclared identifier 'free'
  // free(M2[0]);
  
  return;
}

void partOne(){
  int p [10] = {9, 1, 2, 3, 5, 5, 6, 7, 2, 9};
  printf("p: %p\n", p);
  printf("*p: %d\n", *p);
  printf("&p: %p\n", &p);
  printf("*(p+1): %d\n", *(p+1));
  printf("*p+1: %d\n", *p+1);

  int *q = p-1;
  printf("q[0]: %d\n", q[0]); // This is asked
  printf("q[0]: %d\n", q[1]);
  printf("q[0]: %d\n", q[2]);
  printf("q[0]: %d\n", q[3]);
  printf("q[0]: %d\n", q[4]);
  printf("q[0]: %d\n", q[5]);
  printf("*(q+10): %d\n", *(q+8));
  printf("*(q+10): %d\n", *(q+9));
  printf("*(q+10): %d\n", *(q+10));   // This is asked
  printf("*(q+11): %d\n", *(q+11));   // This is asked

//  This gives a compilation error.
  int ** M = new int *[2];
  M[0] = new int[5];
  M[0][0] = 0; M[0][1] = 1; M[0][2] = 2; M[0][3] = 3; M[0][4] = 4; 
  M[1] = new int[5];
  M[1][0] = 5; M[1][1] = 6; M[1][2] = 7; M[1][3] = 8; M[1][4] = 9; 
  printf("M: %p\n", M);
  printf("*M: %p\n", *M);
  printf("**M: %d\n", **M);
  printf("M[1][3]: %d\n", M[1][3]);
  printf("*(M[0]+1): %d\n", *(M[0]+1));
  printf("*(*(M+1)+3): %d\n", *(*(M+1)+3));
  return;
}

int main(){
  partOne();

  // Part two
  int ** M = new int *[2];
  M[0] = new int[5];
  M[0][0] = 0; M[0][1] = 1; M[0][2] = 2; M[0][3] = 3; M[0][4] = 4; 
  M[1] = new int[5];
  M[1][0] = 5; M[1][1] = 6; M[1][2] = 7; M[1][3] = 8; M[1][4] = 9;
  swapArray(M, 2, 5);

  return 0;
}

