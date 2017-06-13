/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_test_parfor_mex.c
 *
 * Code generation for function '_coder_test_parfor_mex'
 *
 */

/* Include files */
#include "test_parfor.h"
#include "_coder_test_parfor_mex.h"
#include "test_parfor_terminate.h"
#include "_coder_test_parfor_api.h"
#include "test_parfor_initialize.h"
#include "test_parfor_data.h"
#include <stdio.h>

/* Variable Definitions */
static jmp_buf emlrtJBEnviron;

/* Function Declarations */
static void test_parfor_mexFunction(int32_T nlhs, int32_T nrhs);

/* Function Definitions */
static void test_parfor_mexFunction(int32_T nlhs, int32_T nrhs)
{
  emlrtStack st = { NULL, NULL, NULL };

  st.tls = emlrtRootTLSGlobal;

  /* Check for proper number of arguments. */
  if (nrhs != 0) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 0, 4,
                        11, "test_parfor");
  }

  if (nlhs > 0) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 11,
                        "test_parfor");
  }

  /* Call the function. */
  test_parfor_api();

  /* Module termination. */
  test_parfor_terminate();
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs, const mxArray
                 *prhs[])
{
  emlrtStack st = { NULL, NULL, NULL };

  (void)plhs;
  (void)prhs;

  /* Initialize the memory manager. */
  omp_init_lock(&emlrtLockGlobal);
  omp_init_nest_lock(&emlrtNestLockGlobal);
  emlrtLoadLibrary("/usr/local/MATLAB/R2015a/sys/os/glnxa64/libiomp5.so");
  mexAtExit(test_parfor_atexit);

  /* Module initialization. */
  test_parfor_initialize();
  st.tls = emlrtRootTLSGlobal;
  emlrtSetJmpBuf(&st, &emlrtJBEnviron);
  if (setjmp(emlrtJBEnviron) == 0) {
    /* Dispatch the entry-point. */
    test_parfor_mexFunction(nlhs, nrhs);
    omp_destroy_lock(&emlrtLockGlobal);
    omp_destroy_nest_lock(&emlrtNestLockGlobal);
  } else {
    omp_destroy_lock(&emlrtLockGlobal);
    omp_destroy_nest_lock(&emlrtNestLockGlobal);
    emlrtReportParallelRunTimeError(&st);
  }
}

/* End of code generation (_coder_test_parfor_mex.c) */
