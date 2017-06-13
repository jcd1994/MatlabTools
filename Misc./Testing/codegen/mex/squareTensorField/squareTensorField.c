/*
 * squareTensorField.c
 *
 * Code generation for function 'squareTensorField'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "squareTensorField.h"
#include "squareTensorField_data.h"

/* Function Definitions */
void squareTensorField(const emlrtStack *sp, real_T D[2359296])
{
  int32_T ii;
  int32_T jj;
  int32_T kk;
  real_T a[9];
  int32_T k;
  real_T b_a[9];
  int32_T i0;
  int32_T i1;
  covrtLogFcn(&emlrtCoverageInstance, 0U, 0);

  /* SQUAREDTI Input is an MxNx3x3 (4D) or MxNxPx3x3 (5D) tensor field matrix. */
  /* The tensor elements will be squared */
  covrtLogIf(&emlrtCoverageInstance, 0U, 0U, 0, false);
  covrtLogIf(&emlrtCoverageInstance, 0U, 0U, 1, true);
  ii = 0;
  while (ii < 64) {
    covrtLogFor(&emlrtCoverageInstance, 0U, 0U, 2, 1);
    jj = 0;
    while (jj < 64) {
      covrtLogFor(&emlrtCoverageInstance, 0U, 0U, 3, 1);
      kk = 0;
      while (kk < 64) {
        covrtLogFor(&emlrtCoverageInstance, 0U, 0U, 4, 1);
        covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 1);
        for (k = 0; k < 9; k++) {
          a[k] = D[(((ii + (jj << 6)) + (kk << 12)) + (k % 3 << 18)) + 786432 *
            (k / 3)];
        }

        for (k = 0; k < 3; k++) {
          for (i0 = 0; i0 < 3; i0++) {
            b_a[k + 3 * i0] = 0.0;
            for (i1 = 0; i1 < 3; i1++) {
              b_a[k + 3 * i0] += a[k + 3 * i1] * a[i1 + 3 * i0];
            }
          }
        }

        for (k = 0; k < 3; k++) {
          for (i0 = 0; i0 < 3; i0++) {
            D[(((ii + (jj << 6)) + (kk << 12)) + (i0 << 18)) + 786432 * k] =
              b_a[i0 + 3 * k];
          }
        }

        kk++;
        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b(sp);
        }
      }

      covrtLogFor(&emlrtCoverageInstance, 0U, 0U, 4, 0);
      jj++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }

    covrtLogFor(&emlrtCoverageInstance, 0U, 0U, 3, 0);
    ii++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  covrtLogFor(&emlrtCoverageInstance, 0U, 0U, 2, 0);
}

/* End of code generation (squareTensorField.c) */
