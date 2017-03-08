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

#define V(x,i,j,k) x[i+j+k]

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
//     const uint32_t nx2 = 2*nx, ny2 = 2*ny, nz2 = 2*nz, nxny2 = 2*nxny, nxnynz2 = 2*nxnynz;
//     const uint32_t nx4 = 4*nx, ny4 = 4*ny, nz4 = 4*nz, nxny4 = 4*nxny, nxnynz4 = 4*nxnynz;
    const uint32_t Nx = nx-1, Ny = nx*(ny-1), Nz = nxny*(nz-1);
//     const uint32_t Nx2 = nx2-1, Ny2 = nx2*(ny2-1), Nz2 = nxny2*(nz2-1);
    
    uint32_t i, j, k, l, i2, j2, k2, l2;
//     uint32_t il, il2, jl, jl2, kl, kl2;
    for(k = 0; k < nxnynz; k += nxny){
        for(j = 0; j < nxny; j += nx){
            l  = k + j;
            l2 = (k<<3) + (j<<2); //times 2 for each dimension
            for(i = 0; i < nx; ++i, ++l, l2 += 2){
//                 i2 = (i<<1);
//                 j2 = (j<<2);
//                 k2 = (k<<3);
//                 il = (i==0) ? l+Nx : l-1;
//                 jl = (j==0) ? l+Ny : l-nx;
//                 kl = (k==0) ? l+Nz : l-nxny;
//                 il2 = (il<<1);
//                 jl2 = (jl<<2);
//                 kl2 = (kl<<3);
                
                /* Assign Center Values */
                zr[l2] = xr[l];
                zi[l2] = xi[l];
                
                /* 6 Close Neighbours */
//                 V(zr ,il2, j2   ,k2       )	=   0.5 * ( xr[l] + V(xr ,il, j   ,k     ) );
//                 V(zr ,i2+1,j2   ,k2       )	=   0.5 * ( xr[l] + V(xr ,i+1,j   ,k     ) );
//                 V(zr ,i2  ,jl2  ,k2       )	=   0.5 * ( xr[l] + V(xr ,i  ,jl  ,k     ) );
//                 V(zr ,i2  ,j2+nx,k2       )	=   0.5 * ( xr[l] + V(xr ,i  ,j+nx,k     ) );
//                 V(zr ,i2  ,j2   ,kl2      )	=   0.5 * ( xr[l] + V(xr ,i  ,j   ,kl    ) );
//                 V(zr ,i2  ,j2   ,k2 + nxny)	=   0.5 * ( xr[l] + V(xr ,i  ,j   ,k+nxny) );
            }
        }
    }
    /*
    uint32_t i, j, k, l, i2, j2, k2, l2;
    uint32_t il, il2, jl, jl2, kl, kl2;
    for(k = 0, k2 = 0; k < nxnynz; k += nxny, k2 += nxny8){
        for(j = 0, j2 = 0; j < nxny; j += nx, j2 += nx4){
            l  = k + j;
            l2 = (k<<3) + (j<<2); //times 2 for each dimension
//             l2 = k2 + j2; //times 2 for each dimension
            for(i = 0, i2 = 0; i < nx; ++i, i2 += 2, ++l, l2 += 2){
//                 i2 = (i<<1);
//                 j2 = (j<<2);
//                 k2 = (k<<3);
                il = (i==0) ? Nx : i-1;
                jl = (j==0) ? Ny : j-nx;
                kl = (k==0) ? Nz : k-nxny;
//                 il2 = (i2==0) ? Nx2 : i2-2;
//                 jl2 = (j2==0) ? Ny2 : j2-nx2;
//                 kl2 = (k2==0) ? Nz2 : k2-nxny2;
//                 il2 = (il<<1);
//                 jl2 = (jl<<2);
//                 kl2 = (kl<<3);
                
                // Assign Center Values
                zr[l2] = xr[l];
                zi[l2] = xi[l];
                
                // 6 Close Neighbours
//                 V(zr ,il2, j2   ,k2       )	=   0.5 * ( xr[l] + V(xr ,il, j   ,k     ) );
//                 V(zr ,i2+1,j2   ,k2       )	=   0.5 * ( xr[l] + V(xr ,i+1,j   ,k     ) );
//                 V(zr ,i2  ,jl2  ,k2       )	=   0.5 * ( xr[l] + V(xr ,i  ,jl  ,k     ) );
//                 V(zr ,i2  ,j2+nx,k2       )	=   0.5 * ( xr[l] + V(xr ,i  ,j+nx,k     ) );
//                 V(zr ,i2  ,j2   ,kl2      )	=   0.5 * ( xr[l] + V(xr ,i  ,j   ,kl    ) );
//                 V(zr ,i2  ,j2   ,k2 + nxny)	=   0.5 * ( xr[l] + V(xr ,i  ,j   ,k+nxny) );
            }
        }
    }
    */
    
    return;
}