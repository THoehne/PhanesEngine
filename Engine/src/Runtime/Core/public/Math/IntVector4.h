#pragma once

#include "Misc/BoilerplateHeader.h"
#include PHANES_CORE_PCH_DEFAULT_PATH

#include "Math/MathCommon.h"
#include "Math/MathAbstractTypes.h"
#include "Math/MathFwd.h"


#ifndef P_DEBUG
#pragma warning(disable : 4244)
#endif


#ifndef INTVECTOR4_H
#define INTVECTOR4_H

namespace phanes::core::math::coretypes {

	/**
	 * A 4D Vector with components x, y, z and w with integer precision.
	 */

	template<typename T>
	struct IntVector4 {

		static_assert(std::is_integral_v(T), "T must be an integer type.");

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
				T x = &components[1];

				/** Y component of Vector
				 *
				 * @ref [FIELD]components
				 *
				 * @note y does not hold the component, but is a reference two the second item in the components array. The varibale exists wholly for convenience.
				 */
				T y = &components[1];

				/** Z component of Vector
				 *
				 * @ref [FIELD]components
				 *
				 * @note z does not hold the component, but is a reference two the second item in the components array. The varibale exists wholly for convenience.
				 */
				T z = &components[2];

				/** W component of Vector
				 *
				 * @ref [FIELD]components
				 *
				 * @note w does not hold the component, but is a reference two the second item in the components array. The varibale exists wholly for convenience.
				 */
				T w = &components[3];

			};

			/** Components array holding the data
			 *
			 * @ref [FIELD]x
			 * @ref [FIELD]y
			 * @ref [FIELD]z
			 * @ref [FIELD]w
			 *
			 * @note Components are split into x, y, z and w. Access and manipulation is possible by these variables.
			 */

			T components[4];
		};


	public:

		/**
		 * Default constructor without initialization
		 */

		PHANES_CORE_API IntVector4() = default;


		/**
		 * Construct Vector from xy components.
		 *
		 * @param x X component
		 * @param y Y component
		 * @param z Z component
		 * @param w W component
		 */

		PHANES_CORE_API IntVector4(const T x, const T y, const T z, const T w);

		/**
		 * Construct Vector from two component array.
		 *
		 * @param comp Array of components
		 */

		PHANES_CORE_API IntVector4(const T comp[4]);

		/**
		* Construct Vector from 2D Vector's xy and the last two zero.
		*
		* @param v 2D IntVector to copy from
		*/

		PHANES_CORE_API IntVector4(const Vector2<T>& v);

		/**
		 * Construct Vector from 3D Vector's xyz and zero.
		 *
		 * @param v 3D Vector to copy from
		 */


		PHANES_CORE_API IntVector4(const Vector3<T>& v);

		/**
		 * Construct Vector from 4D Vector's xyzw.
		 *
		 * @param v 4D Vector to copy from
		 */

		PHANES_CORE_API IntVector4(const Vector4<T>& v);


		/**
		 * Construct Vector from 2D integer Vector's xy and the last two zero.
		 *
		 * @param v 3D IntVector to copy from
		 */

		PHANES_CORE_API IntVector4(const IntVector2<T>& v);

		/**
		 * Construct Vector from 4D integer Vector's xyz and zero.
		 *
		 * @param v 4D IntVector to copy from
		 */

		PHANES_CORE_API IntVector4(const IntVector3<T>& v);

		/**
		 * Construct Vector from 3D Point's xyzw.
		 *
		 * @param v 3D Point to copy from
		 */

		PHANES_CORE_API IntVector4(const IntPoint4<T>& v);


	};


	// List of IntVector4 for DoP and ECS

	// List of 4D Vectors using int
	using IntVector4List = std::vector <IntVector4<int>>;



	// ======================== //
	//   IntVector4 operators   //
	// ======================== //



	/**
	 * Addition operation on same IntVector4 (this) by a integer value.
	 *
	 * @param a Vector to add to
	 * @param s integer to add
	 */

	template<typename T>
	INLINE PHANES_CORE_API void operator+= (IntVector4<T>& a, T s);


	/**
	 * Addition operation on same IntVector4 (this) by a another IntVector4.
	 *
	 * @param a Vector to add to
	 * @param b Vector to add
	 */

	template<typename T>
	INLINE PHANES_CORE_API void operator+= (IntVector4<T>& a, const IntVector4<T>& b);


	/**
	 * Substraction operation on same IntVector4 (this) by a integer.
	 *
	 * @param a Vector to substract from
	 * @param b integer to substract
	 */

	template<typename T>
	INLINE PHANES_CORE_API void operator-= (IntVector4<T>& a, T s);


	/**
	 * Substraction operation on same IntVector4 (this) by a another IntVector4.
	 *
	 * @param a Vector to substract from
	 * @param b Vector to substract
	 */

	template<typename T>
	INLINE PHANES_CORE_API void operator-= (IntVector4<T>& a, const IntVector4<T>& b);


	/**
	 * Multiplication of IntVector4 (this) with a integer. (Scale)
	 *
	 * @param a Vector to multiply with
	 * @param s integer to multiply with
	 */

	template<typename T>
	INLINE PHANES_CORE_API void operator*= (IntVector4<T>& a, T s);


	/**
	 * Devision of Vector (this) by integer.
	 *
	 * @ref [FUNC]DivideTruncV
	 * @ref [FUNC]DivideFloatV
	 *
	 * @param a Vector to multiply with
	 * @param s integer to divide with
	 *
	 * @note Rounds components
	 */

	template<typename T>
	INLINE PHANES_CORE_API void operator/= (IntVector4<T>& a, T s);


	/**
	 * Componentwise divison of Vector (this) by another vector
	 *
	 * @ref [FUNC]DivideTruncV
	 * @ref [FUNC]DivideFloatV
	 *
	 * @param a Vector to multiply with
	 * @param b Vector to divide with
	 *
	 * @note Rounds components
	 */

	template<typename T>
	INLINE PHANES_CORE_API void operator/= (IntVector4<T>& a, const IntVector4<T>& b);


	/**
	 * Scale of Vector by integer. (> Creates a new IntVector4)
	 *
	 * @param a Vector to multiply with
	 * @param s integer to multiply with
	 *
	 * @return Result Vector
	 */

	template<typename T>
	INLINE PHANES_CORE_API IntVector4<T> operator* (const IntVector4<T>& a, T s);


	/**
	 * Scale of Vector by integer. (> Creates a new IntVector4)
	 *
	 * @param a Vector to multiply with
	 * @param s integer to multiply with
	 *
	 * @return Result Vector
	 */

	template<typename T>
	INLINE PHANES_CORE_API IntVector4<T> operator* (T s, const IntVector4<T>& a);


	/**
	 * Dot product between two Vectors.
	 *
	 * @ref [FUNC]DotP
	 *
	 * @param a Vector one
	 * @param b Vector two
	 *
	 * @result Dot product
	 */

	template<typename T>
	INLINE PHANES_CORE_API T operator* (const IntVector4<T>& a, const IntVector4<T>& b);


	/**
	 * Division of Vector by integer. (> Creates another IntVector4)
	 *
	 * @param a Vector to multiply with
	 * @param s integer to divide with
	 *
	 * @return Result Vector
	 */

	template<typename T>
	INLINE PHANES_CORE_API IntVector4<T> operator/ (const IntVector4<T>& a, T s);


	/**
	 * Division of Vector by integer. (> For convenience not arithmethicaly correct. Works like overloaded counterpart.)
	 *
	 * @ref [FUNC]DivideTrunc
	 * @ref [FUNC]DivideFloat
	 *
	 * @param a Vector to multiply with
	 * @param s integer to divide with
	 *
	 * @note Rounds components
	 *
	 * @return Result Vector
	 */

	template<typename T>
	INLINE PHANES_CORE_API IntVector4<T> operator/ (T s, const IntVector4<T>& a);


	/**
	 * Componentwise division of Vector (> For convenience not arithmethicaly correct. Works like overloaded counterpart.)
	 *
	 * @ref [FUNC]DivideTrunc
	 * @ref [FUNC]DivideFloat
	 *
	 * @param a Vector to multiply with
	 * @param s integer to divide with
	 *
	 * @note Rounds components
	 *
	 * @return Result Vector
	 */

	template<typename T>
	INLINE PHANES_CORE_API IntVector4<T> operator/ (const IntVector4<T>& a, const IntVector4<T>& b);


	/**
	 * Componentwise addition of Vector with integer.
	 *
	 * @param a Vector to add to
	 * @param s integer to add
	 *
	 * @return Result Vector
	 */

	template<typename T>
	INLINE PHANES_CORE_API IntVector4<T> operator+ (const IntVector4<T>& a, T s);


	/**
	 * Componentwise addition of Vector with integer.
	 *
	 * @param a Vector to add to
	 * @param s integer to add
	 *
	 * @return Result Vector
	 */

	template<typename T>
	INLINE PHANES_CORE_API IntVector4<T> operator+ (const IntVector4<T>& a, const IntVector4<T>& b);


	/**
	 * Componentwise substraction of Vector with integer.
	 *
	 * @param a Vector to substract from
	 * @param s integer to substract
	 *
	 * @return Result Vector
	 */

	template<typename T>
	INLINE PHANES_CORE_API IntVector4<T> operator- (const IntVector4<T>& a, T s);

	/**
	 * Componentwise substraction of Vector with Vector.
	 *
	 * @param a Vector to substract from
	 * @param s integer to substract
	 *
	 * @return Result Vector
	 */

	template<typename T>
	INLINE PHANES_CORE_API IntVector4<T> operator- (const IntVector4<T>& a, const IntVector4<T>& b);


	/**
	 * Negate Vector.
	 *
	 * @param a Vector to negate
	 */

	template<typename T>
	INLINE PHANES_CORE_API void operator- (IntVector4<T>& a);


	/**
	 * Compare Vector for equality.
	 *
	 * @ref [FUNC]Equals
	 *
	 * @param a Vector to negate
	 *
	 * @return true if equal, false if inequal
	 */

	template<typename T>
	INLINE PHANES_CORE_API bool operator== (const IntVector4<T>& a, const IntVector4<T>& b);


	/**
		* Compare Vector for inequality.
		*
		* @ref [FUNC]Equals
		*
		* @param a Vector to negate
		*
		* @return true if inequal, false if equal
		*/

	template<typename T>
	INLINE PHANES_CORE_API bool operator!= (const IntVector4<T>& a, const IntVector4<T>& b);


	// ============================================== //
	//    IntVector4 static function implementation	  //
	// ============================================== //

	/**
	 * Magnitude of Vector
	 *
	 * @param a Vector
	 *
	 * @return Size of Vector
	 */

	template<typename T>
	PHANES_CORE_API T Magnitude(const IntVector4<T>& a);


	/**
	 * Square of magnitude of Vector
	 *
	 * @param a Vector
	 *
	 * @return Magnitude without calculating square root
	 */

	template<typename T>
	PHANES_CORE_API T SqrMagnitude(const IntVector4<T>& a);


	/**
	 * Normalize Vector
	 *
	 * @param a Vector
	 */

	template<typename T>
	PHANES_CORE_API void NormalizeV(IntVector4<T>& a);


	/**
	 * Angle between to Vectors
	 *
	 * @param a Vector one
	 * @param b Vector two
	 */

	template<typename T>
	PHANES_CORE_API T Angle(const IntVector4<T>& a, const IntVector4<T>& b);


	/**
	 * Dot product of two Vectors
	 *
	 * @param a Vector one
	 * @param b Vector two
	 */

	template<typename T>
	PHANES_CORE_API T DotP(const IntVector4<T>& a, const IntVector4<T>& b);


	/**
	 * Creates Vector, with component wise largest values.
	 *
	 * @param a Vector one
	 * @param b Vector two
	 *
	 * @note Stores new Vector to a
	 */

	template<typename T>
	PHANES_CORE_API void MaxV(IntVector4<T>& a, const IntVector4<T>& b);


	/**
	 * Creates Vector, with component wise smallest values.
	 *
	 * @param a Vector one
	 * @param b Vector two
	 *
	 * @note Stores new Vector to a
	 */

	template<typename T>
	PHANES_CORE_API void MinV(IntVector4<T>& a, const IntVector4<T>& b);


	/**
	 * Gets perpendicular Vector to a.
	 *
	 * @reg NO_RETURN(ReversePerpendicular)
	 *
	 * @param a Vector one
	 *
	 * @note Stores new Vector to a
	 */

	template<typename T>
	PHANES_CORE_API void PerpendicularV(IntVector4<T>& a);


	/**
	 * Gets perpendicular Vector to a.
	 *
	 * @reg NO_RETURN(Perpendicular)
	 *
	 * @param a Vector one
	 *
	 * @note Stores new Vector to a
	 */

	template<typename T>
	PHANES_CORE_API void ReversePerpendicularV(IntVector4<T>& a);


	/**
	 * Component wise multiplication of Vector
	 *
	 * @param a Vector one
	 * @param b Vector two
	 *
	 * @note Stores new Vector to a
	 */

	template<typename T>
	PHANES_CORE_API void ScaleV(IntVector4<T>& a, const IntVector4<T>& b);


	/**
	 * Component wise division of Vector
	 *
	 * @param a Vector one
	 * @param b Vector two
	 *
	 * @note Truncates result instead of rounding
	 * @note Stores new Vector to a
	 */

	template<typename T>
	PHANES_CORE_API void DivideTruncV(IntVector4<T>& a, const IntVector4<T>& b);


	/**
	 * Component wise division of Vector
	 *
	 * @param a Vector one
	 * @param b Vector two
	 *
	 * @note Truncates result instead of rounding
	 * @note Stores new Vector to a
	 */

	template<typename T>
	PHANES_CORE_API void DivideTruncV(IntVector4<T>& a, T s);


	/**
	 * Componentwise inversion of Vector
	 *
	 * @param a Vector one
	 *
	 * @note Stores new Vector to a
	 */

	template<typename T>
	PHANES_CORE_API void CompInverseV(IntVector4<T>& a);


	/**
	 * Reflect Vector by normal vector.
	 *
	 * @param a Vector one
	 * @param b Vector two
	 *
	 * @note Stores new Vector to a
	 */

	template<typename T>
	PHANES_CORE_API void ReflectV(IntVector4<T>& a, const IntVector4<T>& normal);


	/**
	 * Copies one Vector two another
	 *
	 * @param a Vector to copy to
	 * @param b Vector to copy
	 */

	template<typename T>
	PHANES_CORE_API void Set(IntVector4<T>& a, const IntVector4<T>& b);


	/**
	 * Sets components of a vector.
	 *
	 * @param a Vector to copy to
	 * @param b Vector to copy
	 */

	template<typename T>
	PHANES_CORE_API void Set(IntVector4<T>& a, T x, T y, T z, T w);


	/**
	 * Tests if vector is a unity vector.
	 *
	 * @param a Vector one
	 * @param threshold Threshold to one
	 *
	 * @return true if unit vector, false if not
	 */

	template<typename T>
	PHANES_CORE_API bool IsNormalized(const IntVector4<T>& a, T threshold = P_FLT_INAC);

	/**
	 * Tests if 2 vectors are perpendicular to each other.
	 *
	 * @param a Vector one
	 * @param b Vector two
	 * @param threshold Threshold
	 *
	 * @return true if perpendicular, false if not
	 */

	template<typename T>
	PHANES_CORE_API bool IsPerpendicular(const IntVector4<T>& a, const IntVector4<T>& b, T threshold = P_FLT_INAC);


	/**
	 * Tests if 2 vectors are parallel to each other. (Angle is close to zero.)
	 *
	 * @param a Vector one
	 * @param b Vector two
	 * @param threshold Threshold
	 *
	 * @return true if parallel, false if not
	 */

	template<typename T>
	PHANES_CORE_API bool IsParallel(const IntVector4<T>& a, const IntVector4<T>& b, T threshold = P_FLT_INAC);

	/**
	 * Tests if 2 vectors are coincident. (Are parallel and point in the same direction.)
	 *
	 * @param a Vector one
	 * @param b Vector two
	 * @param threshold Threshold
	 *
	 * @return true if coincident, false if not
	 */

	template<typename T>
	PHANES_CORE_API bool IsCoincident(const IntVector4<T>& a, const IntVector4<T>& b, T threshold = P_FLT_INAC);


	/**
	 * Gets outer product of to vectors.
	 *
	 * @param a Vector one
	 * @param b Vector two
	 *
	 * @return Resulting matrix
	 */

	template<typename T>
	PHANES_CORE_API Matrix2<T> OuterProduct(const IntVector4<T>& a, const IntVector4<T>& b);


	// ================================================================ //
	//   IntVector4 static function implementation with return values   // 
	// ================================================================ //


	/**
	 * Reflects a vector on a normal
	 *
	 * @param a Vector one
	 * @param normal Normal vector
	 *
	 * @return Reflected vector
	 */

	template<typename T>
	PHANES_CORE_API IntVector4<T> Reflect(const IntVector4<T>& a, const IntVector4<T>& normal);


	/**
	 * Scales a vector component wise
	 *
	 * @param a Vector one
	 * @param b Vector two
	 *
	 * @return Reflected vector
	 */

	template<typename T>
	PHANES_CORE_API IntVector4<T> Scale(const IntVector4<T>& a, const IntVector4<T>& b);


	/**
	 * Component wise division of Vector
	 *
	 * @param a Vector one
	 * @param b Vector two
	 *
	 * @note Truncates result instead of rounding
	 */

	template<typename T>
	PHANES_CORE_API IntVector4<T> DivideTrunc(const IntVector4<T>& a, const IntVector4<T>& b);


	/**
	 * Component wise division of Vector
	 *
	 * @param a Vector one
	 * @param b Vector two
	 *
	 * @note Truncates result instead of rounding
	 */

	template<typename T>
	PHANES_CORE_API IntVector4<T> DivideTrunc(const IntVector4<T>& a, T s);


	/**
	 * Component wise division of Vector
	 *
	 * @param a Vector one
	 * @param b Vector two
	 *
	 * @return Floating point vector
	 */

	template<typename T>
	PHANES_CORE_API Vector2<T> DivideFloat(const IntVector4<T>& a, const IntVector4<T>& b);


	/**
	 * Component wise division of Vector
	 *
	 * @param a Vector one
	 * @param b Vector two
	 *
	 * @return Floating point vector
	 */

	template<typename T>
	PHANES_CORE_API Vector2<T> DivideFloat(const IntVector4<T>& a, T s);


	/**
	 * Componentwise inverse of Vector
	 *
	 * @param a Vector one
	 * @param b Vector two
	 *
	 * @return Reflected vector
	 */

	template<typename T>
	PHANES_CORE_API IntVector4<T> CompInverse(const IntVector4<T>& a);


	/**
	 * Gets the perpendicular vector of a
	 *
	 * @param a Vector one
	 *
	 * @return Perpendicular vector
	 */

	template<typename T>
	PHANES_CORE_API IntVector4<T> Perpendicular(const IntVector4<T>& a);


	/**
	 * Gets reverse of the perpendicular vector of a
	 *
	 * @param a Vector one
	 *
	 * @return Reversed perpendicular vector
	 */

	template<typename T>
	PHANES_CORE_API IntVector4<T> ReversePerpendicular(const IntVector4<T>& a);


	/**
	 * Creates a new Vector by the component wise minimals of both vectors
	 *
	 * @param a Vector one
	 * @param b Vector two
	 *
	 * @return Minimal vector
	 */

	template<typename T>
	PHANES_CORE_API IntVector4<T> Min(const IntVector4<T>& a, const IntVector4<T>& b);


	/**
	 * Creates a new Vector by the component wise maxima of both vectors
	 *
	 * @param a Vector one
	 * @param b Vector two
	 *
	 * @return Maximal vector
	 */

	template<typename T>
	PHANES_CORE_API IntVector4<T> Max(const IntVector4<T>& a, const IntVector4<T>& b);


	/**
	 * Creates a normalized instance of the vector
	 *
	 * @param a Vector to normalize
	 *
	 * @return Unit vector
	 */

	template<typename T>
	PHANES_CORE_API IntVector4<T> Normalize(const IntVector4<T>& a);


	/**
	 * Interpolates between to vectors.
	 *
	 * @param a Start value (t = 0)
	 * @param b End value (t = 1)
	 * @param t Interpolation value
	 *
	 * @return Interpolated vector
	 *
	 * @note Interpolation is clamped between 0 - 1.
	 */

	template<typename T>
	INLINE PHANES_CORE_API IntVector4<T> Lerp(const IntVector4<T>& a, const IntVector4<T>& b, T t);


	/**
	 * Interpolates between to vectors.
	 *
	 * @param a Start value (t = 0)
	 * @param b End value (t = 1)
	 * @param t Interpolation value
	 *
	 * @return Interpolated vector
	 *
	 * @note Interpolation is not clamped.
	 */

	template<typename T>
	INLINE PHANES_CORE_API IntVector4<T> LerpUnclamped(const IntVector4<T>& a, const IntVector4<T>& b, T t);


	/**
	 * Spherical interpolation between two vectors.
	 *
	 * @param a Start value (t = 0)
	 * @param b End value (t = 1)
	 * @param t Interpolation value
	 *
	 * @return Interpolated vector
	 *
	 * @note Interpolation is clamped between 0 - 1.
	 * @note Quaternion are more efficient and should be used if possible.
	 */

	template<typename T>
	PHANES_CORE_API IntVector4<T> Slerp(const IntVector4<T>& a, const IntVector4<T>& b, T t);


	/**
	 * Spherical interpolation between two vectors.
	 *
	 * @param a Start value (t = 0)
	 * @param b End value (t = 1)
	 * @param t Interpolation value
	 *
	 * @return Interpolated vector
	 *
	 * @note Interpolation is clamped between 0 - 1.
	 * @note Quaternion are more efficient and should be used if possible.
	 */

	template<typename T>
	PHANES_CORE_API IntVector4<T> SlerpUnclamped(const IntVector4<T>& a, const IntVector4<T>& b, T t);

} // phanes::core::math::coretypes

#endif // !INTVECTOR3_H

