/*
 * squareTensorField_initialize.c
 *
 * Code generation for function 'squareTensorField_initialize'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "squareTensorField.h"
#include "squareTensorField_initialize.h"
#include "_coder_squareTensorField_mex.h"
#include "squareTensorField_data.h"

/* Function Declarations */
static void squareTensorField_once(void);

/* Function Definitions */
static void squareTensorField_once(void)
{
  /* Allocate instance data */
  covrtAllocateInstanceData(&emlrtCoverageInstance);

  /* Initialize Coverage Information */
  covrtScriptInit(&emlrtCoverageInstance,
                  "C:\\Users\\Jonathan\\Dropbox\\Projects\\Matlab\\MyToolbox\\Testing\\squareTensorField.m",
                  0, 1, 2, 2, 0, 0, 0, 5, 0, 0, 0);

  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 0, 0, "squareTensorField", 0, -1, 506);

  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 0, 1, 416, -1, 460);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0, 0, 232, -1, 270);

  /* Initialize If Information */
  covrtIfInit(&emlrtCoverageInstance, 0, 0, 149, 165, 292, 312);
  covrtIfInit(&emlrtCoverageInstance, 0, 1, 292, 312, -1, 312);

  /* Initialize MCDC Information */
  /* Initialize For Information */
  covrtForInit(&emlrtCoverageInstance, 0, 0, 170, 191, 291);
  covrtForInit(&emlrtCoverageInstance, 0, 1, 199, 220, 283);
  covrtForInit(&emlrtCoverageInstance, 0, 2, 317, 338, 497);
  covrtForInit(&emlrtCoverageInstance, 0, 3, 346, 367, 489);
  covrtForInit(&emlrtCoverageInstance, 0, 4, 379, 400, 477);

  /* Initialize While Information */
  /* Initialize Switch Information */
  /* Start callback for coverage engine */
  covrtScriptStart(&emlrtCoverageInstance, 0U);
}

void squareTensorField_initialize(void)
{
  emlrtStack st = { NULL, NULL, NULL };

  mexFunctionCreateRootTLS();
  emlrtBreakCheckR2012bFlagVar = emlrtGetBreakCheckFlagAddressR2012b();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, 0);
  emlrtEnterRtStackR2012b(&st);
  if (emlrtFirstTimeR2012b(emlrtRootTLSGlobal)) {
    squareTensorField_once();
  }
}

/* End of code generation (squareTensorField_initialize.c) */
