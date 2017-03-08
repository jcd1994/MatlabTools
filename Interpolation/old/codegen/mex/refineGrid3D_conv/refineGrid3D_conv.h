/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * refineGrid3D_conv.h
 *
 * Code generation for function 'refineGrid3D_conv'
 *
 */

#ifndef __REFINEGRID3D_CONV_H__
#define __REFINEGRID3D_CONV_H__

/* Include files */
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include "blas.h"
#include "rtwtypes.h"
#include "refineGrid3D_conv_types.h"

/* Function Declarations */
extern void refineGrid3D_conv(const emlrtStack *sp, const emxArray_real32_T *V,
  real_T K, emxArray_real32_T *Vk);

#endif

/* End of code generation (refineGrid3D_conv.h) */
