//=================================================================================================
/*!
//  \file blaze/math/typetraits/IsSubmatrix.h
//  \brief Header file for the IsSubmatrix type trait
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

#ifndef _BLAZE_MATH_TYPETRAITS_ISSUBMATRIX_H_
#define _BLAZE_MATH_TYPETRAITS_ISSUBMATRIX_H_


//*************************************************************************************************
// Includes
//*************************************************************************************************

#include <blaze/math/views/Forward.h>
#include <blaze/util/FalseType.h>
#include <blaze/util/TrueType.h>


namespace blaze {

//=================================================================================================
//
//  CLASS DEFINITION
//
//=================================================================================================

//*************************************************************************************************
/*!\brief Compile time check for submatrices.
// \ingroup math_type_traits
//
// This type trait tests whether or not the given template parameter is a submatrix (i.e. dense
// or sparse submatrix). In case the type is a submatrix, the \a value member constant is set
// to \a true, the nested type definition \a Type is \a TrueType, and the class derives from
// \a TrueType. Otherwise \a value is set to \a false, \a Type is \a FalseType, and the class
// derives from \a FalseType.

   \code
   using DenseMatrixType1    = blaze::DynamicMatrix<double,columnMajor>;
   using DenseSubmatrixType1 = blaze::Submatrix<DenseMatrixType1>;

   using DenseMatrixType2    = blaze::StaticMatrix<float,3UL,4UL,rowMajor>;
   using DenseSubmatrixType2 = blaze::Submatrix<DenseMatrixType2>;

   using SparseMatrixType    = blaze::CompressedMatrix<int,columnMajor>;
   using SparseSubmatrixType = blaze::Submatrix<SparseMatrixType>;

   blaze::IsSubmatrix< SparseSubmatrixType >::value       // Evaluates to 1
   blaze::IsSubmatrix< const DenseSubmatrixType1 >::Type  // Results in TrueType
   blaze::IsSubmatrix< volatile DenseSubmatrixType2 >     // Is derived from TrueType
   blaze::IsSubmatrix< DenseMatrixType1 >::value          // Evaluates to 0
   blaze::IsSubmatrix< const SparseMatrixType >::Type     // Results in FalseType
   blaze::IsSubmatrix< volatile long double >             // Is derived from FalseType
   \endcode
*/
template< typename T >
struct IsSubmatrix
   : public FalseType
{};
//*************************************************************************************************


//*************************************************************************************************
/*! \cond BLAZE_INTERNAL */
/*!\brief Specialization of the IsSubmatrix type trait for 'Submatrix'.
// \ingroup math_type_traits
*/
template< typename MT, bool AF, bool SO, bool DF >
struct IsSubmatrix< Submatrix<MT,AF,SO,DF> >
   : public TrueType
{};
/*! \endcond */
//*************************************************************************************************


//*************************************************************************************************
/*! \cond BLAZE_INTERNAL */
/*!\brief Specialization of the IsSubmatrix type trait for 'const Submatrix'.
// \ingroup math_type_traits
*/
template< typename MT, bool AF, bool SO, bool DF >
struct IsSubmatrix< const Submatrix<MT,AF,SO,DF> >
   : public TrueType
{};
/*! \endcond */
//*************************************************************************************************


//*************************************************************************************************
/*! \cond BLAZE_INTERNAL */
/*!\brief Specialization of the IsSubmatrix type trait for 'volatile Submatrix'.
// \ingroup math_type_traits
*/
template< typename MT, bool AF, bool SO, bool DF >
struct IsSubmatrix< volatile Submatrix<MT,AF,SO,DF> >
   : public TrueType
{};
/*! \endcond */
//*************************************************************************************************


//*************************************************************************************************
/*! \cond BLAZE_INTERNAL */
/*!\brief Specialization of the IsSubmatrix type trait for 'const volatile Submatrix'.
// \ingroup math_type_traits
*/
template< typename MT, bool AF, bool SO, bool DF >
struct IsSubmatrix< const volatile Submatrix<MT,AF,SO,DF> >
   : public TrueType
{};
/*! \endcond */
//*************************************************************************************************

} // namespace blaze

#endif
