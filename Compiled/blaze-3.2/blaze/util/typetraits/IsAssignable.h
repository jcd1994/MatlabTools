//=================================================================================================
/*!
//  \file blaze/util/typetraits/IsAssignable.h
//  \brief Header file for the IsAssignable type trait
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

#ifndef _BLAZE_UTIL_TYPETRAITS_ISASSIGNABLE_H_
#define _BLAZE_UTIL_TYPETRAITS_ISASSIGNABLE_H_


//*************************************************************************************************
// Includes
//*************************************************************************************************

#include <type_traits>
#include <blaze/util/IntegralConstant.h>


namespace blaze {

//=================================================================================================
//
//  CLASS ISASSIGNABLE
//
//=================================================================================================

//*************************************************************************************************
/*!\brief Compile time type check.
// \ingroup type_traits
//
// The IsAssignable type trait tests whether the expression

   \code
   std::declval<T>() = std::declval<U>();
   \endcode

// is well formed. If an object of type \a U can be assigned to an object of type \a T in this
// way, the \a value member constant is set to \a true, the nested type definition \a Type is set
// to \a TrueType, and the class derives from \a TrueType. Otherwise \a value is set to \a false,
// \a Type is \a FalseType and the class derives from \a FalseType.
*/
template< typename T, typename U >
struct IsAssignable
   : public BoolConstant< std::is_assignable<T,U>::value >
{};
//*************************************************************************************************




//=================================================================================================
//
//  CLASS ISNOTHROWASSIGNABLE
//
//=================================================================================================

//*************************************************************************************************
/*!\brief Compile time type check.
// \ingroup type_traits
//
// The IsNothrowAssignable type trait tests whether the expression

   \code
   std::declval<T>() = std::declval<U>();
   \endcode

// is well formed and guaranteed to not throw an exception (i.e. noexcept). If an object of type
// \a U can be assigned to an object of type \a T in this way, the \a value member constant is set
// to \a true, the nested type definition \a Type is set to \a TrueType, and the class derives
// from \a TrueType. Otherwise \a value is set to \a false, \a Type is \a FalseType and the class
// derives from \a FalseType.
*/
template< typename T, typename U >
struct IsNothrowAssignable
   : public BoolConstant< std::is_nothrow_assignable<T,U>::value >
{};
//*************************************************************************************************




//=================================================================================================
//
//  CLASS ISCOPYASSIGNABLE
//
//=================================================================================================

//*************************************************************************************************
/*!\brief Compile time type check.
// \ingroup type_traits
//
// The IsCopyAssignable type trait tests whether the expression

   \code
   std::declval<T>() = std::declval<T>();
   \endcode

// is well formed. If an object of type \a T can be copy assigned to another object of type \a T,
// the \a value member constant is set to \a true, the nested type definition \a Type is set to
// \a TrueType, and the class derives from \a TrueType. Otherwise \a value is set to \a false,
// \a Type is \a FalseType and the class derives from \a FalseType.
*/
template< typename T >
struct IsCopyAssignable
   : public BoolConstant< std::is_copy_assignable<T>::value >
{};
//*************************************************************************************************




//=================================================================================================
//
//  CLASS ISNOTHROWCOPYASSIGNABLE
//
//=================================================================================================

//*************************************************************************************************
/*!\brief Compile time type check.
// \ingroup type_traits
//
// The IsNothrowCopyAssignable type trait tests whether the expression

   \code
   std::declval<T>() = std::declval<T>();
   \endcode

// is well formed and guaranteed to not throw an exception (i.e. noexcept). If an object of
// type \a T can be copy assigned to another object of type \a T in this way, the \a value
// member constant is set to \a true, the nested type definition \a Type is set to \a TrueType,
// and the class derives from \a TrueType. Otherwise \a value is set to \a false, \a Type is
// \a FalseType and the class derives from \a FalseType.
*/
template< typename T >
struct IsNothrowCopyAssignable
   : public BoolConstant< std::is_nothrow_copy_assignable<T>::value >
{};
//*************************************************************************************************




//=================================================================================================
//
//  CLASS ISMOVEASSIGNABLE
//
//=================================================================================================

//*************************************************************************************************
/*!\brief Compile time type check.
// \ingroup type_traits
//
// The IsMoveAssignable type trait tests whether the expression

   \code
   std::declval<T>() = std::move( std::declval<T>() );
   \endcode

// is well formed. If an object of type \a T can be move assigned to another object of type \a T,
// the \a value member constant is set to \a true, the nested type definition \a Type is set to
// \a TrueType, and the class derives from \a TrueType. Otherwise \a value is set to \a false,
// \a Type is \a FalseType and the class derives from \a FalseType.
*/
template< typename T >
struct IsMoveAssignable
   : public BoolConstant< std::is_move_assignable<T>::value >
{};
//*************************************************************************************************




//=================================================================================================
//
//  CLASS ISNOTHROWMOVEASSIGNABLE
//
//=================================================================================================

//*************************************************************************************************
/*!\brief Compile time type check.
// \ingroup type_traits
//
// The IsNothrowMoveAssignable type trait tests whether the expression

   \code
   std::declval<T>() = std::move( std::declval<T>() );
   \endcode

// is well formed and guaranteed to not throw an exception (i.e. noexcept). If an object of
// type \a T can be move assigned to another object of type \a T in this way, the \a value
// member constant is set to \a true, the nested type definition \a Type is set to \a TrueType,
// and the class derives from \a TrueType. Otherwise \a value is set to \a false, \a Type is
// \a FalseType and the class derives from \a FalseType.
*/
template< typename T >
struct IsNothrowMoveAssignable
   : public BoolConstant< std::is_nothrow_move_assignable<T>::value >
{};
//*************************************************************************************************

} // namespace blaze

#endif
