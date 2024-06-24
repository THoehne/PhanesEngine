#pragma once

#ifdef P_BUILD_LIB
    #include "PhanesEnginePCH.h"
#else 
    #include <vector>
#endif

#ifndef MATH_FWD_H
#define MATH_FWD_H

#include "Core/public/Math/Boilerplate.h"
#include "Core/public/Math/SIMD/PhanesSIMDTypes.h"

/**
 * Includes forward declarations, as well as certain useful typedefs.
 * 
 * @ref OSAL/PlatformTypes.h
 */


namespace Phanes::Core::Math {

    /**
     * Template forward declarations.
     */

    template<RealType T>    struct TColor;
    template<RealType T>    struct TLinearColor;
    template<RealType T>    struct TRay;
    template<RealType T>    struct TLine;
    template<RealType T>    struct TPlane;
    template<RealType T>    struct TQuaternion;
    template<RealType T>    struct TTransform;
    template<RealType T>    struct TPoint2;
    template<RealType T>    struct TPoint3;
    template<RealType T>    struct TPoint4;
    template<IntType T>		struct TIntPoint2;
    template<IntType T>		struct TIntPoint3;
    template<IntType T>		struct TIntPoint4;
    template<RealType T>    struct TMatrix2;
    template<RealType T, bool S>    struct TMatrix3;
    template<RealType T, bool S>    struct TMatrix4; 
    template<RealType T, bool S>    struct TVector2;
    template<RealType T, bool S>    struct TVector3;
    template<RealType T, bool S>	struct TVector4;
    template<IntType T, bool S>		struct TIntVector2;
    template<IntType T, bool S>		struct TIntVector3;
    template<IntType T, bool S>		struct TIntVector4;

    /**
     * Specific instantiation of forward declarations.
     */

    // Vector2

    typedef TVector2<float, false>      Vector2;
    typedef TVector2<float, false>      Vector2f;
    typedef TVector2<double, false>     Vector2d;

    typedef TVector2<double, SIMD::use_simd<double, 2, true>::value>        Vector2Regf64;
    typedef TVector2<double, SIMD::use_simd<double, 2, true>::value>        Vector2Reg;
    typedef TVector2<double, SIMD::use_simd<double, 2, true>::value>        Vector2Regd;


    // Vector3

    typedef TVector3<float, false>      Vector3;
    typedef TVector3<float, false>      Vector3f;
    typedef TVector3<double, false>     Vector3d;

    typedef TVector3<float, SIMD::use_simd<float, 3, true>::value>          Vector3Reg;
    typedef TVector3<float, SIMD::use_simd<float, 3, true>::value>          Vector3Regf32;
    typedef TVector3<double, SIMD::use_simd<double, 3, true>::value>        Vector3Regd;
    typedef TVector3<double, SIMD::use_simd<double, 3, true>::value>        Vector3Regf64;


    // Vector4

    typedef TVector4<float, false>      Vector4;
    typedef TVector4<float, false>      Vector4f;
    typedef TVector4<double, false>     Vector4d;

    typedef TVector4<float, SIMD::use_simd<float, 4, true>::value>          Vector4Reg;
    typedef TVector4<float, SIMD::use_simd<float, 4, true>::value>          Vector4Regf32;
    typedef TVector4<double, SIMD::use_simd<double, 4, true>::value>        Vector4Regd;
    typedef TVector4<double, SIMD::use_simd<double, 4, true>::value>        Vector4Regf64;
    

} // Phanes::Core::Math::coretypes

namespace Phanes::Core::Math::Internal
{

    // Internal types

    template <typename T, unsigned int D> struct AVector;

    template <typename T, unsigned int n, unsigned int> struct AMatrix;
}


#endif // !MATH_FWD_H