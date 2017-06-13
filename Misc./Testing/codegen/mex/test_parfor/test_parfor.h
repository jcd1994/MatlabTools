/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * test_parfor.h
 *
 * Code generation for function 'test_parfor'
 *
 */

#ifndef __TEST_PARFOR_H__
#define __TEST_PARFOR_H__

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
extern real_T func(const real_T x[50]);

#ifdef __WATCOMC__

#pragma aux func value [8087];

#endif

extern void test_parfor(const emlrtStack *sp);

#endif

/* End of code generation (test_parfor.h) */
