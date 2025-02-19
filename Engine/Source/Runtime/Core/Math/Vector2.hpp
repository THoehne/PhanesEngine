#pragma once

#include "Core/Math/Boilerplate.h"

#include "Core/Math/MathCommon.hpp"
#include "Core/Math/MathFwd.h"

#include "Core/Math/SIMD/Storage.h"

#ifndef VECTOR2_H
#define VECTOR2_H


#define PZeroVector2(type, aligned)		Phanes::Core::Math::TVector2<type, aligned>(0,0)
#define PVectorSouth2(type, aligned)	Phanes::Core::Math::TVector2<type, aligned>(0,-1)
#define PVectorNorth2(type, aligned)	Phanes::Core::Math::TVector2<type, aligned>(0,1)
#define PVectorEast2(type, aligned)		Phanes::Core::Math::TVector2<type, aligned>(1,0)
#define PVectorWest2(type, aligned)		Phanes::Core::Math::TVector2<type, aligned>(-1,0)

namespace Phanes::Core::Math {

    /**
     * A 2D Vector with components x and y with floating point precision.
     */


    template<RealType T, bool A>
    struct TVector2 {

    public:

        using Real = T;

        // Using in combination with a struct and an array allows us the reflect changes of the x and y variables in the comp array and vise versa.

        union
        {

            struct
            {
                /** X component of Vector
                 *
                 * @see [FIELD]components
                 * @note x does not hold the component, but is a reference two the second item in the components array. The varibale exists wholly for convenience.
                 */
                Real x;

                /** Y component of Vector
                 *
                 * @see [FIELD]components
                 *
                 * @note y does not hold the component, but is a reference two the second item in the components array. The varibale exists wholly for convenience.
                 */
                Real y;
            };

            /** Components array holding the data
             *
             * @see [FIELD]x
             * @see [FIELD]y
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

        TVector2() = default;

        /**
         * Copy constructor
         */

        TVector2(const TVector2<Real, A>& v);

        /**
         * Construct Vector from xy components.
         *
         * @param(x) X component
         * @param(y) Y component
         */

        TVector2(const Real x, const Real y);

        /// <summary>
        /// Construct vector from array.
        /// </summary>
        /// <param name="comp">Array of at least 2 items.</param>
        TVector2(const Real* comp);

        /// <summary>
        /// Construct vector by broadcasting one scalar into all components.
        /// </summary>
        /// <param name="s">Scalar</param>
        TVector2(Real s);
    };

    // ====================== //
    //   TVector2 operators   //
    // ====================== //

    /**
     * Addition operation on same TVector2<T, S> (this) by a floating point value.
     *
     * @param(v1) Vector to add to
     * @param(s) Floating point to add
     */

    template<RealType T, bool S>
    TVector2<T, S>& operator+= (TVector2<T, S>& v1, T s);

    /**
     * Addition operation on same TVector2<T, S> (this) by a another TVector2<T, S>.
     *
     * @param(v1) Vector to add to
     * @param(v2) Vector to add
     */

    template<RealType T, bool S>
    TVector2<T, S>& operator+= (TVector2<T, S>& v1, const TVector2<T, S>& v2);

    /**
     * Substraction operation on same TVector2<T, S> (this) by a floating point.
     *
     * @param(v1) Vector to substract from
     * @param(v2) Floating point to substract
     */

    template<RealType T, bool S>
    TVector2<T, S>& operator-= (TVector2<T, S>& v1, T s);

    /**
     * Substraction operation on same TVector2<T, S> (this) by a another TVector2<T, S>.
     *
     * @param(v1) Vector to substract from
     * @param(v2) Vector to substract
     */

    template<RealType T, bool S>
    TVector2<T, S>& operator-= (TVector2<T, S>& v1, const TVector2<T, S>& v2);

    /**
     * Multiplication of TVector2<T, S> (this) with a floating point.
     *
     * @param(v1) Vector to multiply with
     * @param(s Floating point to multiply with
     */

    template<RealType T, bool S>
    TVector2<T, S>& operator*= (TVector2<T, S>& v1, T s);

    /// <summary>
    /// Componentwise multiplication of vector by other vector.
    /// </summary>
    /// <typeparam name="T"></typeparam>
    /// <typeparam name="S"></typeparam>
    /// <param name="v1"></param>
    /// <param name="v2"></param>
    /// <returns>Copy of v1.</returns>
    template<RealType T, bool S>
    TVector2<T, S>& operator*= (TVector2<T, S>& v1, const TVector2<T, S>& v2);

    /**
     * Devision of Vector (this) by floating point.
     *
     * @param(v1) Vector to divide with
     * @param(s Floating point to divide with
     */

    template<RealType T, bool S>
    TVector2<T, S>& operator/= (TVector2<T, S>& v1, T s);

    /// <summary>
    /// Componentwise division of vector by other vector.
    /// </summary>
    /// <typeparam name="T"></typeparam>
    /// <typeparam name="S"></typeparam>
    /// <param name="v1"></param>
    /// <param name="v2"></param>
    /// <returns>Copy of v1.</returns>
    template<RealType T, bool S>
    TVector2<T, S>& operator/= (TVector2<T, S>& v1, const TVector2<T, S>& v2);

    /**
     * Scale of Vector by floating point. (> Creates a new TVector2<T, S>)
     *
     * @param(v1) Vector to multiply with
     * @param(s Floating point to multiply with
     *
     * @return Result Vector
     */

    template<RealType T, bool S>
    TVector2<T, S> operator* (const TVector2<T, S>& v1, T s);

    /// <summary>
    /// Componentwise multiplication with vector by vector.
    /// </summary>
    /// <typeparam name="T"></typeparam>
    /// <typeparam name="S"></typeparam>
    /// <param name="v1"></param>
    /// <param name="v2"></param>
    /// <returns></returns>
    template<RealType T, bool S>
    TVector2<T, S> operator* (const TVector2<T, S>& v1, const TVector2<T, S>& v2);

    /**
     * Division of Vector by floating point. (> Creates another TVector2<T, S>)
     *
     * @param(v1) Vector to multiply with
     * @param(s Floating point to divide with
     *
     * @return Result Vector
     */

    template<RealType T, bool S>
    TVector2<T, S> operator/ (const TVector2<T, S>& v1, T s);


    template<RealType T, bool S>
    inline TVector2<T, S> operator/ (T s, const TVector2<T, S>& v1);

    /// <summary>
    /// Componentwise multiplication with vector by vector.
    /// </summary>
    /// <typeparam name="T"></typeparam>
    /// <typeparam name="S"></typeparam>
    /// <param name="v1"></param>
    /// <param name="v2"></param>
    /// <returns></returns>
    template<RealType T, bool S>
    TVector2<T, S> operator/ (const TVector2<T, S>& v1, const TVector2<T, S>& v2);

    /**
     * Scale of Vector by floating point. (> Creates a new TVector2<T, S>)
     *
     * @param(v1) Vector to multiply with
     * @param(s Floating point to multiply with
     *
     * @return Result Vector
     */

    template<RealType T, bool S>
    inline TVector2<T, S> operator* (T s, const TVector2<T, S>& v1)
    {
        return v1 * s;
    }

    /**
     * Componentwise addition of Vector with floating point.
     *
     * @param(v1) Vector to add to
     * @param(s Floating point to add
     *
     * @return Result Vector
     */

    template<RealType T, bool S>
    TVector2<T, S> operator+ (const TVector2<T, S>& v1, T s);

    /**
     * Componentwise addition of Vector with floating point.
     *
     * @param(v1) Vector to add to
     * @param(s Floating point to add
     *
     * @return Result Vector
     */

    template<RealType T, bool S>
    TVector2<T, S> operator+ (const TVector2<T, S>& v1, const TVector2<T, S>& v2);

    /**
     * Componentwise substraction of Vector with floating point.
     *
     * @param(v1) Vector to substract from
     * @param(s Floating point to substract
     *
     * @return Result Vector
     */

    template<RealType T, bool S>
    TVector2<T, S> operator- (const TVector2<T, S>& v1, T s);


    template<RealType T, bool S>
    inline TVector2<T, S> operator- (T s, const TVector2<T, S>& v1);

    /**
     * Componentwise substraction of Vector with Vector.
     *
     * @param(v1) Vector to substract from
     * @param(s Floating point to substract
     *
     * @return Result Vector
     */

    template<RealType T, bool S>
    TVector2<T, S> operator- (const TVector2<T, S>& v1, const TVector2<T, S>& v2);

    /**
     * Compare Vector for equality.
     *
     * @see [FUNC]Equals
     *
     * @param(v1) Vector to negate
     *
     * @return true if equal, false if inequal
     */

    template<RealType T, bool S>
    bool operator== (const TVector2<T, S>& v1, const TVector2<T, S>& v2);


    /**
        * Compare Vector for inequality.
        *
        * @see [FUNC]Equals
        *
        * @param(v1) Vector to negate
        *
        * @return true if inequal, false if equal
        */

    template<RealType T, bool S>
    bool operator!= (const TVector2<T, S>& v1, const TVector2<T, S>& v2);



    template<RealType T, bool A>
    TVector2<T, A>& operator++(TVector2<T, A>& v1);

    template<RealType T, bool A>
    TVector2<T, A>& operator--(TVector2<T, A>& v1);

    template<RealType T, bool A>
    TVector2<T, A>& operator++(TVector2<T, A>& v1, int);

    template<RealType T, bool S>
    TVector2<T, S>& operator--(TVector2<T, S>& v1, int);

    // ============================================ //
    //    TVector2 static function implementation	//
    // ============================================ //

    /**
     * Magnitude of Vector
     *
     * @param(v1) Vector
     *
     * @return Size of Vector
     */

    template<RealType T, bool S>
    T Magnitude(const TVector2<T, S>& v1);

    /**
     * @see [FUNC]Magnitude
     */
    template<RealType T>
    FORCEINLINE T Length(const TVector2<T, false>& v1) { return Magnitude(v1); };

    /**
     * Square of magnitude of Vector
     *
     * @param(v1) Vector
     *
     * @return Magnitude without calculating square root
     */

    template<RealType T, bool S>
    T SqrMagnitude(const TVector2<T, S>& v1);

    /**
     * @see [FUNC]SqrMagnitude
     */
    template<RealType T>
    FORCEINLINE T SqrLength(const TVector2<T, false>& v1) { return SqrMagnitude(v1); };

    /**
     * Normalize Vector 
     *
     * @param(v1) Vector
     */

    template<RealType T, bool S>
    TVector2<T, S>& NormalizeV(TVector2<T, S>& v1)
    {
        T vecNorm = Magnitude(v1);
        v1 /= (vecNorm < P_FLT_INAC) ? (T)1.0 : vecNorm;
        return v1;
    }

    /**
     * Normalize Vector
     *
     * @param(v1) Vector
     * 
     * @note Does not look for zero vector.
     */

    template<RealType T, bool S>
    TVector2<T, S>& UnsafeNormalizeV(TVector2<T, S>& v1)
    {
        return (v1 /= Magnitude(v1));
    }

    /**
     * Angle between to Vectors
     *
     * @param(v1) Vector one
     * @param(v2) Vector two
     */

    template<RealType T, bool S>
    T Angle(const TVector2<T, S>& v1, const TVector2<T, S>& v2)
    {
        return acos(DotP(v1, v2) / (Magnitude(v1) * Magnitude(v2)));
    }

    /**
     * Cosine of angle between to Vectors
     *
     * @param(v1) Vector one
     * @param(v2) Vector two
     */

    template<RealType T, bool S>
    T CosineAngle(const TVector2<T, S>& v1, const TVector2<T, S>& v2)
    {
        return DotP(v1, v2) / (Magnitude(v1) * Magnitude(v2));
    }

    /**
     * Returns signs of components in vector: -1 / +1 / 0.
     *
     * @param(v1) Vector one
     */

    template<RealType T, bool S>
    TVector2<T, S>& SignVectorV(TVector2<T, S>& v1)
    {
        v1.x = (v1.x >= (T)0.0) ? (T)1.0 : -(T)1.0;
        v1.y = (v1.y >= (T)0.0) ? (T)1.0 : -(T)1.0;

        return v1;
    }

    template<RealType T, bool S>
    T Distance(const TVector2<T, S>& v1, const TVector2<T, S>& v2)
    {
        return Magnitude(v2 - v1);
    }

    /**
     * Binds a vector to a square with a radius
     *
     * @param(v1) Vector one
     * @param(radius) Radius of square (=> Distance from middle to center of each site.)
     */

    template<RealType T, bool S>
    TVector2<T, S>& BindToSquareV(TVector2<T, S>& v1, T radius)
    {
        T k = (Abs(v1.x) > Abs(v1.y)) ? Abs(radius / v1.x) : Abs(radius / v1.y);
        v1 *= k;

        return v1;
    }

    /**
     * Clamps a vector to a square with a radius
     *
     * @param(v1) Vector one
     * @param(radius) Radius of square (=> Distance from middle to center of each site.)
     */

    template<RealType T, bool S>
    TVector2<T, S>& ClampToSquareV(TVector2<T, S>& v1, T radius)
    {
        T prime = (Abs(v1.x) > Abs(v1.y)) ? v1.x : v1.y;
        T k = (prime > radius) ? Abs(radius / prime) : (T)1.0;
        v1 *= k;

        return v1;
    }

    /**
     * Dot product of two Vectors
     * 
     * @param(v1) Vector one
     * @param(v2) Vector two
     */

    template<RealType T, bool S>
    inline T DotP(const TVector2<T, S>& v1, const TVector2<T, S>& v2);

    /**
     * Creates Vector, with component wise largest values. 
     *
     * @param(v1) Vector one
     * @param(v2) Vector two
     * 
     * @note Stores new Vector to v1
     */

    template<RealType T, bool S>
    TVector2<T, S>& MaxV(TVector2<T, S>& v1, const TVector2<T, S>& v2);

    /**
     * Creates Vector, with component wise smallest values.
     *
     * @param(v1) Vector one
     * @param(v2) Vector two
     *
     * @note Stores new Vector to v1
     */

    template<RealType T, bool S>
    TVector2<T, S>& MinV(TVector2<T, S>& v1, const TVector2<T, S>& v2);

    /**
     * Gets perpendicular Vector to v1.
     * 
     * @param(v1) Vector one
     *
     * @note Stores new Vector to v1
     */

    template<RealType T>
    TVector2<T, false>& GetPerpendicularV(TVector2<T, false>& v1)
    {
        return Set(v1, v1.y, -v1.x);
    }

    /**
     * Gets perpendicular Vector to v1.
     *
     * @reg [FUNC]PerpendicularV
     *
     * @param(v1) Vector one
     *
     * @note Stores new Vector to v1
     */

    template<RealType T>
    TVector2<T, false>& GetReversePerpendicularV(TVector2<T, false>& v1)
    {
        T x = v1.x;
        v1.x = -v1.y;
        v1.y = x;

        return v1;
    }

    /**
     * Componentwise inverse of Vector
     *
     * @param(v1) Vector one
     *
     * @note Stores new Vector to v1
     */

    template<RealType T, bool S>
    TVector2<T, S>& CompInverseV(TVector2<T, S>& v1)
    {
        return (v1 = (T)1.0 / v1);
    }

    /**
     * Reflect Vector by normal vector.
     *
     * @param(v1) Vector one
     * @param(normal) Normal of surface
     *
     * @note Stores new Vector to v1
     */

    template<RealType T, bool S>
    TVector2<T, S>& ReflectV(TVector2<T, S>& v1, const TVector2<T, S>& normal)
    {
        v1 = ((T)2.0 * DotP(v1, normal) * normal) - v1;

        return v1;
    }

    /**
     * Copies one Vector two another
     *
     * @param(v1) Vector to copy to
     * @param(v2) Vector to copy
     */

    template<RealType T, bool S>
    TVector2<T, S>& Set(TVector2<T, S>& v1, const TVector2<T, S>& v2)
    {
        v1 = v2;

        return v1;
    }

    /**
     * Sets components of a vector.
     * 
     * Automatically used _mm_setr_ps, if vector is xmm register.
     *
     * @param(v1) Vector to copy to
     * @param(v2) Vector to copy
     */

    template<RealType T, bool S>
    TVector2<T, S>& Set(TVector2<T, S>& v1, T x, T y);

    /**
     * Anti-clockwise vector rotation.
     *
     * @param(v1) Vector to rotate
     *
     * @note Angle is not clamped
     */

    template<RealType T, bool S>
    TVector2<T, S>& RotateV(TVector2<T, S>& v1, T angle)
    {
        T sinAngle = sin(angle);
        T cosAngle = cos(angle);

        Set(v1,
            v1.x * cosAngle - v1.y * sinAngle,
            v1.y * cosAngle + v1.x * sinAngle
        );

        return v1;
    }


    /**
     * Clockwise vector rotation.
     *
     * @param(v1) Vector to rotate
     *
     * @note Angle is not clamped
     */

    template<RealType T, bool S>
    FORCEINLINE TVector2<T, S>& ClockwiseRotateV(TVector2<T, S>& v1, T angle)
    {
        RotateV(v1, -angle);

        return v1;
    }

    /**
     * Negates Vector
     *
     * @param(v1) Vector one
     */

    template<RealType T>
    TVector2<T, false>& NegateV(TVector2<T, false>& v1)
    {
        return Set(v1, -v1.x, -v1.y);
    }

    /**
     * Tests if vector is a unity vector.
     *
     * @param(v1) Vector one
     * @param(threshold) Threshold to zero
     * 
     * @return true if unit vector, false if not
     */

    template<RealType T, bool S>
    inline bool IsNormalized(const TVector2<T, S>& v1, T threshold = P_FLT_INAC)
    {
        return (Abs(SqrMagnitude(v1) - 1) < threshold);
    }

    /**
     * Tests if 2 vectors are perpendicular to each other.
     *
     * @param(v1) Vector one
     * @param(v2) Vector two
     * @param(threshold) Threshold to zero
     * 
     * @return true if perpendicular, false if not
     * 
     * @note Requires v1 and v2 to be normal vectors.
     */

    template<RealType T, bool S>
    inline bool IsPerpendicular(const TVector2<T, S>& v1, const TVector2<T, S>& v2, T threshold = P_FLT_INAC)
    {
        return (Abs(DotP(v1, v2)) < threshold);
    }

    /**
     * Tests if 2 vectors are parallel to each other. (Angle is close to zero.)
     *
     * @param(v1) Vector one
     * @param(v2) Vector two
     * @param(t) threshold Threshold from one (e.g. 0.98f)
     * 
     * @return true if parallel, false if not
     *
     * @note Requires v1 and v2 to be normal vectors.
     */

    template<RealType T, bool S>
    inline bool IsParallel(const TVector2<T, S>& v1, const TVector2<T, S>& v2, T threshold = 1.0f - P_FLT_INAC)
    {
        return (Abs(DotP(v1, v2)) > threshold);
    }

    /**
     * Tests if 2 vectors are coincident. (Are parallel and point in the same direction.)
     *
     * @param(v1) Vector one
     * @param(v2) Vector two
     * @param(threshold) from one (e.g. 0.98f)
     *
     * @return true if coincident, false if not
     * 
     * @note Requires v1 and v2 to be normal vectors.
     */

    template<RealType T, bool S>
    inline bool IsCoincident(const TVector2<T, S>& v1, const TVector2<T, S>& v2, T threshold = 1.0f - P_FLT_INAC)
    {
        return (DotP(v1, v2) > threshold);
    }

    /**
     * Gets outer product of to vectors.
     *
     * @param(v1) Vector one
     * @param(v2) Vector two
     * 
     * @return Resulting matrix
     */

    //
    //Matrix2 OuterProduct(const TVector2<T, false>& v1, const TVector2<T, false>& v2);


    // ============================================================== //
    //   TVector2 static function implementation with return values   // 
    // ============================================================== //


    /**
     * Reflects a vector on a normal
     *
     * @param(v1) Vector one
     * @param(normal) Normal of surface
     *
     * @return Reflected vector
     */

    template<RealType T, bool S>
    TVector2<T, S> Reflect(const TVector2<T, S>& v1, const TVector2<T, S>& normal)
    {
        return (((T)2.0 * DotP(v1, normal) * normal) - v1);
    }

    /**
     * Componentwise inverse of a vector
     *
     * @param(v1) Vector one
     *
     * @return Componentwise inverted vector
     */

    template<RealType T, bool S>
    TVector2<T, S> CompInverse(const TVector2<T, S>& v1)
    {
        return ((T)1.0 / v1);
    }

    /**
     * Negates Vector
     * 
     * @param(v1) Vector one
     *
     * @return Componentwise inverted vector
     */

    template<RealType T, bool S>
    TVector2<T, S> Negate(const TVector2<T, S>& v1)
    {
        return ((T)0.0 - v1);
    }

    /**
     * Gets the perpendicular vector of v1
     *
     * @param(v1) Vector one
     *
     * @return Perpendicular vector
     */

    template<RealType T, bool S>
    TVector2<T, S> GetPerpendicular(const TVector2<T, S>& v1)
    {
        return TVector2<T, S>(v1.y, -v1.x);
    }

    /**
     * Gets reverse of the perpendicular vector of v1
     *
     * @param(v1) Vector one
     *
     * @return Reversed perpendicular vector
     */

    template<RealType T, bool S>
    TVector2<T, S> GetReversePerpendicular(const TVector2<T, S>& v1)
    {
        return TVector2<T, S>(-v1.y, v1.x);
    }

    /**
     * Creates a new Vector by the component wise minimals of both vectors
     *
     * @param(v1) Vector one
     * @param(v2) Vector two
     *
     * @return Minimal vector
     */

    template<RealType T, bool S>
    TVector2<T, S> Min(const TVector2<T, S>& v1, const TVector2<T, S>& v2);

    /**
     * Creates a new Vector by the component wise maxima of both vectors
     *
     * @param(v1) Vector one
     * @param(v2) Vector two
     *
     * @return Maximal vector
     */

    template<RealType T, bool S>
    TVector2<T, S> Max(const TVector2<T, S>& v1, const TVector2<T, S>& v2);

    /**
     * Creates a normalized instance of the vector
     *
     * @param(v1) Vector to normalize
     * 
     * @return Unit vector
     */

    template<RealType T, bool S>
    TVector2<T, S> Normalize(const TVector2<T, S>& v1)
    {
        T vecNorm = Magnitude(v1);
        return (vecNorm < P_FLT_INAC) ? v1 : (v1 / vecNorm);
    }

    /**
     * Creates a normalized instance of the vector
     *
     * @param(v1) Vector to normalize
     *
     * @return Unit vector
     * @note Does not test for zero vector
     */

    template<RealType T, bool S>
    TVector2<T, S> UnsafeNormalize(const TVector2<T, S>& v1)
    {
        return (v1 / Magnitude(v1));
    }

    /**
     * Returns signs of components in vector: -1 / +1.
     *
     * @param(v1) Vector one
     * 
     * @return Vector with signs as components
     */

    template<RealType T, bool S>
    TVector2<T, S> SignVector(const TVector2<T, S>& v1)
    {
        return TVector2<T, S>((v1.x >= (T)0.0) ? (T)1.0 : (T)-1.0, (v1.y >= (T)0.0) ? (T)1.0 : (T)-1.0);
    }

    /**
     * Binds a vector to a square with a radius
     *
     * @param(v1) Vector one
     * @param(radius) Radius of square (=> Distance from middle to center of each site.)
     * 
     * @return Bound vector
     */

    template<RealType T, bool S>
    TVector2<T, S> BindToSquare(const TVector2<T, S>& v1, T radius)
    {
        T k = (Abs(v1.x) > Abs(v1.y)) ? Abs(radius / v1.x) : Abs(radius / v1.y);
        return v1 * k;
    }

    /**
     * Clamps a vector to a square with a radius
     *
     * @param(v1) Vector one
     * @param(radius) Radius of square (=> Distance from middle to center of each site.)
     *
     * @return Clamped vector. If the length of the vector fits the square, then the vector is returned.
     */

    template<RealType T, bool S>
    TVector2<T, S> ClampToSquare(const TVector2<T, S>& v1, T radius)
    {
        T prime = (Abs(v1.x) > Abs(v1.y)) ? v1.x : v1.y;
        T k = (prime > radius) ? Abs(radius / prime) : 1.0f;

        return v1 * k;
    }

    /**
     * Interpolates between to vectors.
     *
     * @param(startVec) Start vector (t = 0)
     * @param(destVec) Destination vector (t = 1)
     * @param(t) Interpolation value
     *
     * @return Interpolated vector
     * 
     * @note Interpolation is clamped between 0 - 1.
     */

    template<RealType T, bool S>
    TVector2<T, S> Lerp(const TVector2<T, S>& startVec, const TVector2<T, S>& destVec, T t)
    {
        t = Phanes::Core::Math::Clamp(t, (T)0.0, (T)1.0);

        return ((1 - t) * startVec) + (t * destVec);
    }

    /**
     * Interpolates between to vectors. 
     *
     * @param(startVec) Start vector (t = 0)
     * @param(destVec) Destination vector (t = 1)
     * @param(t) Interpolation value
     *
     * @return Interpolated vector
     * 
     * @note Interpolation is not clamped. Make shure t is between 0.0f and 1.0f
     */

    template<RealType T, bool S>
    TVector2<T, S> LerpUnclamped(const TVector2<T, S>& startVec, const TVector2<T, S>& destVec, T t)
    {
        return (t * destVec) + ((1 - t) * startVec);
    }

    /**
     * Anti-clockwise vector rotation.
     *
     * @param(v1) Vector to rotate
     * @param(angle) Angle to rotate
     *
     * @return Rotated vector
     * 
     * @note Angle is not clamped
     */

    template<RealType T, bool S>
    TVector2<T, S> Rotate(const TVector2<T, S>& v1, T angle)
    {
        float sinAngle = sin(angle);
        float cosAngle = cos(angle);

        return TVector2<T, S>(v1.x * cosAngle - v1.y * sinAngle,
                           v1.y * cosAngle + v1.x * sinAngle);
    }

    /**
     * Clockwise vector rotation.
     *
     * @param(v1) Vector to rotate
     *
     * @return Rotated vector
     *
     * @note Angle is not clamped
     */

    template<RealType T, bool S>
    TVector2<T, S> ClockwiseRotate(const TVector2<T, S>& v1, T angle)
    {
        return Rotate(v1, -angle);
    }

} // phanes::core::math::coretypes

#endif // !VECTOR2_H

// Include operator impl.
#include "Core/Math/Vector2.inl"