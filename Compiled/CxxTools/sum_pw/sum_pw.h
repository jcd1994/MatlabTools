#ifndef _SUM_PW_H_
#define _SUM_PW_H_

#include <math.h>
#include <stdint.h>
#include <omp.h>
#include <pthread.h>
#include "mex.h"
#include "matrix.h"

/* SUM_PW
 *
 * INPUT ARGUMENTS
 *  x: input array (N-D real or complex, double or float array)
 *
 */

void c_sum_pw( double *xr, double *xi, double *re_out, double *im_out, const uint32_t n );
void c_sum_pw_f( const float *xr, const float *xi, float *re_out, float *im_out, const uint32_t n );
void f_sum_pw( const double *x, double *out , const uint32_t n );
void f_sum_pw_f( const float *x, float *out, const uint32_t n );
void u8_sum_pw_u8( const mxLogical *x, double *out, const uint32_t n );
void *f_sum_pw_entry( void *arguments );
void *f_sum_pw_entry_f( void *arguments );
void *u8_sum_pw_entry_u8( void *arguments );

#define SUM_PW_USE_PARALLEL 0
#define SUM_PW_NUM_THREADS (omp_get_max_threads())
#define SUM_PW_INLINE //inline

#define N_BASE_CASE 512 /* Base case for recursion */

struct arg_struct {
    const double *x;
    double *out;
    const uint32_t n;
};
typedef struct arg_struct Args;

struct arg_struct_f {
    const float *x;
    float *out;
    const uint32_t n;
};
typedef struct arg_struct_f Args_f;

struct arg_struct_u8 {
    const mxLogical *x;
    double *out;
    const uint32_t n;
};
typedef struct arg_struct_u8 Args_u8;

/**************************************************************************
 * Complex double sum_pw
 *************************************************************************/

void c_sum_pw( double *xr, double *xi, double *re_out, double *im_out, const uint32_t n ) {
    
    /* Sequential version */
    //f_sum_pw( xr, re_out, n );
    //f_sum_pw( xi, im_out, n );
    
    /* Threaded version */
    pthread_t real_thread, imag_thread;
    Args real_args = (Args){ .x = xr, .out = re_out, .n = n };
    Args imag_args = (Args){ .x = xi, .out = im_out, .n = n };
    
    pthread_create(&real_thread, NULL, f_sum_pw_entry, &real_args);
    pthread_create(&imag_thread, NULL, f_sum_pw_entry, &imag_args);
    
    pthread_join(real_thread, NULL);
    pthread_join(imag_thread, NULL);
    
    return;
}

/**************************************************************************
 * Complex float sum_pw
 *************************************************************************/

void c_sum_pw_f( const float *xr, const float *xi, float *re_out, float *im_out, const uint32_t n ) {
    
    /* Sequential version */
    //f_sum_pw_f( xr, re_out, n );
    //f_sum_pw_f( xi, im_out, n );
    
    /* Threaded version */
    pthread_t real_thread, imag_thread;
    Args_f real_args = (Args_f){ .x = xr, .out = re_out, .n = n };
    Args_f imag_args = (Args_f){ .x = xi, .out = im_out, .n = n };
    
    pthread_create(&real_thread, NULL, f_sum_pw_entry_f, &real_args);
    pthread_create(&imag_thread, NULL, f_sum_pw_entry_f, &imag_args);
    
    pthread_join(real_thread, NULL);
    pthread_join(imag_thread, NULL);
    
    return;
}


/**************************************************************************
 * Double sum_pw
 *************************************************************************/

void *f_sum_pw_entry( void *arguments ) {
    Args *args = arguments;
    f_sum_pw( args->x, args->out, args->n );
}

SUM_PW_INLINE void f_sum_pw( const double *x, double *out , const uint32_t n ) {
    
    double sum;
    
    if(n == 0) {
        sum = 0.0; //Matlab convention for empty arrays
    } else if(n <= N_BASE_CASE) { //base case: naive summation for a sufficiently small array
        uint32_t i;
        sum = x[0];
        
#if SUM_PW_USE_PARALLEL
#pragma omp parallel for num_threads(SUM_PW_NUM_THREADS) reduction(+:sum)
#endif /* SUM_PW_USE_PARALLEL */
        for(i = 1; i < n; ++i)
            sum += x[i];
        
    } else { //divide and conquer: recursively sum two halves of the array
        const uint32_t m = n / 2;
        double sum1, sum2;
        f_sum_pw(&x[0],&sum1,m);
        f_sum_pw(&x[m],&sum2,n-m);
        sum = sum1 + sum2;
    }
    
    *out = sum;
    return;
}

/**************************************************************************
 * Float sum_pw
 *************************************************************************/

void *f_sum_pw_entry_f( void *arguments ) {
    Args_f *args = arguments;
    f_sum_pw_f( args->x, args->out, args->n );
}

SUM_PW_INLINE void f_sum_pw_f( const float *x, float *out, const uint32_t n ) {
    
    float sum;
    
    if(n == 0) {
        sum = 0.0; //Matlab convention for empty arrays
    } else if(n <= N_BASE_CASE) { //base case: naive summation for a sufficiently small array
        sum = x[0];
        uint32_t i;
        
#if SUM_PW_USE_PARALLEL
#pragma omp parallel for num_threads(SUM_PW_NUM_THREADS) reduction(+:sum)
#endif /* SUM_PW_USE_PARALLEL */
        for(i = 1; i < n; ++i)
            sum += x[i];
        
    } else { //divide and conquer: recursively sum two halves of the array
        const uint32_t m = n / 2;
        float sum1, sum2;
        f_sum_pw_f(&x[0],&sum1,m);
        f_sum_pw_f(&x[m],&sum2,n-m);
        sum = sum1 + sum2;
    }
    
    *out = sum;
    return;
}

/**************************************************************************
 * mxLogical sum_pw
 *************************************************************************/

void *u8_sum_pw_entry_u8( void *arguments ) {
    Args_u8 *args = arguments;
    u8_sum_pw_u8( args->x, args->out, args->n );
}

SUM_PW_INLINE void u8_sum_pw_u8( const mxLogical *x, double *out, const uint32_t n ) {
    
    double sumd;
    uint32_t sum;
    
    if(n == 0) {
        sum  = 0; //Matlab convention for empty arrays
        sumd = 0.0;
    } else if(n <= N_BASE_CASE) { //base case: naive summation for a sufficiently small array
        sum = x[0];
        uint32_t i;
        
#if SUM_PW_USE_PARALLEL
#pragma omp parallel for num_threads(SUM_PW_NUM_THREADS) reduction(+:sum)
#endif /* SUM_PW_USE_PARALLEL */
        for(i = 1; i < n; ++i){
            sum += x[i]; //(uint32_t)
        }
        sumd = (double)sum;
    } else { //divide and conquer: recursively sum two halves of the array
        const uint32_t m = n / 2;
        double sumd1, sumd2;
        u8_sum_pw_u8(&x[0],&sumd1,m);
        u8_sum_pw_u8(&x[m],&sumd2,n-m);
        sumd = sumd1 + sumd2;
    }
    
    *out = sumd;
    return;
}

#endif /* _SUM_PW_H_ */