//=================================================================================================
/*!
//  \file blaze/math/views/Forward.h
//  \brief Header file for all forward declarations for views
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

#ifndef _BLAZE_MATH_VIEWS_FORWARD_H_
#define _BLAZE_MATH_VIEWS_FORWARD_H_


//*************************************************************************************************
// Includes
//*************************************************************************************************

#include <blaze/math/expressions/Forward.h>
#include <blaze/math/views/column/BaseTemplate.h>
#include <blaze/math/views/row/BaseTemplate.h>
#include <blaze/math/views/submatrix/BaseTemplate.h>
#include <blaze/math/views/subvector/BaseTemplate.h>
#include <blaze/util/Types.h>


namespace blaze {

//=================================================================================================
//
//  ::blaze NAMESPACE FORWARD DECLARATIONS
//
//=================================================================================================

template< bool AF, typename VT, bool TF >
Subvector<VT,AF> subvector( Vector<VT,TF>& vector, size_t index, size_t size );

template< bool AF, typename VT, bool TF >
const Subvector<const VT,AF> subvector( const Vector<VT,TF>& vector, size_t index, size_t size );

template< bool AF, typename VT, bool TF >
Subvector<VT,AF> subvector( Vector<VT,TF>&& vector, size_t index, size_t size );

template< bool AF, typename MT, bool SO >
Submatrix<MT,AF> submatrix( Matrix<MT,SO>& matrix, size_t row, size_t column, size_t m, size_t n );

template< bool AF, typename MT, bool SO >
const Submatrix<const MT,AF> submatrix( const Matrix<MT,SO>& matrix, size_t row, size_t column, size_t m, size_t n );

template< bool AF, typename MT, bool SO >
Submatrix<MT,AF> submatrix( Matrix<MT,SO>&& matrix, size_t row, size_t column, size_t m, size_t n );

template< typename MT, bool SO >
Row<MT> row( Matrix<MT,SO>& matrix, size_t index );

template< typename MT, bool SO >
const Row<const MT> row( const Matrix<MT,SO>& matrix, size_t index );

template< typename MT, bool SO >
Row<MT> row( Matrix<MT,SO>&& matrix, size_t index );

template< typename MT, bool SO >
Column<MT> column( Matrix<MT,SO>& matrix, size_t index );

template< typename MT, bool SO >
const Column<const MT> column( const Matrix<MT,SO>& matrix, size_t index );

template< typename MT, bool SO >
Column<MT> column( Matrix<MT,SO>&& matrix, size_t index );

} // namespace blaze

#endif
