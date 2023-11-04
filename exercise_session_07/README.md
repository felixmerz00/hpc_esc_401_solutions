## Exercise 1
The program runs forever because a deadlock occurs. Every rank wants to send information and waits until the next rank received the information. But no rank is receiving. Therefore we enter a deadlock. With the proposed solution the even ranks send information and get the confirmation from the odd ranks that they received the information. Then the program can proceed and the odd ranks send information and the even ranks receive it. This solution is not optimal. A rank that is receiving first, must wait until it got the message and only then it can start sending data.

  // send to right, receive from left
  if (my_rank % 2 == 0)
  {
      MPI_Ssend(&send_rank, 1, MPI_INTEGER, right_rank, 100, MPI_COMM_WORLD);
      MPI_Recv(&recv_rank, 1, MPI_INTEGER, left_rank, 100, MPI_COMM_WORLD, & status);
  }else
  {
      MPI_Recv(&recv_rank, 1, MPI_INTEGER, left_rank, 100, MPI_COMM_WORLD, & status);
      MPI_Ssend(&send_rank, 1, MPI_INTEGER, right_rank, 100, MPI_COMM_WORLD);
  }

The combinations Irecv-Isend-Waitall and Isend-Irecv-Waitall are better solutions than synchronous communication because on each rank the requests can be executed simultaniously and independent from each other.
  MPI_Isend(&send_rank, 1, MPI_INTEGER, right_rank, 100, MPI_COMM_WORLD, &sendRequest);
  MPI_Irecv(&recv_rank, 1, MPI_INTEGER, left_rank, 100, MPI_COMM_WORLD, &receiveRequest);
  MPI_Wait(&sendRequest, &status);
  MPI_Wait(&receiveRequest, &status);

# Bonus
It worked. The job (slurm-2423586.out) produced the following output.
    I am processor 0. My left neighbour is 3. My right neighbour is 1.
    I am processor 0 out of 4, and the sum is 6
    I am processor 3. My left neighbour is 2. My right neighbour is 0.
    I am processor 3 out of 4, and the sum is 6
    I am processor 2. My left neighbour is 1. My right neighbour is 3.
    I am processor 2 out of 4, and the sum is 6
    I am processor 1. My left neighbour is 0. My right neighbour is 2.
    I am processor 1 out of 4, and the sum is 6