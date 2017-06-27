/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * test_parfor_data.c
 *
 * Code generation for function 'test_parfor_data'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "test_parfor.h"
#include "test_parfor_data.h"
#include <stdio.h>

/* Variable Definitions */
emlrtCTX emlrtRootTLSGlobal = NULL;
const volatile char_T *emlrtBreakCheckR2012bFlagVar;
omp_lock_t emlrtLockGlobal;
omp_nest_lock_t emlrtNestLockGlobal;
emlrtContext emlrtContextGlobal = { true, false, 131418U, NULL, "test_parfor",
  NULL, false, { 2045744189U, 2170104910U, 2743257031U, 4284093946U }, NULL };

emlrtRSInfo i_emlrtRSI = { 166, "fminsearch",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/optimfun/fminsearch.m" };

emlrtRSInfo j_emlrtRSI = { 321, "fminsearch",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/optimfun/fminsearch.m" };

emlrtRSInfo k_emlrtRSI = { 77, "eml_sort_idx",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/eml/eml_sort_idx.m" };

emlrtRSInfo l_emlrtRSI = { 264, "eml_sort_idx",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/eml/eml_sort_idx.m" };

emlrtRSInfo n_emlrtRSI = { 16, "max",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/datafun/max.m" };

emlrtRSInfo o_emlrtRSI = { 18, "eml_min_or_max",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/eml/eml_min_or_max.m" };

emlrtRSInfo p_emlrtRSI = { 96, "eml_min_or_max",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/eml/eml_min_or_max.m" };

emlrtRSInfo q_emlrtRSI = { 202, "eml_min_or_max",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/eml/eml_min_or_max.m" };

emlrtRSInfo r_emlrtRSI = { 229, "eml_min_or_max",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/eml/eml_min_or_max.m" };

/* End of code generation (test_parfor_data.c) */
