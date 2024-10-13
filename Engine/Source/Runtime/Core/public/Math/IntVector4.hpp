#pragma once

#include "Core/public/Math/Boilerplate.h"

#include "Core/public/Math/MathCommon.hpp"
#include "Core/public/Math/MathFwd.h"

#include "Core/public/Math/SIMD/Storage.h"

#include "Core/public/Math/IntVector2.hpp"

#ifndef P_DEBUG
#pragma warning(disable : 4244)
#endif


#ifndef INTVECTOR4_H
#define INTVECTOR4_H

namespace Phanes::Core::Math {

	/**
	 * A 4D Vector with components x, y, z and w with integer precision.
	 */

	template<IntType T, bool A>
	struct TIntVector4 {

	public:

		union
		{

			struct
			{

				/** X component of Vector
				 *
				 * @ref [FIELD]components
				 *
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
				 * @note z does not hold the component, but is a reference two the second item in the components array. The varibale exists wholly for convenience.
				 */
				T z;

				/** W component of Vector
				 *
				 * @ref [FIELD]components
				 *
				 * @note w does not hold the component, but is a reference two the second item in the components array. The varibale exists wholly for convenience.
				 */
				T w;

			};

			union
			{
				typename SIMD::Storage<4, T, SIMD::use_simd<T, 4, A>::value>::type comp;
				typename SIMD::Storage<4, T, SIMD::use_simd<T, 4, A>::value>::type data;
			};
		};


	public:

		/**
		 * Default constructor without initialization
		 */

		TIntVector4() = default;


		/// <summary>
		/// Copy constructor.
		/// </summary>
		/// <param name="v"></param>
		TIntVector4(const TIntVector4<T, A>& v);

		/// <summary>
		/// Construct vector from x, y, z, w components.
		/// </summary>
		/// <param name="x"></param>
		/// <param name="y"></param>
		/// <param name="z"></param>
		/// <param name="w"></param>
		TIntVector4(const T x, const T y, const T z, const T w);

		/// <summary>
		/// Broadcast s into all components.
		/// </summary>
		/// <param name="s"></param>
		TIntVector4(T s);

		/**
		 * Construct Vector from two component array.
		 *
		 * @param comp Array of components
		 */

		TIntVector4(const T *comp);

		/// <summary>
		/// Construct vector from two 2d vectors 
		/// <param>
		/// x,y = v1.x, v2.y
		/// </param>
		/// z,w = v2.x, v2.y
		/// </summary>
		/// <param name="v1"></param>
		/// <param name="v2"></param>
		TIntVector4(const TIntVector2<T, A>& v1, const TIntVector2<T, A>& v2);



	};


    /**
     * Addition operation on same TIntVector4<T, A> (this) by a scalar value.
     *
     * @param(v1) Vector to add to
     * @param(s) Scalar
     */

    template<IntType T, bool A>
    TIntVector4<T, A>& operator+= (TIntVector4<T, A>& v1, T s);

    /**
     * Addition operation on same TIntVector4<T, A> (this) by a another TIntVector4<T, A>.
     *
     * @param(v1) Vector to add to
     * @param(v2) Vector to add
     */

    template<IntType T, bool A>
    TIntVector4<T, A>& operator+= (TIntVector4<T, A>& v1, const TIntVector4<T, A>& v2);

    /**
     * Substraction operation on same TIntVector4<T, A> (this) by a floating point.
     *
     * @param(v1) Vector to substract from
     * @param(v2) Floating point to substract
     */

    template<IntType T, bool A>
    TIntVector4<T, A>& operator-= (TIntVector4<T, A>& v1, T s);

    /**
     * Substraction operation on same TIntVector4<T, A> (this) by a another TIntVector4<T, A>.
     *
     * @param(v1) Vector to substract from
     * @param(v2) Vector to substract
     */

    template<IntType T, bool A>
    TIntVector4<T, A>& operator-= (TIntVector4<T, A>& v1, const TIntVector4<T, A>& v2);


    /**
     * Multiplication of TIntVector4<T, A> (this) with a floating point.
     *
     * @param(v1) Vector to multiply with
     * @param(s Floating point to multiply with
     */

    template<IntType T, bool A>
    TIntVector4<T, A>& operator*= (TIntVector4<T, A>& v1, T s);

    /**
     * Devision of Vector
     *
     * @param(v1) Vector to divide with
     * @param(s) Scalar to divide with
     *
     * @note Result is rounded (obviously)
     */

    template<IntType T, bool A>
    TIntVector4<T, A>& operator/= (TIntVector4<T, A>& v1, T s);

    /**
     * Stores the remainder of division by a scalar.
     *
     * @param(v1) Vector to divide with
     * @param(s) Scalar to divide with
     */

    template<IntType T, bool A>
    TIntVector4<T, A>& operator%= (TIntVector4<T, A>& v1, const TIntVector4<T, A>& v2);

    template<IntType T, bool A>
    TIntVector4<T, A>& operator%= (TIntVector4<T, A>& v1, T s);

    template<IntType T, bool A>
    inline TIntVector4<T, A>& operator&= (TIntVector4<T, A>& v1, const TIntVector4<T, A>& v2);

    template<IntType T, bool A>
    inline TIntVector4<T, A>& operator&= (TIntVector4<T, A>& v1, T s);

    template<IntType T, bool A>
    inline TIntVector4<T, A>& operator|= (TIntVector4<T, A>& v1, const TIntVector4<T, A>& v2);

    template<IntType T, bool A>
    inline TIntVector4<T, A>& operator|= (TIntVector4<T, A>& v1, T s);

    template<IntType T, bool A>
    inline TIntVector4<T, A> operator^= (TIntVector4<T, A>& v1, const TIntVector4<T, A>& v2);

    template<IntType T, bool A>
    inline TIntVector4<T, A>& operator^= (TIntVector4<T, A>& v1, T s);

    template<IntType T, bool A>
    inline TIntVector4<T, A>& operator<<= (TIntVector4<T, A>& v1, const TIntVector4<T, A>& v2);

    template<IntType T, bool A>
    inline TIntVector4<T, A>& operator<<= (TIntVector4<T, A>& v1, T s);

    template<IntType T, bool A>
    inline TIntVector4<T, A>& operator>>= (TIntVector4<T, A>& v1, const TIntVector4<T, A>& v2);

    template<IntType T, bool A>
    inline TIntVector4<T, A>& operator>>= (TIntVector4<T, A>& v1, T s);

    /**
     * Scale of Vector by floating point. (> Creates a new TIntVector4<T, A>)
     *
     * @param(v1) Vector to multiply with
     * @param(s Floating point to multiply with
     *
     * @return Result Vector
     */

    template<IntType T, bool A>
    TIntVector4<T, A> operator* (const TIntVector4<T, A>& v1, T s);

    /**
     * Division of Vector by floating point. (> Creates another TIntVector4<T, A>)
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
    TIntVector4<T, A> operator/ (const TIntVector4<T, A>& v1, T s);

    /**
     * Scale of Vector by floating point. (> Creates a new TIntVector4<T, A>)
     *
     * @param(v1) Vector to multiply with
     * @param(s Floating point to multiply with
     *
     * @return Result Vector
     */

    template<IntType T, bool A>
    FORCEINLINE TIntVector4<T, A> operator* (T s, const TIntVector4<T, A>& v1) { return v1 * s; };

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
    FORCEINLINE TIntVector4<T, A> operator/ (T s, const TIntVector4<T, A>& v1) { return v1 / s; };

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
    T operator* (const TIntVector4<T, A>& v1, const TIntVector4<T, A>& v2);

    /**
     * Componentwise addition of Vector with floating point.
     *
     * @param(v1) Vector to add to
     * @param(s Floating point to add
     *
     * @return Result Vector
     */

    template<IntType T, bool A>
    TIntVector4<T, A> operator+ (const TIntVector4<T, A>& v1, T s);

    /**
     * Componentwise addition of Vector with floating point.
     *
     * @param(v1) Vector to add to
     * @param(s Floating point to add
     *
     * @return Result Vector
     */

    template<IntType T, bool A>
    TIntVector4<T, A> operator+ (const TIntVector4<T, A>& v1, const TIntVector4<T, A>& v2);

    /**
     * Componentwise substraction of Vector with floating point.
     *
     * @param(v1) Vector to substract from
     * @param(s Floating point to substract
     *
     * @return Result Vector
     */

    template<IntType T, bool A>
    TIntVector4<T, A> operator- (const TIntVector4<T, A>& v1, T s);

    /**
     * Componentwise substraction of Vector with Vector.
     *
     * @param(v1) Vector to substract from
     * @param(s Floating point to substract
     *
     * @return Result Vector
     */

    template<IntType T, bool A>
    TIntVector4<T, A> operator- (const TIntVector4<T, A>& v1, const TIntVector4<T, A>& v2);




    /**
     * Scale of Vector by floating point. (> Creates a new TIntVector4<T, A>)
     *
     * @param(v1) Vector to multiply with
     * @param(s Floating point to multiply with
     *
     * @return Result Vector
     */

    template<IntType T, bool A>
    FORCEINLINE TIntVector4<T, A> operator% (const TIntVector4<T, A>& v1, const TIntVector4<T, A>& v2);

    template<IntType T, bool A>
    FORCEINLINE TIntVector4<T, A> operator% (const TIntVector4<T, A>& v1, T s);



    template<IntType T, bool A>
    inline TIntVector4<T, A> operator& (TIntVector4<T, A>& v1, const TIntVector4<T, A>& v2);

    template<IntType T, bool A>
    inline TIntVector4<T, A> operator& (TIntVector4<T, A>& v1, T s);

    template<IntType T, bool A>
    inline TIntVector4<T, A> operator| (TIntVector4<T, A>& v1, const TIntVector4<T, A>& v2);

    template<IntType T, bool A>
    inline TIntVector4<T, A> operator| (TIntVector4<T, A>& v1, T s);

    template<IntType T, bool A>
    inline TIntVector4<T, A> operator^ (TIntVector4<T, A>& v1, const TIntVector4<T, A>& v2);

    template<IntType T, bool A>
    inline TIntVector4<T, A> operator^ (TIntVector4<T, A>& v1, T s);

    template<IntType T, bool A>
    inline TIntVector4<T, A> operator<< (TIntVector4<T, A>& v1, const TIntVector4<T, A>& v2);

    template<IntType T, bool A>
    inline TIntVector4<T, A> operator<< (TIntVector4<T, A>& v1, T s);

    template<IntType T, bool A>
    inline TIntVector4<T, A> operator>> (TIntVector4<T, A>& v1, const TIntVector4<T, A>& v2);

    template<IntType T, bool A>
    inline TIntVector4<T, A> operator>> (TIntVector4<T, A>& v1, T s);

    template<IntType T, bool A>
    inline TIntVector4<T, A> operator~ (TIntVector4<T, A>& v1);


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
    bool operator== (const TIntVector4<T, A>& v1, const TIntVector4<T, A>& v2);


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
    bool operator!= (const TIntVector4<T, A>& v1, const TIntVector4<T, A>& v2);




    // ========================= //
    //   TIntVector4 functions   //
    // ========================= //


    template<IntType T>
    TIntVector4<T, false>& Set(TIntVector4<T, false>& v1, TIntVector4<T, false>& v2)
    {
        v1.x = v2.x;
        v1.y = v2.y;
        v1.z = v2.z;
        v1.w = v2.w;
        
        return v1;
    }


    /// <summary>
    /// Calculates the dot product between two vectors.
    /// </summary>
    /// <typeparam name="T">Type of vector</typeparam>
    /// <typeparam name="A">Vector is aligned?</typeparam>
    /// <param name="v1">Vector one</param>
    /// <param name="v2">Vector two</param>
    /// <returns>Dot product between vectors.</returns>
    template<IntType T>
    T DotP(const TIntVector4<T, false>& v1, const TIntVector4<T, false>& v2)
    {
        return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z + v1.w * v2.w;
    }

    /// <summary>
    /// Gets componentwise max of both vectors.
    /// </summary>
    /// <typeparam name="T">Type of vector</typeparam>
    /// <typeparam name="A">Vector is aligned?</typeparam>
    /// <param name="v1">Vector one</param>
    /// <param name="v2">Vector two</param>
    /// <returns>Vector with componentwise max of both vectors.</returns>
    template<IntType T>
    TIntVector4<T, false> Max(const TIntVector4<T, false>& v1, const TIntVector4<T, false>& v2)
    {
        return TIntVector4<T, false>(
            (v1.x > v2.x) ? v1.x : v2.x,
            (v1.y > v2.y) ? v1.y : v2.y,
            (v1.z > v2.z) ? v1.z : v2.z,
            (v1.w > v2.w) ? v1.w : v2.w
        );
    }

    /// <summary>
    /// Gets componentwise max of both vectors.
    /// </summary>
    /// <typeparam name="T">Type of vector</typeparam>
    /// <typeparam name="A">Vector is aligned?</typeparam>
    /// <param name="v1">Vector one</param>
    /// <param name="v2">Vector two</param>
    /// <returns>Copy of v1.</returns>
    template<IntType T>
    TIntVector4<T, false>& MaxV(TIntVector4<T, false>& v1, const TIntVector4<T, false>& v2)
    {
        v1.x = (v1.x > v2.x) ? v1.x : v2.x;
        v1.y = (v1.y > v2.y) ? v1.y : v2.y;
        v1.z = (v1.z > v2.z) ? v1.z : v2.z;
        v1.w = (v1.w > v2.w) ? v1.w : v2.w;

        return v1;
    }

    /// <summary>
    /// Gets componentwise min of both vectors.
    /// </summary>
    /// <typeparam name="T">Type of vector</typeparam>
    /// <typeparam name="A">Vector is aligned?</typeparam>
    /// <param name="v1">Vector one</param>
    /// <param name="v2">Vector two</param>
    /// <returns>Vector with componentwise max of both vectors.</returns>
    template<IntType T>
    TIntVector4<T, false> Min(const TIntVector4<T, false>& v1, const TIntVector4<T, false>& v2)
    {
        return TIntVector4<T, false>(
            (v1.x < v2.x) ? v1.x : v2.x,
            (v1.y < v2.y) ? v1.y : v2.y,
            (v1.z < v2.z) ? v1.z : v2.z,
            (v1.w < v2.w) ? v1.w : v2.w
        );
    }

    /// <summary>
    /// Gets componentwise min of both vectors.
    /// </summary>
    /// <typeparam name="T">Type of vector</typeparam>
    /// <typeparam name="A">Vector is aligned?</typeparam>
    /// <param name="v1">Vector one</param>
    /// <param name="v2">Vector two</param>
    /// <returns>Copy of v1.</returns>
    template<IntType T>
    TIntVector4<T, false>& MinV(TIntVector4<T, false>& v1, const TIntVector4<T, false>& v2)
    {
        v1.x = (v1.x < v2.x) ? v1.x : v2.x;
        v1.y = (v1.y < v2.y) ? v1.y : v2.y;
        v1.z = (v1.z < v2.z) ? v1.z : v2.z;
        v1.w = (v1.w < v2.w) ? v1.w : v2.w;

        return v1;
    }

    /// <summary>
    /// Inverses vector.
    /// </summary>
    /// <typeparam name="T">Type of vector</typeparam>
    /// <typeparam name="A">Vector is aligned?</typeparam>
    /// <param name="v1">Vector</param>
    /// <returns>Inverted vector</returns>
    template<IntType T>
    TIntVector4<T, false> Negate(const TIntVector4<T, false>& v1)
    {
        return TIntVector4<T, false>(
            -v1.x,
            -v1.y,
            -v1.z,
            -v1.w
        );
    }

    /// <summary>
    /// Inverses vector.
    /// </summary>
    /// <typeparam name="T">Type of vector</typeparam>
    /// <typeparam name="A">Vector is aligned?</typeparam>
    /// <param name="v1">Vector</param>
    /// <returns>Copy of v1.</returns>
    template<IntType T>
    TIntVector4<T, false>& NegateV(TIntVector4<T, false>& v1)
    {
        v1.x = -v1.x;
        v1.y = -v1.y;
        v1.z = -v1.z;
        v1.w = -v1.w;
        
        return v1;
    }
    
    /// <summary>
    /// Get signs of components.
    /// <para>
    /// + -> +1
    /// </para>
    /// x -> -1
    /// </summary>
    /// <typeparam name="T">Type of vector</typeparam>
    /// <typeparam name="A">Vector is aligned?</typeparam>
    /// <returns>Vector with signs of components.</returns>
    template<IntType T>
    TIntVector4<T, false> SignVector(TIntVector4<T, false>& v1)
    {
        return TIntVector4<T, false>(
            (v1.x > 0) ? 1 : -1,
            (v1.y > 0) ? 1 : -1,
            (v1.z > 0) ? 1 : -1,
            (v1.w > 0) ? 1 : -1
        );
    }

    /// <summary>
    /// Get signs of components.
    /// <param>
    /// + -> +1
    /// </param>
    /// x -> -1
    /// </summary>
    /// <typeparam name="T">Type of vector</typeparam>
    /// <returns></returns>
    template<IntType T>
    TIntVector4<T, false>& SignVectorV(TIntVector4<T, false>& v1)
    {
        v1.x = (v1.x > 0) ? 1 : -1;
        v1.y = (v1.y > 0) ? 1 : -1;
        v1.z = (v1.z > 0) ? 1 : -1;
        v1.w = (v1.w > 0) ? 1 : -1;

        return v1;
    }

    /// <summary>
    /// Test if two vectors are perpendicular.
    /// </summary>
    /// <typeparam name="T">Type of vector</typeparam>
    /// <param name="v1"></param>
    /// <param name="v2"></param>
    /// <returns>True if perpendicular.</returns>
    template<IntType T>
    inline bool IsPerpendicular(const TIntVector4<T, false>& v1, const TIntVector4<T, false>& v2)
    {
        return (abs(DotP(v1, v2)) == 0);
    }

} // phanes::core::math::coretypes


#endif // !INTVECTOR3_H


#include "Core/public/Math/IntVector4.inl"