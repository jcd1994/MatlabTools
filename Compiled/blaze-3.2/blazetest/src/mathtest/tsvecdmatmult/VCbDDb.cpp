//=================================================================================================
/*!
//  \file src/mathtest/tsvecdmatmult/VCbDDb.cpp
//  \brief Source file for the VCbDDb sparse vector/dense matrix multiplication math test
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

#include <cstdlib>
#include <iostream>
#include <blaze/math/CompressedVector.h>
#include <blaze/math/DiagonalMatrix.h>
#include <blaze/math/DynamicMatrix.h>
#include <blazetest/mathtest/Creator.h>
#include <blazetest/mathtest/tsvecdmatmult/OperationTest.h>
#include <blazetest/system/MathTest.h>


//=================================================================================================
//
//  MAIN FUNCTION
//
//=================================================================================================

//*************************************************************************************************
int main()
{
   std::cout << "   Running 'VCbDDb'..." << std::endl;

   using blazetest::mathtest::TypeB;

   try
   {
      // Matrix type definitions
      typedef blaze::CompressedVector<TypeB>                        VCb;
      typedef blaze::DiagonalMatrix< blaze::DynamicMatrix<TypeB> >  DDb;

      // Creator type definitions
      typedef blazetest::Creator<VCb>  CVCb;
      typedef blazetest::Creator<DDb>  CDDb;

      // Running tests with small vectors and matrices
      for( size_t i=0UL; i<=6UL; ++i ) {
         for( size_t j=0UL; j<=i; ++j ) {
            RUN_TSVECDMATMULT_OPERATION_TEST( CVCb( i, j ), CDDb( i ) );
         }
      }

      // Running tests with large vectors and matrices
      RUN_TSVECDMATMULT_OPERATION_TEST( CVCb(  67UL,  7UL ), CDDb(  67UL ) );
      RUN_TSVECDMATMULT_OPERATION_TEST( CVCb( 127UL, 13UL ), CDDb( 127UL ) );
      RUN_TSVECDMATMULT_OPERATION_TEST( CVCb(  64UL,  8UL ), CDDb(  64UL ) );
      RUN_TSVECDMATMULT_OPERATION_TEST( CVCb( 128UL, 16UL ), CDDb( 128UL ) );
   }
   catch( std::exception& ex ) {
      std::cerr << "\n\n ERROR DETECTED during sparse vector/dense matrix multiplication:\n"
                << ex.what() << "\n";
      return EXIT_FAILURE;
   }

   return EXIT_SUCCESS;
}
//*************************************************************************************************