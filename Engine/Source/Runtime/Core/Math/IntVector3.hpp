#pragma once

#include "Core/Math/Boilerplate.h"

#include "Core/Math/MathCommon.hpp"
#include "Core/Math/MathFwd.h"

#include "Core/Math/SIMD/Storage.h"

#include "Core/Math/IntVector4.hpp"

#ifndef P_DEBUG
#pragma warning(disable : 4244)
#endif


#ifndef INTVECTOR3_H
#define INTVECTOR3_H

#define PIntZeroVector3(type)			TIntVector3<##type>(0,0,0)
#define PIntVectorForward3(type)		TIntVector3<##type>(1,0,0)
#define PIntVectorBackward3(type)		TIntVector3<##type>(-1,0,0)
#define PIntVectorEast3(type)			TIntVector3<##type>(0,1,0)
#define PIntVectorWest3(type)			TIntVector3<##type>(0,-1,0)
#define PIntVectorUp3(type)				TIntVector3<##type>(0,0,1)
#define PIntVectorDown3(type)			TIntVector3<##type>(0,0,-1)

namespace Phanes::Core::Math {

    /**
     * A 3D Vector with components x, y and z with integer precision.
     */

    template<IntType T, bool A>
    struct TIntVector3 : public TIntVector4<T, A> {

    public:


        /**
         * Default constructor without initialization
         */

        TIntVector3() = default;

        /**
         * Copy constructor
         */

        TIntVector3(const TIntVector3<T, A>& v);

        /**
         * Construct Vector from xyz components.
         *
         * @param(x) X component
         * @param(y) Y component
         * @param(z) Z component
         */

        TIntVector3(const T x, const T y, const T z);

        /// <summary>
        /// Broadcast s into all components.
        /// </summary>
        /// <param name="s"></param>
        TIntVector3(const T s);

        /**
         * Construct Vector from two component array.
         *
         * @param(comp) Array of components
         */

        TIntVector3(const T* comp);
    
        TIntVector3(const TIntVector2<T, A>& v1, const T s);

    };


    // ======================== //
    //   IntVector3 operators   //
    // ======================== //


    /**
     * Coponentwise addition of scalar to 3D vector
     *
     * @param(v1) vector to add to
     * @param(s) scalar to add
     */

    template<IntType T, bool A>
    inline TIntVector3<T, A>& operator+= (TIntVector3<T, A>& v1, T s);

    /**
     * Coponentwise addition of 3D vector to 3D vector
     *
     * @param(v1) vector to add to
     * @param(v2) vector to add
     */

    template<IntType T, bool A>
    inline TIntVector3<T, A>& operator+= (TIntVector3<T, A>& v1, const TIntVector3<T, A>& v2);

    /**
     * Coponentwise substraction of scalar of 3D vector
     *
     * @param(v1) vector to substract from
     * @param(s) scalar to substract
     */

    template<IntType T, bool A>
    inline TIntVector3<T, A>& operator-= (TIntVector3<T, A>& v1, T s);

    /**
     * Coponentwise substraction of 3D vector to 3D vector
     *
     * @param(v1) vector to substract from
     * @param(v2) vector to substract with
     */

    template<IntType T, bool A>
    inline TIntVector3<T, A>& operator-= (TIntVector3<T, A>& v1, const TIntVector3<T, A>& v2);

    /**
     * Dot product between two 3D Vectors
     *
     * @param(v1) vector one
     * @param(s) scalar
     */

    template<IntType T, bool A>
    inline TIntVector3<T, A>& operator*= (TIntVector3<T, A>& v1, T s);

    /**
     * Division of vector by scalar
     *
     * @param(v1) vector one
     * @param(s) scalar
     */

    template<IntType T, bool A>
    inline TIntVector3<T, A>& operator/= (TIntVector3<T, A>& v1, T s);


    template<IntType T, bool A>
    TIntVector2<T, A>& operator%= (TIntVector2<T, A>& v1, const TIntVector2<T, A>& v2);

    template<IntType T, bool A>
    TIntVector2<T, A>& operator%= (TIntVector2<T, A>& v1, T s);

    template<IntType T, bool A>
    inline TIntVector2<T, A>& operator&= (TIntVector2<T, A>& v1, const TIntVector2<T, A>& v2);

    template<IntType T, bool A>
    inline TIntVector2<T, A>& operator&= (TIntVector2<T, A>& v1, T s);

    template<IntType T, bool A>
    inline TIntVector2<T, A>& operator|= (TIntVector2<T, A>& v1, const TIntVector2<T, A>& v2);

    template<IntType T, bool A>
    inline TIntVector2<T, A>& operator|= (TIntVector2<T, A>& v1, T s);

    template<IntType T, bool A>
    inline TIntVector2<T, A>& operator^= (TIntVector2<T, A>& v1, const TIntVector2<T, A>& v2);

    template<IntType T, bool A>
    inline TIntVector2<T, A>& operator^= (TIntVector2<T, A>& v1, T s);

    template<IntType T, bool A>
    inline TIntVector2<T, A>& operator<<= (TIntVector2<T, A>& v1, const TIntVector2<T, A>& v2);

    template<IntType T, bool A>
    inline TIntVector2<T, A>& operator<<= (TIntVector2<T, A>& v1, T s);

    template<IntType T, bool A>
    inline TIntVector2<T, A>& operator>>= (TIntVector2<T, A>& v1, const TIntVector2<T, A>& v2);

    template<IntType T, bool A>
    inline TIntVector2<T, A>& operator>>= (TIntVector2<T, A>& v1, T s);

    /**
     * Coponentwise multiplication of 3D Vectors with scalar
     *
     * @param(v1) vector one
     * @param(s) scalar
     *
     * @return Resulting vector
     */

    template<IntType T, bool A>
    TIntVector3<T, A> operator* (const TIntVector3<T, A>& v1, T s);

    /**
     * Coponentwise multiplication of 3D Vectors with scalar
     *
     * @param(s) scalar
     * @param(v2) vector
     *
     * @return Solution vector
     */

    template<IntType T, bool A>
    FORCEINLINE TIntVector3<T, A> operator* (T s, const TIntVector3<T, A>& v1) { return v1 / s;  };
   
    /**
     * Division by scalar
     *
     * @param(s) scalar
     * @param(v2) vector
     *
     * @return Solution vector
     */

    template<IntType T, bool A>
    inline TIntVector3<T, A> operator/ (const TIntVector3<T, A>& v1, T s);

    template<IntType T, bool A>
    FORCEINLINE TIntVector3<T, A> operator/ (T s, const TIntVector3<T, A>& v1) { return v1 / s;  };


    template<IntType T, bool A>
    inline TIntVector2<T, A> operator% (const TIntVector2<T, A>& v1, const TIntVector2<T, A>& v2);

    template<IntType T, bool A>
    inline TIntVector2<T, A> operator% (const TIntVector2<T, A>& v1, T s);

    template<IntType T, bool A>
    inline TIntVector2<T, A> operator& (TIntVector2<T, A>& v1, const TIntVector2<T, A>& v2);

    template<IntType T, bool A>
    inline TIntVector2<T, A> operator& (TIntVector2<T, A>& v1, T s);

    template<IntType T, bool A>
    inline TIntVector2<T, A> operator| (TIntVector2<T, A>& v1, const TIntVector2<T, A>& v2);

    template<IntType T, bool A>
    inline TIntVector2<T, A> operator| (TIntVector2<T, A>& v1, T s);

    template<IntType T, bool A>
    inline TIntVector2<T, A> operator^ (TIntVector2<T, A>& v1, const TIntVector2<T, A>& v2);

    template<IntType T, bool A>
    inline TIntVector2<T, A> operator^ (TIntVector2<T, A>& v1, T s);

    template<IntType T, bool A>
    inline TIntVector2<T, A> operator<< (TIntVector2<T, A>& v1, const TIntVector2<T, A>& v2);

    template<IntType T, bool A>
    inline TIntVector2<T, A> operator<< (TIntVector2<T, A>& v1, T s);

    template<IntType T, bool A>
    inline TIntVector2<T, A> operator>> (TIntVector2<T, A>& v1, const TIntVector2<T, A>& v2);

    template<IntType T, bool A>
    inline TIntVector2<T, A> operator>> (TIntVector2<T, A>& v1, T s);

    template<IntType T, bool A>
    inline TIntVector2<T, A> operator~ (TIntVector2<T, A>& v1);

    /**
     * Dot product between two 3D Vectors
     *
     * @param(v1) vector one
     * @param(v2) vector two
     *
     * @return Dot product of Vectors
     */

    template<IntType T, bool A>
    TIntVector3<T, A> operator* (const TIntVector3<T, A>& v1, const TIntVector3<T, A>& v2);

    /**
     * Coponentwise addition of scalar to 3D vector
     *
     * @param(v1) vector to add to
     * @param(s) scalar to add
     *
     * @return Resulting vector
     */

    template<IntType T, bool A>
    TIntVector3<T, A> operator+ (const TIntVector3<T, A>& v1, T s);

    /**
     * Coponentwise addition of 3D vector to 3D vector
     *
     * @param(v1) vector to add to
     * @param(v2) vector to add
     *
     * @return Resulting vector
     */

    template<IntType T, bool A>
    TIntVector3<T, A> operator+ (const TIntVector3<T, A>& v1, const TIntVector3<T, A>& v2);

    /**
     * Coponentwise substraction of scalar of 3D vector
     *
     * @param(v1) vector to substract from
     * @param(s) scalar to substract
     *
     * @return Resulting vector
     */

    template<IntType T, bool A>
    TIntVector3<T, A> operator- (const TIntVector3<T, A>& v1, T s);

    /**
     * Coponentwise substraction of scalar of 3D vector
     *
     * @param(v1) vector to substract from
     * @param(v2) vector to substract with
     *
     * @return Resulting vector
     */

    template<IntType T, bool A>
    TIntVector3<T, A> operator- (const TIntVector3<T, A>& v1, const TIntVector3<T, A>& v2);

    /**
     * Tests two 3D vectors for equality.
     *
     * @ref [FUNC]Equals
     *
     * @param(v1) Vector one
     * @param(v2) Vector two
     *
     * @return True if equal, false if not.
     *
     * @note Uses [MACRO]P_FLT_INAC
     */

    template<IntType T, bool A>
    inline bool operator== (const TIntVector3<T, A>& v1, const TIntVector3<T, A>& v2);

    /**
     * Tests two 3D vectors for inequality.
     *
     * @param(v1) Vector one
     * @param(v2) Vector two
     *
     * @return True if inequal, false if not.
     */

    template<IntType T, bool A>
    inline bool operator!= (const TIntVector3<T, A>& v1, const TIntVector3<T, A>& v2);


    // ============================================== //
    //   IntVector3 static function implementation	  //
    // ============================================== //


    /**
     * Dot product of two vectors
     *
     * @param(v1) Vector one
     * @param(v2) Vector two
     *
     * @return Dot product of vectors
     */

    template<IntType T>
    T DotP(const TIntVector3<T, false>& v1, const TIntVector3<T, false>& v2)
    {
        return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
    }

    /**
     * Tests two vectors for equality.
     *
     * @param(v1) Vector one
     * @param(v2) Vector two
     * @param(threshold) Allowed T inaccuracy.
     *
     * @return True if equal, false if not.
     */

    template<IntType T>
    inline bool Equals(const TIntVector3<T, false>& v1, const TIntVector3<T, false>& v2, T threshold = P_FLT_INAC)
    {
        return (abs(v1.x - v2.x) < threshold && abs(v1.y - v2.y) < threshold && abs(v1.z - v2.z) < threshold);
    }

    /**
     * Calculates the cross product between two vectors.
     *
     * @param(v1) Vector one
     * @param(v2) Vector two
     *
     * @note result is stored in v1.
     */

    template<IntType T>
    TIntVector3<T, false>& CrossPV(TIntVector3<T, false>& v1, const TIntVector3<T, false>& v2)
    {
        T x = v1.x;
        T y = v1.y;
        T z = v1.z;

        v1.x = (y * v2.z) - (z * v2.y);
        v1.y = (z * v2.x) - (x * v2.z);
        v1.z = (x * v2.y) - (y * v2.x);

        return v1;
    }

    /**
     * Gets the componentwise max of both vectors.
     *
     * @param(v1) Vector one
     * @param(v2) Vector two
     *
     * @note result is stored in v1.
     */

    template<IntType T>
    TIntVector3<T, false>& MaxV(TIntVector3<T, false>& v1, const TIntVector3<T, false>& v2)
    {
        v1.x = Phanes::Core::Math::Max(v1.x, v2.x);
        v1.y = Phanes::Core::Math::Max(v1.y, v2.y);
        v1.z = Phanes::Core::Math::Max(v1.z, v2.z);

        return v1;
    }

    /**
     * Gets the componentwise min of both vectors.
     *
     * @param(v1) Vector one
     * @param(v2) Vector two
     *
     * @note result is stored in v1.
     */

    template<IntType T>
    TIntVector3<T, false>& MinV(TIntVector3<T, false>& v1, const TIntVector3<T, false>& v2)
    {
        v1.x = Phanes::Core::Math::Min(v1.x, v2.x);
        v1.y = Phanes::Core::Math::Min(v1.y, v2.y);
        v1.z = Phanes::Core::Math::Min(v1.z, v2.z);

        return v1;
    }

    /**
     * Gets reversed vector.
     *
     * @param(v1) Vector one
     *
     * @note result is stored in v1.
     */

    template<IntType T>
    TIntVector3<T, false>& NegateV(TIntVector3<T, false>& v1)
    {
        v1.x = -v1.x;
        v1.y = -v1.y;
        v1.z = -v1.z;

        return v1;
    }

    /**
     * Copies v1 vector
     *
     * @param(v1) Vector to copy to
     * @param(v2) Vector to copy
     */

    template<IntType T>
    TIntVector3<T, false>& Set(TIntVector3<T, false>& v1, const TIntVector3<T, false>& v2)
    {
        v1 = v2;

        return v1;
    }

    /**
     * Sets vector.
     *
     * @param(v1) Vector to copy to
     * @param(x) X component
     * @param(y) Y component
     * @param(z) Z component
     */

    template<IntType T>
    TIntVector3<T, false>& Set(TIntVector3<T, false>& v1, T x, T y, T z)
    {
        v1.x = x;
        v1.y = y;
        v1.z = z;

        return v1;
    }

    /**
     * Returns signs of components in vector: -1 / +1 / 0.
     *
     * @param(v1) Vector one
     */

    template<IntType T>
    TIntVector3<T, false>& SignVectorV(TIntVector3<T, false>& v1)
    {
        v1.x = (v1.x >= 0) ? 1 : -1;
        v1.y = (v1.y >= 0) ? 1 : -1;
        v1.z = (v1.z >= 0) ? 1 : -1;

        return v1;
    }


    /**
     * Gets scalar triple product ((v1 x v2) * v3). (Volume of parallelepiped.)
     *
     * @param(v1) Vector one
     * @param(v2) Vector two
     * @param(v3) Vector three
     *
     * @return Vector triple product
     */

    template<IntType T>
    T ScalarTriple(const TIntVector3<T, false>& v1, const TIntVector3<T, false>& v2, const TIntVector3<T, false>& v3)
    {
        return DotP(CrossP(v1, v2), v3);
    }

    /**
     * Gets vector triple product ((v1 x v2) x v3).
     *
     * @param(v1) Vector one
     * @param(v2) Vector two
     * @param(v3) Vector three
     *
     * @note result is stored in v1
     */

    template<IntType T>
    TIntVector3<T, false>& VectorTripleV(TIntVector3<T, false>& v1, const TIntVector3<T, false>& v2, const TIntVector3<T, false>& v3)
    {
        CrossPV(CrossPV(v1, v2), v3);

        return v1;
    }

    template<IntType T>
    TIntVector3<T, false>& GetPerpendicular(TIntVector3<T, false>& v1)
    {
        T y = v1.y;
        v1.x = 0;
        v1.y = v1.z;
        v1.z = -y;

        return v1;
    }

    /**
     * Tests whether two vectors are perpendicular.
     *
     * @param(v1) Vector one
     * @param(v2) Vector two
     *
     * @return True if perpendicular, false if not.
     */

    template<IntType T>
    inline bool IsPerpendicular(const TIntVector3<T, false>& v1, const TIntVector3<T, false>& v2)
    {
        return (DotP(v1, v2) == 0);
    }

    /**
     * Tests if three vectors are coplanar
     *
     * @param(v1) Vector one
     * @param(v2) Vector two
     * @param(v3) Vector three
     *
     * @return True if coplanar, false if not.
     */

    template<IntType T>
    inline bool IsCoplanar(const TIntVector3<T, false>& v1, const TIntVector3<T, false>& v2, const TIntVector3<T, false>& v3)
    {
        return (ScalarTriple(v1, v2, v3) == 0);
    }


    // ================================================================ //
    //   IntVector3 static function implementation with return values   // 
    // ================================================================ //

    /**
     * Gets cross product between two vectors.
     *
     * @param(v1) vector one
     * @param(v2) vector two
     *
     * @return Cross product of v1 and v2
     */

    template<IntType T>
    TIntVector3<T, false> CrossP(const TIntVector3<T, false>& v1, const TIntVector3<T, false>& v2)
    {
        return TIntVector3<T, false>((v1.y * v2.z) - (v1.z * v2.y),
                                     (v1.z * v2.x) - (v1.x * v2.z),
                                     (v1.x * v2.y) - (v1.y * v2.x));
    }

    /**
     * Creates a new Vector by the componentwise max of both vectors
     *
     * @param(v1) Vector one
     * @param(v2) Vector two
     *
     * @return Vector of componentwise max
     */

    template<IntType T>
    TIntVector3<T, false> Max(const TIntVector3<T, false>& v1, const TIntVector3<T, false>& v2)
    {
        return TIntVector3<T, false>((v1.x > v2.x) ? v1.x : v2.x,
                                     (v1.y > v2.y) ? v1.y : v2.y,
                                     (v1.z > v2.z) ? v1.z : v2.z);
    }

    /**
     * Creates a new Vector by the componentwise min of both vectors
     *
     * @param(v1) Vector one
     * @param(v2) Vector two
     *
     * @return Vector of componentwise min
     */

    template<IntType T>
    TIntVector3<T, false> Min(const TIntVector3<T, false>& v1, const TIntVector3<T, false>& v2)
    {
        return TIntVector3<T, false>((v1.x < v2.x) ? v1.x : v2.x,
                                     (v1.y < v2.y) ? v1.y : v2.y,
                                     (v1.z < v2.z) ? v1.z : v2.z);
    }

    /**
     * Gets reversed vector.
     *
     * @param(v1) Vector one
     *
     * @note result is stored in v1.
     */

    template<IntType T>
    TIntVector3<T, false> Negate(const TIntVector3<T, false>& v1)
    {
        return TIntVector3<T, false>(-v1.x, -v1.y, -v1.z);
    }

    /**
     * Gets vector triple product ((v1 x v2) x v3).
     *
     * @param(v1) Vector one
     * @param(v2) Vector two
     * @param(v3) Vector three
     *
     * @return Vector triple product
     */

    template<IntType T>
    TIntVector3<T, false> VectorTriple(const TIntVector3<T, false>& v1, const TIntVector3<T, false>& v2, const TIntVector3<T, false>& v3)
    {
        return CrossP(CrossP(v1, v2), v3);
    }

    template<IntType T>
    TIntVector3<T, false> SignVector(const TIntVector3<T, false>& v1)
    {
        return TIntVector3<T, false>((v1.x >= 0) ? 1 : -1, (v1.y >= 0) ? 1 : -1, (v1.z >= 0) ? 1 : -1);
    }

} // phanes::core::math::coretypes

#endif // !INTVECTOR3_H

#include "Core/Math/IntVector3.inl"