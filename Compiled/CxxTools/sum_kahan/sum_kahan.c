#include "sum_kahan.h"

/* SUM_KAHAN
 *
 * INPUT ARGUMENTS
 *  x: input array (N-D complex double array)
 *
 */

/* Simple aliases for input pointers */
#define __x__   prhs[0]

/* Simple aliases for output pointers */
#define __c__   plhs[0]

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
    /* length of input array */
    const uint32_t n = (const uint32_t)mxGetNumberOfElements(__x__);
    
    /* declare input and output variables */
    void *xr, *xi, *cr, *ci;
    xr = mxGetData(__x__);
    xi = mxGetImagData(__x__);
    
    switch(mxGetClassID(__x__))
    {
        case mxDOUBLE_CLASS: /* Perform computation for a double array */
            
            /* Call real or complex function */
            if(mxIsComplex(__x__)) {
                __c__ = mxCreateNumericMatrix(1, 1, mxDOUBLE_CLASS, mxCOMPLEX);
                cr = (double*)mxGetData(__c__);
                ci = (double*)mxGetImagData(__c__);
                c_sum_kahan( xr, xi, cr, ci, n );
            } else {
                __c__ = mxCreateNumericMatrix(1, 1, mxDOUBLE_CLASS, mxREAL);
                cr = (double*)mxGetData(__c__);
                f_sum_kahan( xr, cr, n );
            }
            
            break;
            
        case mxSINGLE_CLASS: /* Perform computation for a single array */
            
            /* Call real or complex function */
            if(mxIsComplex(__x__)) {
                __c__ = mxCreateNumericMatrix(1, 1, mxSINGLE_CLASS, mxCOMPLEX);
                cr = (float*)mxGetData(__c__);
                ci = (float*)mxGetImagData(__c__);
                c_sum_kahan_f( xr, xi, cr, ci, n );
            } else {
                __c__ = mxCreateNumericMatrix(1, 1, mxSINGLE_CLASS, mxREAL);
                cr = (float*)mxGetData(__c__);
                f_sum_kahan_f( xr, cr, n );
            }
            
            break;
            
        default:
            /* x is of some other class */
            mexPrintf( "x is of class %s; sum_kahan supports only "
                    "real/complex float/double arrays.\n",
                    mxGetClassName(__x__));
    }
    
    return;
}

