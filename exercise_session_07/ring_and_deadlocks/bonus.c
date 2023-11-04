#include "mpi.h"
#include <stdio.h>

int main(int argc, char** argv) {
  MPI_Comm comm_cart;
  MPI_Status status;
  MPI_Request sendRequest;
  MPI_Request receiveRequest;
  // Initialize the MPI environment
  MPI_Init(NULL, NULL);

  // Get the number of processes and rank of the process
  int size, my_rank, lneigh_rank, rneigh_rank;
  MPI_Comm_size(MPI_COMM_WORLD, &size);
  MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);

  int send_rank = my_rank;  // Send    buffer
  int recv_rank = 0;        // Receive buffer
  int my_sum = 0;

  int dims[1] = {size};
  int periods[1] = {1};
  // int MPI_Cart_create(MPI_Comm comm_old, int ndims, int *dims, int *periods, int reorder, MPI_Comm *comm_cart);
  MPI_Cart_create(MPI_COMM_WORLD, 1, dims, periods, 1, &comm_cart);

  // int MPI_Cart_shift(MPI_Comm comm, int direction, int displ, int *source, int *dest);
  MPI_Cart_shift(comm_cart, 0, 1, &lneigh_rank, &rneigh_rank);

  for (int i = 0; i < size; i++)
  {
    MPI_Isend(&send_rank, 1, MPI_INTEGER, rneigh_rank, 100, comm_cart, &sendRequest);
    MPI_Irecv(&recv_rank, 1, MPI_INTEGER, lneigh_rank, 100, comm_cart, &receiveRequest);
    MPI_Wait(&sendRequest, &status);
    MPI_Wait(&receiveRequest, &status);

    send_rank = recv_rank;  // update the send buffer
    my_sum += recv_rank;   // update the local sum
  }
  
  printf("I am processor %d. My left neighbour is %d. My right neighbour is %d.\n", my_rank, lneigh_rank, rneigh_rank);
  printf("I am processor %d out of %d, and the sum is %d\n", my_rank, size, my_sum);

  // Finalize the MPI environment.
  MPI_Finalize();
}
