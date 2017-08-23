#include "infnorm.hpp"

/* INFNORM
 *
 * INPUT ARGUMENTS
 *  x: input array (N-D complex double array)
 *
 */

/* Simple aliases for input pointers */
#define __x__   prhs[0]

/* Simple aliases for output pointers */
#define __c__   plhs[0]

using namespace Eigen;
    
void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
    /* length of input array */
    const uint32_t n = (const uint32_t)mxGetNumberOfElements(__x__);
    
    /* declare input and output variables */
    void *xr, *xi, *c;
    xr = mxGetData(__x__);
    xi = mxGetImagData(__x__);
        
    switch(mxGetClassID(__x__))
    {
        case mxDOUBLE_CLASS: /* Perform computation for a double array */
            /* Initialize output variable */
            __c__ = mxCreateNumericMatrix(1, 1, mxDOUBLE_CLASS, mxREAL);
            c = (double*)mxGetData(__c__);
            
            /* Call real or complex function */
            if(mxIsComplex(__x__)) {
                Map<VectorXd> vr((double*)xr,n), vi((double*)xi,n);
                infnorm(vr,vi,(double*)c);
            } else {
                Map<VectorXd> vr((double*)xr,n);
                infnorm(vr,(double*)c);
            }
            
            break;
            
        case mxSINGLE_CLASS: /* Perform computation for a single array */
            /* Initialize output variable */
            __c__ = mxCreateNumericMatrix(1, 1, mxSINGLE_CLASS, mxREAL);
            c = (float*)mxGetData(__c__);
            
            /* Call real or complex function */
            if(mxIsComplex(__x__)){
                Map<VectorXf> vr((float*)xr,n), vi((float*)xi,n);
                infnorm(vr,vi,(float*)c);
            } else {
                Map<VectorXf> vr((float*)xr,n);
                infnorm(vr,(float*)c);
            }
            
            break;
            
        default:
            /* x is of some other class */
            mexPrintf( "x is of class %s; infnorm supports only "
                    "real/complex float/double arrays.\n",
                    mxGetClassName(__x__));
    }
    
    
    return;
}

