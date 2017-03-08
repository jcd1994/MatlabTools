/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_refineGrid3D_conv_mex.c
 *
 * Code generation for function '_coder_refineGrid3D_conv_mex'
 *
 */

/* Include files */
#include "refineGrid3D_conv.h"
#include "_coder_refineGrid3D_conv_mex.h"
#include "refineGrid3D_conv_terminate.h"
#include "_coder_refineGrid3D_conv_api.h"
#include "refineGrid3D_conv_initialize.h"
#include "refineGrid3D_conv_data.h"

/* Function Declarations */
static void refineGrid3D_conv_mexFunction(int32_T nlhs, mxArray *plhs[1],
  int32_T nrhs, const mxArray *prhs[2]);

/* Function Definitions */
static void refineGrid3D_conv_mexFunction(int32_T nlhs, mxArray *plhs[1],
  int32_T nrhs, const mxArray *prhs[2])
{
  int32_T n;
  const mxArray *inputs[2];
  const mxArray *outputs[1];
  int32_T b_nlhs;
  emlrtStack st = { NULL, NULL, NULL };

  st.tls = emlrtRootTLSGlobal;

  /* Check for proper number of arguments. */
  if (nrhs != 2) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 2, 4,
                        17, "refineGrid3D_conv");
  }

  if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 17,
                        "refineGrid3D_conv");
  }

  /* Temporary copy for mex inputs. */
  for (n = 0; n < nrhs; n++) {
    inputs[n] = prhs[n];
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(&st);
    }
  }

  /* Call the function. */
  refineGrid3D_conv_api(inputs, outputs);

  /* Copy over outputs to the caller. */
  if (nlhs < 1) {
    b_nlhs = 1;
  } else {
    b_nlhs = nlhs;
  }

  emlrtReturnArrays(b_nlhs, plhs, outputs);

  /* Module termination. */
  refineGrid3D_conv_terminate();
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs, const mxArray
                 *prhs[])
{
  /* Initialize the memory manager. */
  mexAtExit(refineGrid3D_conv_atexit);

  /* Module initialization. */
  refineGrid3D_conv_initialize();

  /* Dispatch the entry-point. */
  refineGrid3D_conv_mexFunction(nlhs, plhs, nrhs, prhs);
}

/* End of code generation (_coder_refineGrid3D_conv_mex.c) */
