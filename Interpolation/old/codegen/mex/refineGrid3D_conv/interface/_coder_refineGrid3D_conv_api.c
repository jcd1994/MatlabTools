/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_refineGrid3D_conv_api.c
 *
 * Code generation for function '_coder_refineGrid3D_conv_api'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "refineGrid3D_conv.h"
#include "_coder_refineGrid3D_conv_api.h"
#include "refineGrid3D_conv_emxutil.h"
#include "refineGrid3D_conv_data.h"

/* Variable Definitions */
static emlrtRTEInfo c_emlrtRTEI = { 1, 1, "_coder_refineGrid3D_conv_api", "" };

/* Function Declarations */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real32_T *y);
static real_T c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *K, const
  char_T *identifier);
static real_T d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real32_T *ret);
static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *V, const
  char_T *identifier, emxArray_real32_T *y);
static const mxArray *emlrt_marshallOut(const emxArray_real32_T *u);
static real_T f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId);

/* Function Definitions */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real32_T *y)
{
  e_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static real_T c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *K, const
  char_T *identifier)
{
  real_T y;
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  y = d_emlrt_marshallIn(sp, emlrtAlias(K), &thisId);
  emlrtDestroyArray(&K);
  return y;
}

static real_T d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = f_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real32_T *ret)
{
  int32_T iv41[3];
  int32_T i;
  int32_T iv42[3];
  boolean_T bv0[3] = { true, true, true };

  for (i = 0; i < 3; i++) {
    iv41[i] = -1;
  }

  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "single", false, 3U, iv41, &bv0[0],
    iv42);
  ret->size[0] = iv42[0];
  ret->size[1] = iv42[1];
  ret->size[2] = iv42[2];
  ret->allocatedSize = ret->size[0] * ret->size[1] * ret->size[2];
  ret->data = (real32_T *)mxGetData(src);
  ret->canFreeData = false;
  emlrtDestroyArray(&src);
}

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *V, const
  char_T *identifier, emxArray_real32_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  b_emlrt_marshallIn(sp, emlrtAlias(V), &thisId, y);
  emlrtDestroyArray(&V);
}

static const mxArray *emlrt_marshallOut(const emxArray_real32_T *u)
{
  const mxArray *y;
  static const int32_T iv40[3] = { 0, 0, 0 };

  const mxArray *m0;
  y = NULL;
  m0 = emlrtCreateNumericArray(3, iv40, mxSINGLE_CLASS, mxREAL);
  mxSetData((mxArray *)m0, (void *)u->data);
  emlrtSetDimensions((mxArray *)m0, u->size, 3);
  emlrtAssign(&y, m0);
  return y;
}

static real_T f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId)
{
  real_T ret;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 0U, 0);
  ret = *(real_T *)mxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

void refineGrid3D_conv_api(const mxArray * const prhs[2], const mxArray *plhs[1])
{
  emxArray_real32_T *V;
  emxArray_real32_T *Vk;
  real_T K;
  emlrtStack st = { NULL, NULL, NULL };

  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  emxInit_real32_T(&st, &V, 3, &c_emlrtRTEI, true);
  emxInit_real32_T(&st, &Vk, 3, &c_emlrtRTEI, true);

  /* Marshall function inputs */
  emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "V", V);
  K = c_emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "K");

  /* Invoke the target function */
  refineGrid3D_conv(&st, V, K, Vk);

  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(Vk);
  Vk->canFreeData = false;
  emxFree_real32_T(&Vk);
  V->canFreeData = false;
  emxFree_real32_T(&V);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

/* End of code generation (_coder_refineGrid3D_conv_api.c) */
