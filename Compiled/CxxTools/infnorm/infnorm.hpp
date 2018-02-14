#ifndef INFNORM_HPP
#define INFNORM_HPP

/* Disable debugging */
#ifndef NDEBUG
#define NDEBUG
#endif

#include "mex.h"
#include <math.h>
#include <stdint.h>
#include <omp.h>
#include <iostream>
#include <Eigen/Dense>
#include <blaze/Math.h>

#define INFNORM_EIGEN_ARRAYS //define for using Eigen arrays
// #define INFNORM_BLAZE_ARRAYS //define for using blaze arrays

#ifdef INFNORM_EIGEN_ARRAYS
/* Eigen typedefs */
inline namespace Eigen {
    typedef Map<ArrayXd> VecXd;
    typedef Map<ArrayXf> VecXf;
}
#endif

#ifdef INFNORM_BLAZE_ARRAYS
/* Blaze typedefs */
inline namespace blaze {
    using VecXd = CustomVector<double,aligned,unpadded,columnVector>;
    using VecXf = CustomVector<float, aligned,unpadded,columnVector>;
}
#endif

template <typename Derived>
        inline auto infnorm(const Eigen::ArrayBase<Derived>& x)
{
//     Eigen::initParallel();
    omp_set_num_threads(omp_get_max_threads());
//     auto n_req = omp_get_max_threads();
//     Eigen::setNbThreads(n_req);
//     auto n_set = Eigen::nbThreads();
//     mexPrintf("n_set = %d\n",n_set);
//     return x.abs().maxCoeff();
    return (x.matrix()).template lpNorm<Infinity>();
}

template <typename Derived>
        inline auto infnorm(const Eigen::ArrayBase<Derived>& xr,
        const Eigen::ArrayBase<Derived>& xi)
{
    Eigen::initParallel();
    return sqrt((xr*xr+xi*xi).maxCoeff());
}

template <typename Derived, bool TF = blaze::defaultTransposeFlag>
        inline auto infnorm(const blaze::DenseVector<Derived,TF>& x)
{
    return max(abs(x));
}

template <typename Derived, bool TF = blaze::defaultTransposeFlag>
        inline auto infnorm(const blaze::DenseVector<Derived,TF>& xr,
        const blaze::DenseVector<Derived,TF>& xi)
{
    return sqrt(max(xr*xr+xi*xi));
}

#endif //INFNORM_HPP