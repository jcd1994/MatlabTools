//=================================================================================================
/*!
//  \file src/mathtest/sparsevector/OperationTest.cpp
//  \brief Source file for the SparseVector functionality operation test
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
#include <blaze/math/sparse/SparseVector.h>
#include <blaze/math/CompressedVector.h>
#include <blazetest/mathtest/sparsevector/OperationTest.h>


namespace blazetest {

namespace mathtest {

namespace sparsevector {

//=================================================================================================
//
//  CONSTRUCTORS
//
//=================================================================================================

//*************************************************************************************************
/*!\brief Constructor for the OperationTest class test.
//
// \exception std::runtime_error Operation error detected.
*/
OperationTest::OperationTest()
{
   testIsNan();
   testIsUniform();
   testLength();
   testNormalize();
   testMinimum();
   testMaximum();
}
//*************************************************************************************************




//=================================================================================================
//
//  TEST FUNCTIONS
//
//=================================================================================================

//*************************************************************************************************
/*!\brief Test of the \c isnan() function for sparse vectors.
//
// \return void
// \exception std::runtime_error Error detected.
//
// This function performs a test of the \c isnan() function for sparse vectors. In case an
// error is detected, a \a std::runtime_error exception is thrown.
*/
void OperationTest::testIsNan()
{
   test_ = "isnan() function";

   // isnan with 0-dimensional vector
   {
      blaze::CompressedVector<float,blaze::rowVector> vec;

      if( blaze::isnan( vec ) != false ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Invalid isnan evaluation\n"
             << " Details:\n"
             << "   Vector:\n" << vec << "\n";
         throw std::runtime_error( oss.str() );
      }
   }

   // isnan with empty 9-dimensional vector
   {
      blaze::CompressedVector<float,blaze::rowVector> vec( 9UL );

      if( blaze::isnan( vec ) != false ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Invalid isnan evaluation\n"
             << " Details:\n"
             << "   Vector:\n" << vec << "\n";
         throw std::runtime_error( oss.str() );
      }
   }

   // isnan with filled 9-dimensional vector
   {
      blaze::CompressedVector<float,blaze::rowVector> vec( 9UL );
      vec[3] =  1.0F;
      vec[4] = -2.0F;
      vec[6] =  3.0F;
      vec[8] =  4.0F;

      if( blaze::isnan( vec ) != false ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Invalid isnan evaluation\n"
             << " Details:\n"
             << "   Vector:\n" << vec << "\n";
         throw std::runtime_error( oss.str() );
      }
   }
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Test of the \c isUniform() function for sparse vectors.
//
// \return void
// \exception std::runtime_error Error detected.
//
// This function performs a test of the \c isUniform() function for sparse vectors. In case an
// error is detected, a \a std::runtime_error exception is thrown.
*/
void OperationTest::testIsUniform()
{
   test_ = "isUniform() function";

   // Uniform 0-dimensional vector
   {
      blaze::CompressedVector<int,blaze::rowVector> vec;

      if( blaze::isUniform( vec ) != true ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Invalid isUniform evaluation\n"
             << " Details:\n"
             << "   Vector:\n" << vec << "\n";
         throw std::runtime_error( oss.str() );
      }
   }

   // Uniform 1-dimensional vector
   {
      blaze::CompressedVector<int,blaze::rowVector> vec( 1UL, 1UL );
      vec.insert( 0UL, 5 );

      if( blaze::isUniform( vec ) != true ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Invalid isUniform evaluation\n"
             << " Details:\n"
             << "   Vector:\n" << vec << "\n";
         throw std::runtime_error( oss.str() );
      }
   }

   // Uniform 5-dimensional vector (2 non-zeros)
   {
      blaze::CompressedVector<int,blaze::rowVector> vec( 5UL, 2UL );
      vec.insert( 1UL, 0 );
      vec.insert( 4UL, 0 );

      if( blaze::isUniform( vec ) != true ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Invalid isUniform evaluation\n"
             << " Details:\n"
             << "   Vector:\n" << vec << "\n";
         throw std::runtime_error( oss.str() );
      }
   }

   // Uniform 5-dimensional vector (5 non-zeros)
   {
      blaze::CompressedVector<int,blaze::rowVector> vec( 5UL, 5UL );
      vec.insert( 0UL, 5 );
      vec.insert( 1UL, 5 );
      vec.insert( 2UL, 5 );
      vec.insert( 3UL, 5 );
      vec.insert( 4UL, 5 );

      if( blaze::isUniform( vec ) != true ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Invalid isUniform evaluation\n"
             << " Details:\n"
             << "   Vector:\n" << vec << "\n";
         throw std::runtime_error( oss.str() );
      }
   }

   // Non-uniform 5-dimensional vector (2 non-zeros)
   {
      blaze::CompressedVector<int,blaze::rowVector> vec( 5UL, 2UL );
      vec.insert( 1UL, 0 );
      vec.insert( 4UL, 3 );

      if( blaze::isUniform( vec ) != false ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Invalid isUniform evaluation\n"
             << " Details:\n"
             << "   Vector:\n" << vec << "\n";
         throw std::runtime_error( oss.str() );
      }
   }

   // Uniform 5-dimensional vector (5 non-zeros)
   {
      blaze::CompressedVector<int,blaze::rowVector> vec( 5UL, 5UL );
      vec.insert( 0UL, 5 );
      vec.insert( 1UL, 5 );
      vec.insert( 2UL, 5 );
      vec.insert( 3UL, 5 );
      vec.insert( 4UL, 3 );

      if( blaze::isUniform( vec ) != false ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Invalid isUniform evaluation\n"
             << " Details:\n"
             << "   Vector:\n" << vec << "\n";
         throw std::runtime_error( oss.str() );
      }
   }
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Test of the \c length() and \c sqrLength() functions for sparse vectors.
//
// \return void
// \exception std::runtime_error Error detected.
//
// This function performs a test of the \c length() and \c sqrLength() functions for sparse
// vectors. In case an error is detected, a \a std::runtime_error exception is thrown.
*/
void OperationTest::testLength()
{
   test_ = "length() and sqrLength() functions";

   {
      // Initialization check
      blaze::CompressedVector<double,blaze::rowVector> vec;

      // Computing the vector length
      const double len( length( vec ) );

      if( !blaze::equal( len, 0.0 ) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Length computation failed\n"
             << " Details:\n"
             << "   Result: " << len << "\n"
             << "   Expected result: 0\n";
         throw std::runtime_error( oss.str() );
      }

      // Computing the vector square length
      const double sqrlen( sqrLength( vec ) );

      if( !blaze::equal( sqrLength( vec ), 0.0 ) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Square length computation failed\n"
             << " Details:\n"
             << "   Result: " << sqrlen << "\n"
             << "   Expected result: 0\n";
         throw std::runtime_error( oss.str() );
      }
   }

   {
      // Initialization check
      blaze::CompressedVector<double,blaze::rowVector> vec( 5UL );

      // Computing the vector length
      const double len( length( vec ) );

      if( !blaze::equal( len, 0.0 ) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Length computation failed\n"
             << " Details:\n"
             << "   Result: " << len << "\n"
             << "   Expected result: 0\n";
         throw std::runtime_error( oss.str() );
      }

      // Computing the vector square length
      const double sqrlen( sqrLength( vec ) );

      if( !blaze::equal( sqrLength( vec ), 0.0 ) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Square length computation failed\n"
             << " Details:\n"
             << "   Result: " << sqrlen << "\n"
             << "   Expected result: 0\n";
         throw std::runtime_error( oss.str() );
      }
   }

   {
      // Initialization check
      blaze::CompressedVector<double,blaze::rowVector> vec( 5UL, 2UL );
      vec[1] = 3.0;
      vec[4] = 4.0;

      // Computing the vector length
      const double len( length( vec ) );

      if( !blaze::equal( len, 5.0 ) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Length computation failed\n"
             << " Details:\n"
             << "   Result: " << len << "\n"
             << "   Expected result: 5\n";
         throw std::runtime_error( oss.str() );
      }

      // Computing the vector square length
      const double sqrlen( sqrLength( vec ) );

      if( !blaze::equal( sqrLength( vec ), 25.0 ) ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Square length computation failed\n"
             << " Details:\n"
             << "   Result: " << sqrlen << "\n"
             << "   Expected result: 25\n";
         throw std::runtime_error( oss.str() );
      }
   }
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Test of the \c normalize() function for sparse vectors.
//
// \return void
// \exception std::runtime_error Error detected.
//
// This function performs a test of the \c normalize() function for sparse vectors. In case
// an error is detected, a \a std::runtime_error exception is thrown.
*/
void OperationTest::testNormalize()
{
   test_ = "normalize() function";

   // Initialization check
   blaze::CompressedVector<double,blaze::rowVector> vec( 10UL, 4UL );
   vec[0] = 1.0;
   vec[1] = 2.0;
   vec[2] = 3.0;
   vec[3] = 4.0;

   checkSize    ( vec, 10UL );
   checkCapacity( vec,  4UL );
   checkNonZeros( vec,  4UL );

   if( vec[0] != 1.0 || vec[1] != 2.0 || vec[2] != 3.0 || vec[3] != 4.0 ) {
      std::ostringstream oss;
      oss << " Test: " << test_ << "\n"
          << " Error: Initialization failed\n"
          << " Details:\n"
          << "   Result:\n" << vec << "\n"
          << "   Expected result:\n( 1 2 3 4 0 0 0 0 0 0 )\n";
      throw std::runtime_error( oss.str() );
   }

   // Acquiring normalized vector
   const blaze::CompressedVector<double,blaze::rowVector> normalized( normalize( vec ) );

   if( !blaze::equal( length( normalized ), 1.0 ) ) {
      std::ostringstream oss;
      oss << " Test: CompressedVector::getNormalized()\n"
          << " Error: Normalization failed\n"
          << " Details:\n"
          << "   Result: " << length( normalized ) << "\n"
          << "   Expected result: 1\n";
      throw std::runtime_error( oss.str() );
   }

   // Normalizing the vector
   vec = normalize( vec );

   if( !blaze::equal( length( vec ), 1.0 ) ) {
      std::ostringstream oss;
      oss << " Test: " << test_ << "\n"
          << " Error: Normalization failed\n"
          << " Details:\n"
          << "   Result: " << length( vec ) << "\n"
          << "   Expected result: 1\n";
      throw std::runtime_error( oss.str() );
   }
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Test of the \c min() function for sparse vectors.
//
// \return void
// \exception std::runtime_error Error detected.
//
// This function performs a test of the \c min() function for sparse vectors template. In case an
// error is detected, a \a std::runtime_error exception is thrown.
*/
void OperationTest::testMinimum()
{
   test_ = "min() function";

   {
      blaze::CompressedVector<int,blaze::rowVector> vec( 8UL, 3UL );
      vec[1] =  1;
      vec[3] =  4;
      vec[7] =  3;

      const int minimum = min( vec );

      if( minimum != 0 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: First computation failed\n"
             << " Details:\n"
             << "   Result: " << minimum << "\n"
             << "   Expected result: 0\n";
         throw std::runtime_error( oss.str() );
      }
   }

   {
      blaze::CompressedVector<int,blaze::rowVector> vec( 8UL, 4UL );
      vec[1] =  -4;
      vec[3] =  -2;
      vec[5] =   8;
      vec[7] =  -3;

      const int minimum = min( vec );

      if( minimum != -4 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Second computation failed\n"
             << " Details:\n"
             << "   Result: " << minimum << "\n"
             << "   Expected result: -4\n";
         throw std::runtime_error( oss.str() );
      }
   }

   {
      blaze::CompressedVector<int,blaze::rowVector> vec( 8UL, 2UL );
      vec[5] =   8;
      vec[6] =  -3;

      const int minimum = min( vec );

      if( minimum != -3 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Third computation failed\n"
             << " Details:\n"
             << "   Result: " << minimum << "\n"
             << "   Expected result: -3\n";
         throw std::runtime_error( oss.str() );
      }
   }
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Test of the \c max() function for sparse vectors.
//
// \return void
// \exception std::runtime_error Error detected.
//
// This function performs a test of the \c max() function for sparse vectors template. In case an
// error is detected, a \a std::runtime_error exception is thrown.
*/
void OperationTest::testMaximum()
{
   test_ = "max() function";

   {
      blaze::CompressedVector<int,blaze::rowVector> vec( 8UL, 3UL );
      vec[1] = -1;
      vec[3] = -4;
      vec[7] = -3;

      const int maximum = max( vec );

      if( maximum != 0 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: First computation failed\n"
             << " Details:\n"
             << "   Result: " << maximum << "\n"
             << "   Expected result: 0\n";
         throw std::runtime_error( oss.str() );
      }
   }

   {
      blaze::CompressedVector<int,blaze::rowVector> vec( 8UL, 4UL );
      vec[1] =  4;
      vec[3] =  2;
      vec[5] = -8;
      vec[7] =  3;

      const int maximum = max( vec );

      if( maximum != 4 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Second computation failed\n"
             << " Details:\n"
             << "   Result: " << maximum << "\n"
             << "   Expected result: 4\n";
         throw std::runtime_error( oss.str() );
      }
   }

   {
      blaze::CompressedVector<int,blaze::rowVector> vec( 8UL, 2UL );
      vec[5] = -8;
      vec[6] =  3;

      const int maximum = max( vec );

      if( maximum != 3 ) {
         std::ostringstream oss;
         oss << " Test: " << test_ << "\n"
             << " Error: Third computation failed\n"
             << " Details:\n"
             << "   Result: " << maximum << "\n"
             << "   Expected result: 3\n";
         throw std::runtime_error( oss.str() );
      }
   }
}
//*************************************************************************************************

} // namespace sparsevector

} // namespace mathtest

} // namespace blazetest




//=================================================================================================
//
//  MAIN FUNCTION
//
//=================================================================================================

//*************************************************************************************************
int main()
{
   std::cout << "   Running SparseVector operation test..." << std::endl;

   try
   {
      RUN_SPARSEVECTOR_OPERATION_TEST;
   }
   catch( std::exception& ex ) {
      std::cerr << "\n\n ERROR DETECTED during SparseVector operation test:\n"
                << ex.what() << "\n";
      return EXIT_FAILURE;
   }

   return EXIT_SUCCESS;
}
//*************************************************************************************************
