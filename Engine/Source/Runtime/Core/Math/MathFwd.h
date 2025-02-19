#pragma once

#ifdef P_BUILD_LIB
    #include "PhanesEnginePCH.h"
#else 
    #include <vector>
#endif

#ifndef MATH_FWD_H
#define MATH_FWD_H

#include "Core/Math/Boilerplate.h"
#include "Core/Math/SIMD/PhanesSIMDTypes.h"

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
    template<RealType T>    struct TLine;
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
    template<RealType T, bool S>    struct TPlane;
    template<RealType T, bool S>    struct TRay;

    /**
     * Specific instantiation of forward declarations.
     */

    // TPoint2

    typedef TPoint2<float>      Point2;
    typedef TPoint2<float>      Point2f;
    typedef TPoint2<double>     Point2d;

    // TPoint3

    typedef TPoint3<float>      Point3;
    typedef TPoint3<float>      Point3f;
    typedef TPoint3<double>     Point3d;

    // TPoint4

    typedef TPoint4<float>      Point4;
    typedef TPoint4<float>      Point4f;
    typedef TPoint4<double>     Point4d;


    // TIntPoint2

    typedef TIntPoint2<int>      IntPoint2;
    typedef TIntPoint2<int>      IntPoint2i;
    typedef TIntPoint2<long>     IntPoint2l;

    // TIntPoint3

    typedef TIntPoint3<int>      IntPoint3;
    typedef TIntPoint3<int>      IntPoint3i;
    typedef TIntPoint3<long>     IntPoint3l;

    // TIntPoint4

    typedef TIntPoint4<int>      IntPoint4;
    typedef TIntPoint4<int>      IntPoint4i;
    typedef TIntPoint4<long>     IntPoint4l;

    // IntVetor2

    typedef TIntVector2<int, false>     IntVector2;
    typedef TIntVector2<int, false>     Vector2i;
    typedef TIntVector2<long, false>    LongVector2;
    typedef TIntVector2<long, false>    Vector2l;

    // IntVetor3

    typedef TIntVector3<int, false>     IntVector3;
    typedef TIntVector3<int, false>     Vector3i;
    typedef TIntVector3<long, false>    LongVector3;
    typedef TIntVector3<long, false>    Vector3l;


    // IntVetor4

    typedef TIntVector4<int, false>     IntVector4;
    typedef TIntVector4<int, false>     Vector4i;
    typedef TIntVector4<long, false>    LongVector4;
    typedef TIntVector4<long, false>    Vector4l;

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
    
    // Matrix2 
    
    typedef TMatrix2<float>             Matrix2;
    typedef TMatrix2<float>             Matrix2f;
    typedef TMatrix2<double>            Matrix2d;

    // Matrix3 

    typedef TMatrix3<float, false>      Matrix3;
    typedef TMatrix3<float, false>      Matrix3f;
    typedef TMatrix3<double, false>     Matrix3d;

    typedef TMatrix3<float, SIMD::use_simd<float, 3, true>::value>      Matrix3Reg;
    typedef TMatrix3<float, SIMD::use_simd<float, 3, true>::value>      Matrix3Regf;
    typedef TMatrix3<double, SIMD::use_simd<double, 3, true>::value>    Matrix3Regd;
    typedef TMatrix3<double, SIMD::use_simd<double, 3, true>::value>   Matrix3Regf64;

    // Matrix4 

    typedef TMatrix4<float, false>             Matrix4;
    typedef TMatrix4<float, false>             Matrix4f;
    typedef TMatrix4<double, false>            Matrix4d;

    typedef TMatrix3<float, SIMD::use_simd<float, 4, true>::value>      Matrix4Reg;
    typedef TMatrix3<float, SIMD::use_simd<float, 4, true>::value>      Matrix4Regf;
    typedef TMatrix3<double, SIMD::use_simd<double, 4, true>::value>    Matrix4Regd;
    typedef TMatrix3<double, SIMD::use_simd<double, 4, true>::value>   Matrix4Regf64;



    // TPlane 

    typedef TPlane<float, false>        Plane;
    typedef TPlane<float, false>        Planef;
    typedef TPlane<double, false>       Planed;

    typedef TPlane<float, SIMD::use_simd<float, 4, true>::value>    PlaneReg;
    typedef TPlane<float, SIMD::use_simd<double, 4, true>::value>   PlaneRegd;


} // Phanes::Core::Math::coretypes

namespace Phanes::Core::Math::Internal
{

    // Internal types

    template <typename T, unsigned int D> struct AVector;

    template <typename T, unsigned int n, unsigned int> struct AMatrix;
}


#endif // !MATH_FWD_H