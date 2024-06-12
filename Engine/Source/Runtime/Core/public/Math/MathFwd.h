#pragma once

#ifdef P_BUILD_LIB
    #include "PhanesEnginePCH.h"
#else 
    #include <vector>
#endif

#ifndef MATH_FWD_H
#define MATH_FWD_H

#include "Core/public/Math/Boilerplate.h"

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
    template<RealType T>    struct TMatrix3;
    template<RealType T>    struct TMatrix4;
    template<RealType T>    struct TQuaternion;
    template<RealType T>    struct TTransform;
    template<RealType T>    struct TPoint2;
    template<RealType T>    struct TPoint3;
    template<RealType T>    struct TPoint4;
    template<IntType T>		struct TIntPoint2;
    template<IntType T>		struct TIntPoint3;
    template<IntType T>		struct TIntPoint4;
    template<RealType T>    struct TMatrix2;
    template<RealType T, bool S>    struct TVector2;
    template<RealType T, bool S>    struct TVector3;
    template<RealType T, bool S>	struct TVector4;
    template<IntType T, bool S>		struct TIntVector2;
    template<IntType T, bool S>		struct TIntVector3;
    template<IntType T, bool S>		struct TIntVector4;

    /**
     * Specific instantiation of forward declarations.
     */
    

} // Phanes::Core::Math::coretypes

namespace Phanes::Core::Math::Internal
{

    // Internal types

    template <typename T, unsigned int D> struct AVector;

    template <typename T, unsigned int n, unsigned int> struct AMatrix;
}


#endif // !MATH_FWD_H