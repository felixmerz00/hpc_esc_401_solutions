// Using CUDA device to calculate pi
#include <stdio.h>
#include <cuda.h>
extern "C" double getTime(void);

#define NBIN 1000000000  // Number of bins
#define NUM_BLOCK  (2*56)  // Number of thread blocks
#define NUM_THREAD  (2*8)  // Number of threads per block

// Kernel that executes on the CUDA device
__global__ void cal_pi(double *sum, int nbin, double step, int nthreads, int nblocks) {
	int i;
	double x;
	int idx = blockIdx.x*blockDim.x+threadIdx.x;  // Sequential thread index across the blocks
	for (i=idx; i< nbin; i+=nthreads*nblocks) {
		x = (i+0.5)*step;
		sum[idx] += 4.0/(1.0+x*x);
	}
}

// Main routine that executes on the host
int main(void) {
	int NUM_BLOCK_VALUES[] =	{60, 120, 180, 240, 300, 360, 420, 600};
	int NUM_THREAD_VALUES[] = {16, 32, 48, 64, 80, 96, 112, 128, 144, 160};

	for(int b = 0; b < 8; b++){
		for(int t = 0; t < 10; t++){

			dim3 dimGrid(NUM_BLOCK_VALUES[b],1,1);  // Grid dimensions
			dim3 dimBlock(NUM_THREAD_VALUES[t],1,1);  // Block dimensions
			double *sumHost, *sumDev;  // Pointer to host & device arrays
			double pi = 0;
			int tid;

			double step = 1.0/NBIN;  // Step size
			size_t size = NUM_BLOCK_VALUES[b]*NUM_THREAD_VALUES[t]*sizeof(double);  //Array memory size
			sumHost = (double *)malloc(size);  //  Allocate array on host
			cudaMalloc((void **) &sumDev, size);  // Allocate array on device
				double start = getTime();

			// Initialize array in device to 0
			cudaMemset(sumDev, 0, size);
			// Do calculation on device
			cal_pi <<<dimGrid, dimBlock>>> (sumDev, NBIN, step, NUM_THREAD_VALUES[t], NUM_BLOCK_VALUES[b]); // call CUDA kernel
			// Retrieve result from device and store it in host array
			cudaMemcpy(sumHost, sumDev, size, cudaMemcpyDeviceToHost);
			for(tid=0; tid<NUM_THREAD_VALUES[t]*NUM_BLOCK_VALUES[b]; tid++)
				pi += sumHost[tid];
			pi *= step;

			// Print results
			double delta = getTime() - start;
			printf("Num blocks: %d, num threads: %d, computation time: %.4g seconds\n", NUM_BLOCK_VALUES[b], NUM_THREAD_VALUES[t], delta);

			// Cleanup
			free(sumHost);
			cudaFree(sumDev);
		}
	}


	return 0;
}

