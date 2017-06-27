/*
 * File: _coder_squareTensorField_api.h
 *
 * MATLAB Coder version            : 3.1
 * C/C++ source code generated on  : 12-May-2016 09:08:19
 */

#ifndef _CODER_SQUARETENSORFIELD_API_H
#define _CODER_SQUARETENSORFIELD_API_H

/* Include Files */
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include <stddef.h>
#include <stdlib.h>
#include "_coder_squareTensorField_api.h"

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

/* Function Declarations */
extern void squareTensorField(real_T D[2359296]);
extern void squareTensorField_api(const mxArray *prhs[1], const mxArray *plhs[1]);
extern void squareTensorField_atexit(void);
extern void squareTensorField_initialize(void);
extern void squareTensorField_terminate(void);
extern void squareTensorField_xil_terminate(void);

#endif

/*
 * File trailer for _coder_squareTensorField_api.h
 *
 * [EOF]
 */
