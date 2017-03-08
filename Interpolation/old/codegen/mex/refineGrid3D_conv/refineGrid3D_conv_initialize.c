/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * refineGrid3D_conv_initialize.c
 *
 * Code generation for function 'refineGrid3D_conv_initialize'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "refineGrid3D_conv.h"
#include "refineGrid3D_conv_initialize.h"
#include "refineGrid3D_conv_data.h"

/* Function Definitions */
void refineGrid3D_conv_initialize(void)
{
  emlrtStack st = { NULL, NULL, NULL };

  emlrtBreakCheckR2012bFlagVar = emlrtGetBreakCheckFlagAddressR2012b();
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, 0);
  emlrtEnterRtStackR2012b(&st);
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
}

/* End of code generation (refineGrid3D_conv_initialize.c) */
