#ifndef _SUM_KAHAN_H_
#define _SUM_KAHAN_H_

#include <math.h>
#include <stdint.h>
#include <omp.h>
#include <pthread.h>
#include "mex.h"

/* SUM_KAHAN
 *
 * INPUT ARGUMENTS
 *  x: input array (N-D real or complex, double or float array)
 *
 */

void c_sum_kahan( double *xr, double *xi, double *re_out, double *im_out, const uint32_t n );
void c_sum_kahan_f( float *xr, float *xi, float *re_out, float *im_out, const uint32_t n );
void f_sum_kahan( double *x, double *out, const uint32_t n );
void f_sum_kahan_f( float *x, float *out, const uint32_t n );
void *f_sum_kahan_entry( void *arguments );
void *f_sum_kahan_entry_f( void *arguments );

#define SUM_KAHAN_USE_PARALLEL  0
#define SUM_KAHAN_NUM_THREADS (omp_get_max_threads())

struct arg_struct {
    double *x;
    double *out;
    uint32_t n;
};
typedef struct arg_struct Args;

struct arg_struct_f {
    float *x;
    float *out;
    uint32_t n;
};
typedef struct arg_struct_f Args_f;

/**************************************************************************
 * Complex double sum_kahan
 *************************************************************************/

void c_sum_kahan( double *xr, double *xi, double *re_out, double *im_out, const uint32_t n ) {
    
    /* Sequential version */
    //f_sum_kahan( xr, re_out, n );
    //f_sum_kahan( xi, im_out, n );
    
    /* Threaded version */
    pthread_t real_thread, imag_thread;
    Args real_args = (Args){ .x = xr, .out = re_out, .n = n };
    Args imag_args = (Args){ .x = xi, .out = im_out, .n = n };
    
    pthread_create(&real_thread, NULL, f_sum_kahan_entry, &real_args);
    pthread_create(&imag_thread, NULL, f_sum_kahan_entry, &imag_args);
    
    pthread_join(real_thread, NULL);
    pthread_join(imag_thread, NULL);
    
    return;
}

/**************************************************************************
 * Complex float sum_kahan
 *************************************************************************/

void c_sum_kahan_f( float *xr, float *xi, float *re_out, float *im_out, const uint32_t n ) {
    
    /* Sequential version */
    //f_sum_kahan_f( xr, re_out, n );
    //f_sum_kahan_f( xi, im_out, n );
    
    /* Threaded version */
    pthread_t real_thread, imag_thread;
    Args_f real_args = (Args_f){ .x = xr, .out = re_out, .n = n };
    Args_f imag_args = (Args_f){ .x = xi, .out = im_out, .n = n };
    
    pthread_create(&real_thread, NULL, f_sum_kahan_entry_f, &real_args);
    pthread_create(&imag_thread, NULL, f_sum_kahan_entry_f, &imag_args);
    
    pthread_join(real_thread, NULL);
    pthread_join(imag_thread, NULL);
    
    return;
}


/**************************************************************************
 * Double sum_kahan
 *************************************************************************/

void *f_sum_kahan_entry( void *arguments ) {
    Args *args = arguments;
    f_sum_kahan( args->x, args->out, args->n );
}

void f_sum_kahan( double *x, double *out, const uint32_t n ) {
    
    uint32_t i;
    double sum = 0.0;
    double drift = 0.0; // A running compensation for lost low-order bits.
    
    for(i = 0; i < n; ++i) {
        double y = x[i] - drift; // So far, so good: drift is zero.
        double t = sum + y;      // Alas, sum is big, y small, so low-order digits of y are lost.
        drift = (t - sum) - y;   // (t - sum) cancels the high-order part of y; subtracting y recovers negative (low part of y)
        sum = t;                 // Algebraically, drift should always be zero. Beware overly-aggressive optimizing compilers!
    }                            // Next time around, the lost low part will be added to y in a fresh attempt.
    
    *out = sum;
    
    return;
}

/**************************************************************************
 * Float sum_kahan
 *************************************************************************/

void *f_sum_kahan_entry_f( void *arguments ) {
    Args_f *args = arguments;
    f_sum_kahan_f( args->x, args->out, args->n );
}

void f_sum_kahan_f( float *x, float *out, const uint32_t n ) {
    
    uint32_t i;
    float sum = 0.0;
    float drift = 0.0; // A running compensation for lost low-order bits.
    
    for(i = 0; i < n; ++i) {
        float y = x[i] - drift; // So far, so good: drift is zero.
        float t = sum + y;      // Alas, sum is big, y small, so low-order digits of y are lost.
        drift = (t - sum) - y;  // (t - sum) cancels the high-order part of y; subtracting y recovers negative (low part of y)
        sum = t;                // Algebraically, drift should always be zero. Beware overly-aggressive optimizing compilers!
    }                           // Next time around, the lost low part will be added to y in a fresh attempt.
    
    *out = sum;
    
    return;
}

#endif