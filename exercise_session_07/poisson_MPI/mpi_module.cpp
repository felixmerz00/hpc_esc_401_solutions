#include "mpi.h"
#include <stdio.h>
#include "init.h"

int start_MPI(int* my_rank, int* size){
	printf("Setting MPI environment\n");
	MPI_Init(NULL,NULL);
	MPI_Comm_size(MPI_COMM_WORLD,size);
	MPI_Comm_rank(MPI_COMM_WORLD,my_rank);

	return 0;
}

int close_MPI(){
	MPI_Finalize();
	return 0;
}

int mpi_get_domain(int nx, int ny, int my_rank, int size, int* min_x, int* max_x, int* min_y, int* max_y){
	/*
	define corners or local domains
	*/
	*min_y = 0;
	*max_y = ny;
	*min_x = my_rank * nx/size;
	*max_x = (my_rank == size-1) ? nx : (my_rank+1) * nx/size;

    printf("in mpi_get_domain() in mpi_module.cpp,  define corners of the local domains\n");

	printf("I am rank %d and my domain is: xmin, xmax, ymin, ymax: %d %d %d %d\n",my_rank,*min_x,*max_x,*min_y,*max_y);
	return 0;
}

int halo_comm(params p, int my_rank, int size, double** u, double* fromLeft, double* fromRight){
	
	/*this function, vectors fromLeft and fromRight should be received from the neighbours of my_rank process*/
	/*if you want to implement also cartesian topology, you need fromTop and fromBottom in addition to fromLeft a
	nd fromRight*/

	for (int j=0;j<(p.ymax - p.ymin);j++) {fromLeft[j] = 0; fromRight[j] = 0;} //initialize fromLeft and fromRight

	/* His code from exercise 8 start. */
	// double * toLeft, toRight;	// Define a vector where we store the values we want to send to the left and right.
	// MPI_Isend(&toLeft[0], p.ymax - p.ymin, MPI_DOUBLE, leftRank, tag, request[0]);
	// MPI_Isend(&u[0][p.xmax - p.xmin], p.ymax - p.ymin, MPI_DOUBLE, rightRankRank, tag, request[1]);
	// MPI_Irecv(from)
	// MPI_Waitall(MPI_COMM_WORLD, request, MPI_STATES_IGNORE)

	/* define columns to be sent to right neighbour and to the left neighbour, 
	also receive one both form left and right neighbour*/

	/* choose either to define MPIcolumn_type (lines 43-45) or define 
	the columns to be sent manually (lines 53-56)*/

	MPI_Datatype column_type;
	MPI_Type_vector(p.ymax - p.ymin, 1, p.xmax - p.xmin, MPI_DOUBLE, &column_type);
	MPI_Type_commit(&column_type);

	// ...some code goes here and then do not forget to free the column_type
	int array_size = (my_rank == 0 || my_rank == size-1) ? 2 : 4;
	MPI_Request requests[array_size];

	if (my_rank != 0)	// Interaction with left neighbour
	{
		MPI_Isend(u[0], 1, column_type, my_rank - 1, 100, MPI_COMM_WORLD, &requests[0]);
		MPI_Irecv(u[0], 1, column_type, my_rank - 1, 100, MPI_COMM_WORLD, &requests[1]);
	}
	if (my_rank != size - 1)	// Interaction with right neighbour
	{	// p.xmax is a global variable. If i want the max of my local u I calculate xmax-xmin.
		MPI_Isend(u[p.xmax-p.xmin-1], 1, column_type, my_rank + 1, 100, MPI_COMM_WORLD, &requests[array_size-2]);
		MPI_Irecv(u[p.xmax-p.xmin-1], 1, column_type, my_rank + 1, 100, MPI_COMM_WORLD, &requests[array_size-1]);
	}

	MPI_Type_free(&column_type);

	//or alternative approach below

	// double* column_to_right = new double [p.ymax - p.ymin];
	// for (int j=0;j<(p.ymax - p.ymin);j++) column_to_right[j] = u[p.xmax - p.xmin - 1][j]; 
	// double* column_to_left = new double [p.ymax - p.ymin];
	// for (int j=0;j<(p.ymax - p.ymin);j++) column_to_left[j] = u[0][j]; 


	printf("mpi_module.cpp, define halo comm:  \n");
	return 0;
}

// I can use this when callculating the norm_diff
// Maybe call this at the end of norm_diff()
int ALLREDUCE(double* loc_diff, double* loc_sumdiff){

	MPI_Allreduce(loc_diff, loc_sumdiff, 1, MPI_DOUBLE, MPI_SUM, MPI_COMM_WORLD);
	return 0;

	}
