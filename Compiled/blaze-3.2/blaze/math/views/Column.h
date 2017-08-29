//=================================================================================================
/*!
//  \file blaze/math/views/Column.h
//  \brief Header file for all restructuring column functions
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

#ifndef _BLAZE_MATH_VIEWS_COLUMN_H_
#define _BLAZE_MATH_VIEWS_COLUMN_H_


//*************************************************************************************************
// Includes
//*************************************************************************************************

#include <blaze/math/expressions/DeclExpr.h>
#include <blaze/math/expressions/MatEvalExpr.h>
#include <blaze/math/expressions/MatMapExpr.h>
#include <blaze/math/expressions/MatMatAddExpr.h>
#include <blaze/math/expressions/MatMatMapExpr.h>
#include <blaze/math/expressions/MatMatMultExpr.h>
#include <blaze/math/expressions/MatMatSubExpr.h>
#include <blaze/math/expressions/Matrix.h>
#include <blaze/math/expressions/MatScalarDivExpr.h>
#include <blaze/math/expressions/MatScalarMultExpr.h>
#include <blaze/math/expressions/MatSerialExpr.h>
#include <blaze/math/expressions/MatTransExpr.h>
#include <blaze/math/expressions/SchurExpr.h>
#include <blaze/math/expressions/VecTVecMultExpr.h>
#include <blaze/math/shims/IsDefault.h>
#include <blaze/math/traits/AddTrait.h>
#include <blaze/math/traits/ColumnTrait.h>
#include <blaze/math/traits/CrossTrait.h>
#include <blaze/math/traits/DivTrait.h>
#include <blaze/math/traits/MultTrait.h>
#include <blaze/math/traits/SubTrait.h>
#include <blaze/math/traits/SubvectorTrait.h>
#include <blaze/math/typetraits/HasConstDataAccess.h>
#include <blaze/math/typetraits/HasMutableDataAccess.h>
#include <blaze/math/typetraits/IsAligned.h>
#include <blaze/math/typetraits/IsColumnMajorMatrix.h>
#include <blaze/math/typetraits/IsOpposedView.h>
#include <blaze/math/typetraits/IsSymmetric.h>
#include <blaze/math/views/column/BaseTemplate.h>
#include <blaze/math/views/column/Dense.h>
#include <blaze/math/views/column/Sparse.h>
#include <blaze/util/FunctionTrace.h>
#include <blaze/util/IntegralConstant.h>
#include <blaze/util/mpl/And.h>
#include <blaze/util/mpl/Or.h>
#include <blaze/util/TrueType.h>
#include <blaze/util/Types.h>


namespace blaze {

//=================================================================================================
//
//  GLOBAL FUNCTIONS
//
//=================================================================================================

//*************************************************************************************************
/*!\brief Creating a view on a specific column of the given matrix.
// \ingroup views
//
// \param matrix The matrix containing the column.
// \param index The index of the column.
// \return View on the specified column of the matrix.
// \exception std::invalid_argument Invalid column access index.
//
// This function returns an expression representing the specified column of the given matrix.

   \code
   using blaze::columnMajor;

   using DenseMatrix  = blaze::DynamicMatrix<double,columnMajor>;
   using SparseMatrix = blaze::CompressedMatrix<double,columnMajor>;

   DenseMatrix D;
   SparseMatrix S;
   // ... Resizing and initialization

   // Creating a view on the 3rd column of the dense matrix D
   blaze::Column<DenseMatrix> = column( D, 3UL );

   // Creating a view on the 4th column of the sparse matrix S
   blaze::Column<SparseMatrix> = column( S, 4UL );
   \endcode

// In case the column is not properly specified (i.e. if the specified index is greater than or
// equal to the total number of the columns in the given matrix) a \a std::invalid_argument
// exception is thrown.
*/
template< typename MT  // Type of the matrix
        , bool SO >    // Storage order
inline Column<MT> column( Matrix<MT,SO>& matrix, size_t index )
{
   BLAZE_FUNCTION_TRACE;

   return Column<MT>( ~matrix, index );
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Creating a view on a specific column of the given constant matrix.
// \ingroup views
//
// \param matrix The constant matrix containing the column.
// \param index The index of the column.
// \return View on the specified column of the matrix.
// \exception std::invalid_argument Invalid column access index.
//
// This function returns an expression representing the specified column of the given constant
// matrix.

   \code
   using blaze::columnMajor;

   using DenseMatrix  = blaze::DynamicMatrix<double,columnMajor>;
   using SparseMatrix = blaze::CompressedMatrix<double,columnMajor>;

   const DenseMatrix D( ... );
   const SparseMatrix S( ... );

   // Creating a view on the 3rd column of the dense matrix D
   blaze::Column<const DenseMatrix> = column( D, 3UL );

   // Creating a view on the 4th column of the sparse matrix S
   blaze::Column<const SparseMatrix> = column( S, 4UL );
   \endcode

// In case the column is not properly specified (i.e. if the specified index is greater than or
// equal to the total number of the columns in the given matrix) a \a std::invalid_argument
// exception is thrown.
*/
template< typename MT  // Type of the matrix
        , bool SO >    // Storage order
inline const Column<const MT> column( const Matrix<MT,SO>& matrix, size_t index )
{
   BLAZE_FUNCTION_TRACE;

   return Column<const MT>( ~matrix, index );
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Creating a view on a specific column of the given temporary matrix.
// \ingroup views
//
// \param matrix The temporary matrix containing the column.
// \param index The index of the column.
// \return View on the specified column of the matrix.
// \exception std::invalid_argument Invalid column access index.
//
// This function returns an expression representing the specified column of the given temporary
// matrix. In case the column is not properly specified (i.e. if the specified index is greater
// than or equal to the total number of the columns in the given matrix) a \a std::invalid_argument
// exception is thrown.
*/
template< typename MT  // Type of the matrix
        , bool SO >    // Storage order
inline Column<MT> column( Matrix<MT,SO>&& matrix, size_t index )
{
   BLAZE_FUNCTION_TRACE;

   return Column<MT>( ~matrix, index );
}
//*************************************************************************************************




//=================================================================================================
//
//  GLOBAL RESTRUCTURING FUNCTIONS
//
//=================================================================================================

//*************************************************************************************************
/*! \cond BLAZE_INTERNAL */
/*!\brief Creating a view on a specific column of the given matrix/matrix addition.
// \ingroup views
//
// \param matrix The constant matrix/matrix addition.
// \param index The index of the column.
// \return View on the specified column of the addition.
//
// This function returns an expression representing the specified column of the given matrix/matrix
// addition.
*/
template< typename MT >  // Matrix base type of the expression
inline decltype(auto) column( const MatMatAddExpr<MT>& matrix, size_t index )
{
   BLAZE_FUNCTION_TRACE;

   return column( (~matrix).leftOperand(), index ) + column( (~matrix).rightOperand(), index );
}
/*! \endcond */
//*************************************************************************************************


//*************************************************************************************************
/*! \cond BLAZE_INTERNAL */
/*!\brief Creating a view on a specific column of the given matrix/matrix subtraction.
// \ingroup views
//
// \param matrix The constant matrix/matrix subtraction.
// \param index The index of the column.
// \return View on the specified column of the subtraction.
//
// This function returns an expression representing the specified column of the given matrix/matrix
// subtraction.
*/
template< typename MT >  // Matrix base type of the expression
inline decltype(auto) column( const MatMatSubExpr<MT>& matrix, size_t index )
{
   BLAZE_FUNCTION_TRACE;

   return column( (~matrix).leftOperand(), index ) - column( (~matrix).rightOperand(), index );
}
/*! \endcond */
//*************************************************************************************************


//*************************************************************************************************
/*! \cond BLAZE_INTERNAL */
/*!\brief Creating a view on a specific column of the given Schur product.
// \ingroup views
//
// \param matrix The constant Schur product.
// \param index The index of the column.
// \return View on the specified column of the Schur product.
//
// This function returns an expression representing the specified column of the given Schur
// product.
*/
template< typename MT >  // Matrix base type of the expression
inline decltype(auto) column( const SchurExpr<MT>& matrix, size_t index )
{
   BLAZE_FUNCTION_TRACE;

   return column( (~matrix).leftOperand(), index ) * column( (~matrix).rightOperand(), index );
}
/*! \endcond */
//*************************************************************************************************


//*************************************************************************************************
/*! \cond BLAZE_INTERNAL */
/*!\brief Creating a view on a specific column of the given matrix/matrix multiplication.
// \ingroup views
//
// \param matrix The constant matrix/matrix multiplication.
// \param index The index of the column.
// \return View on the specified column of the multiplication.
//
// This function returns an expression representing the specified column of the given matrix/matrix
// multiplication.
*/
template< typename MT >  // Matrix base type of the expression
inline decltype(auto) column( const MatMatMultExpr<MT>& matrix, size_t index )
{
   BLAZE_FUNCTION_TRACE;

   return (~matrix).leftOperand() * column( (~matrix).rightOperand(), index );
}
/*! \endcond */
//*************************************************************************************************


//*************************************************************************************************
/*! \cond BLAZE_INTERNAL */
/*!\brief Creating a view on a specific column of the given outer product.
// \ingroup views
//
// \param matrix The constant outer product.
// \param index The index of the column.
// \return View on the specified column of the outer product.
//
// This function returns an expression representing the specified column of the given outer
// product.
*/
template< typename MT >  // Matrix base type of the expression
inline decltype(auto) column( const VecTVecMultExpr<MT>& matrix, size_t index )
{
   BLAZE_FUNCTION_TRACE;

   return (~matrix).leftOperand() * (~matrix).rightOperand()[index];
}
/*! \endcond */
//*************************************************************************************************


//*************************************************************************************************
/*! \cond BLAZE_INTERNAL */
/*!\brief Creating a view on a specific column of the given matrix/scalar multiplication.
// \ingroup views
//
// \param matrix The constant matrix/scalar multiplication.
// \param index The index of the column.
// \return View on the specified column of the multiplication.
//
// This function returns an expression representing the specified column of the given matrix/scalar
// multiplication.
*/
template< typename MT >  // Matrix base type of the expression
inline decltype(auto) column( const MatScalarMultExpr<MT>& matrix, size_t index )
{
   BLAZE_FUNCTION_TRACE;

   return column( (~matrix).leftOperand(), index ) * (~matrix).rightOperand();
}
/*! \endcond */
//*************************************************************************************************


//*************************************************************************************************
/*! \cond BLAZE_INTERNAL */
/*!\brief Creating a view on a specific column of the given matrix/scalar division.
// \ingroup views
//
// \param matrix The constant matrix/scalar division.
// \param index The index of the column.
// \return View on the specified column of the division.
//
// This function returns an expression representing the specified column of the given matrix/scalar
// division.
*/
template< typename MT >  // Matrix base type of the expression
inline decltype(auto) column( const MatScalarDivExpr<MT>& matrix, size_t index )
{
   BLAZE_FUNCTION_TRACE;

   return column( (~matrix).leftOperand(), index ) / (~matrix).rightOperand();
}
/*! \endcond */
//*************************************************************************************************


//*************************************************************************************************
/*! \cond BLAZE_INTERNAL */
/*!\brief Creating a view on a specific column of the given unary matrix map operation.
// \ingroup views
//
// \param matrix The constant unary matrix map operation.
// \param index The index of the column.
// \return View on the specified column of the unary map operation.
//
// This function returns an expression representing the specified column of the given unary
// matrix map operation.
*/
template< typename MT >  // Matrix base type of the expression
inline decltype(auto) column( const MatMapExpr<MT>& matrix, size_t index )
{
   BLAZE_FUNCTION_TRACE;

   return map( column( (~matrix).operand(), index ), (~matrix).operation() );
}
/*! \endcond */
//*************************************************************************************************


//*************************************************************************************************
/*! \cond BLAZE_INTERNAL */
/*!\brief Creating a view on a specific column of the given binary matrix map operation.
// \ingroup views
//
// \param matrix The constant binary matrix map operation.
// \param index The index of the column.
// \return View on the specified column of the binary map operation.
//
// This function returns an expression representing the specified column of the given binary
// matrix map operation.
*/
template< typename MT >  // Matrix base type of the expression
inline decltype(auto) column( const MatMatMapExpr<MT>& matrix, size_t index )
{
   BLAZE_FUNCTION_TRACE;

   return map( column( (~matrix).leftOperand() , index ),
               column( (~matrix).rightOperand(), index ),
               (~matrix).operation() );
}
/*! \endcond */
//*************************************************************************************************


//*************************************************************************************************
/*! \cond BLAZE_INTERNAL */
/*!\brief Creating a view on a specific column of the given matrix evaluation operation.
// \ingroup views
//
// \param matrix The constant matrix evaluation operation.
// \param index The index of the column.
// \return View on the specified column of the evaluation operation.
//
// This function returns an expression representing the specified column of the given matrix
// evaluation operation.
*/
template< typename MT >  // Matrix base type of the expression
inline decltype(auto) column( const MatEvalExpr<MT>& matrix, size_t index )
{
   BLAZE_FUNCTION_TRACE;

   return eval( column( (~matrix).operand(), index ) );
}
/*! \endcond */
//*************************************************************************************************


//*************************************************************************************************
/*! \cond BLAZE_INTERNAL */
/*!\brief Creating a view on a specific column of the given matrix serialization operation.
// \ingroup views
//
// \param matrix The constant matrix serialization operation.
// \param index The index of the column.
// \return View on the specified column of the serialization operation.
//
// This function returns an expression representing the specified column of the given matrix
// serialization operation.
*/
template< typename MT >  // Matrix base type of the expression
inline decltype(auto) column( const MatSerialExpr<MT>& matrix, size_t index )
{
   BLAZE_FUNCTION_TRACE;

   return serial( column( (~matrix).operand(), index ) );
}
/*! \endcond */
//*************************************************************************************************


//*************************************************************************************************
/*! \cond BLAZE_INTERNAL */
/*!\brief Creating a view on a specific column of the given matrix declaration operation.
// \ingroup views
//
// \param matrix The constant matrix declaration operation.
// \param index The index of the column.
// \return View on the specified column of the declaration operation.
//
// This function returns an expression representing the specified column of the given matrix
// declaration operation.
*/
template< typename MT >  // Matrix base type of the expression
inline decltype(auto) column( const DeclExpr<MT>& matrix, size_t index )
{
   BLAZE_FUNCTION_TRACE;

   return column( (~matrix).operand(), index );
}
/*! \endcond */
//*************************************************************************************************


//*************************************************************************************************
/*! \cond BLAZE_INTERNAL */
/*!\brief Creating a view on a specific column of the given matrix transpose operation.
// \ingroup views
//
// \param matrix The constant matrix transpose operation.
// \param index The index of the column.
// \return View on the specified column of the transpose operation.
//
// This function returns an expression representing the specified column of the given matrix
// transpose operation.
*/
template< typename MT >  // Matrix base type of the expression
inline decltype(auto) column( const MatTransExpr<MT>& matrix, size_t index )
{
   BLAZE_FUNCTION_TRACE;

   return trans( row( (~matrix).operand(), index ) );
}
/*! \endcond */
//*************************************************************************************************




//=================================================================================================
//
//  COLUMN OPERATORS
//
//=================================================================================================

//*************************************************************************************************
/*!\name Column operators */
//@{
template< typename MT, bool SO, bool DF, bool SF >
inline void reset( Column<MT,SO,DF,SF>& column );

template< typename MT, bool SO, bool DF, bool SF >
inline void reset( Column<MT,SO,DF,SF>&& column );

template< typename MT, bool SO, bool DF, bool SF >
inline void clear( Column<MT,SO,DF,SF>& column );

template< typename MT, bool SO, bool DF, bool SF >
inline void clear( Column<MT,SO,DF,SF>&& column );

template< bool RF, typename MT, bool SO, bool DF, bool SF >
inline bool isDefault( const Column<MT,SO,DF,SF>& column );

template< typename MT, bool SO, bool DF, bool SF >
inline bool isIntact( const Column<MT,SO,DF,SF>& column ) noexcept;

template< typename MT, bool SO, bool DF, bool SF >
inline bool isSame( const Column<MT,SO,DF,SF>& a, const Column<MT,SO,DF,SF>& b ) noexcept;
//@}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Resetting the given column.
// \ingroup column
//
// \param column The column to be resetted.
// \return void
*/
template< typename MT  // Type of the matrix
        , bool SO      // Storage order
        , bool DF      // Density flag
        , bool SF >    // Symmetry flag
inline void reset( Column<MT,SO,DF,SF>& column )
{
   column.reset();
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Resetting the given temporary column.
// \ingroup column
//
// \param column The temporary column to be resetted.
// \return void
*/
template< typename MT  // Type of the matrix
        , bool SO      // Storage order
        , bool DF      // Density flag
        , bool SF >    // Symmetry flag
inline void reset( Column<MT,SO,DF,SF>&& column )
{
   column.reset();
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Clearing the given column.
// \ingroup column
//
// \param column The column to be cleared.
// \return void
//
// Clearing a column is equivalent to resetting it via the reset() function.
*/
template< typename MT  // Type of the dense matrix
        , bool SO      // Storage order
        , bool DF      // Density flag
        , bool SF >    // Symmetry flag
inline void clear( Column<MT,SO,DF,SF>& column )
{
   column.reset();
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Clearing the given temporary column.
// \ingroup column
//
// \param column The temporary column to be cleared.
// \return void
//
// Clearing a column is equivalent to resetting it via the reset() function.
*/
template< typename MT  // Type of the dense matrix
        , bool SO      // Storage order
        , bool DF      // Density flag
        , bool SF >    // Symmetry flag
inline void clear( Column<MT,SO,DF,SF>&& column )
{
   column.reset();
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Returns whether the given column is in default state.
// \ingroup column
//
// \param column The column to be tested for its default state.
// \return \a true in case the given column is component-wise zero, \a false otherwise.
//
// This function checks whether the column is in default state. For instance, in case the
// column is instantiated for a built-in integral or floating point data type, the function
// returns \a true in case all column elements are 0 and \a false in case any column element
// is not 0. The following example demonstrates the use of the \a isDefault function:

   \code
   blaze::DynamicMatrix<int,columnMajor> A;
   // ... Resizing and initialization
   if( isDefault( column( A, 0UL ) ) ) { ... }
   \endcode

// Optionally, it is possible to switch between strict semantics (blaze::strict) and relaxed
// semantics (blaze::relaxed):

   \code
   if( isDefault<relaxed>( column( A, 0UL ) ) ) { ... }
   \endcode
*/
template< bool RF      // Relaxation flag
        , typename MT  // Type of the matrix
        , bool SO      // Storage order
        , bool DF      // Density flag
        , bool SF >    // Symmetry flag
inline bool isDefault( const Column<MT,SO,DF,SF>& column )
{
   using blaze::isDefault;

   for( size_t i=0UL; i<column.size(); ++i )
      if( !isDefault<RF>( column[i] ) ) return false;
   return true;
}
//*************************************************************************************************


//*************************************************************************************************
/*! \cond BLAZE_INTERNAL */
/*!\brief Returns whether the given sparse column is in default state.
// \ingroup column
//
// \param column The sparse column to be tested for its default state.
// \return \a true in case the given column is component-wise zero, \a false otherwise.
//
// This function checks whether the sparse column is in default state. For instance, in case
// the column is instantiated for a built-in integral or floating point data type, the function
// returns \a true in case all column elements are 0 and \a false in case any vector element is
// not 0. The following example demonstrates the use of the \a isDefault function:

   \code
   blaze::CompressedMatrix<double,columnMajor> A;
   // ... Resizing and initialization
   if( isDefault( column( A, 0UL ) ) ) { ... }
   \endcode
*/
template< bool RF      // Relaxation flag
        , typename MT  // Type of the sparse matrix
        , bool SO      // Storage order
        , bool SF >    // Symmetry flag
inline bool isDefault( const Column<MT,SO,false,SF>& column )
{
   using blaze::isDefault;

   using ConstIterator = ConstIterator_< Column<MT,SO,false,SF> >;

   const ConstIterator end( column.end() );
   for( ConstIterator element=column.begin(); element!=end; ++element )
      if( !isDefault<RF>( element->value() ) ) return false;
   return true;
}
/*! \endcond */
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Returns whether the invariants of the given column are intact.
// \ingroup column
//
// \param column The column to be tested.
// \return \a true in case the given column's invariants are intact, \a false otherwise.
//
// This function checks whether the invariants of the column are intact, i.e. if its state is
// valid. In case the invariants are intact, the function returns \a true, else it will return
// \a false. The following example demonstrates the use of the \a isIntact() function:

   \code
   blaze::DynamicMatrix<int,columnMajor> A;
   // ... Resizing and initialization
   if( isIntact( column( A, 0UL ) ) ) { ... }
   \endcode
*/
template< typename MT  // Type of the matrix
        , bool SO      // Storage order
        , bool DF      // Density flag
        , bool SF >    // Symmetry flag
inline bool isIntact( const Column<MT,SO,DF,SF>& column ) noexcept
{
   return ( column.column() < column.operand().columns() &&
            isIntact( column.operand() ) );
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Returns whether the two given columns represent the same observable state.
// \ingroup column
//
// \param a The first column to be tested for its state.
// \param b The second column to be tested for its state.
// \return \a true in case the two columns share a state, \a false otherwise.
//
// This overload of the isSame function tests if the two given columns refer to exactly the
// same range of the same matrix. In case both columns represent the same observable state,
// the function returns \a true, otherwise it returns \a false.
*/
template< typename MT  // Type of the matrix
        , bool SO      // Storage order
        , bool DF      // Density flag
        , bool SF >    // Symmetry flag
inline bool isSame( const Column<MT,SO,DF,SF>& a, const Column<MT,SO,DF,SF>& b ) noexcept
{
   return ( isSame( a.operand(), b.operand() ) && ( a.column() == b.column() ) );
}
//*************************************************************************************************


//*************************************************************************************************
/*! \cond BLAZE_INTERNAL */
/*!\brief Predict invariant violations by the assignment of a vector to a column.
// \ingroup column
//
// \param lhs The target left-hand side column.
// \param rhs The right-hand side vector to be assigned.
// \param index The index of the first element to be modified.
// \return \a true in case the assignment would be successful, \a false if not.
//
// This function must \b NOT be called explicitly! It is used internally for the performance
// optimized evaluation of expression templates. Calling this function explicitly might result
// in erroneous results and/or in compilation errors. Instead of using this function use the
// assignment operator.
*/
template< typename MT    // Type of the matrix
        , bool SO        // Storage order
        , bool DF        // Density flag
        , bool SF        // Symmetry flag
        , typename VT >  // Type of the right-hand side vector
inline bool tryAssign( const Column<MT,SO,DF,SF>& lhs, const Vector<VT,false>& rhs, size_t index )
{
   BLAZE_INTERNAL_ASSERT( index <= lhs.size(), "Invalid vector access index" );
   BLAZE_INTERNAL_ASSERT( (~rhs).size() <= lhs.size() - index, "Invalid vector size" );

   return tryAssign( lhs.operand(), ~rhs, index, lhs.column );
}
/*! \endcond */
//*************************************************************************************************


//*************************************************************************************************
/*! \cond BLAZE_INTERNAL */
/*!\brief Predict invariant violations by the addition assignment of a vector to a column.
// \ingroup column
//
// \param lhs The target left-hand side column.
// \param rhs The right-hand side vector to be added.
// \param index The index of the first element to be modified.
// \return \a true in case the assignment would be successful, \a false if not.
//
// This function must \b NOT be called explicitly! It is used internally for the performance
// optimized evaluation of expression templates. Calling this function explicitly might result
// in erroneous results and/or in compilation errors. Instead of using this function use the
// assignment operator.
*/
template< typename MT    // Type of the matrix
        , bool SO        // Storage order
        , bool DF        // Density flag
        , bool SF        // Symmetry flag
        , typename VT >  // Type of the right-hand side vector
inline bool tryAddAssign( const Column<MT,SO,DF,SF>& lhs, const Vector<VT,false>& rhs, size_t index )
{
   BLAZE_INTERNAL_ASSERT( index <= lhs.size(), "Invalid vector access index" );
   BLAZE_INTERNAL_ASSERT( (~rhs).size() <= lhs.size() - index, "Invalid vector size" );

   return tryAddAssign( lhs.operand(), ~rhs, index, lhs.column() );
}
/*! \endcond */
//*************************************************************************************************


//*************************************************************************************************
/*! \cond BLAZE_INTERNAL */
/*!\brief Predict invariant violations by the subtraction assignment of a vector to a column.
// \ingroup column
//
// \param lhs The target left-hand side column.
// \param rhs The right-hand side vector to be subtracted.
// \param index The index of the first element to be modified.
// \return \a true in case the assignment would be successful, \a false if not.
//
// This function must \b NOT be called explicitly! It is used internally for the performance
// optimized evaluation of expression templates. Calling this function explicitly might result
// in erroneous results and/or in compilation errors. Instead of using this function use the
// assignment operator.
*/
template< typename MT    // Type of the matrix
        , bool SO        // Storage order
        , bool DF        // Density flag
        , bool SF        // Symmetry flag
        , typename VT >  // Type of the right-hand side vector
inline bool trySubAssign( const Column<MT,SO,DF,SF>& lhs, const Vector<VT,false>& rhs, size_t index )
{
   BLAZE_INTERNAL_ASSERT( index <= lhs.size(), "Invalid vector access index" );
   BLAZE_INTERNAL_ASSERT( (~rhs).size() <= lhs.size() - index, "Invalid vector size" );

   return trySubAssign( lhs.operand(), ~rhs, index, lhs.column() );
}
/*! \endcond */
//*************************************************************************************************


//*************************************************************************************************
/*! \cond BLAZE_INTERNAL */
/*!\brief Predict invariant violations by the multiplication assignment of a vector to a column.
// \ingroup column
//
// \param lhs The target left-hand side column.
// \param rhs The right-hand side vector to be multiplied.
// \param index The index of the first element to be modified.
// \return \a true in case the assignment would be successful, \a false if not.
//
// This function must \b NOT be called explicitly! It is used internally for the performance
// optimized evaluation of expression templates. Calling this function explicitly might result
// in erroneous results and/or in compilation errors. Instead of using this function use the
// assignment operator.
*/
template< typename MT    // Type of the matrix
        , bool SO        // Storage order
        , bool DF        // Density flag
        , bool SF        // Symmetry flag
        , typename VT >  // Type of the right-hand side vector
inline bool tryMultAssign( const Column<MT,SO,DF,SF>& lhs, const Vector<VT,false>& rhs, size_t index )
{
   BLAZE_INTERNAL_ASSERT( index <= lhs.size(), "Invalid vector access index" );
   BLAZE_INTERNAL_ASSERT( (~rhs).size() <= lhs.size() - index, "Invalid vector size" );

   return tryMultAssign( lhs.operand(), ~rhs, index, lhs.column() );
}
/*! \endcond */
//*************************************************************************************************


//*************************************************************************************************
/*! \cond BLAZE_INTERNAL */
/*!\brief Predict invariant violations by the division assignment of a vector to a column.
// \ingroup column
//
// \param lhs The target left-hand side column.
// \param rhs The right-hand side vector divisor.
// \param index The index of the first element to be modified.
// \return \a true in case the assignment would be successful, \a false if not.
//
// This function must \b NOT be called explicitly! It is used internally for the performance
// optimized evaluation of expression templates. Calling this function explicitly might result
// in erroneous results and/or in compilation errors. Instead of using this function use the
// assignment operator.
*/
template< typename MT    // Type of the matrix
        , bool SO        // Storage order
        , bool DF        // Density flag
        , bool SF        // Symmetry flag
        , typename VT >  // Type of the right-hand side vector
inline bool tryDivAssign( const Column<MT,SO,DF,SF>& lhs, const Vector<VT,false>& rhs, size_t index )
{
   BLAZE_INTERNAL_ASSERT( index <= lhs.size(), "Invalid vector access index" );
   BLAZE_INTERNAL_ASSERT( (~rhs).size() <= lhs.size() - index, "Invalid vector size" );

   return tryDivAssign( lhs.operand(), ~rhs, index, lhs.column() );
}
/*! \endcond */
//*************************************************************************************************


//*************************************************************************************************
/*! \cond BLAZE_INTERNAL */
/*!\brief Removal of all restrictions on the data access to the given column.
// \ingroup column
//
// \param c The column to be derestricted.
// \return Column without access restrictions.
//
// This function removes all restrictions on the data access to the given column. It returns a
// column object that does provide the same interface but does not have any restrictions on the
// data access.\n
// This function must \b NOT be called explicitly! It is used internally for the performance
// optimized evaluation of expression templates. Calling this function explicitly might result
// in the violation of invariants, erroneous results and/or in compilation errors.
*/
template< typename MT  // Type of the matrix
        , bool SO      // Storage order
        , bool DF      // Density flag
        , bool SF >    // Symmetry flag
inline decltype(auto) derestrict( Column<MT,SO,DF,SF>& c )
{
   return column( derestrict( c.operand() ), c.column() );
}
/*! \endcond */
//*************************************************************************************************


//*************************************************************************************************
/*! \cond BLAZE_INTERNAL */
/*!\brief Removal of all restrictions on the data access to the given temporary column.
// \ingroup column
//
// \param c The temporary column to be derestricted.
// \return Column without access restrictions.
//
// This function removes all restrictions on the data access to the given temporary column. It
// returns a column object that does provide the same interface but does not have any restrictions
// on the data access.\n
// This function must \b NOT be called explicitly! It is used internally for the performance
// optimized evaluation of expression templates. Calling this function explicitly might result
// in the violation of invariants, erroneous results and/or in compilation errors.
*/
template< typename MT  // Type of the matrix
        , bool SO      // Storage order
        , bool DF      // Density flag
        , bool SF >    // Symmetry flag
inline decltype(auto) derestrict( Column<MT,SO,DF,SF>&& c )
{
   return column( derestrict( c.operand() ), c.column() );
}
/*! \endcond */
//*************************************************************************************************




//=================================================================================================
//
//  ISRESTRICTED SPECIALIZATIONS
//
//=================================================================================================

//*************************************************************************************************
/*! \cond BLAZE_INTERNAL */
template< typename MT, bool SO, bool DF, bool SF >
struct IsRestricted< Column<MT,SO,DF,SF> >
   : public BoolConstant< IsRestricted<MT>::value >
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
template< typename MT, bool SO, bool SF >
struct HasConstDataAccess< Column<MT,SO,true,SF> >
   : public BoolConstant< HasConstDataAccess<MT>::value >
{};
/*! \endcond */
//*************************************************************************************************




//=================================================================================================
//
//  HASMUTABLEDATAACCESS SPECIALIZATIONS
//
//=================================================================================================

//*************************************************************************************************
/*! \cond BLAZE_INTERNAL */
template< typename MT, bool SO, bool SF >
struct HasMutableDataAccess< Column<MT,SO,true,SF> >
   : public BoolConstant< HasMutableDataAccess<MT>::value >
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
template< typename MT, bool SO, bool SF >
struct IsAligned< Column<MT,SO,true,SF> >
   : public BoolConstant< And< IsAligned<MT>, Or< IsColumnMajorMatrix<MT>, IsSymmetric<MT> > >::value >
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
template< typename MT, bool SO, bool SF >
struct IsPadded< Column<MT,SO,true,SF> >
   : public BoolConstant< And< IsPadded<MT>, Or< IsColumnMajorMatrix<MT>, IsSymmetric<MT> > >::value >
{};
/*! \endcond */
//*************************************************************************************************




//=================================================================================================
//
//  ISOPPOSEDVIEW SPECIALIZATIONS
//
//=================================================================================================

//*************************************************************************************************
/*! \cond BLAZE_INTERNAL */
template< typename MT, bool DF >
struct IsOpposedView< Column<MT,false,DF,false> >
   : public TrueType
{};
/*! \endcond */
//*************************************************************************************************




//=================================================================================================
//
//  ADDTRAIT SPECIALIZATIONS
//
//=================================================================================================

//*************************************************************************************************
/*! \cond BLAZE_INTERNAL */
template< typename MT, bool SO, bool DF, bool SF, typename T >
struct AddTrait< Column<MT,SO,DF,SF>, T >
{
   using Type = AddTrait_< ColumnTrait_<MT>, T >;
};

template< typename T, typename MT, bool SO, bool DF, bool SF >
struct AddTrait< T, Column<MT,SO,DF,SF> >
{
   using Type = AddTrait_< T, ColumnTrait_<MT> >;
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
template< typename MT, bool SO, bool DF, bool SF, typename T >
struct SubTrait< Column<MT,SO,DF,SF>, T >
{
   using Type = SubTrait_< ColumnTrait_<MT>, T >;
};

template< typename T, typename MT, bool SO, bool DF, bool SF >
struct SubTrait< T, Column<MT,SO,DF,SF> >
{
   using Type = SubTrait_< T, ColumnTrait_<MT> >;
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
template< typename MT, bool SO, bool DF, bool SF, typename T >
struct MultTrait< Column<MT,SO,DF,SF>, T >
{
   using Type = MultTrait_< ColumnTrait_<MT>, T >;
};

template< typename T, typename MT, bool SO, bool DF, bool SF >
struct MultTrait< T, Column<MT,SO,DF,SF> >
{
   using Type = MultTrait_< T, ColumnTrait_<MT> >;
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
template< typename MT, bool SO, bool DF, bool SF, typename T >
struct DivTrait< Column<MT,SO,DF,SF>, T >
{
   using Type = DivTrait_< ColumnTrait_<MT>, T >;
};

template< typename T, typename MT, bool SO, bool DF, bool SF >
struct DivTrait< T, Column<MT,SO,DF,SF> >
{
   using Type = DivTrait_< T, ColumnTrait_<MT> >;
};
/*! \endcond */
//*************************************************************************************************




//=================================================================================================
//
//  CROSSTRAIT SPECIALIZATIONS
//
//=================================================================================================

//*************************************************************************************************
/*! \cond BLAZE_INTERNAL */
template< typename MT, bool SO, bool DF, bool SF, typename T >
struct CrossTrait< Column<MT,SO,DF,SF>, T >
{
   using Type = CrossTrait_< ColumnTrait_<MT>, T >;
};

template< typename T, typename MT, bool SO, bool DF, bool SF >
struct CrossTrait< T, Column<MT,SO,DF,SF> >
{
   using Type = CrossTrait_< T, ColumnTrait_<MT> >;
};
/*! \endcond */
//*************************************************************************************************




//=================================================================================================
//
//  SUBVECTORTRAIT SPECIALIZATIONS
//
//=================================================================================================

//*************************************************************************************************
/*! \cond BLAZE_INTERNAL */
template< typename MT, bool SO, bool DF, bool SF >
struct SubvectorTrait< Column<MT,SO,DF,SF> >
{
   using Type = SubvectorTrait_< ResultType_< Column<MT,SO,DF,SF> > >;
};
/*! \endcond */
//*************************************************************************************************

} // namespace blaze

#endif
