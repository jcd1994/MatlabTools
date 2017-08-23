#include <math.h>
#include <stdint.h>
#include "mex.h"
#include <omp.h>

/* INFNORM_PAR_CS
 *
 * INPUT ARGUMENTS
 *  x: input array (N-D complex single array)
 *
 */

#define USE_PARALLEL    1
#define NUM_THREADS     64
#define cfabs2(x,y)     (x*x + y*y)
#define MAX(x,y)        (x > y ? x : y)

void infnorm_complex( float *xr, float *xi, float *c, const uint32_t n );
void infnorm_real( float *x, float *c, const uint32_t n );

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
    /* length of input array */
    const uint32_t n = (const uint32_t)mxGetNumberOfElements(prhs[0]);
    
    /* get complex input data */
    float *xr = (float*)mxGetData(prhs[0]);
    float *xi = (float*)mxGetImagData(prhs[0]);
    bool isComplex = (bool)mxIsComplex(prhs[0]);
    
    /* infnorm output */
    plhs[0]  = mxCreateNumericMatrix(1, 1, mxSINGLE_CLASS, mxREAL);
    float *c = (float*)mxGetData(plhs[0]);
    
    /* evaluate inf-norm */
    if(isComplex)
        infnorm_complex( xr, xi, c, n );
    else
        infnorm_real( xr, c, n );
    
    return;
}

void infnorm_complex( float *xr, float *xi, float *c, const uint32_t n ) {
    
#if USE_PARALLEL
    
    uint32_t l;
    float max = 0.0;
    
#pragma omp parallel private(l) shared(max) num_threads(NUM_THREADS)
    {
        float tempc, priv_max = 0.0;
#pragma omp for private(l,tempc) schedule(static)
        for (l = 0; l < n; ++l) {
            tempc = cfabs2(xr[l],xi[l]);
            priv_max = MAX(tempc,priv_max);
        }
#pragma omp flush(max)
        if (priv_max > max) {
#pragma omp critical
            max = MAX(max,priv_max);
        }
    }
    
    *c = sqrt(max);
    
#else
    
    uint32_t l;
    float max = cfabs2(xr[0],xi[0]), tempc = 0.0;
    
    for(l = 1; l < n; ++l) {
        tempc = cfabs2(xr[l],xi[l]);
        max   = MAX(tempc,max);
    }
    
    *c = sqrt(max);
    
#endif
    
    return;
}

void infnorm_real( float *x, float *c, const uint32_t n ) {
    
#if USE_PARALLEL
    
    uint32_t l;
    float max = 0.0;
    
#pragma omp parallel private(l) shared(max) num_threads(NUM_THREADS)
    {
        float tempc, priv_max = 0.0;
#pragma omp for private(l,tempc) schedule(static)
        for (l = 0; l < n; ++l) {
            tempc = fabs(x[l]);
            priv_max = MAX(tempc,priv_max);
        }
#pragma omp flush(max)
        if (priv_max > max) {
#pragma omp critical
            max = MAX(max,priv_max);
        }
    }
    
    *c = max;
    
#else
    
    uint32_t l;
    float max = fabs(x[0]), tempc = 0.0;
    
    for(l = 1; l < n; ++l) {
        tempc = fabs(x[l]);
        max   = MAX(tempc,max);
    }
    
    *c = max;
    
#endif
    
    return;
}
