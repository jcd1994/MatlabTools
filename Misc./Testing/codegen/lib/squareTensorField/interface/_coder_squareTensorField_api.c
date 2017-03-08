/*
 * File: _coder_squareTensorField_api.c
 *
 * MATLAB Coder version            : 3.1
 * C/C++ source code generated on  : 12-May-2016 09:08:19
 */

/* Include Files */
#include "tmwtypes.h"
#include "_coder_squareTensorField_api.h"
#include "_coder_squareTensorField_mex.h"

/* Variable Definitions */
emlrtCTX emlrtRootTLSGlobal = NULL;
emlrtContext emlrtContextGlobal = { true, false, 131434U, NULL,
  "squareTensorField", NULL, false, { 2045744189U, 2170104910U, 2743257031U,
    4284093946U }, NULL };

/* Function Declarations */
static real_T (*b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[2359296];
static real_T (*c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[2359296];
static real_T (*emlrt_marshallIn(const emlrtStack *sp, const mxArray *D, const
  char_T *identifier))[2359296];
static void emlrt_marshallOut(const real_T u[2359296], const mxArray *y);

/* Function Definitions */

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 * Return Type  : real_T (*)[2359296]
 */
static real_T (*b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[2359296]
{
  real_T (*y)[2359296];
  y = c_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}
/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 * Return Type  : real_T (*)[2359296]
 */
  static real_T (*c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[2359296]
{
  real_T (*ret)[2359296];
  static const int32_T dims[5] = { 64, 64, 64, 3, 3 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 5U, dims);
  ret = (real_T (*)[2359296])mxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *D
 *                const char_T *identifier
 * Return Type  : real_T (*)[2359296]
 */
static real_T (*emlrt_marshallIn(const emlrtStack *sp, const mxArray *D, const
  char_T *identifier))[2359296]
{
  real_T (*y)[2359296];
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = b_emlrt_marshallIn(sp, emlrtAlias(D), &thisId);
  emlrtDestroyArray(&D);
  return y;
}
/*
 * Arguments    : const real_T u[2359296]
 *                const mxArray *y
 * Return Type  : void
 */
  static void emlrt_marshallOut(const real_T u[2359296], const mxArray *y)
{
  static const int32_T iv0[5] = { 64, 64, 64, 3, 3 };

  mxSetData((mxArray *)y, (void *)u);
  emlrtSetDimensions((mxArray *)y, iv0, 5);
}

/*
 * Arguments    : const mxArray *prhs[1]
 *                const mxArray *plhs[1]
 * Return Type  : void
 */
void squareTensorField_api(const mxArray *prhs[1], const mxArray *plhs[1])
{
  real_T (*D)[2359296];
  emlrtStack st = { NULL, NULL, NULL };

  st.tls = emlrtRootTLSGlobal;
  prhs[0] = emlrtProtectR2012b(prhs[0], 0, true, -1);

  /* Marshall function inputs */
  D = emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "D");

  /* Invoke the target function */
  squareTensorField(*D);

  /* Marshall function outputs */
  emlrt_marshallOut(*D, prhs[0]);
  plhs[0] = prhs[0];
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void squareTensorField_atexit(void)
{
  emlrtStack st = { NULL, NULL, NULL };

  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtEnterRtStackR2012b(&st);
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
  squareTensorField_xil_terminate();
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void squareTensorField_initialize(void)
{
  emlrtStack st = { NULL, NULL, NULL };

  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, 0);
  emlrtEnterRtStackR2012b(&st);
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void squareTensorField_terminate(void)
{
  emlrtStack st = { NULL, NULL, NULL };

  st.tls = emlrtRootTLSGlobal;
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/*
 * File trailer for _coder_squareTensorField_api.c
 *
 * [EOF]
 */
