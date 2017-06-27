/*
 * _coder_squareTensorField_api.c
 *
 * Code generation for function '_coder_squareTensorField_api'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "squareTensorField.h"
#include "_coder_squareTensorField_api.h"
#include "squareTensorField_data.h"

/* Function Declarations */
static real_T (*b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[2359296];
static real_T (*c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[2359296];
static real_T (*emlrt_marshallIn(const emlrtStack *sp, const mxArray *D, const
  char_T *identifier))[2359296];
static void emlrt_marshallOut(const real_T u[2359296], const mxArray *y);

/* Function Definitions */
static real_T (*b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[2359296]
{
  real_T (*y)[2359296];
  y = c_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}
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
  static void emlrt_marshallOut(const real_T u[2359296], const mxArray *y)
{
  static const int32_T iv0[5] = { 64, 64, 64, 3, 3 };

  mxSetData((mxArray *)y, (void *)u);
  emlrtSetDimensions((mxArray *)y, iv0, 5);
}

void squareTensorField_api(const mxArray *prhs[1], const mxArray *plhs[1])
{
  real_T (*D)[2359296];
  emlrtStack st = { NULL, NULL, NULL };

  st.tls = emlrtRootTLSGlobal;
  prhs[0] = emlrtProtectR2012b(prhs[0], 0, true, -1);

  /* Marshall function inputs */
  D = emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "D");

  /* Invoke the target function */
  squareTensorField(&st, *D);

  /* Marshall function outputs */
  emlrt_marshallOut(*D, prhs[0]);
  plhs[0] = prhs[0];
}

/* End of code generation (_coder_squareTensorField_api.c) */
