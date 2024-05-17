#pragma once

#include "Core/Core.h"

#include "Core/public/Misc/Boilerplate.h"

#include "Core/public/Math/MathCommon.hpp"
#include "Core/public/Math/MathAbstractTypes.h"
#include "Core/public/Math/MathFwd.h"

#ifndef P_DEBUG
#pragma warning(disable : 4244)
#endif

/**
 * Note: Some function are deleted, because, their unusable with int types, except very specific cases. 
 * To keep the library verbose, these functions are explicitly marked as deleted.
 */


#ifndef INTVECTOR2_H
#define INTVECTOR2_H

#define PIntZeroVector2(type)		TIntVector2<##type>(0,0)
#define PIntVectorSouth2(type)		TIntVector2<##type>(0,-1)
#define PIntVectorNorth2(type)		TIntVector2<##type>(0,1)
#define PIntVectorEast2(type)		TIntVector2<##type>(1,0)
#define PIntVectorWest2(type)		TIntVector2<##type>(-1,0)


namespace Phanes::Core::Math {

    /**
     * A 2D Vector with components x and y with integer precision.
     */

    template<IntType T>
    struct TIntVector2 {

        static_assert(std::is_integral_v<T>, "T must be an integer type.");

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
            };

            /** Components array holding the data
             *
             * @ref [FIELD]x
             * @ref [FIELD]y
             *
             * @note Components are split into x and y. Access and manipulation is possible by these variables.
             */

            T comp[2];

        };
    


    
    public:

        /**
         * Default constructor without initialization
         */

        TIntVector2() = default;

        /**
         * Copy constructor
         */

        TIntVector2(const TIntVector2<T>& v)
        {
            memcpy(this->comp, comp, sizeof(T) * 2);
        }

        /**
         * Move constructor
         */

        TIntVector2(TIntVector2<T>&& v)
        {
            this->comp = v.comp;
            v.comp = nullptr;
        }

        /**
         * Convert other type of vector
         */

        template<IntType OtherIntType>
        explicit TIntVector2(const TIntVector2<OtherIntType>& v) : x((T)v.x), y((T)v.y) {};

        /**
         * Construct Vector from xy components.
         *
         * @param x X component
         * @param y Y component
         */

        TIntVector2(const T x, const T y)
        {
            this->x = x;
            this->y = y;
        }

        /**
         * Construct Vector from two component array.
         *
         * @param comp Array of components
         */

        TIntVector2(const T* comp)
        {
            memcpy(this->comp, comp, sizeof(T) * 2);
        }

        /**
         * Construct Vector from 3D integer Vector's xy.
         *
         * @param v 3D IntVector to copy from
         */

        TIntVector2(const TIntVector3<T>& v)
        {
            this->x = v.x;
            this->y = v.y;
        }

        /**
         * Constructs a vector pointing from start to end.
         *
         * @param(start) Startingpoint
         * @param(end) Endpoint
         */

        TIntVector2(const TIntPoint2<T>& start, const TIntPoint2<T>& end)
        {
            this->x = end.x - start.x;
            this->y = end.y - start.y;
        }
    };

    // ======================== //
    //   IntVector2 operators   //
    // ======================== //
    
    
    /**
     * Addition operation on same TIntVector2<T> (this) by a floating point value.
     *
     * @param(v1) Vector to add to
     * @param(s) Floating point to add
     */

    template<IntType T>
    TIntVector2<T> operator+= (TIntVector2<T>& v1, T s)
    {
        v1.x += s;
        v1.y += s;

        return v1;
    }

    /**
     * Addition operation on same TIntVector2<T> (this) by a another TIntVector2<T>.
     *
     * @param(v1) Vector to add to
     * @param(v2) Vector to add
     */

    template<IntType T>
    TIntVector2<T> operator+= (TIntVector2<T>& v1, const TIntVector2<T>& v2)
    {
        v1.x += v2.x;
        v1.y += v2.y;

        return v1;
    }

    /**
     * Substraction operation on same TIntVector2<T> (this) by a floating point.
     *
     * @param(v1) Vector to substract from
     * @param(v2) Floating point to substract
     */

    template<IntType T>
    TIntVector2<T> operator-= (TIntVector2<T>& v1, T s)
    {
        v1.x -= s;
        v1.y -= s;

        return v1;
    }

    /**
     * Substraction operation on same TIntVector2<T> (this) by a another TIntVector2<T>.
     *
     * @param(v1) Vector to substract from
     * @param(v2) Vector to substract
     */

    template<IntType T>
    TIntVector2<T> operator-= (TIntVector2<T>& v1, const TIntVector2<T>& v2)
    {
        v1.x -= v2.x;
        v1.y -= v2.y;

        return v1;
    }

    /**
     * Multiplication of TIntVector2<T> (this) with a floating point.
     *
     * @param(v1) Vector to multiply with
     * @param(s Floating point to multiply with
     */

    template<IntType T>
    TIntVector2<T> operator*= (TIntVector2<T>& v1, T s)
    {
        v1.x *= s;
        v1.y *= s;

        return v1;
    }

    /**
     * Devision of Vector
     *
     * @param(v1) Vector to divide with
     * @param(s) Scalar to divide with
     * 
     * @note Result is rounded (obviously)
     */

    template<IntType T>
    TIntVector2<T> operator/= (TIntVector2<T>& v1, T s)
    {
        float _1_s = 1.0f;
        
        v1.x *= _1_s;
        v1.y *= _1_s;
        
        return v1;
    }

    /**
     * Stores the remainder of division by a scalar.
     *
     * @param(v1) Vector to divide with
     * @param(s) Scalar to divide with
     */

    template<IntType T>
    TIntVector2<T> operator%= (TIntVector2<T>& v1, T s)
    {
        v1.x %= s;
        v1.y %= s;

        return v1;
    }

    /**
     * Scale of Vector by floating point. (> Creates a new TIntVector2<T>)
     *
     * @param(v1) Vector to multiply with
     * @param(s Floating point to multiply with
     *
     * @return Result Vector
     */

    template<IntType T>
    TIntVector2<T> operator* (const TIntVector2<T>& v1, T s)
    {
        return TIntVector2<T>(v1.x * s, v1.y * s);
    }

    /**
     * Division of Vector by floating point. (> Creates another TIntVector2<T>)
     *
     * @see [FUNC]DivideFloat
     * 
     * @param(v1) Vector to multiply with
     * @param(s Floating point to divide with
     *
     * @return Result Vector
     * @note Deleted, because the returntype might not implicitly be obvious, when using in code or reading.
     */

    template<IntType T>
    TIntVector2<T> operator/ (const TIntVector2<T>& v1, T s)
    {
        float _1_s = 1.0f;
        return TIntVector2<T>(v1.x * _1_s, v1.y * _1_s);
    }

    /**
     * Scale of Vector by floating point. (> Creates a new TIntVector2<T>)
     *
     * @param(v1) Vector to multiply with
     * @param(s Floating point to multiply with
     *
     * @return Result Vector
     */

    template<IntType T>
    FORCEINLINE TIntVector2<T> operator* (T s, const TIntVector2<T>& v1)
    {
        return v1 * s;
    }

    /**
     * Division of Vector by floating point. (> For convenience not arithmethicaly correct. Works like overloaded counterpart.)
     *
     * @see [FUNC]DivideFloat
     * 
     * @param(v1) Vector to multiply with
     * @param(s Floating point to divide with
     *
     * @return Result Vector
     * 
     * @note Deleted, because the returntype might not implicitly be obvious, when using in code or reading.
     */

    template<IntType T>
    FORCEINLINE TIntVector2<T> operator/ (T s, const TIntVector2<T>& v1)
    {
        return v1 / s;
    }

    /**
     * Dot product between two Vectors.
     *
     * @see [FUNC]DotP
     *
     * @param(v1) Vector one
     * @param(v2) Vector two
     *
     * @result Dot product
     */

    template<IntType T>
    T operator* (const TIntVector2<T>& v1, const TIntVector2<T>& v2)
    {
        return v1.x * v2.x + v1.y * v2.y;
    }

    /**
     * Componentwise addition of Vector with floating point.
     *
     * @param(v1) Vector to add to
     * @param(s Floating point to add
     *
     * @return Result Vector
     */

    template<IntType T>
    TIntVector2<T> operator+ (const TIntVector2<T>& v1, T s)
    {
        return TIntVector2<T>(v1.x + s, v1.y + s);
    }

    /**
     * Componentwise addition of Vector with floating point.
     *
     * @param(v1) Vector to add to
     * @param(s Floating point to add
     *
     * @return Result Vector
     */

    template<IntType T>
    TIntVector2<T> operator+ (const TIntVector2<T>& v1, const TIntVector2<T>& v2)
    {
        return TIntVector2<T>(v1.x + v2.x, v1.y + v2.y);
    }

    /**
     * Componentwise substraction of Vector with floating point.
     *
     * @param(v1) Vector to substract from
     * @param(s Floating point to substract
     *
     * @return Result Vector
     */

    template<IntType T>
    TIntVector2<T> operator- (const TIntVector2<T>& v1, T s)
    {
        return TIntVector2<T>(v1.x - s, v1.y - s);
    }

    /**
     * Componentwise substraction of Vector with Vector.
     *
     * @param(v1) Vector to substract from
     * @param(s Floating point to substract
     *
     * @return Result Vector
     */

    template<IntType T>
    TIntVector2<T> operator- (const TIntVector2<T>& v1, const TIntVector2<T>& v2)
    {
        return TIntVector2<T>(v1.x - v2.x, v1.y - v2.y);
    }

    /**
     * Scale of Vector by floating point. (> Creates a new TIntVector2<T>)
     *
     * @param(v1) Vector to multiply with
     * @param(s Floating point to multiply with
     *
     * @return Result Vector
     */

    template<IntType T>
    FORCEINLINE TIntVector2<T> operator% (const TIntVector2<T>& v1, T s)
    {
        return TIntVector2<T>(v1.x % s, v1.y % s);
    }

    /**
     * Negate Vector.
     *
     * @param(v1) Vector to negate
     */

    template<IntType T>
    void operator- (TIntVector2<T>& v1)
    {
        v1.x = -v1.x;
        v1.y = -v1.y;
    }

    /**
     * Compare Vector for equality.
     *
     * @see [FUNC]Equals
     *
     * @param(v1) Vector to negate
     *
     * @return true if equal, false if inequal
     */

    template<IntType T>
    bool operator== (const TIntVector2<T>& v1, const TIntVector2<T>& v2)
    {
        return (abs(v1.x - v1.x) < P_FLT_INAC && abs(v1.y - v1.y) < P_FLT_INAC);
    }


    /**
     * Compare Vector for inequality.
     *
     * @see [FUNC]Equals
     *
     * @param(v1) Vector to negate
     *
     * @return true if inequal, false if equal
     */

    template<IntType T>
    bool operator!= (const TIntVector2<T>& v1, const TIntVector2<T>& v2)
    {
        return (abs(v1.x - v1.x) > P_FLT_INAC || abs(v1.y - v1.y) > P_FLT_INAC);
    }

    // ============================================== //
    //   TIntVector2 static function implementation	  //
    // ============================================== //

    template<IntType T>
    TIntVector2<T> MaxV(TIntVector2<T>& v1, const TIntVector2<T>& v2)
    {
        v1.x = Phanes::Core::Math::Max(v1.x, v2.x);
        v1.y = Phanes::Core::Math::Max(v1.y, v2.y);

        return v1;
    }

    /**
     * Creates Vector, with component wise smallest values.
     *
     * @param(v1) Vector one
     * @param(v2) Vector two
     *
     * @note Stores new Vector to v1
     */

    template<IntType T>
    TIntVector2<T> MinV(TIntVector2<T>& v1, const TIntVector2<T>& v2)
    {
        v1.x = Phanes::Core::Math::Min(v1.x, v2.x);
        v1.y = Phanes::Core::Math::Min(v1.y, v2.y);

        return v1;
    }

    template<IntType T>
    TIntVector2<T> SignVectorV(TIntVector2<T>& v1)
    {
        v1.x = (v1.x >= 0) ? 1 : -1;
        v1.y = (v1.y >= 0) ? 1 : -1;

        return v1;
    }

    /**
     * Component wise multiplication of Vector
     *
     * @param(v1) Vector one
     * @param(v2) Vector two
     *
     * @note Stores new Vector to v1
     */

    template<IntType T>
    TIntVector2<T> ScaleV(TIntVector2<T>& v1, const TIntVector2<T>& v2)
    {
        v1.x *= v2.x;
        v1.y *= v2.y;

        return v1;
    }

    /**
     * Copies one Vector two another
     *
     * @param(v1) Vector to copy to
     * @param(v2) Vector to copy
     */

    template<IntType T>
    TIntVector2<T> Set(TIntVector2<T>& v1, const TIntVector2<T>& v2)
    {
        v1 = v2;

        return v1;
    }

    /**
     * Sets components of a vector.
     *
     * @param(v1) Vector to copy to
     * @param(v2) Vector to copy
     */

    template<IntType T>
    TIntVector2<T> Set(TIntVector2<T>& v1, T x, T y)
    {
        v1.x = x;
        v1.y = y;

        return v1;
    }


    /**
     * Negates Vector
     *
     * @param(v1) Vector one
     */

    template<IntType T>
    TIntVector2<T> NegateV(TIntVector2<T>& v1)
    {
        v1.x = -v1.x;
        v1.y = -v1.y;
    }

    /**
     * Tests if 2 vectors are perpendicular to each other.
     *
     * @param(v1) Vector one
     * @param(v2) Vector two
     *
     * @return true if perpendicular, false if not
     *
     * @note Requires v1 and v2 to be normal vectors.
     */

    template<IntType T>
    inline bool IsPerpendicular(const TIntVector2<T>& v1, const TIntVector2<T>& v2)
    {
        return (abs(DotP(v1, v2)) = 0);
    }

    /**
     * Tests if 2 vectors are parallel to each other. (Angle is close to zero.)
     *
     * @param(v1) Vector one
     * @param(v2) Vector two
     *
     * @return true if parallel, false if not
     *
     * @note Requires v1 and v2 to be normal vectors.
     */

    template<IntType T>
    inline bool IsParallel(const TIntVector2<T>& v1, const TIntVector2<T>& v2)
    {
        return (abs(DotP(v1, v2)) = 1);
    }

    /**
     * Tests if 2 vectors are coincident. (Are parallel and point in the same direction.)
     *
     * @param(v1) Vector one
     * @param(v2) Vector two
     *
     * @return true if coincident, false if not
     *
     * @note Requires v1 and v2 to be normal vectors.
     */

    template<IntType T>
    inline bool IsCoincident(const TIntVector2<T>& v1, const TIntVector2<T>& v2)
    {
        return (DotP(v1, v2) > 1);
    }

    /**
     * Gets outer product of to vectors.
     *
     * @param(v1) Vector one
     * @param(v2) Vector two
     *
     * @return Resulting matrix
     */

     //template<IntType T>
     //Matrix2<T> OuterProduct(const TIntVector2<T>& v1, const TIntVector2<T>& v2);


    // ================================================================ //
    //   IntVector2 static function implementation with return values   // 
    // ================================================================ //


    /**
     * Negates Vector
     *
     * @param(v1) Vector one
     *
     * @return Componentwise inverted vector
     */

    template<IntType T>
    TIntVector2<T> Negate(const TIntVector2<T>& v1)
    {
        return TIntVector2<T>(-v1.x, -v1.y);
    }

    /**
     * Creates a new Vector by the component wise minimals of both vectors
     *
     * @param(v1) Vector one
     * @param(v2) Vector two
     *
     * @return Minimal vector
     */

    template<IntType T>
    TIntVector2<T> Min(const TIntVector2<T>& v1, const TIntVector2<T>& v2)
    {
        return TIntVector2<T>(Phanes::Core::Math::Min(v1.x, v2.x), Phanes::Core::Math::Min(v1.y, v2.y));
    }

    /**
     * Creates a new Vector by the component wise maxima of both vectors
     *
     * @param(v1) Vector one
     * @param(v2) Vector two
     *
     * @return Maximal vector
     */

    template<IntType T>
    TIntVector2<T> Max(const TIntVector2<T>& v1, const TIntVector2<T>& v2)
    {
        return TIntVector2<T>(Phanes::Core::Math::Max(v1.x, v2.x), Phanes::Core::Math::Max(v1.y, v2.y));
    }


    template<IntType T>
    TIntVector2<T> SignVector(const TIntVector2<T>& v1)
    {
        return TIntVector2<T>((v1.x >= 0) ? 1 : -1, (v1.y >= 0) ? 1 : -1);
    }


} // phanes::core::math::coretypes

#endif // !INTVECTOR2_H

