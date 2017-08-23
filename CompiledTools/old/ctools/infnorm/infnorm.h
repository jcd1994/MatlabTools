#ifndef _INFNORM_H_

#include <math.h>
#include <stdint.h>
#include <omp.h>
#include "mex.h"

/* INFNORM
 *
 * INPUT ARGUMENTS
 *  x: input array (N-D real or complex, double or float array)
 *
 */

#define INFNORM_USE_PARALLEL  1
#define ABS2(x,y)  (x*x + y*y)
#define MAX(x,y)   (x > y ? x : y)

/**************************************************************************
 * Complex double infnorm
 *************************************************************************/

void c_infnorm( double *xr, double *xi, double *c, const uint32_t n ) {
    
#if INFNORM_USE_PARALLEL
    
    uint32_t l;
    double max = 0.0;
    
#pragma omp parallel private(l) shared(max) num_threads(omp_get_max_threads())
    {
        double priv_max = 0.0;
#pragma omp for private(l) schedule(static)
        for (l = 0; l < n; ++l) {
            priv_max = MAX(ABS2(xr[l],xi[l]),priv_max);
        }
#pragma omp flush(max)
        if (priv_max > max) {
#pragma omp critical
            max = MAX(max,priv_max);
        }
    }
    
#else
    
    uint32_t l;
    double max = ABS2(xr[0],xi[0]);
    
    for(l = 1; l < n; ++l) {
        max = MAX(ABS2(xr[l],xi[l]),max);
    }
    
#endif
    
    *c = sqrt(max);
    return;
}

/**************************************************************************
 * Complex float infnorm
 *************************************************************************/

void c_infnorm_f( float *xr, float *xi, float *c, const uint32_t n ) {
    
#if INFNORM_USE_PARALLEL
    
    uint32_t l;
    float max = 0.0;
    
#pragma omp parallel private(l) shared(max) num_threads(omp_get_max_threads())
    {
        float tempc, priv_max = 0.0;
#pragma omp for private(l,tempc) schedule(static)
        for (l = 0; l < n; ++l) {
            tempc = ABS2(xr[l],xi[l]);
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
    float max = ABS2(xr[0],xi[0]), tempc = 0.0;
    
    for(l = 1; l < n; ++l) {
        tempc = ABS2(xr[l],xi[l]);
        max   = MAX(tempc,max);
    }
    
    *c = sqrt(max);
    
#endif
    
    return;
}


/**************************************************************************
 * Double infnorm
 *************************************************************************/

void f_infnorm( double *x, double *c, const uint32_t n ) {
    
#if INFNORM_USE_PARALLEL
    
    uint32_t l;
    double max = 0.0;
    
#pragma omp parallel private(l) shared(max) num_threads(omp_get_max_threads())
    {
        double priv_max = 0.0;
#pragma omp for private(l) schedule(static)
        for (l = 0; l < n; ++l) {
            priv_max = MAX(fabs(x[l]),priv_max);
        }
#pragma omp flush(max)
        if (priv_max > max) {
#pragma omp critical
            max = MAX(max,priv_max);
        }
    }
    
#else
    
    uint32_t l;
    double max = fabs(x[0]);
    
    for(l = 1; l < n; ++l) {
        max = MAX(fabs(x[l]),max);
    }
        
#endif
    
    *c = max;
    return;
}

/**************************************************************************
 * Float infnorm
 *************************************************************************/

void f_infnorm_f( float *x, float *c, const uint32_t n ) {
    
#if INFNORM_USE_PARALLEL
    
    uint32_t l;
    float max = 0.0;
    
#pragma omp parallel private(l) shared(max) num_threads(omp_get_max_threads())
    {
        float priv_max = 0.0;
#pragma omp for private(l) schedule(static)
        for (l = 0; l < n; ++l) {
            priv_max = MAX(fabs(x[l]),priv_max);
        }
#pragma omp flush(max)
        if (priv_max > max) {
#pragma omp critical
            max = MAX(max,priv_max);
        }
    }
    
#else
    
    uint32_t l;
    float max = fabs(x[0]);
    
    for(l = 1; l < n; ++l) {
        max = MAX(fabs(x[l]),max);
    }
        
#endif
    
    *c = max;
    return;
}

#endif