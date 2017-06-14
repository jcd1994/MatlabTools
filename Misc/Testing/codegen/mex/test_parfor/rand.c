/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * rand.c
 *
 * Code generation for function 'rand'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "test_parfor.h"
#include "rand.h"
#include <stdio.h>

/* Function Definitions */
void b_rand(real_T r[750])
{
  emlrtRandu(r, 750);
}

/* End of code generation (rand.c) */
