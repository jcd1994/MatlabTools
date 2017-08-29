//=================================================================================================
/*!
//  \file blaze/math/adaptors/LowerMatrix.h
//  \brief Header file for the implementation of a lower matrix adaptor
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

#ifndef _BLAZE_MATH_ADAPTORS_LOWERMATRIX_H_
#define _BLAZE_MATH_ADAPTORS_LOWERMATRIX_H_


//*************************************************************************************************
// Includes
//*************************************************************************************************

#include <blaze/math/Aliases.h>
#include <blaze/math/adaptors/lowermatrix/BaseTemplate.h>
#include <blaze/math/adaptors/lowermatrix/Dense.h>
#include <blaze/math/adaptors/lowermatrix/Sparse.h>
#include <blaze/math/constraints/BLASCompatible.h>
#include <blaze/math/constraints/Hermitian.h>
#include <blaze/math/constraints/Lower.h>
#include <blaze/math/constraints/RequiresEvaluation.h>
#include <blaze/math/constraints/Symmetric.h>
#include <blaze/math/constraints/UniTriangular.h>
#include <blaze/math/constraints/Upper.h>
#include <blaze/math/Exception.h>
#include <blaze/math/Forward.h>
#include <blaze/math/InversionFlag.h>
#include <blaze/math/shims/IsDefault.h>
#include <blaze/math/shims/IsDivisor.h>
#include <blaze/math/traits/AddTrait.h>
#include <blaze/math/traits/BinaryMapTrait.h>
#include <blaze/math/traits/ColumnTrait.h>
#include <blaze/math/traits/DeclDiagTrait.h>
#include <blaze/math/traits/DeclHermTrait.h>
#include <blaze/math/traits/DeclLowTrait.h>
#include <blaze/math/traits/DeclSymTrait.h>
#include <blaze/math/traits/DeclUppTrait.h>
#include <blaze/math/traits/DivTrait.h>
#include <blaze/math/traits/MultTrait.h>
#include <blaze/math/traits/RowTrait.h>
#include <blaze/math/traits/SchurTrait.h>
#include <blaze/math/traits/SubmatrixTrait.h>
#include <blaze/math/traits/SubTrait.h>
#include <blaze/math/traits/UnaryMapTrait.h>
#include <blaze/math/typetraits/Columns.h>
#include <blaze/math/typetraits/HasConstDataAccess.h>
#include <blaze/math/typetraits/HighType.h>
#include <blaze/math/typetraits/IsAdaptor.h>
#include <blaze/math/typetraits/IsAligned.h>
#include <blaze/math/typetraits/IsLower.h>
#include <blaze/math/typetraits/IsPadded.h>
#include <blaze/math/typetraits/IsResizable.h>
#include <blaze/math/typetraits/IsRestricted.h>
#include <blaze/math/typetraits/IsShrinkable.h>
#include <blaze/math/typetraits/IsSquare.h>
#include <blaze/math/typetraits/LowType.h>
#include <blaze/math/typetraits/RemoveAdaptor.h>
#include <blaze/math/typetraits/Rows.h>
#include <blaze/util/algorithms/Min.h>
#include <blaze/util/Assert.h>
#include <blaze/util/EnableIf.h>
#include <blaze/util/IntegralConstant.h>
#include <blaze/util/TrueType.h>
#include <blaze/util/typetraits/IsNumeric.h>
#include <blaze/util/Unused.h>


namespace blaze {

//=================================================================================================
//
//  LOWERMATRIX OPERATORS
//
//=================================================================================================

//*************************************************************************************************
/*!\name LowerMatrix operators */
//@{
template< typename MT, bool SO, bool DF >
inline void reset( LowerMatrix<MT,SO,DF>& m );

template< typename MT, bool SO, bool DF >
inline void reset( LowerMatrix<MT,SO,DF>& m, size_t i );

template< typename MT, bool SO, bool DF >
inline void clear( LowerMatrix<MT,SO,DF>& m );

template< bool RF, typename MT, bool SO, bool DF >
inline bool isDefault( const LowerMatrix<MT,SO,DF>& m );

template< typename MT, bool SO, bool DF >
inline bool isIntact( const LowerMatrix<MT,SO,DF>& m );

template< typename MT, bool SO, bool DF >
inline void swap( LowerMatrix<MT,SO,DF>& a, LowerMatrix<MT,SO,DF>& b ) noexcept;
//@}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Resetting the given lower matrix.
// \ingroup lower_matrix
//
// \param m The lower matrix to be resetted.
// \return void
*/
template< typename MT  // Type of the adapted matrix
        , bool SO      // Storage order of the adapted matrix
        , bool DF >    // Density flag
inline void reset( LowerMatrix<MT,SO,DF>& m )
{
   m.reset();
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Resetting the specified row/column of the given lower matrix.
// \ingroup lower_matrix
//
// \param m The lower matrix to be resetted.
// \param i The index of the row/column to be resetted.
// \return void
//
// This function resets the values in the specified row/column of the given lower matrix to their
// default value. In case the given matrix is a \a rowMajor matrix the function resets the values
// in row \a i, if it is a \a columnMajor matrix the function resets the values in column \a i.
// Note that the capacity of the row/column remains unchanged.
*/
template< typename MT  // Type of the adapted matrix
        , bool SO      // Storage order of the adapted matrix
        , bool DF >    // Density flag
inline void reset( LowerMatrix<MT,SO,DF>& m, size_t i )
{
   m.reset( i );
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Clearing the given lower matrix.
// \ingroup lower_matrix
//
// \param m The lower matrix to be cleared.
// \return void
*/
template< typename MT  // Type of the adapted matrix
        , bool SO      // Storage order of the adapted matrix
        , bool DF >    // Density flag
inline void clear( LowerMatrix<MT,SO,DF>& m )
{
   m.clear();
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Returns whether the given lower matrix is in default state.
// \ingroup lower_matrix
//
// \param m The lower matrix to be tested for its default state.
// \return \a true in case the given matrix is component-wise zero, \a false otherwise.
//
// This function checks whether the matrix is in default state. For instance, in case the
// matrix is instantiated for a built-in integral or floating point data type, the function
// returns \a true in case all matrix elements are 0 and \a false in case any matrix element
// is not 0. The following example demonstrates the use of the \a isDefault function:

   \code
   using blaze::DynamicMatrix;
   using blaze::LowerMatrix;

   LowerMatrix< DynamicMatrix<int> > A;
   // ... Resizing and initialization
   if( isDefault( A ) ) { ... }
   \endcode

// Optionally, it is possible to switch between strict semantics (blaze::strict) and relaxed
// semantics (blaze::relaxed):

   \code
   if( isDefault<relaxed>( A ) ) { ... }
   \endcode
*/
template< bool RF      // Relaxation flag
        , typename MT  // Type of the adapted matrix
        , bool SO      // Storage order of the adapted matrix
        , bool DF >    // Density flag
inline bool isDefault( const LowerMatrix<MT,SO,DF>& m )
{
   return isDefault<RF>( m.matrix_ );
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Returns whether the invariants of the given lower matrix are intact.
// \ingroup lower_matrix
//
// \param m The lower matrix to be tested.
// \return \a true in case the given matrix's invariants are intact, \a false otherwise.
//
// This function checks whether the invariants of the lower matrix are intact, i.e. if its
// state is valid. In case the invariants are intact, the function returns \a true, else it
// will return \a false. The following example demonstrates the use of the \a isIntact()
// function:

   \code
   using blaze::DynamicMatrix;
   using blaze::LowerMatrix;

   LowerMatrix< DynamicMatrix<int> > A;
   // ... Resizing and initialization
   if( isIntact( A ) ) { ... }
   \endcode
*/
template< typename MT  // Type of the adapted matrix
        , bool SO      // Storage order of the adapted matrix
        , bool DF >    // Density flag
inline bool isIntact( const LowerMatrix<MT,SO,DF>& m )
{
   return m.isIntact();
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Swapping the contents of two matrices.
// \ingroup lower_matrix
//
// \param a The first matrix to be swapped.
// \param b The second matrix to be swapped.
// \return void
*/
template< typename MT  // Type of the adapted matrix
        , bool SO      // Storage order of the adapted matrix
        , bool DF >    // Density flag
inline void swap( LowerMatrix<MT,SO,DF>& a, LowerMatrix<MT,SO,DF>& b ) noexcept
{
   a.swap( b );
}
//*************************************************************************************************


//*************************************************************************************************
/*! \cond BLAZE_INTERNAL */
/*!\brief In-place inversion of the given lower dense matrix.
// \ingroup lower_matrix
//
// \param m The lower dense matrix to be inverted.
// \return void
// \exception std::invalid_argument Inversion of singular matrix failed.
//
// This function inverts the given lower dense matrix by means of the specified matrix inversion
// algorithm \c IF. The The inversion fails if the given matrix is singular and not invertible.
// In this case a \a std::invalid_argument exception is thrown.
//
// \note The matrix inversion can only be used for dense matrices with \c float, \c double,
// \c complex<float> or \c complex<double> element type. The attempt to call the function with
// matrices of any other element type results in a compile time error!
//
// \note This function can only be used if a fitting LAPACK library is available and linked to
// the executable. Otherwise a linker error will be created.
//
// \note This function does only provide the basic exception safety guarantee, i.e. in case of an
// exception \a m may already have been modified.
*/
template< InversionFlag IF  // Inversion algorithm
        , typename MT       // Type of the dense matrix
        , bool SO >         // Storage order of the dense matrix
inline void invert( LowerMatrix<MT,SO,true>& m )
{
   BLAZE_CONSTRAINT_MUST_BE_BLAS_COMPATIBLE_TYPE( ElementType_<MT> );

   if( IF == asUniUpper ) {
      BLAZE_INTERNAL_ASSERT( isIdentity( m ), "Violation of preconditions detected" );
      return;
   }

   constexpr InversionFlag flag( ( IF == byLU || IF == asGeneral || IF == asLower )
                                 ? ( asLower )
                                 : ( ( IF == asUniLower )
                                     ?( asUniLower )
                                     :( asDiagonal ) ) );

   invert<flag>( derestrict( m ) );

   BLAZE_INTERNAL_ASSERT( isIntact( m ), "Broken invariant detected" );
}
/*! \endcond */
//*************************************************************************************************


//*************************************************************************************************
/*! \cond BLAZE_INTERNAL */
/*!\brief LU decomposition of the given lower dense matrix.
// \ingroup lower_matrix
//
// \param A The lower matrix to be decomposed.
// \param L The resulting lower triangular matrix.
// \param U The resulting upper triangular matrix.
// \param P The resulting permutation matrix.
// \return void
//
// This function performs the dense matrix (P)LU decomposition of a lower n-by-n matrix. The
// resulting decomposition is written to the three distinct matrices \c L, \c U, and \c P, which
// are resized to the correct dimensions (if possible and necessary).
//
// \note The LU decomposition will never fail, even for singular matrices. However, in case of a
// singular matrix the resulting decomposition cannot be used for a matrix inversion or solving
// a linear system of equations.
*/
template< typename MT1, bool SO1, typename MT2, typename MT3, typename MT4, bool SO2 >
inline void lu( const LowerMatrix<MT1,SO1,true>& A, DenseMatrix<MT2,SO1>& L,
                DenseMatrix<MT3,SO1>& U, Matrix<MT4,SO2>& P )
{
   BLAZE_CONSTRAINT_MUST_BE_BLAS_COMPATIBLE_TYPE( ElementType_<MT1> );

   BLAZE_CONSTRAINT_MUST_NOT_BE_SYMMETRIC_MATRIX_TYPE( MT2 );
   BLAZE_CONSTRAINT_MUST_NOT_BE_HERMITIAN_MATRIX_TYPE( MT2 );
   BLAZE_CONSTRAINT_MUST_NOT_BE_UNITRIANGULAR_MATRIX_TYPE( MT2 );
   BLAZE_CONSTRAINT_MUST_NOT_BE_UPPER_MATRIX_TYPE( MT2 );

   BLAZE_CONSTRAINT_MUST_NOT_BE_SYMMETRIC_MATRIX_TYPE( MT3 );
   BLAZE_CONSTRAINT_MUST_NOT_BE_HERMITIAN_MATRIX_TYPE( MT3 );
   BLAZE_CONSTRAINT_MUST_NOT_BE_UNITRIANGULAR_MATRIX_TYPE( MT3 );
   BLAZE_CONSTRAINT_MUST_NOT_BE_LOWER_MATRIX_TYPE( MT3 );

   using ET3 = ElementType_<MT3>;
   using ET4 = ElementType_<MT4>;

   const size_t n( (~A).rows() );

   decltype(auto) U2( derestrict( ~U ) );

   (~L) = A;

   resize( ~U, n, n );
   reset( U2 );

   resize( ~P, n, n );
   reset( ~P );

   for( size_t i=0UL; i<n; ++i ) {
      U2(i,i)   = ET3(1);
      (~P)(i,i) = ET4(1);
   }
}
/*! \endcond */
//*************************************************************************************************


//*************************************************************************************************
/*! \cond BLAZE_INTERNAL */
/*!\brief Predict invariant violations by the assignment of a dense vector to a lower matrix.
// \ingroup lower_matrix
//
// \param lhs The target left-hand side lower matrix.
// \param rhs The right-hand side dense vector to be assigned.
// \param row The row index of the first element to be modified.
// \param column The column index of the first element to be modified.
// \return \a true in case the assignment would be successful, \a false if not.
//
// This function must \b NOT be called explicitly! It is used internally for the performance
// optimized evaluation of expression templates. Calling this function explicitly might result
// in erroneous results and/or in compilation errors. Instead of using this function use the
// assignment operator.
*/
template< typename MT    // Type of the adapted matrix
        , bool SO        // Storage order of the adapted matrix
        , bool DF        // Density flag
        , typename VT >  // Type of the right-hand side dense vector
inline bool tryAssign( const LowerMatrix<MT,SO,DF>& lhs,
                       const DenseVector<VT,false>& rhs, size_t row, size_t column )
{
   BLAZE_CONSTRAINT_MUST_NOT_REQUIRE_EVALUATION( VT );

   BLAZE_INTERNAL_ASSERT( row <= lhs.rows(), "Invalid row access index" );
   BLAZE_INTERNAL_ASSERT( column <= lhs.columns(), "Invalid column access index" );
   BLAZE_INTERNAL_ASSERT( (~rhs).size() <= lhs.rows() - row, "Invalid number of rows" );

   UNUSED_PARAMETER( lhs );

   if( column <= row )
      return true;

   const size_t iend( min( column - row, (~rhs).size() ) );

   for( size_t i=0UL; i<iend; ++i ) {
      if( !isDefault( (~rhs)[i] ) )
         return false;
   }

   return true;
}
/*! \endcond */
//*************************************************************************************************


//*************************************************************************************************
/*! \cond BLAZE_INTERNAL */
/*!\brief Predict invariant violations by the assignment of a dense vector to a lower matrix.
// \ingroup lower_matrix
//
// \param lhs The target left-hand side lower matrix.
// \param rhs The right-hand side dense vector to be assigned.
// \param row The row index of the first element to be modified.
// \param column The column index of the first element to be modified.
// \return \a true in case the assignment would be successful, \a false if not.
//
// This function must \b NOT be called explicitly! It is used internally for the performance
// optimized evaluation of expression templates. Calling this function explicitly might result
// in erroneous results and/or in compilation errors. Instead of using this function use the
// assignment operator.
*/
template< typename MT    // Type of the adapted matrix
        , bool SO        // Storage order of the adapted matrix
        , bool DF        // Density flag
        , typename VT >  // Type of the right-hand side dense vector
inline bool tryAssign( const LowerMatrix<MT,SO,DF>& lhs,
                       const DenseVector<VT,true>& rhs, size_t row, size_t column )
{
   BLAZE_CONSTRAINT_MUST_NOT_REQUIRE_EVALUATION( VT );

   BLAZE_INTERNAL_ASSERT( row <= lhs.rows(), "Invalid row access index" );
   BLAZE_INTERNAL_ASSERT( column <= lhs.columns(), "Invalid column access index" );
   BLAZE_INTERNAL_ASSERT( (~rhs).size() <= lhs.columns() - column, "Invalid number of columns" );

   UNUSED_PARAMETER( lhs );

   const size_t ibegin( ( row < column )?( 0UL ):( row - column + 1UL ) );

   for( size_t i=ibegin; i<(~rhs).size(); ++i ) {
      if( !isDefault( (~rhs)[i] ) )
         return false;
   }

   return true;
}
/*! \endcond */
//*************************************************************************************************


//*************************************************************************************************
/*! \cond BLAZE_INTERNAL */
/*!\brief Predict invariant violations by the assignment of a sparse vector to a lower matrix.
// \ingroup lower_matrix
//
// \param lhs The target left-hand side lower matrix.
// \param rhs The right-hand side sparse vector to be assigned.
// \param row The row index of the first element to be modified.
// \param column The column index of the first element to be modified.
// \return \a true in case the assignment would be successful, \a false if not.
//
// This function must \b NOT be called explicitly! It is used internally for the performance
// optimized evaluation of expression templates. Calling this function explicitly might result
// in erroneous results and/or in compilation errors. Instead of using this function use the
// assignment operator.
*/
template< typename MT    // Type of the adapted matrix
        , bool SO        // Storage order of the adapted matrix
        , bool DF        // Density flag
        , typename VT >  // Type of the right-hand side sparse vector
inline bool tryAssign( const LowerMatrix<MT,SO,DF>& lhs,
                       const SparseVector<VT,false>& rhs, size_t row, size_t column )
{
   BLAZE_CONSTRAINT_MUST_NOT_REQUIRE_EVALUATION( VT );

   BLAZE_INTERNAL_ASSERT( row <= lhs.rows(), "Invalid row access index" );
   BLAZE_INTERNAL_ASSERT( column <= lhs.columns(), "Invalid column access index" );
   BLAZE_INTERNAL_ASSERT( (~rhs).size() <= lhs.rows() - row, "Invalid number of rows" );

   UNUSED_PARAMETER( lhs );

   using RhsIterator = typename VT::ConstIterator;

   if( column <= row )
      return true;

   const RhsIterator last( (~rhs).lowerBound( column - row ) );

   for( RhsIterator element=(~rhs).begin(); element!=last; ++element ) {
      if( !isDefault( element->value() ) )
         return false;
   }

   return true;
}
/*! \endcond */
//*************************************************************************************************


//*************************************************************************************************
/*! \cond BLAZE_INTERNAL */
/*!\brief Predict invariant violations by the assignment of a sparse vector to a lower matrix.
// \ingroup lower_matrix
//
// \param lhs The target left-hand side lower matrix.
// \param rhs The right-hand side sparse vector to be assigned.
// \param row The row index of the first element to be modified.
// \param column The column index of the first element to be modified.
// \return \a true in case the assignment would be successful, \a false if not.
//
// This function must \b NOT be called explicitly! It is used internally for the performance
// optimized evaluation of expression templates. Calling this function explicitly might result
// in erroneous results and/or in compilation errors. Instead of using this function use the
// assignment operator.
*/
template< typename MT    // Type of the adapted matrix
        , bool SO        // Storage order of the adapted matrix
        , bool DF        // Density flag
        , typename VT >  // Type of the right-hand side sparse vector
inline bool tryAssign( const LowerMatrix<MT,SO,DF>& lhs,
                       const SparseVector<VT,true>& rhs, size_t row, size_t column )
{
   BLAZE_CONSTRAINT_MUST_NOT_REQUIRE_EVALUATION( VT );

   BLAZE_INTERNAL_ASSERT( row <= lhs.rows(), "Invalid row access index" );
   BLAZE_INTERNAL_ASSERT( column <= lhs.columns(), "Invalid column access index" );
   BLAZE_INTERNAL_ASSERT( (~rhs).size() <= lhs.columns() - column, "Invalid number of columns" );

   UNUSED_PARAMETER( lhs );

   using RhsIterator = typename VT::ConstIterator;

   const RhsIterator last( (~rhs).end() );
   RhsIterator element( (~rhs).lowerBound( ( row < column )?( 0UL ):( row - column + 1UL ) ) );

   for( ; element!=last; ++element ) {
      if( !isDefault( element->value() ) )
         return false;
   }

   return true;
}
/*! \endcond */
//*************************************************************************************************


//*************************************************************************************************
/*! \cond BLAZE_INTERNAL */
/*!\brief Predict invariant violations by the assignment of a dense matrix to a lower matrix.
// \ingroup lower_matrix
//
// \param lhs The target left-hand side lower matrix.
// \param rhs The right-hand side dense matrix to be assigned.
// \param row The row index of the first element to be modified.
// \param column The column index of the first element to be modified.
// \return \a true in case the assignment would be successful, \a false if not.
//
// This function must \b NOT be called explicitly! It is used internally for the performance
// optimized evaluation of expression templates. Calling this function explicitly might result
// in erroneous results and/or in compilation errors. Instead of using this function use the
// assignment operator.
*/
template< typename MT1    // Type of the adapted matrix
        , bool SO         // Storage order of the adapted matrix
        , bool DF         // Density flag
        , typename MT2 >  // Type of the right-hand side dense matrix
inline bool tryAssign( const LowerMatrix<MT1,SO,DF>& lhs,
                       const DenseMatrix<MT2,false>& rhs, size_t row, size_t column )
{
   BLAZE_CONSTRAINT_MUST_NOT_REQUIRE_EVALUATION( MT2 );

   BLAZE_INTERNAL_ASSERT( row <= lhs.rows(), "Invalid row access index" );
   BLAZE_INTERNAL_ASSERT( column <= lhs.columns(), "Invalid column access index" );
   BLAZE_INTERNAL_ASSERT( (~rhs).rows() <= lhs.rows() - row, "Invalid number of rows" );
   BLAZE_INTERNAL_ASSERT( (~rhs).columns() <= lhs.columns() - column, "Invalid number of columns" );

   UNUSED_PARAMETER( lhs );

   const size_t M( (~rhs).rows()    );
   const size_t N( (~rhs).columns() );

   if( row + 1UL >= column + N )
      return true;

   const size_t iend( min( column + N - row - 1UL, M ) );

   for( size_t i=0UL; i<iend; ++i )
   {
      const bool containsDiagonal( row + i >= column );
      const size_t jbegin( ( containsDiagonal )?( row + i - column + 1UL ):( 0UL ) );

      for( size_t j=jbegin; j<N; ++j ) {
         if( !isDefault( (~rhs)(i,j) ) )
            return false;
      }
   }

   return true;
}
/*! \endcond */
//*************************************************************************************************


//*************************************************************************************************
/*! \cond BLAZE_INTERNAL */
/*!\brief Predict invariant violations by the assignment of a dense matrix to a lower matrix.
// \ingroup lower_matrix
//
// \param lhs The target left-hand side lower matrix.
// \param rhs The right-hand side dense matrix to be assigned.
// \param row The row index of the first element to be modified.
// \param column The column index of the first element to be modified.
// \return \a true in case the assignment would be successful, \a false if not.
//
// This function must \b NOT be called explicitly! It is used internally for the performance
// optimized evaluation of expression templates. Calling this function explicitly might result
// in erroneous results and/or in compilation errors. Instead of using this function use the
// assignment operator.
*/
template< typename MT1    // Type of the adapted matrix
        , bool SO         // Storage order of the adapted matrix
        , bool DF         // Density flag
        , typename MT2 >  // Type of the right-hand side dense matrix
inline bool tryAssign( const LowerMatrix<MT1,SO,DF>& lhs,
                       const DenseMatrix<MT2,true>& rhs, size_t row, size_t column )
{
   BLAZE_CONSTRAINT_MUST_NOT_REQUIRE_EVALUATION( MT2 );

   BLAZE_INTERNAL_ASSERT( row <= lhs.rows(), "Invalid row access index" );
   BLAZE_INTERNAL_ASSERT( column <= lhs.columns(), "Invalid column access index" );
   BLAZE_INTERNAL_ASSERT( (~rhs).rows() <= lhs.rows() - row, "Invalid number of rows" );
   BLAZE_INTERNAL_ASSERT( (~rhs).columns() <= lhs.columns() - column, "Invalid number of columns" );

   UNUSED_PARAMETER( lhs );

   const size_t M( (~rhs).rows()    );
   const size_t N( (~rhs).columns() );

   if( row + 1UL >= column + N )
      return true;

   const size_t jbegin( ( row < column )?( 0UL ):( row - column + 1UL ) );

   for( size_t j=jbegin; j<N; ++j )
   {
      const size_t iend( min( column + j - row, M ) );

      for( size_t i=0UL; i<iend; ++i ) {
         if( !isDefault( (~rhs)(i,j) ) )
            return false;
      }
   }

   return true;
}
/*! \endcond */
//*************************************************************************************************


//*************************************************************************************************
/*! \cond BLAZE_INTERNAL */
/*!\brief Predict invariant violations by the assignment of a sparse matrix to a lower matrix.
// \ingroup lower_matrix
//
// \param lhs The target left-hand side lower matrix.
// \param rhs The right-hand side sparse matrix to be assigned.
// \param row The row index of the first element to be modified.
// \param column The column index of the first element to be modified.
// \return \a true in case the assignment would be successful, \a false if not.
//
// This function must \b NOT be called explicitly! It is used internally for the performance
// optimized evaluation of expression templates. Calling this function explicitly might result
// in erroneous results and/or in compilation errors. Instead of using this function use the
// assignment operator.
*/
template< typename MT1    // Type of the adapted matrix
        , bool SO         // Storage order of the adapted matrix
        , bool DF         // Density flag
        , typename MT2 >  // Type of the right-hand side sparse matrix
inline bool tryAssign( const LowerMatrix<MT1,SO,DF>& lhs,
                       const SparseMatrix<MT2,false>& rhs, size_t row, size_t column )
{
   BLAZE_CONSTRAINT_MUST_NOT_REQUIRE_EVALUATION( MT2 );

   BLAZE_INTERNAL_ASSERT( row <= lhs.rows(), "Invalid row access index" );
   BLAZE_INTERNAL_ASSERT( column <= lhs.columns(), "Invalid column access index" );
   BLAZE_INTERNAL_ASSERT( (~rhs).rows() <= lhs.rows() - row, "Invalid number of rows" );
   BLAZE_INTERNAL_ASSERT( (~rhs).columns() <= lhs.columns() - column, "Invalid number of columns" );

   UNUSED_PARAMETER( lhs );

   using RhsIterator = typename MT2::ConstIterator;

   const size_t M( (~rhs).rows()    );
   const size_t N( (~rhs).columns() );

   if( row + 1UL >= column + N )
      return true;

   const size_t iend( min( column + N - row - 1UL, M ) );

   for( size_t i=0UL; i<iend; ++i )
   {
      const bool containsDiagonal( row + i >= column );
      const size_t index( ( containsDiagonal )?( row + i - column + 1UL ):( 0UL ) );

      const RhsIterator last( (~rhs).end(i) );
      RhsIterator element( (~rhs).lowerBound( i, index ) );

      for( ; element!=last; ++element ) {
         if( !isDefault( element->value() ) )
            return false;
      }
   }

   return true;
}
/*! \endcond */
//*************************************************************************************************


//*************************************************************************************************
/*! \cond BLAZE_INTERNAL */
/*!\brief Predict invariant violations by the assignment of a sparse matrix to a lower matrix.
// \ingroup lower_matrix
//
// \param lhs The target left-hand side lower matrix.
// \param rhs The right-hand side sparse matrix to be assigned.
// \param row The row index of the first element to be modified.
// \param column The column index of the first element to be modified.
// \return \a true in case the assignment would be successful, \a false if not.
//
// This function must \b NOT be called explicitly! It is used internally for the performance
// optimized evaluation of expression templates. Calling this function explicitly might result
// in erroneous results and/or in compilation errors. Instead of using this function use the
// assignment operator.
*/
template< typename MT1    // Type of the adapted matrix
        , bool SO         // Storage order of the adapted matrix
        , bool DF         // Density flag
        , typename MT2 >  // Type of the right-hand side sparse matrix
inline bool tryAssign( const LowerMatrix<MT1,SO,DF>& lhs,
                       const SparseMatrix<MT2,true>& rhs, size_t row, size_t column )
{
   BLAZE_CONSTRAINT_MUST_NOT_REQUIRE_EVALUATION( MT2 );

   BLAZE_INTERNAL_ASSERT( row <= lhs.rows(), "Invalid row access index" );
   BLAZE_INTERNAL_ASSERT( column <= lhs.columns(), "Invalid column access index" );
   BLAZE_INTERNAL_ASSERT( (~rhs).rows() <= lhs.rows() - row, "Invalid number of rows" );
   BLAZE_INTERNAL_ASSERT( (~rhs).columns() <= lhs.columns() - column, "Invalid number of columns" );

   UNUSED_PARAMETER( lhs );

   using RhsIterator = typename MT2::ConstIterator;

   const size_t M( (~rhs).rows()    );
   const size_t N( (~rhs).columns() );

   if( row + 1UL >= column + N )
      return true;

   const size_t jbegin( ( row < column )?( 0UL ):( row - column + 1UL ) );

   for( size_t j=jbegin; j<N; ++j )
   {
      const size_t index( column + j - row );
      const RhsIterator last( (~rhs).lowerBound( min( index, M ), j ) );

      for( RhsIterator element=(~rhs).begin(j); element!=last; ++element ) {
         if( !isDefault( element->value() ) )
            return false;
      }
   }

   return true;
}
/*! \endcond */
//*************************************************************************************************


//*************************************************************************************************
/*! \cond BLAZE_INTERNAL */
/*!\brief Predict invariant violations by the addition assignment of a vector to a lower matrix.
// \ingroup lower_matrix
//
// \param lhs The target left-hand side lower matrix.
// \param rhs The right-hand side vector to be added.
// \param row The row index of the first element to be modified.
// \param column The column index of the first element to be modified.
// \return \a true in case the assignment would be successful, \a false if not.
//
// This function must \b NOT be called explicitly! It is used internally for the performance
// optimized evaluation of expression templates. Calling this function explicitly might result
// in erroneous results and/or in compilation errors. Instead of using this function use the
// assignment operator.
*/
template< typename MT  // Type of the adapted matrix
        , bool SO      // Storage order of the adapted matrix
        , bool DF      // Density flag
        , typename VT  // Type of the right-hand side vector
        , bool TF >    // Transpose flag of the right-hand side vector
inline bool tryAddAssign( const LowerMatrix<MT,SO,DF>& lhs,
                          const Vector<VT,TF>& rhs, size_t row, size_t column )
{
   return tryAssign( lhs, ~rhs, row, column );
}
/*! \endcond */
//*************************************************************************************************


//*************************************************************************************************
/*! \cond BLAZE_INTERNAL */
/*!\brief Predict invariant violations by the addition assignment of a matrix to a lower matrix.
// \ingroup lower_matrix
//
// \param lhs The target left-hand side lower matrix.
// \param rhs The right-hand side matrix to be added.
// \param row The row index of the first element to be modified.
// \param column The column index of the first element to be modified.
// \return \a true in case the assignment would be successful, \a false if not.
//
// This function must \b NOT be called explicitly! It is used internally for the performance
// optimized evaluation of expression templates. Calling this function explicitly might result
// in erroneous results and/or in compilation errors. Instead of using this function use the
// assignment operator.
*/
template< typename MT1  // Type of the adapted matrix
        , bool SO1      // Storage order of the adapted matrix
        , bool DF       // Density flag
        , typename MT2  // Type of the right-hand side matrix
        , bool SO2 >    // Storage order of the right-hand side matrix
inline bool tryAddAssign( const LowerMatrix<MT1,SO1,DF>& lhs,
                          const Matrix<MT2,SO2>& rhs, size_t row, size_t column )
{
   return tryAssign( lhs, ~rhs, row, column );
}
/*! \endcond */
//*************************************************************************************************


//*************************************************************************************************
/*! \cond BLAZE_INTERNAL */
/*!\brief Predict invariant violations by the subtraction assignment of a vector to a lower matrix.
// \ingroup lower_matrix
//
// \param lhs The target left-hand side lower matrix.
// \param rhs The right-hand side vector to be subtracted.
// \param row The row index of the first element to be modified.
// \param column The column index of the first element to be modified.
// \return \a true in case the assignment would be successful, \a false if not.
//
// This function must \b NOT be called explicitly! It is used internally for the performance
// optimized evaluation of expression templates. Calling this function explicitly might result
// in erroneous results and/or in compilation errors. Instead of using this function use the
// assignment operator.
*/
template< typename MT  // Type of the adapted matrix
        , bool SO      // Storage order of the adapted matrix
        , bool DF      // Density flag
        , typename VT  // Type of the right-hand side vector
        , bool TF >    // Transpose flag of the right-hand side vector
inline bool trySubAssign( const LowerMatrix<MT,SO,DF>& lhs,
                          const Vector<VT,TF>& rhs, size_t row, size_t column )
{
   return tryAssign( lhs, ~rhs, row, column );
}
/*! \endcond */
//*************************************************************************************************


//*************************************************************************************************
/*! \cond BLAZE_INTERNAL */
/*!\brief Predict invariant violations by the subtraction assignment of a matrix to a lower matrix.
// \ingroup lower_matrix
//
// \param lhs The target left-hand side lower matrix.
// \param rhs The right-hand side matrix to be subtracted.
// \param row The row index of the first element to be modified.
// \param column The column index of the first element to be modified.
// \return \a true in case the assignment would be successful, \a false if not.
//
// This function must \b NOT be called explicitly! It is used internally for the performance
// optimized evaluation of expression templates. Calling this function explicitly might result
// in erroneous results and/or in compilation errors. Instead of using this function use the
// assignment operator.
*/
template< typename MT1  // Type of the adapted matrix
        , bool SO1      // Storage order of the adapted matrix
        , bool DF       // Density flag
        , typename MT2  // Type of the right-hand side matrix
        , bool SO2 >    // Storage order of the right-hand side matrix
inline bool trySubAssign( const LowerMatrix<MT1,SO1,DF>& lhs,
                          const Matrix<MT2,SO2>& rhs, size_t row, size_t column )
{
   return tryAssign( lhs, ~rhs, row, column );
}
/*! \endcond */
//*************************************************************************************************


//*************************************************************************************************
/*! \cond BLAZE_INTERNAL */
/*!\brief Returns a reference to the instance without the access restrictions to the upper part.
// \ingroup lower_matrix
//
// \param m The lower matrix to be derestricted.
// \return Reference to the matrix without access restrictions.
//
// This function returns a reference to the given lower matrix instance that has no access
// restrictions to the upper part of the matrix.\n
// This function must \b NOT be called explicitly! It is used internally for the performance
// optimized evaluation of expression templates. Calling this function explicitly might result
// in the violation of invariants, erroneous results and/or in compilation errors.
*/
template< typename MT  // Type of the adapted matrix
        , bool SO      // Storage order of the adapted matrix
        , bool DF >    // Density flag
inline MT& derestrict( LowerMatrix<MT,SO,DF>& m )
{
   return m.matrix_;
}
/*! \endcond */
//*************************************************************************************************




//=================================================================================================
//
//  ROWS SPECIALIZATIONS
//
//=================================================================================================

//*************************************************************************************************
/*! \cond BLAZE_INTERNAL */
template< typename MT, bool SO, bool DF >
struct Rows< LowerMatrix<MT,SO,DF> >
   : public Rows<MT>
{};
/*! \endcond */
//*************************************************************************************************




//=================================================================================================
//
//  COLUMNS SPECIALIZATIONS
//
//=================================================================================================

//*************************************************************************************************
/*! \cond BLAZE_INTERNAL */
template< typename MT, bool SO, bool DF >
struct Columns< LowerMatrix<MT,SO,DF> >
   : public Columns<MT>
{};
/*! \endcond */
//*************************************************************************************************




//=================================================================================================
//
//  ISSQUARE SPECIALIZATIONS
//
//=================================================================================================

//*************************************************************************************************
/*! \cond BLAZE_INTERNAL */
template< typename MT, bool SO, bool DF >
struct IsSquare< LowerMatrix<MT,SO,DF> >
   : public TrueType
{};
/*! \endcond */
//*************************************************************************************************




//=================================================================================================
//
//  ISLOWER SPECIALIZATIONS
//
//=================================================================================================

//*************************************************************************************************
/*! \cond BLAZE_INTERNAL */
template< typename MT, bool SO, bool DF >
struct IsLower< LowerMatrix<MT,SO,DF> >
   : public TrueType
{};
/*! \endcond */
//*************************************************************************************************




//=================================================================================================
//
//  ISADAPTOR SPECIALIZATIONS
//
//=================================================================================================

//*************************************************************************************************
/*! \cond BLAZE_INTERNAL */
template< typename MT, bool SO, bool DF >
struct IsAdaptor< LowerMatrix<MT,SO,DF> >
   : public TrueType
{};
/*! \endcond */
//*************************************************************************************************




//=================================================================================================
//
//  ISRESTRICTED SPECIALIZATIONS
//
//=================================================================================================

//*************************************************************************************************
/*! \cond BLAZE_INTERNAL */
template< typename MT, bool SO, bool DF >
struct IsRestricted< LowerMatrix<MT,SO,DF> >
   : public TrueType
{};
/*! \endcond */
//*************************************************************************************************




//=================================================================================================
//
//  HASCONSTDATAACCESS SPECIALIZATIONS
//
//=================================================================================================

//*************************************************************************************************
/*! \cond BLAZE_INTERNAL */
template< typename MT, bool SO >
struct HasConstDataAccess< LowerMatrix<MT,SO,true> >
   : public TrueType
{};
/*! \endcond */
//*************************************************************************************************




//=================================================================================================
//
//  ISALIGNED SPECIALIZATIONS
//
//=================================================================================================

//*************************************************************************************************
/*! \cond BLAZE_INTERNAL */
template< typename MT, bool SO, bool DF >
struct IsAligned< LowerMatrix<MT,SO,DF> >
   : public BoolConstant< IsAligned<MT>::value >
{};
/*! \endcond */
//*************************************************************************************************




//=================================================================================================
//
//  ISPADDED SPECIALIZATIONS
//
//=================================================================================================

//*************************************************************************************************
/*! \cond BLAZE_INTERNAL */
template< typename MT, bool SO, bool DF >
struct IsPadded< LowerMatrix<MT,SO,DF> >
   : public BoolConstant< IsPadded<MT>::value >
{};
/*! \endcond */
//*************************************************************************************************




//=================================================================================================
//
//  ISRESIZABLE SPECIALIZATIONS
//
//=================================================================================================

//*************************************************************************************************
/*! \cond BLAZE_INTERNAL */
template< typename MT, bool SO, bool DF >
struct IsResizable< LowerMatrix<MT,SO,DF> >
   : public BoolConstant< IsResizable<MT>::value >
{};
/*! \endcond */
//*************************************************************************************************




//=================================================================================================
//
//  ISSHRINKABLE SPECIALIZATIONS
//
//=================================================================================================

//*************************************************************************************************
/*! \cond BLAZE_INTERNAL */
template< typename MT, bool SO, bool DF >
struct IsShrinkable< LowerMatrix<MT,SO,DF> >
   : public BoolConstant< IsShrinkable<MT>::value >
{};
/*! \endcond */
//*************************************************************************************************




//=================================================================================================
//
//  REMOVEADAPTOR SPECIALIZATIONS
//
//=================================================================================================

//*************************************************************************************************
/*! \cond BLAZE_INTERNAL */
template< typename MT, bool SO, bool DF >
struct RemoveAdaptor< LowerMatrix<MT,SO,DF> >
{
   using Type = MT;
};
/*! \endcond */
//*************************************************************************************************




//=================================================================================================
//
//  ADDTRAIT SPECIALIZATIONS
//
//=================================================================================================

//*************************************************************************************************
/*! \cond BLAZE_INTERNAL */
template< typename MT, bool SO1, bool DF, typename T, size_t M, size_t N, bool SO2 >
struct AddTrait< LowerMatrix<MT,SO1,DF>, StaticMatrix<T,M,N,SO2> >
{
   using Type = AddTrait_< MT, StaticMatrix<T,M,N,SO2> >;
};

template< typename T, size_t M, size_t N, bool SO1, typename MT, bool SO2, bool DF >
struct AddTrait< StaticMatrix<T,M,N,SO1>, LowerMatrix<MT,SO2,DF> >
{
   using Type = AddTrait_< StaticMatrix<T,M,N,SO1>, MT >;
};

template< typename MT, bool SO1, bool DF, typename T, size_t M, size_t N, bool SO2 >
struct AddTrait< LowerMatrix<MT,SO1,DF>, HybridMatrix<T,M,N,SO2> >
{
   using Type = AddTrait_< MT, HybridMatrix<T,M,N,SO2> >;
};

template< typename T, size_t M, size_t N, bool SO1, typename MT, bool SO2, bool DF >
struct AddTrait< HybridMatrix<T,M,N,SO1>, LowerMatrix<MT,SO2,DF> >
{
   using Type = AddTrait_< HybridMatrix<T,M,N,SO1>, MT >;
};

template< typename MT, bool SO1, bool DF, typename T, bool SO2 >
struct AddTrait< LowerMatrix<MT,SO1,DF>, DynamicMatrix<T,SO2> >
{
   using Type = AddTrait_< MT, DynamicMatrix<T,SO2> >;
};

template< typename T, bool SO1, typename MT, bool SO2, bool DF >
struct AddTrait< DynamicMatrix<T,SO1>, LowerMatrix<MT,SO2,DF> >
{
   using Type = AddTrait_< DynamicMatrix<T,SO1>, MT >;
};

template< typename MT, bool SO1, bool DF, typename T, bool AF, bool PF, bool SO2 >
struct AddTrait< LowerMatrix<MT,SO1,DF>, CustomMatrix<T,AF,PF,SO2> >
{
   using Type = AddTrait_< MT, CustomMatrix<T,AF,PF,SO2> >;
};

template< typename T, bool AF, bool PF, bool SO1, typename MT, bool SO2, bool DF >
struct AddTrait< CustomMatrix<T,AF,PF,SO1>, LowerMatrix<MT,SO2,DF> >
{
   using Type = AddTrait_< CustomMatrix<T,AF,PF,SO1>, MT >;
};

template< typename MT, bool SO1, bool DF, typename T, bool SO2 >
struct AddTrait< LowerMatrix<MT,SO1,DF>, CompressedMatrix<T,SO2> >
{
   using Type = AddTrait_< MT, CompressedMatrix<T,SO2> >;
};

template< typename T, bool SO1, typename MT, bool SO2, bool DF >
struct AddTrait< CompressedMatrix<T,SO1>, LowerMatrix<MT,SO2,DF> >
{
   using Type = AddTrait_< CompressedMatrix<T,SO1>, MT >;
};

template< typename MT, bool SO1, bool DF, typename T, bool SO2 >
struct AddTrait< LowerMatrix<MT,SO1,DF>, IdentityMatrix<T,SO2> >
{
   using Type = LowerMatrix< AddTrait_< MT, IdentityMatrix<T,SO2> > >;
};

template< typename T, bool SO1, typename MT, bool SO2, bool DF >
struct AddTrait< IdentityMatrix<T,SO1>, LowerMatrix<MT,SO2,DF> >
{
   using Type = LowerMatrix< AddTrait_< IdentityMatrix<T,SO1>, MT > >;
};

template< typename MT1, bool SO1, bool DF1, typename MT2, bool SO2, bool DF2, bool NF >
struct AddTrait< LowerMatrix<MT1,SO1,DF1>, SymmetricMatrix<MT2,SO2,DF2,NF> >
{
   using Type = AddTrait_<MT1,MT2>;
};

template< typename MT1, bool SO1, bool DF1, bool NF, typename MT2, bool SO2, bool DF2 >
struct AddTrait< SymmetricMatrix<MT1,SO1,DF1,NF>, LowerMatrix<MT2,SO2,DF2> >
{
   using Type = AddTrait_<MT1,MT2>;
};

template< typename MT1, bool SO1, bool DF1, typename MT2, bool SO2, bool DF2 >
struct AddTrait< LowerMatrix<MT1,SO1,DF1>, HermitianMatrix<MT2,SO2,DF2> >
{
   using Type = AddTrait_<MT1,MT2>;
};

template< typename MT1, bool SO1, bool DF1, typename MT2, bool SO2, bool DF2 >
struct AddTrait< HermitianMatrix<MT1,SO1,DF1>, LowerMatrix<MT2,SO2,DF2> >
{
   using Type = AddTrait_<MT1,MT2>;
};

template< typename MT1, bool SO1, bool DF1, typename MT2, bool SO2, bool DF2 >
struct AddTrait< LowerMatrix<MT1,SO1,DF1>, LowerMatrix<MT2,SO2,DF2> >
{
   using Type = LowerMatrix< AddTrait_<MT1,MT2> >;
};
/*! \endcond */
//*************************************************************************************************




//=================================================================================================
//
//  SUBTRAIT SPECIALIZATIONS
//
//=================================================================================================

//*************************************************************************************************
/*! \cond BLAZE_INTERNAL */
template< typename MT, bool SO1, bool DF, typename T, size_t M, size_t N, bool SO2 >
struct SubTrait< LowerMatrix<MT,SO1,DF>, StaticMatrix<T,M,N,SO2> >
{
   using Type = SubTrait_< MT, StaticMatrix<T,M,N,SO2> >;
};

template< typename T, size_t M, size_t N, bool SO1, typename MT, bool SO2, bool DF >
struct SubTrait< StaticMatrix<T,M,N,SO1>, LowerMatrix<MT,SO2,DF> >
{
   using Type = SubTrait_< StaticMatrix<T,M,N,SO1>, MT >;
};

template< typename MT, bool SO1, bool DF, typename T, size_t M, size_t N, bool SO2 >
struct SubTrait< LowerMatrix<MT,SO1,DF>, HybridMatrix<T,M,N,SO2> >
{
   using Type = SubTrait_< MT, HybridMatrix<T,M,N,SO2> >;
};

template< typename T, size_t M, size_t N, bool SO1, typename MT, bool SO2, bool DF >
struct SubTrait< HybridMatrix<T,M,N,SO1>, LowerMatrix<MT,SO2,DF> >
{
   using Type = SubTrait_< HybridMatrix<T,M,N,SO1>, MT >;
};

template< typename MT, bool SO1, bool DF, typename T, bool SO2 >
struct SubTrait< LowerMatrix<MT,SO1,DF>, DynamicMatrix<T,SO2> >
{
   using Type = SubTrait_< MT, DynamicMatrix<T,SO2> >;
};

template< typename T, bool SO1, typename MT, bool SO2, bool DF >
struct SubTrait< DynamicMatrix<T,SO1>, LowerMatrix<MT,SO2,DF> >
{
   using Type = SubTrait_< DynamicMatrix<T,SO1>, MT >;
};

template< typename MT, bool SO1, bool DF, typename T, bool AF, bool PF, bool SO2 >
struct SubTrait< LowerMatrix<MT,SO1,DF>, CustomMatrix<T,AF,PF,SO2> >
{
   using Type = SubTrait_< MT, CustomMatrix<T,AF,PF,SO2> >;
};

template< typename T, bool AF, bool PF, bool SO1, typename MT, bool SO2, bool DF >
struct SubTrait< CustomMatrix<T,AF,PF,SO1>, LowerMatrix<MT,SO2,DF> >
{
   using Type = SubTrait_< CustomMatrix<T,AF,PF,SO1>, MT >;
};

template< typename MT, bool SO1, bool DF, typename T, bool SO2 >
struct SubTrait< LowerMatrix<MT,SO1,DF>, CompressedMatrix<T,SO2> >
{
   using Type = SubTrait_< MT, CompressedMatrix<T,SO2> >;
};

template< typename T, bool SO1, typename MT, bool SO2, bool DF >
struct SubTrait< CompressedMatrix<T,SO1>, LowerMatrix<MT,SO2,DF> >
{
   using Type = SubTrait_< CompressedMatrix<T,SO1>, MT >;
};

template< typename MT, bool SO1, bool DF, typename T, bool SO2 >
struct SubTrait< LowerMatrix<MT,SO1,DF>, IdentityMatrix<T,SO2> >
{
   using Type = LowerMatrix< SubTrait_< MT, IdentityMatrix<T,SO2> > >;
};

template< typename T, bool SO1, typename MT, bool SO2, bool DF >
struct SubTrait< IdentityMatrix<T,SO1>, LowerMatrix<MT,SO2,DF> >
{
   using Type = LowerMatrix< SubTrait_< IdentityMatrix<T,SO1>, MT > >;
};

template< typename MT1, bool SO1, bool DF1, typename MT2, bool SO2, bool DF2, bool NF >
struct SubTrait< LowerMatrix<MT1,SO1,DF1>, SymmetricMatrix<MT2,SO2,DF2,NF> >
{
   using Type = SubTrait_<MT1,MT2>;
};

template< typename MT1, bool SO1, bool DF1, bool NF, typename MT2, bool SO2, bool DF2 >
struct SubTrait< SymmetricMatrix<MT1,SO1,DF1,NF>, LowerMatrix<MT2,SO2,DF2> >
{
   using Type = SubTrait_<MT1,MT2>;
};

template< typename MT1, bool SO1, bool DF1, typename MT2, bool SO2, bool DF2 >
struct SubTrait< LowerMatrix<MT1,SO1,DF1>, HermitianMatrix<MT2,SO2,DF2> >
{
   using Type = SubTrait_<MT1,MT2>;
};

template< typename MT1, bool SO1, bool DF1, typename MT2, bool SO2, bool DF2 >
struct SubTrait< HermitianMatrix<MT1,SO1,DF1>, LowerMatrix<MT2,SO2,DF2> >
{
   using Type = SubTrait_<MT1,MT2>;
};

template< typename MT1, bool SO1, bool DF1, typename MT2, bool SO2, bool DF2 >
struct SubTrait< LowerMatrix<MT1,SO1,DF1>, LowerMatrix<MT2,SO2,DF2> >
{
   using Type = LowerMatrix< SubTrait_<MT1,MT2> >;
};
/*! \endcond */
//*************************************************************************************************




//=================================================================================================
//
//  SCHURTRAIT SPECIALIZATIONS
//
//=================================================================================================

//*************************************************************************************************
/*! \cond BLAZE_INTERNAL */
template< typename MT, bool SO1, bool DF, typename T, size_t M, size_t N, bool SO2 >
struct SchurTrait< LowerMatrix<MT,SO1,DF>, StaticMatrix<T,M,N,SO2> >
{
   using Type = LowerMatrix< SchurTrait_< MT, StaticMatrix<T,M,N,SO2> > >;
};

template< typename T, size_t M, size_t N, bool SO1, typename MT, bool SO2, bool DF >
struct SchurTrait< StaticMatrix<T,M,N,SO1>, LowerMatrix<MT,SO2,DF> >
{
   using Type = LowerMatrix< SchurTrait_< StaticMatrix<T,M,N,SO1>, MT > >;
};

template< typename MT, bool SO1, bool DF, typename T, size_t M, size_t N, bool SO2 >
struct SchurTrait< LowerMatrix<MT,SO1,DF>, HybridMatrix<T,M,N,SO2> >
{
   using Type = LowerMatrix< SchurTrait_< MT, HybridMatrix<T,M,N,SO2> > >;
};

template< typename T, size_t M, size_t N, bool SO1, typename MT, bool SO2, bool DF >
struct SchurTrait< HybridMatrix<T,M,N,SO1>, LowerMatrix<MT,SO2,DF> >
{
   using Type = LowerMatrix< SchurTrait_< HybridMatrix<T,M,N,SO1>, MT > >;
};

template< typename MT, bool SO1, bool DF, typename T, bool SO2 >
struct SchurTrait< LowerMatrix<MT,SO1,DF>, DynamicMatrix<T,SO2> >
{
   using Type = LowerMatrix< SchurTrait_< MT, DynamicMatrix<T,SO2> > >;
};

template< typename T, bool SO1, typename MT, bool SO2, bool DF >
struct SchurTrait< DynamicMatrix<T,SO1>, LowerMatrix<MT,SO2,DF> >
{
   using Type = LowerMatrix< SchurTrait_< DynamicMatrix<T,SO1>, MT > >;
};

template< typename MT, bool SO1, bool DF, typename T, bool AF, bool PF, bool SO2 >
struct SchurTrait< LowerMatrix<MT,SO1,DF>, CustomMatrix<T,AF,PF,SO2> >
{
   using Type = LowerMatrix< SchurTrait_< MT, CustomMatrix<T,AF,PF,SO2> > >;
};

template< typename T, bool AF, bool PF, bool SO1, typename MT, bool SO2, bool DF >
struct SchurTrait< CustomMatrix<T,AF,PF,SO1>, LowerMatrix<MT,SO2,DF> >
{
   using Type = LowerMatrix< SchurTrait_< CustomMatrix<T,AF,PF,SO1>, MT > >;
};

template< typename MT, bool SO1, bool DF, typename T, bool SO2 >
struct SchurTrait< LowerMatrix<MT,SO1,DF>, CompressedMatrix<T,SO2> >
{
   using Type = LowerMatrix< SchurTrait_< MT, CompressedMatrix<T,SO2> > >;
};

template< typename T, bool SO1, typename MT, bool SO2, bool DF >
struct SchurTrait< CompressedMatrix<T,SO1>, LowerMatrix<MT,SO2,DF> >
{
   using Type = LowerMatrix< SchurTrait_< CompressedMatrix<T,SO1>, MT > >;
};

template< typename MT, bool SO1, bool DF, typename T, bool SO2 >
struct SchurTrait< LowerMatrix<MT,SO1,DF>, IdentityMatrix<T,SO2> >
{
   using Type = DiagonalMatrix< SchurTrait_< MT, IdentityMatrix<T,SO2> > >;
};

template< typename T, bool SO1, typename MT, bool SO2, bool DF >
struct SchurTrait< IdentityMatrix<T,SO1>, LowerMatrix<MT,SO2,DF> >
{
   using Type = DiagonalMatrix< SchurTrait_< IdentityMatrix<T,SO1>, MT > >;
};

template< typename MT1, bool SO1, bool DF1, typename MT2, bool SO2, bool DF2, bool NF >
struct SchurTrait< LowerMatrix<MT1,SO1,DF1>, SymmetricMatrix<MT2,SO2,DF2,NF> >
{
   using Type = LowerMatrix< SchurTrait_<MT1,MT2> >;
};

template< typename MT1, bool SO1, bool DF1, bool NF, typename MT2, bool SO2, bool DF2 >
struct SchurTrait< SymmetricMatrix<MT1,SO1,DF1,NF>, LowerMatrix<MT2,SO2,DF2> >
{
   using Type = LowerMatrix< SchurTrait_<MT1,MT2> >;
};

template< typename MT1, bool SO1, bool DF1, typename MT2, bool SO2, bool DF2 >
struct SchurTrait< LowerMatrix<MT1,SO1,DF1>, HermitianMatrix<MT2,SO2,DF2> >
{
   using Type = LowerMatrix< SchurTrait_<MT1,MT2> >;
};

template< typename MT1, bool SO1, bool DF1, typename MT2, bool SO2, bool DF2 >
struct SchurTrait< HermitianMatrix<MT1,SO1,DF1>, LowerMatrix<MT2,SO2,DF2> >
{
   using Type = LowerMatrix< SchurTrait_<MT1,MT2> >;
};

template< typename MT1, bool SO1, bool DF1, typename MT2, bool SO2, bool DF2 >
struct SchurTrait< LowerMatrix<MT1,SO1,DF1>, LowerMatrix<MT2,SO2,DF2> >
{
   using Type = LowerMatrix< SchurTrait_<MT1,MT2> >;
};
/*! \endcond */
//*************************************************************************************************




//=================================================================================================
//
//  MULTTRAIT SPECIALIZATIONS
//
//=================================================================================================

//*************************************************************************************************
/*! \cond BLAZE_INTERNAL */
template< typename MT, bool SO, bool DF, typename T >
struct MultTrait< LowerMatrix<MT,SO,DF>, T, EnableIf_< IsNumeric<T> > >
{
   using Type = LowerMatrix< MultTrait_<MT,T> >;
};

template< typename T, typename MT, bool SO, bool DF >
struct MultTrait< T, LowerMatrix<MT,SO,DF>, EnableIf_< IsNumeric<T> > >
{
   using Type = LowerMatrix< MultTrait_<T,MT> >;
};

template< typename MT, bool SO, bool DF, typename T, size_t N >
struct MultTrait< LowerMatrix<MT,SO,DF>, StaticVector<T,N,false> >
{
   using Type = MultTrait_< MT, StaticVector<T,N,false> >;
};

template< typename T, size_t N, typename MT, bool SO, bool DF >
struct MultTrait< StaticVector<T,N,true>, LowerMatrix<MT,SO,DF> >
{
   using Type = MultTrait_< StaticVector<T,N,true>, MT >;
};

template< typename MT, bool SO, bool DF, typename T, size_t N >
struct MultTrait< LowerMatrix<MT,SO,DF>, HybridVector<T,N,false> >
{
   using Type = MultTrait_< MT, HybridVector<T,N,false> >;
};

template< typename T, size_t N, typename MT, bool SO, bool DF >
struct MultTrait< HybridVector<T,N,true>, LowerMatrix<MT,SO,DF> >
{
   using Type = MultTrait_< HybridVector<T,N,true>, MT >;
};

template< typename MT, bool SO, bool DF, typename T >
struct MultTrait< LowerMatrix<MT,SO,DF>, DynamicVector<T,false> >
{
   using Type = MultTrait_< MT, DynamicVector<T,false> >;
};

template< typename T, typename MT, bool SO, bool DF >
struct MultTrait< DynamicVector<T,true>, LowerMatrix<MT,SO,DF> >
{
   using Type = MultTrait_< DynamicVector<T,true>, MT >;
};

template< typename MT, bool SO, bool DF, typename T, bool AF, bool PF >
struct MultTrait< LowerMatrix<MT,SO,DF>, CustomVector<T,AF,PF,false> >
{
   using Type = MultTrait_< MT, CustomVector<T,AF,PF,false> >;
};

template< typename T, bool AF, bool PF, typename MT, bool SO, bool DF >
struct MultTrait< CustomVector<T,AF,PF,true>, LowerMatrix<MT,SO,DF> >
{
   using Type = MultTrait_< CustomVector<T,AF,PF,true>, MT >;
};

template< typename MT, bool SO, bool DF, typename T >
struct MultTrait< LowerMatrix<MT,SO,DF>, CompressedVector<T,false> >
{
   using Type = MultTrait_< MT, CompressedVector<T,false> >;
};

template< typename T, typename MT, bool SO, bool DF >
struct MultTrait< CompressedVector<T,true>, LowerMatrix<MT,SO,DF> >
{
   using Type = MultTrait_< CompressedVector<T,true>, MT >;
};

template< typename MT, bool SO1, bool DF, typename T, size_t M, size_t N, bool SO2 >
struct MultTrait< LowerMatrix<MT,SO1,DF>, StaticMatrix<T,M,N,SO2> >
{
   using Type = MultTrait_< MT, StaticMatrix<T,M,N,SO2> >;
};

template< typename T, size_t M, size_t N, bool SO1, typename MT, bool SO2, bool DF >
struct MultTrait< StaticMatrix<T,M,N,SO1>, LowerMatrix<MT,SO2,DF> >
{
   using Type = MultTrait_< StaticMatrix<T,M,N,SO1>, MT >;
};

template< typename MT, bool SO1, bool DF, typename T, size_t M, size_t N, bool SO2 >
struct MultTrait< LowerMatrix<MT,SO1,DF>, HybridMatrix<T,M,N,SO2> >
{
   using Type = MultTrait_< MT, HybridMatrix<T,M,N,SO2> >;
};

template< typename T, size_t M, size_t N, bool SO1, typename MT, bool SO2, bool DF >
struct MultTrait< HybridMatrix<T,M,N,SO1>, LowerMatrix<MT,SO2,DF> >
{
   using Type = MultTrait_< HybridMatrix<T,M,N,SO1>, MT >;
};

template< typename MT, bool SO1, bool DF, typename T, bool SO2 >
struct MultTrait< LowerMatrix<MT,SO1,DF>, DynamicMatrix<T,SO2> >
{
   using Type = MultTrait_< MT, DynamicMatrix<T,SO2> >;
};

template< typename T, bool SO1, typename MT, bool SO2, bool DF >
struct MultTrait< DynamicMatrix<T,SO1>, LowerMatrix<MT,SO2,DF> >
{
   using Type = MultTrait_< DynamicMatrix<T,SO1>, MT >;
};

template< typename MT, bool SO1, bool DF, typename T, bool AF, bool PF, bool SO2 >
struct MultTrait< LowerMatrix<MT,SO1,DF>, CustomMatrix<T,AF,PF,SO2> >
{
   using Type = MultTrait_< MT, CustomMatrix<T,AF,PF,SO2> >;
};

template< typename T, bool AF, bool PF, bool SO1, typename MT, bool SO2, bool DF >
struct MultTrait< CustomMatrix<T,AF,PF,SO1>, LowerMatrix<MT,SO2,DF> >
{
   using Type = MultTrait_< CustomMatrix<T,AF,PF,SO1>, MT >;
};

template< typename MT, bool SO1, bool DF, typename T, bool SO2 >
struct MultTrait< LowerMatrix<MT,SO1,DF>, CompressedMatrix<T,SO2> >
{
   using Type = MultTrait_< MT, CompressedMatrix<T,SO2> >;
};

template< typename T, bool SO1, typename MT, bool SO2, bool DF >
struct MultTrait< CompressedMatrix<T,SO1>, LowerMatrix<MT,SO2,DF> >
{
   using Type = MultTrait_< CompressedMatrix<T,SO1>, MT >;
};

template< typename MT, bool SO1, bool DF, typename T, bool SO2 >
struct MultTrait< LowerMatrix<MT,SO1,DF>, IdentityMatrix<T,SO2> >
{
   using Type = LowerMatrix< MultTrait_< MT, IdentityMatrix<T,SO2> > >;
};

template< typename T, bool SO1, typename MT, bool SO2, bool DF >
struct MultTrait< IdentityMatrix<T,SO1>, LowerMatrix<MT,SO2,DF> >
{
   using Type = LowerMatrix< MultTrait_< IdentityMatrix<T,SO1>, MT > >;
};

template< typename MT1, bool SO1, bool DF1, typename MT2, bool SO2, bool DF2, bool NF >
struct MultTrait< LowerMatrix<MT1,SO1,DF1>, SymmetricMatrix<MT2,SO2,DF2,NF> >
{
   using Type = MultTrait_<MT1,MT2>;
};

template< typename MT1, bool SO1, bool DF1, bool NF, typename MT2, bool SO2, bool DF2 >
struct MultTrait< SymmetricMatrix<MT1,SO1,DF1,NF>, LowerMatrix<MT2,SO2,DF2> >
{
   using Type = MultTrait_<MT1,MT2>;
};

template< typename MT1, bool SO1, bool DF1, typename MT2, bool SO2, bool DF2 >
struct MultTrait< LowerMatrix<MT1,SO1,DF1>, HermitianMatrix<MT2,SO2,DF2> >
{
   using Type = MultTrait_<MT1,MT2>;
};

template< typename MT1, bool SO1, bool DF1, typename MT2, bool SO2, bool DF2 >
struct MultTrait< HermitianMatrix<MT1,SO1,DF1>, LowerMatrix<MT2,SO2,DF2> >
{
   using Type = MultTrait_<MT1,MT2>;
};

template< typename MT1, bool SO1, bool DF1, typename MT2, bool SO2, bool DF2 >
struct MultTrait< LowerMatrix<MT1,SO1,DF1>, LowerMatrix<MT2,SO2,DF2> >
{
   using Type = LowerMatrix< MultTrait_<MT1,MT2> >;
};
/*! \endcond */
//*************************************************************************************************




//=================================================================================================
//
//  DIVTRAIT SPECIALIZATIONS
//
//=================================================================================================

//*************************************************************************************************
/*! \cond BLAZE_INTERNAL */
template< typename MT, bool SO, bool DF, typename T >
struct DivTrait< LowerMatrix<MT,SO,DF>, T, EnableIf_< IsNumeric<T> > >
{
   using Type = LowerMatrix< DivTrait_<MT,T> >;
};
/*! \endcond */
//*************************************************************************************************




//=================================================================================================
//
//  UNARYMAPTRAIT SPECIALIZATIONS
//
//=================================================================================================

//*************************************************************************************************
/*! \cond BLAZE_INTERNAL */
template< typename MT, bool SO, bool DF >
struct UnaryMapTrait< LowerMatrix<MT,SO,DF>, Abs >
{
   using Type = LowerMatrix< UnaryMapTrait_<MT,Abs> >;
};

template< typename MT, bool SO, bool DF >
struct UnaryMapTrait< LowerMatrix<MT,SO,DF>, Floor >
{
   using Type = LowerMatrix< UnaryMapTrait_<MT,Floor> >;
};

template< typename MT, bool SO, bool DF >
struct UnaryMapTrait< LowerMatrix<MT,SO,DF>, Ceil >
{
   using Type = LowerMatrix< UnaryMapTrait_<MT,Ceil> >;
};

template< typename MT, bool SO, bool DF >
struct UnaryMapTrait< LowerMatrix<MT,SO,DF>, Trunc >
{
   using Type = LowerMatrix< UnaryMapTrait_<MT,Trunc> >;
};

template< typename MT, bool SO, bool DF >
struct UnaryMapTrait< LowerMatrix<MT,SO,DF>, Round >
{
   using Type = LowerMatrix< UnaryMapTrait_<MT,Round> >;
};

template< typename MT, bool SO, bool DF >
struct UnaryMapTrait< LowerMatrix<MT,SO,DF>, Conj >
{
   using Type = LowerMatrix< UnaryMapTrait_<MT,Conj> >;
};

template< typename MT, bool SO, bool DF >
struct UnaryMapTrait< LowerMatrix<MT,SO,DF>, Real >
{
   using Type = LowerMatrix< UnaryMapTrait_<MT,Real> >;
};

template< typename MT, bool SO, bool DF >
struct UnaryMapTrait< LowerMatrix<MT,SO,DF>, Imag >
{
   using Type = LowerMatrix< UnaryMapTrait_<MT,Imag> >;
};

template< typename MT, bool SO, bool DF >
struct UnaryMapTrait< LowerMatrix<MT,SO,DF>, Sqrt >
{
   using Type = LowerMatrix< UnaryMapTrait_<MT,Sqrt> >;
};

template< typename MT, bool SO, bool DF >
struct UnaryMapTrait< LowerMatrix<MT,SO,DF>, Cbrt >
{
   using Type = LowerMatrix< UnaryMapTrait_<MT,Cbrt> >;
};

template< typename MT, bool SO, bool DF >
struct UnaryMapTrait< LowerMatrix<MT,SO,DF>, Sin >
{
   using Type = LowerMatrix< UnaryMapTrait_<MT,Sin> >;
};

template< typename MT, bool SO, bool DF >
struct UnaryMapTrait< LowerMatrix<MT,SO,DF>, Asin >
{
   using Type = LowerMatrix< UnaryMapTrait_<MT,Asin> >;
};

template< typename MT, bool SO, bool DF >
struct UnaryMapTrait< LowerMatrix<MT,SO,DF>, Sinh >
{
   using Type = LowerMatrix< UnaryMapTrait_<MT,Sinh> >;
};

template< typename MT, bool SO, bool DF >
struct UnaryMapTrait< LowerMatrix<MT,SO,DF>, Asinh >
{
   using Type = LowerMatrix< UnaryMapTrait_<MT,Asinh> >;
};

template< typename MT, bool SO, bool DF >
struct UnaryMapTrait< LowerMatrix<MT,SO,DF>, Tan >
{
   using Type = LowerMatrix< UnaryMapTrait_<MT,Tan> >;
};

template< typename MT, bool SO, bool DF >
struct UnaryMapTrait< LowerMatrix<MT,SO,DF>, Atan >
{
   using Type = LowerMatrix< UnaryMapTrait_<MT,Atan> >;
};

template< typename MT, bool SO, bool DF >
struct UnaryMapTrait< LowerMatrix<MT,SO,DF>, Tanh >
{
   using Type = LowerMatrix< UnaryMapTrait_<MT,Tanh> >;
};

template< typename MT, bool SO, bool DF >
struct UnaryMapTrait< LowerMatrix<MT,SO,DF>, Atanh >
{
   using Type = LowerMatrix< UnaryMapTrait_<MT,Atanh> >;
};

template< typename MT, bool SO, bool DF >
struct UnaryMapTrait< LowerMatrix<MT,SO,DF>, Erf >
{
   using Type = LowerMatrix< UnaryMapTrait_<MT,Erf> >;
};
/*! \endcond */
//*************************************************************************************************




//=================================================================================================
//
//  BINARYMAPTRAIT SPECIALIZATIONS
//
//=================================================================================================

//*************************************************************************************************
/*! \cond BLAZE_INTERNAL */
template< typename MT1, bool SO1, bool DF1, typename MT2, bool SO2, bool DF2 >
struct BinaryMapTrait< LowerMatrix<MT1,SO1,DF1>, LowerMatrix<MT2,SO2,DF2>, Min >
{
   using Type = LowerMatrix< BinaryMapTrait_<MT1,MT2,Min> >;
};

template< typename MT1, bool SO1, bool DF1, typename MT2, bool SO2, bool DF2 >
struct BinaryMapTrait< LowerMatrix<MT1,SO1,DF1>, LowerMatrix<MT2,SO2,DF2>, Max >
{
   using Type = LowerMatrix< BinaryMapTrait_<MT1,MT2,Max> >;
};
/*! \endcond */
//*************************************************************************************************




//=================================================================================================
//
//  DECLSYMTRAIT SPECIALIZATIONS
//
//=================================================================================================

//*************************************************************************************************
/*! \cond BLAZE_INTERNAL */
template< typename MT, bool SO, bool DF >
struct DeclSymTrait< LowerMatrix<MT,SO,DF> >
{
   using Type = DiagonalMatrix<MT>;
};
/*! \endcond */
//*************************************************************************************************




//=================================================================================================
//
//  DECLHERMTRAIT SPECIALIZATIONS
//
//=================================================================================================

//*************************************************************************************************
/*! \cond BLAZE_INTERNAL */
template< typename MT, bool SO, bool DF >
struct DeclHermTrait< LowerMatrix<MT,SO,DF> >
{
   using Type = HermitianMatrix<MT>;
};
/*! \endcond */
//*************************************************************************************************




//=================================================================================================
//
//  DECLLOWTRAIT SPECIALIZATIONS
//
//=================================================================================================

//*************************************************************************************************
/*! \cond BLAZE_INTERNAL */
template< typename MT, bool SO, bool DF >
struct DeclLowTrait< LowerMatrix<MT,SO,DF> >
{
   using Type = LowerMatrix<MT,SO,DF>;
};
/*! \endcond */
//*************************************************************************************************




//=================================================================================================
//
//  DECLUPPTRAIT SPECIALIZATIONS
//
//=================================================================================================

//*************************************************************************************************
/*! \cond BLAZE_INTERNAL */
template< typename MT, bool SO, bool DF >
struct DeclUppTrait< LowerMatrix<MT,SO,DF> >
{
   using Type = DiagonalMatrix<MT,SO,DF>;
};
/*! \endcond */
//*************************************************************************************************




//=================================================================================================
//
//  DECLDIAGTRAIT SPECIALIZATIONS
//
//=================================================================================================

//*************************************************************************************************
/*! \cond BLAZE_INTERNAL */
template< typename MT, bool SO, bool DF >
struct DeclDiagTrait< LowerMatrix<MT,SO,DF> >
{
   using Type = DiagonalMatrix<MT,SO,DF>;
};
/*! \endcond */
//*************************************************************************************************




//=================================================================================================
//
//  HIGHTYPE SPECIALIZATIONS
//
//=================================================================================================

//*************************************************************************************************
/*! \cond BLAZE_INTERNAL */
template< typename MT1, bool SO1, bool DF1, typename MT2, bool SO2, bool DF2 >
struct HighType< LowerMatrix<MT1,SO1,DF1>, LowerMatrix<MT2,SO2,DF2> >
{
   using Type = LowerMatrix< typename HighType<MT1,MT2>::Type >;
};
/*! \endcond */
//*************************************************************************************************




//=================================================================================================
//
//  LOWTYPE SPECIALIZATIONS
//
//=================================================================================================

//*************************************************************************************************
/*! \cond BLAZE_INTERNAL */
template< typename MT1, bool SO1, bool DF1, typename MT2, bool SO2, bool DF2 >
struct LowType< LowerMatrix<MT1,SO1,DF1>, LowerMatrix<MT2,SO2,DF2> >
{
   using Type = LowerMatrix< typename LowType<MT1,MT2>::Type >;
};
/*! \endcond */
//*************************************************************************************************




//=================================================================================================
//
//  SUBMATRIXTRAIT SPECIALIZATIONS
//
//=================================================================================================

//*************************************************************************************************
/*! \cond BLAZE_INTERNAL */
template< typename MT, bool SO, bool DF >
struct SubmatrixTrait< LowerMatrix<MT,SO,DF> >
{
   using Type = SubmatrixTrait_<MT>;
};
/*! \endcond */
//*************************************************************************************************




//=================================================================================================
//
//  ROWTRAIT SPECIALIZATIONS
//
//=================================================================================================

//*************************************************************************************************
/*! \cond BLAZE_INTERNAL */
template< typename MT, bool SO, bool DF >
struct RowTrait< LowerMatrix<MT,SO,DF> >
{
   using Type = RowTrait_<MT>;
};
/*! \endcond */
//*************************************************************************************************




//=================================================================================================
//
//  COLUMNTRAIT SPECIALIZATIONS
//
//=================================================================================================

//*************************************************************************************************
/*! \cond BLAZE_INTERNAL */
template< typename MT, bool SO, bool DF >
struct ColumnTrait< LowerMatrix<MT,SO,DF> >
{
   using Type = ColumnTrait_<MT>;
};
/*! \endcond */
//*************************************************************************************************

} // namespace blaze

#endif
