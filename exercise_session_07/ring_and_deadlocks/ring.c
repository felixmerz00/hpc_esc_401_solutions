#include "mpi.h"
#include <stdio.h>

int main(int argc, char** argv) {
    MPI_Status status;
    MPI_Request sendRequest;
    MPI_Request receiveRequest;
    // Initialize the MPI environment
    MPI_Init(NULL, NULL);

    // Get the number of processes and rank of the process
    int size, my_rank;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);

    int my_sum = 0;

    int send_rank = my_rank;    // Send    buffer
    int recv_rank = 0;    // Receive buffer

    // Compute the ranks of left/right neighbours 
    int left_rank, right_rank;
    left_rank = (my_rank + size-1)%size;
    right_rank = (my_rank + 1)%size;
    
    // Loop over the number of processes
    for (int i = 0; i < size; i++)
    {
        // send to right, receive from left
        // if (my_rank % 2 == 0)
        // {
        //     MPI_Ssend(&send_rank, 1, MPI_INTEGER, right_rank, 100, MPI_COMM_WORLD);
        //     MPI_Recv(&recv_rank, 1, MPI_INTEGER, left_rank, 100, MPI_COMM_WORLD, & status);
        // }else
        // {
        //     MPI_Recv(&recv_rank, 1, MPI_INTEGER, left_rank, 100, MPI_COMM_WORLD, & status);
        //     MPI_Ssend(&send_rank, 1, MPI_INTEGER, right_rank, 100, MPI_COMM_WORLD);
        // }

        // MPI_Isend(&send_rank, 1, MPI_INTEGER, right_rank, 100, MPI_COMM_WORLD, &sendRequest);
        // MPI_Irecv(&recv_rank, 1, MPI_INTEGER, left_rank, 100, MPI_COMM_WORLD, &receiveRequest);
        MPI_Irecv(&recv_rank, 1, MPI_INTEGER, left_rank, 100, MPI_COMM_WORLD, &receiveRequest);
        MPI_Isend(&send_rank, 1, MPI_INTEGER, right_rank, 100, MPI_COMM_WORLD, &sendRequest);
        MPI_Wait(&sendRequest, &status);
        MPI_Wait(&receiveRequest, &status);
        
        // update the send buffer
        send_rank = recv_rank;
        // update the local sum
        my_sum += recv_rank;
    }

    printf("I am processor %d out of %d, and the sum is %d\n", my_rank, size, my_sum);

    // Finalize the MPI environment.
    MPI_Finalize();
}
