/*
 * File: main.c
 *
 * MATLAB Coder version            : 3.1
 * C/C++ source code generated on  : 12-May-2016 09:08:19
 */

/*************************************************************************/
/* This automatically generated example C main file shows how to call    */
/* entry-point functions that MATLAB Coder generated. You must customize */
/* this file for your application. Do not modify this file directly.     */
/* Instead, make a copy of this file, modify it, and integrate it into   */
/* your development environment.                                         */
/*                                                                       */
/* This file initializes entry-point function arguments to a default     */
/* size and value before calling the entry-point functions. It does      */
/* not store or use any values returned from the entry-point functions.  */
/* If necessary, it does pre-allocate memory for returned values.        */
/* You can use this file as a starting point for a main function that    */
/* you can deploy in your application.                                   */
/*                                                                       */
/* After you copy the file, and before you deploy it, you must make the  */
/* following changes:                                                    */
/* * For variable-size function arguments, change the example sizes to   */
/* the sizes that your application requires.                             */
/* * Change the example values of function arguments to the values that  */
/* your application requires.                                            */
/* * If the entry-point functions return values, store these values or   */
/* otherwise use them as required by your application.                   */
/*                                                                       */
/*************************************************************************/
/* Include Files */
#include "rt_nonfinite.h"
#include "squareTensorField.h"
#include "main.h"
#include "squareTensorField_terminate.h"
#include "squareTensorField_initialize.h"

/* Function Declarations */
static void argInit_64x64x64x3x3_real_T(double result[2359296]);
static double argInit_real_T(void);
static void main_squareTensorField(void);

/* Function Definitions */

/*
 * Arguments    : double result[2359296]
 * Return Type  : void
 */
static void argInit_64x64x64x3x3_real_T(double result[2359296])
{
  int idx0;
  int idx1;
  int idx2;
  int idx3;
  int idx4;

  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < 64; idx0++) {
    for (idx1 = 0; idx1 < 64; idx1++) {
      for (idx2 = 0; idx2 < 64; idx2++) {
        for (idx3 = 0; idx3 < 3; idx3++) {
          for (idx4 = 0; idx4 < 3; idx4++) {
            /* Set the value of the array element.
               Change this value to the value that the application requires. */
            result[(((idx0 + (idx1 << 6)) + (idx2 << 12)) + (idx3 << 18)) +
              786432 * idx4] = argInit_real_T();
          }
        }
      }
    }
  }
}

/*
 * Arguments    : void
 * Return Type  : double
 */
static double argInit_real_T(void)
{
  return 0.0;
}

/*
 * Arguments    : void
 * Return Type  : void
 */
static void main_squareTensorField(void)
{
  static double D[2359296];

  /* Initialize function 'squareTensorField' input arguments. */
  /* Initialize function input argument 'D'. */
  argInit_64x64x64x3x3_real_T(D);

  /* Call the entry-point 'squareTensorField'. */
  squareTensorField(D);
}

/*
 * Arguments    : int argc
 *                const char * const argv[]
 * Return Type  : int
 */
int main(int argc, const char * const argv[])
{
  (void)argc;
  (void)argv;

  /* Initialize the application.
     You do not need to do this more than one time. */
  squareTensorField_initialize();

  /* Invoke the entry-point functions.
     You can call entry-point functions multiple times. */
  main_squareTensorField();

  /* Terminate the application.
     You do not need to do this more than one time. */
  squareTensorField_terminate();
  return 0;
}

/*
 * File trailer for main.c
 *
 * [EOF]
 */
