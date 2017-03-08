/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * refineGrid3D_conv_terminate.c
 *
 * Code generation for function 'refineGrid3D_conv_terminate'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "refineGrid3D_conv.h"
#include "refineGrid3D_conv_terminate.h"
#include "refineGrid3D_conv_data.h"

/* Function Definitions */
void refineGrid3D_conv_atexit(void)
{
  emlrtStack st = { NULL, NULL, NULL };

  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  st.tls = emlrtRootTLSGlobal;
  emlrtEnterRtStackR2012b(&st);
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

void refineGrid3D_conv_terminate(void)
{
  emlrtStack st = { NULL, NULL, NULL };

  st.tls = emlrtRootTLSGlobal;
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/* End of code generation (refineGrid3D_conv_terminate.c) */
