/*
 * File: squareTensorField.c
 *
 * MATLAB Coder version            : 3.1
 * C/C++ source code generated on  : 12-May-2016 09:08:19
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "squareTensorField.h"

/* Function Definitions */

/*
 * SQUAREDTI Input is an MxNx3x3 (4D) or MxNxPx3x3 (5D) tensor field matrix.
 * The tensor elements will be squared
 * Arguments    : double D[2359296]
 * Return Type  : void
 */
void squareTensorField(double D[2359296])
{
  int ii;
  int jj;
  int kk;
  double b[9];
  int k;
  double b_b[9];
  int i0;
  int i1;
  for (ii = 0; ii < 64; ii++) {
    for (jj = 0; jj < 64; jj++) {
      for (kk = 0; kk < 64; kk++) {
        for (k = 0; k < 9; k++) {
          b[k] = D[(((ii + (jj << 6)) + (kk << 12)) + (k % 3 << 18)) + 786432 *
            (k / 3)];
        }

        for (k = 0; k < 3; k++) {
          for (i0 = 0; i0 < 3; i0++) {
            b_b[k + 3 * i0] = 0.0;
            for (i1 = 0; i1 < 3; i1++) {
              b_b[k + 3 * i0] += b[k + 3 * i1] * b[i1 + 3 * i0];
            }
          }
        }

        for (k = 0; k < 3; k++) {
          for (i0 = 0; i0 < 3; i0++) {
            D[(((ii + (jj << 6)) + (kk << 12)) + (i0 << 18)) + 786432 * k] =
              b_b[i0 + 3 * k];
          }
        }
      }
    }
  }
}

/*
 * File trailer for squareTensorField.c
 *
 * [EOF]
 */
