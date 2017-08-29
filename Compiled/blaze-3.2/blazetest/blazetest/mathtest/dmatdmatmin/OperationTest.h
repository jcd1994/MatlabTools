//=================================================================================================
/*!
//  \file blazetest/mathtest/dmatdmatmin/OperationTest.h
//  \brief Header file for the dense matrix/dense matrix minimum operation test
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

#ifndef _BLAZETEST_MATHTEST_DMATDMATMIN_OPERATIONTEST_H_
#define _BLAZETEST_MATHTEST_DMATDMATMIN_OPERATIONTEST_H_


//*************************************************************************************************
// Includes
//*************************************************************************************************

#include <sstream>
#include <stdexcept>
#include <string>
#include <typeinfo>
#include <blaze/math/Aliases.h>
#include <blaze/math/CompressedMatrix.h>
#include <blaze/math/constraints/ColumnMajorMatrix.h>
#include <blaze/math/constraints/DenseMatrix.h>
#include <blaze/math/constraints/RowMajorMatrix.h>
#include <blaze/math/constraints/SparseMatrix.h>
#include <blaze/math/DynamicMatrix.h>
#include <blaze/math/Functors.h>
#include <blaze/math/shims/Equal.h>
#include <blaze/math/shims/IsDefault.h>
#include <blaze/math/traits/BinaryMapTrait.h>
#include <blaze/math/typetraits/IsDiagonal.h>
#include <blaze/math/typetraits/IsHermitian.h>
#include <blaze/math/typetraits/IsResizable.h>
#include <blaze/math/typetraits/IsRowMajorMatrix.h>
#include <blaze/math/typetraits/IsSquare.h>
#include <blaze/math/typetraits/IsSymmetric.h>
#include <blaze/math/typetraits/IsTriangular.h>
#include <blaze/math/typetraits/UnderlyingBuiltin.h>
#include <blaze/math/typetraits/UnderlyingNumeric.h>
#include <blaze/math/Views.h>
#include <blaze/util/algorithms/Min.h>
#include <blaze/util/constraints/Numeric.h>
#include <blaze/util/constraints/SameType.h>
#include <blaze/util/FalseType.h>
#include <blaze/util/mpl/If.h>
#include <blaze/util/mpl/Or.h>
#include <blaze/util/Random.h>
#include <blaze/util/TrueType.h>
#include <blaze/util/typetraits/IsComplex.h>
#include <blazetest/system/LAPACK.h>
#include <blazetest/system/MathTest.h>
#include <blazetest/mathtest/Creator.h>
#include <blazetest/mathtest/IsEqual.h>
#include <blazetest/mathtest/MatchAdaptor.h>
#include <blazetest/mathtest/MatchSymmetry.h>
#include <blazetest/mathtest/RandomMaximum.h>
#include <blazetest/mathtest/RandomMinimum.h>


namespace blazetest {

namespace mathtest {

namespace dmatdmatmin {

//=================================================================================================
//
//  CLASS DEFINITION
//
//=================================================================================================

//*************************************************************************************************
/*!\brief Auxiliary class template for the dense matrix/dense matrix minimum operation test.
//
// This class template represents one particular matrix minimum test between two matrices of
// a particular type. The two template arguments \a MT1 and \a MT2 represent the types of the
// left-hand side and right-hand side matrix, respectively.
*/
template< typename MT1    // Type of the left-hand side dense matrix
        , typename MT2 >  // Type of the right-hand side dense matrix
class OperationTest
{
 private:
   //**Type definitions****************************************************************************
   typedef blaze::ElementType_<MT1>  ET1;  //!< Element type 1
   typedef blaze::ElementType_<MT2>  ET2;  //!< Element type 2

   typedef blaze::OppositeType_<MT1>    OMT1;   //!< Matrix type 1 with opposite storage order
   typedef blaze::OppositeType_<MT2>    OMT2;   //!< Matrix type 2 with opposite storage order
   typedef blaze::TransposeType_<MT1>   TMT1;   //!< Transpose matrix type 1
   typedef blaze::TransposeType_<MT2>   TMT2;   //!< Transpose matrix type 2
   typedef blaze::TransposeType_<OMT1>  TOMT1;  //!< Transpose matrix type 1 with opposite storage order
   typedef blaze::TransposeType_<OMT2>  TOMT2;  //!< Transpose matrix type 2 with opposite storage order

   //! Dense result type
   typedef blaze::BinaryMapTrait_<MT1,MT2,blaze::Min>  DRE;

   typedef blaze::ElementType_<DRE>     DET;    //!< Element type of the dense result
   typedef blaze::OppositeType_<DRE>    ODRE;   //!< Dense result type with opposite storage order
   typedef blaze::TransposeType_<DRE>   TDRE;   //!< Transpose dense result type
   typedef blaze::TransposeType_<ODRE>  TODRE;  //!< Transpose dense result type with opposite storage order

   //! Sparse result type
   typedef MatchAdaptor_< DRE, blaze::CompressedMatrix<DET,false> >  SRE;

   typedef blaze::ElementType_<SRE>     SET;    //!< Element type of the sparse result
   typedef blaze::OppositeType_<SRE>    OSRE;   //!< Sparse result type with opposite storage order
   typedef blaze::TransposeType_<SRE>   TSRE;   //!< Transpose sparse result type
   typedef blaze::TransposeType_<OSRE>  TOSRE;  //!< Transpose sparse result type with opposite storage order

   typedef blaze::DynamicMatrix<blaze::ElementType_<DRE>,false>  RT;  //!< Reference type
   //**********************************************************************************************

 public:
   //**Constructors********************************************************************************
   /*!\name Constructors */
   //@{
   explicit OperationTest( const Creator<MT1>& creator1, const Creator<MT2>& creator2 );
   // No explicitly declared copy constructor.
   //@}
   //**********************************************************************************************

   //**Destructor**********************************************************************************
   // No explicitly declared destructor.
   //**********************************************************************************************

 private:
   //**Test functions******************************************************************************
   /*!\name Test functions */
   //@{
                          void testEvaluation        ();
                          void testElementAccess     ();
                          void testBasicOperation    ();
                          void testNegatedOperation  ();
   template< typename T > void testScaledOperation   ( T scalar );
                          void testTransOperation    ();
                          void testCTransOperation   ();
                          void testAbsOperation      ();
                          void testConjOperation     ();
                          void testRealOperation     ();
                          void testImagOperation     ();
                          void testInvOperation      ();
                          void testEvalOperation     ();
                          void testSerialOperation   ();
                          void testDeclSymOperation  ( blaze::TrueType  );
                          void testDeclSymOperation  ( blaze::FalseType );
                          void testDeclHermOperation ( blaze::TrueType  );
                          void testDeclHermOperation ( blaze::FalseType );
                          void testDeclLowOperation  ( blaze::TrueType  );
                          void testDeclLowOperation  ( blaze::FalseType );
                          void testDeclUppOperation  ( blaze::TrueType  );
                          void testDeclUppOperation  ( blaze::FalseType );
                          void testDeclDiagOperation ( blaze::TrueType  );
                          void testDeclDiagOperation ( blaze::FalseType );
                          void testSubmatrixOperation();
                          void testRowOperation      ();
                          void testColumnOperation   ();

   template< typename OP > void testCustomOperation( OP op, const std::string& name );
   //@}
   //**********************************************************************************************

   //**Error detection functions*******************************************************************
   /*!\name Error detection functions */
   //@{
   template< typename LT, typename RT > void checkResults();
   template< typename LT, typename RT > void checkTransposeResults();
   //@}
   //**********************************************************************************************

   //**Utility functions***************************************************************************
   /*!\name Utility functions */
   //@{
   void initResults();
   void initTransposeResults();
   template< typename LT, typename RT > void convertException( const std::exception& ex );
   //@}
   //**********************************************************************************************

   //**Member variables****************************************************************************
   /*!\name Member variables */
   //@{
   MT1   lhs_;     //!< The left-hand side dense matrix.
   MT2   rhs_;     //!< The right-hand side dense matrix.
   OMT1  olhs_;    //!< The left-hand side dense matrix with opposite storage order.
   OMT2  orhs_;    //!< The right-hand side dense matrix with opposite storage order.
   DRE   dres_;    //!< The dense result matrix.
   SRE   sres_;    //!< The sparse result matrix.
   ODRE  odres_;   //!< The dense result matrix with opposite storage order.
   OSRE  osres_;   //!< The sparse result matrix with opposite storage order.
   TDRE  tdres_;   //!< The transpose dense result matrix.
   TSRE  tsres_;   //!< The transpose sparse result matrix.
   TODRE todres_;  //!< The transpose dense result matrix with opposite storage order.
   TOSRE tosres_;  //!< The transpose sparse result matrix with opposite storage order.
   RT    ref_;     //!< The reference matrix.
   RT    refres_;  //!< The reference result.

   std::string test_;   //!< Label of the currently performed test.
   std::string error_;  //!< Description of the current error type.
   //@}
   //**********************************************************************************************

   //**Compile time checks*************************************************************************
   /*! \cond BLAZE_INTERNAL */
   BLAZE_CONSTRAINT_MUST_BE_DENSE_MATRIX_TYPE ( MT1   );
   BLAZE_CONSTRAINT_MUST_BE_DENSE_MATRIX_TYPE ( MT2   );
   BLAZE_CONSTRAINT_MUST_BE_DENSE_MATRIX_TYPE ( OMT1  );
   BLAZE_CONSTRAINT_MUST_BE_DENSE_MATRIX_TYPE ( OMT2  );
   BLAZE_CONSTRAINT_MUST_BE_DENSE_MATRIX_TYPE ( TMT1  );
   BLAZE_CONSTRAINT_MUST_BE_DENSE_MATRIX_TYPE ( TMT2  );
   BLAZE_CONSTRAINT_MUST_BE_DENSE_MATRIX_TYPE ( TOMT1 );
   BLAZE_CONSTRAINT_MUST_BE_DENSE_MATRIX_TYPE ( TOMT2 );
   BLAZE_CONSTRAINT_MUST_BE_DENSE_MATRIX_TYPE ( RT    );
   BLAZE_CONSTRAINT_MUST_BE_DENSE_MATRIX_TYPE ( DRE   );
   BLAZE_CONSTRAINT_MUST_BE_SPARSE_MATRIX_TYPE( SRE   );
   BLAZE_CONSTRAINT_MUST_BE_DENSE_MATRIX_TYPE ( ODRE  );
   BLAZE_CONSTRAINT_MUST_BE_SPARSE_MATRIX_TYPE( OSRE  );
   BLAZE_CONSTRAINT_MUST_BE_DENSE_MATRIX_TYPE ( TDRE  );
   BLAZE_CONSTRAINT_MUST_BE_SPARSE_MATRIX_TYPE( TSRE  );
   BLAZE_CONSTRAINT_MUST_BE_DENSE_MATRIX_TYPE ( TODRE );
   BLAZE_CONSTRAINT_MUST_BE_SPARSE_MATRIX_TYPE( TOSRE );

   BLAZE_CONSTRAINT_MUST_BE_ROW_MAJOR_MATRIX_TYPE   ( MT1   );
   BLAZE_CONSTRAINT_MUST_BE_ROW_MAJOR_MATRIX_TYPE   ( MT2   );
   BLAZE_CONSTRAINT_MUST_BE_COLUMN_MAJOR_MATRIX_TYPE( OMT1  );
   BLAZE_CONSTRAINT_MUST_BE_COLUMN_MAJOR_MATRIX_TYPE( OMT2  );
   BLAZE_CONSTRAINT_MUST_BE_COLUMN_MAJOR_MATRIX_TYPE( TMT1  );
   BLAZE_CONSTRAINT_MUST_BE_COLUMN_MAJOR_MATRIX_TYPE( TMT2  );
   BLAZE_CONSTRAINT_MUST_BE_ROW_MAJOR_MATRIX_TYPE   ( TOMT1 );
   BLAZE_CONSTRAINT_MUST_BE_ROW_MAJOR_MATRIX_TYPE   ( TOMT2 );
   BLAZE_CONSTRAINT_MUST_BE_ROW_MAJOR_MATRIX_TYPE   ( RT    );
   BLAZE_CONSTRAINT_MUST_BE_ROW_MAJOR_MATRIX_TYPE   ( DRE   );
   BLAZE_CONSTRAINT_MUST_BE_ROW_MAJOR_MATRIX_TYPE   ( SRE   );
   BLAZE_CONSTRAINT_MUST_BE_COLUMN_MAJOR_MATRIX_TYPE( ODRE  );
   BLAZE_CONSTRAINT_MUST_BE_COLUMN_MAJOR_MATRIX_TYPE( OSRE  );
   BLAZE_CONSTRAINT_MUST_BE_COLUMN_MAJOR_MATRIX_TYPE( TDRE  );
   BLAZE_CONSTRAINT_MUST_BE_COLUMN_MAJOR_MATRIX_TYPE( TSRE  );
   BLAZE_CONSTRAINT_MUST_BE_ROW_MAJOR_MATRIX_TYPE   ( TODRE );
   BLAZE_CONSTRAINT_MUST_BE_ROW_MAJOR_MATRIX_TYPE   ( TOSRE );

   BLAZE_CONSTRAINT_MUST_BE_SAME_TYPE( ET1, blaze::ElementType_<OMT1>   );
   BLAZE_CONSTRAINT_MUST_BE_SAME_TYPE( ET2, blaze::ElementType_<OMT2>   );
   BLAZE_CONSTRAINT_MUST_BE_SAME_TYPE( ET1, blaze::ElementType_<TMT1>   );
   BLAZE_CONSTRAINT_MUST_BE_SAME_TYPE( ET2, blaze::ElementType_<TMT2>   );
   BLAZE_CONSTRAINT_MUST_BE_SAME_TYPE( ET1, blaze::ElementType_<TOMT1>  );
   BLAZE_CONSTRAINT_MUST_BE_SAME_TYPE( ET2, blaze::ElementType_<TOMT2>  );
   BLAZE_CONSTRAINT_MUST_BE_SAME_TYPE( DET, blaze::ElementType_<DRE>    );
   BLAZE_CONSTRAINT_MUST_BE_SAME_TYPE( DET, blaze::ElementType_<ODRE>   );
   BLAZE_CONSTRAINT_MUST_BE_SAME_TYPE( DET, blaze::ElementType_<TDRE>   );
   BLAZE_CONSTRAINT_MUST_BE_SAME_TYPE( DET, blaze::ElementType_<TODRE>  );
   BLAZE_CONSTRAINT_MUST_BE_SAME_TYPE( DET, blaze::ElementType_<SRE>    );
   BLAZE_CONSTRAINT_MUST_BE_SAME_TYPE( SET, blaze::ElementType_<SRE>    );
   BLAZE_CONSTRAINT_MUST_BE_SAME_TYPE( SET, blaze::ElementType_<OSRE>   );
   BLAZE_CONSTRAINT_MUST_BE_SAME_TYPE( SET, blaze::ElementType_<TSRE>   );
   BLAZE_CONSTRAINT_MUST_BE_SAME_TYPE( SET, blaze::ElementType_<TOSRE>  );
   BLAZE_CONSTRAINT_MUST_BE_SAME_TYPE( SET, blaze::ElementType_<DRE>    );
   BLAZE_CONSTRAINT_MUST_BE_SAME_TYPE( MT1, blaze::OppositeType_<OMT1>  );
   BLAZE_CONSTRAINT_MUST_BE_SAME_TYPE( MT2, blaze::OppositeType_<OMT2>  );
   BLAZE_CONSTRAINT_MUST_BE_SAME_TYPE( MT1, blaze::TransposeType_<TMT1> );
   BLAZE_CONSTRAINT_MUST_BE_SAME_TYPE( MT2, blaze::TransposeType_<TMT2> );
   BLAZE_CONSTRAINT_MUST_BE_SAME_TYPE( DRE, blaze::OppositeType_<ODRE>  );
   BLAZE_CONSTRAINT_MUST_BE_SAME_TYPE( DRE, blaze::TransposeType_<TDRE> );
   BLAZE_CONSTRAINT_MUST_BE_SAME_TYPE( SRE, blaze::OppositeType_<OSRE>  );
   BLAZE_CONSTRAINT_MUST_BE_SAME_TYPE( SRE, blaze::TransposeType_<TSRE> );
   /*! \endcond */
   //**********************************************************************************************
};
//*************************************************************************************************




//=================================================================================================
//
//  CONSTRUCTORS
//
//=================================================================================================

//*************************************************************************************************
/*!\brief Constructor for the dense matrix/dense matrix minimum operation test.
//
// \param creator1 The creator for the left-hand side dense matrix of the matrix minimum.
// \param creator2 The creator for the right-hand side dense matrix of the matrix minimum.
// \exception std::runtime_error Operation error detected.
*/
template< typename MT1    // Type of the left-hand side dense matrix
        , typename MT2 >  // Type of the right-hand side dense matrix
OperationTest<MT1,MT2>::OperationTest( const Creator<MT1>& creator1, const Creator<MT2>& creator2 )
   : lhs_( creator1() )  // The left-hand side dense matrix
   , rhs_( creator2() )  // The right-hand side dense matrix
   , olhs_( lhs_ )       // The left-hand side dense matrix with opposite storage order
   , orhs_( rhs_ )       // The right-hand side dense matrix with opposite storage order
   , dres_()             // The dense result matrix
   , sres_()             // The sparse result matrix
   , odres_()            // The dense result matrix with opposite storage order
   , osres_()            // The sparse result matrix with opposite storage order
   , tdres_()            // The transpose dense result matrix
   , tsres_()            // The transpose sparse result matrix
   , todres_()           // The transpose dense result matrix with opposite storage order
   , tosres_()           // The transpose sparse result matrix with opposite storage order
   , ref_()              // The reference left-hand side matrix
   , refres_()           // The reference result
   , test_()             // Label of the currently performed test
   , error_()            // Description of the current error type
{
   typedef blaze::UnderlyingNumeric_<DET>  Scalar;

   if( lhs_.rows() != rhs_.rows() || lhs_.columns() != rhs_.columns() ) {
      throw std::runtime_error( "Non-matching operands detected" );
   }

   ref_.resize( lhs_.rows(), lhs_.columns() );
   for( size_t i=0UL; i<lhs_.rows(); ++i ) {
      for( size_t j=0UL; j<lhs_.columns(); ++j ) {
         ref_(i,j) = blaze::min( lhs_(i,j), rhs_(i,j) );
      }
   }

   testEvaluation();
   testElementAccess();
   testBasicOperation();
   testNegatedOperation();
   testScaledOperation( 2 );
   testScaledOperation( 2UL );
   testScaledOperation( 2.0F );
   testScaledOperation( 2.0 );
   testScaledOperation( Scalar( 2 ) );
   testTransOperation();
   testCTransOperation();
   testAbsOperation();
   testConjOperation();
   testRealOperation();
   testImagOperation();
   testInvOperation();
   testEvalOperation();
   testSerialOperation();
   testDeclSymOperation( blaze::Or< blaze::IsSquare<DRE>, blaze::IsResizable<DRE> >() );
   testDeclHermOperation( blaze::Or< blaze::IsSquare<DRE>, blaze::IsResizable<DRE> >() );
   testDeclLowOperation( blaze::Or< blaze::IsSquare<DRE>, blaze::IsResizable<DRE> >() );
   testDeclUppOperation( blaze::Or< blaze::IsSquare<DRE>, blaze::IsResizable<DRE> >() );
   testDeclDiagOperation( blaze::Or< blaze::IsSquare<DRE>, blaze::IsResizable<DRE> >() );
   testSubmatrixOperation();
   testRowOperation();
   testColumnOperation();
}
//*************************************************************************************************






//=================================================================================================
//
//  TEST FUNCTIONS
//
//=================================================================================================

//*************************************************************************************************
/*!\brief Testing the explicit evaluation.
//
// \return void
// \exception std::runtime_error Evaluation error detected.
//
// This function tests the explicit evaluation. In case any error is detected, a
// \a std::runtime_error exception is thrown.
*/
template< typename MT1    // Type of the left-hand side dense matrix
        , typename MT2 >  // Type of the right-hand side dense matrix
void OperationTest<MT1,MT2>::testEvaluation()
{
   using blaze::IsRowMajorMatrix;


   //=====================================================================================
   // Testing the evaluation with two row-major matrices
   //=====================================================================================

   {
      const auto res   ( evaluate( min( lhs_, rhs_ ) ) );
      const auto refres( evaluate( ref_ ) );

      if( !isEqual( res, refres ) ) {
         std::ostringstream oss;
         oss << " Test: Evaluation with the given matrices\n"
             << " Error: Failed evaluation\n"
             << " Details:\n"
             << "   Random seed = " << blaze::getSeed() << "\n"
             << "   Left-hand side " << ( IsRowMajorMatrix<MT1>::value ? ( "row-major" ) : ( "column-major" ) ) << " dense matrix type:\n"
             << "     " << typeid( lhs_ ).name() << "\n"
             << "   Right-hand side " << ( IsRowMajorMatrix<MT2>::value ? ( "row-major" ) : ( "column-major" ) ) << " dense matrix type:\n"
             << "     " << typeid( rhs_ ).name() << "\n"
             << "   Deduced result type:\n"
             << "     " << typeid( res ).name() << "\n"
             << "   Deduced reference result type:\n"
             << "     " << typeid( refres ).name() << "\n"
             << "   Result:\n" << res << "\n"
             << "   Expected result:\n" << refres << "\n";
         throw std::runtime_error( oss.str() );
      }
   }

   {
      const auto res   ( evaluate( min( eval( lhs_ ), eval( rhs_ ) ) ) );
      const auto refres( evaluate( eval( ref_ ) ) );

      if( !isEqual( res, refres ) ) {
         std::ostringstream oss;
         oss << " Test: Evaluation with evaluated matrices\n"
             << " Error: Failed evaluation\n"
             << " Details:\n"
             << "   Random seed = " << blaze::getSeed() << "\n"
             << "   Left-hand side " << ( IsRowMajorMatrix<MT1>::value ? ( "row-major" ) : ( "column-major" ) ) << " dense matrix type:\n"
             << "     " << typeid( lhs_ ).name() << "\n"
             << "   Right-hand side " << ( IsRowMajorMatrix<MT2>::value ? ( "row-major" ) : ( "column-major" ) ) << " dense matrix type:\n"
             << "     " << typeid( rhs_ ).name() << "\n"
             << "   Deduced result type:\n"
             << "     " << typeid( res ).name() << "\n"
             << "   Deduced reference result type:\n"
             << "     " << typeid( refres ).name() << "\n"
             << "   Result:\n" << res << "\n"
             << "   Expected result:\n" << refres << "\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Testing the evaluation with a row-major matrix and a column-major matrix
   //=====================================================================================

   {
      const auto res   ( evaluate( min( lhs_, orhs_ ) ) );
      const auto refres( evaluate( ref_ ) );

      if( !isEqual( res, refres ) ) {
         std::ostringstream oss;
         oss << " Test: Evaluation with the given matrices\n"
             << " Error: Failed evaluation\n"
             << " Details:\n"
             << "   Random seed = " << blaze::getSeed() << "\n"
             << "   Left-hand side " << ( IsRowMajorMatrix<MT1>::value ? ( "row-major" ) : ( "column-major" ) ) << " dense matrix type:\n"
             << "     " << typeid( lhs_ ).name() << "\n"
             << "   Right-hand side " << ( IsRowMajorMatrix<OMT2>::value ? ( "row-major" ) : ( "column-major" ) ) << " dense matrix type:\n"
             << "     " << typeid( orhs_ ).name() << "\n"
             << "   Deduced result type:\n"
             << "     " << typeid( res ).name() << "\n"
             << "   Deduced reference result type:\n"
             << "     " << typeid( refres ).name() << "\n"
             << "   Result:\n" << res << "\n"
             << "   Expected result:\n" << refres << "\n";
         throw std::runtime_error( oss.str() );
      }
   }

   {
      const auto res   ( evaluate( min( eval( lhs_ ), eval( orhs_ ) ) ) );
      const auto refres( evaluate( eval( ref_ ) ) );

      if( !isEqual( res, refres ) ) {
         std::ostringstream oss;
         oss << " Test: Evaluation with the given matrices\n"
             << " Error: Failed evaluation\n"
             << " Details:\n"
             << "   Random seed = " << blaze::getSeed() << "\n"
             << "   Left-hand side " << ( IsRowMajorMatrix<MT1>::value ? ( "row-major" ) : ( "column-major" ) ) << " dense matrix type:\n"
             << "     " << typeid( lhs_ ).name() << "\n"
             << "   Right-hand side " << ( IsRowMajorMatrix<OMT2>::value ? ( "row-major" ) : ( "column-major" ) ) << " dense matrix type:\n"
             << "     " << typeid( orhs_ ).name() << "\n"
             << "   Deduced result type:\n"
             << "     " << typeid( res ).name() << "\n"
             << "   Deduced reference result type:\n"
             << "     " << typeid( refres ).name() << "\n"
             << "   Result:\n" << res << "\n"
             << "   Expected result:\n" << refres << "\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Testing the evaluation with a column-major matrix and a row-major matrix
   //=====================================================================================

   {
      const auto res   ( evaluate( min( olhs_, rhs_ ) ) );
      const auto refres( evaluate( ref_ ) );

      if( !isEqual( res, refres ) ) {
         std::ostringstream oss;
         oss << " Test: Evaluation with the given matrices\n"
             << " Error: Failed evaluation\n"
             << " Details:\n"
             << "   Random seed = " << blaze::getSeed() << "\n"
             << "   Left-hand side " << ( IsRowMajorMatrix<OMT1>::value ? ( "row-major" ) : ( "column-major" ) ) << " dense matrix type:\n"
             << "     " << typeid( olhs_ ).name() << "\n"
             << "   Right-hand side " << ( IsRowMajorMatrix<MT2>::value ? ( "row-major" ) : ( "column-major" ) ) << " dense matrix type:\n"
             << "     " << typeid( rhs_ ).name() << "\n"
             << "   Deduced result type:\n"
             << "     " << typeid( res ).name() << "\n"
             << "   Deduced reference result type:\n"
             << "     " << typeid( refres ).name() << "\n"
             << "   Result:\n" << res << "\n"
             << "   Expected result:\n" << refres << "\n";
         throw std::runtime_error( oss.str() );
      }
   }

   {
      const auto res   ( evaluate( min( eval( olhs_ ), eval( rhs_ ) ) ) );
      const auto refres( evaluate( eval( ref_ ) ) );

      if( !isEqual( res, refres ) ) {
         std::ostringstream oss;
         oss << " Test: Evaluation with the given matrices\n"
             << " Error: Failed evaluation\n"
             << " Details:\n"
             << "   Random seed = " << blaze::getSeed() << "\n"
             << "   Left-hand side " << ( IsRowMajorMatrix<OMT1>::value ? ( "row-major" ) : ( "column-major" ) ) << " dense matrix type:\n"
             << "     " << typeid( olhs_ ).name() << "\n"
             << "   Right-hand side " << ( IsRowMajorMatrix<MT2>::value ? ( "row-major" ) : ( "column-major" ) ) << " dense matrix type:\n"
             << "     " << typeid( rhs_ ).name() << "\n"
             << "   Deduced result type:\n"
             << "     " << typeid( res ).name() << "\n"
             << "   Deduced reference result type:\n"
             << "     " << typeid( refres ).name() << "\n"
             << "   Result:\n" << res << "\n"
             << "   Expected result:\n" << refres << "\n";
         throw std::runtime_error( oss.str() );
      }
   }


   //=====================================================================================
   // Testing the evaluation with two column-major matrices
   //=====================================================================================

   {
      const auto res   ( evaluate( min( olhs_, orhs_ ) ) );
      const auto refres( evaluate( ref_ ) );

      if( !isEqual( res, refres ) ) {
         std::ostringstream oss;
         oss << " Test: Evaluation with the given matrices\n"
             << " Error: Failed evaluation\n"
             << " Details:\n"
             << "   Random seed = " << blaze::getSeed() << "\n"
             << "   Left-hand side " << ( IsRowMajorMatrix<OMT1>::value ? ( "row-major" ) : ( "column-major" ) ) << " dense matrix type:\n"
             << "     " << typeid( olhs_ ).name() << "\n"
             << "   Right-hand side " << ( IsRowMajorMatrix<OMT2>::value ? ( "row-major" ) : ( "column-major" ) ) << " dense matrix type:\n"
             << "     " << typeid( orhs_ ).name() << "\n"
             << "   Deduced result type:\n"
             << "     " << typeid( res ).name() << "\n"
             << "   Deduced reference result type:\n"
             << "     " << typeid( refres ).name() << "\n"
             << "   Result:\n" << res << "\n"
             << "   Expected result:\n" << refres << "\n";
         throw std::runtime_error( oss.str() );
      }
   }

   {
      const auto res   ( evaluate( min( eval( olhs_ ), eval( orhs_ ) ) ) );
      const auto refres( evaluate( eval( ref_ ) ) );

      if( !isEqual( res, refres ) ) {
         std::ostringstream oss;
         oss << " Test: Evaluation with the given matrices\n"
             << " Error: Failed evaluation\n"
             << " Details:\n"
             << "   Random seed = " << blaze::getSeed() << "\n"
             << "   Left-hand side " << ( IsRowMajorMatrix<OMT1>::value ? ( "row-major" ) : ( "column-major" ) ) << " dense matrix type:\n"
             << "     " << typeid( olhs_ ).name() << "\n"
             << "   Right-hand side " << ( IsRowMajorMatrix<OMT2>::value ? ( "row-major" ) : ( "column-major" ) ) << " dense matrix type:\n"
             << "     " << typeid( orhs_ ).name() << "\n"
             << "   Deduced result type:\n"
             << "     " << typeid( res ).name() << "\n"
             << "   Deduced reference result type:\n"
             << "     " << typeid( refres ).name() << "\n"
             << "   Result:\n" << res << "\n"
             << "   Expected result:\n" << refres << "\n";
         throw std::runtime_error( oss.str() );
      }
   }
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Testing the matrix element access.
//
// \return void
// \exception std::runtime_error Element access error detected.
//
// This function tests the element access via the subscript operator. In case any
// error is detected, a \a std::runtime_error exception is thrown.
*/
template< typename MT1    // Type of the left-hand side dense matrix
        , typename MT2 >  // Type of the right-hand side dense matrix
void OperationTest<MT1,MT2>::testElementAccess()
{
   using blaze::equal;


   //=====================================================================================
   // Testing the element access with two row-major matrices
   //=====================================================================================

   if( lhs_.rows() > 0UL && lhs_.columns() > 0UL )
   {
      const size_t m( lhs_.rows()    - 1UL );
      const size_t n( lhs_.columns() - 1UL );

      if( !equal( min( lhs_, rhs_ )(m,n), ref_(m,n) ) ||
          !equal( min( lhs_, rhs_ ).at(m,n), ref_.at(m,n) ) ) {
         std::ostringstream oss;
         oss << " Test : Element access of minimum expression\n"
             << " Error: Unequal resulting elements at element (" << m << "," << n << ") detected\n"
             << " Details:\n"
             << "   Random seed = " << blaze::getSeed() << "\n"
             << "   Left-hand side row-major dense matrix type:\n"
             << "     " << typeid( MT1 ).name() << "\n"
             << "   Right-hand side row-major dense matrix type:\n"
             << "     " << typeid( MT2 ).name() << "\n";
         throw std::runtime_error( oss.str() );
      }

      if( !equal( min( lhs_, eval( rhs_ ) )(m,n), ref_(m,n) ) ||
          !equal( min( lhs_, eval( rhs_ ) ).at(m,n), ref_.at(m,n) ) ) {
         std::ostringstream oss;
         oss << " Test : Element access of right evaluated minimum expression\n"
             << " Error: Unequal resulting elements at element (" << m << "," << n << ") detected\n"
             << " Details:\n"
             << "   Random seed = " << blaze::getSeed() << "\n"
             << "   Left-hand side row-major dense matrix type:\n"
             << "     " << typeid( MT1 ).name() << "\n"
             << "   Right-hand side row-major dense matrix type:\n"
             << "     " << typeid( MT2 ).name() << "\n";
         throw std::runtime_error( oss.str() );
      }

      if( !equal( min( eval( lhs_ ), rhs_ )(m,n), ref_(m,n) ) ||
          !equal( min( eval( lhs_ ), rhs_ ).at(m,n), ref_.at(m,n) ) ) {
         std::ostringstream oss;
         oss << " Test : Element access of left evaluated minimum expression\n"
             << " Error: Unequal resulting elements at element (" << m << "," << n << ") detected\n"
             << " Details:\n"
             << "   Random seed = " << blaze::getSeed() << "\n"
             << "   Left-hand side row-major dense matrix type:\n"
             << "     " << typeid( MT1 ).name() << "\n"
             << "   Right-hand side row-major dense matrix type:\n"
             << "     " << typeid( MT2 ).name() << "\n";
         throw std::runtime_error( oss.str() );
      }

      if( !equal( min( eval( lhs_ ), eval( rhs_ ) )(m,n), ref_(m,n) ) ||
          !equal( min( eval( lhs_ ), eval( rhs_ ) ).at(m,n), ref_.at(m,n) ) ) {
         std::ostringstream oss;
         oss << " Test : Element access of fully evaluated minimum expression\n"
             << " Error: Unequal resulting elements at element (" << m << "," << n << ") detected\n"
             << " Details:\n"
             << "   Random seed = " << blaze::getSeed() << "\n"
             << "   Left-hand side row-major dense matrix type:\n"
             << "     " << typeid( MT1 ).name() << "\n"
             << "   Right-hand side row-major dense matrix type:\n"
             << "     " << typeid( MT2 ).name() << "\n";
         throw std::runtime_error( oss.str() );
      }
   }

   try {
      min( lhs_, rhs_ ).at( 0UL, lhs_.columns() );

      std::ostringstream oss;
      oss << " Test : Checked element access of minimum expression\n"
          << " Error: Out-of-bound access succeeded\n"
          << " Details:\n"
          << "   Random seed = " << blaze::getSeed() << "\n"
          << "   Left-hand side row-major dense matrix type:\n"
          << "     " << typeid( MT1 ).name() << "\n"
          << "   Right-hand side row-major dense matrix type:\n"
          << "     " << typeid( MT2 ).name() << "\n";
      throw std::runtime_error( oss.str() );
   }
   catch( std::out_of_range& ) {}

   try {
      min( lhs_, rhs_ ).at( lhs_.rows(), 0UL );

      std::ostringstream oss;
      oss << " Test : Checked element access of minimum expression\n"
          << " Error: Out-of-bound access succeeded\n"
          << " Details:\n"
          << "   Random seed = " << blaze::getSeed() << "\n"
          << "   Left-hand side row-major dense matrix type:\n"
          << "     " << typeid( MT1 ).name() << "\n"
          << "   Right-hand side row-major dense matrix type:\n"
          << "     " << typeid( MT2 ).name() << "\n";
      throw std::runtime_error( oss.str() );
   }
   catch( std::out_of_range& ) {}


   //=====================================================================================
   // Testing the element access with a row-major matrix and a column-major matrix
   //=====================================================================================

   if( lhs_.rows() > 0UL && lhs_.columns() > 0UL )
   {
      const size_t m( lhs_.rows()    - 1UL );
      const size_t n( lhs_.columns() - 1UL );

      if( !equal( min( lhs_, orhs_ )(m,n), ref_(m,n) ) ||
          !equal( min( lhs_, orhs_ ).at(m,n), ref_.at(m,n) ) ) {
         std::ostringstream oss;
         oss << " Test : Element access of minimum expression\n"
             << " Error: Unequal resulting elements at element (" << m << "," << n << ") detected\n"
             << " Details:\n"
             << "   Random seed = " << blaze::getSeed() << "\n"
             << "   Left-hand side row-major dense matrix type:\n"
             << "     " << typeid( MT1 ).name() << "\n"
             << "   Right-hand side column-major dense matrix type:\n"
             << "     " << typeid( OMT2 ).name() << "\n";
         throw std::runtime_error( oss.str() );
      }

      if( !equal( min( lhs_, eval( orhs_ ) )(m,n), ref_(m,n) ) ||
          !equal( min( lhs_, eval( orhs_ ) ).at(m,n), ref_.at(m,n) ) ) {
         std::ostringstream oss;
         oss << " Test : Element access of right evaluated minimum expression\n"
             << " Error: Unequal resulting elements at element (" << m << "," << n << ") detected\n"
             << " Details:\n"
             << "   Random seed = " << blaze::getSeed() << "\n"
             << "   Left-hand side row-major dense matrix type:\n"
             << "     " << typeid( MT1 ).name() << "\n"
             << "   Right-hand side column-major dense matrix type:\n"
             << "     " << typeid( OMT2 ).name() << "\n";
         throw std::runtime_error( oss.str() );
      }

      if( !equal( min( eval( lhs_ ), orhs_ )(m,n), ref_(m,n) ) ||
          !equal( min( eval( lhs_ ), orhs_ ).at(m,n), ref_.at(m,n) ) ) {
         std::ostringstream oss;
         oss << " Test : Element access of left evaluated minimum expression\n"
             << " Error: Unequal resulting elements at element (" << m << "," << n << ") detected\n"
             << " Details:\n"
             << "   Random seed = " << blaze::getSeed() << "\n"
             << "   Left-hand side row-major dense matrix type:\n"
             << "     " << typeid( MT1 ).name() << "\n"
             << "   Right-hand side column-major dense matrix type:\n"
             << "     " << typeid( OMT2 ).name() << "\n";
         throw std::runtime_error( oss.str() );
      }

      if( !equal( min( eval( lhs_ ), eval( orhs_ ) )(m,n), ref_(m,n) ) ||
          !equal( min( eval( lhs_ ), eval( orhs_ ) ).at(m,n), ref_.at(m,n) ) ) {
         std::ostringstream oss;
         oss << " Test : Element access of fully evaluated minimum expression\n"
             << " Error: Unequal resulting elements at element (" << m << "," << n << ") detected\n"
             << " Details:\n"
             << "   Random seed = " << blaze::getSeed() << "\n"
             << "   Left-hand side row-major dense matrix type:\n"
             << "     " << typeid( MT1 ).name() << "\n"
             << "   Right-hand side column-major dense matrix type:\n"
             << "     " << typeid( OMT2 ).name() << "\n";
         throw std::runtime_error( oss.str() );
      }
   }

   try {
      min( lhs_, orhs_ ).at( 0UL, lhs_.columns() );

      std::ostringstream oss;
      oss << " Test : Checked element access of minimum expression\n"
          << " Error: Out-of-bound access succeeded\n"
          << " Details:\n"
          << "   Random seed = " << blaze::getSeed() << "\n"
          << "   Left-hand side row-major dense matrix type:\n"
          << "     " << typeid( MT1 ).name() << "\n"
          << "   Right-hand side column-major dense matrix type:\n"
          << "     " << typeid( OMT2 ).name() << "\n";
      throw std::runtime_error( oss.str() );
   }
   catch( std::out_of_range& ) {}

   try {
      min( lhs_, orhs_ ).at( lhs_.rows(), 0UL );

      std::ostringstream oss;
      oss << " Test : Checked element access of minimum expression\n"
          << " Error: Out-of-bound access succeeded\n"
          << " Details:\n"
          << "   Random seed = " << blaze::getSeed() << "\n"
          << "   Left-hand side row-major dense matrix type:\n"
          << "     " << typeid( MT1 ).name() << "\n"
          << "   Right-hand side column-major dense matrix type:\n"
          << "     " << typeid( OMT2 ).name() << "\n";
      throw std::runtime_error( oss.str() );
   }
   catch( std::out_of_range& ) {}


   //=====================================================================================
   // Testing the element access with a column-major matrix and a row-major matrix
   //=====================================================================================

   if( olhs_.rows() > 0UL && olhs_.columns() > 0UL )
   {
      const size_t m( olhs_.rows()    - 1UL );
      const size_t n( olhs_.columns() - 1UL );

      if( !equal( min( olhs_, rhs_ )(m,n), ref_(m,n) ) ||
          !equal( min( olhs_, rhs_ ).at(m,n), ref_.at(m,n) ) ) {
         std::ostringstream oss;
         oss << " Test : Element access of minimum expression\n"
             << " Error: Unequal resulting elements at element (" << m << "," << n << ") detected\n"
             << " Details:\n"
             << "   Random seed = " << blaze::getSeed() << "\n"
             << "   Left-hand side column-major dense matrix type:\n"
             << "     " << typeid( OMT1 ).name() << "\n"
             << "   Right-hand side row-major dense matrix type:\n"
             << "     " << typeid( MT2 ).name() << "\n";
         throw std::runtime_error( oss.str() );
      }

      if( !equal( min( olhs_, eval( rhs_ ) )(m,n), ref_(m,n) ) ||
          !equal( min( olhs_, eval( rhs_ ) ).at(m,n), ref_.at(m,n) ) ) {
         std::ostringstream oss;
         oss << " Test : Element access of right evaluated minimum expression\n"
             << " Error: Unequal resulting elements at element (" << m << "," << n << ") detected\n"
             << " Details:\n"
             << "   Random seed = " << blaze::getSeed() << "\n"
             << "   Left-hand side column-major dense matrix type:\n"
             << "     " << typeid( OMT1 ).name() << "\n"
             << "   Right-hand side row-major dense matrix type:\n"
             << "     " << typeid( MT2 ).name() << "\n";
         throw std::runtime_error( oss.str() );
      }

      if( !equal( min( eval( olhs_ ), rhs_ )(m,n), ref_(m,n) ) ||
          !equal( min( eval( olhs_ ), rhs_ ).at(m,n), ref_.at(m,n) ) ) {
         std::ostringstream oss;
         oss << " Test : Element access of left evaluated minimum expression\n"
             << " Error: Unequal resulting elements at element (" << m << "," << n << ") detected\n"
             << " Details:\n"
             << "   Random seed = " << blaze::getSeed() << "\n"
             << "   Left-hand side column-major dense matrix type:\n"
             << "     " << typeid( OMT1 ).name() << "\n"
             << "   Right-hand side row-major dense matrix type:\n"
             << "     " << typeid( MT2 ).name() << "\n";
         throw std::runtime_error( oss.str() );
      }

      if( !equal( min( eval( olhs_ ), eval( rhs_ ) )(m,n), ref_(m,n) ) ||
          !equal( min( eval( olhs_ ), eval( rhs_ ) ).at(m,n), ref_.at(m,n) ) ) {
         std::ostringstream oss;
         oss << " Test : Element access of fully evaluated minimum expression\n"
             << " Error: Unequal resulting elements at element (" << m << "," << n << ") detected\n"
             << " Details:\n"
             << "   Random seed = " << blaze::getSeed() << "\n"
             << "   Left-hand side column-major dense matrix type:\n"
             << "     " << typeid( OMT1 ).name() << "\n"
             << "   Right-hand side row-major dense matrix type:\n"
             << "     " << typeid( MT2 ).name() << "\n";
         throw std::runtime_error( oss.str() );
      }
   }

   try {
      min( olhs_, rhs_ ).at( 0UL, lhs_.columns() );

      std::ostringstream oss;
      oss << " Test : Checked element access of minimum expression\n"
          << " Error: Out-of-bound access succeeded\n"
          << " Details:\n"
          << "   Random seed = " << blaze::getSeed() << "\n"
          << "   Left-hand side column-major dense matrix type:\n"
          << "     " << typeid( OMT1 ).name() << "\n"
          << "   Right-hand side row-major dense matrix type:\n"
          << "     " << typeid( MT2 ).name() << "\n";
      throw std::runtime_error( oss.str() );
   }
   catch( std::out_of_range& ) {}

   try {
      min( olhs_, rhs_ ).at( lhs_.rows(), 0UL );

      std::ostringstream oss;
      oss << " Test : Checked element access of minimum expression\n"
          << " Error: Out-of-bound access succeeded\n"
          << " Details:\n"
          << "   Random seed = " << blaze::getSeed() << "\n"
          << "   Left-hand side column-major dense matrix type:\n"
          << "     " << typeid( OMT1 ).name() << "\n"
          << "   Right-hand side row-major dense matrix type:\n"
          << "     " << typeid( MT2 ).name() << "\n";
      throw std::runtime_error( oss.str() );
   }
   catch( std::out_of_range& ) {}


   //=====================================================================================
   // Testing the element access with two column-major matrices
   //=====================================================================================

   if( olhs_.rows() > 0UL && olhs_.columns() > 0UL )
   {
      const size_t m( olhs_.rows()    - 1UL );
      const size_t n( olhs_.columns() - 1UL );

      if( !equal( min( olhs_, orhs_ )(m,n), ref_(m,n) ) ||
          !equal( min( olhs_, orhs_ ).at(m,n), ref_.at(m,n) ) ) {
         std::ostringstream oss;
         oss << " Test : Element access of minimum expression\n"
             << " Error: Unequal resulting elements at element (" << m << "," << n << ") detected\n"
             << " Details:\n"
             << "   Random seed = " << blaze::getSeed() << "\n"
             << "   Left-hand side column-major dense matrix type:\n"
             << "     " << typeid( OMT1 ).name() << "\n"
             << "   Right-hand side column-major dense matrix type:\n"
             << "     " << typeid( OMT2 ).name() << "\n";
         throw std::runtime_error( oss.str() );
      }

      if( !equal( min( olhs_, eval( orhs_ ) )(m,n), ref_(m,n) ) ||
          !equal( min( olhs_, eval( orhs_ ) ).at(m,n), ref_.at(m,n) ) ) {
         std::ostringstream oss;
         oss << " Test : Element access of right evaluated minimum expression\n"
             << " Error: Unequal resulting elements at element (" << m << "," << n << ") detected\n"
             << " Details:\n"
             << "   Random seed = " << blaze::getSeed() << "\n"
             << "   Left-hand side column-major dense matrix type:\n"
             << "     " << typeid( OMT1 ).name() << "\n"
             << "   Right-hand side column-major dense matrix type:\n"
             << "     " << typeid( OMT2 ).name() << "\n";
         throw std::runtime_error( oss.str() );
      }

      if( !equal( min( eval( olhs_ ), orhs_ )(m,n), ref_(m,n) ) ||
          !equal( min( eval( olhs_ ), orhs_ ).at(m,n), ref_.at(m,n) ) ) {
         std::ostringstream oss;
         oss << " Test : Element access of left evaluated minimum expression\n"
             << " Error: Unequal resulting elements at element (" << m << "," << n << ") detected\n"
             << " Details:\n"
             << "   Random seed = " << blaze::getSeed() << "\n"
             << "   Left-hand side column-major dense matrix type:\n"
             << "     " << typeid( OMT1 ).name() << "\n"
             << "   Right-hand side column-major dense matrix type:\n"
             << "     " << typeid( OMT2 ).name() << "\n";
         throw std::runtime_error( oss.str() );
      }

      if( !equal( min( eval( olhs_ ), eval( orhs_ ) )(m,n), ref_(m,n) ) ||
          !equal( min( eval( olhs_ ), eval( orhs_ ) ).at(m,n), ref_.at(m,n) ) ) {
         std::ostringstream oss;
         oss << " Test : Element access of fully evaluated minimum expression\n"
             << " Error: Unequal resulting elements at element (" << m << "," << n << ") detected\n"
             << " Details:\n"
             << "   Random seed = " << blaze::getSeed() << "\n"
             << "   Left-hand side column-major dense matrix type:\n"
             << "     " << typeid( OMT1 ).name() << "\n"
             << "   Right-hand side column-major dense matrix type:\n"
             << "     " << typeid( OMT2 ).name() << "\n";
         throw std::runtime_error( oss.str() );
      }
   }

   try {
      min( olhs_, orhs_ ).at( 0UL, lhs_.columns() );

      std::ostringstream oss;
      oss << " Test : Checked element access of minimum expression\n"
          << " Error: Out-of-bound access succeeded\n"
          << " Details:\n"
          << "   Random seed = " << blaze::getSeed() << "\n"
          << "   Left-hand side column-major dense matrix type:\n"
          << "     " << typeid( OMT1 ).name() << "\n"
          << "   Right-hand side column-major dense matrix type:\n"
          << "     " << typeid( OMT2 ).name() << "\n";
      throw std::runtime_error( oss.str() );
   }
   catch( std::out_of_range& ) {}

   try {
      min( olhs_, orhs_ ).at( lhs_.rows(), 0UL );

      std::ostringstream oss;
      oss << " Test : Checked element access of minimum expression\n"
          << " Error: Out-of-bound access succeeded\n"
          << " Details:\n"
          << "   Random seed = " << blaze::getSeed() << "\n"
          << "   Left-hand side column-major dense matrix type:\n"
          << "     " << typeid( OMT1 ).name() << "\n"
          << "   Right-hand side column-major dense matrix type:\n"
          << "     " << typeid( OMT2 ).name() << "\n";
      throw std::runtime_error( oss.str() );
   }
   catch( std::out_of_range& ) {}
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Testing the plain dense matrix/dense matrix minimum operation.
//
// \return void
// \exception std::runtime_error Minimum error detected.
//
// This function tests the matrix minimum with plain assignment, addition assignment,
// subtraction assignment, and Schur product assignment. In case any error resulting from
// the minimum operation or the subsequent assignment is detected, a \a std::runtime_error
// exception is thrown.
*/
template< typename MT1    // Type of the left-hand side dense matrix
        , typename MT2 >  // Type of the right-hand side dense matrix
void OperationTest<MT1,MT2>::testBasicOperation()
{
#if BLAZETEST_MATHTEST_TEST_BASIC_OPERATION
   if( BLAZETEST_MATHTEST_TEST_BASIC_OPERATION > 1 )
   {
      //=====================================================================================
      // Minimum
      //=====================================================================================

      // Minimum with the given matrices
      {
         test_  = "Minimum with the given matrices";
         error_ = "Failed minimum operation";

         try {
            initResults();
            dres_   = min( lhs_, rhs_ );
            odres_  = min( lhs_, rhs_ );
            sres_   = min( lhs_, rhs_ );
            osres_  = min( lhs_, rhs_ );
            refres_ = ref_;
         }
         catch( std::exception& ex ) {
            convertException<MT1,MT2>( ex );
         }

         checkResults<MT1,MT2>();

         try {
            initResults();
            dres_   = min( lhs_, orhs_ );
            odres_  = min( lhs_, orhs_ );
            sres_   = min( lhs_, orhs_ );
            osres_  = min( lhs_, orhs_ );
            refres_ = ref_;
         }
         catch( std::exception& ex ) {
            convertException<MT1,OMT2>( ex );
         }

         checkResults<MT1,OMT2>();

         try {
            initResults();
            dres_   = min( olhs_, rhs_ );
            odres_  = min( olhs_, rhs_ );
            sres_   = min( olhs_, rhs_ );
            osres_  = min( olhs_, rhs_ );
            refres_ = ref_;
         }
         catch( std::exception& ex ) {
            convertException<OMT1,MT2>( ex );
         }

         checkResults<OMT1,MT2>();

         try {
            initResults();
            dres_   = min( olhs_, orhs_ );
            odres_  = min( olhs_, orhs_ );
            sres_   = min( olhs_, orhs_ );
            osres_  = min( olhs_, orhs_ );
            refres_ = ref_;
         }
         catch( std::exception& ex ) {
            convertException<OMT1,OMT2>( ex );
         }

         checkResults<OMT1,OMT2>();
      }

      // Minimum with evaluated matrices
      {
         test_  = "Minimum with evaluated matrices";
         error_ = "Failed minimum operation";

         try {
            initResults();
            dres_   = min( eval( lhs_ ), eval( rhs_ ) );
            odres_  = min( eval( lhs_ ), eval( rhs_ ) );
            sres_   = min( eval( lhs_ ), eval( rhs_ ) );
            osres_  = min( eval( lhs_ ), eval( rhs_ ) );
            refres_ = eval( ref_ );
         }
         catch( std::exception& ex ) {
            convertException<MT1,MT2>( ex );
         }

         checkResults<MT1,MT2>();

         try {
            initResults();
            dres_   = min( eval( lhs_ ), eval( orhs_ ) );
            odres_  = min( eval( lhs_ ), eval( orhs_ ) );
            sres_   = min( eval( lhs_ ), eval( orhs_ ) );
            osres_  = min( eval( lhs_ ), eval( orhs_ ) );
            refres_ = eval( ref_ );
         }
         catch( std::exception& ex ) {
            convertException<MT1,OMT2>( ex );
         }

         checkResults<MT1,OMT2>();

         try {
            initResults();
            dres_   = min( eval( olhs_ ), eval( rhs_ ) );
            odres_  = min( eval( olhs_ ), eval( rhs_ ) );
            sres_   = min( eval( olhs_ ), eval( rhs_ ) );
            osres_  = min( eval( olhs_ ), eval( rhs_ ) );
            refres_ = eval( ref_ );
         }
         catch( std::exception& ex ) {
            convertException<OMT1,MT2>( ex );
         }

         checkResults<OMT1,MT2>();

         try {
            initResults();
            dres_   = min( eval( olhs_ ), eval( orhs_ ) );
            odres_  = min( eval( olhs_ ), eval( orhs_ ) );
            sres_   = min( eval( olhs_ ), eval( orhs_ ) );
            osres_  = min( eval( olhs_ ), eval( orhs_ ) );
            refres_ = eval( ref_ );
         }
         catch( std::exception& ex ) {
            convertException<OMT1,OMT2>( ex );
         }

         checkResults<OMT1,OMT2>();
      }


      //=====================================================================================
      // Minimum with addition assignment
      //=====================================================================================

      // Minimum with addition assignment with the given matrices
      {
         test_  = "Minimum with addition assignment with the given matrices";
         error_ = "Failed addition assignment operation";

         try {
            initResults();
            dres_   += min( lhs_, rhs_ );
            odres_  += min( lhs_, rhs_ );
            sres_   += min( lhs_, rhs_ );
            osres_  += min( lhs_, rhs_ );
            refres_ += ref_;
         }
         catch( std::exception& ex ) {
            convertException<MT1,MT2>( ex );
         }

         checkResults<MT1,MT2>();

         try {
            initResults();
            dres_   += min( lhs_, orhs_ );
            odres_  += min( lhs_, orhs_ );
            sres_   += min( lhs_, orhs_ );
            osres_  += min( lhs_, orhs_ );
            refres_ += ref_;
         }
         catch( std::exception& ex ) {
            convertException<MT1,OMT2>( ex );
         }

         checkResults<MT1,OMT2>();

         try {
            initResults();
            dres_   += min( olhs_, rhs_ );
            odres_  += min( olhs_, rhs_ );
            sres_   += min( olhs_, rhs_ );
            osres_  += min( olhs_, rhs_ );
            refres_ += ref_;
         }
         catch( std::exception& ex ) {
            convertException<OMT1,MT2>( ex );
         }

         checkResults<OMT1,MT2>();

         try {
            initResults();
            dres_   += min( olhs_, orhs_ );
            odres_  += min( olhs_, orhs_ );
            sres_   += min( olhs_, orhs_ );
            osres_  += min( olhs_, orhs_ );
            refres_ += ref_;
         }
         catch( std::exception& ex ) {
            convertException<OMT1,OMT2>( ex );
         }

         checkResults<OMT1,OMT2>();
      }

      // Minimum with addition assignment with evaluated matrices
      {
         test_  = "Minimum with addition assignment with evaluated matrices";
         error_ = "Failed addition assignment operation";

         try {
            initResults();
            dres_   += min( eval( lhs_ ), eval( rhs_ ) );
            odres_  += min( eval( lhs_ ), eval( rhs_ ) );
            sres_   += min( eval( lhs_ ), eval( rhs_ ) );
            osres_  += min( eval( lhs_ ), eval( rhs_ ) );
            refres_ += eval( ref_ );
         }
         catch( std::exception& ex ) {
            convertException<MT1,MT2>( ex );
         }

         checkResults<MT1,MT2>();

         try {
            initResults();
            dres_   += min( eval( lhs_ ), eval( orhs_ ) );
            odres_  += min( eval( lhs_ ), eval( orhs_ ) );
            sres_   += min( eval( lhs_ ), eval( orhs_ ) );
            osres_  += min( eval( lhs_ ), eval( orhs_ ) );
            refres_ += eval( ref_ );
         }
         catch( std::exception& ex ) {
            convertException<MT1,OMT2>( ex );
         }

         checkResults<MT1,OMT2>();

         try {
            initResults();
            dres_   += min( eval( olhs_ ), eval( rhs_ ) );
            odres_  += min( eval( olhs_ ), eval( rhs_ ) );
            sres_   += min( eval( olhs_ ), eval( rhs_ ) );
            osres_  += min( eval( olhs_ ), eval( rhs_ ) );
            refres_ += eval( ref_ );
         }
         catch( std::exception& ex ) {
            convertException<OMT1,MT2>( ex );
         }

         checkResults<OMT1,MT2>();

         try {
            initResults();
            dres_   += min( eval( olhs_ ), eval( orhs_ ) );
            odres_  += min( eval( olhs_ ), eval( orhs_ ) );
            sres_   += min( eval( olhs_ ), eval( orhs_ ) );
            osres_  += min( eval( olhs_ ), eval( orhs_ ) );
            refres_ += eval( ref_ );
         }
         catch( std::exception& ex ) {
            convertException<OMT1,OMT2>( ex );
         }

         checkResults<OMT1,OMT2>();
      }


      //=====================================================================================
      // Minimum with subtraction assignment with the given matrices
      //=====================================================================================

      // Minimum with subtraction assignment with the given matrices
      {
         test_  = "Minimum with subtraction assignment with the given matrices";
         error_ = "Failed subtraction assignment operation";

         try {
            initResults();
            dres_   -= min( lhs_, rhs_ );
            odres_  -= min( lhs_, rhs_ );
            sres_   -= min( lhs_, rhs_ );
            osres_  -= min( lhs_, rhs_ );
            refres_ -= ref_;
         }
         catch( std::exception& ex ) {
            convertException<MT1,MT2>( ex );
         }

         checkResults<MT1,MT2>();

         try {
            initResults();
            dres_   -= min( lhs_, orhs_ );
            odres_  -= min( lhs_, orhs_ );
            sres_   -= min( lhs_, orhs_ );
            osres_  -= min( lhs_, orhs_ );
            refres_ -= ref_;
         }
         catch( std::exception& ex ) {
            convertException<MT1,OMT2>( ex );
         }

         checkResults<MT1,OMT2>();

         try {
            initResults();
            dres_   -= min( olhs_, rhs_ );
            odres_  -= min( olhs_, rhs_ );
            sres_   -= min( olhs_, rhs_ );
            osres_  -= min( olhs_, rhs_ );
            refres_ -= ref_;
         }
         catch( std::exception& ex ) {
            convertException<OMT1,MT2>( ex );
         }

         checkResults<OMT1,MT2>();

         try {
            initResults();
            dres_   -= min( olhs_, orhs_ );
            odres_  -= min( olhs_, orhs_ );
            sres_   -= min( olhs_, orhs_ );
            osres_  -= min( olhs_, orhs_ );
            refres_ -= ref_;
         }
         catch( std::exception& ex ) {
            convertException<OMT1,OMT2>( ex );
         }

         checkResults<OMT1,OMT2>();
      }

      // Minimum with subtraction assignment with evaluated matrices
      {
         test_  = "Minimum with subtraction assignment with evaluated matrices";
         error_ = "Failed subtraction assignment operation";

         try {
            initResults();
            dres_   -= min( eval( lhs_ ), eval( rhs_ ) );
            odres_  -= min( eval( lhs_ ), eval( rhs_ ) );
            sres_   -= min( eval( lhs_ ), eval( rhs_ ) );
            osres_  -= min( eval( lhs_ ), eval( rhs_ ) );
            refres_ -= eval( ref_ );
         }
         catch( std::exception& ex ) {
            convertException<MT1,MT2>( ex );
         }

         checkResults<MT1,MT2>();

         try {
            initResults();
            dres_   -= min( eval( lhs_ ), eval( orhs_ ) );
            odres_  -= min( eval( lhs_ ), eval( orhs_ ) );
            sres_   -= min( eval( lhs_ ), eval( orhs_ ) );
            osres_  -= min( eval( lhs_ ), eval( orhs_ ) );
            refres_ -= eval( ref_ );
         }
         catch( std::exception& ex ) {
            convertException<MT1,OMT2>( ex );
         }

         checkResults<MT1,OMT2>();

         try {
            initResults();
            dres_   -= min( eval( olhs_ ), eval( rhs_ ) );
            odres_  -= min( eval( olhs_ ), eval( rhs_ ) );
            sres_   -= min( eval( olhs_ ), eval( rhs_ ) );
            osres_  -= min( eval( olhs_ ), eval( rhs_ ) );
            refres_ -= eval( ref_ );
         }
         catch( std::exception& ex ) {
            convertException<OMT1,MT2>( ex );
         }

         checkResults<OMT1,MT2>();

         try {
            initResults();
            dres_   -= min( eval( olhs_ ), eval( orhs_ ) );
            odres_  -= min( eval( olhs_ ), eval( orhs_ ) );
            sres_   -= min( eval( olhs_ ), eval( orhs_ ) );
            osres_  -= min( eval( olhs_ ), eval( orhs_ ) );
            refres_ -= eval( ref_ );
         }
         catch( std::exception& ex ) {
            convertException<OMT1,OMT2>( ex );
         }

         checkResults<OMT1,OMT2>();
      }


      //=====================================================================================
      // Minimum with Schur product assignment
      //=====================================================================================

      // Minimum with Schur product assignment with the given matrices
      {
         test_  = "Minimum with Schur product assignment with the given matrices";
         error_ = "Failed Schur product assignment operation";

         try {
            initResults();
            dres_   %= min( lhs_, rhs_ );
            odres_  %= min( lhs_, rhs_ );
            sres_   %= min( lhs_, rhs_ );
            osres_  %= min( lhs_, rhs_ );
            refres_ %= ref_;
         }
         catch( std::exception& ex ) {
            convertException<MT1,MT2>( ex );
         }

         checkResults<MT1,MT2>();

         try {
            initResults();
            dres_   %= min( lhs_, orhs_ );
            odres_  %= min( lhs_, orhs_ );
            sres_   %= min( lhs_, orhs_ );
            osres_  %= min( lhs_, orhs_ );
            refres_ %= ref_;
         }
         catch( std::exception& ex ) {
            convertException<MT1,OMT2>( ex );
         }

         checkResults<MT1,OMT2>();

         try {
            initResults();
            dres_   %= min( olhs_, rhs_ );
            odres_  %= min( olhs_, rhs_ );
            sres_   %= min( olhs_, rhs_ );
            osres_  %= min( olhs_, rhs_ );
            refres_ %= ref_;
         }
         catch( std::exception& ex ) {
            convertException<OMT1,MT2>( ex );
         }

         checkResults<OMT1,MT2>();

         try {
            initResults();
            dres_   %= min( olhs_, orhs_ );
            odres_  %= min( olhs_, orhs_ );
            sres_   %= min( olhs_, orhs_ );
            osres_  %= min( olhs_, orhs_ );
            refres_ %= ref_;
         }
         catch( std::exception& ex ) {
            convertException<OMT1,OMT2>( ex );
         }

         checkResults<OMT1,OMT2>();
      }

      // Minimum with Schur product assignment with evaluated matrices
      {
         test_  = "Minimum with Schur product assignment with evaluated matrices";
         error_ = "Failed Schur product assignment operation";

         try {
            initResults();
            dres_   %= min( eval( lhs_ ), eval( rhs_ ) );
            odres_  %= min( eval( lhs_ ), eval( rhs_ ) );
            sres_   %= min( eval( lhs_ ), eval( rhs_ ) );
            osres_  %= min( eval( lhs_ ), eval( rhs_ ) );
            refres_ %= eval( ref_ );
         }
         catch( std::exception& ex ) {
            convertException<MT1,MT2>( ex );
         }

         checkResults<MT1,MT2>();

         try {
            initResults();
            dres_   %= min( eval( lhs_ ), eval( orhs_ ) );
            odres_  %= min( eval( lhs_ ), eval( orhs_ ) );
            sres_   %= min( eval( lhs_ ), eval( orhs_ ) );
            osres_  %= min( eval( lhs_ ), eval( orhs_ ) );
            refres_ %= eval( ref_ );
         }
         catch( std::exception& ex ) {
            convertException<MT1,OMT2>( ex );
         }

         checkResults<MT1,OMT2>();

         try {
            initResults();
            dres_   %= min( eval( olhs_ ), eval( rhs_ ) );
            odres_  %= min( eval( olhs_ ), eval( rhs_ ) );
            sres_   %= min( eval( olhs_ ), eval( rhs_ ) );
            osres_  %= min( eval( olhs_ ), eval( rhs_ ) );
            refres_ %= eval( ref_ );
         }
         catch( std::exception& ex ) {
            convertException<OMT1,MT2>( ex );
         }

         checkResults<OMT1,MT2>();

         try {
            initResults();
            dres_   %= min( eval( olhs_ ), eval( orhs_ ) );
            odres_  %= min( eval( olhs_ ), eval( orhs_ ) );
            sres_   %= min( eval( olhs_ ), eval( orhs_ ) );
            osres_  %= min( eval( olhs_ ), eval( orhs_ ) );
            refres_ %= eval( ref_ );
         }
         catch( std::exception& ex ) {
            convertException<OMT1,OMT2>( ex );
         }

         checkResults<OMT1,OMT2>();
      }
   }
#endif
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Testing the negated dense matrix/dense matrix minimum operation.
//
// \return void
// \exception std::runtime_error Minimum error detected.
//
// This function tests the negated matrix minimum with plain assignment, addition assignment,
// subtraction assignment, and Schur product assignment. In case any error resulting from the
// minimum operation or the subsequent assignment is detected, a \a std::runtime_error exception
// is thrown.
*/
template< typename MT1    // Type of the left-hand side dense matrix
        , typename MT2 >  // Type of the right-hand side dense matrix
void OperationTest<MT1,MT2>::testNegatedOperation()
{
#if BLAZETEST_MATHTEST_TEST_NEGATED_OPERATION
   if( BLAZETEST_MATHTEST_TEST_NEGATED_OPERATION > 1 )
   {
      //=====================================================================================
      // Negated minimum
      //=====================================================================================

      // Negated minimum with the given matrices
      {
         test_  = "Negated minimum with the given matrices";
         error_ = "Failed minimum operation";

         try {
            initResults();
            dres_   = -min( lhs_, rhs_ );
            odres_  = -min( lhs_, rhs_ );
            sres_   = -min( lhs_, rhs_ );
            osres_  = -min( lhs_, rhs_ );
            refres_ = -ref_;
         }
         catch( std::exception& ex ) {
            convertException<MT1,MT2>( ex );
         }

         checkResults<MT1,MT2>();

         try {
            initResults();
            dres_   = -min( lhs_, orhs_ );
            odres_  = -min( lhs_, orhs_ );
            sres_   = -min( lhs_, orhs_ );
            osres_  = -min( lhs_, orhs_ );
            refres_ = -ref_;
         }
         catch( std::exception& ex ) {
            convertException<MT1,OMT2>( ex );
         }

         checkResults<MT1,OMT2>();

         try {
            initResults();
            dres_   = -min( olhs_, rhs_ );
            odres_  = -min( olhs_, rhs_ );
            sres_   = -min( olhs_, rhs_ );
            osres_  = -min( olhs_, rhs_ );
            refres_ = -ref_;
         }
         catch( std::exception& ex ) {
            convertException<OMT1,MT2>( ex );
         }

         checkResults<OMT1,MT2>();

         try {
            initResults();
            dres_   = -min( olhs_, orhs_ );
            odres_  = -min( olhs_, orhs_ );
            sres_   = -min( olhs_, orhs_ );
            osres_  = -min( olhs_, orhs_ );
            refres_ = -ref_;
         }
         catch( std::exception& ex ) {
            convertException<OMT1,OMT2>( ex );
         }

         checkResults<OMT1,OMT2>();
      }

      // Negated minimum with evaluated matrices
      {
         test_  = "Negated minimum with evaluated matrices";
         error_ = "Failed minimum operation";

         try {
            initResults();
            dres_   = -min( eval( lhs_ ), eval( rhs_ ) );
            odres_  = -min( eval( lhs_ ), eval( rhs_ ) );
            sres_   = -min( eval( lhs_ ), eval( rhs_ ) );
            osres_  = -min( eval( lhs_ ), eval( rhs_ ) );
            refres_ = -eval( ref_ );
         }
         catch( std::exception& ex ) {
            convertException<MT1,MT2>( ex );
         }

         checkResults<MT1,MT2>();

         try {
            initResults();
            dres_   = -min( eval( lhs_ ), eval( orhs_ ) );
            odres_  = -min( eval( lhs_ ), eval( orhs_ ) );
            sres_   = -min( eval( lhs_ ), eval( orhs_ ) );
            osres_  = -min( eval( lhs_ ), eval( orhs_ ) );
            refres_ = -eval( ref_ );
         }
         catch( std::exception& ex ) {
            convertException<MT1,OMT2>( ex );
         }

         checkResults<MT1,OMT2>();

         try {
            initResults();
            dres_   = -min( eval( olhs_ ), eval( rhs_ ) );
            odres_  = -min( eval( olhs_ ), eval( rhs_ ) );
            sres_   = -min( eval( olhs_ ), eval( rhs_ ) );
            osres_  = -min( eval( olhs_ ), eval( rhs_ ) );
            refres_ = -eval( ref_ );
         }
         catch( std::exception& ex ) {
            convertException<OMT1,MT2>( ex );
         }

         checkResults<OMT1,MT2>();

         try {
            initResults();
            dres_   = -min( eval( olhs_ ), eval( orhs_ ) );
            odres_  = -min( eval( olhs_ ), eval( orhs_ ) );
            sres_   = -min( eval( olhs_ ), eval( orhs_ ) );
            osres_  = -min( eval( olhs_ ), eval( orhs_ ) );
            refres_ = -eval( ref_ );
         }
         catch( std::exception& ex ) {
            convertException<OMT1,OMT2>( ex );
         }

         checkResults<OMT1,OMT2>();
      }


      //=====================================================================================
      // Negated minimum with addition assignment
      //=====================================================================================

      // Negated minimum with addition assignment with the given matrices
      {
         test_  = "Negated minimum with addition assignment with the given matrices";
         error_ = "Failed addition assignment operation";

         try {
            initResults();
            dres_   += -min( lhs_, rhs_ );
            odres_  += -min( lhs_, rhs_ );
            sres_   += -min( lhs_, rhs_ );
            osres_  += -min( lhs_, rhs_ );
            refres_ += -ref_;
         }
         catch( std::exception& ex ) {
            convertException<MT1,MT2>( ex );
         }

         checkResults<MT1,MT2>();

         try {
            initResults();
            dres_   += -min( lhs_, orhs_ );
            odres_  += -min( lhs_, orhs_ );
            sres_   += -min( lhs_, orhs_ );
            osres_  += -min( lhs_, orhs_ );
            refres_ += -ref_;
         }
         catch( std::exception& ex ) {
            convertException<MT1,OMT2>( ex );
         }

         checkResults<MT1,OMT2>();

         try {
            initResults();
            dres_   += -min( olhs_, rhs_ );
            odres_  += -min( olhs_, rhs_ );
            sres_   += -min( olhs_, rhs_ );
            osres_  += -min( olhs_, rhs_ );
            refres_ += -ref_;
         }
         catch( std::exception& ex ) {
            convertException<OMT1,MT2>( ex );
         }

         checkResults<OMT1,MT2>();

         try {
            initResults();
            dres_   += -min( olhs_, orhs_ );
            odres_  += -min( olhs_, orhs_ );
            sres_   += -min( olhs_, orhs_ );
            osres_  += -min( olhs_, orhs_ );
            refres_ += -ref_;
         }
         catch( std::exception& ex ) {
            convertException<OMT1,OMT2>( ex );
         }

         checkResults<OMT1,OMT2>();
      }

      // Negated minimum with addition assignment with the given matrices
      {
         test_  = "Negated minimum with addition assignment with evaluated matrices";
         error_ = "Failed addition assignment operation";

         try {
            initResults();
            dres_   += -min( eval( lhs_ ), eval( rhs_ ) );
            odres_  += -min( eval( lhs_ ), eval( rhs_ ) );
            sres_   += -min( eval( lhs_ ), eval( rhs_ ) );
            osres_  += -min( eval( lhs_ ), eval( rhs_ ) );
            refres_ += -eval( ref_ );
         }
         catch( std::exception& ex ) {
            convertException<MT1,MT2>( ex );
         }

         checkResults<MT1,MT2>();

         try {
            initResults();
            dres_   += -min( eval( lhs_ ), eval( orhs_ ) );
            odres_  += -min( eval( lhs_ ), eval( orhs_ ) );
            sres_   += -min( eval( lhs_ ), eval( orhs_ ) );
            osres_  += -min( eval( lhs_ ), eval( orhs_ ) );
            refres_ += -eval( ref_ );
         }
         catch( std::exception& ex ) {
            convertException<MT1,OMT2>( ex );
         }

         checkResults<MT1,OMT2>();

         try {
            initResults();
            dres_   += -min( eval( olhs_ ), eval( rhs_ ) );
            odres_  += -min( eval( olhs_ ), eval( rhs_ ) );
            sres_   += -min( eval( olhs_ ), eval( rhs_ ) );
            osres_  += -min( eval( olhs_ ), eval( rhs_ ) );
            refres_ += -eval( ref_ );
         }
         catch( std::exception& ex ) {
            convertException<OMT1,MT2>( ex );
         }

         checkResults<OMT1,MT2>();

         try {
            initResults();
            dres_   += -min( eval( olhs_ ), eval( orhs_ ) );
            odres_  += -min( eval( olhs_ ), eval( orhs_ ) );
            sres_   += -min( eval( olhs_ ), eval( orhs_ ) );
            osres_  += -min( eval( olhs_ ), eval( orhs_ ) );
            refres_ += -eval( ref_ );
         }
         catch( std::exception& ex ) {
            convertException<OMT1,OMT2>( ex );
         }

         checkResults<OMT1,OMT2>();
      }


      //=====================================================================================
      // Negated minimum with subtraction assignment
      //=====================================================================================

      // Negated minimum with subtraction assignment with the given matrices
      {
         test_  = "Negated minimum with subtraction assignment with the given matrices";
         error_ = "Failed subtraction assignment operation";

         try {
            initResults();
            dres_   -= -min( lhs_, rhs_ );
            odres_  -= -min( lhs_, rhs_ );
            sres_   -= -min( lhs_, rhs_ );
            osres_  -= -min( lhs_, rhs_ );
            refres_ -= -ref_;
         }
         catch( std::exception& ex ) {
            convertException<MT1,MT2>( ex );
         }

         checkResults<MT1,MT2>();

         try {
            initResults();
            dres_   -= -min( lhs_, orhs_ );
            odres_  -= -min( lhs_, orhs_ );
            sres_   -= -min( lhs_, orhs_ );
            osres_  -= -min( lhs_, orhs_ );
            refres_ -= -ref_;
         }
         catch( std::exception& ex ) {
            convertException<MT1,OMT2>( ex );
         }

         checkResults<MT1,OMT2>();

         try {
            initResults();
            dres_   -= -min( olhs_, rhs_ );
            odres_  -= -min( olhs_, rhs_ );
            sres_   -= -min( olhs_, rhs_ );
            osres_  -= -min( olhs_, rhs_ );
            refres_ -= -ref_;
         }
         catch( std::exception& ex ) {
            convertException<OMT1,MT2>( ex );
         }

         checkResults<OMT1,MT2>();

         try {
            initResults();
            dres_   -= -min( olhs_, orhs_ );
            odres_  -= -min( olhs_, orhs_ );
            sres_   -= -min( olhs_, orhs_ );
            osres_  -= -min( olhs_, orhs_ );
            refres_ -= -ref_;
         }
         catch( std::exception& ex ) {
            convertException<OMT1,OMT2>( ex );
         }

         checkResults<OMT1,OMT2>();
      }

      // Negated minimum with subtraction assignment with evaluated matrices
      {
         test_  = "Negated minimum with subtraction assignment with evaluated matrices";
         error_ = "Failed subtraction assignment operation";

         try {
            initResults();
            dres_   -= -min( eval( lhs_ ), eval( rhs_ ) );
            odres_  -= -min( eval( lhs_ ), eval( rhs_ ) );
            sres_   -= -min( eval( lhs_ ), eval( rhs_ ) );
            osres_  -= -min( eval( lhs_ ), eval( rhs_ ) );
            refres_ -= -eval( ref_ );
         }
         catch( std::exception& ex ) {
            convertException<MT1,MT2>( ex );
         }

         checkResults<MT1,MT2>();

         try {
            initResults();
            dres_   -= -min( eval( lhs_ ), eval( orhs_ ) );
            odres_  -= -min( eval( lhs_ ), eval( orhs_ ) );
            sres_   -= -min( eval( lhs_ ), eval( orhs_ ) );
            osres_  -= -min( eval( lhs_ ), eval( orhs_ ) );
            refres_ -= -eval( ref_ );
         }
         catch( std::exception& ex ) {
            convertException<MT1,OMT2>( ex );
         }

         checkResults<MT1,OMT2>();

         try {
            initResults();
            dres_   -= -min( eval( olhs_ ), eval( rhs_ ) );
            odres_  -= -min( eval( olhs_ ), eval( rhs_ ) );
            sres_   -= -min( eval( olhs_ ), eval( rhs_ ) );
            osres_  -= -min( eval( olhs_ ), eval( rhs_ ) );
            refres_ -= -eval( ref_ );
         }
         catch( std::exception& ex ) {
            convertException<OMT1,MT2>( ex );
         }

         checkResults<OMT1,MT2>();

         try {
            initResults();
            dres_   -= -min( eval( olhs_ ), eval( orhs_ ) );
            odres_  -= -min( eval( olhs_ ), eval( orhs_ ) );
            sres_   -= -min( eval( olhs_ ), eval( orhs_ ) );
            osres_  -= -min( eval( olhs_ ), eval( orhs_ ) );
            refres_ -= -eval( ref_ );
         }
         catch( std::exception& ex ) {
            convertException<OMT1,OMT2>( ex );
         }

         checkResults<OMT1,OMT2>();
      }


      //=====================================================================================
      // Negated minimum with Schur product assignment
      //=====================================================================================

      // Negated minimum with Schur product assignment with the given matrices
      {
         test_  = "Negated minimum with Schur product assignment with the given matrices";
         error_ = "Failed Schur product assignment operation";

         try {
            initResults();
            dres_   %= -min( lhs_, rhs_ );
            odres_  %= -min( lhs_, rhs_ );
            sres_   %= -min( lhs_, rhs_ );
            osres_  %= -min( lhs_, rhs_ );
            refres_ %= -ref_;
         }
         catch( std::exception& ex ) {
            convertException<MT1,MT2>( ex );
         }

         checkResults<MT1,MT2>();

         try {
            initResults();
            dres_   %= -min( lhs_, orhs_ );
            odres_  %= -min( lhs_, orhs_ );
            sres_   %= -min( lhs_, orhs_ );
            osres_  %= -min( lhs_, orhs_ );
            refres_ %= -ref_;
         }
         catch( std::exception& ex ) {
            convertException<MT1,OMT2>( ex );
         }

         checkResults<MT1,OMT2>();

         try {
            initResults();
            dres_   %= -min( olhs_, rhs_ );
            odres_  %= -min( olhs_, rhs_ );
            sres_   %= -min( olhs_, rhs_ );
            osres_  %= -min( olhs_, rhs_ );
            refres_ %= -ref_;
         }
         catch( std::exception& ex ) {
            convertException<OMT1,MT2>( ex );
         }

         checkResults<OMT1,MT2>();

         try {
            initResults();
            dres_   %= -min( olhs_, orhs_ );
            odres_  %= -min( olhs_, orhs_ );
            sres_   %= -min( olhs_, orhs_ );
            osres_  %= -min( olhs_, orhs_ );
            refres_ %= -ref_;
         }
         catch( std::exception& ex ) {
            convertException<OMT1,OMT2>( ex );
         }

         checkResults<OMT1,OMT2>();
      }

      // Negated minimum with Schur product assignment with the given matrices
      {
         test_  = "Negated minimum with Schur product assignment with evaluated matrices";
         error_ = "Failed Schur product assignment operation";

         try {
            initResults();
            dres_   %= -min( eval( lhs_ ), eval( rhs_ ) );
            odres_  %= -min( eval( lhs_ ), eval( rhs_ ) );
            sres_   %= -min( eval( lhs_ ), eval( rhs_ ) );
            osres_  %= -min( eval( lhs_ ), eval( rhs_ ) );
            refres_ %= -eval( ref_ );
         }
         catch( std::exception& ex ) {
            convertException<MT1,MT2>( ex );
         }

         checkResults<MT1,MT2>();

         try {
            initResults();
            dres_   %= -min( eval( lhs_ ), eval( orhs_ ) );
            odres_  %= -min( eval( lhs_ ), eval( orhs_ ) );
            sres_   %= -min( eval( lhs_ ), eval( orhs_ ) );
            osres_  %= -min( eval( lhs_ ), eval( orhs_ ) );
            refres_ %= -eval( ref_ );
         }
         catch( std::exception& ex ) {
            convertException<MT1,OMT2>( ex );
         }

         checkResults<MT1,OMT2>();

         try {
            initResults();
            dres_   %= -min( eval( olhs_ ), eval( rhs_ ) );
            odres_  %= -min( eval( olhs_ ), eval( rhs_ ) );
            sres_   %= -min( eval( olhs_ ), eval( rhs_ ) );
            osres_  %= -min( eval( olhs_ ), eval( rhs_ ) );
            refres_ %= -eval( ref_ );
         }
         catch( std::exception& ex ) {
            convertException<OMT1,MT2>( ex );
         }

         checkResults<OMT1,MT2>();

         try {
            initResults();
            dres_   %= -min( eval( olhs_ ), eval( orhs_ ) );
            odres_  %= -min( eval( olhs_ ), eval( orhs_ ) );
            sres_   %= -min( eval( olhs_ ), eval( orhs_ ) );
            osres_  %= -min( eval( olhs_ ), eval( orhs_ ) );
            refres_ %= -eval( ref_ );
         }
         catch( std::exception& ex ) {
            convertException<OMT1,OMT2>( ex );
         }

         checkResults<OMT1,OMT2>();
      }
   }
#endif
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Testing the scaled dense matrix/dense matrix minimum operation.
//
// \param scalar The scalar value.
// \return void
// \exception std::runtime_error Minimum error detected.
//
// This function tests the scaled matrix minimum with plain assignment, addition assignment,
// subtraction assignment, and Schur product assignment. In case any error resulting from the
// minimum operation or the subsequent assignment is detected, a \a std::runtime_error exception
// is thrown.
*/
template< typename MT1    // Type of the left-hand side dense matrix
        , typename MT2 >  // Type of the right-hand side dense matrix
template< typename T >    // Type of the scalar
void OperationTest<MT1,MT2>::testScaledOperation( T scalar )
{
   BLAZE_CONSTRAINT_MUST_BE_NUMERIC_TYPE( T );

   if( scalar == T(0) )
      throw std::invalid_argument( "Invalid scalar parameter" );


#if BLAZETEST_MATHTEST_TEST_SCALED_OPERATION
   if( BLAZETEST_MATHTEST_TEST_SCALED_OPERATION > 1 )
   {
      //=====================================================================================
      // Self-scaling (M*=s)
      //=====================================================================================

      // Self-scaling (M*=s)
      {
         test_ = "Self-scaling (M*=s)";

         try {
            dres_   = min( lhs_, rhs_ );
            odres_  = dres_;
            sres_   = dres_;
            osres_  = dres_;
            refres_ = dres_;

            dres_   *= scalar;
            odres_  *= scalar;
            sres_   *= scalar;
            osres_  *= scalar;
            refres_ *= scalar;
         }
         catch( std::exception& ex ) {
            std::ostringstream oss;
            oss << " Test : " << test_ << "\n"
                << " Error: Failed self-scaling operation\n"
                << " Details:\n"
                << "   Random seed = " << blaze::getSeed() << "\n"
                << "   Scalar = " << scalar << "\n"
                << "   Error message: " << ex.what() << "\n";
            throw std::runtime_error( oss.str() );
         }

         checkResults<MT1,MT2>();
      }


      //=====================================================================================
      // Self-scaling (M=M*s)
      //=====================================================================================

      // Self-scaling (M=M*s)
      {
         test_ = "Self-scaling (M=M*s)";

         try {
            dres_   = min( lhs_, rhs_ );
            odres_  = dres_;
            sres_   = dres_;
            osres_  = dres_;
            refres_ = dres_;

            dres_   = dres_   * scalar;
            odres_  = odres_  * scalar;
            sres_   = sres_   * scalar;
            osres_  = osres_  * scalar;
            refres_ = refres_ * scalar;
         }
         catch( std::exception& ex ) {
            std::ostringstream oss;
            oss << " Test : " << test_ << "\n"
                << " Error: Failed self-scaling operation\n"
                << " Details:\n"
                << "   Random seed = " << blaze::getSeed() << "\n"
                << "   Scalar = " << scalar << "\n"
                << "   Error message: " << ex.what() << "\n";
            throw std::runtime_error( oss.str() );
         }

         checkResults<MT1,MT2>();
      }


      //=====================================================================================
      // Self-scaling (M=s*M)
      //=====================================================================================

      // Self-scaling (M=s*M)
      {
         test_ = "Self-scaling (M=s*M)";

         try {
            dres_   = min( lhs_, rhs_ );
            odres_  = dres_;
            sres_   = dres_;
            osres_  = dres_;
            refres_ = dres_;

            dres_   = scalar * dres_;
            odres_  = scalar * odres_;
            sres_   = scalar * sres_;
            osres_  = scalar * osres_;
            refres_ = scalar * refres_;
         }
         catch( std::exception& ex ) {
            std::ostringstream oss;
            oss << " Test : " << test_ << "\n"
                << " Error: Failed self-scaling operation\n"
                << " Details:\n"
                << "   Random seed = " << blaze::getSeed() << "\n"
                << "   Scalar = " << scalar << "\n"
                << "   Error message: " << ex.what() << "\n";
            throw std::runtime_error( oss.str() );
         }

         checkResults<MT1,MT2>();
      }


      //=====================================================================================
      // Self-scaling (M/=s)
      //=====================================================================================

      // Self-scaling (M/=s)
      {
         test_ = "Self-scaling (M/=s)";

         try {
            dres_   = min( lhs_, rhs_ );
            odres_  = dres_;
            sres_   = dres_;
            osres_  = dres_;
            refres_ = dres_;

            dres_   /= scalar;
            odres_  /= scalar;
            sres_   /= scalar;
            osres_  /= scalar;
            refres_ /= scalar;
         }
         catch( std::exception& ex ) {
            std::ostringstream oss;
            oss << " Test : " << test_ << "\n"
                << " Error: Failed self-scaling operation\n"
                << " Details:\n"
                << "   Random seed = " << blaze::getSeed() << "\n"
                << "   Scalar = " << scalar << "\n"
                << "   Error message: " << ex.what() << "\n";
            throw std::runtime_error( oss.str() );
         }

         checkResults<MT1,MT2>();
      }


      //=====================================================================================
      // Self-scaling (M=M/s)
      //=====================================================================================

      // Self-scaling (M=M/s)
      {
         test_ = "Self-scaling (M=M/s)";

         try {
            dres_   = min( lhs_, rhs_ );
            odres_  = dres_;
            sres_   = dres_;
            osres_  = dres_;
            refres_ = dres_;

            dres_   = dres_   / scalar;
            odres_  = odres_  / scalar;
            sres_   = sres_   / scalar;
            osres_  = osres_  / scalar;
            refres_ = refres_ / scalar;
         }
         catch( std::exception& ex ) {
            std::ostringstream oss;
            oss << " Test : " << test_ << "\n"
                << " Error: Failed self-scaling operation\n"
                << " Details:\n"
                << "   Random seed = " << blaze::getSeed() << "\n"
                << "   Scalar = " << scalar << "\n"
                << "   Error message: " << ex.what() << "\n";
            throw std::runtime_error( oss.str() );
         }

         checkResults<MT1,MT2>();
      }


      //=====================================================================================
      // Scaled minimum (s*OP)
      //=====================================================================================

      // Scaled minimum with the given matrices
      {
         test_  = "Scaled minimum with the given matrices (s*OP)";
         error_ = "Failed minimum operation";

         try {
            initResults();
            dres_   = scalar * min( lhs_, rhs_ );
            odres_  = scalar * min( lhs_, rhs_ );
            sres_   = scalar * min( lhs_, rhs_ );
            osres_  = scalar * min( lhs_, rhs_ );
            refres_ = scalar * ref_;
         }
         catch( std::exception& ex ) {
            convertException<MT1,MT2>( ex );
         }

         checkResults<MT1,MT2>();

         try {
            initResults();
            dres_   = scalar * min( lhs_, orhs_ );
            odres_  = scalar * min( lhs_, orhs_ );
            sres_   = scalar * min( lhs_, orhs_ );
            osres_  = scalar * min( lhs_, orhs_ );
            refres_ = scalar * ref_;
         }
         catch( std::exception& ex ) {
            convertException<MT1,OMT2>( ex );
         }

         checkResults<MT1,OMT2>();

         try {
            initResults();
            dres_   = scalar * min( olhs_, rhs_ );
            odres_  = scalar * min( olhs_, rhs_ );
            sres_   = scalar * min( olhs_, rhs_ );
            osres_  = scalar * min( olhs_, rhs_ );
            refres_ = scalar * ref_;
         }
         catch( std::exception& ex ) {
            convertException<OMT1,MT2>( ex );
         }

         checkResults<OMT1,MT2>();

         try {
            initResults();
            dres_   = scalar * min( olhs_, orhs_ );
            odres_  = scalar * min( olhs_, orhs_ );
            sres_   = scalar * min( olhs_, orhs_ );
            osres_  = scalar * min( olhs_, orhs_ );
            refres_ = scalar * ref_;
         }
         catch( std::exception& ex ) {
            convertException<OMT1,OMT2>( ex );
         }

         checkResults<OMT1,OMT2>();
      }

      // Scaled minimum with evaluated matrices
      {
         test_  = "Scaled minimum with evaluated matrices (s*OP)";
         error_ = "Failed minimum operation";

         try {
            initResults();
            dres_   = scalar * min( eval( lhs_ ), eval( rhs_ ) );
            odres_  = scalar * min( eval( lhs_ ), eval( rhs_ ) );
            sres_   = scalar * min( eval( lhs_ ), eval( rhs_ ) );
            osres_  = scalar * min( eval( lhs_ ), eval( rhs_ ) );
            refres_ = scalar * eval( ref_ );
         }
         catch( std::exception& ex ) {
            convertException<MT1,MT2>( ex );
         }

         checkResults<MT1,MT2>();

         try {
            initResults();
            dres_   = scalar * min( eval( lhs_ ), eval( orhs_ ) );
            odres_  = scalar * min( eval( lhs_ ), eval( orhs_ ) );
            sres_   = scalar * min( eval( lhs_ ), eval( orhs_ ) );
            osres_  = scalar * min( eval( lhs_ ), eval( orhs_ ) );
            refres_ = scalar * eval( ref_ );
         }
         catch( std::exception& ex ) {
            convertException<MT1,OMT2>( ex );
         }

         checkResults<MT1,OMT2>();

         try {
            initResults();
            dres_   = scalar * min( eval( olhs_ ), eval( rhs_ ) );
            odres_  = scalar * min( eval( olhs_ ), eval( rhs_ ) );
            sres_   = scalar * min( eval( olhs_ ), eval( rhs_ ) );
            osres_  = scalar * min( eval( olhs_ ), eval( rhs_ ) );
            refres_ = scalar * eval( ref_ );
         }
         catch( std::exception& ex ) {
            convertException<OMT1,MT2>( ex );
         }

         checkResults<OMT1,MT2>();

         try {
            initResults();
            dres_   = scalar * min( eval( olhs_ ), eval( orhs_ ) );
            odres_  = scalar * min( eval( olhs_ ), eval( orhs_ ) );
            sres_   = scalar * min( eval( olhs_ ), eval( orhs_ ) );
            osres_  = scalar * min( eval( olhs_ ), eval( orhs_ ) );
            refres_ = scalar * eval( ref_ );
         }
         catch( std::exception& ex ) {
            convertException<OMT1,OMT2>( ex );
         }

         checkResults<OMT1,OMT2>();
      }


      //=====================================================================================
      // Scaled minimum (OP*s)
      //=====================================================================================

      // Scaled minimum with the given matrices
      {
         test_  = "Scaled minimum with the given matrices (OP*s)";
         error_ = "Failed minimum operation";

         try {
            initResults();
            dres_   = min( lhs_, rhs_ ) * scalar;
            odres_  = min( lhs_, rhs_ ) * scalar;
            sres_   = min( lhs_, rhs_ ) * scalar;
            osres_  = min( lhs_, rhs_ ) * scalar;
            refres_ = ref_ * scalar;
         }
         catch( std::exception& ex ) {
            convertException<MT1,MT2>( ex );
         }

         checkResults<MT1,MT2>();

         try {
            initResults();
            dres_   = min( lhs_, orhs_ ) * scalar;
            odres_  = min( lhs_, orhs_ ) * scalar;
            sres_   = min( lhs_, orhs_ ) * scalar;
            osres_  = min( lhs_, orhs_ ) * scalar;
            refres_ = ref_ * scalar;
         }
         catch( std::exception& ex ) {
            convertException<MT1,OMT2>( ex );
         }

         checkResults<MT1,OMT2>();

         try {
            initResults();
            dres_   = min( olhs_, rhs_ ) * scalar;
            odres_  = min( olhs_, rhs_ ) * scalar;
            sres_   = min( olhs_, rhs_ ) * scalar;
            osres_  = min( olhs_, rhs_ ) * scalar;
            refres_ = ref_ * scalar;
         }
         catch( std::exception& ex ) {
            convertException<OMT1,MT2>( ex );
         }

         checkResults<OMT1,MT2>();

         try {
            initResults();
            dres_   = min( olhs_, orhs_ ) * scalar;
            odres_  = min( olhs_, orhs_ ) * scalar;
            sres_   = min( olhs_, orhs_ ) * scalar;
            osres_  = min( olhs_, orhs_ ) * scalar;
            refres_ = ref_ * scalar;
         }
         catch( std::exception& ex ) {
            convertException<OMT1,OMT2>( ex );
         }

         checkResults<OMT1,OMT2>();
      }

      // Scaled minimum with evaluated matrices
      {
         test_  = "Scaled minimum with evaluated matrices (OP*s)";
         error_ = "Failed minimum operation";

         try {
            initResults();
            dres_   = min( eval( lhs_ ), eval( rhs_ ) ) * scalar;
            odres_  = min( eval( lhs_ ), eval( rhs_ ) ) * scalar;
            sres_   = min( eval( lhs_ ), eval( rhs_ ) ) * scalar;
            osres_  = min( eval( lhs_ ), eval( rhs_ ) ) * scalar;
            refres_ = eval( ref_ ) * scalar;
         }
         catch( std::exception& ex ) {
            convertException<MT1,MT2>( ex );
         }

         checkResults<MT1,MT2>();

         try {
            initResults();
            dres_   = min( eval( lhs_ ), eval( orhs_ ) ) * scalar;
            odres_  = min( eval( lhs_ ), eval( orhs_ ) ) * scalar;
            sres_   = min( eval( lhs_ ), eval( orhs_ ) ) * scalar;
            osres_  = min( eval( lhs_ ), eval( orhs_ ) ) * scalar;
            refres_ = eval( ref_ ) * scalar;
         }
         catch( std::exception& ex ) {
            convertException<MT1,OMT2>( ex );
         }

         checkResults<MT1,OMT2>();

         try {
            initResults();
            dres_   = min( eval( olhs_ ), eval( rhs_ ) ) * scalar;
            odres_  = min( eval( olhs_ ), eval( rhs_ ) ) * scalar;
            sres_   = min( eval( olhs_ ), eval( rhs_ ) ) * scalar;
            osres_  = min( eval( olhs_ ), eval( rhs_ ) ) * scalar;
            refres_ = eval( ref_ ) * scalar;
         }
         catch( std::exception& ex ) {
            convertException<OMT1,MT2>( ex );
         }

         checkResults<OMT1,MT2>();

         try {
            initResults();
            dres_   = min( eval( olhs_ ), eval( orhs_ ) ) * scalar;
            odres_  = min( eval( olhs_ ), eval( orhs_ ) ) * scalar;
            sres_   = min( eval( olhs_ ), eval( orhs_ ) ) * scalar;
            osres_  = min( eval( olhs_ ), eval( orhs_ ) ) * scalar;
            refres_ = eval( ref_ ) * scalar;
         }
         catch( std::exception& ex ) {
            convertException<OMT1,OMT2>( ex );
         }

         checkResults<OMT1,OMT2>();
      }


      //=====================================================================================
      // Scaled minimum (OP/s)
      //=====================================================================================

      // Scaled minimum with the given matrices
      {
         test_  = "Scaled minimum with the given matrices (OP/s)";
         error_ = "Failed minimum operation";

         try {
            initResults();
            dres_   = min( lhs_, rhs_ ) / scalar;
            odres_  = min( lhs_, rhs_ ) / scalar;
            sres_   = min( lhs_, rhs_ ) / scalar;
            osres_  = min( lhs_, rhs_ ) / scalar;
            refres_ = ref_ / scalar;
         }
         catch( std::exception& ex ) {
            convertException<MT1,MT2>( ex );
         }

         checkResults<MT1,MT2>();

         try {
            initResults();
            dres_   = min( lhs_, orhs_ ) / scalar;
            odres_  = min( lhs_, orhs_ ) / scalar;
            sres_   = min( lhs_, orhs_ ) / scalar;
            osres_  = min( lhs_, orhs_ ) / scalar;
            refres_ = ref_ / scalar;
         }
         catch( std::exception& ex ) {
            convertException<MT1,OMT2>( ex );
         }

         checkResults<MT1,OMT2>();

         try {
            initResults();
            dres_   = min( olhs_, rhs_ ) / scalar;
            odres_  = min( olhs_, rhs_ ) / scalar;
            sres_   = min( olhs_, rhs_ ) / scalar;
            osres_  = min( olhs_, rhs_ ) / scalar;
            refres_ = ref_ / scalar;
         }
         catch( std::exception& ex ) {
            convertException<OMT1,MT2>( ex );
         }

         checkResults<OMT1,MT2>();

         try {
            initResults();
            dres_   = min( olhs_, orhs_ ) / scalar;
            odres_  = min( olhs_, orhs_ ) / scalar;
            sres_   = min( olhs_, orhs_ ) / scalar;
            osres_  = min( olhs_, orhs_ ) / scalar;
            refres_ = ref_ / scalar;
         }
         catch( std::exception& ex ) {
            convertException<OMT1,OMT2>( ex );
         }

         checkResults<OMT1,OMT2>();
      }

      // Scaled minimum with evaluated matrices
      {
         test_  = "Scaled minimum with evaluated matrices (OP/s)";
         error_ = "Failed minimum operation";

         try {
            initResults();
            dres_   = min( eval( lhs_ ), eval( rhs_ ) ) / scalar;
            odres_  = min( eval( lhs_ ), eval( rhs_ ) ) / scalar;
            sres_   = min( eval( lhs_ ), eval( rhs_ ) ) / scalar;
            osres_  = min( eval( lhs_ ), eval( rhs_ ) ) / scalar;
            refres_ = eval( ref_ ) / scalar;
         }
         catch( std::exception& ex ) {
            convertException<MT1,MT2>( ex );
         }

         checkResults<MT1,MT2>();

         try {
            initResults();
            dres_   = min( eval( lhs_ ), eval( orhs_ ) ) / scalar;
            odres_  = min( eval( lhs_ ), eval( orhs_ ) ) / scalar;
            sres_   = min( eval( lhs_ ), eval( orhs_ ) ) / scalar;
            osres_  = min( eval( lhs_ ), eval( orhs_ ) ) / scalar;
            refres_ = eval( ref_ ) / scalar;
         }
         catch( std::exception& ex ) {
            convertException<MT1,OMT2>( ex );
         }

         checkResults<MT1,OMT2>();

         try {
            initResults();
            dres_   = min( eval( olhs_ ), eval( rhs_ ) ) / scalar;
            odres_  = min( eval( olhs_ ), eval( rhs_ ) ) / scalar;
            sres_   = min( eval( olhs_ ), eval( rhs_ ) ) / scalar;
            osres_  = min( eval( olhs_ ), eval( rhs_ ) ) / scalar;
            refres_ = eval( ref_ ) / scalar;
         }
         catch( std::exception& ex ) {
            convertException<OMT1,MT2>( ex );
         }

         checkResults<OMT1,MT2>();

         try {
            initResults();
            dres_   = min( eval( olhs_ ), eval( orhs_ ) ) / scalar;
            odres_  = min( eval( olhs_ ), eval( orhs_ ) ) / scalar;
            sres_   = min( eval( olhs_ ), eval( orhs_ ) ) / scalar;
            osres_  = min( eval( olhs_ ), eval( orhs_ ) ) / scalar;
            refres_ = eval( ref_ ) / scalar;
         }
         catch( std::exception& ex ) {
            convertException<OMT1,OMT2>( ex );
         }

         checkResults<OMT1,OMT2>();
      }


      //=====================================================================================
      // Scaled minimum with addition assignment (s*OP)
      //=====================================================================================

      // Scaled minimum with addition assignment with the given matrices
      {
         test_  = "Scaled minimum with addition assignment with the given matrices (s*OP)";
         error_ = "Failed addition assignment operation";

         try {
            initResults();
            dres_   += scalar * min( lhs_, rhs_ );
            odres_  += scalar * min( lhs_, rhs_ );
            sres_   += scalar * min( lhs_, rhs_ );
            osres_  += scalar * min( lhs_, rhs_ );
            refres_ += scalar * ref_;
         }
         catch( std::exception& ex ) {
            convertException<MT1,MT2>( ex );
         }

         checkResults<MT1,MT2>();

         try {
            initResults();
            dres_   += scalar * min( lhs_, orhs_ );
            odres_  += scalar * min( lhs_, orhs_ );
            sres_   += scalar * min( lhs_, orhs_ );
            osres_  += scalar * min( lhs_, orhs_ );
            refres_ += scalar * ref_;
         }
         catch( std::exception& ex ) {
            convertException<MT1,OMT2>( ex );
         }

         checkResults<MT1,OMT2>();

         try {
            initResults();
            dres_   += scalar * min( olhs_, rhs_ );
            odres_  += scalar * min( olhs_, rhs_ );
            sres_   += scalar * min( olhs_, rhs_ );
            osres_  += scalar * min( olhs_, rhs_ );
            refres_ += scalar * ref_;
         }
         catch( std::exception& ex ) {
            convertException<OMT1,MT2>( ex );
         }

         checkResults<OMT1,MT2>();

         try {
            initResults();
            dres_   += scalar * min( olhs_, orhs_ );
            odres_  += scalar * min( olhs_, orhs_ );
            sres_   += scalar * min( olhs_, orhs_ );
            osres_  += scalar * min( olhs_, orhs_ );
            refres_ += scalar * ref_;
         }
         catch( std::exception& ex ) {
            convertException<OMT1,OMT2>( ex );
         }

         checkResults<OMT1,OMT2>();
      }

      // Scaled minimum with addition assignment with evaluated matrices
      {
         test_  = "Scaled minimum with addition assignment with evaluated matrices (s*OP)";
         error_ = "Failed addition assignment operation";

         try {
            initResults();
            dres_   += scalar * min( eval( lhs_ ), eval( rhs_ ) );
            odres_  += scalar * min( eval( lhs_ ), eval( rhs_ ) );
            sres_   += scalar * min( eval( lhs_ ), eval( rhs_ ) );
            osres_  += scalar * min( eval( lhs_ ), eval( rhs_ ) );
            refres_ += scalar * eval( ref_ );
         }
         catch( std::exception& ex ) {
            convertException<MT1,MT2>( ex );
         }

         checkResults<MT1,MT2>();

         try {
            initResults();
            dres_   += scalar * min( eval( lhs_ ), eval( orhs_ ) );
            odres_  += scalar * min( eval( lhs_ ), eval( orhs_ ) );
            sres_   += scalar * min( eval( lhs_ ), eval( orhs_ ) );
            osres_  += scalar * min( eval( lhs_ ), eval( orhs_ ) );
            refres_ += scalar * eval( ref_ );
         }
         catch( std::exception& ex ) {
            convertException<MT1,OMT2>( ex );
         }

         checkResults<MT1,OMT2>();

         try {
            initResults();
            dres_   += scalar * min( eval( olhs_ ), eval( rhs_ ) );
            odres_  += scalar * min( eval( olhs_ ), eval( rhs_ ) );
            sres_   += scalar * min( eval( olhs_ ), eval( rhs_ ) );
            osres_  += scalar * min( eval( olhs_ ), eval( rhs_ ) );
            refres_ += scalar * eval( ref_ );
         }
         catch( std::exception& ex ) {
            convertException<OMT1,MT2>( ex );
         }

         checkResults<OMT1,MT2>();

         try {
            initResults();
            dres_   += scalar * min( eval( olhs_ ), eval( orhs_ ) );
            odres_  += scalar * min( eval( olhs_ ), eval( orhs_ ) );
            sres_   += scalar * min( eval( olhs_ ), eval( orhs_ ) );
            osres_  += scalar * min( eval( olhs_ ), eval( orhs_ ) );
            refres_ += scalar * eval( ref_ );
         }
         catch( std::exception& ex ) {
            convertException<OMT1,OMT2>( ex );
         }

         checkResults<OMT1,OMT2>();
      }


      //=====================================================================================
      // Scaled minimum with addition assignment (OP*s)
      //=====================================================================================

      // Scaled minimum with addition assignment with the given matrices
      {
         test_  = "Scaled minimum with addition assignment with the given matrices (OP*s)";
         error_ = "Failed addition assignment operation";

         try {
            initResults();
            dres_   += min( lhs_, rhs_ ) * scalar;
            odres_  += min( lhs_, rhs_ ) * scalar;
            sres_   += min( lhs_, rhs_ ) * scalar;
            osres_  += min( lhs_, rhs_ ) * scalar;
            refres_ += ref_ * scalar;
         }
         catch( std::exception& ex ) {
            convertException<MT1,MT2>( ex );
         }

         checkResults<MT1,MT2>();

         try {
            initResults();
            dres_   += min( lhs_, orhs_ ) * scalar;
            odres_  += min( lhs_, orhs_ ) * scalar;
            sres_   += min( lhs_, orhs_ ) * scalar;
            osres_  += min( lhs_, orhs_ ) * scalar;
            refres_ += ref_ * scalar;
         }
         catch( std::exception& ex ) {
            convertException<MT1,OMT2>( ex );
         }

         checkResults<MT1,OMT2>();

         try {
            initResults();
            dres_   += min( olhs_, rhs_ ) * scalar;
            odres_  += min( olhs_, rhs_ ) * scalar;
            sres_   += min( olhs_, rhs_ ) * scalar;
            osres_  += min( olhs_, rhs_ ) * scalar;
            refres_ += ref_ * scalar;
         }
         catch( std::exception& ex ) {
            convertException<OMT1,MT2>( ex );
         }

         checkResults<OMT1,MT2>();

         try {
            initResults();
            dres_   += min( olhs_, orhs_ ) * scalar;
            odres_  += min( olhs_, orhs_ ) * scalar;
            sres_   += min( olhs_, orhs_ ) * scalar;
            osres_  += min( olhs_, orhs_ ) * scalar;
            refres_ += ref_ * scalar;
         }
         catch( std::exception& ex ) {
            convertException<OMT1,OMT2>( ex );
         }

         checkResults<OMT1,OMT2>();
      }

      // Scaled minimum with addition assignment with evaluated matrices
      {
         test_  = "Scaled minimum with addition assignment with evaluated matrices (OP*s)";
         error_ = "Failed addition assignment operation";

         try {
            initResults();
            dres_   += min( eval( lhs_ ), eval( rhs_ ) ) * scalar;
            odres_  += min( eval( lhs_ ), eval( rhs_ ) ) * scalar;
            sres_   += min( eval( lhs_ ), eval( rhs_ ) ) * scalar;
            osres_  += min( eval( lhs_ ), eval( rhs_ ) ) * scalar;
            refres_ += eval( ref_ ) * scalar;
         }
         catch( std::exception& ex ) {
            convertException<MT1,MT2>( ex );
         }

         checkResults<MT1,MT2>();

         try {
            initResults();
            dres_   += min( eval( lhs_ ), eval( orhs_ ) ) * scalar;
            odres_  += min( eval( lhs_ ), eval( orhs_ ) ) * scalar;
            sres_   += min( eval( lhs_ ), eval( orhs_ ) ) * scalar;
            osres_  += min( eval( lhs_ ), eval( orhs_ ) ) * scalar;
            refres_ += eval( ref_ ) * scalar;
         }
         catch( std::exception& ex ) {
            convertException<MT1,OMT2>( ex );
         }

         checkResults<MT1,OMT2>();

         try {
            initResults();
            dres_   += min( eval( olhs_ ), eval( rhs_ ) ) * scalar;
            odres_  += min( eval( olhs_ ), eval( rhs_ ) ) * scalar;
            sres_   += min( eval( olhs_ ), eval( rhs_ ) ) * scalar;
            osres_  += min( eval( olhs_ ), eval( rhs_ ) ) * scalar;
            refres_ += eval( ref_ ) * scalar;
         }
         catch( std::exception& ex ) {
            convertException<OMT1,MT2>( ex );
         }

         checkResults<OMT1,MT2>();

         try {
            initResults();
            dres_   += min( eval( olhs_ ), eval( orhs_ ) ) * scalar;
            odres_  += min( eval( olhs_ ), eval( orhs_ ) ) * scalar;
            sres_   += min( eval( olhs_ ), eval( orhs_ ) ) * scalar;
            osres_  += min( eval( olhs_ ), eval( orhs_ ) ) * scalar;
            refres_ += eval( ref_ ) * scalar;
         }
         catch( std::exception& ex ) {
            convertException<OMT1,OMT2>( ex );
         }

         checkResults<OMT1,OMT2>();
      }


      //=====================================================================================
      // Scaled minimum with addition assignment (OP/s)
      //=====================================================================================

      // Scaled minimum with addition assignment with the given matrices
      {
         test_  = "Scaled minimum with addition assignment with the given matrices (OP/s)";
         error_ = "Failed addition assignment operation";

         try {
            initResults();
            dres_   += min( lhs_, rhs_ ) / scalar;
            odres_  += min( lhs_, rhs_ ) / scalar;
            sres_   += min( lhs_, rhs_ ) / scalar;
            osres_  += min( lhs_, rhs_ ) / scalar;
            refres_ += ref_ / scalar;
         }
         catch( std::exception& ex ) {
            convertException<MT1,MT2>( ex );
         }

         checkResults<MT1,MT2>();

         try {
            initResults();
            dres_   += min( lhs_, orhs_ ) / scalar;
            odres_  += min( lhs_, orhs_ ) / scalar;
            sres_   += min( lhs_, orhs_ ) / scalar;
            osres_  += min( lhs_, orhs_ ) / scalar;
            refres_ += ref_ / scalar;
         }
         catch( std::exception& ex ) {
            convertException<MT1,OMT2>( ex );
         }

         checkResults<MT1,OMT2>();

         try {
            initResults();
            dres_   += min( olhs_, rhs_ ) / scalar;
            odres_  += min( olhs_, rhs_ ) / scalar;
            sres_   += min( olhs_, rhs_ ) / scalar;
            osres_  += min( olhs_, rhs_ ) / scalar;
            refres_ += ref_ / scalar;
         }
         catch( std::exception& ex ) {
            convertException<OMT1,MT2>( ex );
         }

         checkResults<OMT1,MT2>();

         try {
            initResults();
            dres_   += min( olhs_, orhs_ ) / scalar;
            odres_  += min( olhs_, orhs_ ) / scalar;
            sres_   += min( olhs_, orhs_ ) / scalar;
            osres_  += min( olhs_, orhs_ ) / scalar;
            refres_ += ref_ / scalar;
         }
         catch( std::exception& ex ) {
            convertException<OMT1,OMT2>( ex );
         }

         checkResults<OMT1,OMT2>();
      }

      // Scaled minimum with addition assignment with evaluated matrices
      {
         test_  = "Scaled minimum with addition assignment with evaluated matrices (OP/s)";
         error_ = "Failed addition assignment operation";

         try {
            initResults();
            dres_   += min( eval( lhs_ ), eval( rhs_ ) ) / scalar;
            odres_  += min( eval( lhs_ ), eval( rhs_ ) ) / scalar;
            sres_   += min( eval( lhs_ ), eval( rhs_ ) ) / scalar;
            osres_  += min( eval( lhs_ ), eval( rhs_ ) ) / scalar;
            refres_ += eval( ref_ ) / scalar;
         }
         catch( std::exception& ex ) {
            convertException<MT1,MT2>( ex );
         }

         checkResults<MT1,MT2>();

         try {
            initResults();
            dres_   += min( eval( lhs_ ), eval( orhs_ ) ) / scalar;
            odres_  += min( eval( lhs_ ), eval( orhs_ ) ) / scalar;
            sres_   += min( eval( lhs_ ), eval( orhs_ ) ) / scalar;
            osres_  += min( eval( lhs_ ), eval( orhs_ ) ) / scalar;
            refres_ += eval( ref_ ) / scalar;
         }
         catch( std::exception& ex ) {
            convertException<MT1,OMT2>( ex );
         }

         checkResults<MT1,OMT2>();

         try {
            initResults();
            dres_   += min( eval( olhs_ ), eval( rhs_ ) ) / scalar;
            odres_  += min( eval( olhs_ ), eval( rhs_ ) ) / scalar;
            sres_   += min( eval( olhs_ ), eval( rhs_ ) ) / scalar;
            osres_  += min( eval( olhs_ ), eval( rhs_ ) ) / scalar;
            refres_ += eval( ref_ ) / scalar;
         }
         catch( std::exception& ex ) {
            convertException<OMT1,MT2>( ex );
         }

         checkResults<OMT1,MT2>();

         try {
            initResults();
            dres_   += min( eval( olhs_ ), eval( orhs_ ) ) / scalar;
            odres_  += min( eval( olhs_ ), eval( orhs_ ) ) / scalar;
            sres_   += min( eval( olhs_ ), eval( orhs_ ) ) / scalar;
            osres_  += min( eval( olhs_ ), eval( orhs_ ) ) / scalar;
            refres_ += eval( ref_ ) / scalar;
         }
         catch( std::exception& ex ) {
            convertException<OMT1,OMT2>( ex );
         }

         checkResults<OMT1,OMT2>();
      }


      //=====================================================================================
      // Scaled minimum with subtraction assignment (s*OP)
      //=====================================================================================

      // Scaled minimum with subtraction assignment with the given matrices
      {
         test_  = "Scaled minimum with subtraction assignment with the given matrices (s*OP)";
         error_ = "Failed subtraction assignment operation";

         try {
            initResults();
            dres_   -= scalar * min( lhs_, rhs_ );
            odres_  -= scalar * min( lhs_, rhs_ );
            sres_   -= scalar * min( lhs_, rhs_ );
            osres_  -= scalar * min( lhs_, rhs_ );
            refres_ -= scalar * ref_;
         }
         catch( std::exception& ex ) {
            convertException<MT1,MT2>( ex );
         }

         checkResults<MT1,MT2>();

         try {
            initResults();
            dres_   -= scalar * min( lhs_, orhs_ );
            odres_  -= scalar * min( lhs_, orhs_ );
            sres_   -= scalar * min( lhs_, orhs_ );
            osres_  -= scalar * min( lhs_, orhs_ );
            refres_ -= scalar * ref_;
         }
         catch( std::exception& ex ) {
            convertException<MT1,OMT2>( ex );
         }

         checkResults<MT1,OMT2>();

         try {
            initResults();
            dres_   -= scalar * min( olhs_, rhs_ );
            odres_  -= scalar * min( olhs_, rhs_ );
            sres_   -= scalar * min( olhs_, rhs_ );
            osres_  -= scalar * min( olhs_, rhs_ );
            refres_ -= scalar * ref_;
         }
         catch( std::exception& ex ) {
            convertException<OMT1,MT2>( ex );
         }

         checkResults<OMT1,MT2>();

         try {
            initResults();
            dres_   -= scalar * min( olhs_, orhs_ );
            odres_  -= scalar * min( olhs_, orhs_ );
            sres_   -= scalar * min( olhs_, orhs_ );
            osres_  -= scalar * min( olhs_, orhs_ );
            refres_ -= scalar * ref_;
         }
         catch( std::exception& ex ) {
            convertException<OMT1,OMT2>( ex );
         }

         checkResults<OMT1,OMT2>();
      }

      // Scaled minimum with subtraction assignment with evaluated matrices
      {
         test_  = "Scaled minimum with subtraction assignment with evaluated matrices (s*OP)";
         error_ = "Failed subtraction assignment operation";

         try {
            initResults();
            dres_   -= scalar * min( eval( lhs_ ), eval( rhs_ ) );
            odres_  -= scalar * min( eval( lhs_ ), eval( rhs_ ) );
            sres_   -= scalar * min( eval( lhs_ ), eval( rhs_ ) );
            osres_  -= scalar * min( eval( lhs_ ), eval( rhs_ ) );
            refres_ -= scalar * eval( ref_ );
         }
         catch( std::exception& ex ) {
            convertException<MT1,MT2>( ex );
         }

         checkResults<MT1,MT2>();

         try {
            initResults();
            dres_   -= scalar * min( eval( lhs_ ), eval( orhs_ ) );
            odres_  -= scalar * min( eval( lhs_ ), eval( orhs_ ) );
            sres_   -= scalar * min( eval( lhs_ ), eval( orhs_ ) );
            osres_  -= scalar * min( eval( lhs_ ), eval( orhs_ ) );
            refres_ -= scalar * eval( ref_ );
         }
         catch( std::exception& ex ) {
            convertException<MT1,OMT2>( ex );
         }

         checkResults<MT1,OMT2>();

         try {
            initResults();
            dres_   -= scalar * min( eval( olhs_ ), eval( rhs_ ) );
            odres_  -= scalar * min( eval( olhs_ ), eval( rhs_ ) );
            sres_   -= scalar * min( eval( olhs_ ), eval( rhs_ ) );
            osres_  -= scalar * min( eval( olhs_ ), eval( rhs_ ) );
            refres_ -= scalar * eval( ref_ );
         }
         catch( std::exception& ex ) {
            convertException<OMT1,MT2>( ex );
         }

         checkResults<OMT1,MT2>();

         try {
            initResults();
            dres_   -= scalar * min( eval( olhs_ ), eval( orhs_ ) );
            odres_  -= scalar * min( eval( olhs_ ), eval( orhs_ ) );
            sres_   -= scalar * min( eval( olhs_ ), eval( orhs_ ) );
            osres_  -= scalar * min( eval( olhs_ ), eval( orhs_ ) );
            refres_ -= scalar * eval( ref_ );
         }
         catch( std::exception& ex ) {
            convertException<OMT1,OMT2>( ex );
         }

         checkResults<OMT1,OMT2>();
      }


      //=====================================================================================
      // Scaled minimum with subtraction assignment (OP*s)
      //=====================================================================================

      // Scaled minimum with subtraction assignment with the given matrices
      {
         test_  = "Scaled minimum with subtraction assignment with the given matrices (OP*s)";
         error_ = "Failed subtraction assignment operation";

         try {
            initResults();
            dres_   -= min( lhs_, rhs_ ) * scalar;
            odres_  -= min( lhs_, rhs_ ) * scalar;
            sres_   -= min( lhs_, rhs_ ) * scalar;
            osres_  -= min( lhs_, rhs_ ) * scalar;
            refres_ -= ref_ * scalar;
         }
         catch( std::exception& ex ) {
            convertException<MT1,MT2>( ex );
         }

         checkResults<MT1,MT2>();

         try {
            initResults();
            dres_   -= min( lhs_, orhs_ ) * scalar;
            odres_  -= min( lhs_, orhs_ ) * scalar;
            sres_   -= min( lhs_, orhs_ ) * scalar;
            osres_  -= min( lhs_, orhs_ ) * scalar;
            refres_ -= ref_ * scalar;
         }
         catch( std::exception& ex ) {
            convertException<MT1,OMT2>( ex );
         }

         checkResults<MT1,OMT2>();

         try {
            initResults();
            dres_   -= min( olhs_, rhs_ ) * scalar;
            odres_  -= min( olhs_, rhs_ ) * scalar;
            sres_   -= min( olhs_, rhs_ ) * scalar;
            osres_  -= min( olhs_, rhs_ ) * scalar;
            refres_ -= ref_ * scalar;
         }
         catch( std::exception& ex ) {
            convertException<OMT1,MT2>( ex );
         }

         checkResults<OMT1,MT2>();

         try {
            initResults();
            dres_   -= min( olhs_, orhs_ ) * scalar;
            odres_  -= min( olhs_, orhs_ ) * scalar;
            sres_   -= min( olhs_, orhs_ ) * scalar;
            osres_  -= min( olhs_, orhs_ ) * scalar;
            refres_ -= ref_ * scalar;
         }
         catch( std::exception& ex ) {
            convertException<OMT1,OMT2>( ex );
         }

         checkResults<OMT1,OMT2>();
      }

      // Scaled minimum with subtraction assignment with evaluated matrices
      {
         test_  = "Scaled minimum with subtraction assignment with evaluated matrices (OP*s)";
         error_ = "Failed subtraction assignment operation";

         try {
            initResults();
            dres_   -= min( eval( lhs_ ), eval( rhs_ ) ) * scalar;
            odres_  -= min( eval( lhs_ ), eval( rhs_ ) ) * scalar;
            sres_   -= min( eval( lhs_ ), eval( rhs_ ) ) * scalar;
            osres_  -= min( eval( lhs_ ), eval( rhs_ ) ) * scalar;
            refres_ -= eval( ref_ ) * scalar;
         }
         catch( std::exception& ex ) {
            convertException<MT1,MT2>( ex );
         }

         checkResults<MT1,MT2>();

         try {
            initResults();
            dres_   -= min( eval( lhs_ ), eval( orhs_ ) ) * scalar;
            odres_  -= min( eval( lhs_ ), eval( orhs_ ) ) * scalar;
            sres_   -= min( eval( lhs_ ), eval( orhs_ ) ) * scalar;
            osres_  -= min( eval( lhs_ ), eval( orhs_ ) ) * scalar;
            refres_ -= eval( ref_ ) * scalar;
         }
         catch( std::exception& ex ) {
            convertException<MT1,OMT2>( ex );
         }

         checkResults<MT1,OMT2>();

         try {
            initResults();
            dres_   -= min( eval( olhs_ ), eval( rhs_ ) ) * scalar;
            odres_  -= min( eval( olhs_ ), eval( rhs_ ) ) * scalar;
            sres_   -= min( eval( olhs_ ), eval( rhs_ ) ) * scalar;
            osres_  -= min( eval( olhs_ ), eval( rhs_ ) ) * scalar;
            refres_ -= eval( ref_ ) * scalar;
         }
         catch( std::exception& ex ) {
            convertException<OMT1,MT2>( ex );
         }

         checkResults<OMT1,MT2>();

         try {
            initResults();
            dres_   -= min( eval( olhs_ ), eval( orhs_ ) ) * scalar;
            odres_  -= min( eval( olhs_ ), eval( orhs_ ) ) * scalar;
            sres_   -= min( eval( olhs_ ), eval( orhs_ ) ) * scalar;
            osres_  -= min( eval( olhs_ ), eval( orhs_ ) ) * scalar;
            refres_ -= eval( ref_ ) * scalar;
         }
         catch( std::exception& ex ) {
            convertException<OMT1,OMT2>( ex );
         }

         checkResults<OMT1,OMT2>();
      }


      //=====================================================================================
      // Scaled minimum with subtraction assignment (OP/s)
      //=====================================================================================

      // Scaled minimum with subtraction assignment with the given matrices
      {
         test_  = "Scaled minimum with subtraction assignment with the given matrices (OP/s)";
         error_ = "Failed subtraction assignment operation";

         try {
            initResults();
            dres_   -= min( lhs_, rhs_ ) / scalar;
            odres_  -= min( lhs_, rhs_ ) / scalar;
            sres_   -= min( lhs_, rhs_ ) / scalar;
            osres_  -= min( lhs_, rhs_ ) / scalar;
            refres_ -= ref_ / scalar;
         }
         catch( std::exception& ex ) {
            convertException<MT1,MT2>( ex );
         }

         checkResults<MT1,MT2>();

         try {
            initResults();
            dres_   -= min( lhs_, orhs_ ) / scalar;
            odres_  -= min( lhs_, orhs_ ) / scalar;
            sres_   -= min( lhs_, orhs_ ) / scalar;
            osres_  -= min( lhs_, orhs_ ) / scalar;
            refres_ -= ref_ / scalar;
         }
         catch( std::exception& ex ) {
            convertException<MT1,OMT2>( ex );
         }

         checkResults<MT1,OMT2>();

         try {
            initResults();
            dres_   -= min( olhs_, rhs_ ) / scalar;
            odres_  -= min( olhs_, rhs_ ) / scalar;
            sres_   -= min( olhs_, rhs_ ) / scalar;
            osres_  -= min( olhs_, rhs_ ) / scalar;
            refres_ -= ref_ / scalar;
         }
         catch( std::exception& ex ) {
            convertException<OMT1,MT2>( ex );
         }

         checkResults<OMT1,MT2>();

         try {
            initResults();
            dres_   -= min( olhs_, orhs_ ) / scalar;
            odres_  -= min( olhs_, orhs_ ) / scalar;
            sres_   -= min( olhs_, orhs_ ) / scalar;
            osres_  -= min( olhs_, orhs_ ) / scalar;
            refres_ -= ref_ / scalar;
         }
         catch( std::exception& ex ) {
            convertException<OMT1,OMT2>( ex );
         }

         checkResults<OMT1,OMT2>();
      }

      // Scaled minimum with subtraction assignment with evaluated matrices
      {
         test_  = "Scaled minimum with subtraction assignment with evaluated matrices (OP/s)";
         error_ = "Failed subtraction assignment operation";

         try {
            initResults();
            dres_   -= min( eval( lhs_ ), eval( rhs_ ) ) / scalar;
            odres_  -= min( eval( lhs_ ), eval( rhs_ ) ) / scalar;
            sres_   -= min( eval( lhs_ ), eval( rhs_ ) ) / scalar;
            osres_  -= min( eval( lhs_ ), eval( rhs_ ) ) / scalar;
            refres_ -= eval( ref_ ) / scalar;
         }
         catch( std::exception& ex ) {
            convertException<MT1,MT2>( ex );
         }

         checkResults<MT1,MT2>();

         try {
            initResults();
            dres_   -= min( eval( lhs_ ), eval( orhs_ ) ) / scalar;
            odres_  -= min( eval( lhs_ ), eval( orhs_ ) ) / scalar;
            sres_   -= min( eval( lhs_ ), eval( orhs_ ) ) / scalar;
            osres_  -= min( eval( lhs_ ), eval( orhs_ ) ) / scalar;
            refres_ -= eval( ref_ ) / scalar;
         }
         catch( std::exception& ex ) {
            convertException<MT1,OMT2>( ex );
         }

         checkResults<MT1,OMT2>();

         try {
            initResults();
            dres_   -= min( eval( olhs_ ), eval( rhs_ ) ) / scalar;
            odres_  -= min( eval( olhs_ ), eval( rhs_ ) ) / scalar;
            sres_   -= min( eval( olhs_ ), eval( rhs_ ) ) / scalar;
            osres_  -= min( eval( olhs_ ), eval( rhs_ ) ) / scalar;
            refres_ -= eval( ref_ ) / scalar;
         }
         catch( std::exception& ex ) {
            convertException<OMT1,MT2>( ex );
         }

         checkResults<OMT1,MT2>();

         try {
            initResults();
            dres_   -= min( eval( olhs_ ), eval( orhs_ ) ) / scalar;
            odres_  -= min( eval( olhs_ ), eval( orhs_ ) ) / scalar;
            sres_   -= min( eval( olhs_ ), eval( orhs_ ) ) / scalar;
            osres_  -= min( eval( olhs_ ), eval( orhs_ ) ) / scalar;
            refres_ -= eval( ref_ ) / scalar;
         }
         catch( std::exception& ex ) {
            convertException<OMT1,OMT2>( ex );
         }

         checkResults<OMT1,OMT2>();
      }


      //=====================================================================================
      // Scaled minimum with Schur product assignment (s*OP)
      //=====================================================================================

      // Scaled minimum with Schur product assignment with the given matrices
      {
         test_  = "Scaled minimum with Schur product assignment with the given matrices (s*OP)";
         error_ = "Failed Schur product assignment operation";

         try {
            initResults();
            dres_   %= scalar * min( lhs_, rhs_ );
            odres_  %= scalar * min( lhs_, rhs_ );
            sres_   %= scalar * min( lhs_, rhs_ );
            osres_  %= scalar * min( lhs_, rhs_ );
            refres_ %= scalar * ref_;
         }
         catch( std::exception& ex ) {
            convertException<MT1,MT2>( ex );
         }

         checkResults<MT1,MT2>();

         try {
            initResults();
            dres_   %= scalar * min( lhs_, orhs_ );
            odres_  %= scalar * min( lhs_, orhs_ );
            sres_   %= scalar * min( lhs_, orhs_ );
            osres_  %= scalar * min( lhs_, orhs_ );
            refres_ %= scalar * ref_;
         }
         catch( std::exception& ex ) {
            convertException<MT1,OMT2>( ex );
         }

         checkResults<MT1,OMT2>();

         try {
            initResults();
            dres_   %= scalar * min( olhs_, rhs_ );
            odres_  %= scalar * min( olhs_, rhs_ );
            sres_   %= scalar * min( olhs_, rhs_ );
            osres_  %= scalar * min( olhs_, rhs_ );
            refres_ %= scalar * ref_;
         }
         catch( std::exception& ex ) {
            convertException<OMT1,MT2>( ex );
         }

         checkResults<OMT1,MT2>();

         try {
            initResults();
            dres_   %= scalar * min( olhs_, orhs_ ) ;
            odres_  %= scalar * min( olhs_, orhs_ );
            sres_   %= scalar * min( olhs_, orhs_ );
            osres_  %= scalar * min( olhs_, orhs_ );
            refres_ %= scalar * ref_;
         }
         catch( std::exception& ex ) {
            convertException<OMT1,OMT2>( ex );
         }

         checkResults<OMT1,OMT2>();
      }

      // Scaled minimum with Schur product assignment with evaluated matrices
      {
         test_  = "Scaled minimum with Schur product assignment with evaluated matrices (s*OP)";
         error_ = "Failed Schur product assignment operation";

         try {
            initResults();
            dres_   %= scalar * min( eval( lhs_ ), eval( rhs_ ) );
            odres_  %= scalar * min( eval( lhs_ ), eval( rhs_ ) );
            sres_   %= scalar * min( eval( lhs_ ), eval( rhs_ ) );
            osres_  %= scalar * min( eval( lhs_ ), eval( rhs_ ) );
            refres_ %= scalar * eval( ref_ );
         }
         catch( std::exception& ex ) {
            convertException<MT1,MT2>( ex );
         }

         checkResults<MT1,MT2>();

         try {
            initResults();
            dres_   %= scalar * min( eval( lhs_ ), eval( orhs_ ) );
            odres_  %= scalar * min( eval( lhs_ ), eval( orhs_ ) );
            sres_   %= scalar * min( eval( lhs_ ), eval( orhs_ ) );
            osres_  %= scalar * min( eval( lhs_ ), eval( orhs_ ) );
            refres_ %= scalar * eval( ref_ );
         }
         catch( std::exception& ex ) {
            convertException<MT1,OMT2>( ex );
         }

         checkResults<MT1,OMT2>();

         try {
            initResults();
            dres_   %= scalar * min( eval( olhs_ ), eval( rhs_ ) );
            odres_  %= scalar * min( eval( olhs_ ), eval( rhs_ ) );
            sres_   %= scalar * min( eval( olhs_ ), eval( rhs_ ) );
            osres_  %= scalar * min( eval( olhs_ ), eval( rhs_ ) );
            refres_ %= scalar * eval( ref_ );
         }
         catch( std::exception& ex ) {
            convertException<OMT1,MT2>( ex );
         }

         checkResults<OMT1,MT2>();

         try {
            initResults();
            dres_   %= scalar * min( eval( olhs_ ), eval( orhs_ ) );
            odres_  %= scalar * min( eval( olhs_ ), eval( orhs_ ) );
            sres_   %= scalar * min( eval( olhs_ ), eval( orhs_ ) );
            osres_  %= scalar * min( eval( olhs_ ), eval( orhs_ ) );
            refres_ %= scalar * eval( ref_ );
         }
         catch( std::exception& ex ) {
            convertException<OMT1,OMT2>( ex );
         }

         checkResults<OMT1,OMT2>();
      }


      //=====================================================================================
      // Scaled minimum with Schur product assignment (OP*s)
      //=====================================================================================

      // Scaled minimum with Schur product assignment with the given matrices
      {
         test_  = "Scaled minimum with Schur product assignment with the given matrices (OP*s)";
         error_ = "Failed Schur product assignment operation";

         try {
            initResults();
            dres_   %= min( lhs_, rhs_ ) * scalar;
            odres_  %= min( lhs_, rhs_ ) * scalar;
            sres_   %= min( lhs_, rhs_ ) * scalar;
            osres_  %= min( lhs_, rhs_ ) * scalar;
            refres_ %= ref_ * scalar;
         }
         catch( std::exception& ex ) {
            convertException<MT1,MT2>( ex );
         }

         checkResults<MT1,MT2>();

         try {
            initResults();
            dres_   %= min( lhs_, orhs_ ) * scalar;
            odres_  %= min( lhs_, orhs_ ) * scalar;
            sres_   %= min( lhs_, orhs_ ) * scalar;
            osres_  %= min( lhs_, orhs_ ) * scalar;
            refres_ %= ref_ * scalar;
         }
         catch( std::exception& ex ) {
            convertException<MT1,OMT2>( ex );
         }

         checkResults<MT1,OMT2>();

         try {
            initResults();
            dres_   %= min( olhs_, rhs_ ) * scalar;
            odres_  %= min( olhs_, rhs_ ) * scalar;
            sres_   %= min( olhs_, rhs_ ) * scalar;
            osres_  %= min( olhs_, rhs_ ) * scalar;
            refres_ %= ref_ * scalar;
         }
         catch( std::exception& ex ) {
            convertException<OMT1,MT2>( ex );
         }

         checkResults<OMT1,MT2>();

         try {
            initResults();
            dres_   %= min( olhs_, orhs_ ) * scalar;
            odres_  %= min( olhs_, orhs_ ) * scalar;
            sres_   %= min( olhs_, orhs_ ) * scalar;
            osres_  %= min( olhs_, orhs_ ) * scalar;
            refres_ %= ref_ * scalar;
         }
         catch( std::exception& ex ) {
            convertException<OMT1,OMT2>( ex );
         }

         checkResults<OMT1,OMT2>();
      }

      // Scaled minimum with Schur product assignment with evaluated matrices
      {
         test_  = "Scaled minimum with Schur product assignment with evaluated matrices (OP*s)";
         error_ = "Failed Schur product assignment operation";

         try {
            initResults();
            dres_   %= min( eval( lhs_ ), eval( rhs_ ) ) * scalar;
            odres_  %= min( eval( lhs_ ), eval( rhs_ ) ) * scalar;
            sres_   %= min( eval( lhs_ ), eval( rhs_ ) ) * scalar;
            osres_  %= min( eval( lhs_ ), eval( rhs_ ) ) * scalar;
            refres_ %= eval( ref_ ) * scalar;
         }
         catch( std::exception& ex ) {
            convertException<MT1,MT2>( ex );
         }

         checkResults<MT1,MT2>();

         try {
            initResults();
            dres_   %= min( eval( lhs_ ), eval( orhs_ ) ) * scalar;
            odres_  %= min( eval( lhs_ ), eval( orhs_ ) ) * scalar;
            sres_   %= min( eval( lhs_ ), eval( orhs_ ) ) * scalar;
            osres_  %= min( eval( lhs_ ), eval( orhs_ ) ) * scalar;
            refres_ %= eval( ref_ ) * scalar;
         }
         catch( std::exception& ex ) {
            convertException<MT1,OMT2>( ex );
         }

         checkResults<MT1,OMT2>();

         try {
            initResults();
            dres_   %= min( eval( olhs_ ), eval( rhs_ ) ) * scalar;
            odres_  %= min( eval( olhs_ ), eval( rhs_ ) ) * scalar;
            sres_   %= min( eval( olhs_ ), eval( rhs_ ) ) * scalar;
            osres_  %= min( eval( olhs_ ), eval( rhs_ ) ) * scalar;
            refres_ %= eval( ref_ ) * scalar;
         }
         catch( std::exception& ex ) {
            convertException<OMT1,MT2>( ex );
         }

         checkResults<OMT1,MT2>();

         try {
            initResults();
            dres_   %= min( eval( olhs_ ), eval( orhs_ ) ) * scalar;
            odres_  %= min( eval( olhs_ ), eval( orhs_ ) ) * scalar;
            sres_   %= min( eval( olhs_ ), eval( orhs_ ) ) * scalar;
            osres_  %= min( eval( olhs_ ), eval( orhs_ ) ) * scalar;
            refres_ %= eval( ref_ ) * scalar;
         }
         catch( std::exception& ex ) {
            convertException<OMT1,OMT2>( ex );
         }

         checkResults<OMT1,OMT2>();
      }


      //=====================================================================================
      // Scaled minimum with Schur product assignment (OP/s)
      //=====================================================================================

      // Scaled minimum with Schur product assignment with the given matrices
      {
         test_  = "Scaled minimum with Schur product assignment with the given matrices (OP/s)";
         error_ = "Failed Schur product assignment operation";

         try {
            initResults();
            dres_   %= min( lhs_, rhs_ ) / scalar;
            odres_  %= min( lhs_, rhs_ ) / scalar;
            sres_   %= min( lhs_, rhs_ ) / scalar;
            osres_  %= min( lhs_, rhs_ ) / scalar;
            refres_ %= ref_ / scalar;
         }
         catch( std::exception& ex ) {
            convertException<MT1,MT2>( ex );
         }

         checkResults<MT1,MT2>();

         try {
            initResults();
            dres_   %= min( lhs_, orhs_ ) / scalar;
            odres_  %= min( lhs_, orhs_ ) / scalar;
            sres_   %= min( lhs_, orhs_ ) / scalar;
            osres_  %= min( lhs_, orhs_ ) / scalar;
            refres_ %= ref_ / scalar;
         }
         catch( std::exception& ex ) {
            convertException<MT1,OMT2>( ex );
         }

         checkResults<MT1,OMT2>();

         try {
            initResults();
            dres_   %= min( olhs_, rhs_ ) / scalar;
            odres_  %= min( olhs_, rhs_ ) / scalar;
            sres_   %= min( olhs_, rhs_ ) / scalar;
            osres_  %= min( olhs_, rhs_ ) / scalar;
            refres_ %= ref_ / scalar;
         }
         catch( std::exception& ex ) {
            convertException<OMT1,MT2>( ex );
         }

         checkResults<OMT1,MT2>();

         try {
            initResults();
            dres_   %= min( olhs_, orhs_ ) / scalar;
            odres_  %= min( olhs_, orhs_ ) / scalar;
            sres_   %= min( olhs_, orhs_ ) / scalar;
            osres_  %= min( olhs_, orhs_ ) / scalar;
            refres_ %= ref_ / scalar;
         }
         catch( std::exception& ex ) {
            convertException<OMT1,OMT2>( ex );
         }

         checkResults<OMT1,OMT2>();
      }

      // Scaled minimum with Schur product assignment with evaluated matrices
      {
         test_  = "Scaled minimum with Schur product assignment with evaluated matrices (OP/s)";
         error_ = "Failed Schur product assignment operation";

         try {
            initResults();
            dres_   %= min( eval( lhs_ ), eval( rhs_ ) ) / scalar;
            odres_  %= min( eval( lhs_ ), eval( rhs_ ) ) / scalar;
            sres_   %= min( eval( lhs_ ), eval( rhs_ ) ) / scalar;
            osres_  %= min( eval( lhs_ ), eval( rhs_ ) ) / scalar;
            refres_ %= eval( ref_ ) / scalar;
         }
         catch( std::exception& ex ) {
            convertException<MT1,MT2>( ex );
         }

         checkResults<MT1,MT2>();

         try {
            initResults();
            dres_   %= min( eval( lhs_ ), eval( orhs_ ) ) / scalar;
            odres_  %= min( eval( lhs_ ), eval( orhs_ ) ) / scalar;
            sres_   %= min( eval( lhs_ ), eval( orhs_ ) ) / scalar;
            osres_  %= min( eval( lhs_ ), eval( orhs_ ) ) / scalar;
            refres_ %= eval( ref_ ) / scalar;
         }
         catch( std::exception& ex ) {
            convertException<MT1,OMT2>( ex );
         }

         checkResults<MT1,OMT2>();

         try {
            initResults();
            dres_   %= min( eval( olhs_ ), eval( rhs_ ) ) / scalar;
            odres_  %= min( eval( olhs_ ), eval( rhs_ ) ) / scalar;
            sres_   %= min( eval( olhs_ ), eval( rhs_ ) ) / scalar;
            osres_  %= min( eval( olhs_ ), eval( rhs_ ) ) / scalar;
            refres_ %= eval( ref_ ) / scalar;
         }
         catch( std::exception& ex ) {
            convertException<OMT1,MT2>( ex );
         }

         checkResults<OMT1,MT2>();

         try {
            initResults();
            dres_   %= min( eval( olhs_ ), eval( orhs_ ) ) / scalar;
            odres_  %= min( eval( olhs_ ), eval( orhs_ ) ) / scalar;
            sres_   %= min( eval( olhs_ ), eval( orhs_ ) ) / scalar;
            osres_  %= min( eval( olhs_ ), eval( orhs_ ) ) / scalar;
            refres_ %= eval( ref_ ) / scalar;
         }
         catch( std::exception& ex ) {
            convertException<OMT1,OMT2>( ex );
         }

         checkResults<OMT1,OMT2>();
      }
   }
#endif
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Testing the transpose dense matrix/dense matrix minimum operation.
//
// \return void
// \exception std::runtime_error Minimum error detected.
//
// This function tests the transpose matrix minimum with plain assignment. In case any error
// resulting from the minimum or the subsequent assignment is detected, a \a std::runtime_error
// exception is thrown.
*/
template< typename MT1    // Type of the left-hand side dense matrix
        , typename MT2 >  // Type of the right-hand side dense matrix
void OperationTest<MT1,MT2>::testTransOperation()
{
#if BLAZETEST_MATHTEST_TEST_TRANS_OPERATION
   if( BLAZETEST_MATHTEST_TEST_TRANS_OPERATION > 1 )
   {
      //=====================================================================================
      // Transpose minimum
      //=====================================================================================

      // Transpose minimum with the given matrices
      {
         test_  = "Transpose minimum with the given matrices";
         error_ = "Failed minimum operation";

         try {
            initTransposeResults();
            tdres_  = trans( min( lhs_, rhs_ ) );
            todres_ = trans( min( lhs_, rhs_ ) );
            tsres_  = trans( min( lhs_, rhs_ ) );
            tosres_ = trans( min( lhs_, rhs_ ) );
            refres_ = trans( ref_ );
         }
         catch( std::exception& ex ) {
            convertException<MT1,MT2>( ex );
         }

         checkTransposeResults<MT1,MT2>();

         try {
            initTransposeResults();
            tdres_  = trans( min( lhs_, orhs_ ) );
            todres_ = trans( min( lhs_, orhs_ ) );
            tsres_  = trans( min( lhs_, orhs_ ) );
            tosres_ = trans( min( lhs_, orhs_ ) );
            refres_ = trans( ref_ );
         }
         catch( std::exception& ex ) {
            convertException<MT1,OMT2>( ex );
         }

         checkTransposeResults<MT1,OMT2>();

         try {
            initTransposeResults();
            tdres_  = trans( min( olhs_, rhs_ ) );
            todres_ = trans( min( olhs_, rhs_ ) );
            tsres_  = trans( min( olhs_, rhs_ ) );
            tosres_ = trans( min( olhs_, rhs_ ) );
            refres_ = trans( ref_ );
         }
         catch( std::exception& ex ) {
            convertException<OMT1,MT2>( ex );
         }

         checkTransposeResults<OMT1,MT2>();

         try {
            initTransposeResults();
            tdres_  = trans( min( olhs_, orhs_ ) );
            todres_ = trans( min( olhs_, orhs_ ) );
            tsres_  = trans( min( olhs_, orhs_ ) );
            tosres_ = trans( min( olhs_, orhs_ ) );
            refres_ = trans( ref_ );
         }
         catch( std::exception& ex ) {
            convertException<OMT1,OMT2>( ex );
         }

         checkTransposeResults<OMT1,OMT2>();
      }

      // Transpose minimum with evaluated matrices
      {
         test_  = "Transpose minimum with evaluated matrices";
         error_ = "Failed minimum operation";

         try {
            initTransposeResults();
            tdres_  = trans( min( eval( lhs_ ), eval( rhs_ ) ) );
            todres_ = trans( min( eval( lhs_ ), eval( rhs_ ) ) );
            tsres_  = trans( min( eval( lhs_ ), eval( rhs_ ) ) );
            tosres_ = trans( min( eval( lhs_ ), eval( rhs_ ) ) );
            refres_ = trans( eval( ref_ ) );
         }
         catch( std::exception& ex ) {
            convertException<MT1,MT2>( ex );
         }

         checkTransposeResults<MT1,MT2>();

         try {
            initTransposeResults();
            tdres_  = trans( min( eval( lhs_ ), eval( orhs_ ) ) );
            todres_ = trans( min( eval( lhs_ ), eval( orhs_ ) ) );
            tsres_  = trans( min( eval( lhs_ ), eval( orhs_ ) ) );
            tosres_ = trans( min( eval( lhs_ ), eval( orhs_ ) ) );
            refres_ = trans( eval( ref_ ) );
         }
         catch( std::exception& ex ) {
            convertException<MT1,OMT2>( ex );
         }

         checkTransposeResults<MT1,OMT2>();

         try {
            initTransposeResults();
            tdres_  = trans( min( eval( olhs_ ), eval( rhs_ ) ) );
            todres_ = trans( min( eval( olhs_ ), eval( rhs_ ) ) );
            tsres_  = trans( min( eval( olhs_ ), eval( rhs_ ) ) );
            tosres_ = trans( min( eval( olhs_ ), eval( rhs_ ) ) );
            refres_ = trans( eval( ref_ ) );
         }
         catch( std::exception& ex ) {
            convertException<OMT1,MT2>( ex );
         }

         checkTransposeResults<OMT1,MT2>();

         try {
            initTransposeResults();
            tdres_  = trans( min( eval( olhs_ ), eval( orhs_ ) ) );
            todres_ = trans( min( eval( olhs_ ), eval( orhs_ ) ) );
            tsres_  = trans( min( eval( olhs_ ), eval( orhs_ ) ) );
            tosres_ = trans( min( eval( olhs_ ), eval( orhs_ ) ) );
            refres_ = trans( eval( ref_ ) );
         }
         catch( std::exception& ex ) {
            convertException<OMT1,OMT2>( ex );
         }

         checkTransposeResults<OMT1,OMT2>();
      }
   }
#endif
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Testing the conjugate transpose dense matrix/dense matrix minimum operation.
//
// \return void
// \exception std::runtime_error Minimum error detected.
//
// This function tests the conjugate transpose matrix minimum with plain assignment. In case
// any error resulting from the minimum operation or the subsequent assignment is detected,
// a \a std::runtime_error exception is thrown.
*/
template< typename MT1    // Type of the left-hand side dense matrix
        , typename MT2 >  // Type of the right-hand side dense matrix
void OperationTest<MT1,MT2>::testCTransOperation()
{
#if BLAZETEST_MATHTEST_TEST_CTRANS_OPERATION
   if( BLAZETEST_MATHTEST_TEST_CTRANS_OPERATION > 1 )
   {
      //=====================================================================================
      // Conjugate transpose minimum
      //=====================================================================================

      // Conjugate transpose minimum with the given matrices
      {
         test_  = "Conjugate transpose minimum with the given matrices";
         error_ = "Failed minimum operation";

         try {
            initTransposeResults();
            tdres_  = ctrans( min( lhs_, rhs_ ) );
            todres_ = ctrans( min( lhs_, rhs_ ) );
            tsres_  = ctrans( min( lhs_, rhs_ ) );
            tosres_ = ctrans( min( lhs_, rhs_ ) );
            refres_ = ctrans( ref_ );
         }
         catch( std::exception& ex ) {
            convertException<MT1,MT2>( ex );
         }

         checkTransposeResults<MT1,MT2>();

         try {
            initTransposeResults();
            tdres_  = ctrans( min( lhs_, orhs_ ) );
            todres_ = ctrans( min( lhs_, orhs_ ) );
            tsres_  = ctrans( min( lhs_, orhs_ ) );
            tosres_ = ctrans( min( lhs_, orhs_ ) );
            refres_ = ctrans( ref_ );
         }
         catch( std::exception& ex ) {
            convertException<MT1,OMT2>( ex );
         }

         checkTransposeResults<MT1,OMT2>();

         try {
            initTransposeResults();
            tdres_  = ctrans( min( olhs_, rhs_ ) );
            todres_ = ctrans( min( olhs_, rhs_ ) );
            tsres_  = ctrans( min( olhs_, rhs_ ) );
            tosres_ = ctrans( min( olhs_, rhs_ ) );
            refres_ = ctrans( ref_ );
         }
         catch( std::exception& ex ) {
            convertException<OMT1,MT2>( ex );
         }

         checkTransposeResults<OMT1,MT2>();

         try {
            initTransposeResults();
            tdres_  = ctrans( min( olhs_, orhs_ ) );
            todres_ = ctrans( min( olhs_, orhs_ ) );
            tsres_  = ctrans( min( olhs_, orhs_ ) );
            tosres_ = ctrans( min( olhs_, orhs_ ) );
            refres_ = ctrans( ref_ );
         }
         catch( std::exception& ex ) {
            convertException<OMT1,OMT2>( ex );
         }

         checkTransposeResults<OMT1,OMT2>();
      }

      // Conjugate transpose minimum with evaluated matrices
      {
         test_  = "Conjugate transpose minimum with evaluated matrices";
         error_ = "Failed minimum operation";

         try {
            initTransposeResults();
            tdres_  = ctrans( min( eval( lhs_ ), eval( rhs_ ) ) );
            todres_ = ctrans( min( eval( lhs_ ), eval( rhs_ ) ) );
            tsres_  = ctrans( min( eval( lhs_ ), eval( rhs_ ) ) );
            tosres_ = ctrans( min( eval( lhs_ ), eval( rhs_ ) ) );
            refres_ = ctrans( eval( ref_ ) );
         }
         catch( std::exception& ex ) {
            convertException<MT1,MT2>( ex );
         }

         checkTransposeResults<MT1,MT2>();

         try {
            initTransposeResults();
            tdres_  = ctrans( min( eval( lhs_ ), eval( orhs_ ) ) );
            todres_ = ctrans( min( eval( lhs_ ), eval( orhs_ ) ) );
            tsres_  = ctrans( min( eval( lhs_ ), eval( orhs_ ) ) );
            tosres_ = ctrans( min( eval( lhs_ ), eval( orhs_ ) ) );
            refres_ = ctrans( eval( ref_ ) );
         }
         catch( std::exception& ex ) {
            convertException<MT1,OMT2>( ex );
         }

         checkTransposeResults<MT1,OMT2>();

         try {
            initTransposeResults();
            tdres_  = ctrans( min( eval( olhs_ ), eval( rhs_ ) ) );
            todres_ = ctrans( min( eval( olhs_ ), eval( rhs_ ) ) );
            tsres_  = ctrans( min( eval( olhs_ ), eval( rhs_ ) ) );
            tosres_ = ctrans( min( eval( olhs_ ), eval( rhs_ ) ) );
            refres_ = ctrans( eval( ref_ ) );
         }
         catch( std::exception& ex ) {
            convertException<OMT1,MT2>( ex );
         }

         checkTransposeResults<OMT1,MT2>();

         try {
            initTransposeResults();
            tdres_  = ctrans( min( eval( olhs_ ), eval( orhs_ ) ) );
            todres_ = ctrans( min( eval( olhs_ ), eval( orhs_ ) ) );
            tsres_  = ctrans( min( eval( olhs_ ), eval( orhs_ ) ) );
            tosres_ = ctrans( min( eval( olhs_ ), eval( orhs_ ) ) );
            refres_ = ctrans( eval( ref_ ) );
         }
         catch( std::exception& ex ) {
            convertException<OMT1,OMT2>( ex );
         }

         checkTransposeResults<OMT1,OMT2>();
      }
   }
#endif
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Testing the abs dense matrix/dense matrix minimum operation.
//
// \return void
// \exception std::runtime_error Minimum error detected.
//
// This function tests the abs matrix minimum with plain assignment, addition assignment,
// subtraction assignment, and Schur product assignment. In case any error resulting from the
// minimum operation or the subsequent assignment is detected, a \a std::runtime_error exception
// is thrown.
*/
template< typename MT1    // Type of the left-hand side dense matrix
        , typename MT2 >  // Type of the right-hand side dense matrix
void OperationTest<MT1,MT2>::testAbsOperation()
{
#if BLAZETEST_MATHTEST_TEST_ABS_OPERATION
   if( BLAZETEST_MATHTEST_TEST_ABS_OPERATION > 1 )
   {
      testCustomOperation( blaze::Abs(), "abs" );
   }
#endif
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Testing the conjugate dense matrix/dense matrix minimum operation.
//
// \return void
// \exception std::runtime_error Minimum error detected.
//
// This function tests the conjugate matrix minimum with plain assignment, addition assignment,
// subtraction assignment, and Schur product assignment. In case any error resulting from the
// minimum operation or the subsequent assignment is detected, a \a std::runtime_error exception
// is thrown.
*/
template< typename MT1    // Type of the left-hand side dense matrix
        , typename MT2 >  // Type of the right-hand side dense matrix
void OperationTest<MT1,MT2>::testConjOperation()
{
#if BLAZETEST_MATHTEST_TEST_CONJ_OPERATION
   if( BLAZETEST_MATHTEST_TEST_CONJ_OPERATION > 1 )
   {
      testCustomOperation( blaze::Conj(), "conj" );
   }
#endif
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Testing the \a real dense matrix/dense matrix minimum operation.
//
// \return void
// \exception std::runtime_error Minimum error detected.
//
// This function tests the \a real matrix minimum with plain assignment, addition assignment,
// subtraction assignment, and Schur product assignment. In case any error resulting from the
// minimum operation or the subsequent assignment is detected, a \a std::runtime_error exception
// is thrown.
*/
template< typename MT1    // Type of the left-hand side dense matrix
        , typename MT2 >  // Type of the right-hand side dense matrix
void OperationTest<MT1,MT2>::testRealOperation()
{
#if BLAZETEST_MATHTEST_TEST_REAL_OPERATION
   if( BLAZETEST_MATHTEST_TEST_REAL_OPERATION > 1 )
   {
      testCustomOperation( blaze::Real(), "real" );
   }
#endif
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Testing the \a imag dense matrix/dense matrix minimum operation.
//
// \return void
// \exception std::runtime_error Minimum error detected.
//
// This function tests the \a imag matrix minimum with plain assignment, addition assignment,
// subtraction assignment, and Schur product assignment. In case any error resulting from the
// minimum operation or the subsequent assignment is detected, a \a std::runtime_error exception
// is thrown.
*/
template< typename MT1    // Type of the left-hand side dense matrix
        , typename MT2 >  // Type of the right-hand side dense matrix
void OperationTest<MT1,MT2>::testImagOperation()
{
#if BLAZETEST_MATHTEST_TEST_IMAG_OPERATION
   if( BLAZETEST_MATHTEST_TEST_IMAG_OPERATION > 1 &&
       ( !blaze::IsHermitian<DRE>::value || blaze::isSymmetric( imag( min( lhs_, rhs_ ) ) ) ) )
   {
      testCustomOperation( blaze::Imag(), "imag" );
   }
#endif
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Testing the \a inv dense matrix/dense matrix minimum operation.
//
// \return void
// \exception std::runtime_error Minimum error detected.
//
// This function tests the \a inv matrix minimum with plain assignment, addition assignment,
// subtraction assignment, and Schur product assignment. In case any error resulting from the
// minimum operation or the subsequent assignment is detected, a \a std::runtime_error exception
// is thrown.
*/
template< typename MT1    // Type of the left-hand side dense matrix
        , typename MT2 >  // Type of the right-hand side dense matrix
void OperationTest<MT1,MT2>::testInvOperation()
{
#if BLAZETEST_MATHTEST_TEST_INV_OPERATION && BLAZETEST_MATHTEST_LAPACK_MODE
   if( BLAZETEST_MATHTEST_TEST_INV_OPERATION > 1 )
   {
      if( !isSquare( min( lhs_, rhs_ ) ) || blaze::isDefault( det( min( lhs_, rhs_ ) ) ) )
         return;

      testCustomOperation( blaze::Inv(), "inv" );
   }
#endif
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Testing the evaluated dense matrix/dense matrix minimum operation.
//
// \return void
// \exception std::runtime_error Minimum error detected.
//
// This function tests the evaluated matrix minimum with plain assignment, addition assignment,
// subtraction assignment, and Schur product assignment. In case any error resulting from the
// minimum operation or the subsequent assignment is detected, a \a std::runtime_error exception
// is thrown.
*/
template< typename MT1    // Type of the left-hand side dense matrix
        , typename MT2 >  // Type of the right-hand side dense matrix
void OperationTest<MT1,MT2>::testEvalOperation()
{
#if BLAZETEST_MATHTEST_TEST_EVAL_OPERATION
   if( BLAZETEST_MATHTEST_TEST_EVAL_OPERATION > 1 )
   {
      testCustomOperation( blaze::Eval(), "eval" );
   }
#endif
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Testing the serialized dense matrix/dense matrix minimum operation.
//
// \return void
// \exception std::runtime_error Minimum error detected.
//
// This function tests the serialized matrix minimum with plain assignment, addition assignment,
// subtraction assignment, and Schur product assignment. In case any error resulting from the
// minimum operation or the subsequent assignment is detected, a \a std::runtime_error exception
// is thrown.
*/
template< typename MT1    // Type of the left-hand side dense matrix
        , typename MT2 >  // Type of the right-hand side dense matrix
void OperationTest<MT1,MT2>::testSerialOperation()
{
#if BLAZETEST_MATHTEST_TEST_SERIAL_OPERATION
   if( BLAZETEST_MATHTEST_TEST_SERIAL_OPERATION > 1 )
   {
      testCustomOperation( blaze::Serial(), "serial" );
   }
#endif
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Testing the symmetric dense matrix/dense matrix minimum operation.
//
// \return void
// \exception std::runtime_error Minimum error detected.
//
// This function tests the symmetric matrix minimum with plain assignment, addition assignment,
// subtraction assignment, and Schur product assignment. In case any error resulting from the
// minimum operation or the subsequent assignment is detected, a \a std::runtime_error exception
// is thrown.
*/
template< typename MT1    // Type of the left-hand side dense matrix
        , typename MT2 >  // Type of the right-hand side dense matrix
void OperationTest<MT1,MT2>::testDeclSymOperation( blaze::TrueType )
{
#if BLAZETEST_MATHTEST_TEST_DECLSYM_OPERATION
   if( BLAZETEST_MATHTEST_TEST_DECLSYM_OPERATION > 1 )
   {
      if( ( !blaze::IsDiagonal<MT1>::value && blaze::IsTriangular<MT1>::value ) ||
          ( !blaze::IsDiagonal<MT2>::value && blaze::IsTriangular<MT2>::value ) ||
          ( !blaze::IsDiagonal<MT1>::value && blaze::IsHermitian<MT1>::value && blaze::IsComplex<ET1>::value ) ||
          ( !blaze::IsDiagonal<MT2>::value && blaze::IsHermitian<MT2>::value && blaze::IsComplex<ET2>::value ) ||
          ( lhs_.rows() != lhs_.columns() ) )
         return;


      //=====================================================================================
      // Test-specific setup of the left-hand side operand
      //=====================================================================================

      MT1  lhs ( lhs_ * trans( lhs_ ) );
      OMT1 olhs( lhs );


      //=====================================================================================
      // Test-specific setup of the right-hand side operand
      //=====================================================================================

      MT2  rhs ( rhs_ * trans( rhs_ ) );
      OMT2 orhs( rhs );


      //=====================================================================================
      // Test-specific setup of the reference matrix
      //=====================================================================================

      RT ref( min( lhs, rhs ) );


      //=====================================================================================
      // Declsym minimum
      //=====================================================================================

      // Declsym minimum with the given matrices
      {
         test_  = "Declsym minimum with the given matrices";
         error_ = "Failed minimum operation";

         try {
            initResults();
            dres_   = declsym( min( lhs, rhs ) );
            odres_  = declsym( min( lhs, rhs ) );
            sres_   = declsym( min( lhs, rhs ) );
            osres_  = declsym( min( lhs, rhs ) );
            refres_ = declsym( ref );
         }
         catch( std::exception& ex ) {
            convertException<MT1,MT2>( ex );
         }

         checkResults<MT1,MT2>();

         try {
            initResults();
            dres_   = declsym( min( lhs, orhs ) );
            odres_  = declsym( min( lhs, orhs ) );
            sres_   = declsym( min( lhs, orhs ) );
            osres_  = declsym( min( lhs, orhs ) );
            refres_ = declsym( ref );
         }
         catch( std::exception& ex ) {
            convertException<MT1,OMT2>( ex );
         }

         checkResults<MT1,OMT2>();

         try {
            initResults();
            dres_   = declsym( min( olhs, rhs ) );
            odres_  = declsym( min( olhs, rhs ) );
            sres_   = declsym( min( olhs, rhs ) );
            osres_  = declsym( min( olhs, rhs ) );
            refres_ = declsym( ref );
         }
         catch( std::exception& ex ) {
            convertException<OMT1,MT2>( ex );
         }

         checkResults<OMT1,MT2>();

         try {
            initResults();
            dres_   = declsym( min( olhs, orhs ) );
            odres_  = declsym( min( olhs, orhs ) );
            sres_   = declsym( min( olhs, orhs ) );
            osres_  = declsym( min( olhs, orhs ) );
            refres_ = declsym( ref );
         }
         catch( std::exception& ex ) {
            convertException<OMT1,OMT2>( ex );
         }

         checkResults<OMT1,OMT2>();
      }

      // Declsym minimum with evaluated matrices
      {
         test_  = "Declsym minimum with evaluated left-hand side matrix";
         error_ = "Failed minimum operation";

         try {
            initResults();
            dres_   = declsym( min( eval( lhs ), eval( rhs ) ) );
            odres_  = declsym( min( eval( lhs ), eval( rhs ) ) );
            sres_   = declsym( min( eval( lhs ), eval( rhs ) ) );
            osres_  = declsym( min( eval( lhs ), eval( rhs ) ) );
            refres_ = declsym( eval( ref_ ) );
         }
         catch( std::exception& ex ) {
            convertException<MT1,MT2>( ex );
         }

         checkResults<MT1,MT2>();

         try {
            initResults();
            dres_   = declsym( min( eval( lhs ), eval( orhs ) ) );
            odres_  = declsym( min( eval( lhs ), eval( orhs ) ) );
            sres_   = declsym( min( eval( lhs ), eval( orhs ) ) );
            osres_  = declsym( min( eval( lhs ), eval( orhs ) ) );
            refres_ = declsym( eval( ref_ ) );
         }
         catch( std::exception& ex ) {
            convertException<MT1,OMT2>( ex );
         }

         checkResults<MT1,OMT2>();

         try {
            initResults();
            dres_   = declsym( min( eval( olhs ), eval( rhs ) ) );
            odres_  = declsym( min( eval( olhs ), eval( rhs ) ) );
            sres_   = declsym( min( eval( olhs ), eval( rhs ) ) );
            osres_  = declsym( min( eval( olhs ), eval( rhs ) ) );
            refres_ = declsym( eval( ref_ ) );
         }
         catch( std::exception& ex ) {
            convertException<OMT1,MT2>( ex );
         }

         checkResults<OMT1,MT2>();

         try {
            initResults();
            dres_   = declsym( min( eval( olhs ), eval( orhs ) ) );
            odres_  = declsym( min( eval( olhs ), eval( orhs ) ) );
            sres_   = declsym( min( eval( olhs ), eval( orhs ) ) );
            osres_  = declsym( min( eval( olhs ), eval( orhs ) ) );
            refres_ = declsym( eval( ref_ ) );
         }
         catch( std::exception& ex ) {
            convertException<OMT1,OMT2>( ex );
         }

         checkResults<OMT1,OMT2>();
      }


      //=====================================================================================
      // Declsym minimum with addition assignment
      //=====================================================================================

      // Declsym minimum with addition assignment with the given matrices
      {
         test_  = "Declsym minimum with addition assignment with the given matrices";
         error_ = "Failed addition assignment operation";

         try {
            initResults();
            dres_   += declsym( min( lhs, rhs ) );
            odres_  += declsym( min( lhs, rhs ) );
            sres_   += declsym( min( lhs, rhs ) );
            osres_  += declsym( min( lhs, rhs ) );
            refres_ += declsym( ref );
         }
         catch( std::exception& ex ) {
            convertException<MT1,MT2>( ex );
         }

         checkResults<MT1,MT2>();

         try {
            initResults();
            dres_   += declsym( min( lhs, orhs ) );
            odres_  += declsym( min( lhs, orhs ) );
            sres_   += declsym( min( lhs, orhs ) );
            osres_  += declsym( min( lhs, orhs ) );
            refres_ += declsym( ref );
         }
         catch( std::exception& ex ) {
            convertException<MT1,OMT2>( ex );
         }

         checkResults<MT1,OMT2>();

         try {
            initResults();
            dres_   += declsym( min( olhs, rhs ) );
            odres_  += declsym( min( olhs, rhs ) );
            sres_   += declsym( min( olhs, rhs ) );
            osres_  += declsym( min( olhs, rhs ) );
            refres_ += declsym( ref );
         }
         catch( std::exception& ex ) {
            convertException<OMT1,MT2>( ex );
         }

         checkResults<OMT1,MT2>();

         try {
            initResults();
            dres_   += declsym( min( olhs, orhs ) );
            odres_  += declsym( min( olhs, orhs ) );
            sres_   += declsym( min( olhs, orhs ) );
            osres_  += declsym( min( olhs, orhs ) );
            refres_ += declsym( ref );
         }
         catch( std::exception& ex ) {
            convertException<OMT1,OMT2>( ex );
         }

         checkResults<OMT1,OMT2>();
      }

      // Declsym minimum with addition assignment with evaluated matrices
      {
         test_  = "Declsym minimum with addition assignment with evaluated matrices";
         error_ = "Failed addition assignment operation";

         try {
            initResults();
            dres_   += declsym( min( eval( lhs ), eval( rhs ) ) );
            odres_  += declsym( min( eval( lhs ), eval( rhs ) ) );
            sres_   += declsym( min( eval( lhs ), eval( rhs ) ) );
            osres_  += declsym( min( eval( lhs ), eval( rhs ) ) );
            refres_ += declsym( eval( ref_ ) );
         }
         catch( std::exception& ex ) {
            convertException<MT1,MT2>( ex );
         }

         checkResults<MT1,MT2>();

         try {
            initResults();
            dres_   += declsym( min( eval( lhs ), eval( orhs ) ) );
            odres_  += declsym( min( eval( lhs ), eval( orhs ) ) );
            sres_   += declsym( min( eval( lhs ), eval( orhs ) ) );
            osres_  += declsym( min( eval( lhs ), eval( orhs ) ) );
            refres_ += declsym( eval( ref_ ) );
         }
         catch( std::exception& ex ) {
            convertException<MT1,OMT2>( ex );
         }

         checkResults<MT1,OMT2>();

         try {
            initResults();
            dres_   += declsym( min( eval( olhs ), eval( rhs ) ) );
            odres_  += declsym( min( eval( olhs ), eval( rhs ) ) );
            sres_   += declsym( min( eval( olhs ), eval( rhs ) ) );
            osres_  += declsym( min( eval( olhs ), eval( rhs ) ) );
            refres_ += declsym( eval( ref_ ) );
         }
         catch( std::exception& ex ) {
            convertException<OMT1,MT2>( ex );
         }

         checkResults<OMT1,MT2>();

         try {
            initResults();
            dres_   += declsym( min( eval( olhs ), eval( orhs ) ) );
            odres_  += declsym( min( eval( olhs ), eval( orhs ) ) );
            sres_   += declsym( min( eval( olhs ), eval( orhs ) ) );
            osres_  += declsym( min( eval( olhs ), eval( orhs ) ) );
            refres_ += declsym( eval( ref_ ) );
         }
         catch( std::exception& ex ) {
            convertException<OMT1,OMT2>( ex );
         }

         checkResults<OMT1,OMT2>();
      }


      //=====================================================================================
      // Declsym minimum with subtraction assignment
      //=====================================================================================

      // Declsym minimum with subtraction assignment with the given matrices
      {
         test_  = "Declsym minimum with subtraction assignment with the given matrices";
         error_ = "Failed subtraction assignment operation";

         try {
            initResults();
            dres_   -= declsym( min( lhs, rhs ) );
            odres_  -= declsym( min( lhs, rhs ) );
            sres_   -= declsym( min( lhs, rhs ) );
            osres_  -= declsym( min( lhs, rhs ) );
            refres_ -= declsym( ref );
         }
         catch( std::exception& ex ) {
            convertException<MT1,MT2>( ex );
         }

         checkResults<MT1,MT2>();

         try {
            initResults();
            dres_   -= declsym( min( lhs, orhs ) );
            odres_  -= declsym( min( lhs, orhs ) );
            sres_   -= declsym( min( lhs, orhs ) );
            osres_  -= declsym( min( lhs, orhs ) );
            refres_ -= declsym( ref );
         }
         catch( std::exception& ex ) {
            convertException<MT1,OMT2>( ex );
         }

         checkResults<MT1,OMT2>();

         try {
            initResults();
            dres_   -= declsym( min( olhs, rhs ) );
            odres_  -= declsym( min( olhs, rhs ) );
            sres_   -= declsym( min( olhs, rhs ) );
            osres_  -= declsym( min( olhs, rhs ) );
            refres_ -= declsym( ref );
         }
         catch( std::exception& ex ) {
            convertException<OMT1,MT2>( ex );
         }

         checkResults<OMT1,MT2>();

         try {
            initResults();
            dres_   -= declsym( min( olhs, orhs ) );
            odres_  -= declsym( min( olhs, orhs ) );
            sres_   -= declsym( min( olhs, orhs ) );
            osres_  -= declsym( min( olhs, orhs ) );
            refres_ -= declsym( ref );
         }
         catch( std::exception& ex ) {
            convertException<OMT1,OMT2>( ex );
         }

         checkResults<OMT1,OMT2>();
      }

      // Declsym minimum with subtraction assignment with evaluated matrices
      {
         test_  = "Declsym minimum with subtraction assignment with evaluated matrices";
         error_ = "Failed subtraction assignment operation";

         try {
            initResults();
            dres_   -= declsym( min( eval( lhs ), eval( rhs ) ) );
            odres_  -= declsym( min( eval( lhs ), eval( rhs ) ) );
            sres_   -= declsym( min( eval( lhs ), eval( rhs ) ) );
            osres_  -= declsym( min( eval( lhs ), eval( rhs ) ) );
            refres_ -= declsym( eval( ref_ ) );
         }
         catch( std::exception& ex ) {
            convertException<MT1,MT2>( ex );
         }

         checkResults<MT1,MT2>();

         try {
            initResults();
            dres_   -= declsym( min( eval( lhs ), eval( orhs ) ) );
            odres_  -= declsym( min( eval( lhs ), eval( orhs ) ) );
            sres_   -= declsym( min( eval( lhs ), eval( orhs ) ) );
            osres_  -= declsym( min( eval( lhs ), eval( orhs ) ) );
            refres_ -= declsym( eval( ref_ ) );
         }
         catch( std::exception& ex ) {
            convertException<MT1,OMT2>( ex );
         }

         checkResults<MT1,OMT2>();

         try {
            initResults();
            dres_   -= declsym( min( eval( olhs ), eval( rhs ) ) );
            odres_  -= declsym( min( eval( olhs ), eval( rhs ) ) );
            sres_   -= declsym( min( eval( olhs ), eval( rhs ) ) );
            osres_  -= declsym( min( eval( olhs ), eval( rhs ) ) );
            refres_ -= declsym( eval( ref_ ) );
         }
         catch( std::exception& ex ) {
            convertException<OMT1,MT2>( ex );
         }

         checkResults<OMT1,MT2>();

         try {
            initResults();
            dres_   -= declsym( min( eval( olhs ), eval( orhs ) ) );
            odres_  -= declsym( min( eval( olhs ), eval( orhs ) ) );
            sres_   -= declsym( min( eval( olhs ), eval( orhs ) ) );
            osres_  -= declsym( min( eval( olhs ), eval( orhs ) ) );
            refres_ -= declsym( eval( ref_ ) );
         }
         catch( std::exception& ex ) {
            convertException<OMT1,OMT2>( ex );
         }

         checkResults<OMT1,OMT2>();
      }


      //=====================================================================================
      // Declsym minimum with Schur product assignment
      //=====================================================================================

      // Declsym minimum with Schur product assignment with the given matrices
      {
         test_  = "Declsym minimum with Schur product assignment with the given matrices";
         error_ = "Failed Schur product assignment operation";

         try {
            initResults();
            dres_   %= declsym( min( lhs, rhs ) );
            odres_  %= declsym( min( lhs, rhs ) );
            sres_   %= declsym( min( lhs, rhs ) );
            osres_  %= declsym( min( lhs, rhs ) );
            refres_ %= declsym( ref );
         }
         catch( std::exception& ex ) {
            convertException<MT1,MT2>( ex );
         }

         checkResults<MT1,MT2>();

         try {
            initResults();
            dres_   %= declsym( min( lhs, orhs ) );
            odres_  %= declsym( min( lhs, orhs ) );
            sres_   %= declsym( min( lhs, orhs ) );
            osres_  %= declsym( min( lhs, orhs ) );
            refres_ %= declsym( ref );
         }
         catch( std::exception& ex ) {
            convertException<MT1,OMT2>( ex );
         }

         checkResults<MT1,OMT2>();

         try {
            initResults();
            dres_   %= declsym( min( olhs, rhs ) );
            odres_  %= declsym( min( olhs, rhs ) );
            sres_   %= declsym( min( olhs, rhs ) );
            osres_  %= declsym( min( olhs, rhs ) );
            refres_ %= declsym( ref );
         }
         catch( std::exception& ex ) {
            convertException<OMT1,MT2>( ex );
         }

         checkResults<OMT1,MT2>();

         try {
            initResults();
            dres_   %= declsym( min( olhs, orhs ) );
            odres_  %= declsym( min( olhs, orhs ) );
            sres_   %= declsym( min( olhs, orhs ) );
            osres_  %= declsym( min( olhs, orhs ) );
            refres_ %= declsym( ref );
         }
         catch( std::exception& ex ) {
            convertException<OMT1,OMT2>( ex );
         }

         checkResults<OMT1,OMT2>();
      }

      // Declsym minimum with Schur product assignment with evaluated matrices
      {
         test_  = "Declsym minimum with Schur product assignment with evaluated matrices";
         error_ = "Failed Schur product assignment operation";

         try {
            initResults();
            dres_   %= declsym( min( eval( lhs ), eval( rhs ) ) );
            odres_  %= declsym( min( eval( lhs ), eval( rhs ) ) );
            sres_   %= declsym( min( eval( lhs ), eval( rhs ) ) );
            osres_  %= declsym( min( eval( lhs ), eval( rhs ) ) );
            refres_ %= declsym( eval( ref_ ) );
         }
         catch( std::exception& ex ) {
            convertException<MT1,MT2>( ex );
         }

         checkResults<MT1,MT2>();

         try {
            initResults();
            dres_   %= declsym( min( eval( lhs ), eval( orhs ) ) );
            odres_  %= declsym( min( eval( lhs ), eval( orhs ) ) );
            sres_   %= declsym( min( eval( lhs ), eval( orhs ) ) );
            osres_  %= declsym( min( eval( lhs ), eval( orhs ) ) );
            refres_ %= declsym( eval( ref_ ) );
         }
         catch( std::exception& ex ) {
            convertException<MT1,OMT2>( ex );
         }

         checkResults<MT1,OMT2>();

         try {
            initResults();
            dres_   %= declsym( min( eval( olhs ), eval( rhs ) ) );
            odres_  %= declsym( min( eval( olhs ), eval( rhs ) ) );
            sres_   %= declsym( min( eval( olhs ), eval( rhs ) ) );
            osres_  %= declsym( min( eval( olhs ), eval( rhs ) ) );
            refres_ %= declsym( eval( ref_ ) );
         }
         catch( std::exception& ex ) {
            convertException<OMT1,MT2>( ex );
         }

         checkResults<OMT1,MT2>();

         try {
            initResults();
            dres_   %= declsym( min( eval( olhs ), eval( orhs ) ) );
            odres_  %= declsym( min( eval( olhs ), eval( orhs ) ) );
            sres_   %= declsym( min( eval( olhs ), eval( orhs ) ) );
            osres_  %= declsym( min( eval( olhs ), eval( orhs ) ) );
            refres_ %= declsym( eval( ref_ ) );
         }
         catch( std::exception& ex ) {
            convertException<OMT1,OMT2>( ex );
         }

         checkResults<OMT1,OMT2>();
      }
   }
#endif
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Skipping the symmetric dense matrix/dense matrix minimum operation.
//
// \return void
//
// This function is called in case the symmetric matrix/matrix minimum operation is not
// available for the given matrix types \a MT1 and \a MT2.
*/
template< typename MT1    // Type of the left-hand side dense matrix
        , typename MT2 >  // Type of the right-hand side dense matrix
void OperationTest<MT1,MT2>::testDeclSymOperation( blaze::FalseType )
{}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Testing the Hermitian dense matrix/dense matrix minimum operation.
//
// \return void
// \exception std::runtime_error Minimum error detected.
//
// This function tests the Hermitian matrix minimum with plain assignment, addition assignment,
// subtraction assignment, and Schur product assignment. In case any error resulting from the
// minimum operation or the subsequent assignment is detected, a \a std::runtime_error exception
// is thrown.
*/
template< typename MT1    // Type of the left-hand side dense matrix
        , typename MT2 >  // Type of the right-hand side dense matrix
void OperationTest<MT1,MT2>::testDeclHermOperation( blaze::TrueType )
{
#if BLAZETEST_MATHTEST_TEST_DECLHERM_OPERATION
   if( BLAZETEST_MATHTEST_TEST_DECLHERM_OPERATION > 1 )
   {
      if( ( !blaze::IsDiagonal<MT1>::value && blaze::IsTriangular<MT1>::value ) ||
          ( !blaze::IsDiagonal<MT2>::value && blaze::IsTriangular<MT2>::value ) ||
          ( !blaze::IsDiagonal<MT1>::value && blaze::IsSymmetric<MT1>::value && blaze::IsComplex<ET1>::value ) ||
          ( !blaze::IsDiagonal<MT2>::value && blaze::IsSymmetric<MT2>::value && blaze::IsComplex<ET2>::value ) ||
          ( lhs_.rows() != lhs_.columns() ) )
         return;


      //=====================================================================================
      // Test-specific setup of the left-hand side operand
      //=====================================================================================

      MT1  lhs ( lhs_ * ctrans( lhs_ ) );
      OMT1 olhs( lhs );


      //=====================================================================================
      // Test-specific setup of the right-hand side operand
      //=====================================================================================

      MT2  rhs ( rhs_ * ctrans( rhs_ ) );
      OMT2 orhs( rhs );


      //=====================================================================================
      // Test-specific setup of the reference matrix
      //=====================================================================================

      RT ref( min( lhs, rhs ) );


      //=====================================================================================
      // Declherm minimum
      //=====================================================================================

      // Declherm minimum with the given matrices
      {
         test_  = "Declherm minimum with the given matrices";
         error_ = "Failed minimum operation";

         try {
            initResults();
            dres_   = declherm( min( lhs, rhs ) );
            odres_  = declherm( min( lhs, rhs ) );
            sres_   = declherm( min( lhs, rhs ) );
            osres_  = declherm( min( lhs, rhs ) );
            refres_ = declherm( ref );
         }
         catch( std::exception& ex ) {
            convertException<MT1,MT2>( ex );
         }

         checkResults<MT1,MT2>();

         try {
            initResults();
            dres_   = declherm( min( lhs, orhs ) );
            odres_  = declherm( min( lhs, orhs ) );
            sres_   = declherm( min( lhs, orhs ) );
            osres_  = declherm( min( lhs, orhs ) );
            refres_ = declherm( ref );
         }
         catch( std::exception& ex ) {
            convertException<MT1,OMT2>( ex );
         }

         checkResults<MT1,OMT2>();

         try {
            initResults();
            dres_   = declherm( min( olhs, rhs ) );
            odres_  = declherm( min( olhs, rhs ) );
            sres_   = declherm( min( olhs, rhs ) );
            osres_  = declherm( min( olhs, rhs ) );
            refres_ = declherm( ref );
         }
         catch( std::exception& ex ) {
            convertException<OMT1,MT2>( ex );
         }

         checkResults<OMT1,MT2>();

         try {
            initResults();
            dres_   = declherm( min( olhs, orhs ) );
            odres_  = declherm( min( olhs, orhs ) );
            sres_   = declherm( min( olhs, orhs ) );
            osres_  = declherm( min( olhs, orhs ) );
            refres_ = declherm( ref );
         }
         catch( std::exception& ex ) {
            convertException<OMT1,OMT2>( ex );
         }

         checkResults<OMT1,OMT2>();
      }

      // Declherm minimum with evaluated matrices
      {
         test_  = "Declherm minimum with evaluated left-hand side matrix";
         error_ = "Failed minimum operation";

         try {
            initResults();
            dres_   = declherm( min( eval( lhs ), eval( rhs ) ) );
            odres_  = declherm( min( eval( lhs ), eval( rhs ) ) );
            sres_   = declherm( min( eval( lhs ), eval( rhs ) ) );
            osres_  = declherm( min( eval( lhs ), eval( rhs ) ) );
            refres_ = declherm( eval( ref_ ) );
         }
         catch( std::exception& ex ) {
            convertException<MT1,MT2>( ex );
         }

         checkResults<MT1,MT2>();

         try {
            initResults();
            dres_   = declherm( min( eval( lhs ), eval( orhs ) ) );
            odres_  = declherm( min( eval( lhs ), eval( orhs ) ) );
            sres_   = declherm( min( eval( lhs ), eval( orhs ) ) );
            osres_  = declherm( min( eval( lhs ), eval( orhs ) ) );
            refres_ = declherm( eval( ref_ ) );
         }
         catch( std::exception& ex ) {
            convertException<MT1,OMT2>( ex );
         }

         checkResults<MT1,OMT2>();

         try {
            initResults();
            dres_   = declherm( min( eval( olhs ), eval( rhs ) ) );
            odres_  = declherm( min( eval( olhs ), eval( rhs ) ) );
            sres_   = declherm( min( eval( olhs ), eval( rhs ) ) );
            osres_  = declherm( min( eval( olhs ), eval( rhs ) ) );
            refres_ = declherm( eval( ref_ ) );
         }
         catch( std::exception& ex ) {
            convertException<OMT1,MT2>( ex );
         }

         checkResults<OMT1,MT2>();

         try {
            initResults();
            dres_   = declherm( min( eval( olhs ), eval( orhs ) ) );
            odres_  = declherm( min( eval( olhs ), eval( orhs ) ) );
            sres_   = declherm( min( eval( olhs ), eval( orhs ) ) );
            osres_  = declherm( min( eval( olhs ), eval( orhs ) ) );
            refres_ = declherm( eval( ref_ ) );
         }
         catch( std::exception& ex ) {
            convertException<OMT1,OMT2>( ex );
         }

         checkResults<OMT1,OMT2>();
      }


      //=====================================================================================
      // Declherm minimum with addition assignment
      //=====================================================================================

      // Declherm minimum with addition assignment with the given matrices
      {
         test_  = "Declherm minimum with addition assignment with the given matrices";
         error_ = "Failed addition assignment operation";

         try {
            initResults();
            dres_   += declherm( min( lhs, rhs ) );
            odres_  += declherm( min( lhs, rhs ) );
            sres_   += declherm( min( lhs, rhs ) );
            osres_  += declherm( min( lhs, rhs ) );
            refres_ += declherm( ref );
         }
         catch( std::exception& ex ) {
            convertException<MT1,MT2>( ex );
         }

         checkResults<MT1,MT2>();

         try {
            initResults();
            dres_   += declherm( min( lhs, orhs ) );
            odres_  += declherm( min( lhs, orhs ) );
            sres_   += declherm( min( lhs, orhs ) );
            osres_  += declherm( min( lhs, orhs ) );
            refres_ += declherm( ref );
         }
         catch( std::exception& ex ) {
            convertException<MT1,OMT2>( ex );
         }

         checkResults<MT1,OMT2>();

         try {
            initResults();
            dres_   += declherm( min( olhs, rhs ) );
            odres_  += declherm( min( olhs, rhs ) );
            sres_   += declherm( min( olhs, rhs ) );
            osres_  += declherm( min( olhs, rhs ) );
            refres_ += declherm( ref );
         }
         catch( std::exception& ex ) {
            convertException<OMT1,MT2>( ex );
         }

         checkResults<OMT1,MT2>();

         try {
            initResults();
            dres_   += declherm( min( olhs, orhs ) );
            odres_  += declherm( min( olhs, orhs ) );
            sres_   += declherm( min( olhs, orhs ) );
            osres_  += declherm( min( olhs, orhs ) );
            refres_ += declherm( ref );
         }
         catch( std::exception& ex ) {
            convertException<OMT1,OMT2>( ex );
         }

         checkResults<OMT1,OMT2>();
      }

      // Declherm minimum with addition assignment with evaluated matrices
      {
         test_  = "Declherm minimum with addition assignment with evaluated matrices";
         error_ = "Failed addition assignment operation";

         try {
            initResults();
            dres_   += declherm( min( eval( lhs ), eval( rhs ) ) );
            odres_  += declherm( min( eval( lhs ), eval( rhs ) ) );
            sres_   += declherm( min( eval( lhs ), eval( rhs ) ) );
            osres_  += declherm( min( eval( lhs ), eval( rhs ) ) );
            refres_ += declherm( eval( ref_ ) );
         }
         catch( std::exception& ex ) {
            convertException<MT1,MT2>( ex );
         }

         checkResults<MT1,MT2>();

         try {
            initResults();
            dres_   += declherm( min( eval( lhs ), eval( orhs ) ) );
            odres_  += declherm( min( eval( lhs ), eval( orhs ) ) );
            sres_   += declherm( min( eval( lhs ), eval( orhs ) ) );
            osres_  += declherm( min( eval( lhs ), eval( orhs ) ) );
            refres_ += declherm( eval( ref_ ) );
         }
         catch( std::exception& ex ) {
            convertException<MT1,OMT2>( ex );
         }

         checkResults<MT1,OMT2>();

         try {
            initResults();
            dres_   += declherm( min( eval( olhs ), eval( rhs ) ) );
            odres_  += declherm( min( eval( olhs ), eval( rhs ) ) );
            sres_   += declherm( min( eval( olhs ), eval( rhs ) ) );
            osres_  += declherm( min( eval( olhs ), eval( rhs ) ) );
            refres_ += declherm( eval( ref_ ) );
         }
         catch( std::exception& ex ) {
            convertException<OMT1,MT2>( ex );
         }

         checkResults<OMT1,MT2>();

         try {
            initResults();
            dres_   += declherm( min( eval( olhs ), eval( orhs ) ) );
            odres_  += declherm( min( eval( olhs ), eval( orhs ) ) );
            sres_   += declherm( min( eval( olhs ), eval( orhs ) ) );
            osres_  += declherm( min( eval( olhs ), eval( orhs ) ) );
            refres_ += declherm( eval( ref_ ) );
         }
         catch( std::exception& ex ) {
            convertException<OMT1,OMT2>( ex );
         }

         checkResults<OMT1,OMT2>();
      }


      //=====================================================================================
      // Declherm minimum with subtraction assignment
      //=====================================================================================

      // Declherm minimum with subtraction assignment with the given matrices
      {
         test_  = "Declherm minimum with subtraction assignment with the given matrices";
         error_ = "Failed subtraction assignment operation";

         try {
            initResults();
            dres_   -= declherm( min( lhs, rhs ) );
            odres_  -= declherm( min( lhs, rhs ) );
            sres_   -= declherm( min( lhs, rhs ) );
            osres_  -= declherm( min( lhs, rhs ) );
            refres_ -= declherm( ref );
         }
         catch( std::exception& ex ) {
            convertException<MT1,MT2>( ex );
         }

         checkResults<MT1,MT2>();

         try {
            initResults();
            dres_   -= declherm( min( lhs, orhs ) );
            odres_  -= declherm( min( lhs, orhs ) );
            sres_   -= declherm( min( lhs, orhs ) );
            osres_  -= declherm( min( lhs, orhs ) );
            refres_ -= declherm( ref );
         }
         catch( std::exception& ex ) {
            convertException<MT1,OMT2>( ex );
         }

         checkResults<MT1,OMT2>();

         try {
            initResults();
            dres_   -= declherm( min( olhs, rhs ) );
            odres_  -= declherm( min( olhs, rhs ) );
            sres_   -= declherm( min( olhs, rhs ) );
            osres_  -= declherm( min( olhs, rhs ) );
            refres_ -= declherm( ref );
         }
         catch( std::exception& ex ) {
            convertException<OMT1,MT2>( ex );
         }

         checkResults<OMT1,MT2>();

         try {
            initResults();
            dres_   -= declherm( min( olhs, orhs ) );
            odres_  -= declherm( min( olhs, orhs ) );
            sres_   -= declherm( min( olhs, orhs ) );
            osres_  -= declherm( min( olhs, orhs ) );
            refres_ -= declherm( ref );
         }
         catch( std::exception& ex ) {
            convertException<OMT1,OMT2>( ex );
         }

         checkResults<OMT1,OMT2>();
      }

      // Declherm minimum with subtraction assignment with evaluated matrices
      {
         test_  = "Declherm minimum with subtraction assignment with evaluated matrices";
         error_ = "Failed subtraction assignment operation";

         try {
            initResults();
            dres_   -= declherm( min( eval( lhs ), eval( rhs ) ) );
            odres_  -= declherm( min( eval( lhs ), eval( rhs ) ) );
            sres_   -= declherm( min( eval( lhs ), eval( rhs ) ) );
            osres_  -= declherm( min( eval( lhs ), eval( rhs ) ) );
            refres_ -= declherm( eval( ref_ ) );
         }
         catch( std::exception& ex ) {
            convertException<MT1,MT2>( ex );
         }

         checkResults<MT1,MT2>();

         try {
            initResults();
            dres_   -= declherm( min( eval( lhs ), eval( orhs ) ) );
            odres_  -= declherm( min( eval( lhs ), eval( orhs ) ) );
            sres_   -= declherm( min( eval( lhs ), eval( orhs ) ) );
            osres_  -= declherm( min( eval( lhs ), eval( orhs ) ) );
            refres_ -= declherm( eval( ref_ ) );
         }
         catch( std::exception& ex ) {
            convertException<MT1,OMT2>( ex );
         }

         checkResults<MT1,OMT2>();

         try {
            initResults();
            dres_   -= declherm( min( eval( olhs ), eval( rhs ) ) );
            odres_  -= declherm( min( eval( olhs ), eval( rhs ) ) );
            sres_   -= declherm( min( eval( olhs ), eval( rhs ) ) );
            osres_  -= declherm( min( eval( olhs ), eval( rhs ) ) );
            refres_ -= declherm( eval( ref_ ) );
         }
         catch( std::exception& ex ) {
            convertException<OMT1,MT2>( ex );
         }

         checkResults<OMT1,MT2>();

         try {
            initResults();
            dres_   -= declherm( min( eval( olhs ), eval( orhs ) ) );
            odres_  -= declherm( min( eval( olhs ), eval( orhs ) ) );
            sres_   -= declherm( min( eval( olhs ), eval( orhs ) ) );
            osres_  -= declherm( min( eval( olhs ), eval( orhs ) ) );
            refres_ -= declherm( eval( ref_ ) );
         }
         catch( std::exception& ex ) {
            convertException<OMT1,OMT2>( ex );
         }

         checkResults<OMT1,OMT2>();
      }


      //=====================================================================================
      // Declherm minimum with Schur product assignment
      //=====================================================================================

      // Declherm minimum with Schur product assignment with the given matrices
      {
         test_  = "Declherm minimum with Schur product assignment with the given matrices";
         error_ = "Failed Schur product assignment operation";

         try {
            initResults();
            dres_   %= declherm( min( lhs, rhs ) );
            odres_  %= declherm( min( lhs, rhs ) );
            sres_   %= declherm( min( lhs, rhs ) );
            osres_  %= declherm( min( lhs, rhs ) );
            refres_ %= declherm( ref );
         }
         catch( std::exception& ex ) {
            convertException<MT1,MT2>( ex );
         }

         checkResults<MT1,MT2>();

         try {
            initResults();
            dres_   %= declherm( min( lhs, orhs ) );
            odres_  %= declherm( min( lhs, orhs ) );
            sres_   %= declherm( min( lhs, orhs ) );
            osres_  %= declherm( min( lhs, orhs ) );
            refres_ %= declherm( ref );
         }
         catch( std::exception& ex ) {
            convertException<MT1,OMT2>( ex );
         }

         checkResults<MT1,OMT2>();

         try {
            initResults();
            dres_   %= declherm( min( olhs, rhs ) );
            odres_  %= declherm( min( olhs, rhs ) );
            sres_   %= declherm( min( olhs, rhs ) );
            osres_  %= declherm( min( olhs, rhs ) );
            refres_ %= declherm( ref );
         }
         catch( std::exception& ex ) {
            convertException<OMT1,MT2>( ex );
         }

         checkResults<OMT1,MT2>();

         try {
            initResults();
            dres_   %= declherm( min( olhs, orhs ) );
            odres_  %= declherm( min( olhs, orhs ) );
            sres_   %= declherm( min( olhs, orhs ) );
            osres_  %= declherm( min( olhs, orhs ) );
            refres_ %= declherm( ref );
         }
         catch( std::exception& ex ) {
            convertException<OMT1,OMT2>( ex );
         }

         checkResults<OMT1,OMT2>();
      }

      // Declherm minimum with Schur product assignment with evaluated matrices
      {
         test_  = "Declherm minimum with Schur product assignment with evaluated matrices";
         error_ = "Failed Schur product assignment operation";

         try {
            initResults();
            dres_   %= declherm( min( eval( lhs ), eval( rhs ) ) );
            odres_  %= declherm( min( eval( lhs ), eval( rhs ) ) );
            sres_   %= declherm( min( eval( lhs ), eval( rhs ) ) );
            osres_  %= declherm( min( eval( lhs ), eval( rhs ) ) );
            refres_ %= declherm( eval( ref_ ) );
         }
         catch( std::exception& ex ) {
            convertException<MT1,MT2>( ex );
         }

         checkResults<MT1,MT2>();

         try {
            initResults();
            dres_   %= declherm( min( eval( lhs ), eval( orhs ) ) );
            odres_  %= declherm( min( eval( lhs ), eval( orhs ) ) );
            sres_   %= declherm( min( eval( lhs ), eval( orhs ) ) );
            osres_  %= declherm( min( eval( lhs ), eval( orhs ) ) );
            refres_ %= declherm( eval( ref_ ) );
         }
         catch( std::exception& ex ) {
            convertException<MT1,OMT2>( ex );
         }

         checkResults<MT1,OMT2>();

         try {
            initResults();
            dres_   %= declherm( min( eval( olhs ), eval( rhs ) ) );
            odres_  %= declherm( min( eval( olhs ), eval( rhs ) ) );
            sres_   %= declherm( min( eval( olhs ), eval( rhs ) ) );
            osres_  %= declherm( min( eval( olhs ), eval( rhs ) ) );
            refres_ %= declherm( eval( ref_ ) );
         }
         catch( std::exception& ex ) {
            convertException<OMT1,MT2>( ex );
         }

         checkResults<OMT1,MT2>();

         try {
            initResults();
            dres_   %= declherm( min( eval( olhs ), eval( orhs ) ) );
            odres_  %= declherm( min( eval( olhs ), eval( orhs ) ) );
            sres_   %= declherm( min( eval( olhs ), eval( orhs ) ) );
            osres_  %= declherm( min( eval( olhs ), eval( orhs ) ) );
            refres_ %= declherm( eval( ref_ ) );
         }
         catch( std::exception& ex ) {
            convertException<OMT1,OMT2>( ex );
         }

         checkResults<OMT1,OMT2>();
      }
   }
#endif
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Skipping the Hermitian dense matrix/dense matrix minimum operation.
//
// \return void
//
// This function is called in case the Hermitian matrix/matrix minimum operation is not
// available for the given matrix types \a MT1 and \a MT2.
*/
template< typename MT1    // Type of the left-hand side dense matrix
        , typename MT2 >  // Type of the right-hand side dense matrix
void OperationTest<MT1,MT2>::testDeclHermOperation( blaze::FalseType )
{}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Testing the lower dense matrix/dense matrix minimum operation.
//
// \return void
// \exception std::runtime_error Minimum error detected.
//
// This function tests the lower matrix minimum with plain assignment, addition assignment,
// and subtraction assignment. In case any error resulting from the minimum operation or the
// subsequent assignment is detected, a \a std::runtime_error exception is thrown.
*/
template< typename MT1    // Type of the left-hand side dense matrix
        , typename MT2 >  // Type of the right-hand side dense matrix
void OperationTest<MT1,MT2>::testDeclLowOperation( blaze::TrueType )
{
#if BLAZETEST_MATHTEST_TEST_DECLLOW_OPERATION
   if( BLAZETEST_MATHTEST_TEST_DECLLOW_OPERATION > 1 )
   {
      if( lhs_.rows() != lhs_.columns() )
         return;


      //=====================================================================================
      // Test-specific setup of the left-hand side operand
      //=====================================================================================

      MT1 lhs( lhs_ );

      blaze::resetUpper( lhs );

      OMT1 olhs( lhs );


      //=====================================================================================
      // Test-specific setup of the right-hand side operand
      //=====================================================================================

      MT2 rhs( rhs_ );

      blaze::resetUpper( rhs );

      OMT2 orhs( rhs );


      //=====================================================================================
      // Test-specific setup of the reference matrix
      //=====================================================================================

      RT ref( min( lhs, rhs ) );


      //=====================================================================================
      // Decllow minimum
      //=====================================================================================

      // Decllow minimum with the given matrices
      {
         test_  = "Decllow minimum with the given matrices";
         error_ = "Failed minimum operation";

         try {
            initResults();
            dres_   = decllow( min( lhs, rhs ) );
            odres_  = decllow( min( lhs, rhs ) );
            sres_   = decllow( min( lhs, rhs ) );
            osres_  = decllow( min( lhs, rhs ) );
            refres_ = decllow( ref );
         }
         catch( std::exception& ex ) {
            convertException<MT1,MT2>( ex );
         }

         checkResults<MT1,MT2>();

         try {
            initResults();
            dres_   = decllow( min( lhs, orhs ) );
            odres_  = decllow( min( lhs, orhs ) );
            sres_   = decllow( min( lhs, orhs ) );
            osres_  = decllow( min( lhs, orhs ) );
            refres_ = decllow( ref );
         }
         catch( std::exception& ex ) {
            convertException<MT1,OMT2>( ex );
         }

         checkResults<MT1,OMT2>();

         try {
            initResults();
            dres_   = decllow( min( olhs, rhs ) );
            odres_  = decllow( min( olhs, rhs ) );
            sres_   = decllow( min( olhs, rhs ) );
            osres_  = decllow( min( olhs, rhs ) );
            refres_ = decllow( ref );
         }
         catch( std::exception& ex ) {
            convertException<OMT1,MT2>( ex );
         }

         checkResults<OMT1,MT2>();

         try {
            initResults();
            dres_   = decllow( min( olhs, orhs ) );
            odres_  = decllow( min( olhs, orhs ) );
            sres_   = decllow( min( olhs, orhs ) );
            osres_  = decllow( min( olhs, orhs ) );
            refres_ = decllow( ref );
         }
         catch( std::exception& ex ) {
            convertException<OMT1,OMT2>( ex );
         }

         checkResults<OMT1,OMT2>();
      }

      // Decllow minimum with evaluated matrices
      {
         test_  = "Decllow minimum with evaluated left-hand side matrix";
         error_ = "Failed minimum operation";

         try {
            initResults();
            dres_   = decllow( min( eval( lhs ), eval( rhs ) ) );
            odres_  = decllow( min( eval( lhs ), eval( rhs ) ) );
            sres_   = decllow( min( eval( lhs ), eval( rhs ) ) );
            osres_  = decllow( min( eval( lhs ), eval( rhs ) ) );
            refres_ = decllow( eval( ref ) );
         }
         catch( std::exception& ex ) {
            convertException<MT1,MT2>( ex );
         }

         checkResults<MT1,MT2>();

         try {
            initResults();
            dres_   = decllow( min( eval( lhs ), eval( orhs ) ) );
            odres_  = decllow( min( eval( lhs ), eval( orhs ) ) );
            sres_   = decllow( min( eval( lhs ), eval( orhs ) ) );
            osres_  = decllow( min( eval( lhs ), eval( orhs ) ) );
            refres_ = decllow( eval( ref ) );
         }
         catch( std::exception& ex ) {
            convertException<MT1,OMT2>( ex );
         }

         checkResults<MT1,OMT2>();

         try {
            initResults();
            dres_   = decllow( min( eval( olhs ), eval( rhs ) ) );
            odres_  = decllow( min( eval( olhs ), eval( rhs ) ) );
            sres_   = decllow( min( eval( olhs ), eval( rhs ) ) );
            osres_  = decllow( min( eval( olhs ), eval( rhs ) ) );
            refres_ = decllow( eval( ref ) );
         }
         catch( std::exception& ex ) {
            convertException<OMT1,MT2>( ex );
         }

         checkResults<OMT1,MT2>();

         try {
            initResults();
            dres_   = decllow( min( eval( olhs ), eval( orhs ) ) );
            odres_  = decllow( min( eval( olhs ), eval( orhs ) ) );
            sres_   = decllow( min( eval( olhs ), eval( orhs ) ) );
            osres_  = decllow( min( eval( olhs ), eval( orhs ) ) );
            refres_ = decllow( eval( ref ) );
         }
         catch( std::exception& ex ) {
            convertException<OMT1,OMT2>( ex );
         }

         checkResults<OMT1,OMT2>();
      }


      //=====================================================================================
      // Decllow minimum with addition assignment
      //=====================================================================================

      // Decllow minimum with addition assignment with the given matrices
      {
         test_  = "Decllow minimum with addition assignment with the given matrices";
         error_ = "Failed addition assignment operation";

         try {
            initResults();
            dres_   += decllow( min( lhs, rhs ) );
            odres_  += decllow( min( lhs, rhs ) );
            sres_   += decllow( min( lhs, rhs ) );
            osres_  += decllow( min( lhs, rhs ) );
            refres_ += decllow( ref );
         }
         catch( std::exception& ex ) {
            convertException<MT1,MT2>( ex );
         }

         checkResults<MT1,MT2>();

         try {
            initResults();
            dres_   += decllow( min( lhs, orhs ) );
            odres_  += decllow( min( lhs, orhs ) );
            sres_   += decllow( min( lhs, orhs ) );
            osres_  += decllow( min( lhs, orhs ) );
            refres_ += decllow( ref );
         }
         catch( std::exception& ex ) {
            convertException<MT1,OMT2>( ex );
         }

         checkResults<MT1,OMT2>();

         try {
            initResults();
            dres_   += decllow( min( olhs, rhs ) );
            odres_  += decllow( min( olhs, rhs ) );
            sres_   += decllow( min( olhs, rhs ) );
            osres_  += decllow( min( olhs, rhs ) );
            refres_ += decllow( ref );
         }
         catch( std::exception& ex ) {
            convertException<OMT1,MT2>( ex );
         }

         checkResults<OMT1,MT2>();

         try {
            initResults();
            dres_   += decllow( min( olhs, orhs ) );
            odres_  += decllow( min( olhs, orhs ) );
            sres_   += decllow( min( olhs, orhs ) );
            osres_  += decllow( min( olhs, orhs ) );
            refres_ += decllow( ref );
         }
         catch( std::exception& ex ) {
            convertException<OMT1,OMT2>( ex );
         }

         checkResults<OMT1,OMT2>();
      }

      // Decllow minimum with addition assignment with evaluated matrices
      {
         test_  = "Decllow minimum with addition assignment with evaluated matrices";
         error_ = "Failed addition assignment operation";

         try {
            initResults();
            dres_   += decllow( min( eval( lhs ), eval( rhs ) ) );
            odres_  += decllow( min( eval( lhs ), eval( rhs ) ) );
            sres_   += decllow( min( eval( lhs ), eval( rhs ) ) );
            osres_  += decllow( min( eval( lhs ), eval( rhs ) ) );
            refres_ += decllow( eval( ref ) );
         }
         catch( std::exception& ex ) {
            convertException<MT1,MT2>( ex );
         }

         checkResults<MT1,MT2>();

         try {
            initResults();
            dres_   += decllow( min( eval( lhs ), eval( orhs ) ) );
            odres_  += decllow( min( eval( lhs ), eval( orhs ) ) );
            sres_   += decllow( min( eval( lhs ), eval( orhs ) ) );
            osres_  += decllow( min( eval( lhs ), eval( orhs ) ) );
            refres_ += decllow( eval( ref ) );
         }
         catch( std::exception& ex ) {
            convertException<MT1,OMT2>( ex );
         }

         checkResults<MT1,OMT2>();

         try {
            initResults();
            dres_   += decllow( min( eval( olhs ), eval( rhs ) ) );
            odres_  += decllow( min( eval( olhs ), eval( rhs ) ) );
            sres_   += decllow( min( eval( olhs ), eval( rhs ) ) );
            osres_  += decllow( min( eval( olhs ), eval( rhs ) ) );
            refres_ += decllow( eval( ref ) );
         }
         catch( std::exception& ex ) {
            convertException<OMT1,MT2>( ex );
         }

         checkResults<OMT1,MT2>();

         try {
            initResults();
            dres_   += decllow( min( eval( olhs ), eval( orhs ) ) );
            odres_  += decllow( min( eval( olhs ), eval( orhs ) ) );
            sres_   += decllow( min( eval( olhs ), eval( orhs ) ) );
            osres_  += decllow( min( eval( olhs ), eval( orhs ) ) );
            refres_ += decllow( eval( ref ) );
         }
         catch( std::exception& ex ) {
            convertException<OMT1,OMT2>( ex );
         }

         checkResults<OMT1,OMT2>();
      }


      //=====================================================================================
      // Decllow minimum with subtraction assignment
      //=====================================================================================

      // Decllow minimum with subtraction assignment with the given matrices
      {
         test_  = "Decllow minimum with subtraction assignment with the given matrices";
         error_ = "Failed subtraction assignment operation";

         try {
            initResults();
            dres_   -= decllow( min( lhs, rhs ) );
            odres_  -= decllow( min( lhs, rhs ) );
            sres_   -= decllow( min( lhs, rhs ) );
            osres_  -= decllow( min( lhs, rhs ) );
            refres_ -= decllow( ref );
         }
         catch( std::exception& ex ) {
            convertException<MT1,MT2>( ex );
         }

         checkResults<MT1,MT2>();

         try {
            initResults();
            dres_   -= decllow( min( lhs, orhs ) );
            odres_  -= decllow( min( lhs, orhs ) );
            sres_   -= decllow( min( lhs, orhs ) );
            osres_  -= decllow( min( lhs, orhs ) );
            refres_ -= decllow( ref );
         }
         catch( std::exception& ex ) {
            convertException<MT1,OMT2>( ex );
         }

         checkResults<MT1,OMT2>();

         try {
            initResults();
            dres_   -= decllow( min( olhs, rhs ) );
            odres_  -= decllow( min( olhs, rhs ) );
            sres_   -= decllow( min( olhs, rhs ) );
            osres_  -= decllow( min( olhs, rhs ) );
            refres_ -= decllow( ref );
         }
         catch( std::exception& ex ) {
            convertException<OMT1,MT2>( ex );
         }

         checkResults<OMT1,MT2>();

         try {
            initResults();
            dres_   -= decllow( min( olhs, orhs ) );
            odres_  -= decllow( min( olhs, orhs ) );
            sres_   -= decllow( min( olhs, orhs ) );
            osres_  -= decllow( min( olhs, orhs ) );
            refres_ -= decllow( ref );
         }
         catch( std::exception& ex ) {
            convertException<OMT1,OMT2>( ex );
         }

         checkResults<OMT1,OMT2>();
      }

      // Decllow minimum with subtraction assignment with evaluated matrices
      {
         test_  = "Decllow minimum with subtraction assignment with evaluated matrices";
         error_ = "Failed subtraction assignment operation";

         try {
            initResults();
            dres_   -= decllow( min( eval( lhs ), eval( rhs ) ) );
            odres_  -= decllow( min( eval( lhs ), eval( rhs ) ) );
            sres_   -= decllow( min( eval( lhs ), eval( rhs ) ) );
            osres_  -= decllow( min( eval( lhs ), eval( rhs ) ) );
            refres_ -= decllow( eval( ref ) );
         }
         catch( std::exception& ex ) {
            convertException<MT1,MT2>( ex );
         }

         checkResults<MT1,MT2>();

         try {
            initResults();
            dres_   -= decllow( min( eval( lhs ), eval( orhs ) ) );
            odres_  -= decllow( min( eval( lhs ), eval( orhs ) ) );
            sres_   -= decllow( min( eval( lhs ), eval( orhs ) ) );
            osres_  -= decllow( min( eval( lhs ), eval( orhs ) ) );
            refres_ -= decllow( eval( ref ) );
         }
         catch( std::exception& ex ) {
            convertException<MT1,OMT2>( ex );
         }

         checkResults<MT1,OMT2>();

         try {
            initResults();
            dres_   -= decllow( min( eval( olhs ), eval( rhs ) ) );
            odres_  -= decllow( min( eval( olhs ), eval( rhs ) ) );
            sres_   -= decllow( min( eval( olhs ), eval( rhs ) ) );
            osres_  -= decllow( min( eval( olhs ), eval( rhs ) ) );
            refres_ -= decllow( eval( ref ) );
         }
         catch( std::exception& ex ) {
            convertException<OMT1,MT2>( ex );
         }

         checkResults<OMT1,MT2>();

         try {
            initResults();
            dres_   -= decllow( min( eval( olhs ), eval( orhs ) ) );
            odres_  -= decllow( min( eval( olhs ), eval( orhs ) ) );
            sres_   -= decllow( min( eval( olhs ), eval( orhs ) ) );
            osres_  -= decllow( min( eval( olhs ), eval( orhs ) ) );
            refres_ -= decllow( eval( ref ) );
         }
         catch( std::exception& ex ) {
            convertException<OMT1,OMT2>( ex );
         }

         checkResults<OMT1,OMT2>();
      }


      //=====================================================================================
      // Decllow minimum with Schur product assignment
      //=====================================================================================

      // Decllow minimum with Schur product assignment with the given matrices
      {
         test_  = "Decllow minimum with Schur product assignment with the given matrices";
         error_ = "Failed Schur product assignment operation";

         try {
            initResults();
            dres_   %= decllow( min( lhs, rhs ) );
            odres_  %= decllow( min( lhs, rhs ) );
            sres_   %= decllow( min( lhs, rhs ) );
            osres_  %= decllow( min( lhs, rhs ) );
            refres_ %= decllow( ref );
         }
         catch( std::exception& ex ) {
            convertException<MT1,MT2>( ex );
         }

         checkResults<MT1,MT2>();

         try {
            initResults();
            dres_   %= decllow( min( lhs, orhs ) );
            odres_  %= decllow( min( lhs, orhs ) );
            sres_   %= decllow( min( lhs, orhs ) );
            osres_  %= decllow( min( lhs, orhs ) );
            refres_ %= decllow( ref );
         }
         catch( std::exception& ex ) {
            convertException<MT1,OMT2>( ex );
         }

         checkResults<MT1,OMT2>();

         try {
            initResults();
            dres_   %= decllow( min( olhs, rhs ) );
            odres_  %= decllow( min( olhs, rhs ) );
            sres_   %= decllow( min( olhs, rhs ) );
            osres_  %= decllow( min( olhs, rhs ) );
            refres_ %= decllow( ref );
         }
         catch( std::exception& ex ) {
            convertException<OMT1,MT2>( ex );
         }

         checkResults<OMT1,MT2>();

         try {
            initResults();
            dres_   %= decllow( min( olhs, orhs ) );
            odres_  %= decllow( min( olhs, orhs ) );
            sres_   %= decllow( min( olhs, orhs ) );
            osres_  %= decllow( min( olhs, orhs ) );
            refres_ %= decllow( ref );
         }
         catch( std::exception& ex ) {
            convertException<OMT1,OMT2>( ex );
         }

         checkResults<OMT1,OMT2>();
      }

      // Decllow minimum with Schur product assignment with evaluated matrices
      {
         test_  = "Decllow minimum with Schur product assignment with evaluated matrices";
         error_ = "Failed Schur product assignment operation";

         try {
            initResults();
            dres_   %= decllow( min( eval( lhs ), eval( rhs ) ) );
            odres_  %= decllow( min( eval( lhs ), eval( rhs ) ) );
            sres_   %= decllow( min( eval( lhs ), eval( rhs ) ) );
            osres_  %= decllow( min( eval( lhs ), eval( rhs ) ) );
            refres_ %= decllow( eval( ref ) );
         }
         catch( std::exception& ex ) {
            convertException<MT1,MT2>( ex );
         }

         checkResults<MT1,MT2>();

         try {
            initResults();
            dres_   %= decllow( min( eval( lhs ), eval( orhs ) ) );
            odres_  %= decllow( min( eval( lhs ), eval( orhs ) ) );
            sres_   %= decllow( min( eval( lhs ), eval( orhs ) ) );
            osres_  %= decllow( min( eval( lhs ), eval( orhs ) ) );
            refres_ %= decllow( eval( ref ) );
         }
         catch( std::exception& ex ) {
            convertException<MT1,OMT2>( ex );
         }

         checkResults<MT1,OMT2>();

         try {
            initResults();
            dres_   %= decllow( min( eval( olhs ), eval( rhs ) ) );
            odres_  %= decllow( min( eval( olhs ), eval( rhs ) ) );
            sres_   %= decllow( min( eval( olhs ), eval( rhs ) ) );
            osres_  %= decllow( min( eval( olhs ), eval( rhs ) ) );
            refres_ %= decllow( eval( ref ) );
         }
         catch( std::exception& ex ) {
            convertException<OMT1,MT2>( ex );
         }

         checkResults<OMT1,MT2>();

         try {
            initResults();
            dres_   %= decllow( min( eval( olhs ), eval( orhs ) ) );
            odres_  %= decllow( min( eval( olhs ), eval( orhs ) ) );
            sres_   %= decllow( min( eval( olhs ), eval( orhs ) ) );
            osres_  %= decllow( min( eval( olhs ), eval( orhs ) ) );
            refres_ %= decllow( eval( ref ) );
         }
         catch( std::exception& ex ) {
            convertException<OMT1,OMT2>( ex );
         }

         checkResults<OMT1,OMT2>();
      }
   }
#endif
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Skipping the lower dense matrix/dense matrix minimum operation.
//
// \return void
//
// This function is called in case the lower matrix/matrix minimum operation is not
// available for the given matrix types \a MT1 and \a MT2.
*/
template< typename MT1    // Type of the left-hand side dense matrix
        , typename MT2 >  // Type of the right-hand side dense matrix
void OperationTest<MT1,MT2>::testDeclLowOperation( blaze::FalseType )
{}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Testing the upper dense matrix/dense matrix minimum operation.
//
// \return void
// \exception std::runtime_error Minimum error detected.
//
// This function tests the upper matrix minimum with plain assignment, addition assignment,
// subtraction assignment, and Schur product assignment. In case any error resulting from the
// minimum operation or the subsequent assignment is detected, a \a std::runtime_error exception
// is thrown.
*/
template< typename MT1    // Type of the left-hand side dense matrix
        , typename MT2 >  // Type of the right-hand side dense matrix
void OperationTest<MT1,MT2>::testDeclUppOperation( blaze::TrueType )
{
#if BLAZETEST_MATHTEST_TEST_DECLUPP_OPERATION
   if( BLAZETEST_MATHTEST_TEST_DECLUPP_OPERATION > 1 )
   {
      if( lhs_.rows() != lhs_.columns() )
         return;


      //=====================================================================================
      // Test-specific setup of the left-hand side operand
      //=====================================================================================

      MT1 lhs( lhs_ );

      blaze::resetLower( lhs );

      OMT1 olhs( lhs );


      //=====================================================================================
      // Test-specific setup of the right-hand side operand
      //=====================================================================================

      MT2 rhs( rhs_ );

      blaze::resetLower( rhs );

      OMT2 orhs( rhs );


      //=====================================================================================
      // Test-specific setup of the reference matrix
      //=====================================================================================

      RT ref( min( lhs, rhs ) );


      //=====================================================================================
      // Declupp minimum
      //=====================================================================================

      // Declupp minimum with the given matrices
      {
         test_  = "Declupp minimum with the given matrices";
         error_ = "Failed minimum operation";

         try {
            initResults();
            dres_   = declupp( min( lhs, rhs ) );
            odres_  = declupp( min( lhs, rhs ) );
            sres_   = declupp( min( lhs, rhs ) );
            osres_  = declupp( min( lhs, rhs ) );
            refres_ = declupp( ref );
         }
         catch( std::exception& ex ) {
            convertException<MT1,MT2>( ex );
         }

         checkResults<MT1,MT2>();

         try {
            initResults();
            dres_   = declupp( min( lhs, orhs ) );
            odres_  = declupp( min( lhs, orhs ) );
            sres_   = declupp( min( lhs, orhs ) );
            osres_  = declupp( min( lhs, orhs ) );
            refres_ = declupp( ref );
         }
         catch( std::exception& ex ) {
            convertException<MT1,OMT2>( ex );
         }

         checkResults<MT1,OMT2>();

         try {
            initResults();
            dres_   = declupp( min( olhs, rhs ) );
            odres_  = declupp( min( olhs, rhs ) );
            sres_   = declupp( min( olhs, rhs ) );
            osres_  = declupp( min( olhs, rhs ) );
            refres_ = declupp( ref );
         }
         catch( std::exception& ex ) {
            convertException<OMT1,MT2>( ex );
         }

         checkResults<OMT1,MT2>();

         try {
            initResults();
            dres_   = declupp( min( olhs, orhs ) );
            odres_  = declupp( min( olhs, orhs ) );
            sres_   = declupp( min( olhs, orhs ) );
            osres_  = declupp( min( olhs, orhs ) );
            refres_ = declupp( ref );
         }
         catch( std::exception& ex ) {
            convertException<OMT1,OMT2>( ex );
         }

         checkResults<OMT1,OMT2>();
      }

      // Declupp minimum with evaluated matrices
      {
         test_  = "Declupp minimum with evaluated left-hand side matrix";
         error_ = "Failed minimum operation";

         try {
            initResults();
            dres_   = declupp( min( eval( lhs ), eval( rhs ) ) );
            odres_  = declupp( min( eval( lhs ), eval( rhs ) ) );
            sres_   = declupp( min( eval( lhs ), eval( rhs ) ) );
            osres_  = declupp( min( eval( lhs ), eval( rhs ) ) );
            refres_ = declupp( eval( ref ) );
         }
         catch( std::exception& ex ) {
            convertException<MT1,MT2>( ex );
         }

         checkResults<MT1,MT2>();

         try {
            initResults();
            dres_   = declupp( min( eval( lhs ), eval( orhs ) ) );
            odres_  = declupp( min( eval( lhs ), eval( orhs ) ) );
            sres_   = declupp( min( eval( lhs ), eval( orhs ) ) );
            osres_  = declupp( min( eval( lhs ), eval( orhs ) ) );
            refres_ = declupp( eval( ref ) );
         }
         catch( std::exception& ex ) {
            convertException<MT1,OMT2>( ex );
         }

         checkResults<MT1,OMT2>();

         try {
            initResults();
            dres_   = declupp( min( eval( olhs ), eval( rhs ) ) );
            odres_  = declupp( min( eval( olhs ), eval( rhs ) ) );
            sres_   = declupp( min( eval( olhs ), eval( rhs ) ) );
            osres_  = declupp( min( eval( olhs ), eval( rhs ) ) );
            refres_ = declupp( eval( ref ) );
         }
         catch( std::exception& ex ) {
            convertException<OMT1,MT2>( ex );
         }

         checkResults<OMT1,MT2>();

         try {
            initResults();
            dres_   = declupp( min( eval( olhs ), eval( orhs ) ) );
            odres_  = declupp( min( eval( olhs ), eval( orhs ) ) );
            sres_   = declupp( min( eval( olhs ), eval( orhs ) ) );
            osres_  = declupp( min( eval( olhs ), eval( orhs ) ) );
            refres_ = declupp( eval( ref ) );
         }
         catch( std::exception& ex ) {
            convertException<OMT1,OMT2>( ex );
         }

         checkResults<OMT1,OMT2>();
      }


      //=====================================================================================
      // Declupp minimum with addition assignment
      //=====================================================================================

      // Declupp minimum with addition assignment with the given matrices
      {
         test_  = "Declupp minimum with addition assignment with the given matrices";
         error_ = "Failed addition assignment operation";

         try {
            initResults();
            dres_   += declupp( min( lhs, rhs ) );
            odres_  += declupp( min( lhs, rhs ) );
            sres_   += declupp( min( lhs, rhs ) );
            osres_  += declupp( min( lhs, rhs ) );
            refres_ += declupp( ref );
         }
         catch( std::exception& ex ) {
            convertException<MT1,MT2>( ex );
         }

         checkResults<MT1,MT2>();

         try {
            initResults();
            dres_   += declupp( min( lhs, orhs ) );
            odres_  += declupp( min( lhs, orhs ) );
            sres_   += declupp( min( lhs, orhs ) );
            osres_  += declupp( min( lhs, orhs ) );
            refres_ += declupp( ref );
         }
         catch( std::exception& ex ) {
            convertException<MT1,OMT2>( ex );
         }

         checkResults<MT1,OMT2>();

         try {
            initResults();
            dres_   += declupp( min( olhs, rhs ) );
            odres_  += declupp( min( olhs, rhs ) );
            sres_   += declupp( min( olhs, rhs ) );
            osres_  += declupp( min( olhs, rhs ) );
            refres_ += declupp( ref );
         }
         catch( std::exception& ex ) {
            convertException<OMT1,MT2>( ex );
         }

         checkResults<OMT1,MT2>();

         try {
            initResults();
            dres_   += declupp( min( olhs, orhs ) );
            odres_  += declupp( min( olhs, orhs ) );
            sres_   += declupp( min( olhs, orhs ) );
            osres_  += declupp( min( olhs, orhs ) );
            refres_ += declupp( ref );
         }
         catch( std::exception& ex ) {
            convertException<OMT1,OMT2>( ex );
         }

         checkResults<OMT1,OMT2>();
      }

      // Declupp minimum with addition assignment with evaluated matrices
      {
         test_  = "Declupp minimum with addition assignment with evaluated matrices";
         error_ = "Failed addition assignment operation";

         try {
            initResults();
            dres_   += declupp( min( eval( lhs ), eval( rhs ) ) );
            odres_  += declupp( min( eval( lhs ), eval( rhs ) ) );
            sres_   += declupp( min( eval( lhs ), eval( rhs ) ) );
            osres_  += declupp( min( eval( lhs ), eval( rhs ) ) );
            refres_ += declupp( eval( ref ) );
         }
         catch( std::exception& ex ) {
            convertException<MT1,MT2>( ex );
         }

         checkResults<MT1,MT2>();

         try {
            initResults();
            dres_   += declupp( min( eval( lhs ), eval( orhs ) ) );
            odres_  += declupp( min( eval( lhs ), eval( orhs ) ) );
            sres_   += declupp( min( eval( lhs ), eval( orhs ) ) );
            osres_  += declupp( min( eval( lhs ), eval( orhs ) ) );
            refres_ += declupp( eval( ref ) );
         }
         catch( std::exception& ex ) {
            convertException<MT1,OMT2>( ex );
         }

         checkResults<MT1,OMT2>();

         try {
            initResults();
            dres_   += declupp( min( eval( olhs ), eval( rhs ) ) );
            odres_  += declupp( min( eval( olhs ), eval( rhs ) ) );
            sres_   += declupp( min( eval( olhs ), eval( rhs ) ) );
            osres_  += declupp( min( eval( olhs ), eval( rhs ) ) );
            refres_ += declupp( eval( ref ) );
         }
         catch( std::exception& ex ) {
            convertException<OMT1,MT2>( ex );
         }

         checkResults<OMT1,MT2>();

         try {
            initResults();
            dres_   += declupp( min( eval( olhs ), eval( orhs ) ) );
            odres_  += declupp( min( eval( olhs ), eval( orhs ) ) );
            sres_   += declupp( min( eval( olhs ), eval( orhs ) ) );
            osres_  += declupp( min( eval( olhs ), eval( orhs ) ) );
            refres_ += declupp( eval( ref ) );
         }
         catch( std::exception& ex ) {
            convertException<OMT1,OMT2>( ex );
         }

         checkResults<OMT1,OMT2>();
      }


      //=====================================================================================
      // Declupp minimum with subtraction assignment
      //=====================================================================================

      // Declupp minimum with subtraction assignment with the given matrices
      {
         test_  = "Declupp minimum with subtraction assignment with the given matrices";
         error_ = "Failed subtraction assignment operation";

         try {
            initResults();
            dres_   -= declupp( min( lhs, rhs ) );
            odres_  -= declupp( min( lhs, rhs ) );
            sres_   -= declupp( min( lhs, rhs ) );
            osres_  -= declupp( min( lhs, rhs ) );
            refres_ -= declupp( ref );
         }
         catch( std::exception& ex ) {
            convertException<MT1,MT2>( ex );
         }

         checkResults<MT1,MT2>();

         try {
            initResults();
            dres_   -= declupp( min( lhs, orhs ) );
            odres_  -= declupp( min( lhs, orhs ) );
            sres_   -= declupp( min( lhs, orhs ) );
            osres_  -= declupp( min( lhs, orhs ) );
            refres_ -= declupp( ref );
         }
         catch( std::exception& ex ) {
            convertException<MT1,OMT2>( ex );
         }

         checkResults<MT1,OMT2>();

         try {
            initResults();
            dres_   -= declupp( min( olhs, rhs ) );
            odres_  -= declupp( min( olhs, rhs ) );
            sres_   -= declupp( min( olhs, rhs ) );
            osres_  -= declupp( min( olhs, rhs ) );
            refres_ -= declupp( ref );
         }
         catch( std::exception& ex ) {
            convertException<OMT1,MT2>( ex );
         }

         checkResults<OMT1,MT2>();

         try {
            initResults();
            dres_   -= declupp( min( olhs, orhs ) );
            odres_  -= declupp( min( olhs, orhs ) );
            sres_   -= declupp( min( olhs, orhs ) );
            osres_  -= declupp( min( olhs, orhs ) );
            refres_ -= declupp( ref );
         }
         catch( std::exception& ex ) {
            convertException<OMT1,OMT2>( ex );
         }

         checkResults<OMT1,OMT2>();
      }

      // Declupp minimum with subtraction assignment with evaluated matrices
      {
         test_  = "Declupp minimum with subtraction assignment with evaluated matrices";
         error_ = "Failed subtraction assignment operation";

         try {
            initResults();
            dres_   -= declupp( min( eval( lhs ), eval( rhs ) ) );
            odres_  -= declupp( min( eval( lhs ), eval( rhs ) ) );
            sres_   -= declupp( min( eval( lhs ), eval( rhs ) ) );
            osres_  -= declupp( min( eval( lhs ), eval( rhs ) ) );
            refres_ -= declupp( eval( ref ) );
         }
         catch( std::exception& ex ) {
            convertException<MT1,MT2>( ex );
         }

         checkResults<MT1,MT2>();

         try {
            initResults();
            dres_   -= declupp( min( eval( lhs ), eval( orhs ) ) );
            odres_  -= declupp( min( eval( lhs ), eval( orhs ) ) );
            sres_   -= declupp( min( eval( lhs ), eval( orhs ) ) );
            osres_  -= declupp( min( eval( lhs ), eval( orhs ) ) );
            refres_ -= declupp( eval( ref ) );
         }
         catch( std::exception& ex ) {
            convertException<MT1,OMT2>( ex );
         }

         checkResults<MT1,OMT2>();

         try {
            initResults();
            dres_   -= declupp( min( eval( olhs ), eval( rhs ) ) );
            odres_  -= declupp( min( eval( olhs ), eval( rhs ) ) );
            sres_   -= declupp( min( eval( olhs ), eval( rhs ) ) );
            osres_  -= declupp( min( eval( olhs ), eval( rhs ) ) );
            refres_ -= declupp( eval( ref ) );
         }
         catch( std::exception& ex ) {
            convertException<OMT1,MT2>( ex );
         }

         checkResults<OMT1,MT2>();

         try {
            initResults();
            dres_   -= declupp( min( eval( olhs ), eval( orhs ) ) );
            odres_  -= declupp( min( eval( olhs ), eval( orhs ) ) );
            sres_   -= declupp( min( eval( olhs ), eval( orhs ) ) );
            osres_  -= declupp( min( eval( olhs ), eval( orhs ) ) );
            refres_ -= declupp( eval( ref ) );
         }
         catch( std::exception& ex ) {
            convertException<OMT1,OMT2>( ex );
         }

         checkResults<OMT1,OMT2>();
      }


      //=====================================================================================
      // Declupp minimum with Schur product assignment
      //=====================================================================================

      // Declupp minimum with Schur product assignment with the given matrices
      {
         test_  = "Declupp minimum with Schur product assignment with the given matrices";
         error_ = "Failed Schur product assignment operation";

         try {
            initResults();
            dres_   %= declupp( min( lhs, rhs ) );
            odres_  %= declupp( min( lhs, rhs ) );
            sres_   %= declupp( min( lhs, rhs ) );
            osres_  %= declupp( min( lhs, rhs ) );
            refres_ %= declupp( ref );
         }
         catch( std::exception& ex ) {
            convertException<MT1,MT2>( ex );
         }

         checkResults<MT1,MT2>();

         try {
            initResults();
            dres_   %= declupp( min( lhs, orhs ) );
            odres_  %= declupp( min( lhs, orhs ) );
            sres_   %= declupp( min( lhs, orhs ) );
            osres_  %= declupp( min( lhs, orhs ) );
            refres_ %= declupp( ref );
         }
         catch( std::exception& ex ) {
            convertException<MT1,OMT2>( ex );
         }

         checkResults<MT1,OMT2>();

         try {
            initResults();
            dres_   %= declupp( min( olhs, rhs ) );
            odres_  %= declupp( min( olhs, rhs ) );
            sres_   %= declupp( min( olhs, rhs ) );
            osres_  %= declupp( min( olhs, rhs ) );
            refres_ %= declupp( ref );
         }
         catch( std::exception& ex ) {
            convertException<OMT1,MT2>( ex );
         }

         checkResults<OMT1,MT2>();

         try {
            initResults();
            dres_   %= declupp( min( olhs, orhs ) );
            odres_  %= declupp( min( olhs, orhs ) );
            sres_   %= declupp( min( olhs, orhs ) );
            osres_  %= declupp( min( olhs, orhs ) );
            refres_ %= declupp( ref );
         }
         catch( std::exception& ex ) {
            convertException<OMT1,OMT2>( ex );
         }

         checkResults<OMT1,OMT2>();
      }

      // Declupp minimum with Schur product assignment with evaluated matrices
      {
         test_  = "Declupp minimum with Schur product assignment with evaluated matrices";
         error_ = "Failed Schur product assignment operation";

         try {
            initResults();
            dres_   %= declupp( min( eval( lhs ), eval( rhs ) ) );
            odres_  %= declupp( min( eval( lhs ), eval( rhs ) ) );
            sres_   %= declupp( min( eval( lhs ), eval( rhs ) ) );
            osres_  %= declupp( min( eval( lhs ), eval( rhs ) ) );
            refres_ %= declupp( eval( ref ) );
         }
         catch( std::exception& ex ) {
            convertException<MT1,MT2>( ex );
         }

         checkResults<MT1,MT2>();

         try {
            initResults();
            dres_   %= declupp( min( eval( lhs ), eval( orhs ) ) );
            odres_  %= declupp( min( eval( lhs ), eval( orhs ) ) );
            sres_   %= declupp( min( eval( lhs ), eval( orhs ) ) );
            osres_  %= declupp( min( eval( lhs ), eval( orhs ) ) );
            refres_ %= declupp( eval( ref ) );
         }
         catch( std::exception& ex ) {
            convertException<MT1,OMT2>( ex );
         }

         checkResults<MT1,OMT2>();

         try {
            initResults();
            dres_   %= declupp( min( eval( olhs ), eval( rhs ) ) );
            odres_  %= declupp( min( eval( olhs ), eval( rhs ) ) );
            sres_   %= declupp( min( eval( olhs ), eval( rhs ) ) );
            osres_  %= declupp( min( eval( olhs ), eval( rhs ) ) );
            refres_ %= declupp( eval( ref ) );
         }
         catch( std::exception& ex ) {
            convertException<OMT1,MT2>( ex );
         }

         checkResults<OMT1,MT2>();

         try {
            initResults();
            dres_   %= declupp( min( eval( olhs ), eval( orhs ) ) );
            odres_  %= declupp( min( eval( olhs ), eval( orhs ) ) );
            sres_   %= declupp( min( eval( olhs ), eval( orhs ) ) );
            osres_  %= declupp( min( eval( olhs ), eval( orhs ) ) );
            refres_ %= declupp( eval( ref ) );
         }
         catch( std::exception& ex ) {
            convertException<OMT1,OMT2>( ex );
         }

         checkResults<OMT1,OMT2>();
      }
   }
#endif
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Skipping the upper dense matrix/dense matrix minimum operation.
//
// \return void
//
// This function is called in case the upper matrix/matrix minimum operation is not
// available for the given matrix types \a MT1 and \a MT2.
*/
template< typename MT1    // Type of the left-hand side dense matrix
        , typename MT2 >  // Type of the right-hand side dense matrix
void OperationTest<MT1,MT2>::testDeclUppOperation( blaze::FalseType )
{}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Testing the diagonal dense matrix/dense matrix minimum operation.
//
// \return void
// \exception std::runtime_error Minimum error detected.
//
// This function tests the diagonal matrix minimum with plain assignment, addition assignment,
// subtraction assignment, and Schur product assignment. In case any error resulting from the
// minimum operation or the subsequent assignment is detected, a \a std::runtime_error exception
// is thrown.
*/
template< typename MT1    // Type of the left-hand side dense matrix
        , typename MT2 >  // Type of the right-hand side dense matrix
void OperationTest<MT1,MT2>::testDeclDiagOperation( blaze::TrueType )
{
#if BLAZETEST_MATHTEST_TEST_DECLDIAG_OPERATION
   if( BLAZETEST_MATHTEST_TEST_DECLDIAG_OPERATION > 1 )
   {
      if( lhs_.rows() != lhs_.columns() )
         return;


      //=====================================================================================
      // Test-specific setup of the left-hand side operand
      //=====================================================================================

      MT1 lhs( lhs_ );

      blaze::resetLower( lhs );
      blaze::resetUpper( lhs );

      OMT1 olhs( lhs );


      //=====================================================================================
      // Test-specific setup of the right-hand side operand
      //=====================================================================================

      MT2 rhs( rhs_ );

      blaze::resetLower( rhs );
      blaze::resetUpper( rhs );

      OMT2 orhs( rhs );


      //=====================================================================================
      // Test-specific setup of the reference matrix
      //=====================================================================================

      RT ref( min( lhs, rhs ) );


      //=====================================================================================
      // Decldiag minimum
      //=====================================================================================

      // Decldiag minimum with the given matrices
      {
         test_  = "Decldiag minimum with the given matrices";
         error_ = "Failed minimum operation";

         try {
            initResults();
            dres_   = decldiag( min( lhs, rhs ) );
            odres_  = decldiag( min( lhs, rhs ) );
            sres_   = decldiag( min( lhs, rhs ) );
            osres_  = decldiag( min( lhs, rhs ) );
            refres_ = decldiag( ref );
         }
         catch( std::exception& ex ) {
            convertException<MT1,MT2>( ex );
         }

         checkResults<MT1,MT2>();

         try {
            initResults();
            dres_   = decldiag( min( lhs, orhs ) );
            odres_  = decldiag( min( lhs, orhs ) );
            sres_   = decldiag( min( lhs, orhs ) );
            osres_  = decldiag( min( lhs, orhs ) );
            refres_ = decldiag( ref );
         }
         catch( std::exception& ex ) {
            convertException<MT1,OMT2>( ex );
         }

         checkResults<MT1,OMT2>();

         try {
            initResults();
            dres_   = decldiag( min( olhs, rhs ) );
            odres_  = decldiag( min( olhs, rhs ) );
            sres_   = decldiag( min( olhs, rhs ) );
            osres_  = decldiag( min( olhs, rhs ) );
            refres_ = decldiag( ref );
         }
         catch( std::exception& ex ) {
            convertException<OMT1,MT2>( ex );
         }

         checkResults<OMT1,MT2>();

         try {
            initResults();
            dres_   = decldiag( min( olhs, orhs ) );
            odres_  = decldiag( min( olhs, orhs ) );
            sres_   = decldiag( min( olhs, orhs ) );
            osres_  = decldiag( min( olhs, orhs ) );
            refres_ = decldiag( ref );
         }
         catch( std::exception& ex ) {
            convertException<OMT1,OMT2>( ex );
         }

         checkResults<OMT1,OMT2>();
      }

      // Decldiag minimum with evaluated matrices
      {
         test_  = "Decldiag minimum with evaluated left-hand side matrix";
         error_ = "Failed minimum operation";

         try {
            initResults();
            dres_   = decldiag( min( eval( lhs ), eval( rhs ) ) );
            odres_  = decldiag( min( eval( lhs ), eval( rhs ) ) );
            sres_   = decldiag( min( eval( lhs ), eval( rhs ) ) );
            osres_  = decldiag( min( eval( lhs ), eval( rhs ) ) );
            refres_ = decldiag( eval( ref ) );
         }
         catch( std::exception& ex ) {
            convertException<MT1,MT2>( ex );
         }

         checkResults<MT1,MT2>();

         try {
            initResults();
            dres_   = decldiag( min( eval( lhs ), eval( orhs ) ) );
            odres_  = decldiag( min( eval( lhs ), eval( orhs ) ) );
            sres_   = decldiag( min( eval( lhs ), eval( orhs ) ) );
            osres_  = decldiag( min( eval( lhs ), eval( orhs ) ) );
            refres_ = decldiag( eval( ref ) );
         }
         catch( std::exception& ex ) {
            convertException<MT1,OMT2>( ex );
         }

         checkResults<MT1,OMT2>();

         try {
            initResults();
            dres_   = decldiag( min( eval( olhs ), eval( rhs ) ) );
            odres_  = decldiag( min( eval( olhs ), eval( rhs ) ) );
            sres_   = decldiag( min( eval( olhs ), eval( rhs ) ) );
            osres_  = decldiag( min( eval( olhs ), eval( rhs ) ) );
            refres_ = decldiag( eval( ref ) );
         }
         catch( std::exception& ex ) {
            convertException<OMT1,MT2>( ex );
         }

         checkResults<OMT1,MT2>();

         try {
            initResults();
            dres_   = decldiag( min( eval( olhs ), eval( orhs ) ) );
            odres_  = decldiag( min( eval( olhs ), eval( orhs ) ) );
            sres_   = decldiag( min( eval( olhs ), eval( orhs ) ) );
            osres_  = decldiag( min( eval( olhs ), eval( orhs ) ) );
            refres_ = decldiag( eval( ref ) );
         }
         catch( std::exception& ex ) {
            convertException<OMT1,OMT2>( ex );
         }

         checkResults<OMT1,OMT2>();
      }


      //=====================================================================================
      // Decldiag minimum with addition assignment
      //=====================================================================================

      // Decldiag minimum with addition assignment with the given matrices
      {
         test_  = "Decldiag minimum with addition assignment with the given matrices";
         error_ = "Failed addition assignment operation";

         try {
            initResults();
            dres_   += decldiag( min( lhs, rhs ) );
            odres_  += decldiag( min( lhs, rhs ) );
            sres_   += decldiag( min( lhs, rhs ) );
            osres_  += decldiag( min( lhs, rhs ) );
            refres_ += decldiag( ref );
         }
         catch( std::exception& ex ) {
            convertException<MT1,MT2>( ex );
         }

         checkResults<MT1,MT2>();

         try {
            initResults();
            dres_   += decldiag( min( lhs, orhs ) );
            odres_  += decldiag( min( lhs, orhs ) );
            sres_   += decldiag( min( lhs, orhs ) );
            osres_  += decldiag( min( lhs, orhs ) );
            refres_ += decldiag( ref );
         }
         catch( std::exception& ex ) {
            convertException<MT1,OMT2>( ex );
         }

         checkResults<MT1,OMT2>();

         try {
            initResults();
            dres_   += decldiag( min( olhs, rhs ) );
            odres_  += decldiag( min( olhs, rhs ) );
            sres_   += decldiag( min( olhs, rhs ) );
            osres_  += decldiag( min( olhs, rhs ) );
            refres_ += decldiag( ref );
         }
         catch( std::exception& ex ) {
            convertException<OMT1,MT2>( ex );
         }

         checkResults<OMT1,MT2>();

         try {
            initResults();
            dres_   += decldiag( min( olhs, orhs ) );
            odres_  += decldiag( min( olhs, orhs ) );
            sres_   += decldiag( min( olhs, orhs ) );
            osres_  += decldiag( min( olhs, orhs ) );
            refres_ += decldiag( ref );
         }
         catch( std::exception& ex ) {
            convertException<OMT1,OMT2>( ex );
         }

         checkResults<OMT1,OMT2>();
      }

      // Decldiag minimum with addition assignment with evaluated matrices
      {
         test_  = "Decldiag minimum with addition assignment with evaluated matrices";
         error_ = "Failed addition assignment operation";

         try {
            initResults();
            dres_   += decldiag( min( eval( lhs ), eval( rhs ) ) );
            odres_  += decldiag( min( eval( lhs ), eval( rhs ) ) );
            sres_   += decldiag( min( eval( lhs ), eval( rhs ) ) );
            osres_  += decldiag( min( eval( lhs ), eval( rhs ) ) );
            refres_ += decldiag( eval( ref ) );
         }
         catch( std::exception& ex ) {
            convertException<MT1,MT2>( ex );
         }

         checkResults<MT1,MT2>();

         try {
            initResults();
            dres_   += decldiag( min( eval( lhs ), eval( orhs ) ) );
            odres_  += decldiag( min( eval( lhs ), eval( orhs ) ) );
            sres_   += decldiag( min( eval( lhs ), eval( orhs ) ) );
            osres_  += decldiag( min( eval( lhs ), eval( orhs ) ) );
            refres_ += decldiag( eval( ref ) );
         }
         catch( std::exception& ex ) {
            convertException<MT1,OMT2>( ex );
         }

         checkResults<MT1,OMT2>();

         try {
            initResults();
            dres_   += decldiag( min( eval( olhs ), eval( rhs ) ) );
            odres_  += decldiag( min( eval( olhs ), eval( rhs ) ) );
            sres_   += decldiag( min( eval( olhs ), eval( rhs ) ) );
            osres_  += decldiag( min( eval( olhs ), eval( rhs ) ) );
            refres_ += decldiag( eval( ref ) );
         }
         catch( std::exception& ex ) {
            convertException<OMT1,MT2>( ex );
         }

         checkResults<OMT1,MT2>();

         try {
            initResults();
            dres_   += decldiag( min( eval( olhs ), eval( orhs ) ) );
            odres_  += decldiag( min( eval( olhs ), eval( orhs ) ) );
            sres_   += decldiag( min( eval( olhs ), eval( orhs ) ) );
            osres_  += decldiag( min( eval( olhs ), eval( orhs ) ) );
            refres_ += decldiag( eval( ref ) );
         }
         catch( std::exception& ex ) {
            convertException<OMT1,OMT2>( ex );
         }

         checkResults<OMT1,OMT2>();
      }


      //=====================================================================================
      // Decldiag minimum with subtraction assignment
      //=====================================================================================

      // Decldiag minimum with subtraction assignment with the given matrices
      {
         test_  = "Decldiag minimum with subtraction assignment with the given matrices";
         error_ = "Failed subtraction assignment operation";

         try {
            initResults();
            dres_   -= decldiag( min( lhs, rhs ) );
            odres_  -= decldiag( min( lhs, rhs ) );
            sres_   -= decldiag( min( lhs, rhs ) );
            osres_  -= decldiag( min( lhs, rhs ) );
            refres_ -= decldiag( ref );
         }
         catch( std::exception& ex ) {
            convertException<MT1,MT2>( ex );
         }

         checkResults<MT1,MT2>();

         try {
            initResults();
            dres_   -= decldiag( min( lhs, orhs ) );
            odres_  -= decldiag( min( lhs, orhs ) );
            sres_   -= decldiag( min( lhs, orhs ) );
            osres_  -= decldiag( min( lhs, orhs ) );
            refres_ -= decldiag( ref );
         }
         catch( std::exception& ex ) {
            convertException<MT1,OMT2>( ex );
         }

         checkResults<MT1,OMT2>();

         try {
            initResults();
            dres_   -= decldiag( min( olhs, rhs ) );
            odres_  -= decldiag( min( olhs, rhs ) );
            sres_   -= decldiag( min( olhs, rhs ) );
            osres_  -= decldiag( min( olhs, rhs ) );
            refres_ -= decldiag( ref );
         }
         catch( std::exception& ex ) {
            convertException<OMT1,MT2>( ex );
         }

         checkResults<OMT1,MT2>();

         try {
            initResults();
            dres_   -= decldiag( min( olhs, orhs ) );
            odres_  -= decldiag( min( olhs, orhs ) );
            sres_   -= decldiag( min( olhs, orhs ) );
            osres_  -= decldiag( min( olhs, orhs ) );
            refres_ -= decldiag( ref );
         }
         catch( std::exception& ex ) {
            convertException<OMT1,OMT2>( ex );
         }

         checkResults<OMT1,OMT2>();
      }

      // Decldiag minimum with subtraction assignment with evaluated matrices
      {
         test_  = "Decldiag minimum with subtraction assignment with evaluated matrices";
         error_ = "Failed subtraction assignment operation";

         try {
            initResults();
            dres_   -= decldiag( min( eval( lhs ), eval( rhs ) ) );
            odres_  -= decldiag( min( eval( lhs ), eval( rhs ) ) );
            sres_   -= decldiag( min( eval( lhs ), eval( rhs ) ) );
            osres_  -= decldiag( min( eval( lhs ), eval( rhs ) ) );
            refres_ -= decldiag( eval( ref ) );
         }
         catch( std::exception& ex ) {
            convertException<MT1,MT2>( ex );
         }

         checkResults<MT1,MT2>();

         try {
            initResults();
            dres_   -= decldiag( min( eval( lhs ), eval( orhs ) ) );
            odres_  -= decldiag( min( eval( lhs ), eval( orhs ) ) );
            sres_   -= decldiag( min( eval( lhs ), eval( orhs ) ) );
            osres_  -= decldiag( min( eval( lhs ), eval( orhs ) ) );
            refres_ -= decldiag( eval( ref ) );
         }
         catch( std::exception& ex ) {
            convertException<MT1,OMT2>( ex );
         }

         checkResults<MT1,OMT2>();

         try {
            initResults();
            dres_   -= decldiag( min( eval( olhs ), eval( rhs ) ) );
            odres_  -= decldiag( min( eval( olhs ), eval( rhs ) ) );
            sres_   -= decldiag( min( eval( olhs ), eval( rhs ) ) );
            osres_  -= decldiag( min( eval( olhs ), eval( rhs ) ) );
            refres_ -= decldiag( eval( ref ) );
         }
         catch( std::exception& ex ) {
            convertException<OMT1,MT2>( ex );
         }

         checkResults<OMT1,MT2>();

         try {
            initResults();
            dres_   -= decldiag( min( eval( olhs ), eval( orhs ) ) );
            odres_  -= decldiag( min( eval( olhs ), eval( orhs ) ) );
            sres_   -= decldiag( min( eval( olhs ), eval( orhs ) ) );
            osres_  -= decldiag( min( eval( olhs ), eval( orhs ) ) );
            refres_ -= decldiag( eval( ref ) );
         }
         catch( std::exception& ex ) {
            convertException<OMT1,OMT2>( ex );
         }

         checkResults<OMT1,OMT2>();
      }


      //=====================================================================================
      // Decldiag minimum with Schur product assignment
      //=====================================================================================

      // Decldiag minimum with Schur product assignment with the given matrices
      {
         test_  = "Decldiag minimum with Schur product assignment with the given matrices";
         error_ = "Failed Schur product assignment operation";

         try {
            initResults();
            dres_   %= decldiag( min( lhs, rhs ) );
            odres_  %= decldiag( min( lhs, rhs ) );
            sres_   %= decldiag( min( lhs, rhs ) );
            osres_  %= decldiag( min( lhs, rhs ) );
            refres_ %= decldiag( ref );
         }
         catch( std::exception& ex ) {
            convertException<MT1,MT2>( ex );
         }

         checkResults<MT1,MT2>();

         try {
            initResults();
            dres_   %= decldiag( min( lhs, orhs ) );
            odres_  %= decldiag( min( lhs, orhs ) );
            sres_   %= decldiag( min( lhs, orhs ) );
            osres_  %= decldiag( min( lhs, orhs ) );
            refres_ %= decldiag( ref );
         }
         catch( std::exception& ex ) {
            convertException<MT1,OMT2>( ex );
         }

         checkResults<MT1,OMT2>();

         try {
            initResults();
            dres_   %= decldiag( min( olhs, rhs ) );
            odres_  %= decldiag( min( olhs, rhs ) );
            sres_   %= decldiag( min( olhs, rhs ) );
            osres_  %= decldiag( min( olhs, rhs ) );
            refres_ %= decldiag( ref );
         }
         catch( std::exception& ex ) {
            convertException<OMT1,MT2>( ex );
         }

         checkResults<OMT1,MT2>();

         try {
            initResults();
            dres_   %= decldiag( min( olhs, orhs ) );
            odres_  %= decldiag( min( olhs, orhs ) );
            sres_   %= decldiag( min( olhs, orhs ) );
            osres_  %= decldiag( min( olhs, orhs ) );
            refres_ %= decldiag( ref );
         }
         catch( std::exception& ex ) {
            convertException<OMT1,OMT2>( ex );
         }

         checkResults<OMT1,OMT2>();
      }

      // Decldiag minimum with Schur product assignment with evaluated matrices
      {
         test_  = "Decldiag minimum with Schur product assignment with evaluated matrices";
         error_ = "Failed Schur product assignment operation";

         try {
            initResults();
            dres_   %= decldiag( min( eval( lhs ), eval( rhs ) ) );
            odres_  %= decldiag( min( eval( lhs ), eval( rhs ) ) );
            sres_   %= decldiag( min( eval( lhs ), eval( rhs ) ) );
            osres_  %= decldiag( min( eval( lhs ), eval( rhs ) ) );
            refres_ %= decldiag( eval( ref ) );
         }
         catch( std::exception& ex ) {
            convertException<MT1,MT2>( ex );
         }

         checkResults<MT1,MT2>();

         try {
            initResults();
            dres_   %= decldiag( min( eval( lhs ), eval( orhs ) ) );
            odres_  %= decldiag( min( eval( lhs ), eval( orhs ) ) );
            sres_   %= decldiag( min( eval( lhs ), eval( orhs ) ) );
            osres_  %= decldiag( min( eval( lhs ), eval( orhs ) ) );
            refres_ %= decldiag( eval( ref ) );
         }
         catch( std::exception& ex ) {
            convertException<MT1,OMT2>( ex );
         }

         checkResults<MT1,OMT2>();

         try {
            initResults();
            dres_   %= decldiag( min( eval( olhs ), eval( rhs ) ) );
            odres_  %= decldiag( min( eval( olhs ), eval( rhs ) ) );
            sres_   %= decldiag( min( eval( olhs ), eval( rhs ) ) );
            osres_  %= decldiag( min( eval( olhs ), eval( rhs ) ) );
            refres_ %= decldiag( eval( ref ) );
         }
         catch( std::exception& ex ) {
            convertException<OMT1,MT2>( ex );
         }

         checkResults<OMT1,MT2>();

         try {
            initResults();
            dres_   %= decldiag( min( eval( olhs ), eval( orhs ) ) );
            odres_  %= decldiag( min( eval( olhs ), eval( orhs ) ) );
            sres_   %= decldiag( min( eval( olhs ), eval( orhs ) ) );
            osres_  %= decldiag( min( eval( olhs ), eval( orhs ) ) );
            refres_ %= decldiag( eval( ref ) );
         }
         catch( std::exception& ex ) {
            convertException<OMT1,OMT2>( ex );
         }

         checkResults<OMT1,OMT2>();
      }
   }
#endif
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Skipping the diagonal dense matrix/dense matrix minimum operation.
//
// \return void
//
// This function is called in case the diagonal matrix/matrix minimum operation is not
// available for the given matrix types \a MT1 and \a MT2.
*/
template< typename MT1    // Type of the left-hand side dense matrix
        , typename MT2 >  // Type of the right-hand side dense matrix
void OperationTest<MT1,MT2>::testDeclDiagOperation( blaze::FalseType )
{}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Testing the submatrix-wise dense matrix/dense matrix minimum operation.
//
// \return void
// \exception std::runtime_error Minimum error detected.
//
// This function tests the submatrix-wise matrix minimum with plain assignment, addition
// assignment, subtraction assignment, and Schur product assignment. In case any error resulting
// from the minimum operation or the subsequent assignment is detected, a \a std::runtime_error
// exception is thrown.
*/
template< typename MT1    // Type of the left-hand side dense matrix
        , typename MT2 >  // Type of the right-hand side dense matrix
void OperationTest<MT1,MT2>::testSubmatrixOperation()
{
#if BLAZETEST_MATHTEST_TEST_SUBMATRIX_OPERATION
   if( BLAZETEST_MATHTEST_TEST_SUBMATRIX_OPERATION > 1 )
   {
      if( lhs_.rows() == 0UL || lhs_.columns() == 0UL )
         return;


      //=====================================================================================
      // Submatrix-wise minimum
      //=====================================================================================

      // Submatrix-wise minimum with the given matrices
      {
         test_  = "Submatrix-wise minimum with the given matrices";
         error_ = "Failed minimum operation";

         try {
            initResults();
            for( size_t row=0UL, m=0UL; row<lhs_.rows(); row+=m ) {
               m = blaze::rand<size_t>( 1UL, lhs_.rows() - row );
               for( size_t column=0UL, n=0UL; column<rhs_.columns(); column+=n ) {
                  n = blaze::rand<size_t>( 1UL, rhs_.columns() - column );
                  submatrix( dres_  , row, column, m, n ) = submatrix( min( lhs_, rhs_ ), row, column, m, n );
                  submatrix( odres_ , row, column, m, n ) = submatrix( min( lhs_, rhs_ ), row, column, m, n );
                  submatrix( sres_  , row, column, m, n ) = submatrix( min( lhs_, rhs_ ), row, column, m, n );
                  submatrix( osres_ , row, column, m, n ) = submatrix( min( lhs_, rhs_ ), row, column, m, n );
                  submatrix( refres_, row, column, m, n ) = submatrix( ref_             , row, column, m, n );
               }
            }
         }
         catch( std::exception& ex ) {
            convertException<MT1,MT2>( ex );
         }

         checkResults<MT1,MT2>();

         try {
            initResults();
            for( size_t row=0UL, m=0UL; row<lhs_.rows(); row+=m ) {
               m = blaze::rand<size_t>( 1UL, lhs_.rows() - row );
               for( size_t column=0UL, n=0UL; column<orhs_.columns(); column+=n ) {
                  n = blaze::rand<size_t>( 1UL, orhs_.columns() - column );
                  submatrix( dres_  , row, column, m, n ) = submatrix( min( lhs_, orhs_ ), row, column, m, n );
                  submatrix( odres_ , row, column, m, n ) = submatrix( min( lhs_, orhs_ ), row, column, m, n );
                  submatrix( sres_  , row, column, m, n ) = submatrix( min( lhs_, orhs_ ), row, column, m, n );
                  submatrix( osres_ , row, column, m, n ) = submatrix( min( lhs_, orhs_ ), row, column, m, n );
                  submatrix( refres_, row, column, m, n ) = submatrix( ref_              , row, column, m, n );
               }
            }
         }
         catch( std::exception& ex ) {
            convertException<MT1,OMT2>( ex );
         }

         checkResults<MT1,OMT2>();

         try {
            initResults();
            for( size_t row=0UL, m=0UL; row<lhs_.rows(); row+=m ) {
               m = blaze::rand<size_t>( 1UL, lhs_.rows() - row );
               for( size_t column=0UL, n=0UL; column<rhs_.columns(); column+=n ) {
                  n = blaze::rand<size_t>( 1UL, rhs_.columns() - column );
                  submatrix( dres_  , row, column, m, n ) = submatrix( min( olhs_, rhs_ ), row, column, m, n );
                  submatrix( odres_ , row, column, m, n ) = submatrix( min( olhs_, rhs_ ), row, column, m, n );
                  submatrix( sres_  , row, column, m, n ) = submatrix( min( olhs_, rhs_ ), row, column, m, n );
                  submatrix( osres_ , row, column, m, n ) = submatrix( min( olhs_, rhs_ ), row, column, m, n );
                  submatrix( refres_, row, column, m, n ) = submatrix( ref_              , row, column, m, n );
               }
            }
         }
         catch( std::exception& ex ) {
            convertException<OMT1,MT2>( ex );
         }

         checkResults<OMT1,MT2>();

         try {
            initResults();
            for( size_t row=0UL, m=0UL; row<lhs_.rows(); row+=m ) {
               m = blaze::rand<size_t>( 1UL, lhs_.rows() - row );
               for( size_t column=0UL, n=0UL; column<orhs_.columns(); column+=n ) {
                  n = blaze::rand<size_t>( 1UL, orhs_.columns() - column );
                  submatrix( dres_  , row, column, m, n ) = submatrix( min( olhs_, orhs_ ), row, column, m, n );
                  submatrix( odres_ , row, column, m, n ) = submatrix( min( olhs_, orhs_ ), row, column, m, n );
                  submatrix( sres_  , row, column, m, n ) = submatrix( min( olhs_, orhs_ ), row, column, m, n );
                  submatrix( osres_ , row, column, m, n ) = submatrix( min( olhs_, orhs_ ), row, column, m, n );
                  submatrix( refres_, row, column, m, n ) = submatrix( ref_               , row, column, m, n );
               }
            }
         }
         catch( std::exception& ex ) {
            convertException<OMT1,OMT2>( ex );
         }

         checkResults<OMT1,OMT2>();
      }

      // Submatrix-wise minimum with evaluated matrices
      {
         test_  = "Submatrix-wise minimum with evaluated matrices";
         error_ = "Failed minimum operation";

         try {
            initResults();
            for( size_t row=0UL, m=0UL; row<lhs_.rows(); row+=m ) {
               m = blaze::rand<size_t>( 1UL, lhs_.rows() - row );
               for( size_t column=0UL, n=0UL; column<rhs_.columns(); column+=n ) {
                  n = blaze::rand<size_t>( 1UL, rhs_.columns() - column );
                  submatrix( dres_  , row, column, m, n ) = submatrix( min( eval( lhs_ ), eval( rhs_ ) ), row, column, m, n );
                  submatrix( odres_ , row, column, m, n ) = submatrix( min( eval( lhs_ ), eval( rhs_ ) ), row, column, m, n );
                  submatrix( sres_  , row, column, m, n ) = submatrix( min( eval( lhs_ ), eval( rhs_ ) ), row, column, m, n );
                  submatrix( osres_ , row, column, m, n ) = submatrix( min( eval( lhs_ ), eval( rhs_ ) ), row, column, m, n );
                  submatrix( refres_, row, column, m, n ) = submatrix( eval( ref_ )                     , row, column, m, n );
               }
            }
         }
         catch( std::exception& ex ) {
            convertException<MT1,MT2>( ex );
         }

         checkResults<MT1,MT2>();

         try {
            initResults();
            for( size_t row=0UL, m=0UL; row<lhs_.rows(); row+=m ) {
               m = blaze::rand<size_t>( 1UL, lhs_.rows() - row );
               for( size_t column=0UL, n=0UL; column<orhs_.columns(); column+=n ) {
                  n = blaze::rand<size_t>( 1UL, orhs_.columns() - column );
                  submatrix( dres_  , row, column, m, n ) = submatrix( min( eval( lhs_ ), eval( orhs_ ) ), row, column, m, n );
                  submatrix( odres_ , row, column, m, n ) = submatrix( min( eval( lhs_ ), eval( orhs_ ) ), row, column, m, n );
                  submatrix( sres_  , row, column, m, n ) = submatrix( min( eval( lhs_ ), eval( orhs_ ) ), row, column, m, n );
                  submatrix( osres_ , row, column, m, n ) = submatrix( min( eval( lhs_ ), eval( orhs_ ) ), row, column, m, n );
                  submatrix( refres_, row, column, m, n ) = submatrix( eval( ref_ )                      , row, column, m, n );
               }
            }
         }
         catch( std::exception& ex ) {
            convertException<MT1,OMT2>( ex );
         }

         checkResults<MT1,OMT2>();

         try {
            initResults();
            for( size_t row=0UL, m=0UL; row<lhs_.rows(); row+=m ) {
               m = blaze::rand<size_t>( 1UL, lhs_.rows() - row );
               for( size_t column=0UL, n=0UL; column<rhs_.columns(); column+=n ) {
                  n = blaze::rand<size_t>( 1UL, rhs_.columns() - column );
                  submatrix( dres_  , row, column, m, n ) = submatrix( min( eval( olhs_ ), eval( rhs_ ) ), row, column, m, n );
                  submatrix( odres_ , row, column, m, n ) = submatrix( min( eval( olhs_ ), eval( rhs_ ) ), row, column, m, n );
                  submatrix( sres_  , row, column, m, n ) = submatrix( min( eval( olhs_ ), eval( rhs_ ) ), row, column, m, n );
                  submatrix( osres_ , row, column, m, n ) = submatrix( min( eval( olhs_ ), eval( rhs_ ) ), row, column, m, n );
                  submatrix( refres_, row, column, m, n ) = submatrix( eval( ref_ )                      , row, column, m, n );
               }
            }
         }
         catch( std::exception& ex ) {
            convertException<OMT1,MT2>( ex );
         }

         checkResults<OMT1,MT2>();

         try {
            initResults();
            for( size_t row=0UL, m=0UL; row<lhs_.rows(); row+=m ) {
               m = blaze::rand<size_t>( 1UL, lhs_.rows() - row );
               for( size_t column=0UL, n=0UL; column<orhs_.columns(); column+=n ) {
                  n = blaze::rand<size_t>( 1UL, orhs_.columns() - column );
                  submatrix( dres_  , row, column, m, n ) = submatrix( min( eval( olhs_ ), eval( orhs_ ) ), row, column, m, n );
                  submatrix( odres_ , row, column, m, n ) = submatrix( min( eval( olhs_ ), eval( orhs_ ) ), row, column, m, n );
                  submatrix( sres_  , row, column, m, n ) = submatrix( min( eval( olhs_ ), eval( orhs_ ) ), row, column, m, n );
                  submatrix( osres_ , row, column, m, n ) = submatrix( min( eval( olhs_ ), eval( orhs_ ) ), row, column, m, n );
                  submatrix( refres_, row, column, m, n ) = submatrix( eval( ref_ )                       , row, column, m, n );
               }
            }
         }
         catch( std::exception& ex ) {
            convertException<OMT1,OMT2>( ex );
         }

         checkResults<OMT1,OMT2>();
      }


      //=====================================================================================
      // Submatrix-wise minimum with addition assignment
      //=====================================================================================

      // Submatrix-wise minimum with addition assignment with the given matrices
      {
         test_  = "Submatrix-wise minimum with addition assignment with the given matrices";
         error_ = "Failed addition assignment operation";

         try {
            initResults();
            for( size_t row=0UL, m=0UL; row<lhs_.rows(); row+=m ) {
               m = blaze::rand<size_t>( 1UL, lhs_.rows() - row );
               for( size_t column=0UL, n=0UL; column<rhs_.columns(); column+=n ) {
                  n = blaze::rand<size_t>( 1UL, rhs_.columns() - column );
                  submatrix( dres_  , row, column, m, n ) += submatrix( min( lhs_, rhs_ ), row, column, m, n );
                  submatrix( odres_ , row, column, m, n ) += submatrix( min( lhs_, rhs_ ), row, column, m, n );
                  submatrix( sres_  , row, column, m, n ) += submatrix( min( lhs_, rhs_ ), row, column, m, n );
                  submatrix( osres_ , row, column, m, n ) += submatrix( min( lhs_, rhs_ ), row, column, m, n );
                  submatrix( refres_, row, column, m, n ) += submatrix( ref_             , row, column, m, n );
               }
            }
         }
         catch( std::exception& ex ) {
            convertException<MT1,MT2>( ex );
         }

         checkResults<MT1,MT2>();

         try {
            initResults();
            for( size_t row=0UL, m=0UL; row<lhs_.rows(); row+=m ) {
               m = blaze::rand<size_t>( 1UL, lhs_.rows() - row );
               for( size_t column=0UL, n=0UL; column<orhs_.columns(); column+=n ) {
                  n = blaze::rand<size_t>( 1UL, orhs_.columns() - column );
                  submatrix( dres_  , row, column, m, n ) += submatrix( min( lhs_, orhs_ ), row, column, m, n );
                  submatrix( odres_ , row, column, m, n ) += submatrix( min( lhs_, orhs_ ), row, column, m, n );
                  submatrix( sres_  , row, column, m, n ) += submatrix( min( lhs_, orhs_ ), row, column, m, n );
                  submatrix( osres_ , row, column, m, n ) += submatrix( min( lhs_, orhs_ ), row, column, m, n );
                  submatrix( refres_, row, column, m, n ) += submatrix( ref_              , row, column, m, n );
               }
            }
         }
         catch( std::exception& ex ) {
            convertException<MT1,OMT2>( ex );
         }

         checkResults<MT1,OMT2>();

         try {
            initResults();
            for( size_t row=0UL, m=0UL; row<lhs_.rows(); row+=m ) {
               m = blaze::rand<size_t>( 1UL, lhs_.rows() - row );
               for( size_t column=0UL, n=0UL; column<rhs_.columns(); column+=n ) {
                  n = blaze::rand<size_t>( 1UL, rhs_.columns() - column );
                  submatrix( dres_  , row, column, m, n ) += submatrix( min( olhs_, rhs_ ), row, column, m, n );
                  submatrix( odres_ , row, column, m, n ) += submatrix( min( olhs_, rhs_ ), row, column, m, n );
                  submatrix( sres_  , row, column, m, n ) += submatrix( min( olhs_, rhs_ ), row, column, m, n );
                  submatrix( osres_ , row, column, m, n ) += submatrix( min( olhs_, rhs_ ), row, column, m, n );
                  submatrix( refres_, row, column, m, n ) += submatrix( ref_              , row, column, m, n );
               }
            }
         }
         catch( std::exception& ex ) {
            convertException<OMT1,MT2>( ex );
         }

         checkResults<OMT1,MT2>();

         try {
            initResults();
            for( size_t row=0UL, m=0UL; row<lhs_.rows(); row+=m ) {
               m = blaze::rand<size_t>( 1UL, lhs_.rows() - row );
               for( size_t column=0UL, n=0UL; column<orhs_.columns(); column+=n ) {
                  n = blaze::rand<size_t>( 1UL, orhs_.columns() - column );
                  submatrix( dres_  , row, column, m, n ) += submatrix( min( olhs_, orhs_ ), row, column, m, n );
                  submatrix( odres_ , row, column, m, n ) += submatrix( min( olhs_, orhs_ ), row, column, m, n );
                  submatrix( sres_  , row, column, m, n ) += submatrix( min( olhs_, orhs_ ), row, column, m, n );
                  submatrix( osres_ , row, column, m, n ) += submatrix( min( olhs_, orhs_ ), row, column, m, n );
                  submatrix( refres_, row, column, m, n ) += submatrix( ref_               , row, column, m, n );
               }
            }
         }
         catch( std::exception& ex ) {
            convertException<OMT1,OMT2>( ex );
         }

         checkResults<OMT1,OMT2>();
      }

      // Submatrix-wise minimum with addition assignment with evaluated matrices
      {
         test_  = "Submatrix-wise minimum with addition assignment with evaluated matrices";
         error_ = "Failed addition assignment operation";

         try {
            initResults();
            for( size_t row=0UL, m=0UL; row<lhs_.rows(); row+=m ) {
               m = blaze::rand<size_t>( 1UL, lhs_.rows() - row );
               for( size_t column=0UL, n=0UL; column<rhs_.columns(); column+=n ) {
                  n = blaze::rand<size_t>( 1UL, rhs_.columns() - column );
                  submatrix( dres_  , row, column, m, n ) += submatrix( min( eval( lhs_ ), eval( rhs_ ) ), row, column, m, n );
                  submatrix( odres_ , row, column, m, n ) += submatrix( min( eval( lhs_ ), eval( rhs_ ) ), row, column, m, n );
                  submatrix( sres_  , row, column, m, n ) += submatrix( min( eval( lhs_ ), eval( rhs_ ) ), row, column, m, n );
                  submatrix( osres_ , row, column, m, n ) += submatrix( min( eval( lhs_ ), eval( rhs_ ) ), row, column, m, n );
                  submatrix( refres_, row, column, m, n ) += submatrix( eval( ref_ )                     , row, column, m, n );
               }
            }
         }
         catch( std::exception& ex ) {
            convertException<MT1,MT2>( ex );
         }

         checkResults<MT1,MT2>();

         try {
            initResults();
            for( size_t row=0UL, m=0UL; row<lhs_.rows(); row+=m ) {
               m = blaze::rand<size_t>( 1UL, lhs_.rows() - row );
               for( size_t column=0UL, n=0UL; column<orhs_.columns(); column+=n ) {
                  n = blaze::rand<size_t>( 1UL, orhs_.columns() - column );
                  submatrix( dres_  , row, column, m, n ) += submatrix( min( eval( lhs_ ), eval( orhs_ ) ), row, column, m, n );
                  submatrix( odres_ , row, column, m, n ) += submatrix( min( eval( lhs_ ), eval( orhs_ ) ), row, column, m, n );
                  submatrix( sres_  , row, column, m, n ) += submatrix( min( eval( lhs_ ), eval( orhs_ ) ), row, column, m, n );
                  submatrix( osres_ , row, column, m, n ) += submatrix( min( eval( lhs_ ), eval( orhs_ ) ), row, column, m, n );
                  submatrix( refres_, row, column, m, n ) += submatrix( eval( ref_ )                      , row, column, m, n );
               }
            }
         }
         catch( std::exception& ex ) {
            convertException<MT1,OMT2>( ex );
         }

         checkResults<MT1,OMT2>();

         try {
            initResults();
            for( size_t row=0UL, m=0UL; row<lhs_.rows(); row+=m ) {
               m = blaze::rand<size_t>( 1UL, lhs_.rows() - row );
               for( size_t column=0UL, n=0UL; column<rhs_.columns(); column+=n ) {
                  n = blaze::rand<size_t>( 1UL, rhs_.columns() - column );
                  submatrix( dres_  , row, column, m, n ) += submatrix( min( eval( olhs_ ), eval( rhs_ ) ), row, column, m, n );
                  submatrix( odres_ , row, column, m, n ) += submatrix( min( eval( olhs_ ), eval( rhs_ ) ), row, column, m, n );
                  submatrix( sres_  , row, column, m, n ) += submatrix( min( eval( olhs_ ), eval( rhs_ ) ), row, column, m, n );
                  submatrix( osres_ , row, column, m, n ) += submatrix( min( eval( olhs_ ), eval( rhs_ ) ), row, column, m, n );
                  submatrix( refres_, row, column, m, n ) += submatrix( eval( ref_ )                      , row, column, m, n );
               }
            }
         }
         catch( std::exception& ex ) {
            convertException<OMT1,MT2>( ex );
         }

         checkResults<OMT1,MT2>();

         try {
            initResults();
            for( size_t row=0UL, m=0UL; row<lhs_.rows(); row+=m ) {
               m = blaze::rand<size_t>( 1UL, lhs_.rows() - row );
               for( size_t column=0UL, n=0UL; column<orhs_.columns(); column+=n ) {
                  n = blaze::rand<size_t>( 1UL, orhs_.columns() - column );
                  submatrix( dres_  , row, column, m, n ) += submatrix( min( eval( olhs_ ), eval( orhs_ ) ), row, column, m, n );
                  submatrix( odres_ , row, column, m, n ) += submatrix( min( eval( olhs_ ), eval( orhs_ ) ), row, column, m, n );
                  submatrix( sres_  , row, column, m, n ) += submatrix( min( eval( olhs_ ), eval( orhs_ ) ), row, column, m, n );
                  submatrix( osres_ , row, column, m, n ) += submatrix( min( eval( olhs_ ), eval( orhs_ ) ), row, column, m, n );
                  submatrix( refres_, row, column, m, n ) += submatrix( eval( ref_ )                       , row, column, m, n );
               }
            }
         }
         catch( std::exception& ex ) {
            convertException<OMT1,OMT2>( ex );
         }

         checkResults<OMT1,OMT2>();
      }


      //=====================================================================================
      // Submatrix-wise minimum with subtraction assignment
      //=====================================================================================

      // Submatrix-wise minimum with subtraction assignment with the given matrices
      {
         test_  = "Submatrix-wise minimum with subtraction assignment with the given matrices";
         error_ = "Failed subtraction assignment operation";

         try {
            initResults();
            for( size_t row=0UL, m=0UL; row<lhs_.rows(); row+=m ) {
               m = blaze::rand<size_t>( 1UL, lhs_.rows() - row );
               for( size_t column=0UL, n=0UL; column<rhs_.columns(); column+=n ) {
                  n = blaze::rand<size_t>( 1UL, rhs_.columns() - column );
                  submatrix( dres_  , row, column, m, n ) -= submatrix( min( lhs_, rhs_ ), row, column, m, n );
                  submatrix( odres_ , row, column, m, n ) -= submatrix( min( lhs_, rhs_ ), row, column, m, n );
                  submatrix( sres_  , row, column, m, n ) -= submatrix( min( lhs_, rhs_ ), row, column, m, n );
                  submatrix( osres_ , row, column, m, n ) -= submatrix( min( lhs_, rhs_ ), row, column, m, n );
                  submatrix( refres_, row, column, m, n ) -= submatrix( ref_             , row, column, m, n );
               }
            }
         }
         catch( std::exception& ex ) {
            convertException<MT1,MT2>( ex );
         }

         checkResults<MT1,MT2>();

         try {
            initResults();
            for( size_t row=0UL, m=0UL; row<lhs_.rows(); row+=m ) {
               m = blaze::rand<size_t>( 1UL, lhs_.rows() - row );
               for( size_t column=0UL, n=0UL; column<orhs_.columns(); column+=n ) {
                  n = blaze::rand<size_t>( 1UL, orhs_.columns() - column );
                  submatrix( dres_  , row, column, m, n ) -= submatrix( min( lhs_, orhs_ ), row, column, m, n );
                  submatrix( odres_ , row, column, m, n ) -= submatrix( min( lhs_, orhs_ ), row, column, m, n );
                  submatrix( sres_  , row, column, m, n ) -= submatrix( min( lhs_, orhs_ ), row, column, m, n );
                  submatrix( osres_ , row, column, m, n ) -= submatrix( min( lhs_, orhs_ ), row, column, m, n );
                  submatrix( refres_, row, column, m, n ) -= submatrix( ref_              , row, column, m, n );
               }
            }
         }
         catch( std::exception& ex ) {
            convertException<MT1,OMT2>( ex );
         }

         checkResults<MT1,OMT2>();

         try {
            initResults();
            for( size_t row=0UL, m=0UL; row<lhs_.rows(); row+=m ) {
               m = blaze::rand<size_t>( 1UL, lhs_.rows() - row );
               for( size_t column=0UL, n=0UL; column<rhs_.columns(); column+=n ) {
                  n = blaze::rand<size_t>( 1UL, rhs_.columns() - column );
                  submatrix( dres_  , row, column, m, n ) -= submatrix( min( olhs_, rhs_ ), row, column, m, n );
                  submatrix( odres_ , row, column, m, n ) -= submatrix( min( olhs_, rhs_ ), row, column, m, n );
                  submatrix( sres_  , row, column, m, n ) -= submatrix( min( olhs_, rhs_ ), row, column, m, n );
                  submatrix( osres_ , row, column, m, n ) -= submatrix( min( olhs_, rhs_ ), row, column, m, n );
                  submatrix( refres_, row, column, m, n ) -= submatrix( ref_              , row, column, m, n );
               }
            }
         }
         catch( std::exception& ex ) {
            convertException<OMT1,MT2>( ex );
         }

         checkResults<OMT1,MT2>();

         try {
            initResults();
            for( size_t row=0UL, m=0UL; row<lhs_.rows(); row+=m ) {
               m = blaze::rand<size_t>( 1UL, lhs_.rows() - row );
               for( size_t column=0UL, n=0UL; column<orhs_.columns(); column+=n ) {
                  n = blaze::rand<size_t>( 1UL, orhs_.columns() - column );
                  submatrix( dres_  , row, column, m, n ) -= submatrix( min( olhs_, orhs_ ), row, column, m, n );
                  submatrix( odres_ , row, column, m, n ) -= submatrix( min( olhs_, orhs_ ), row, column, m, n );
                  submatrix( sres_  , row, column, m, n ) -= submatrix( min( olhs_, orhs_ ), row, column, m, n );
                  submatrix( osres_ , row, column, m, n ) -= submatrix( min( olhs_, orhs_ ), row, column, m, n );
                  submatrix( refres_, row, column, m, n ) -= submatrix( ref_               , row, column, m, n );
               }
            }
         }
         catch( std::exception& ex ) {
            convertException<OMT1,OMT2>( ex );
         }

         checkResults<OMT1,OMT2>();
      }

      // Submatrix-wise minimum with subtraction assignment with evaluated matrices
      {
         test_  = "Submatrix-wise minimum with subtraction assignment with evaluated matrices";
         error_ = "Failed subtraction assignment operation";

         try {
            initResults();
            for( size_t row=0UL, m=0UL; row<lhs_.rows(); row+=m ) {
               m = blaze::rand<size_t>( 1UL, lhs_.rows() - row );
               for( size_t column=0UL, n=0UL; column<rhs_.columns(); column+=n ) {
                  n = blaze::rand<size_t>( 1UL, rhs_.columns() - column );
                  submatrix( dres_  , row, column, m, n ) -= submatrix( min( eval( lhs_ ), eval( rhs_ ) ), row, column, m, n );
                  submatrix( odres_ , row, column, m, n ) -= submatrix( min( eval( lhs_ ), eval( rhs_ ) ), row, column, m, n );
                  submatrix( sres_  , row, column, m, n ) -= submatrix( min( eval( lhs_ ), eval( rhs_ ) ), row, column, m, n );
                  submatrix( osres_ , row, column, m, n ) -= submatrix( min( eval( lhs_ ), eval( rhs_ ) ), row, column, m, n );
                  submatrix( refres_, row, column, m, n ) -= submatrix( eval( ref_ )                     , row, column, m, n );
               }
            }
         }
         catch( std::exception& ex ) {
            convertException<MT1,MT2>( ex );
         }

         checkResults<MT1,MT2>();

         try {
            initResults();
            for( size_t row=0UL, m=0UL; row<lhs_.rows(); row+=m ) {
               m = blaze::rand<size_t>( 1UL, lhs_.rows() - row );
               for( size_t column=0UL, n=0UL; column<orhs_.columns(); column+=n ) {
                  n = blaze::rand<size_t>( 1UL, orhs_.columns() - column );
                  submatrix( dres_  , row, column, m, n ) -= submatrix( min( eval( lhs_ ), eval( orhs_ ) ), row, column, m, n );
                  submatrix( odres_ , row, column, m, n ) -= submatrix( min( eval( lhs_ ), eval( orhs_ ) ), row, column, m, n );
                  submatrix( sres_  , row, column, m, n ) -= submatrix( min( eval( lhs_ ), eval( orhs_ ) ), row, column, m, n );
                  submatrix( osres_ , row, column, m, n ) -= submatrix( min( eval( lhs_ ), eval( orhs_ ) ), row, column, m, n );
                  submatrix( refres_, row, column, m, n ) -= submatrix( eval( ref_ )                      , row, column, m, n );
               }
            }
         }
         catch( std::exception& ex ) {
            convertException<MT1,OMT2>( ex );
         }

         checkResults<MT1,OMT2>();

         try {
            initResults();
            for( size_t row=0UL, m=0UL; row<lhs_.rows(); row+=m ) {
               m = blaze::rand<size_t>( 1UL, lhs_.rows() - row );
               for( size_t column=0UL, n=0UL; column<rhs_.columns(); column+=n ) {
                  n = blaze::rand<size_t>( 1UL, rhs_.columns() - column );
                  submatrix( dres_  , row, column, m, n ) -= submatrix( min( eval( olhs_ ), eval( rhs_ ) ), row, column, m, n );
                  submatrix( odres_ , row, column, m, n ) -= submatrix( min( eval( olhs_ ), eval( rhs_ ) ), row, column, m, n );
                  submatrix( sres_  , row, column, m, n ) -= submatrix( min( eval( olhs_ ), eval( rhs_ ) ), row, column, m, n );
                  submatrix( osres_ , row, column, m, n ) -= submatrix( min( eval( olhs_ ), eval( rhs_ ) ), row, column, m, n );
                  submatrix( refres_, row, column, m, n ) -= submatrix( eval( ref_ )                      , row, column, m, n );
               }
            }
         }
         catch( std::exception& ex ) {
            convertException<OMT1,MT2>( ex );
         }

         checkResults<OMT1,MT2>();

         try {
            initResults();
            for( size_t row=0UL, m=0UL; row<lhs_.rows(); row+=m ) {
               m = blaze::rand<size_t>( 1UL, lhs_.rows() - row );
               for( size_t column=0UL, n=0UL; column<orhs_.columns(); column+=n ) {
                  n = blaze::rand<size_t>( 1UL, orhs_.columns() - column );
                  submatrix( dres_  , row, column, m, n ) -= submatrix( min( eval( olhs_ ), eval( orhs_ ) ), row, column, m, n );
                  submatrix( odres_ , row, column, m, n ) -= submatrix( min( eval( olhs_ ), eval( orhs_ ) ), row, column, m, n );
                  submatrix( sres_  , row, column, m, n ) -= submatrix( min( eval( olhs_ ), eval( orhs_ ) ), row, column, m, n );
                  submatrix( osres_ , row, column, m, n ) -= submatrix( min( eval( olhs_ ), eval( orhs_ ) ), row, column, m, n );
                  submatrix( refres_, row, column, m, n ) -= submatrix( eval( ref_ )                       , row, column, m, n );
               }
            }
         }
         catch( std::exception& ex ) {
            convertException<OMT1,OMT2>( ex );
         }

         checkResults<OMT1,OMT2>();
      }


      //=====================================================================================
      // Submatrix-wise minimum with Schur product assignment
      //=====================================================================================

      // Submatrix-wise minimum with Schur product assignment with the given matrices
      {
         test_  = "Submatrix-wise minimum with Schur product assignment with the given matrices";
         error_ = "Failed Schur product assignment operation";

         try {
            initResults();
            for( size_t row=0UL, m=0UL; row<lhs_.rows(); row+=m ) {
               m = blaze::rand<size_t>( 1UL, lhs_.rows() - row );
               for( size_t column=0UL, n=0UL; column<rhs_.columns(); column+=n ) {
                  n = blaze::rand<size_t>( 1UL, rhs_.columns() - column );
                  submatrix( dres_  , row, column, m, n ) %= submatrix( min( lhs_, rhs_ ), row, column, m, n );
                  submatrix( odres_ , row, column, m, n ) %= submatrix( min( lhs_, rhs_ ), row, column, m, n );
                  submatrix( sres_  , row, column, m, n ) %= submatrix( min( lhs_, rhs_ ), row, column, m, n );
                  submatrix( osres_ , row, column, m, n ) %= submatrix( min( lhs_, rhs_ ), row, column, m, n );
                  submatrix( refres_, row, column, m, n ) %= submatrix( ref_             , row, column, m, n );
               }
            }
         }
         catch( std::exception& ex ) {
            convertException<MT1,MT2>( ex );
         }

         checkResults<MT1,MT2>();

         try {
            initResults();
            for( size_t row=0UL, m=0UL; row<lhs_.rows(); row+=m ) {
               m = blaze::rand<size_t>( 1UL, lhs_.rows() - row );
               for( size_t column=0UL, n=0UL; column<orhs_.columns(); column+=n ) {
                  n = blaze::rand<size_t>( 1UL, orhs_.columns() - column );
                  submatrix( dres_  , row, column, m, n ) %= submatrix( min( lhs_, orhs_ ), row, column, m, n );
                  submatrix( odres_ , row, column, m, n ) %= submatrix( min( lhs_, orhs_ ), row, column, m, n );
                  submatrix( sres_  , row, column, m, n ) %= submatrix( min( lhs_, orhs_ ), row, column, m, n );
                  submatrix( osres_ , row, column, m, n ) %= submatrix( min( lhs_, orhs_ ), row, column, m, n );
                  submatrix( refres_, row, column, m, n ) %= submatrix( ref_              , row, column, m, n );
               }
            }
         }
         catch( std::exception& ex ) {
            convertException<MT1,OMT2>( ex );
         }

         checkResults<MT1,OMT2>();

         try {
            initResults();
            for( size_t row=0UL, m=0UL; row<lhs_.rows(); row+=m ) {
               m = blaze::rand<size_t>( 1UL, lhs_.rows() - row );
               for( size_t column=0UL, n=0UL; column<rhs_.columns(); column+=n ) {
                  n = blaze::rand<size_t>( 1UL, rhs_.columns() - column );
                  submatrix( dres_  , row, column, m, n ) %= submatrix( min( olhs_, rhs_ ), row, column, m, n );
                  submatrix( odres_ , row, column, m, n ) %= submatrix( min( olhs_, rhs_ ), row, column, m, n );
                  submatrix( sres_  , row, column, m, n ) %= submatrix( min( olhs_, rhs_ ), row, column, m, n );
                  submatrix( osres_ , row, column, m, n ) %= submatrix( min( olhs_, rhs_ ), row, column, m, n );
                  submatrix( refres_, row, column, m, n ) %= submatrix( ref_              , row, column, m, n );
               }
            }
         }
         catch( std::exception& ex ) {
            convertException<OMT1,MT2>( ex );
         }

         checkResults<OMT1,MT2>();

         try {
            initResults();
            for( size_t row=0UL, m=0UL; row<lhs_.rows(); row+=m ) {
               m = blaze::rand<size_t>( 1UL, lhs_.rows() - row );
               for( size_t column=0UL, n=0UL; column<orhs_.columns(); column+=n ) {
                  n = blaze::rand<size_t>( 1UL, orhs_.columns() - column );
                  submatrix( dres_  , row, column, m, n ) %= submatrix( min( olhs_, orhs_ ), row, column, m, n );
                  submatrix( odres_ , row, column, m, n ) %= submatrix( min( olhs_, orhs_ ), row, column, m, n );
                  submatrix( sres_  , row, column, m, n ) %= submatrix( min( olhs_, orhs_ ), row, column, m, n );
                  submatrix( osres_ , row, column, m, n ) %= submatrix( min( olhs_, orhs_ ), row, column, m, n );
                  submatrix( refres_, row, column, m, n ) %= submatrix( ref_               , row, column, m, n );
               }
            }
         }
         catch( std::exception& ex ) {
            convertException<OMT1,OMT2>( ex );
         }

         checkResults<OMT1,OMT2>();
      }

      // Submatrix-wise minimum with Schur product assignment with evaluated matrices
      {
         test_  = "Submatrix-wise minimum with Schur product assignment with evaluated matrices";
         error_ = "Failed Schur product assignment operation";

         try {
            initResults();
            for( size_t row=0UL, m=0UL; row<lhs_.rows(); row+=m ) {
               m = blaze::rand<size_t>( 1UL, lhs_.rows() - row );
               for( size_t column=0UL, n=0UL; column<rhs_.columns(); column+=n ) {
                  n = blaze::rand<size_t>( 1UL, rhs_.columns() - column );
                  submatrix( dres_  , row, column, m, n ) %= submatrix( min( eval( lhs_ ), eval( rhs_ ) ), row, column, m, n );
                  submatrix( odres_ , row, column, m, n ) %= submatrix( min( eval( lhs_ ), eval( rhs_ ) ), row, column, m, n );
                  submatrix( sres_  , row, column, m, n ) %= submatrix( min( eval( lhs_ ), eval( rhs_ ) ), row, column, m, n );
                  submatrix( osres_ , row, column, m, n ) %= submatrix( min( eval( lhs_ ), eval( rhs_ ) ), row, column, m, n );
                  submatrix( refres_, row, column, m, n ) %= submatrix( eval( ref_ )                     , row, column, m, n );
               }
            }
         }
         catch( std::exception& ex ) {
            convertException<MT1,MT2>( ex );
         }

         checkResults<MT1,MT2>();

         try {
            initResults();
            for( size_t row=0UL, m=0UL; row<lhs_.rows(); row+=m ) {
               m = blaze::rand<size_t>( 1UL, lhs_.rows() - row );
               for( size_t column=0UL, n=0UL; column<orhs_.columns(); column+=n ) {
                  n = blaze::rand<size_t>( 1UL, orhs_.columns() - column );
                  submatrix( dres_  , row, column, m, n ) %= submatrix( min( eval( lhs_ ), eval( orhs_ ) ), row, column, m, n );
                  submatrix( odres_ , row, column, m, n ) %= submatrix( min( eval( lhs_ ), eval( orhs_ ) ), row, column, m, n );
                  submatrix( sres_  , row, column, m, n ) %= submatrix( min( eval( lhs_ ), eval( orhs_ ) ), row, column, m, n );
                  submatrix( osres_ , row, column, m, n ) %= submatrix( min( eval( lhs_ ), eval( orhs_ ) ), row, column, m, n );
                  submatrix( refres_, row, column, m, n ) %= submatrix( eval( ref_ )                      , row, column, m, n );
               }
            }
         }
         catch( std::exception& ex ) {
            convertException<MT1,OMT2>( ex );
         }

         checkResults<MT1,OMT2>();

         try {
            initResults();
            for( size_t row=0UL, m=0UL; row<lhs_.rows(); row+=m ) {
               m = blaze::rand<size_t>( 1UL, lhs_.rows() - row );
               for( size_t column=0UL, n=0UL; column<rhs_.columns(); column+=n ) {
                  n = blaze::rand<size_t>( 1UL, rhs_.columns() - column );
                  submatrix( dres_  , row, column, m, n ) %= submatrix( min( eval( olhs_ ), eval( rhs_ ) ), row, column, m, n );
                  submatrix( odres_ , row, column, m, n ) %= submatrix( min( eval( olhs_ ), eval( rhs_ ) ), row, column, m, n );
                  submatrix( sres_  , row, column, m, n ) %= submatrix( min( eval( olhs_ ), eval( rhs_ ) ), row, column, m, n );
                  submatrix( osres_ , row, column, m, n ) %= submatrix( min( eval( olhs_ ), eval( rhs_ ) ), row, column, m, n );
                  submatrix( refres_, row, column, m, n ) %= submatrix( eval( ref_ )                      , row, column, m, n );
               }
            }
         }
         catch( std::exception& ex ) {
            convertException<OMT1,MT2>( ex );
         }

         checkResults<OMT1,MT2>();

         try {
            initResults();
            for( size_t row=0UL, m=0UL; row<lhs_.rows(); row+=m ) {
               m = blaze::rand<size_t>( 1UL, lhs_.rows() - row );
               for( size_t column=0UL, n=0UL; column<orhs_.columns(); column+=n ) {
                  n = blaze::rand<size_t>( 1UL, orhs_.columns() - column );
                  submatrix( dres_  , row, column, m, n ) %= submatrix( min( eval( olhs_ ), eval( orhs_ ) ), row, column, m, n );
                  submatrix( odres_ , row, column, m, n ) %= submatrix( min( eval( olhs_ ), eval( orhs_ ) ), row, column, m, n );
                  submatrix( sres_  , row, column, m, n ) %= submatrix( min( eval( olhs_ ), eval( orhs_ ) ), row, column, m, n );
                  submatrix( osres_ , row, column, m, n ) %= submatrix( min( eval( olhs_ ), eval( orhs_ ) ), row, column, m, n );
                  submatrix( refres_, row, column, m, n ) %= submatrix( eval( ref_ )                       , row, column, m, n );
               }
            }
         }
         catch( std::exception& ex ) {
            convertException<OMT1,OMT2>( ex );
         }

         checkResults<OMT1,OMT2>();
      }
   }
#endif
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Testing the row-wise dense matrix/dense matrix minimum operation.
//
// \return void
// \exception std::runtime_error Minimum error detected.
//
// This function tests the row-wise matrix minimum with plain assignment, addition assignment,
// subtraction assignment, and multiplication assignment. In case any error resulting from the
// minimum operation or the subsequent assignment is detected, a \a std::runtime_error exception
// is thrown.
*/
template< typename MT1    // Type of the left-hand side dense matrix
        , typename MT2 >  // Type of the right-hand side dense matrix
void OperationTest<MT1,MT2>::testRowOperation()
{
#if BLAZETEST_MATHTEST_TEST_ROW_OPERATION
   if( BLAZETEST_MATHTEST_TEST_ROW_OPERATION > 1 )
   {
      if( lhs_.rows() == 0UL )
         return;


      //=====================================================================================
      // Row-wise minimum
      //=====================================================================================

      // Row-wise minimum with the given matrices
      {
         test_  = "Row-wise minimum with the given matrices";
         error_ = "Failed minimum operation";

         try {
            initResults();
            for( size_t i=0UL; i<lhs_.rows(); ++i ) {
               row( dres_  , i ) = row( min( lhs_, rhs_ ), i );
               row( odres_ , i ) = row( min( lhs_, rhs_ ), i );
               row( sres_  , i ) = row( min( lhs_, rhs_ ), i );
               row( osres_ , i ) = row( min( lhs_, rhs_ ), i );
               row( refres_, i ) = row( ref_             , i );
            }
         }
         catch( std::exception& ex ) {
            convertException<MT1,MT2>( ex );
         }

         checkResults<MT1,MT2>();

         try {
            initResults();
            for( size_t i=0UL; i<lhs_.rows(); ++i ) {
               row( dres_  , i ) = row( min( lhs_, orhs_ ), i );
               row( odres_ , i ) = row( min( lhs_, orhs_ ), i );
               row( sres_  , i ) = row( min( lhs_, orhs_ ), i );
               row( osres_ , i ) = row( min( lhs_, orhs_ ), i );
               row( refres_, i ) = row( ref_              , i );
            }
         }
         catch( std::exception& ex ) {
            convertException<MT1,OMT2>( ex );
         }

         checkResults<MT1,OMT2>();

         try {
            initResults();
            for( size_t i=0UL; i<lhs_.rows(); ++i ) {
               row( dres_  , i ) = row( min( olhs_, rhs_ ), i );
               row( odres_ , i ) = row( min( olhs_, rhs_ ), i );
               row( sres_  , i ) = row( min( olhs_, rhs_ ), i );
               row( osres_ , i ) = row( min( olhs_, rhs_ ), i );
               row( refres_, i ) = row( ref_              , i );
            }
         }
         catch( std::exception& ex ) {
            convertException<OMT1,MT2>( ex );
         }

         checkResults<OMT1,MT2>();

         try {
            initResults();
            for( size_t i=0UL; i<lhs_.rows(); ++i ) {
               row( dres_  , i ) = row( min( olhs_, orhs_ ), i );
               row( odres_ , i ) = row( min( olhs_, orhs_ ), i );
               row( sres_  , i ) = row( min( olhs_, orhs_ ), i );
               row( osres_ , i ) = row( min( olhs_, orhs_ ), i );
               row( refres_, i ) = row( ref_               , i );
            }
         }
         catch( std::exception& ex ) {
            convertException<OMT1,OMT2>( ex );
         }

         checkResults<OMT1,OMT2>();
      }

      // Row-wise minimum with evaluated matrices
      {
         test_  = "Row-wise minimum with evaluated matrices";
         error_ = "Failed minimum operation";

         try {
            initResults();
            for( size_t i=0UL; i<lhs_.rows(); ++i ) {
               row( dres_  , i ) = row( min( eval( lhs_ ), eval( rhs_ ) ), i );
               row( odres_ , i ) = row( min( eval( lhs_ ), eval( rhs_ ) ), i );
               row( sres_  , i ) = row( min( eval( lhs_ ), eval( rhs_ ) ), i );
               row( osres_ , i ) = row( min( eval( lhs_ ), eval( rhs_ ) ), i );
               row( refres_, i ) = row( eval( ref_ )                     , i );
            }
         }
         catch( std::exception& ex ) {
            convertException<MT1,MT2>( ex );
         }

         checkResults<MT1,MT2>();

         try {
            initResults();
            for( size_t i=0UL; i<lhs_.rows(); ++i ) {
               row( dres_  , i ) = row( min( eval( lhs_ ), eval( orhs_ ) ), i );
               row( odres_ , i ) = row( min( eval( lhs_ ), eval( orhs_ ) ), i );
               row( sres_  , i ) = row( min( eval( lhs_ ), eval( orhs_ ) ), i );
               row( osres_ , i ) = row( min( eval( lhs_ ), eval( orhs_ ) ), i );
               row( refres_, i ) = row( eval( ref_ )                      , i );
            }
         }
         catch( std::exception& ex ) {
            convertException<MT1,OMT2>( ex );
         }

         checkResults<MT1,OMT2>();

         try {
            initResults();
            for( size_t i=0UL; i<lhs_.rows(); ++i ) {
               row( dres_  , i ) = row( min( eval( olhs_ ), eval( rhs_ ) ), i );
               row( odres_ , i ) = row( min( eval( olhs_ ), eval( rhs_ ) ), i );
               row( sres_  , i ) = row( min( eval( olhs_ ), eval( rhs_ ) ), i );
               row( osres_ , i ) = row( min( eval( olhs_ ), eval( rhs_ ) ), i );
               row( refres_, i ) = row( eval( ref_ )                      , i );
            }
         }
         catch( std::exception& ex ) {
            convertException<OMT1,MT2>( ex );
         }

         checkResults<OMT1,MT2>();

         try {
            initResults();
            for( size_t i=0UL; i<lhs_.rows(); ++i ) {
               row( dres_  , i ) = row( min( eval( olhs_ ), eval( orhs_ ) ), i );
               row( odres_ , i ) = row( min( eval( olhs_ ), eval( orhs_ ) ), i );
               row( sres_  , i ) = row( min( eval( olhs_ ), eval( orhs_ ) ), i );
               row( osres_ , i ) = row( min( eval( olhs_ ), eval( orhs_ ) ), i );
               row( refres_, i ) = row( eval( ref_ )                       , i );
            }
         }
         catch( std::exception& ex ) {
            convertException<OMT1,OMT2>( ex );
         }

         checkResults<OMT1,OMT2>();
      }


      //=====================================================================================
      // Row-wise minimum with addition assignment
      //=====================================================================================

      // Row-wise minimum with addition assignment with the given matrices
      {
         test_  = "Row-wise minimum with addition assignment with the given matrices";
         error_ = "Failed addition assignment operation";

         try {
            initResults();
            for( size_t i=0UL; i<lhs_.rows(); ++i ) {
               row( dres_  , i ) += row( min( lhs_, rhs_ ), i );
               row( odres_ , i ) += row( min( lhs_, rhs_ ), i );
               row( sres_  , i ) += row( min( lhs_, rhs_ ), i );
               row( osres_ , i ) += row( min( lhs_, rhs_ ), i );
               row( refres_, i ) += row( ref_             , i );
            }
         }
         catch( std::exception& ex ) {
            convertException<MT1,MT2>( ex );
         }

         checkResults<MT1,MT2>();

         try {
            initResults();
            for( size_t i=0UL; i<lhs_.rows(); ++i ) {
               row( dres_  , i ) += row( min( lhs_, orhs_ ), i );
               row( odres_ , i ) += row( min( lhs_, orhs_ ), i );
               row( sres_  , i ) += row( min( lhs_, orhs_ ), i );
               row( osres_ , i ) += row( min( lhs_, orhs_ ), i );
               row( refres_, i ) += row( ref_              , i );
            }
         }
         catch( std::exception& ex ) {
            convertException<MT1,OMT2>( ex );
         }

         checkResults<MT1,OMT2>();

         try {
            initResults();
            for( size_t i=0UL; i<lhs_.rows(); ++i ) {
               row( dres_  , i ) += row( min( olhs_, rhs_ ), i );
               row( odres_ , i ) += row( min( olhs_, rhs_ ), i );
               row( sres_  , i ) += row( min( olhs_, rhs_ ), i );
               row( osres_ , i ) += row( min( olhs_, rhs_ ), i );
               row( refres_, i ) += row( ref_              , i );
            }
         }
         catch( std::exception& ex ) {
            convertException<OMT1,MT2>( ex );
         }

         checkResults<OMT1,MT2>();

         try {
            initResults();
            for( size_t i=0UL; i<lhs_.rows(); ++i ) {
               row( dres_  , i ) += row( min( olhs_, orhs_ ), i );
               row( odres_ , i ) += row( min( olhs_, orhs_ ), i );
               row( sres_  , i ) += row( min( olhs_, orhs_ ), i );
               row( osres_ , i ) += row( min( olhs_, orhs_ ), i );
               row( refres_, i ) += row( ref_               , i );
            }
         }
         catch( std::exception& ex ) {
            convertException<OMT1,OMT2>( ex );
         }

         checkResults<OMT1,OMT2>();
      }

      // Row-wise minimum with addition assignment with evaluated matrices
      {
         test_  = "Row-wise minimum with addition assignment with evaluated matrices";
         error_ = "Failed addition assignment operation";

         try {
            initResults();
            for( size_t i=0UL; i<lhs_.rows(); ++i ) {
               row( dres_  , i ) += row( min( eval( lhs_ ), eval( rhs_ ) ), i );
               row( odres_ , i ) += row( min( eval( lhs_ ), eval( rhs_ ) ), i );
               row( sres_  , i ) += row( min( eval( lhs_ ), eval( rhs_ ) ), i );
               row( osres_ , i ) += row( min( eval( lhs_ ), eval( rhs_ ) ), i );
               row( refres_, i ) += row( eval( ref_ )                     , i );
            }
         }
         catch( std::exception& ex ) {
            convertException<MT1,MT2>( ex );
         }

         checkResults<MT1,MT2>();

         try {
            initResults();
            for( size_t i=0UL; i<lhs_.rows(); ++i ) {
               row( dres_  , i ) += row( min( eval( lhs_ ), eval( orhs_ ) ), i );
               row( odres_ , i ) += row( min( eval( lhs_ ), eval( orhs_ ) ), i );
               row( sres_  , i ) += row( min( eval( lhs_ ), eval( orhs_ ) ), i );
               row( osres_ , i ) += row( min( eval( lhs_ ), eval( orhs_ ) ), i );
               row( refres_, i ) += row( eval( ref_ ), i );
            }
         }
         catch( std::exception& ex ) {
            convertException<MT1,OMT2>( ex );
         }

         checkResults<MT1,OMT2>();

         try {
            initResults();
            for( size_t i=0UL; i<lhs_.rows(); ++i ) {
               row( dres_  , i ) += row( min( eval( olhs_ ), eval( rhs_ ) ), i );
               row( odres_ , i ) += row( min( eval( olhs_ ), eval( rhs_ ) ), i );
               row( sres_  , i ) += row( min( eval( olhs_ ), eval( rhs_ ) ), i );
               row( osres_ , i ) += row( min( eval( olhs_ ), eval( rhs_ ) ), i );
               row( refres_, i ) += row( eval( ref_ )                      , i );
            }
         }
         catch( std::exception& ex ) {
            convertException<OMT1,MT2>( ex );
         }

         checkResults<OMT1,MT2>();

         try {
            initResults();
            for( size_t i=0UL; i<lhs_.rows(); ++i ) {
               row( dres_  , i ) += row( min( eval( olhs_ ), eval( orhs_ ) ), i );
               row( odres_ , i ) += row( min( eval( olhs_ ), eval( orhs_ ) ), i );
               row( sres_  , i ) += row( min( eval( olhs_ ), eval( orhs_ ) ), i );
               row( osres_ , i ) += row( min( eval( olhs_ ), eval( orhs_ ) ), i );
               row( refres_, i ) += row( eval( ref_ )                       , i );
            }
         }
         catch( std::exception& ex ) {
            convertException<OMT1,OMT2>( ex );
         }

         checkResults<OMT1,OMT2>();
      }


      //=====================================================================================
      // Row-wise minimum with subtraction assignment
      //=====================================================================================

      // Row-wise minimum with subtraction assignment with the given matrices
      {
         test_  = "Row-wise minimum with subtraction assignment with the given matrices";
         error_ = "Failed subtraction assignment operation";

         try {
            initResults();
            for( size_t i=0UL; i<lhs_.rows(); ++i ) {
               row( dres_  , i ) -= row( min( lhs_, rhs_ ), i );
               row( odres_ , i ) -= row( min( lhs_, rhs_ ), i );
               row( sres_  , i ) -= row( min( lhs_, rhs_ ), i );
               row( osres_ , i ) -= row( min( lhs_, rhs_ ), i );
               row( refres_, i ) -= row( ref_             , i );
            }
         }
         catch( std::exception& ex ) {
            convertException<MT1,MT2>( ex );
         }

         checkResults<MT1,MT2>();

         try {
            initResults();
            for( size_t i=0UL; i<lhs_.rows(); ++i ) {
               row( dres_  , i ) -= row( min( lhs_, orhs_ ), i );
               row( odres_ , i ) -= row( min( lhs_, orhs_ ), i );
               row( sres_  , i ) -= row( min( lhs_, orhs_ ), i );
               row( osres_ , i ) -= row( min( lhs_, orhs_ ), i );
               row( refres_, i ) -= row( ref_              , i );
            }
         }
         catch( std::exception& ex ) {
            convertException<MT1,OMT2>( ex );
         }

         checkResults<MT1,OMT2>();

         try {
            initResults();
            for( size_t i=0UL; i<lhs_.rows(); ++i ) {
               row( dres_  , i ) -= row( min( olhs_, rhs_ ), i );
               row( odres_ , i ) -= row( min( olhs_, rhs_ ), i );
               row( sres_  , i ) -= row( min( olhs_, rhs_ ), i );
               row( osres_ , i ) -= row( min( olhs_, rhs_ ), i );
               row( refres_, i ) -= row( ref_              , i );
            }
         }
         catch( std::exception& ex ) {
            convertException<OMT1,MT2>( ex );
         }

         checkResults<OMT1,MT2>();

         try {
            initResults();
            for( size_t i=0UL; i<lhs_.rows(); ++i ) {
               row( dres_  , i ) -= row( min( olhs_, orhs_ ), i );
               row( odres_ , i ) -= row( min( olhs_, orhs_ ), i );
               row( sres_  , i ) -= row( min( olhs_, orhs_ ), i );
               row( osres_ , i ) -= row( min( olhs_, orhs_ ), i );
               row( refres_, i ) -= row( ref_               , i );
            }
         }
         catch( std::exception& ex ) {
            convertException<OMT1,OMT2>( ex );
         }

         checkResults<OMT1,OMT2>();
      }

      // Row-wise minimum with subtraction assignment with evaluated matrices
      {
         test_  = "Row-wise minimum with subtraction assignment with evaluated matrices";
         error_ = "Failed subtraction assignment operation";

         try {
            initResults();
            for( size_t i=0UL; i<lhs_.rows(); ++i ) {
               row( dres_  , i ) -= row( min( eval( lhs_ ), eval( rhs_ ) ), i );
               row( odres_ , i ) -= row( min( eval( lhs_ ), eval( rhs_ ) ), i );
               row( sres_  , i ) -= row( min( eval( lhs_ ), eval( rhs_ ) ), i );
               row( osres_ , i ) -= row( min( eval( lhs_ ), eval( rhs_ ) ), i );
               row( refres_, i ) -= row( eval( ref_ )                     , i );
            }
         }
         catch( std::exception& ex ) {
            convertException<MT1,MT2>( ex );
         }

         checkResults<MT1,MT2>();

         try {
            initResults();
            for( size_t i=0UL; i<lhs_.rows(); ++i ) {
               row( dres_  , i ) -= row( min( eval( lhs_ ), eval( orhs_ ) ), i );
               row( odres_ , i ) -= row( min( eval( lhs_ ), eval( orhs_ ) ), i );
               row( sres_  , i ) -= row( min( eval( lhs_ ), eval( orhs_ ) ), i );
               row( osres_ , i ) -= row( min( eval( lhs_ ), eval( orhs_ ) ), i );
               row( refres_, i ) -= row( eval( ref_ )                      , i );
            }
         }
         catch( std::exception& ex ) {
            convertException<MT1,OMT2>( ex );
         }

         checkResults<MT1,OMT2>();

         try {
            initResults();
            for( size_t i=0UL; i<lhs_.rows(); ++i ) {
               row( dres_  , i ) -= row( min( eval( olhs_ ), eval( rhs_ ) ), i );
               row( odres_ , i ) -= row( min( eval( olhs_ ), eval( rhs_ ) ), i );
               row( sres_  , i ) -= row( min( eval( olhs_ ), eval( rhs_ ) ), i );
               row( osres_ , i ) -= row( min( eval( olhs_ ), eval( rhs_ ) ), i );
               row( refres_, i ) -= row( eval( ref_ )                      , i );
            }
         }
         catch( std::exception& ex ) {
            convertException<OMT1,MT2>( ex );
         }

         checkResults<OMT1,MT2>();

         try {
            initResults();
            for( size_t i=0UL; i<lhs_.rows(); ++i ) {
               row( dres_  , i ) -= row( min( eval( olhs_ ), eval( orhs_ ) ), i );
               row( odres_ , i ) -= row( min( eval( olhs_ ), eval( orhs_ ) ), i );
               row( sres_  , i ) -= row( min( eval( olhs_ ), eval( orhs_ ) ), i );
               row( osres_ , i ) -= row( min( eval( olhs_ ), eval( orhs_ ) ), i );
               row( refres_, i ) -= row( eval( ref_ )                       , i );
            }
         }
         catch( std::exception& ex ) {
            convertException<OMT1,OMT2>( ex );
         }

         checkResults<OMT1,OMT2>();
      }


      //=====================================================================================
      // Row-wise minimum with multiplication assignment
      //=====================================================================================

      // Row-wise minimum with multiplication assignment with the given matrices
      {
         test_  = "Row-wise minimum with multiplication assignment with the given matrices";
         error_ = "Failed multiplication assignment operation";

         try {
            initResults();
            for( size_t i=0UL; i<lhs_.rows(); ++i ) {
               row( dres_  , i ) *= row( min( lhs_, rhs_ ), i );
               row( odres_ , i ) *= row( min( lhs_, rhs_ ), i );
               row( sres_  , i ) *= row( min( lhs_, rhs_ ), i );
               row( osres_ , i ) *= row( min( lhs_, rhs_ ), i );
               row( refres_, i ) *= row( ref_             , i );
            }
         }
         catch( std::exception& ex ) {
            convertException<MT1,MT2>( ex );
         }

         checkResults<MT1,MT2>();

         try {
            initResults();
            for( size_t i=0UL; i<lhs_.rows(); ++i ) {
               row( dres_  , i ) *= row( min( lhs_, orhs_ ), i );
               row( odres_ , i ) *= row( min( lhs_, orhs_ ), i );
               row( sres_  , i ) *= row( min( lhs_, orhs_ ), i );
               row( osres_ , i ) *= row( min( lhs_, orhs_ ), i );
               row( refres_, i ) *= row( ref_              , i );
            }
         }
         catch( std::exception& ex ) {
            convertException<MT1,OMT2>( ex );
         }

         checkResults<MT1,OMT2>();

         try {
            initResults();
            for( size_t i=0UL; i<lhs_.rows(); ++i ) {
               row( dres_  , i ) *= row( min( olhs_, rhs_ ), i );
               row( odres_ , i ) *= row( min( olhs_, rhs_ ), i );
               row( sres_  , i ) *= row( min( olhs_, rhs_ ), i );
               row( osres_ , i ) *= row( min( olhs_, rhs_ ), i );
               row( refres_, i ) *= row( ref_              , i );
            }
         }
         catch( std::exception& ex ) {
            convertException<OMT1,MT2>( ex );
         }

         checkResults<OMT1,MT2>();

         try {
            initResults();
            for( size_t i=0UL; i<lhs_.rows(); ++i ) {
               row( dres_  , i ) *= row( min( olhs_, orhs_ ), i );
               row( odres_ , i ) *= row( min( olhs_, orhs_ ), i );
               row( sres_  , i ) *= row( min( olhs_, orhs_ ), i );
               row( osres_ , i ) *= row( min( olhs_, orhs_ ), i );
               row( refres_, i ) *= row( ref_               , i );
            }
         }
         catch( std::exception& ex ) {
            convertException<OMT1,OMT2>( ex );
         }

         checkResults<OMT1,OMT2>();
      }

      // Row-wise minimum with multiplication assignment with evaluated matrices
      {
         test_  = "Row-wise minimum with multiplication assignment with evaluated matrices";
         error_ = "Failed multiplication assignment operation";

         try {
            initResults();
            for( size_t i=0UL; i<lhs_.rows(); ++i ) {
               row( dres_  , i ) *= row( min( eval( lhs_ ), eval( rhs_ ) ), i );
               row( odres_ , i ) *= row( min( eval( lhs_ ), eval( rhs_ ) ), i );
               row( sres_  , i ) *= row( min( eval( lhs_ ), eval( rhs_ ) ), i );
               row( osres_ , i ) *= row( min( eval( lhs_ ), eval( rhs_ ) ), i );
               row( refres_, i ) *= row( eval( ref_ )                     , i );
            }
         }
         catch( std::exception& ex ) {
            convertException<MT1,MT2>( ex );
         }

         checkResults<MT1,MT2>();

         try {
            initResults();
            for( size_t i=0UL; i<lhs_.rows(); ++i ) {
               row( dres_  , i ) *= row( min( eval( lhs_ ), eval( orhs_ ) ), i );
               row( odres_ , i ) *= row( min( eval( lhs_ ), eval( orhs_ ) ), i );
               row( sres_  , i ) *= row( min( eval( lhs_ ), eval( orhs_ ) ), i );
               row( osres_ , i ) *= row( min( eval( lhs_ ), eval( orhs_ ) ), i );
               row( refres_, i ) *= row( eval( ref_ )                      , i );
            }
         }
         catch( std::exception& ex ) {
            convertException<MT1,OMT2>( ex );
         }

         checkResults<MT1,OMT2>();

         try {
            initResults();
            for( size_t i=0UL; i<lhs_.rows(); ++i ) {
               row( dres_  , i ) *= row( min( eval( olhs_ ), eval( rhs_ ) ), i );
               row( odres_ , i ) *= row( min( eval( olhs_ ), eval( rhs_ ) ), i );
               row( sres_  , i ) *= row( min( eval( olhs_ ), eval( rhs_ ) ), i );
               row( osres_ , i ) *= row( min( eval( olhs_ ), eval( rhs_ ) ), i );
               row( refres_, i ) *= row( eval( ref_ )                      , i );
            }
         }
         catch( std::exception& ex ) {
            convertException<OMT1,MT2>( ex );
         }

         checkResults<OMT1,MT2>();

         try {
            initResults();
            for( size_t i=0UL; i<lhs_.rows(); ++i ) {
               row( dres_  , i ) *= row( min( eval( olhs_ ), eval( orhs_ ) ), i );
               row( odres_ , i ) *= row( min( eval( olhs_ ), eval( orhs_ ) ), i );
               row( sres_  , i ) *= row( min( eval( olhs_ ), eval( orhs_ ) ), i );
               row( osres_ , i ) *= row( min( eval( olhs_ ), eval( orhs_ ) ), i );
               row( refres_, i ) *= row( eval( ref_ )                       , i );
            }
         }
         catch( std::exception& ex ) {
            convertException<OMT1,OMT2>( ex );
         }

         checkResults<OMT1,OMT2>();
      }
   }
#endif
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Testing the column-wise dense matrix/dense matrix minimum operation.
//
// \return void
// \exception std::runtime_error Minimum error detected.
//
// This function tests the column-wise matrix minimum with plain assignment, addition assignment,
// subtraction assignment, and multiplication assignment. In case any error resulting from the
// minimum operation or the subsequent assignment is detected, a \a std::runtime_error exception is
// thrown.
*/
template< typename MT1    // Type of the left-hand side dense matrix
        , typename MT2 >  // Type of the right-hand side dense matrix
void OperationTest<MT1,MT2>::testColumnOperation()
{
#if BLAZETEST_MATHTEST_TEST_COLUMN_OPERATION
   if( BLAZETEST_MATHTEST_TEST_COLUMN_OPERATION > 1 )
   {
      if( lhs_.columns() == 0UL )
         return;


      //=====================================================================================
      // Column-wise minimum
      //=====================================================================================

      // Column-wise minimum with the given matrices
      {
         test_  = "Column-wise minimum with the given matrices";
         error_ = "Failed minimum operation";

         try {
            initResults();
            for( size_t j=0UL; j<lhs_.columns(); ++j ) {
               column( dres_  , j ) = column( min( lhs_, rhs_ ), j );
               column( odres_ , j ) = column( min( lhs_, rhs_ ), j );
               column( sres_  , j ) = column( min( lhs_, rhs_ ), j );
               column( osres_ , j ) = column( min( lhs_, rhs_ ), j );
               column( refres_, j ) = column( ref_             , j );
            }
         }
         catch( std::exception& ex ) {
            convertException<MT1,MT2>( ex );
         }

         checkResults<MT1,MT2>();

         try {
            initResults();
            for( size_t j=0UL; j<lhs_.columns(); ++j ) {
               column( dres_  , j ) = column( min( lhs_, orhs_ ), j );
               column( odres_ , j ) = column( min( lhs_, orhs_ ), j );
               column( sres_  , j ) = column( min( lhs_, orhs_ ), j );
               column( osres_ , j ) = column( min( lhs_, orhs_ ), j );
               column( refres_, j ) = column( ref_              , j );
            }
         }
         catch( std::exception& ex ) {
            convertException<MT1,OMT2>( ex );
         }

         checkResults<MT1,OMT2>();

         try {
            initResults();
            for( size_t j=0UL; j<lhs_.columns(); ++j ) {
               column( dres_  , j ) = column( min( olhs_, rhs_ ), j );
               column( odres_ , j ) = column( min( olhs_, rhs_ ), j );
               column( sres_  , j ) = column( min( olhs_, rhs_ ), j );
               column( osres_ , j ) = column( min( olhs_, rhs_ ), j );
               column( refres_, j ) = column( ref_              , j );
            }
         }
         catch( std::exception& ex ) {
            convertException<OMT1,MT2>( ex );
         }

         checkResults<OMT1,MT2>();

         try {
            initResults();
            for( size_t j=0UL; j<lhs_.columns(); ++j ) {
               column( dres_  , j ) = column( min( olhs_, orhs_ ), j );
               column( odres_ , j ) = column( min( olhs_, orhs_ ), j );
               column( sres_  , j ) = column( min( olhs_, orhs_ ), j );
               column( osres_ , j ) = column( min( olhs_, orhs_ ), j );
               column( refres_, j ) = column( ref_               , j );
            }
         }
         catch( std::exception& ex ) {
            convertException<OMT1,OMT2>( ex );
         }

         checkResults<OMT1,OMT2>();
      }

      // Column-wise minimum with evaluated matrices
      {
         test_  = "Column-wise minimum with evaluated matrices";
         error_ = "Failed minimum operation";

         try {
            initResults();
            for( size_t j=0UL; j<lhs_.columns(); ++j ) {
               column( dres_  , j ) = column( min( eval( lhs_ ), eval( rhs_ ) ), j );
               column( odres_ , j ) = column( min( eval( lhs_ ), eval( rhs_ ) ), j );
               column( sres_  , j ) = column( min( eval( lhs_ ), eval( rhs_ ) ), j );
               column( osres_ , j ) = column( min( eval( lhs_ ), eval( rhs_ ) ), j );
               column( refres_, j ) = column( eval( ref_ )                     , j );
            }
         }
         catch( std::exception& ex ) {
            convertException<MT1,MT2>( ex );
         }

         checkResults<MT1,MT2>();

         try {
            initResults();
            for( size_t j=0UL; j<lhs_.columns(); ++j ) {
               column( dres_  , j ) = column( min( eval( lhs_ ), eval( orhs_ ) ), j );
               column( odres_ , j ) = column( min( eval( lhs_ ), eval( orhs_ ) ), j );
               column( sres_  , j ) = column( min( eval( lhs_ ), eval( orhs_ ) ), j );
               column( osres_ , j ) = column( min( eval( lhs_ ), eval( orhs_ ) ), j );
               column( refres_, j ) = column( eval( ref_ )                      , j );
            }
         }
         catch( std::exception& ex ) {
            convertException<MT1,OMT2>( ex );
         }

         checkResults<MT1,OMT2>();

         try {
            initResults();
            for( size_t j=0UL; j<lhs_.columns(); ++j ) {
               column( dres_  , j ) = column( min( eval( olhs_ ), eval( rhs_ ) ), j );
               column( odres_ , j ) = column( min( eval( olhs_ ), eval( rhs_ ) ), j );
               column( sres_  , j ) = column( min( eval( olhs_ ), eval( rhs_ ) ), j );
               column( osres_ , j ) = column( min( eval( olhs_ ), eval( rhs_ ) ), j );
               column( refres_, j ) = column( eval( ref_ )                      , j );
            }
         }
         catch( std::exception& ex ) {
            convertException<OMT1,MT2>( ex );
         }

         checkResults<OMT1,MT2>();

         try {
            initResults();
            for( size_t j=0UL; j<lhs_.columns(); ++j ) {
               column( dres_  , j ) = column( min( eval( olhs_ ), eval( orhs_ ) ), j );
               column( odres_ , j ) = column( min( eval( olhs_ ), eval( orhs_ ) ), j );
               column( sres_  , j ) = column( min( eval( olhs_ ), eval( orhs_ ) ), j );
               column( osres_ , j ) = column( min( eval( olhs_ ), eval( orhs_ ) ), j );
               column( refres_, j ) = column( eval( ref_ )                       , j );
            }
         }
         catch( std::exception& ex ) {
            convertException<OMT1,OMT2>( ex );
         }

         checkResults<OMT1,OMT2>();
      }


      //=====================================================================================
      // Column-wise minimum with addition assignment
      //=====================================================================================

      // Column-wise minimum with addition assignment with the given matrices
      {
         test_  = "Column-wise minimum with addition assignment with the given matrices";
         error_ = "Failed addition assignment operation";

         try {
            initResults();
            for( size_t j=0UL; j<lhs_.columns(); ++j ) {
               column( dres_  , j ) += column( min( lhs_, rhs_ ), j );
               column( odres_ , j ) += column( min( lhs_, rhs_ ), j );
               column( sres_  , j ) += column( min( lhs_, rhs_ ), j );
               column( osres_ , j ) += column( min( lhs_, rhs_ ), j );
               column( refres_, j ) += column( ref_             , j );
            }
         }
         catch( std::exception& ex ) {
            convertException<MT1,MT2>( ex );
         }

         checkResults<MT1,MT2>();

         try {
            initResults();
            for( size_t j=0UL; j<lhs_.columns(); ++j ) {
               column( dres_  , j ) += column( min( lhs_, orhs_ ), j );
               column( odres_ , j ) += column( min( lhs_, orhs_ ), j );
               column( sres_  , j ) += column( min( lhs_, orhs_ ), j );
               column( osres_ , j ) += column( min( lhs_, orhs_ ), j );
               column( refres_, j ) += column( ref_              , j );
            }
         }
         catch( std::exception& ex ) {
            convertException<MT1,OMT2>( ex );
         }

         checkResults<MT1,OMT2>();

         try {
            initResults();
            for( size_t j=0UL; j<lhs_.columns(); ++j ) {
               column( dres_  , j ) += column( min( olhs_, rhs_ ), j );
               column( odres_ , j ) += column( min( olhs_, rhs_ ), j );
               column( sres_  , j ) += column( min( olhs_, rhs_ ), j );
               column( osres_ , j ) += column( min( olhs_, rhs_ ), j );
               column( refres_, j ) += column( ref_              , j );
            }
         }
         catch( std::exception& ex ) {
            convertException<OMT1,MT2>( ex );
         }

         checkResults<OMT1,MT2>();

         try {
            initResults();
            for( size_t j=0UL; j<lhs_.columns(); ++j ) {
               column( dres_  , j ) += column( min( olhs_, orhs_ ), j );
               column( odres_ , j ) += column( min( olhs_, orhs_ ), j );
               column( sres_  , j ) += column( min( olhs_, orhs_ ), j );
               column( osres_ , j ) += column( min( olhs_, orhs_ ), j );
               column( refres_, j ) += column( ref_               , j );
            }
         }
         catch( std::exception& ex ) {
            convertException<OMT1,OMT2>( ex );
         }

         checkResults<OMT1,OMT2>();
      }

      // Column-wise minimum with addition assignment with evaluated matrices
      {
         test_  = "Column-wise minimum with addition assignment with evaluated matrices";
         error_ = "Failed addition assignment operation";

         try {
            initResults();
            for( size_t j=0UL; j<lhs_.columns(); ++j ) {
               column( dres_  , j ) += column( min( eval( lhs_ ), eval( rhs_ ) ), j );
               column( odres_ , j ) += column( min( eval( lhs_ ), eval( rhs_ ) ), j );
               column( sres_  , j ) += column( min( eval( lhs_ ), eval( rhs_ ) ), j );
               column( osres_ , j ) += column( min( eval( lhs_ ), eval( rhs_ ) ), j );
               column( refres_, j ) += column( eval( ref_ )                     , j );
            }
         }
         catch( std::exception& ex ) {
            convertException<MT1,MT2>( ex );
         }

         checkResults<MT1,MT2>();

         try {
            initResults();
            for( size_t j=0UL; j<lhs_.columns(); ++j ) {
               column( dres_  , j ) += column( min( eval( lhs_ ), eval( orhs_ ) ), j );
               column( odres_ , j ) += column( min( eval( lhs_ ), eval( orhs_ ) ), j );
               column( sres_  , j ) += column( min( eval( lhs_ ), eval( orhs_ ) ), j );
               column( osres_ , j ) += column( min( eval( lhs_ ), eval( orhs_ ) ), j );
               column( refres_, j ) += column( eval( ref_ )                      , j );
            }
         }
         catch( std::exception& ex ) {
            convertException<MT1,OMT2>( ex );
         }

         checkResults<MT1,OMT2>();

         try {
            initResults();
            for( size_t j=0UL; j<lhs_.columns(); ++j ) {
               column( dres_  , j ) += column( min( eval( olhs_ ), eval( rhs_ ) ), j );
               column( odres_ , j ) += column( min( eval( olhs_ ), eval( rhs_ ) ), j );
               column( sres_  , j ) += column( min( eval( olhs_ ), eval( rhs_ ) ), j );
               column( osres_ , j ) += column( min( eval( olhs_ ), eval( rhs_ ) ), j );
               column( refres_, j ) += column( eval( ref_ )                      , j );
            }
         }
         catch( std::exception& ex ) {
            convertException<OMT1,MT2>( ex );
         }

         checkResults<OMT1,MT2>();

         try {
            initResults();
            for( size_t j=0UL; j<lhs_.columns(); ++j ) {
               column( dres_  , j ) += column( min( eval( olhs_ ), eval( orhs_ ) ), j );
               column( odres_ , j ) += column( min( eval( olhs_ ), eval( orhs_ ) ), j );
               column( sres_  , j ) += column( min( eval( olhs_ ), eval( orhs_ ) ), j );
               column( osres_ , j ) += column( min( eval( olhs_ ), eval( orhs_ ) ), j );
               column( refres_, j ) += column( eval( ref_ )                       , j );
            }
         }
         catch( std::exception& ex ) {
            convertException<OMT1,OMT2>( ex );
         }

         checkResults<OMT1,OMT2>();
      }


      //=====================================================================================
      // Column-wise minimum with subtraction assignment
      //=====================================================================================

      // Column-wise minimum with subtraction assignment with the given matrices
      {
         test_  = "Column-wise minimum with subtraction assignment with the given matrices";
         error_ = "Failed subtraction assignment operation";

         try {
            initResults();
            for( size_t j=0UL; j<lhs_.columns(); ++j ) {
               column( dres_  , j ) -= column( min( lhs_, rhs_ ), j );
               column( odres_ , j ) -= column( min( lhs_, rhs_ ), j );
               column( sres_  , j ) -= column( min( lhs_, rhs_ ), j );
               column( osres_ , j ) -= column( min( lhs_, rhs_ ), j );
               column( refres_, j ) -= column( ref_             , j );
            }
         }
         catch( std::exception& ex ) {
            convertException<MT1,MT2>( ex );
         }

         checkResults<MT1,MT2>();

         try {
            initResults();
            for( size_t j=0UL; j<lhs_.columns(); ++j ) {
               column( dres_  , j ) -= column( min( lhs_, orhs_ ), j );
               column( odres_ , j ) -= column( min( lhs_, orhs_ ), j );
               column( sres_  , j ) -= column( min( lhs_, orhs_ ), j );
               column( osres_ , j ) -= column( min( lhs_, orhs_ ), j );
               column( refres_, j ) -= column( ref_              , j );
            }
         }
         catch( std::exception& ex ) {
            convertException<MT1,OMT2>( ex );
         }

         checkResults<MT1,OMT2>();

         try {
            initResults();
            for( size_t j=0UL; j<lhs_.columns(); ++j ) {
               column( dres_  , j ) -= column( min( olhs_, rhs_ ), j );
               column( odres_ , j ) -= column( min( olhs_, rhs_ ), j );
               column( sres_  , j ) -= column( min( olhs_, rhs_ ), j );
               column( osres_ , j ) -= column( min( olhs_, rhs_ ), j );
               column( refres_, j ) -= column( ref_              , j );
            }
         }
         catch( std::exception& ex ) {
            convertException<OMT1,MT2>( ex );
         }

         checkResults<OMT1,MT2>();

         try {
            initResults();
            for( size_t j=0UL; j<lhs_.columns(); ++j ) {
               column( dres_  , j ) -= column( min( olhs_, orhs_ ), j );
               column( odres_ , j ) -= column( min( olhs_, orhs_ ), j );
               column( sres_  , j ) -= column( min( olhs_, orhs_ ), j );
               column( osres_ , j ) -= column( min( olhs_, orhs_ ), j );
               column( refres_, j ) -= column( ref_               , j );
            }
         }
         catch( std::exception& ex ) {
            convertException<OMT1,OMT2>( ex );
         }

         checkResults<OMT1,OMT2>();
      }

      // Column-wise minimum with subtraction assignment with evaluated matrices
      {
         test_  = "Column-wise minimum with subtraction assignment with evaluated matrices";
         error_ = "Failed subtraction assignment operation";

         try {
            initResults();
            for( size_t j=0UL; j<lhs_.columns(); ++j ) {
               column( dres_  , j ) -= column( min( eval( lhs_ ), eval( rhs_ ) ), j );
               column( odres_ , j ) -= column( min( eval( lhs_ ), eval( rhs_ ) ), j );
               column( sres_  , j ) -= column( min( eval( lhs_ ), eval( rhs_ ) ), j );
               column( osres_ , j ) -= column( min( eval( lhs_ ), eval( rhs_ ) ), j );
               column( refres_, j ) -= column( eval( ref_ )                     , j );
            }
         }
         catch( std::exception& ex ) {
            convertException<MT1,MT2>( ex );
         }

         checkResults<MT1,MT2>();

         try {
            initResults();
            for( size_t j=0UL; j<lhs_.columns(); ++j ) {
               column( dres_  , j ) -= column( min( eval( lhs_ ), eval( orhs_ ) ), j );
               column( odres_ , j ) -= column( min( eval( lhs_ ), eval( orhs_ ) ), j );
               column( sres_  , j ) -= column( min( eval( lhs_ ), eval( orhs_ ) ), j );
               column( osres_ , j ) -= column( min( eval( lhs_ ), eval( orhs_ ) ), j );
               column( refres_, j ) -= column( eval( ref_ )                      , j );
            }
         }
         catch( std::exception& ex ) {
            convertException<MT1,OMT2>( ex );
         }

         checkResults<MT1,OMT2>();

         try {
            initResults();
            for( size_t j=0UL; j<lhs_.columns(); ++j ) {
               column( dres_  , j ) -= column( min( eval( olhs_ ), eval( rhs_ ) ), j );
               column( odres_ , j ) -= column( min( eval( olhs_ ), eval( rhs_ ) ), j );
               column( sres_  , j ) -= column( min( eval( olhs_ ), eval( rhs_ ) ), j );
               column( osres_ , j ) -= column( min( eval( olhs_ ), eval( rhs_ ) ), j );
               column( refres_, j ) -= column( eval( ref_ )                      , j );
            }
         }
         catch( std::exception& ex ) {
            convertException<OMT1,MT2>( ex );
         }

         checkResults<OMT1,MT2>();

         try {
            initResults();
            for( size_t j=0UL; j<lhs_.columns(); ++j ) {
               column( dres_  , j ) -= column( min( eval( olhs_ ), eval( orhs_ ) ), j );
               column( odres_ , j ) -= column( min( eval( olhs_ ), eval( orhs_ ) ), j );
               column( sres_  , j ) -= column( min( eval( olhs_ ), eval( orhs_ ) ), j );
               column( osres_ , j ) -= column( min( eval( olhs_ ), eval( orhs_ ) ), j );
               column( refres_, j ) -= column( eval( ref_ )                       , j );
            }
         }
         catch( std::exception& ex ) {
            convertException<OMT1,OMT2>( ex );
         }

         checkResults<OMT1,OMT2>();
      }


      //=====================================================================================
      // Column-wise minimum with multiplication assignment
      //=====================================================================================

      // Column-wise minimum with multiplication assignment with the given matrices
      {
         test_  = "Column-wise minimum with multiplication assignment with the given matrices";
         error_ = "Failed multiplication assignment operation";

         try {
            initResults();
            for( size_t j=0UL; j<lhs_.columns(); ++j ) {
               column( dres_  , j ) *= column( min( lhs_, rhs_ ), j );
               column( odres_ , j ) *= column( min( lhs_, rhs_ ), j );
               column( sres_  , j ) *= column( min( lhs_, rhs_ ), j );
               column( osres_ , j ) *= column( min( lhs_, rhs_ ), j );
               column( refres_, j ) *= column( ref_             , j );
            }
         }
         catch( std::exception& ex ) {
            convertException<MT1,MT2>( ex );
         }

         checkResults<MT1,MT2>();

         try {
            initResults();
            for( size_t j=0UL; j<lhs_.columns(); ++j ) {
               column( dres_  , j ) *= column( min( lhs_, orhs_ ), j );
               column( odres_ , j ) *= column( min( lhs_, orhs_ ), j );
               column( sres_  , j ) *= column( min( lhs_, orhs_ ), j );
               column( osres_ , j ) *= column( min( lhs_, orhs_ ), j );
               column( refres_, j ) *= column( ref_              , j );
            }
         }
         catch( std::exception& ex ) {
            convertException<MT1,OMT2>( ex );
         }

         checkResults<MT1,OMT2>();

         try {
            initResults();
            for( size_t j=0UL; j<lhs_.columns(); ++j ) {
               column( dres_  , j ) *= column( min( olhs_, rhs_ ), j );
               column( odres_ , j ) *= column( min( olhs_, rhs_ ), j );
               column( sres_  , j ) *= column( min( olhs_, rhs_ ), j );
               column( osres_ , j ) *= column( min( olhs_, rhs_ ), j );
               column( refres_, j ) *= column( ref_              , j );
            }
         }
         catch( std::exception& ex ) {
            convertException<OMT1,MT2>( ex );
         }

         checkResults<OMT1,MT2>();

         try {
            initResults();
            for( size_t j=0UL; j<lhs_.columns(); ++j ) {
               column( dres_  , j ) *= column( min( olhs_, orhs_ ), j );
               column( odres_ , j ) *= column( min( olhs_, orhs_ ), j );
               column( sres_  , j ) *= column( min( olhs_, orhs_ ), j );
               column( osres_ , j ) *= column( min( olhs_, orhs_ ), j );
               column( refres_, j ) *= column( ref_               , j );
            }
         }
         catch( std::exception& ex ) {
            convertException<OMT1,OMT2>( ex );
         }

         checkResults<OMT1,OMT2>();
      }

      // Column-wise minimum with multiplication assignment with evaluated matrices
      {
         test_  = "Column-wise minimum with multiplication assignment with evaluated matrices";
         error_ = "Failed multiplication assignment operation";

         try {
            initResults();
            for( size_t j=0UL; j<lhs_.columns(); ++j ) {
               column( dres_  , j ) *= column( min( eval( lhs_ ), eval( rhs_ ) ), j );
               column( odres_ , j ) *= column( min( eval( lhs_ ), eval( rhs_ ) ), j );
               column( sres_  , j ) *= column( min( eval( lhs_ ), eval( rhs_ ) ), j );
               column( osres_ , j ) *= column( min( eval( lhs_ ), eval( rhs_ ) ), j );
               column( refres_, j ) *= column( eval( ref_ )                     , j );
            }
         }
         catch( std::exception& ex ) {
            convertException<MT1,MT2>( ex );
         }

         checkResults<MT1,MT2>();

         try {
            initResults();
            for( size_t j=0UL; j<lhs_.columns(); ++j ) {
               column( dres_  , j ) *= column( min( eval( lhs_ ), eval( orhs_ ) ), j );
               column( odres_ , j ) *= column( min( eval( lhs_ ), eval( orhs_ ) ), j );
               column( sres_  , j ) *= column( min( eval( lhs_ ), eval( orhs_ ) ), j );
               column( osres_ , j ) *= column( min( eval( lhs_ ), eval( orhs_ ) ), j );
               column( refres_, j ) *= column( eval( ref_ )                      , j );
            }
         }
         catch( std::exception& ex ) {
            convertException<MT1,OMT2>( ex );
         }

         checkResults<MT1,OMT2>();

         try {
            initResults();
            for( size_t j=0UL; j<lhs_.columns(); ++j ) {
               column( dres_  , j ) *= column( min( eval( olhs_ ), eval( rhs_ ) ), j );
               column( odres_ , j ) *= column( min( eval( olhs_ ), eval( rhs_ ) ), j );
               column( sres_  , j ) *= column( min( eval( olhs_ ), eval( rhs_ ) ), j );
               column( osres_ , j ) *= column( min( eval( olhs_ ), eval( rhs_ ) ), j );
               column( refres_, j ) *= column( eval( ref_ )                      , j );
            }
         }
         catch( std::exception& ex ) {
            convertException<OMT1,MT2>( ex );
         }

         checkResults<OMT1,MT2>();

         try {
            initResults();
            for( size_t j=0UL; j<lhs_.columns(); ++j ) {
               column( dres_  , j ) *= column( min( eval( olhs_ ), eval( orhs_ ) ), j );
               column( odres_ , j ) *= column( min( eval( olhs_ ), eval( orhs_ ) ), j );
               column( sres_  , j ) *= column( min( eval( olhs_ ), eval( orhs_ ) ), j );
               column( osres_ , j ) *= column( min( eval( olhs_ ), eval( orhs_ ) ), j );
               column( refres_, j ) *= column( eval( ref_ )                       , j );
            }
         }
         catch( std::exception& ex ) {
            convertException<OMT1,OMT2>( ex );
         }

         checkResults<OMT1,OMT2>();
      }
   }
#endif
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Testing the customized dense matrix/dense matrix minimum operation.
//
// \param op The custom operation to be tested.
// \param name The human-readable name of the operation.
// \return void
// \exception std::runtime_error Minimum error detected.
//
// This function tests the matrix minimum with plain assignment, addition assignment, and
// subtraction assignment in combination with a custom operation. In case any error resulting
// from the minimum operation or the subsequent assignment is detected, a \a std::runtime_error
// exception is thrown.
*/
template< typename MT1    // Type of the left-hand side dense matrix
        , typename MT2 >  // Type of the right-hand side dense matrix
template< typename OP >   // Type of the custom operation
void OperationTest<MT1,MT2>::testCustomOperation( OP op, const std::string& name )
{
   //=====================================================================================
   // Customized minimum
   //=====================================================================================

   // Customized minimum with the given matrices
   {
      test_  = "Customized minimum with the given matrices (" + name + ")";
      error_ = "Failed minimum operation";

      try {
         initResults();
         dres_   = op( min( lhs_, rhs_ ) );
         odres_  = op( min( lhs_, rhs_ ) );
         sres_   = op( min( lhs_, rhs_ ) );
         osres_  = op( min( lhs_, rhs_ ) );
         refres_ = op( ref_ );
      }
      catch( std::exception& ex ) {
         convertException<MT1,MT2>( ex );
      }

      checkResults<MT1,MT2>();

      try {
         initResults();
         dres_   = op( min( lhs_, orhs_ ) );
         odres_  = op( min( lhs_, orhs_ ) );
         sres_   = op( min( lhs_, orhs_ ) );
         osres_  = op( min( lhs_, orhs_ ) );
         refres_ = op( ref_ );
      }
      catch( std::exception& ex ) {
         convertException<MT1,OMT2>( ex );
      }

      checkResults<MT1,OMT2>();

      try {
         initResults();
         dres_   = op( min( olhs_, rhs_ ) );
         odres_  = op( min( olhs_, rhs_ ) );
         sres_   = op( min( olhs_, rhs_ ) );
         osres_  = op( min( olhs_, rhs_ ) );
         refres_ = op( ref_ );
      }
      catch( std::exception& ex ) {
         convertException<OMT1,MT2>( ex );
      }

      checkResults<OMT1,MT2>();

      try {
         initResults();
         dres_   = op( min( olhs_, orhs_ ) );
         odres_  = op( min( olhs_, orhs_ ) );
         sres_   = op( min( olhs_, orhs_ ) );
         osres_  = op( min( olhs_, orhs_ ) );
         refres_ = op( ref_ );
      }
      catch( std::exception& ex ) {
         convertException<OMT1,OMT2>( ex );
      }

      checkResults<OMT1,OMT2>();
   }

   // Customized minimum with evaluated matrices
   {
      test_  = "Customized minimum with evaluated matrices (" + name + ")";
      error_ = "Failed minimum operation";

      try {
         initResults();
         dres_   = op( min( eval( lhs_ ), eval( rhs_ ) ) );
         odres_  = op( min( eval( lhs_ ), eval( rhs_ ) ) );
         sres_   = op( min( eval( lhs_ ), eval( rhs_ ) ) );
         osres_  = op( min( eval( lhs_ ), eval( rhs_ ) ) );
         refres_ = op( eval( ref_ ) );
      }
      catch( std::exception& ex ) {
         convertException<MT1,MT2>( ex );
      }

      checkResults<MT1,MT2>();

      try {
         initResults();
         dres_   = op( min( eval( lhs_ ), eval( orhs_ ) ) );
         odres_  = op( min( eval( lhs_ ), eval( orhs_ ) ) );
         sres_   = op( min( eval( lhs_ ), eval( orhs_ ) ) );
         osres_  = op( min( eval( lhs_ ), eval( orhs_ ) ) );
         refres_ = op( eval( ref_ ) );
      }
      catch( std::exception& ex ) {
         convertException<MT1,OMT2>( ex );
      }

      checkResults<MT1,OMT2>();

      try {
         initResults();
         dres_   = op( min( eval( olhs_ ), eval( rhs_ ) ) );
         odres_  = op( min( eval( olhs_ ), eval( rhs_ ) ) );
         sres_   = op( min( eval( olhs_ ), eval( rhs_ ) ) );
         osres_  = op( min( eval( olhs_ ), eval( rhs_ ) ) );
         refres_ = op( eval( ref_ ) );
      }
      catch( std::exception& ex ) {
         convertException<OMT1,MT2>( ex );
      }

      checkResults<OMT1,MT2>();

      try {
         initResults();
         dres_   = op( min( eval( olhs_ ), eval( orhs_ ) ) );
         odres_  = op( min( eval( olhs_ ), eval( orhs_ ) ) );
         sres_   = op( min( eval( olhs_ ), eval( orhs_ ) ) );
         osres_  = op( min( eval( olhs_ ), eval( orhs_ ) ) );
         refres_ = op( eval( ref_ ) );
      }
      catch( std::exception& ex ) {
         convertException<OMT1,OMT2>( ex );
      }

      checkResults<OMT1,OMT2>();
   }


   //=====================================================================================
   // Customized minimum with addition assignment
   //=====================================================================================

   // Customized minimum with addition assignment with the given matrices
   {
      test_  = "Customized minimum with addition assignment with the given matrices (" + name + ")";
      error_ = "Failed addition assignment operation";

      try {
         initResults();
         dres_   += op( min( lhs_, rhs_ ) );
         odres_  += op( min( lhs_, rhs_ ) );
         sres_   += op( min( lhs_, rhs_ ) );
         osres_  += op( min( lhs_, rhs_ ) );
         refres_ += op( ref_ );
      }
      catch( std::exception& ex ) {
         convertException<MT1,MT2>( ex );
      }

      checkResults<MT1,MT2>();

      try {
         initResults();
         dres_   += op( min( lhs_, orhs_ ) );
         odres_  += op( min( lhs_, orhs_ ) );
         sres_   += op( min( lhs_, orhs_ ) );
         osres_  += op( min( lhs_, orhs_ ) );
         refres_ += op( ref_ );
      }
      catch( std::exception& ex ) {
         convertException<MT1,OMT2>( ex );
      }

      checkResults<MT1,OMT2>();

      try {
         initResults();
         dres_   += op( min( olhs_, rhs_ ) );
         odres_  += op( min( olhs_, rhs_ ) );
         sres_   += op( min( olhs_, rhs_ ) );
         osres_  += op( min( olhs_, rhs_ ) );
         refres_ += op( ref_ );
      }
      catch( std::exception& ex ) {
         convertException<OMT1,MT2>( ex );
      }

      checkResults<OMT1,MT2>();

      try {
         initResults();
         dres_   += op( min( olhs_, orhs_ ) );
         odres_  += op( min( olhs_, orhs_ ) );
         sres_   += op( min( olhs_, orhs_ ) );
         osres_  += op( min( olhs_, orhs_ ) );
         refres_ += op( ref_ );
      }
      catch( std::exception& ex ) {
         convertException<OMT1,OMT2>( ex );
      }

      checkResults<OMT1,OMT2>();
   }

   // Customized minimum with addition assignment with evaluated matrices
   {
      test_  = "Customized minimum with addition assignment with evaluated matrices (" + name + ")";
      error_ = "Failed addition assignment operation";

      try {
         initResults();
         dres_   += op( min( eval( lhs_ ), eval( rhs_ ) ) );
         odres_  += op( min( eval( lhs_ ), eval( rhs_ ) ) );
         sres_   += op( min( eval( lhs_ ), eval( rhs_ ) ) );
         osres_  += op( min( eval( lhs_ ), eval( rhs_ ) ) );
         refres_ += op( eval( ref_ ) );
      }
      catch( std::exception& ex ) {
         convertException<MT1,MT2>( ex );
      }

      checkResults<MT1,MT2>();

      try {
         initResults();
         dres_   += op( min( eval( lhs_ ), eval( orhs_ ) ) );
         odres_  += op( min( eval( lhs_ ), eval( orhs_ ) ) );
         sres_   += op( min( eval( lhs_ ), eval( orhs_ ) ) );
         osres_  += op( min( eval( lhs_ ), eval( orhs_ ) ) );
         refres_ += op( eval( ref_ ) );
      }
      catch( std::exception& ex ) {
         convertException<MT1,OMT2>( ex );
      }

      checkResults<MT1,OMT2>();

      try {
         initResults();
         dres_   += op( min( eval( olhs_ ), eval( rhs_ ) ) );
         odres_  += op( min( eval( olhs_ ), eval( rhs_ ) ) );
         sres_   += op( min( eval( olhs_ ), eval( rhs_ ) ) );
         osres_  += op( min( eval( olhs_ ), eval( rhs_ ) ) );
         refres_ += op( eval( ref_ ) );
      }
      catch( std::exception& ex ) {
         convertException<OMT1,MT2>( ex );
      }

      checkResults<OMT1,MT2>();

      try {
         initResults();
         dres_   += op( min( eval( olhs_ ), eval( orhs_ ) ) );
         odres_  += op( min( eval( olhs_ ), eval( orhs_ ) ) );
         sres_   += op( min( eval( olhs_ ), eval( orhs_ ) ) );
         osres_  += op( min( eval( olhs_ ), eval( orhs_ ) ) );
         refres_ += op( eval( ref_ ) );
      }
      catch( std::exception& ex ) {
         convertException<OMT1,OMT2>( ex );
      }

      checkResults<OMT1,OMT2>();
   }


   //=====================================================================================
   // Customized minimum with subtraction assignment
   //=====================================================================================

   // Customized minimum with subtraction assignment with the given matrices
   {
      test_  = "Customized minimum with subtraction assignment with the given matrices (" + name + ")";
      error_ = "Failed subtraction assignment operation";

      try {
         initResults();
         dres_   -= op( min( lhs_, rhs_ ) );
         odres_  -= op( min( lhs_, rhs_ ) );
         sres_   -= op( min( lhs_, rhs_ ) );
         osres_  -= op( min( lhs_, rhs_ ) );
         refres_ -= op( ref_ );
      }
      catch( std::exception& ex ) {
         convertException<MT1,MT2>( ex );
      }

      checkResults<MT1,MT2>();

      try {
         initResults();
         dres_   -= op( min( lhs_, orhs_ ) );
         odres_  -= op( min( lhs_, orhs_ ) );
         sres_   -= op( min( lhs_, orhs_ ) );
         osres_  -= op( min( lhs_, orhs_ ) );
         refres_ -= op( ref_ );
      }
      catch( std::exception& ex ) {
         convertException<MT1,OMT2>( ex );
      }

      checkResults<MT1,OMT2>();

      try {
         initResults();
         dres_   -= op( min( olhs_, rhs_ ) );
         odres_  -= op( min( olhs_, rhs_ ) );
         sres_   -= op( min( olhs_, rhs_ ) );
         osres_  -= op( min( olhs_, rhs_ ) );
         refres_ -= op( ref_ );
      }
      catch( std::exception& ex ) {
         convertException<OMT1,MT2>( ex );
      }

      checkResults<OMT1,MT2>();

      try {
         initResults();
         dres_   -= op( min( olhs_, orhs_ ) );
         odres_  -= op( min( olhs_, orhs_ ) );
         sres_   -= op( min( olhs_, orhs_ ) );
         osres_  -= op( min( olhs_, orhs_ ) );
         refres_ -= op( ref_ );
      }
      catch( std::exception& ex ) {
         convertException<OMT1,OMT2>( ex );
      }

      checkResults<OMT1,OMT2>();
   }

   // Customized minimum with subtraction assignment with evaluated matrices
   {
      test_  = "Customized minimum with subtraction assignment with evaluated matrices (" + name + ")";
      error_ = "Failed subtraction assignment operation";

      try {
         initResults();
         dres_   -= op( min( eval( lhs_ ), eval( rhs_ ) ) );
         odres_  -= op( min( eval( lhs_ ), eval( rhs_ ) ) );
         sres_   -= op( min( eval( lhs_ ), eval( rhs_ ) ) );
         osres_  -= op( min( eval( lhs_ ), eval( rhs_ ) ) );
         refres_ -= op( eval( ref_ ) );
      }
      catch( std::exception& ex ) {
         convertException<MT1,MT2>( ex );
      }

      checkResults<MT1,MT2>();

      try {
         initResults();
         dres_   -= op( min( eval( lhs_ ), eval( orhs_ ) ) );
         odres_  -= op( min( eval( lhs_ ), eval( orhs_ ) ) );
         sres_   -= op( min( eval( lhs_ ), eval( orhs_ ) ) );
         osres_  -= op( min( eval( lhs_ ), eval( orhs_ ) ) );
         refres_ -= op( eval( ref_ ) );
      }
      catch( std::exception& ex ) {
         convertException<MT1,OMT2>( ex );
      }

      checkResults<MT1,OMT2>();

      try {
         initResults();
         dres_   -= op( min( eval( olhs_ ), eval( rhs_ ) ) );
         odres_  -= op( min( eval( olhs_ ), eval( rhs_ ) ) );
         sres_   -= op( min( eval( olhs_ ), eval( rhs_ ) ) );
         osres_  -= op( min( eval( olhs_ ), eval( rhs_ ) ) );
         refres_ -= op( eval( ref_ ) );
      }
      catch( std::exception& ex ) {
         convertException<OMT1,MT2>( ex );
      }

      checkResults<OMT1,MT2>();

      try {
         initResults();
         dres_   -= op( min( eval( olhs_ ), eval( orhs_ ) ) );
         odres_  -= op( min( eval( olhs_ ), eval( orhs_ ) ) );
         sres_   -= op( min( eval( olhs_ ), eval( orhs_ ) ) );
         osres_  -= op( min( eval( olhs_ ), eval( orhs_ ) ) );
         refres_ -= op( eval( ref_ ) );
      }
      catch( std::exception& ex ) {
         convertException<OMT1,OMT2>( ex );
      }

      checkResults<OMT1,OMT2>();
   }


   //=====================================================================================
   // Customized minimum with Schur product assignment
   //=====================================================================================

   // Customized minimum with Schur product assignment with the given matrices
   {
      test_  = "Customized minimum with Schur product assignment with the given matrices (" + name + ")";
      error_ = "Failed Schur product assignment operation";

      try {
         initResults();
         dres_   %= op( min( lhs_, rhs_ ) );
         odres_  %= op( min( lhs_, rhs_ ) );
         sres_   %= op( min( lhs_, rhs_ ) );
         osres_  %= op( min( lhs_, rhs_ ) );
         refres_ %= op( ref_ );
      }
      catch( std::exception& ex ) {
         convertException<MT1,MT2>( ex );
      }

      checkResults<MT1,MT2>();

      try {
         initResults();
         dres_   %= op( min( lhs_, orhs_ ) );
         odres_  %= op( min( lhs_, orhs_ ) );
         sres_   %= op( min( lhs_, orhs_ ) );
         osres_  %= op( min( lhs_, orhs_ ) );
         refres_ %= op( ref_ );
      }
      catch( std::exception& ex ) {
         convertException<MT1,OMT2>( ex );
      }

      checkResults<MT1,OMT2>();

      try {
         initResults();
         dres_   %= op( min( olhs_, rhs_ ) );
         odres_  %= op( min( olhs_, rhs_ ) );
         sres_   %= op( min( olhs_, rhs_ ) );
         osres_  %= op( min( olhs_, rhs_ ) );
         refres_ %= op( ref_ );
      }
      catch( std::exception& ex ) {
         convertException<OMT1,MT2>( ex );
      }

      checkResults<OMT1,MT2>();

      try {
         initResults();
         dres_   %= op( min( olhs_, orhs_ ) );
         odres_  %= op( min( olhs_, orhs_ ) );
         sres_   %= op( min( olhs_, orhs_ ) );
         osres_  %= op( min( olhs_, orhs_ ) );
         refres_ %= op( ref_ );
      }
      catch( std::exception& ex ) {
         convertException<OMT1,OMT2>( ex );
      }

      checkResults<OMT1,OMT2>();
   }

   // Customized minimum with Schur product assignment with evaluated matrices
   {
      test_  = "Customized minimum with Schur product assignment with evaluated matrices (" + name + ")";
      error_ = "Failed Schur product assignment operation";

      try {
         initResults();
         dres_   %= op( min( eval( lhs_ ), eval( rhs_ ) ) );
         odres_  %= op( min( eval( lhs_ ), eval( rhs_ ) ) );
         sres_   %= op( min( eval( lhs_ ), eval( rhs_ ) ) );
         osres_  %= op( min( eval( lhs_ ), eval( rhs_ ) ) );
         refres_ %= op( eval( ref_ ) );
      }
      catch( std::exception& ex ) {
         convertException<MT1,MT2>( ex );
      }

      checkResults<MT1,MT2>();

      try {
         initResults();
         dres_   %= op( min( eval( lhs_ ), eval( orhs_ ) ) );
         odres_  %= op( min( eval( lhs_ ), eval( orhs_ ) ) );
         sres_   %= op( min( eval( lhs_ ), eval( orhs_ ) ) );
         osres_  %= op( min( eval( lhs_ ), eval( orhs_ ) ) );
         refres_ %= op( eval( ref_ ) );
      }
      catch( std::exception& ex ) {
         convertException<MT1,OMT2>( ex );
      }

      checkResults<MT1,OMT2>();

      try {
         initResults();
         dres_   %= op( min( eval( olhs_ ), eval( rhs_ ) ) );
         odres_  %= op( min( eval( olhs_ ), eval( rhs_ ) ) );
         sres_   %= op( min( eval( olhs_ ), eval( rhs_ ) ) );
         osres_  %= op( min( eval( olhs_ ), eval( rhs_ ) ) );
         refres_ %= op( eval( ref_ ) );
      }
      catch( std::exception& ex ) {
         convertException<OMT1,MT2>( ex );
      }

      checkResults<OMT1,MT2>();

      try {
         initResults();
         dres_   %= op( min( eval( olhs_ ), eval( orhs_ ) ) );
         odres_  %= op( min( eval( olhs_ ), eval( orhs_ ) ) );
         sres_   %= op( min( eval( olhs_ ), eval( orhs_ ) ) );
         osres_  %= op( min( eval( olhs_ ), eval( orhs_ ) ) );
         refres_ %= op( eval( ref_ ) );
      }
      catch( std::exception& ex ) {
         convertException<OMT1,OMT2>( ex );
      }

      checkResults<OMT1,OMT2>();
   }
}
//*************************************************************************************************




//=================================================================================================
//
//  ERROR DETECTION FUNCTIONS
//
//=================================================================================================

//*************************************************************************************************
/*!\brief Checking and comparing the computed results.
//
// \return void
// \exception std::runtime_error Incorrect dense result detected.
// \exception std::runtime_error Incorrect sparse result detected.
//
// This function is called after each test case to check and compare the computed results. The
// two template arguments \a LT and \a RT indicate the types of the left-hand side and right-hand
// side operands used for the computations.
*/
template< typename MT1    // Type of the left-hand side dense matrix
        , typename MT2 >  // Type of the right-hand side dense matrix
template< typename LT     // Type of the left-hand side operand
        , typename RT >   // Type of the right-hand side operand
void OperationTest<MT1,MT2>::checkResults()
{
   using blaze::IsRowMajorMatrix;

   if( !isEqual( dres_, refres_ ) || !isEqual( odres_, refres_ ) ) {
      std::ostringstream oss;
      oss.precision( 20 );
      oss << " Test : " << test_ << "\n"
          << " Error: Incorrect dense result detected\n"
          << " Details:\n"
          << "   Random seed = " << blaze::getSeed() << "\n"
          << "   Left-hand side " << ( IsRowMajorMatrix<LT>::value ? ( "row-major" ) : ( "column-major" ) ) << " dense matrix type:\n"
          << "     " << typeid( LT ).name() << "\n"
          << "   Right-hand side " << ( IsRowMajorMatrix<RT>::value ? ( "row-major" ) : ( "column-major" ) ) << " dense matrix type:\n"
          << "     " << typeid( RT ).name() << "\n"
          << "   Result:\n" << dres_ << "\n"
          << "   Result with opposite storage order:\n" << odres_ << "\n"
          << "   Expected result:\n" << refres_ << "\n";
      throw std::runtime_error( oss.str() );
   }

   if( !isEqual( sres_, refres_ ) || !isEqual( osres_, refres_ ) ) {
      std::ostringstream oss;
      oss.precision( 20 );
      oss << " Test : " << test_ << "\n"
          << " Error: Incorrect sparse result detected\n"
          << " Details:\n"
          << "   Random seed = " << blaze::getSeed() << "\n"
          << "   Left-hand side " << ( IsRowMajorMatrix<LT>::value ? ( "row-major" ) : ( "column-major" ) ) << " dense matrix type:\n"
          << "     " << typeid( LT ).name() << "\n"
          << "   Right-hand side " << ( IsRowMajorMatrix<RT>::value ? ( "row-major" ) : ( "column-major" ) ) << " dense matrix type:\n"
          << "     " << typeid( RT ).name() << "\n"
          << "   Result:\n" << sres_ << "\n"
          << "   Result with opposite storage order:\n" << osres_ << "\n"
          << "   Expected result:\n" << refres_ << "\n";
      throw std::runtime_error( oss.str() );
   }
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Checking and comparing the computed transpose results.
//
// \return void
// \exception std::runtime_error Incorrect dense result detected.
// \exception std::runtime_error Incorrect sparse result detected.
//
// This function is called after each test case to check and compare the computed transpose
// results. The two template arguments \a LT and \a RT indicate the types of the left-hand
// side and right-hand side operands used for the computations.
*/
template< typename MT1    // Type of the left-hand side dense matrix
        , typename MT2 >  // Type of the right-hand side dense matrix
template< typename LT     // Type of the left-hand side operand
        , typename RT >   // Type of the right-hand side operand
void OperationTest<MT1,MT2>::checkTransposeResults()
{
   using blaze::IsRowMajorMatrix;

   if( !isEqual( tdres_, refres_ ) || !isEqual( todres_, refres_ ) ) {
      std::ostringstream oss;
      oss.precision( 20 );
      oss << " Test : " << test_ << "\n"
          << " Error: Incorrect dense result detected\n"
          << " Details:\n"
          << "   Random seed = " << blaze::getSeed() << "\n"
          << "   Left-hand side " << ( IsRowMajorMatrix<LT>::value ? ( "row-major" ) : ( "column-major" ) ) << " dense matrix type:\n"
          << "     " << typeid( LT ).name() << "\n"
          << "   Right-hand side " << ( IsRowMajorMatrix<RT>::value ? ( "row-major" ) : ( "column-major" ) ) << " dense matrix type:\n"
          << "     " << typeid( RT ).name() << "\n"
          << "   Transpose result:\n" << tdres_ << "\n"
          << "   Transpose result with opposite storage order:\n" << todres_ << "\n"
          << "   Expected result:\n" << refres_ << "\n";
      throw std::runtime_error( oss.str() );
   }

   if( !isEqual( tsres_, refres_ ) || !isEqual( tosres_, refres_ ) ) {
      std::ostringstream oss;
      oss.precision( 20 );
      oss << " Test : " << test_ << "\n"
          << " Error: Incorrect sparse result detected\n"
          << " Details:\n"
          << "   Random seed = " << blaze::getSeed() << "\n"
          << "   Left-hand side " << ( IsRowMajorMatrix<LT>::value ? ( "row-major" ) : ( "column-major" ) ) << " dense matrix type:\n"
          << "     " << typeid( LT ).name() << "\n"
          << "   Right-hand side " << ( IsRowMajorMatrix<RT>::value ? ( "row-major" ) : ( "column-major" ) ) << " dense matrix type:\n"
          << "     " << typeid( RT ).name() << "\n"
          << "   Transpose result:\n" << tsres_ << "\n"
          << "   Transpose result with opposite storage order:\n" << tosres_ << "\n"
          << "   Expected result:\n" << refres_ << "\n";
      throw std::runtime_error( oss.str() );
   }
}
//*************************************************************************************************




//=================================================================================================
//
//  UTILITY FUNCTIONS
//
//=================================================================================================

//*************************************************************************************************
/*!\brief Initializing the non-transpose result matrices.
//
// \return void
//
// This function is called before each non-transpose test case to initialize the according result
// matrices to random values.
*/
template< typename MT1    // Type of the left-hand side dense matrix
        , typename MT2 >  // Type of the right-hand side dense matrix
void OperationTest<MT1,MT2>::initResults()
{
   const blaze::UnderlyingBuiltin_<DRE> min( randmin );
   const blaze::UnderlyingBuiltin_<DRE> max( randmax );

   resize( dres_, rows( lhs_ ), columns( lhs_ ) );
   randomize( dres_, min, max );

   odres_  = dres_;
   sres_   = dres_;
   osres_  = dres_;
   refres_ = dres_;
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Initializing the transpose result matrices.
//
// \return void
//
// This function is called before each transpose test case to initialize the according result
// matrices to random values.
*/
template< typename MT1    // Type of the left-hand side dense matrix
        , typename MT2 >  // Type of the right-hand side dense matrix
void OperationTest<MT1,MT2>::initTransposeResults()
{
   const blaze::UnderlyingBuiltin_<TDRE> min( randmin );
   const blaze::UnderlyingBuiltin_<TDRE> max( randmax );

   resize( tdres_, columns( lhs_ ), rows( lhs_ ) );
   randomize( tdres_, min, max );

   todres_ = tdres_;
   tsres_  = tdres_;
   tosres_ = tdres_;
   refres_ = tdres_;
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Convert the given exception into a \a std::runtime_error exception.
//
// \param ex The \a std::exception to be extended.
// \return void
// \exception std::runtime_error The converted exception.
//
// This function converts the given exception to a \a std::runtime_error exception. Additionally,
// the function extends the given exception message by all available information for the failed
// test. The two template arguments \a LT and \a RT indicate the types of the left-hand side and
// right-hand side operands used for the computations.
*/
template< typename MT1    // Type of the left-hand side dense matrix
        , typename MT2 >  // Type of the right-hand side dense matrix
template< typename LT     // Type of the left-hand side operand
        , typename RT >   // Type of the right-hand side operand
void OperationTest<MT1,MT2>::convertException( const std::exception& ex )
{
   using blaze::IsRowMajorMatrix;

   std::ostringstream oss;
   oss << " Test : " << test_ << "\n"
       << " Error: " << error_ << "\n"
       << " Details:\n"
       << "   Random seed = " << blaze::getSeed() << "\n"
       << "   Left-hand side " << ( IsRowMajorMatrix<LT>::value ? ( "row-major" ) : ( "column-major" ) ) << " dense matrix type:\n"
       << "     " << typeid( LT ).name() << "\n"
       << "   Right-hand side " << ( IsRowMajorMatrix<LT>::value ? ( "row-major" ) : ( "column-major" ) ) << " dense matrix type:\n"
       << "     " << typeid( RT ).name() << "\n"
       << "   Error message: " << ex.what() << "\n";
   throw std::runtime_error( oss.str() );
}
//*************************************************************************************************




//=================================================================================================
//
//  GLOBAL TEST FUNCTIONS
//
//=================================================================================================

//*************************************************************************************************
/*!\brief Testing the matrix minimum operation between two specific matrix types.
//
// \param creator1 The creator for the left-hand side matrix.
// \param creator2 The creator for the right-hand side matrix.
// \return void
*/
template< typename MT1    // Type of the left-hand side dense matrix
        , typename MT2 >  // Type of the right-hand side dense matrix
void runTest( const Creator<MT1>& creator1, const Creator<MT2>& creator2 )
{
#if BLAZETEST_MATHTEST_TEST_MINIMUM
   if( BLAZETEST_MATHTEST_TEST_MINIMUM > 1 )
   {
      for( size_t rep=0UL; rep<repetitions; ++rep ) {
         OperationTest<MT1,MT2>( creator1, creator2 );
      }
   }
#endif
}
//*************************************************************************************************




//=================================================================================================
//
//  MACROS
//
//=================================================================================================

//*************************************************************************************************
/*! \cond BLAZE_INTERNAL */
/*!\brief Macro for the definition of a dense matrix/dense matrix minimum test case.
*/
#define DEFINE_DMATDMATMIN_OPERATION_TEST( MT1, MT2 ) \
   extern template class blazetest::mathtest::dmatdmatmin::OperationTest<MT1,MT2>
/*! \endcond */
//*************************************************************************************************


//*************************************************************************************************
/*! \cond BLAZE_INTERNAL */
/*!\brief Macro for the execution of a dense matrix/dense matrix minimum test case.
*/
#define RUN_DMATDMATMIN_OPERATION_TEST( C1, C2 ) \
   blazetest::mathtest::dmatdmatmin::runTest( C1, C2 )
/*! \endcond */
//*************************************************************************************************

} // namespace dmatdmatmin

} // namespace mathtest

} // namespace blazetest

#endif
