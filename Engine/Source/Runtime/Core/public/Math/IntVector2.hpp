#pragma once

#include "Core/public/Math/Boilerplate.h"

#include "Core/public/Math/MathCommon.hpp"
#include "Core/public/Math/MathFwd.h"

#include "Core/public/Math/SIMD/Storage.h"

#ifndef P_DEBUG
#pragma warning(disable : 4244)
#endif

/**
 * Note: Some function are deleted, because, their unusable with int types, except very specific cases. 
 * To keep the library verbose, these functions are explicitly marked as deleted.
 */


#ifndef INTVECTOR2_H
#define INTVECTOR2_H

#define PIntZeroVector2(type, aligned)		TIntVector2<##type, ##aligned>(0,0)
#define PIntVectorSouth2(type, aligned)		TIntVector2<##type, ##aligned>(0,-1)
#define PIntVectorNorth2(type, aligned)		TIntVector2<##type, ##aligned>(0,1)
#define PIntVectorEast2(type, aligned)		TIntVector2<##type, ##aligned>(1,0)
#define PIntVectorWest2(type, aligned)		TIntVector2<##type, ##aligned>(-1,0)


namespace Phanes::Core::Math {

    /**
     * A 2D Vector with components x and y with integer precision.
     */

    template<IntType T, bool A>
    struct TIntVector2 {

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

            union
            {
                typename SIMD::Storage<2, T, SIMD::use_simd<T, 2, A>::value>::type comp;
                typename SIMD::Storage<2, T, SIMD::use_simd<T, 2, A>::value>::type data;
            };

        };
    


    
    public:

        /**
         * Default constructor without initialization
         */

        TIntVector2() = default;

        /**
         * Copy constructor
         */

        TIntVector2(const TIntVector2<T, A>& v);

        /**
         * Construct Vector from xy components.
         *
         * @param x X component
         * @param y Y component
         */

        TIntVector2(const T x, const T y);

        /**
         * Construct Vector from two component array.
         *
         * @param comp Array of components
         */

        TIntVector2(const T* comp);

        /**
         * Construct Vector from 3D integer Vector's xy.
         *
         * @param v 3D IntVector to copy from
         */

        TIntVector2(const T s);
    };



    // ======================== //
    //   IntVector2 operators   //
    // ======================== //
        
    /**
     * Addition operation on same TIntVector2<T, A> (this) by a scalar value.
     *
     * @param(v1) Vector to add to
     * @param(s) Scalar to add
     */

    template<IntType T, bool A>
    TIntVector2<T, A> operator+= (TIntVector2<T, A>& v1, T s);

    /**
     * Addition operation on same TIntVector2<T, A> (this) by a another TIntVector2<T, A>.
     *
     * @param(v1) Vector to add to
     * @param(v2) Vector to add
     */

    template<IntType T, bool A>
    TIntVector2<T, A> operator+= (TIntVector2<T, A>& v1, const TIntVector2<T, A>& v2);

    /**
     * Substraction operation on same TIntVector2<T, A> (this) by a scalar.
     *
     * @param(v1) Vector to substract from
     * @param(v2) Scalar to substract
     */

    template<IntType T, bool A>
    TIntVector2<T, A> operator-= (TIntVector2<T, A>& v1, T s);

    /**
     * Substraction operation on same TIntVector2<T, A> (this) by a another TIntVector2<T, A>.
     *
     * @param(v1) Vector to substract from
     * @param(v2) Vector to substract
     */

    template<IntType T, bool A>
    TIntVector2<T, A> operator-= (TIntVector2<T, A>& v1, const TIntVector2<T, A>& v2);
    

    /**
     * Multiplication of TIntVector2<T, A> (this) with a scalar.
     *
     * @param(v1) Vector to multiply with
     * @param(s) scalar to multiply with
     */

    template<IntType T, bool A>
    TIntVector2<T, A> operator*= (TIntVector2<T, A>& v1, T s);

    template<IntType T, bool A>
    TIntVector2<T, A> operator*= (TIntVector2<T, A>& v1, const TIntVector2<T, A>& v2);

    /**
     * Devision of Vector
     *
     * @param(v1) Vector to divide with
     * @param(s) Scalar to divide with
     * 
     * @note Result is rounded 
     */

    template<IntType T, bool A>
    TIntVector2<T, A> operator/= (TIntVector2<T, A>& v1, T s);

    template<IntType T, bool A>
    TIntVector2<T, A> operator/= (TIntVector2<T, A>& v1, const TIntVector2<T, A>& v2);

    /**
     * Stores the remainder of division by a scalar.
     *
     * @param(v1) Vector to divide with
     * @param(s) Scalar to divide with
     */

    template<IntType T, bool A>
    TIntVector2<T, A> operator%= (TIntVector2<T, A>& v1, const TIntVector2<T, A>& v2);

    template<IntType T, bool A>
    TIntVector2<T, A> operator%= (TIntVector2<T, A>& v1, T s);

    template<IntType T, bool A>
    inline TIntVector2<T, A> operator&= (TIntVector2<T, A>& v1, const TIntVector2<T, A>& v2);

    template<IntType T, bool A>
    inline TIntVector2<T, A> operator&= (TIntVector2<T, A>& v1, T s);

    template<IntType T, bool A>
    inline TIntVector2<T, A> operator|= (TIntVector2<T, A>& v1, const TIntVector2<T, A>& v2);

    template<IntType T, bool A>
    inline TIntVector2<T, A> operator|= (TIntVector2<T, A>& v1, T s);

    template<IntType T, bool A>
    inline TIntVector2<T, A> operator^= (TIntVector2<T, A>& v1, const TIntVector2<T, A>& v2);

    template<IntType T, bool A>
    inline TIntVector2<T, A> operator^= (TIntVector2<T, A>& v1, T s);

    template<IntType T, bool A>
    inline TIntVector2<T, A> operator<<= (TIntVector2<T, A>& v1, const TIntVector2<T, A>& v2);

    template<IntType T, bool A>
    inline TIntVector2<T, A> operator<<= (TIntVector2<T, A>& v1, T s);

    template<IntType T, bool A>
    inline TIntVector2<T, A> operator>>= (TIntVector2<T, A>& v1, const TIntVector2<T, A>& v2);

    template<IntType T, bool A>
    inline TIntVector2<T, A> operator>>= (TIntVector2<T, A>& v1, T s);

    /**
     * Scale of Vector by floating point. (> Creates a new TIntVector2<T, A>)
     *
     * @param(v1) Vector to multiply with
     * @param(s Floating point to multiply with
     *
     * @return Result Vector
     */

    template<IntType T, bool A>
    TIntVector2<T, A> operator* (const TIntVector2<T, A>& v1, T s);

    /**
     * Division of Vector by floating point. (> Creates another TIntVector2<T, A>)
     *
     * @see [FUNC]DivideFloat
     * 
     * @param(v1) Vector to multiply with
     * @param(s Floating point to divide with
     *
     * @return Result Vector
     * @note Deleted, because the returntype might not implicitly be obvious, when using in code or reading.
     */

    template<IntType T, bool A>
    TIntVector2<T, A> operator/ (const TIntVector2<T, A>& v1, T s);

    /**
     * Scale of Vector by floating point. (> Creates a new TIntVector2<T, A>)
     *
     * @param(v1) Vector to multiply with
     * @param(s Floating point to multiply with
     *
     * @return Result Vector
     */

    template<IntType T, bool A>
    FORCEINLINE TIntVector2<T, A> operator* (T s, const TIntVector2<T, A>& v1) { return v1 * s; };

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

    template<IntType T, bool A>
    FORCEINLINE TIntVector2<T, A> operator/ (T s, const TIntVector2<T, A>& v1) { return v1 / s; };

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

    template<IntType T, bool A>
    T operator* (const TIntVector2<T, A>& v1, const TIntVector2<T, A>& v2);

    /**
     * Componentwise addition of Vector with floating point.
     *
     * @param(v1) Vector to add to
     * @param(s Floating point to add
     *
     * @return Result Vector
     */

    template<IntType T, bool A>
    TIntVector2<T, A> operator+ (const TIntVector2<T, A>& v1, T s);

    /**
     * Componentwise addition of Vector with floating point.
     *
     * @param(v1) Vector to add to
     * @param(s Floating point to add
     *
     * @return Result Vector
     */

    template<IntType T, bool A>
    TIntVector2<T, A> operator+ (const TIntVector2<T, A>& v1, const TIntVector2<T, A>& v2);

    /**
     * Componentwise substraction of Vector with floating point.
     *
     * @param(v1) Vector to substract from
     * @param(s Floating point to substract
     *
     * @return Result Vector
     */

    template<IntType T, bool A>
    TIntVector2<T, A> operator- (const TIntVector2<T, A>& v1, T s);

    /**
     * Componentwise substraction of Vector with Vector.
     *
     * @param(v1) Vector to substract from
     * @param(s Floating point to substract
     *
     * @return Result Vector
     */

    template<IntType T, bool A>
    TIntVector2<T, A> operator- (const TIntVector2<T, A>& v1, const TIntVector2<T, A>& v2);




    /**
     * Scale of Vector by floating point. (> Creates a new TIntVector2<T, A>)
     *
     * @param(v1) Vector to multiply with
     * @param(s Floating point to multiply with
     *
     * @return Result Vector
     */

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
     * Compare Vector for equality.
     *
     * @see [FUNC]Equals
     *
     * @param(v1) Vector to negate
     *
     * @return true if equal, false if inequal
     */

    template<IntType T, bool A>
    bool operator== (const TIntVector2<T, A>& v1, const TIntVector2<T, A>& v2);


    /**
     * Compare Vector for inequality.
     *
     * @see [FUNC]Equals
     *
     * @param(v1) Vector to negate
     *
     * @return true if inequal, false if equal
     */

    template<IntType T, bool A>
    bool operator!= (const TIntVector2<T, A>& v1, const TIntVector2<T, A>& v2);



    // ============================================== //
    //   TIntVector2 static function implementation	  //
    // ============================================== //

    template<IntType T>
    T DotP(const TIntVector2<T, false>& v, const TIntVector2<T, false>& v1)
    {
        return v.x * v1.x + v.y * v1.y;
    }

    template<IntType T>
    TIntVector2<T, false> MaxV(TIntVector2<T, false>& v1, const TIntVector2<T, false>& v2)
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
    TIntVector2<T, false> MinV(TIntVector2<T, false>& v1, const TIntVector2<T, false>& v2)
    {
        v1.x = Phanes::Core::Math::Min(v1.x, v2.x);
        v1.y = Phanes::Core::Math::Min(v1.y, v2.y);

        return v1;
    }

    /// <summary>
    /// Returns signs of numbers (1 / -1). <br>
    /// Returns 1 for zero.
    /// </summary>
    /// <typeparam name="T"></typeparam>
    /// <param name="v1"></param>
    /// <returns></returns>
    template<IntType T>
    TIntVector2<T, false> SignVectorV(TIntVector2<T, false>& v1)
    {
        v1.x = (v1.x >= 0) ? 1 : -1;
        v1.y = (v1.y >= 0) ? 1 : -1;

        return v1;
    }

    /**
     * Copies one Vector two another
     *
     * @param(v1) Vector to copy to
     * @param(v2) Vector to copy
     */

    template<IntType T>
    TIntVector2<T, false> Set(TIntVector2<T, false>& v1, const TIntVector2<T, false>& v2)
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
    TIntVector2<T, false> Set(TIntVector2<T, false>& v1, T x, T y)
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
    TIntVector2<T, false> NegateV(TIntVector2<T, false>& v1)
    {
        v1.x = -v1.x;
        v1.y = -v1.y;

        return v1;
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
    inline bool IsPerpendicular(const TIntVector2<T, false>& v1, const TIntVector2<T, false>& v2)
    {
        return (Abs(DotP(v1, v2)) == 0);
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
    inline bool IsParallel(const TIntVector2<T, false>& v1, const TIntVector2<T, false>& v2)
    {
        return ((v1.x / v2.x) == (v1.y / v2.y));
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
    inline bool IsCoincident(const TIntVector2<T, false>& v1, const TIntVector2<T, false>& v2)
    {
        T tmp = v1.x / v2.x;
        return (tmp == (v1.y / v2.y) && tmp > -1);
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
     //Matrix2<T> OuterProduct(const TIntVector2<T, false>& v1, const TIntVector2<T, false>& v2);


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
    TIntVector2<T, false> Negate(const TIntVector2<T, false>& v1)
    {
        return TIntVector2<T, false>(-v1.x, -v1.y);
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
    TIntVector2<T, false> Min(const TIntVector2<T, false>& v1, const TIntVector2<T, false>& v2)
    {
        return TIntVector2<T, false>(Phanes::Core::Math::Min(v1.x, v2.x), Phanes::Core::Math::Min(v1.y, v2.y));
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
    TIntVector2<T, false> Max(const TIntVector2<T, false>& v1, const TIntVector2<T, false>& v2)
    {
        return TIntVector2<T, false>(Phanes::Core::Math::Max(v1.x, v2.x), Phanes::Core::Math::Max(v1.y, v2.y));
    }


    template<IntType T>
    TIntVector2<T, false> SignVector(const TIntVector2<T, false>& v1)
    {
        return TIntVector2<T, false>((v1.x >= 0) ? 1 : -1, (v1.y >= 0) ? 1 : -1);
    }


} // phanes::core::math::coretypes

#endif // !INTVECTOR2_H

#include "Core/public/Math/IntVector2.inl"