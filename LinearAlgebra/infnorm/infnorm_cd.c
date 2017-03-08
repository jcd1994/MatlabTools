#include <math.h>
#include <stdint.h>
#include "mex.h"
#include <omp.h>

/* INFNORM_PAR_CD
 *
 * INPUT ARGUMENTS
 *  x: input array (N-D complex double array)
 *
 */

#define USE_PARALLEL    1
#define NUM_THREADS     64

inline double cfabs2( double x, double y );
void infnorm_complex( double *xr, double *xi, double *c, const uint32_t n );
void infnorm_real( double *x, double *c, const uint32_t n );

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
    /* length of input array */
    const uint32_t n = (const uint32_t)mxGetNumberOfElements(prhs[0]);
    
    /* get complex input data */
    double *xr = (double*)mxGetData(prhs[0]);
    double *xi = (double*)mxGetImagData(prhs[0]);
    bool isComplex = (bool)mxIsComplex(prhs[0]);
    
    /* infnorm output */
    plhs[0]   = mxCreateNumericMatrix(1, 1, mxDOUBLE_CLASS, mxREAL);
    double *c = (double*)mxGetData(plhs[0]);
    
    /* evaluate inf-norm */
    if(isComplex)
        infnorm_complex( xr, xi, c, n );
    else
        infnorm_real( xr, c, n );
    
    return;
}

inline double cfabs2( double x, double y ) {
    return x*x + y*y;
}

void infnorm_complex( double *xr, double *xi, double *c, const uint32_t n ) {
    
#if USE_PARALLEL
    
    uint32_t l;
    double max = 0.0;
    
#pragma omp parallel private(l) shared(max) num_threads(NUM_THREADS)
    {
        double priv_max = 0.0;
#pragma omp for private(l) schedule(static)
        for (l = 0; l < n; ++l) {
            priv_max = fmax(cfabs2(xr[l],xi[l]),priv_max);
        }
#pragma omp flush(max)
        if (priv_max > max) {
#pragma omp critical
            max = fmax(max,priv_max);
        }
    }
    
#else
    
    uint32_t l;
    double max = cfabs2(xr[0],xi[0]);
    
    for(l = 1; l < n; ++l) {
        max = fmax(cfabs2(xr[l],xi[l]),max);
    }
    
#endif
    
    *c = sqrt(max);
    return;
}

void infnorm_real( double *x, double *c, const uint32_t n ) {
    
#if USE_PARALLEL
    
    uint32_t l;
    double max = 0.0;
    
#pragma omp parallel private(l) shared(max) num_threads(NUM_THREADS)
    {
        double priv_max = 0.0;
#pragma omp for private(l) schedule(static)
        for (l = 0; l < n; ++l) {
            priv_max = fmax(fabs(x[l]),priv_max);
        }
#pragma omp flush(max)
        if (priv_max > max) {
#pragma omp critical
            max = fmax(max,priv_max);
        }
    }
    
#else
    
    uint32_t l;
    double max = fabs(x[0]);
    
    for(l = 1; l < n; ++l) {
        max = fmax(fabs(x[l]),max);
    }
        
#endif
    
    *c = max;
    return;
}
