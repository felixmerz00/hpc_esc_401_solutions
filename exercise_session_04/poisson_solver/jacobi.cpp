#include "jacobi.h"
#include <math.h>

/**
 * @brief      Computes norm of the difference between two matrices
 *
 * @param[in]  p     Parameters
 * @param      mat1  The matrix 1
 * @param      mat2  The matrix 2
 *
 * @return     Returns \sqrt{\sum(mat1_{ij} - mat2_{ij})^2/(nx*ny)}
 */
double norm_diff(params p, double** mat1, double** mat2){
    double sum_ij = 0;
    for (int i=0; i<p.nx; i++){
        for (int j=0; j<p.ny; j++){
            sum_ij += pow(mat1[i][j] - mat2[i][j], 2);
        }
    }
    return sqrt(sum_ij/pow(p.nx,2)); // return the norm
}

/**
 * @brief      Compute a Jacobi iteration to solve Poisson equation. This function updates
 *             u_new and u_old in-place.
 *
 * @param[in]  p      Parameters
 * @param      u_new  The new solution
 * @param      u_old  The old solution
 * @param      f      The source term
 */
void jacobi_step(params p, double** u_new, double** u_old, double** f){
    double dx = 1.0/(double(p.nx - 1));
    double dy = 1.0/(double(p.ny - 1));
    double delta = 1/(p.nx-1);

    for (int i=0; i<p.nx; i++){
        for (int j=0; j<p.ny; j++){
            u_old[i][j] = u_new[i][j];
        }
    }

    // Make the next Jacobi step based on equation (4)
    for (int i=1; i<p.ny-1; i++){
        for (int j=1; j<p.nx-1; j++){
            u_new[i][j] = 0.25 * (
                u_old[i-1][j] + u_old[i+1][j] 
                + u_old[i][j-1] + u_old[i][j+1] 
                - pow(delta,2) * f[i][j]
            );
        }
    }
}
