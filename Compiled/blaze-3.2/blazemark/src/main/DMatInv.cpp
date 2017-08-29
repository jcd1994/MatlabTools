//=================================================================================================
/*!
//  \file src/main/DMatInv.cpp
//  \brief Source file for the dense matrix inversion benchmark
//
//  Copyright (C) 2012-2017 Klaus Iglberger - All Rights Reserved
//
//  This file is part of the Blaze library. You can redistribute it and/or modify it under
//  the terms of the New (Revised) BSD License. Redistribution and use in source and binary
//  forms, with or without modification, are permitted provided that the following conditions
//  are met:
//
//  1. Redistributions of source code must retain the above copyright notice, this list of
//     conditions and the following disclaimer.
//  2. Redistributions in binary form must reproduce the above copyright notice, this list
//     of conditions and the following disclaimer in the documentation and/or other materials
//     provided with the distribution.
//  3. Neither the names of the Blaze development group nor the names of its contributors
//     may be used to endorse or promote products derived from this software without specific
//     prior written permission.
//
//  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY
//  EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
//  OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT
//  SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
//  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED
//  TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
//  BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
//  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
//  ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH
//  DAMAGE.
*/
//=================================================================================================


//*************************************************************************************************
// Includes
//*************************************************************************************************

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <blaze/math/DynamicMatrix.h>
#include <blaze/math/Infinity.h>
#include <blaze/util/algorithms/Max.h>
#include <blaze/util/Random.h>
#include <blaze/util/Timing.h>
#include <blazemark/blaze/DMatInv.h>
#include <blazemark/blaze/init/DynamicMatrix.h>
#include <blazemark/armadillo/DMatInv.h>
#include <blazemark/boost/DMatInv.h>
#include <blazemark/eigen/DMatInv.h>
#include <blazemark/gmm/DMatInv.h>
#include <blazemark/mtl/DMatInv.h>
#include <blazemark/system/Boost.h>
#include <blazemark/system/Config.h>
#include <blazemark/system/Eigen.h>
#include <blazemark/system/GMM.h>
#include <blazemark/system/MTL.h>
#include <blazemark/system/Types.h>
#include <blazemark/util/Benchmarks.h>
#include <blazemark/util/DynamicDenseRun.h>
#include <blazemark/util/Parser.h>


//*************************************************************************************************
// Using declarations
//*************************************************************************************************

using blazemark::Benchmarks;
using blazemark::DynamicDenseRun;
using blazemark::Parser;




//=================================================================================================
//
//  TYPE DEFINITIONS
//
//=================================================================================================

//*************************************************************************************************
/*!\brief Type of a benchmark run.
//
// This type definition specifies the type of a single benchmark run for the dense matrix
// inversion benchmark.
*/
typedef DynamicDenseRun  Run;
//*************************************************************************************************




//=================================================================================================
//
//  UTILITY FUNCTIONS
//
//=================================================================================================

//*************************************************************************************************
/*!\brief Estimating the necessary number of steps for each benchmark.
//
// \param run The parameters for the benchmark run.
// \return void
//
// This function estimates the necessary number of steps for the given benchmark based on the
// performance of the Blaze library.
*/
void estimateSteps( Run& run )
{
   using blazemark::element_t;
   using blaze::columnMajor;

   ::blaze::setSeed( ::blazemark::seed );

   const size_t N( run.getSize() );

   blaze::DynamicMatrix<element_t,columnMajor> A( N, N ), B( N, N );
   blaze::timing::WcTimer timer;
   double wct( 0.0 );
   size_t steps( 1UL );

   blazemark::blaze::init( A );

   B = inv( A );

   while( true ) {
      timer.start();
      for( size_t i=0UL; i<steps; ++i ) {
         B = inv( A );
      }
      timer.end();
      wct = timer.last();
      if( wct >= 0.2 ) break;
      steps *= 2UL;
   }

   if( B.rows() != N )
      std::cerr << " Line " << __LINE__ << ": ERROR detected!!!\n";

   const size_t estimatedSteps( ( blazemark::runtime * steps ) / timer.last() );
   run.setSteps( blaze::max( 1UL, estimatedSteps ) );
}
//*************************************************************************************************




//=================================================================================================
//
//  BENCHMARK FUNCTIONS
//
//=================================================================================================

//*************************************************************************************************
/*!\brief Dense matrix inversion benchmark function.
//
// \param runs The specified benchmark runs.
// \param benchmarks The selection of benchmarks.
// \return void
*/
void dmatinv( std::vector<Run>& runs, Benchmarks benchmarks )
{
   std::cout << std::left;

   std::sort( runs.begin(), runs.end() );

   size_t slowSize( blaze::inf );
   for( std::vector<Run>::iterator run=runs.begin(); run!=runs.end(); ++run )
   {
      if( run->getSteps() == 0UL ) {
         if( run->getSize() < slowSize ) {
            estimateSteps( *run );
            if( run->getSteps() == 1UL )
               slowSize = run->getSize();
         }
         else run->setSteps( 1UL );
      }
   }

   if( benchmarks.runBlaze ) {
      std::cout << "   Blaze (Seconds):\n";
      for( std::vector<Run>::iterator run=runs.begin(); run!=runs.end(); ++run ) {
         const size_t N    ( run->getSize()  );
         const size_t steps( run->getSteps() );
         run->setBlazeResult( blazemark::blaze::dmatinv( N, steps ) );
         const double runtime( run->getBlazeResult() / steps );
         std::cout << "     " << std::setw(12) << N << runtime << std::endl;
      }
   }

#if BLAZEMARK_BOOST_MODE
   if( benchmarks.runBoost ) {
      std::cout << "   Boost uBLAS (Seconds):\n";
      for( std::vector<Run>::iterator run=runs.begin(); run!=runs.end(); ++run ) {
         const size_t N    ( run->getSize()  );
         const size_t steps( run->getSteps() );
         run->setBoostResult( blazemark::boost::dmatinv( N, steps ) );
         const double runtime( run->getBoostResult() / steps );
         std::cout << "     " << std::setw(12) << N << runtime << std::endl;
      }
   }
#endif

#if BLAZEMARK_GMM_MODE
   if( benchmarks.runGMM ) {
      std::cout << "   GMM++ (Seconds):\n";
      for( std::vector<Run>::iterator run=runs.begin(); run!=runs.end(); ++run ) {
         const size_t N    ( run->getSize()  );
         const size_t steps( run->getSteps() );
         run->setGMMResult( blazemark::gmm::dmatinv( N, steps ) );
         const double runtime( run->getGMMResult() / steps );
         std::cout << "     " << std::setw(12) << N << runtime << std::endl;
      }
   }
#endif

#if BLAZEMARK_ARMADILLO_MODE
   if( benchmarks.runArmadillo ) {
      std::cout << "   Armadillo (Seconds):\n";
      for( std::vector<Run>::iterator run=runs.begin(); run!=runs.end(); ++run ) {
         const size_t N    ( run->getSize()  );
         const size_t steps( run->getSteps() );
         run->setArmadilloResult( blazemark::armadillo::dmatinv( N, steps ) );
         const double runtime( run->getArmadilloResult() / steps );
         std::cout << "     " << std::setw(12) << N << runtime << std::endl;
      }
   }
#endif

#if BLAZEMARK_MTL_MODE
   if( benchmarks.runMTL ) {
      std::cout << "   MTL (Seconds):\n";
      for( std::vector<Run>::iterator run=runs.begin(); run!=runs.end(); ++run ) {
         const size_t N    ( run->getSize()  );
         const size_t steps( run->getSteps() );
         run->setMTLResult( blazemark::mtl::dmatinv( N, steps ) );
         const double runtime( run->getMTLResult() / steps );
         std::cout << "     " << std::setw(12) << N << runtime << std::endl;
      }
   }
#endif

#if BLAZEMARK_EIGEN_MODE
   if( benchmarks.runEigen ) {
      std::cout << "   Eigen (Seconds):\n";
      for( std::vector<Run>::iterator run=runs.begin(); run!=runs.end(); ++run ) {
         const size_t N    ( run->getSize()  );
         const size_t steps( run->getSteps() );
         run->setEigenResult( blazemark::eigen::dmatinv( N, steps ) );
         const double runtime( run->getEigenResult() / steps );
         std::cout << "     " << std::setw(12) << N << runtime << std::endl;
      }
   }
#endif

   for( std::vector<Run>::iterator run=runs.begin(); run!=runs.end(); ++run ) {
      std::cout << *run;
   }
}
//*************************************************************************************************




//=================================================================================================
//
//  MAIN FUNCTION
//
//=================================================================================================

//*************************************************************************************************
/*!\brief The main function for the dense matrix inversion benchmark.
//
// \param argc The total number of command line arguments.
// \param argv The array of command line arguments.
// \return void
*/
int main( int argc, char** argv )
{
   std::cout << "\n Dense Matrix Inversion:\n";

   Benchmarks benchmarks;

   try {
      parseCommandLineArguments( argc, argv, benchmarks );
   }
   catch( std::exception& ex ) {
      std::cerr << "   " << ex.what() << "\n";
      return EXIT_FAILURE;
   }

   const std::string installPath( INSTALL_PATH );
   const std::string parameterFile( installPath + "/params/dmatinv.prm" );
   Parser<Run> parser;
   std::vector<Run> runs;

   try {
      parser.parse( parameterFile.c_str(), runs );
   }
   catch( std::exception& ex ) {
      std::cerr << "   Error during parameter extraction: " << ex.what() << "\n";
      return EXIT_FAILURE;
   }

   try {
      dmatinv( runs, benchmarks );
   }
   catch( std::exception& ex ) {
      std::cerr << "   Error during benchmark execution: " << ex.what() << "\n";
      return EXIT_FAILURE;
   }
}
//*************************************************************************************************
