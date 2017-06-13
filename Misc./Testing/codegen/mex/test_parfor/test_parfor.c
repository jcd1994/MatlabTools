/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * test_parfor.c
 *
 * Code generation for function 'test_parfor'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "test_parfor.h"
#include "rand.h"
#include "fprintf.h"
#include "fminsearch.h"
#include "test_parfor_data.h"
#include <stdio.h>

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 18, "test_parfor",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Testing/test_parfor.m" };

static emlrtRSInfo b_emlrtRSI = { 20, "test_parfor",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Testing/test_parfor.m" };

static emlrtRSInfo c_emlrtRSI = { 22, "test_parfor",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Testing/test_parfor.m" };

static emlrtRSInfo d_emlrtRSI = { 24, "test_parfor",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Testing/test_parfor.m" };

static emlrtRSInfo e_emlrtRSI = { 26, "test_parfor",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Testing/test_parfor.m" };

static emlrtRSInfo f_emlrtRSI = { 31, "test_parfor",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Testing/test_parfor.m" };

static emlrtRSInfo h_emlrtRSI = { 43, "test_parfor",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Testing/test_parfor.m" };

static emlrtRSInfo m_emlrtRSI = { 63, "test_parfor",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Testing/test_parfor.m" };

static emlrtRTEInfo emlrtRTEI = { 64, 9, "test_parfor",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Testing/test_parfor.m" };

static emlrtMCInfo emlrtMCI = { 22, 1, "test_parfor",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Testing/test_parfor.m" };

static emlrtMCInfo b_emlrtMCI = { 22, 29, "test_parfor",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Testing/test_parfor.m" };

static emlrtMCInfo c_emlrtMCI = { 26, 1, "test_parfor",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Testing/test_parfor.m" };

static emlrtMCInfo d_emlrtMCI = { 26, 32, "test_parfor",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Testing/test_parfor.m" };

static emlrtMCInfo e_emlrtMCI = { 29, 1, "test_parfor",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Testing/test_parfor.m" };

static emlrtMCInfo f_emlrtMCI = { 30, 1, "test_parfor",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Testing/test_parfor.m" };

static emlrtMCInfo h_emlrtMCI = { 44, 9, "test_parfor",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Testing/test_parfor.m" };

static emlrtMCInfo i_emlrtMCI = { 64, 9, "test_parfor",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Testing/test_parfor.m" };

static emlrtRSInfo u_emlrtRSI = { 30, "test_parfor",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Testing/test_parfor.m" };

static emlrtRSInfo v_emlrtRSI = { 29, "test_parfor",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Testing/test_parfor.m" };

static emlrtRSInfo w_emlrtRSI = { 64, "test_parfor",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Testing/test_parfor.m" };

static emlrtRSInfo x_emlrtRSI = { 44, "test_parfor",
  "/home/coopar7/Dropbox/Projects/Matlab/MyToolbox/Testing/test_parfor.m" };

/* Function Declarations */
static const mxArray *b_emlrt_marshallOut(const emlrtStack *sp, const char_T u
  [16]);
static void disp(const emlrtStack *sp, const mxArray *b, emlrtMCInfo *location);
static const mxArray *emlrt_marshallOut(const emlrtStack *sp, const char_T u[17]);
static void for_test(const emlrtStack *sp, const real_T A[750], real_T B[50]);
static void h_fprintf(const emlrtStack *sp, const mxArray *b, const mxArray *c,
                      emlrtMCInfo *location);
static void parfor_test(const emlrtStack *sp, const real_T A[750], real_T B[50]);
static void tic(const emlrtStack *sp, emlrtMCInfo *location);
static const mxArray *toc(const emlrtStack *sp, emlrtMCInfo *location);

/* Function Definitions */
static const mxArray *b_emlrt_marshallOut(const emlrtStack *sp, const char_T u
  [16])
{
  const mxArray *y;
  static const int32_T iv9[2] = { 1, 16 };

  const mxArray *m6;
  y = NULL;
  m6 = emlrtCreateCharArray(2, iv9);
  emlrtInitCharArrayR2013a(sp, 16, m6, &u[0]);
  emlrtAssign(&y, m6);
  return y;
}

static void disp(const emlrtStack *sp, const mxArray *b, emlrtMCInfo *location)
{
  const mxArray *pArray;
  pArray = b;
  emlrtCallMATLABR2012b(sp, 0, NULL, 1, &pArray, "disp", true, location);
}

static const mxArray *emlrt_marshallOut(const emlrtStack *sp, const char_T u[17])
{
  const mxArray *y;
  static const int32_T iv8[2] = { 1, 17 };

  const mxArray *m5;
  y = NULL;
  m5 = emlrtCreateCharArray(2, iv8);
  emlrtInitCharArrayR2013a(sp, 17, m5, &u[0]);
  emlrtAssign(&y, m5);
  return y;
}

static void for_test(const emlrtStack *sp, const real_T A[750], real_T B[50])
{
  int32_T ii;
  int32_T jj;
  real_T dv0[50];
  int32_T i;
  int8_T u[2];
  const mxArray *y;
  static const int32_T iv2[2] = { 1, 2 };

  const mxArray *m1;
  real_T *pData;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  memset(&B[0], 0, 50U * sizeof(real_T));
  ii = 0;
  while (ii < 15) {
    jj = 0;
    while (jj < 15) {
      memcpy(&dv0[0], &A[50 * ii], 50U * sizeof(real_T));
      st.site = &h_emlrtRSI;
      fminsearch(dv0);
      for (i = 0; i < 50; i++) {
        B[i] += dv0[i];
      }

      u[0] = (int8_T)(1 + ii);
      u[1] = (int8_T)(jj + 1);
      y = NULL;
      m1 = emlrtCreateNumericArray(2, iv2, mxDOUBLE_CLASS, mxREAL);
      pData = (real_T *)mxGetPr(m1);
      for (i = 0; i < 2; i++) {
        pData[i] = u[i];
      }

      emlrtAssign(&y, m1);
      st.site = &x_emlrtRSI;
      disp(&st, y, &h_emlrtMCI);
      jj++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }

    ii++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  /*  B = zeros(size(A)); */
  /*  for ii = 1:size(A,3) */
  /*      B(:,:,ii) = A(:,:,ii)^2; */
  /*  end */
}

static void h_fprintf(const emlrtStack *sp, const mxArray *b, const mxArray *c,
                      emlrtMCInfo *location)
{
  const mxArray *pArrays[2];
  pArrays[0] = b;
  pArrays[1] = c;
  emlrtCallMATLABR2012b(sp, 0, NULL, 2, pArrays, "fprintf", true, location);
}

static void parfor_test(const emlrtStack *sp, const real_T A[750], real_T B[50])
{
  int32_T ii;
  real_T BPrime[50];
  int32_T jj;
  real_T dv1[50];
  int32_T i;
  int8_T u[2];
  const mxArray *y;
  static const int32_T iv5[2] = { 1, 2 };

  const mxArray *m3;
  real_T *pData;
  jmp_buf * volatile emlrtJBStack;
  emlrtStack st;
  jmp_buf b_emlrtJBEnviron;
  emlrtStack b_st;
  boolean_T emlrtHadParallelError = false;
  memset(&B[0], 0, 50U * sizeof(real_T));
  emlrtEnterParallelRegion(sp, omp_in_parallel());
  emlrtPushJmpBuf(sp, &emlrtJBStack);

#pragma omp parallel \
 num_threads(emlrtAllocRegionTLSs(sp->tls, omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs())) \
 private(BPrime,jj,i,m3,pData,b_emlrtJBEnviron) \
 firstprivate(st,b_st,dv1,u,y,emlrtHadParallelError)

  {
    if (setjmp(b_emlrtJBEnviron) == 0) {
      st.prev = sp;
      st.tls = emlrtAllocTLS(sp, omp_get_thread_num());
      st.site = NULL;
      emlrtSetJmpBuf(&st, &b_emlrtJBEnviron);
      b_st.prev = &st;
      b_st.tls = st.tls;
      memset(&BPrime[0], 0, 50U * sizeof(real_T));
    } else {
      emlrtHadParallelError = true;
    }

#pragma omp for nowait

    for (ii = 0; ii < 15; ii++) {
      if (emlrtHadParallelError)
        continue;
      if (setjmp(b_emlrtJBEnviron) == 0) {
        jj = 0;
        while (jj < 15) {
          emlrtAssertMATLABThread(&st, &emlrtRTEI);
          memcpy(&dv1[0], &A[50 * ii], 50U * sizeof(real_T));
          b_st.site = &m_emlrtRSI;
          fminsearch(dv1);
          for (i = 0; i < 50; i++) {
            BPrime[i] += dv1[i];
          }

          u[0] = (int8_T)(1 + ii);
          u[1] = (int8_T)(jj + 1);
          y = NULL;
          m3 = emlrtCreateNumericArray(2, iv5, mxDOUBLE_CLASS, mxREAL);
          pData = (real_T *)mxGetPr(m3);
          for (i = 0; i < 2; i++) {
            pData[i] = u[i];
          }

          emlrtAssign(&y, m3);
          b_st.site = &w_emlrtRSI;
          disp(&b_st, y, &i_emlrtMCI);
          jj++;
          if (*emlrtBreakCheckR2012bFlagVar != 0) {
            emlrtBreakCheckR2012b(&st);
          }
        }

        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b(&st);
        }
      } else {
        emlrtHadParallelError = true;
      }
    }

    omp_set_nest_lock(&emlrtNestLockGlobal);
    if (!emlrtHadParallelError) {
      for (i = 0; i < 50; i++) {
        B[i] += BPrime[i];
      }
    }

    omp_unset_nest_lock(&emlrtNestLockGlobal);
  }

  emlrtPopJmpBuf(sp, &emlrtJBStack);
  emlrtExitParallelRegion(sp, omp_in_parallel());

  /*  B = zeros(size(A)); */
  /*  parfor ii = 1:size(A,3) */
  /*      B(:,:,ii) = A(:,:,ii)^2; */
  /*  end */
}

static void tic(const emlrtStack *sp, emlrtMCInfo *location)
{
  emlrtCallMATLABR2012b(sp, 0, NULL, 0, NULL, "tic", true, location);
}

static const mxArray *toc(const emlrtStack *sp, emlrtMCInfo *location)
{
  const mxArray *m7;
  return emlrtCallMATLABR2012b(sp, 1, &m7, 0, NULL, "toc", true, location);
}

real_T func(const real_T x[50])
{
  real_T y;
  real_T b_y[50];
  int32_T k;
  for (k = 0; k < 50; k++) {
    b_y[k] = x[k] * x[k];
  }

  y = b_y[0];
  for (k = 0; k < 49; k++) {
    y += b_y[k + 1];
  }

  return y;
}

void test_parfor(const emlrtStack *sp)
{
  real_T A[750];
  int32_T ixstart;
  real_T B1[50];
  const mxArray *t1 = NULL;
  real_T B2[50];
  const mxArray *t2 = NULL;
  static const char_T cv0[17] = { 'R', 'e', 'g', 'u', 'l', 'a', 'r', ':', ' ',
    '%', '0', '.', '6', 'f', 's', '\\', 'n' };

  static const char_T cv1[16] = { 'P', 'a', 'r', 'f', 'o', 'r', ':', ' ', '%',
    '0', '.', '6', 'f', 's', '\\', 'n' };

  real_T mtmp;
  int32_T ix;
  boolean_T exitg1;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;

  /* TEST_PARFOR Summary of this function goes here */
  /*    Detailed explanation goes here */
  /*  coder.extrinsic('gcp'); */
  /*  coder.extrinsic('feature'); */
  /*  coder.extrinsic('parpool'); */
  /*   */
  /*  if isempty(gcp('nocreate')) */
  /*      nCores = feature('numCores'); */
  /*      parpool('local',nCores); */
  /*  end */
  /*  A = rand(10,10,500000); */
  st.site = &emlrtRSI;
  b_rand(A);
  for (ixstart = 0; ixstart < 750; ixstart++) {
    A[ixstart] *= 2.0;
  }

  st.site = &b_emlrtRSI;
  b_fprintf(&st);

  /*  disp( timeit( @() for_test(A) ) ); */
  st.site = &c_emlrtRSI;
  tic(&st, &emlrtMCI);
  st.site = &c_emlrtRSI;
  for_test(&st, A, B1);
  st.site = &c_emlrtRSI;
  emlrtAssign(&t1, toc(&st, &b_emlrtMCI));
  st.site = &d_emlrtRSI;
  d_fprintf(&st);

  /*  disp( timeit( @() parfor_test(A) ) ); */
  st.site = &e_emlrtRSI;
  tic(&st, &c_emlrtMCI);
  st.site = &e_emlrtRSI;
  parfor_test(&st, A, B2);
  st.site = &e_emlrtRSI;
  emlrtAssign(&t2, toc(&st, &d_emlrtMCI));

  /*  display_toc_time( [t1;t2], {'Regular','Parfor'} ); */
  st.site = &v_emlrtRSI;
  h_fprintf(&st, emlrt_marshallOut(&st, cv0), emlrtAlias(t1), &e_emlrtMCI);
  st.site = &u_emlrtRSI;
  h_fprintf(&st, b_emlrt_marshallOut(&st, cv1), emlrtAlias(t2), &f_emlrtMCI);
  st.site = &f_emlrtRSI;
  for (ixstart = 0; ixstart < 50; ixstart++) {
    B1[ixstart] -= B2[ixstart];
  }

  ixstart = 1;
  mtmp = B1[0];
  if (muDoubleScalarIsNaN(B1[0])) {
    ix = 2;
    exitg1 = false;
    while ((!exitg1) && (ix < 51)) {
      ixstart = ix;
      if (!muDoubleScalarIsNaN(B1[ix - 1])) {
        mtmp = B1[ix - 1];
        exitg1 = true;
      } else {
        ix++;
      }
    }
  }

  if (ixstart < 50) {
    while (ixstart + 1 < 51) {
      if (B1[ixstart] > mtmp) {
        mtmp = B1[ixstart];
      }

      ixstart++;
    }
  }

  st.site = &f_emlrtRSI;
  f_fprintf(&st, mtmp);
  emlrtDestroyArray(&t1);
  emlrtDestroyArray(&t2);
}

/* End of code generation (test_parfor.c) */
