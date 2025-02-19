#pragma once

// ============================================= //
//     Function to convert types into each other     //
//												 //
//	 @ref [FILE]MathUnitConversion				 //
// ============================================= //


#include "Core/Math/Boilerplate.h"
#include "Core/Math/MathPCH.h"

#include "Core/Math/MathAbstractTypes.h"
#include "Core/Math/Vector2.hpp"
#include "Core/Math/Vector3.hpp"
#include "Core/Math/Vector4.hpp"
#include "Core/Math/Matrix2.hpp"
#include "Core/Math/Matrix3.hpp"
#include "Core/Math/Matrix4.hpp"
#include "Core/Math/IntVector2.hpp"
#include "Core/Math/IntVector3.hpp"
#include "Core/Math/IntVector4.hpp"

#ifndef MATH_TYPE_CONVERSION_H
#define MATH_TYPE_CONVERSION_H


namespace Phanes::Core::Math {

    // =================================================== //
    //              std::to_string wrapper    			   //
    //												       //
    //   This is, to make using ToString more general	   //
    //   and allow usage of one function instead of two,   //
    //   for converting a mathmatical type to a string.    // 
    // =================================================== //

    FORCEINLINE std::string ToString(long long val)				{ return std::to_string(val); };

    FORCEINLINE std::string ToString(double val)				{ return std::to_string(val); };

    FORCEINLINE std::string ToString(float val)					{ return std::to_string(val); };

    FORCEINLINE std::string ToString(int val)					{ return std::to_string(val); };

    FORCEINLINE std::string ToString(long val)					{ return std::to_string(val); };

    FORCEINLINE std::string ToString(long double val)			{ return std::to_string(val); };

    FORCEINLINE std::string ToString(unsigned long long val)	{ return std::to_string(val); };

    FORCEINLINE std::string ToString(unsigned int val)			{ return std::to_string(val); };

    FORCEINLINE std::string ToString(unsigned long val)			{ return std::to_string(val); }; 


    // ============ //
    //   ToString   //
    // ============ //

    template<RealType T, bool S>
    std::string ToString(const TVector2<T, S>& v)
    {
        return "(" + ToString(v.x) + ", " + ToString(v.y) + ")";
    }

    template<IntType T, bool S>
    std::string ToString(const TIntVector2<T, S>& v)
    {
        return "(" + ToString(v.x) + ", " + ToString(v.y) + ")";
    }

    template<RealType T, bool S>
    std::string ToString(const TVector3<T, S>& v)
    {
        return "(" + ToString(v.x) + ", " + ToString(v.y) + ", " + ToString(v.z) + ")";
    }

    template<IntType T, bool S>
    std::string ToString(const TIntVector3<T, S>& v)
    {
        return "(" + ToString(v.x) + ", " + ToString(v.y) + ", " + ToString(v.z) + ")";
    }

    template<RealType T, bool S>
    std::string ToString(const TVector4<T, S>& v)
    {
        return "(" + ToString(v.x) + ", " + ToString(v.y) + ", " + ToString(v.z) + ", " + ToString(v.w) + ")";
    }

    template<IntType T, bool S>
    std::string ToString(const TIntVector4<T, S>& v)
    {
        return "(" + ToString(v.x) + ", " + ToString(v.y) + ", " + ToString(v.z) + ", " + ToString(v.w) + ")";
    }

    template<RealType T>
    std::string ToString(const TMatrix2<T>& m)
    {
        return "([" + ToString(m(0, 0)) + ", " + ToString(m(0, 1)) + "], [" + 
                      ToString(m(1, 0)) + ", " + ToString(m(1, 1)) + "])";
    }

    template<RealType T, bool S>
    std::string ToString(const TMatrix3<T, S>& m)
    {
        return "([" + ToString(m(0, 0)) + ", " + ToString(m(0, 1)) + ", " + ToString(m(0, 2)) + "], [" + 
                      ToString(m(1, 0)) + ", " + ToString(m(1, 1)) + ", " + ToString(m(1, 2)) + "], [" + 
                      ToString(m(2, 0)) + ", " + ToString(m(2, 1)) + ", " + ToString(m(2, 2)) + "])";
    }


    template<RealType T, bool S>
    std::string ToString(const TMatrix4<T, S>& m)
    {
        return "([" + ToString(m(0, 0)) + ", " + ToString(m(0, 1)) + ", " + ToString(m(0, 2)) + ", " + ToString(m(0, 3)) + "], [" + 
                      ToString(m(1, 0)) + ", " + ToString(m(1, 1)) + ", " + ToString(m(1, 2)) + ", " + ToString(m(1, 3)) + "], [" + 
                      ToString(m(2, 0)) + ", " + ToString(m(2, 1)) + ", " + ToString(m(2, 2)) + ", " + ToString(m(2, 3)) + "], [" +
                      ToString(m(3, 0)) + ", " + ToString(m(3, 1)) + ", " + ToString(m(3, 2)) + ", " + ToString(m(3, 3)) + "])";
    }

}

#endif // !MATH_TYPE_CONVERSION_H