/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * fminsearch.c
 *
 * Code generation for function 'fminsearch'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "test_parfor.h"
#include "fminsearch.h"
#include "eps.h"
#include <stdio.h>

/* Function Declarations */
static void eml_sort_idx(const real_T x[51], int32_T idx[51]);
static void sort_idx_single_insert(const real_T fv[51], int32_T idx[51]);

/* Function Definitions */
static void eml_sort_idx(const real_T x[51], int32_T idx[51])
{
  int32_T iwork[51];
  int32_T k;
  boolean_T p;
  int32_T i;
  int32_T i2;
  int32_T j;
  int32_T pEnd;
  int32_T b_p;
  int32_T q;
  int32_T qEnd;
  int32_T kEnd;
  memset(&idx[0], 0, 51U * sizeof(int32_T));
  for (k = 0; k < 49; k += 2) {
    if ((x[k] <= x[k + 1]) || muDoubleScalarIsNaN(x[k + 1])) {
      p = true;
    } else {
      p = false;
    }

    if (p) {
      idx[k] = k + 1;
      idx[k + 1] = k + 2;
    } else {
      idx[k] = k + 2;
      idx[k + 1] = k + 1;
    }
  }

  idx[50] = 51;
  i = 2;
  while (i < 51) {
    i2 = i << 1;
    j = 1;
    for (pEnd = 1 + i; pEnd < 52; pEnd = qEnd + i) {
      b_p = j;
      q = pEnd - 1;
      qEnd = j + i2;
      if (qEnd > 52) {
        qEnd = 52;
      }

      k = 0;
      kEnd = qEnd - j;
      while (k + 1 <= kEnd) {
        if ((x[idx[b_p - 1] - 1] <= x[idx[q] - 1]) || muDoubleScalarIsNaN
            (x[idx[q] - 1])) {
          p = true;
        } else {
          p = false;
        }

        if (p) {
          iwork[k] = idx[b_p - 1];
          b_p++;
          if (b_p == pEnd) {
            while (q + 1 < qEnd) {
              k++;
              iwork[k] = idx[q];
              q++;
            }
          }
        } else {
          iwork[k] = idx[q];
          q++;
          if (q + 1 == qEnd) {
            while (b_p < pEnd) {
              k++;
              iwork[k] = idx[b_p - 1];
              b_p++;
            }
          }
        }

        k++;
      }

      for (k = 0; k + 1 <= kEnd; k++) {
        idx[(j + k) - 1] = iwork[k];
      }

      j = qEnd;
    }

    i = i2;
  }
}

static void sort_idx_single_insert(const real_T fv[51], int32_T idx[51])
{
  int32_T k;
  int32_T cidx;
  for (k = 0; k < 50; k++) {
    if (fv[idx[50 - k] - 1] < fv[idx[49 - k] - 1]) {
      cidx = idx[50 - k];
      idx[50 - k] = idx[49 - k];
      idx[49 - k] = cidx;
    }
  }
}

void fminsearch(real_T x[50])
{
  real_T v[2550];
  real_T fv[51];
  int32_T k;
  int32_T j;
  int32_T colIdx;
  real_T xr[50];
  int32_T idx[51];
  boolean_T doShrink;
  int32_T itercount;
  int32_T fun_evals;
  real_T xbar[50];
  int32_T lastCol;
  int32_T firstCol;
  boolean_T exitg1;
  real_T maxfv;
  real_T maxv;
  boolean_T p;
  int32_T b_firstCol;
  real_T xe[50];
  real_T fvt[51];
  int32_T idxb[51];
  for (k = 0; k < 51; k++) {
    for (j = 0; j < 50; j++) {
      v[j + 50 * k] = x[j];
    }
  }

  fv[0] = func(x);
  for (k = 0; k < 50; k++) {
    colIdx = 50 * (k + 1);
    if (x[k] != 0.0) {
      v[k + colIdx] = 1.05 * x[k];
    } else {
      v[k + colIdx] = 0.00025;
    }

    memcpy(&xr[0], &v[colIdx], 50U * sizeof(real_T));
    fv[k + 1] = func(xr);
  }

  eml_sort_idx(fv, idx);
  doShrink = false;
  itercount = 1;
  fun_evals = 51;
  lastCol = 50 * (idx[50] - 1);
  firstCol = 50 * (idx[0] - 1);
  exitg1 = false;
  while ((!exitg1) && ((fun_evals < 100000) && (itercount < 10000))) {
    maxfv = 0.0;
    for (k = 0; k < 50; k++) {
      maxv = muDoubleScalarAbs(fv[idx[0] - 1] - fv[idx[k + 1] - 1]);
      if (maxv > maxfv) {
        maxfv = maxv;
      }
    }

    if (maxfv > muDoubleScalarMax(0.0001, 10.0 * eps(10.0 * eps(fv[idx[0] - 1]))))
    {
      p = false;
    } else {
      maxv = 0.0;
      b_firstCol = (idx[0] - 1) * 50;
      for (j = 0; j < 50; j++) {
        colIdx = (idx[j + 1] - 1) * 50;
        for (k = 0; k < 50; k++) {
          maxfv = muDoubleScalarAbs(v[k + b_firstCol] - v[k + colIdx]);
          if (maxfv > maxv) {
            maxv = maxfv;
          }
        }
      }

      maxfv = v[b_firstCol];
      for (k = 0; k < 49; k++) {
        if (v[(k + b_firstCol) + 1] > maxfv) {
          maxfv = v[(k + b_firstCol) + 1];
        }
      }

      p = (maxv <= muDoubleScalarMax(0.0001, 10.0 * eps(maxfv)));
    }

    if (!p) {
      memcpy(&xbar[0], &v[firstCol], 50U * sizeof(real_T));
      for (k = 0; k < 49; k++) {
        colIdx = 50 * (idx[k + 1] - 1);
        for (j = 0; j < 50; j++) {
          xbar[j] += v[j + colIdx];
        }
      }

      for (k = 0; k < 50; k++) {
        maxfv = xbar[k] / 50.0;
        xr[k] = 2.0 * maxfv - v[k + lastCol];
        xbar[k] = maxfv;
      }

      maxfv = func(xr);
      fun_evals++;
      if (maxfv < fv[idx[0] - 1]) {
        for (k = 0; k < 50; k++) {
          xe[k] = 3.0 * xbar[k] - 2.0 * v[k + lastCol];
        }

        maxv = func(xe);
        fun_evals++;
        if (maxv < maxfv) {
          memcpy(&v[lastCol], &xe[0], 50U * sizeof(real_T));
          fv[idx[50] - 1] = maxv;
        } else {
          memcpy(&v[lastCol], &xr[0], 50U * sizeof(real_T));
          fv[idx[50] - 1] = maxfv;
        }
      } else if (maxfv < fv[idx[49] - 1]) {
        memcpy(&v[lastCol], &xr[0], 50U * sizeof(real_T));
        fv[idx[50] - 1] = maxfv;
      } else {
        if (maxfv < fv[idx[50] - 1]) {
          for (k = 0; k < 50; k++) {
            x[k] = 1.5 * xbar[k] - 0.5 * v[k + lastCol];
          }

          maxv = func(x);
          fun_evals++;
          if (maxv <= maxfv) {
            for (k = 0; k < 50; k++) {
              v[k + lastCol] = x[k];
            }

            fv[idx[50] - 1] = maxv;
          } else {
            doShrink = true;
          }
        } else {
          for (k = 0; k < 50; k++) {
            x[k] = 0.5 * xbar[k] + 0.5 * v[k + lastCol];
          }

          maxfv = func(x);
          fun_evals++;
          if (maxfv < fv[idx[50] - 1]) {
            for (k = 0; k < 50; k++) {
              v[k + lastCol] = x[k];
            }

            fv[idx[50] - 1] = maxfv;
          } else {
            doShrink = true;
          }
        }

        if (doShrink) {
          for (k = 0; k < 50; k++) {
            colIdx = 50 * (idx[k + 1] - 1);
            for (j = 0; j < 50; j++) {
              v[j + colIdx] = v[j + firstCol] + 0.5 * (v[j + colIdx] - v[j +
                firstCol]);
              x[j] = v[j + colIdx];
            }

            fv[idx[k + 1] - 1] = func(x);
          }

          fun_evals += 50;
        }
      }

      if (doShrink) {
        for (k = 0; k < 51; k++) {
          fvt[k] = fv[idx[k] - 1];
          idxb[k] = idx[k];
        }

        eml_sort_idx(fvt, idx);
        for (k = 0; k < 51; k++) {
          idx[k] = idxb[idx[k] - 1];
        }

        doShrink = false;
      } else {
        sort_idx_single_insert(fv, idx);
      }

      itercount++;
      lastCol = 50 * (idx[50] - 1);
      firstCol = 50 * (idx[0] - 1);
    } else {
      exitg1 = true;
    }
  }

  colIdx = 50 * (idx[0] - 1);
  memcpy(&x[0], &v[colIdx], 50U * sizeof(real_T));
}

/* End of code generation (fminsearch.c) */
