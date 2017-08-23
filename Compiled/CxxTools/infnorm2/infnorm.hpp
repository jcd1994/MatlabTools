#include <math.h>
#include <stdint.h>
#include <omp.h>
#include <iostream>
#include <Eigen/Dense>
#include "mex.h"

template <typename Arr, typename Elem>
void infnorm(Arr &x, Elem c)
{
    *c = x.array().abs().maxCoeff();
}

template <typename Arr, typename Elem>
void infnorm(Arr &xr, Arr &xi, Elem c)
{
    *c = sqrt( (xr.array() * xr.array() + xi.array() * xi.array()).maxCoeff() );
}