/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * fprintf.c
 *
 * Code generation for function 'fprintf'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "test_parfor.h"
#include "fprintf.h"
#include <stdio.h>

/* Variable Definitions */
static emlrtRSInfo g_emlrtRSI = { 35, "fprintf",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/iofun/fprintf.m" };

static emlrtRSInfo s_emlrtRSI = { 38, "fprintf",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/iofun/fprintf.m" };

static emlrtMCInfo g_emlrtMCI = { 69, 14, "fprintf",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/iofun/fprintf.m" };

static emlrtRSInfo t_emlrtRSI = { 69, "fprintf",
  "/usr/local/MATLAB/R2015a/toolbox/eml/lib/matlab/iofun/fprintf.m" };

/* Function Declarations */
static real_T b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static const mxArray *b_feval(const emlrtStack *sp, const mxArray *b, const
  mxArray *c, const mxArray *d, const mxArray *e, emlrtMCInfo *location);
static real_T c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId);
static real_T c_fprintf(const emlrtStack *sp);
static real_T e_fprintf(const emlrtStack *sp);
static real_T emlrt_marshallIn(const emlrtStack *sp, const mxArray *c_feval,
  const char_T *identifier);
static const mxArray *feval(const emlrtStack *sp, const mxArray *b, const
  mxArray *c, const mxArray *d, emlrtMCInfo *location);
static real_T g_fprintf(const emlrtStack *sp, real_T varargin_1);

/* Function Definitions */
static real_T b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = c_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static const mxArray *b_feval(const emlrtStack *sp, const mxArray *b, const
  mxArray *c, const mxArray *d, const mxArray *e, emlrtMCInfo *location)
{
  const mxArray *pArrays[4];
  const mxArray *m9;
  pArrays[0] = b;
  pArrays[1] = c;
  pArrays[2] = d;
  pArrays[3] = e;
  return emlrtCallMATLABR2012b(sp, 1, &m9, 4, pArrays, "feval", true, location);
}

static real_T c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId)
{
  real_T ret;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 0U, 0);
  ret = *(real_T *)mxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static real_T c_fprintf(const emlrtStack *sp)
{
  int32_T i0;
  static const char_T cv2[7] = { 'f', 'p', 'r', 'i', 'n', 't', 'f' };

  char_T u[7];
  const mxArray *y;
  static const int32_T iv0[2] = { 1, 7 };

  const mxArray *m0;
  const mxArray *b_y;
  static const char_T formatSpec[15] = { 'R', 'e', 'g', 'u', 'l', 'a', 'r', ' ',
    'l', 'o', 'o', 'p', ':', '\\', 'n' };

  char_T b_u[15];
  const mxArray *c_y;
  static const int32_T iv1[2] = { 1, 15 };

  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  for (i0 = 0; i0 < 7; i0++) {
    u[i0] = cv2[i0];
  }

  y = NULL;
  m0 = emlrtCreateCharArray(2, iv0);
  emlrtInitCharArrayR2013a(sp, 7, m0, &u[0]);
  emlrtAssign(&y, m0);
  b_y = NULL;
  m0 = emlrtCreateDoubleScalar(1.0);
  emlrtAssign(&b_y, m0);
  for (i0 = 0; i0 < 15; i0++) {
    b_u[i0] = formatSpec[i0];
  }

  c_y = NULL;
  m0 = emlrtCreateCharArray(2, iv1);
  emlrtInitCharArrayR2013a(sp, 15, m0, &b_u[0]);
  emlrtAssign(&c_y, m0);
  st.site = &t_emlrtRSI;
  return emlrt_marshallIn(&st, feval(&st, y, b_y, c_y, &g_emlrtMCI), "feval");
}

static real_T e_fprintf(const emlrtStack *sp)
{
  int32_T i1;
  static const char_T cv3[7] = { 'f', 'p', 'r', 'i', 'n', 't', 'f' };

  char_T u[7];
  const mxArray *y;
  static const int32_T iv3[2] = { 1, 7 };

  const mxArray *m2;
  const mxArray *b_y;
  static const char_T formatSpec[14] = { 'P', 'a', 'r', 'f', 'o', 'r', ' ', 'l',
    'o', 'o', 'p', ':', '\\', 'n' };

  char_T b_u[14];
  const mxArray *c_y;
  static const int32_T iv4[2] = { 1, 14 };

  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  for (i1 = 0; i1 < 7; i1++) {
    u[i1] = cv3[i1];
  }

  y = NULL;
  m2 = emlrtCreateCharArray(2, iv3);
  emlrtInitCharArrayR2013a(sp, 7, m2, &u[0]);
  emlrtAssign(&y, m2);
  b_y = NULL;
  m2 = emlrtCreateDoubleScalar(1.0);
  emlrtAssign(&b_y, m2);
  for (i1 = 0; i1 < 14; i1++) {
    b_u[i1] = formatSpec[i1];
  }

  c_y = NULL;
  m2 = emlrtCreateCharArray(2, iv4);
  emlrtInitCharArrayR2013a(sp, 14, m2, &b_u[0]);
  emlrtAssign(&c_y, m2);
  st.site = &t_emlrtRSI;
  return emlrt_marshallIn(&st, feval(&st, y, b_y, c_y, &g_emlrtMCI), "feval");
}

static real_T emlrt_marshallIn(const emlrtStack *sp, const mxArray *c_feval,
  const char_T *identifier)
{
  real_T y;
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  y = b_emlrt_marshallIn(sp, emlrtAlias(c_feval), &thisId);
  emlrtDestroyArray(&c_feval);
  return y;
}

static const mxArray *feval(const emlrtStack *sp, const mxArray *b, const
  mxArray *c, const mxArray *d, emlrtMCInfo *location)
{
  const mxArray *pArrays[3];
  const mxArray *m8;
  pArrays[0] = b;
  pArrays[1] = c;
  pArrays[2] = d;
  return emlrtCallMATLABR2012b(sp, 1, &m8, 3, pArrays, "feval", true, location);
}

static real_T g_fprintf(const emlrtStack *sp, real_T varargin_1)
{
  int32_T i2;
  static const char_T cv4[7] = { 'f', 'p', 'r', 'i', 'n', 't', 'f' };

  char_T u[7];
  const mxArray *y;
  static const int32_T iv6[2] = { 1, 7 };

  const mxArray *m4;
  const mxArray *b_y;
  static const char_T formatSpec[39] = { 'D', 'i', 'f', 'f', 'e', 'r', 'e', 'n',
    'c', 'e', ' ', 'b', 'e', 't', 'w', 'e', 'e', 'n', ' ', 'r', 'e', 's', 'u',
    'l', 't', 's', ':', '\\', 't', '%', '0', '.', '1', '6', 'f', '\\', 'n', '\\',
    'n' };

  char_T b_u[39];
  const mxArray *c_y;
  static const int32_T iv7[2] = { 1, 39 };

  const mxArray *d_y;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  for (i2 = 0; i2 < 7; i2++) {
    u[i2] = cv4[i2];
  }

  y = NULL;
  m4 = emlrtCreateCharArray(2, iv6);
  emlrtInitCharArrayR2013a(sp, 7, m4, &u[0]);
  emlrtAssign(&y, m4);
  b_y = NULL;
  m4 = emlrtCreateDoubleScalar(1.0);
  emlrtAssign(&b_y, m4);
  for (i2 = 0; i2 < 39; i2++) {
    b_u[i2] = formatSpec[i2];
  }

  c_y = NULL;
  m4 = emlrtCreateCharArray(2, iv7);
  emlrtInitCharArrayR2013a(sp, 39, m4, &b_u[0]);
  emlrtAssign(&c_y, m4);
  d_y = NULL;
  m4 = emlrtCreateDoubleScalar(varargin_1);
  emlrtAssign(&d_y, m4);
  st.site = &t_emlrtRSI;
  return emlrt_marshallIn(&st, b_feval(&st, y, b_y, c_y, d_y, &g_emlrtMCI),
    "feval");
}

void b_fprintf(const emlrtStack *sp)
{
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &g_emlrtRSI;
  c_fprintf(&st);
}

void d_fprintf(const emlrtStack *sp)
{
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &g_emlrtRSI;
  e_fprintf(&st);
}

void f_fprintf(const emlrtStack *sp, real_T formatSpec)
{
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &s_emlrtRSI;
  g_fprintf(&st, formatSpec);
}

/* End of code generation (fprintf.c) */
