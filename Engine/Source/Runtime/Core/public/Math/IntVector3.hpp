#pragma once

#include "Core/public/Math/Boilerplate.h"

#include "Core/public/Math/MathCommon.hpp"
#include "Core/public/Math/MathAbstractTypes.h"
#include "Core/public/Math/MathFwd.h"

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

    template<IntType T>
    struct TIntVector3 {

    public:

        // Using in combination with a struct and an array allows us the reflect changes of the x and y variables in the comp array and vise versa.

        union
        {

            struct
            {
                /** X component of Vector
                 *
                 * @ref [FIELD]components
                 * @note x does not hold the component, but is a reference two the second item in the components array. The varibale exists wholly for convenience.
                 */
                T x;

                /** Y component of Vector
                 *
                 * @ref [FIELD]components
                 *
                 * @note y does not hold the component, but is a reference two the second item in the components array. The varibale exists wholly for convenience.
                 */
                T y;

                /** Z component of Vector
                 *
                 * @ref [FIELD]components
                 *
                 * @note Z does not hold the component, but is a reference two the second item in the components array. The varibale exists wholly for convenience.
                 */
                T z;
            };

            /** Components array holding the data
             *
             * @ref [FIELD]x
             * @ref [FIELD]y
             * @ref [FIELD]z
             *
             * @note Components are split into x, y and z. Access and manipulation is possible by these variables.
             */

            T comp[3];

    };

    public:


        /**
         * Default constructor without initialization
         */

        TIntVector3() = default;

        /**
         * Copy constructor
         */

        TIntVector3(const TIntVector3<T>& v)
        {
            memcpy(this->comp, comp, sizeof(T) * 3);
        }

        /**
         * Move constructor
         */

        TIntVector3(TIntVector3<T>&& v)
        {
            this->comp = v.comp;
            v.comp = nullptr;
        }

        /**
         * Convert other type of vector
         */

        template<IntType OtherIntType>
        explicit TIntVector3(const TIntVector3<OtherIntType>& v) : x((T)v.x), y((T)v.y) {};

        /**
         * Construct Vector from xy components.
         *
         * @param(x) X component
         * @param(y) Y component
         * @param(z) Z component
         */

        TIntVector3(const T x, const T y, const T z) : x(x), y(y), z(z) {};

        /**
         * Construct Vector from two component array.
         *
         * @param(comp) Array of components
         */

        TIntVector3(const T* comp)
        {
            memcpy(this->comp, comp, sizeof(T) * 3);
        }
     
        /**
         * Constructs a vector pointing from start to end.
         *
         * @param(start) Startingpoint
         * @param(end) Endpoint
         */

        TIntVector3(const TIntPoint3<T>& start, const TIntPoint3<T>& end)
        {
            this->x = end.x - start.x;
            this->y = end.y - start.y;
            this->z = end.z - start.z;
        }

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

    template<IntType T>
    inline TIntVector3<T> operator+= (TIntVector3<T>& v1, T s)
    {
        v1.x += s;
        v1.y += s;
        v1.z += s;

        return v1;
    }

    /**
     * Coponentwise addition of 3D vector to 3D vector
     *
     * @param(v1) vector to add to
     * @param(v2) vector to add
     */

    template<IntType T>
    inline TIntVector3<T> operator+= (TIntVector3<T>& v1, const TIntVector3<T>& v2)
    {
        v1.x += v2.x;
        v1.y += v2.y;
        v1.z += v2.z;

        return v1;
    }

    /**
     * Coponentwise substraction of scalar of 3D vector
     *
     * @param(v1) vector to substract from
     * @param(s) scalar to substract
     */

    template<IntType T>
    inline TIntVector3<T> operator-= (TIntVector3<T>& v1, T s)
    {
        v1.x -= s;
        v1.y -= s;
        v1.z -= s;

        return v1;
    }

    /**
     * Coponentwise substraction of 3D vector to 3D vector
     *
     * @param(v1) vector to substract from
     * @param(v2) vector to substract with
     */

    template<IntType T>
    inline TIntVector3<T> operator-= (TIntVector3<T>& v1, const TIntVector3<T>& v2)
    {
        v1.x -= v2.x;
        v1.y -= v2.y;
        v1.z -= v2.z;

        return v1;
    }

    /**
     * Dot product between two 3D Vectors
     *
     * @param(v1) vector one
     * @param(s) scalar
     */

    template<IntType T>
    inline TIntVector3<T> operator*= (TIntVector3<T>& v1, T s)
    {
        v1.x *= s;
        v1.y *= s;
        v1.z *= s;

        return v1;
    }

    /**
     * Division of vector by scalar
     *
     * @param(v1) vector one
     * @param(s) scalar
     */

    template<IntType T>
    inline TIntVector3<T> operator/= (TIntVector3<T>& v1, T s)
    {
        float _1_s = 1.0f / s;

        v1.x *= s;
        v1.y *= s;
        v1.z *= s;

        return v1;
    }

    /**
     * Stores remainder of division with scalar
     *
     * @param(v1) vector one
     * @param(s) scalar
     */

    template<IntType T>
    inline TIntVector3<T> operator%= (TIntVector3<T>& v1, T s)
    {
        v1.x %= s;
        v1.y %= s;
        v1.z %= s;

        return v1;
    }

    /**
     * Coponentwise multiplication of 3D Vectors with scalar
     *
     * @param(v1) vector one
     * @param(s) scalar
     *
     * @return Resulting vector
     */

    template<IntType T>
    TIntVector3<T> operator* (const TIntVector3<T>& v1, T s)
    {
        return TIntVector3<T>(v1.x * s, v1.y * s, v1.z * s);
    }

    /**
     * Coponentwise multiplication of 3D Vectors with scalar
     *
     * @param(s) scalar
     * @param(v2) vector
     *
     * @return Solution vector
     */

    template<IntType T>
    FORCEINLINE TIntVector3<T> operator* (T s, const TIntVector3<T>& v1)
    {
        return v1 * s;
    }
   
    /**
     * Division by scalar
     *
     * @param(s) scalar
     * @param(v2) vector
     *
     * @return Solution vector
     */

    template<IntType T>
    inline TIntVector3<T> operator/ (const TIntVector3<T>& v1, T s)
    {
        float _1_s = 1.0f / s;
        return TIntVector3<T>(v1.x * s, v1.y * s, v1.z * s);
    }

    template<IntType T>
    FORCEINLINE TIntVector3<T> operator/ (T s, const TIntVector3<T>& v1)
    {
        return v1 / s;
    }

    /**
     * Stores remainder of division by scalar
     *
     * @param(s) scalar
     * @param(v2) vector
     *
     * @return Solution vector
     */

    template<IntType T>
    inline TIntVector3<T> operator% (T s, const TIntVector3<T>& v1)
    {
        return TIntVector3<T>(v1.x % s, v1.y % s, v1.z % s);
    }

    /**
     * Dot product between two 3D Vectors
     *
     * @param(v1) vector one
     * @param(v2) vector two
     *
     * @return Dot product of Vectors
     */

    template<IntType T>
    T operator* (const TIntVector3<T>& v1, const TIntVector3<T>& v2)
    {
        return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
    }

    /**
     * Coponentwise addition of scalar to 3D vector
     *
     * @param(v1) vector to add to
     * @param(s) scalar to add
     *
     * @return Resulting vector
     */

    template<IntType T>
    TIntVector3<T> operator+ (const TIntVector3<T>& v1, T s)
    {
        return TIntVector3<T>(v1.x + s.v1.y + s, v1.z + s);
    }

    /**
     * Coponentwise addition of 3D vector to 3D vector
     *
     * @param(v1) vector to add to
     * @param(v2) vector to add
     *
     * @return Resulting vector
     */

    template<IntType T>
    TIntVector3<T> operator+ (const TIntVector3<T>& v1, const TIntVector3<T>& v2)
    {
        return TIntVector3<T>(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
    }

    /**
     * Coponentwise substraction of scalar of 3D vector
     *
     * @param(v1) vector to substract from
     * @param(s) scalar to substract
     *
     * @return Resulting vector
     */

    template<IntType T>
    TIntVector3<T> operator- (const TIntVector3<T>& v1, T s)
    {
        return TIntVector3<T>(v1.x - s.v1.y - s, v1.z - s);
    }

    /**
     * Coponentwise substraction of scalar of 3D vector
     *
     * @param(v1) vector to substract from
     * @param(v2) vector to substract with
     *
     * @return Resulting vector
     */

    template<IntType T>
    TIntVector3<T> operator- (const TIntVector3<T>& v1, const TIntVector3<T>& v2)
    {
        return TIntVector3<T>(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
    }

    /**
     * Negates vector
     *
     * @param(v1) Vector to negate
     */

    template<IntType T>
    TIntVector3<T> operator- (TIntVector3<T>& v1)
    {
        v1.x = -v1.x;
        v1.y = -v1.y;
        v1.z = -v1.z;

        return v1;
    }

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

    template<IntType T>
    inline bool operator== (const TIntVector3<T>& v1, const TIntVector3<T>& v2)
    {
        return (abs(v1.x - v2.x) < P_FLT_INAC && abs(v1.y - v2.y) < P_FLT_INAC && abs(v1.z - v2.z) < P_FLT_INAC);
    }

    /**
     * Tests two 3D vectors for inequality.
     *
     * @param(v1) Vector one
     * @param(v2) Vector two
     *
     * @return True if inequal, false if not.
     */

    template<IntType T>
    inline bool operator!= (const TIntVector3<T>& v1, const TIntVector3<T>& v2)
    {
        return (abs(v1.x - v2.x) > P_FLT_INAC || abs(v1.y - v2.y) > P_FLT_INAC || abs(v1.z - v2.z) > P_FLT_INAC);
    }


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
    T DotP(const TIntVector3<T>& v1, const TIntVector3<T>& v2)
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
    inline bool Equals(const TIntVector3<T>& v1, const TIntVector3<T>& v2, T threshold = P_FLT_INAC)
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
    TIntVector3<T> CrossPV(TIntVector3<T>& v1, const TIntVector3<T>& v2)
    {
        float x = v1.x;
        float y = v1.y;
        float z = v1.z;

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
    TIntVector3<T> MaxV(TIntVector3<T>& v1, const TIntVector3<T>& v2)
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
    TIntVector3<T> MinV(TIntVector3<T>& v1, const TIntVector3<T>& v2)
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
    TIntVector3<T> NegateV(TIntVector3<T>& v1)
    {
        v1.x = -v1.x;
        v1.y = -v1.y;
        v1.z = -v1.z;

        return v1;
    }

    /**
     * Performes componentwise multiplication of two vectors.
     *
     * @param(v1) Vector one
     * @param(v2) Vector two
     *
     * @note result is stored in v1.
     */

    template<IntType T>
    TIntVector3<T> ScaleV(TIntVector3<T>& v1, const TIntVector3<T>& v2)
    {
        v1.x *= v2.x;
        v1.y *= v2.y;
        v1.z *= v2.z;

        return v1;
    }

    /**
     * Copies v1 vector
     *
     * @param(v1) Vector to copy to
     * @param(v2) Vector to copy
     */

    template<IntType T>
    TIntVector3<T> Set(TIntVector3<T>& v1, const TIntVector3<T>& v2)
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
    TIntVector3<T> Set(TIntVector3<T>& v1, T x, T y, T z)
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
    TIntVector3<T> SignVectorV(TIntVector3<T>& v1)
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
    T ScalarTriple(const TIntVector3<T>& v1, const TIntVector3<T>& v2, const TIntVector3<T>& v3)
    {
        return CrossP(v1, v2) * v3;
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
    TIntVector3<T> VectorTripleV(TIntVector3<T>& v1, const TIntVector3<T>& v2, const TIntVector3<T>& v3)
    {
        CrossPV(CrossPV(v1, v2), v3);

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
    inline bool IsPerpendicular(const TIntVector3<T>& v1, const TIntVector3<T>& v2)
    {
        return (DotP(v1, v2) == 0);
    }

    /**
     * Tests whether two vectors are parallel.
     *
     * @param(v1) Vector one
     * @param(v2) Vector two
     *
     * @return True if parallel, false if not.
     */

    template<IntType T>
    inline bool IsParallel(const TIntVector3<T>& v1, const TIntVector3<T>& v2)
    {
        return (abs(DotP(v1, v2)) == 1);
    }

    /**
     * Tests whether two vectors are coincident (Parallel and point in same direction).
     *
     * @param(v1) Vector one
     * @param(v2) Vector two
     *
     * @return True if coincident, false if not.
     */

    template<IntType T>
    inline bool IsCoincident(const TIntVector3<T>& v1, const TIntVector3<T>& v2)
    {
        return (DotP(v1, v2) == 1);
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
    inline bool IsCoplanar(const TIntVector3<T>& v1, const TIntVector3<T>& v2, const TIntVector3<T>& v3)
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
    TIntVector3<T> CrossP(const TIntVector3<T>& v1, const TIntVector3<T>& v2)
    {
        return TIntVector3<T>((v1.y * v2.z) - (v1.z * v2.y),
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
    TIntVector3<T> Max(const TIntVector3<T>& v1, const TIntVector3<T>& v2)
    {
        return TIntVector3<T>((v1.x > v2.x) ? v1.x : v2.x,
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
    TIntVector3<T> Min(const TIntVector3<T>& v1, const TIntVector3<T>& v2)
    {
        return TIntVector3<T>((v1.x < v2.x) ? v1.x : v2.x,
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
    TIntVector3<T> Negate(const TIntVector3<T>& v1)
    {
        return TIntVector3<T>(-v1.x, -v1.y, -v1.z);
    }

    /**
     * Multiplies vector componentwise.
     *
     * @param(v1) Vector one
     * @param(v2) Vector two
     *
     * @return Vector with componentwise products
     */

    template<IntType T>
    TIntVector3<T> Scale(const TIntVector3<T>& v1, const TIntVector3<T>& v2)
    {
        return TIntVector3<T>(v1.x * v2.x, v1.y * v2.y, v1.z * v2.z);
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
    TIntVector3<T> VectorTriple(const TIntVector3<T>& v1, const TIntVector3<T>& v2, const TIntVector3<T>& v3)
    {
        return CrossP(CrossP(v1, v2), v3);
    }

} // phanes::core::math::coretypes

#endif // !INTVECTOR3_H

