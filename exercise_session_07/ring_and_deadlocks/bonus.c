#include "mpi.h"
#include <stdio.h>

int main(int argc, char** argv) {
  MPI_Comm comm_cart;
  // Initialize the MPI environment
  MPI_Init(NULL, NULL);

  // Get the number of processes and rank of the process
  int source_rank, rneigh_rank;

  int dims[1] = {4};
  int periods[1] = {1}
  // int MPI_Cart_create(MPI_Comm comm_old, int ndims, int *dims, int *periods, int reorder, MPI_Comm *comm_cart);
  MPI_Cart_create(MPI COMM WORLD, 1, dims, periods, 1, &comm_cart);

  // int MPI_Cart_shift(MPI_Comm comm, int direction, int displ, int *source, int *dest);
  int MPI_Cart_shift(comm_cart, 1, 1, &source_rank, &rneigh_rank);


  printf("I am processor %d. My right neighbour is %d.\n", source_rank, rneigh_rank);

  // Finalize the MPI environment.
  MPI_Finalize();
}
