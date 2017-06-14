/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * eps.h
 *
 * Code generation for function 'eps'
 *
 */

#ifndef __EPS_H__
#define __EPS_H__

/* Include files */
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "mwmathutil.h"
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include "blas.h"
#include "rtwtypes.h"
#include "omp.h"
#include "test_parfor_types.h"

/* Function Declarations */
extern real_T eps(real_T x);

#ifdef __WATCOMC__

#pragma aux eps value [8087];

#endif
#endif

/* End of code generation (eps.h) */
