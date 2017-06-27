/*
 * squareTensorField_terminate.c
 *
 * Code generation for function 'squareTensorField_terminate'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "squareTensorField.h"
#include "squareTensorField_terminate.h"
#include "_coder_squareTensorField_mex.h"
#include "squareTensorField_data.h"

/* Function Definitions */
void squareTensorField_atexit(void)
{
  emlrtStack st = { NULL, NULL, NULL };

  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtEnterRtStackR2012b(&st);

  /* Free instance data */
  covrtFreeInstanceData(&emlrtCoverageInstance);
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

void squareTensorField_terminate(void)
{
  emlrtStack st = { NULL, NULL, NULL };

  st.tls = emlrtRootTLSGlobal;
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/* End of code generation (squareTensorField_terminate.c) */
