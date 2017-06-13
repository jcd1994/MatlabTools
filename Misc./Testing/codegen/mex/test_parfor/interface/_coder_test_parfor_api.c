/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_test_parfor_api.c
 *
 * Code generation for function '_coder_test_parfor_api'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "test_parfor.h"
#include "_coder_test_parfor_api.h"
#include "test_parfor_data.h"
#include <stdio.h>

/* Function Definitions */
void test_parfor_api(void)
{
  emlrtStack st = { NULL, NULL, NULL };

  st.tls = emlrtRootTLSGlobal;

  /* Invoke the target function */
  test_parfor(&st);
}

/* End of code generation (_coder_test_parfor_api.c) */
