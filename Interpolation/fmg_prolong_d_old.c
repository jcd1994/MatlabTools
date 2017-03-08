#include "mex.h"
#include "matrix.h"
#include <math.h>
#include <stdint.h>

/* FMG_PROLONG_D.c
 *
 * INPUT ARGUMENTS
 *  x: 3D double array
 *
 */

/* The gateway routine. */
void mexFunction( int nlhs, mxArray *plhs[],
                  int nrhs, const mxArray *prhs[] )
{
    double  *xr, *xi, *zr, *zi;
    
    /* get the length of each input vector */
    const mwSize *mSizeIn  = mxGetDimensions((const mxArray*)prhs[0]);
    
    /* get pointers to the real and imaginary parts of the inputs */
    xr = (double*)mxGetData(prhs[0]);
    xi = (double*)mxGetImagData(prhs[0]);
    
    /* create a new array and set the output pointer to it */
    mwSize *mSizeOut = (mwSize *) mxMalloc (3 * sizeof (mwSize));
    mSizeOut[0] = 2*mSizeIn[0];
    mSizeOut[1] = 2*mSizeIn[1];
    mSizeOut[2] = 2*mSizeIn[2];
    plhs[0] = mxCreateNumericArray(3, mSizeOut, mxDOUBLE_CLASS, mxCOMPLEX);
    zr = (double*)mxGetData(plhs[0]);
    zi = (double*)mxGetImagData(plhs[0]);
    
    const uint32_t nx = mSizeIn[0], ny = mSizeIn[1], nz = mSizeIn[2];
    const uint32_t nxny = nx*ny, nxnynz = nxny*nz;
    const uint32_t nx2 = 2*nx, ny2 = 2*ny, nz2 = 2*nz, nxny2 = 2*nxny, nxnynz2 = 2*nxnynz;
    const uint32_t nx4 = 4*nx, ny4 = 4*ny, nz4 = 4*nz, nxny4 = 4*nxny, nxnynz4 = 4*nxnynz;
    const uint32_t Nx = nx-1, Ny = nx*(ny-1), Nz = nxny*(nz-1);
    const uint32_t Nx2 = nx2-1, Ny2 = nx2*(ny2-1), Nz2 = nxny2*(nz2-1);
    
    uint32_t il, ir, jl, jr, kl, kr;
    
    uint32_t i, j, k, l, l2;
    /* call the C subroutine */
    for(k = 0; k < nxnynz; k += nxny){
        for(j = 0; j < nxny; j += nx){
            l  = k + j;
            l2 = (k<<3) + (j<<2);
            for(i = 0; i < nx; ++i, ++l, l2 += 2){
                ir = (i==Nx) ? l-Nx : l+1;
                jr = (j==Ny) ? l-Ny : l+nx;
                kr = (k==Nz) ? l-Nz : l+nxny;
                
                zr[l2] = xr[l];
                zi[l2] = xi[l];
                
                
            }
        }
    }
    
    return;
}