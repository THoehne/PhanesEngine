#pragma once

#include "Core/Core.h"

#include "Core/public/Misc/Boilerplate.h"

#include "Core/public/Math/MathCommon.h"
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

		TIntVector2(const TIntVector2<T>& v);

		/**
		 * Move constructor
		 */

		TIntVector2(TIntVector2<T>&& v);

		/**
		 * Convert other type of vector
		 */

		template<IntType OtherIntType>
		explicit TIntVector2(const TIntVector2<OtherIntType>& v) : x((T)v.x), y((T)v.y) {};

		template<RealType Real>
		explicit TIntVector2(const TVector2<Real>& v) : x((T)v.x), y((T)v.y) {};

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

		TIntVector2(const TIntVector3<T>& v);

		/**
		 * Construct Vector from 4D integer Vector's xy.
		 *
		 * @param v 4D IntVector to copy from
		 */

		//TIntVector2(const TIntVector4<IntType>& v);

		/**
		 * Construct Vector from 2D Point's xy.
		 *
		 * @param v 2D Point to copy from
		 */

		//TIntVector2(const TIntPoint2<IntType>& v);


		/**
		 * Constructs a vector pointing from start to end.
		 *
		 * @param(start) Startingpoint
		 * @param(end) Endpoint
		 */

		TIntVector2(const TIntPoint2<T>& start, const TIntPoint2<T>& end);
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
	TIntVector2<T> operator+= (TIntVector2<T>& v1, T s);

	/**
	 * Addition operation on same TIntVector2<T> (this) by a another TIntVector2<T>.
	 *
	 * @param(v1) Vector to add to
	 * @param(v2) Vector to add
	 */

	template<IntType T>
	TIntVector2<T> operator+= (TIntVector2<T>& v1, const TIntVector2<T>& v2);

	/**
	 * Substraction operation on same TIntVector2<T> (this) by a floating point.
	 *
	 * @param(v1) Vector to substract from
	 * @param(v2) Floating point to substract
	 */

	template<IntType T>
	TIntVector2<T> operator-= (TIntVector2<T>& v1, T s);

	/**
	 * Substraction operation on same TIntVector2<T> (this) by a another TIntVector2<T>.
	 *
	 * @param(v1) Vector to substract from
	 * @param(v2) Vector to substract
	 */

	template<IntType T>
	TIntVector2<T> operator-= (TIntVector2<T>& v1, const TIntVector2<T>& v2);

	/**
	 * Multiplication of TIntVector2<T> (this) with a floating point.
	 *
	 * @param(v1) Vector to multiply with
	 * @param(s Floating point to multiply with
	 */

	template<IntType T>
	TIntVector2<T> operator*= (TIntVector2<T>& v1, T s);

	/**
	 * Devision of Vector (this) by floating point.
	 *
	 * @param(v1) Vector to divide with
	 * @param(s Floating point to divide with
	 */

	template<IntType T>
	TIntVector2<T> operator/= (TIntVector2<T>& v1, T s) = delete;

	/**
	 * Scale of Vector by floating point. (> Creates a new TIntVector2<T>)
	 *
	 * @param(v1) Vector to multiply with
	 * @param(s Floating point to multiply with
	 *
	 * @return Result Vector
	 */

	template<IntType T>
	TIntVector2<T> operator* (const TIntVector2<T>& v1, T s);

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
	TIntVector2<T> operator/ (const TIntVector2<T>& v1, T s) = delete;

	/**
	 * Scale of Vector by floating point. (> Creates a new TIntVector2<T>)
	 *
	 * @param(v1) Vector to multiply with
	 * @param(s Floating point to multiply with
	 *
	 * @return Result Vector
	 */

	template<IntType T>
	inline TIntVector2<T> operator* (T s, const TIntVector2<T>& v1);

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
	inline TIntVector2<T> operator/ (T s, const TIntVector2<T>& v1) = delete;

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

	template<IntType T, IntType Rt = float>
	Rt operator* (const TIntVector2<T>& v1, const TIntVector2<T>& v2);

	/**
	 * Componentwise addition of Vector with floating point.
	 *
	 * @param(v1) Vector to add to
	 * @param(s Floating point to add
	 *
	 * @return Result Vector
	 */

	template<IntType T>
	TIntVector2<T> operator+ (const TIntVector2<T>& v1, T s);

	/**
	 * Componentwise addition of Vector with floating point.
	 *
	 * @param(v1) Vector to add to
	 * @param(s Floating point to add
	 *
	 * @return Result Vector
	 */

	template<IntType T>
	TIntVector2<T> operator+ (const TIntVector2<T>& v1, const TIntVector2<T>& v2);

	/**
	 * Componentwise substraction of Vector with floating point.
	 *
	 * @param(v1) Vector to substract from
	 * @param(s Floating point to substract
	 *
	 * @return Result Vector
	 */

	template<IntType T>
	TIntVector2<T> operator- (const TIntVector2<T>& v1, T s);

	/**
	 * Componentwise substraction of Vector with Vector.
	 *
	 * @param(v1) Vector to substract from
	 * @param(s Floating point to substract
	 *
	 * @return Result Vector
	 */

	template<IntType T>
	TIntVector2<T> operator- (const TIntVector2<T>& v1, const TIntVector2<T>& v2);

	/**
	 * Negate Vector.
	 *
	 * @param(v1) Vector to negate
	 */

	template<IntType T>
	void operator- (TIntVector2<T>& v1);

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
	bool operator== (const TIntVector2<T>& v1, const TIntVector2<T>& v2);


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
	bool operator!= (const TIntVector2<T>& v1, const TIntVector2<T>& v2);

	// ============================================== //
	//    IntVector2 static function implementation	  //
	// ============================================== //

	/**
	 * Magnitude of Vector
	 *
	 * @param(v1) Vector
	 *
	 * @return Size of Vector
	 */

	template<IntType T, IntType Rt = float>
	Rt Magnitude(const TIntVector2<T>& v1);

	/**
	 * @see [FUNC]Magnitude
	 */
	template<IntType T, IntType Rt = float>
	FORCEINLINE Rt Length(const TIntVector2<T>& v1) { return Magnitude(v1); };

	/**
	 * Square of magnitude of Vector
	 *
	 * @param(v1) Vector
	 *
	 * @return Magnitude without calculating square root
	 */

	template<IntType T>
	T SqrMagnitude(const TIntVector2<T>& v1);

	/**
	 * @see [FUNC]SqrMagnitude
	 */
	template<IntType T>
	FORCEINLINE T SqrLength(const TIntVector2<T>& v1) { return SqrMagnitude(v1); };


	/**
	 * Divide vector and truncate result.
	 * 
	 * @param(v1) Vector to divide
	 * @param(s) Number to divide with
	 * 
	 * @note Rt is the type of the reciprocal of s.
	 */
	
	template<IntType T, RealType Rt = float>
	TIntVector2<T> DivideTruncV(TIntVector2<T>& v1, T s);

	/**
	 * Angle between to Vectors
	 *
	 * @param(v1) Vector one
	 * @param(v2) Vector two
	 */

	template<IntType T, RealType Rt = float>
	Rt Angle(const TIntVector2<T>& v1, const TIntVector2<T>& v2);

	/**
	 * Cosine of angle between to Vectors
	 *
	 * @param(v1) Vector one
	 * @param(v2) Vector two
	 */

	template<IntType T, RealType Rt = float>
	Rt CosineAngle(const TIntVector2<T>& v1, const TIntVector2<T>& v2);

	/**
	 * Returns signs of components in vector: -1 / +1 / 0.
	 *
	 * @param(v1) Vector one
	 */

	template<IntType T>
	TIntVector2<T> SignVectorV(TIntVector2<T>& v1);

	/**
	 * Dot product of two Vectors
	 *
	 * @param(v1) Vector one
	 * @param(v2) Vector two
	 */

	template<IntType T>
	T DotP(const TIntVector2<T>& v1, const TIntVector2<T>& v2);

	/**
	 * Creates Vector, with component wise largest values.
	 *
	 * @param(v1) Vector one
	 * @param(v2) Vector two
	 *
	 * @note Stores new Vector to v1
	 */

	template<IntType T>
	TIntVector2<T> MaxV(TIntVector2<T>& v1, const TIntVector2<T>& v2);

	/**
	 * Creates Vector, with component wise smallest values.
	 *
	 * @param(v1) Vector one
	 * @param(v2) Vector two
	 *
	 * @note Stores new Vector to v1
	 */

	template<IntType T>
	TIntVector2<T> MinV(TIntVector2<T>& v1, const TIntVector2<T>& v2);

	/**
	 * Gets perpendicular Vector to v1.
	 *
	 * @param(v1) Vector one
	 *
	 * @note Stores new Vector to v1
	 */

	template<IntType T>
	TIntVector2<T> GetPerpendicularV(TIntVector2<T>& v1);

	/**
	 * Gets perpendicular Vector to v1.
	 *
	 * @reg [FUNC]PerpendicularV
	 *
	 * @param(v1) Vector one
	 *
	 * @note Stores new Vector to v1
	 */

	template<IntType T>
	TIntVector2<T> GetReversePerpendicularV(TIntVector2<T>& v1);

	/**
	 * Component wise multiplication of Vector
	 *
	 * @param(v1) Vector one
	 * @param(v2) Vector two
	 *
	 * @note Stores new Vector to v1
	 */

	template<IntType T>
	TIntVector2<T> ScaleV(TIntVector2<T>& v1, const TIntVector2<T>& v2);

	/**
	 * Copies one Vector two another
	 *
	 * @param(v1) Vector to copy to
	 * @param(v2) Vector to copy
	 */

	template<IntType T>
	TIntVector2<T> Set(TIntVector2<T>& v1, const TIntVector2<T>& v2);

	/**
	 * Sets components of a vector.
	 *
	 * @param(v1) Vector to copy to
	 * @param(v2) Vector to copy
	 */

	template<IntType T>
	TIntVector2<T> Set(TIntVector2<T>& v1, T x, T y);


	/**
	 * Negates Vector
	 *
	 * @param(v1) Vector one
	 */

	template<IntType T>
	TIntVector2<T> NegateV(TIntVector2<T>& v1);

	/**
	 * Tests if vector is a unity vector.
	 *
	 * @param(v1) Vector one
	 *
	 * @return true if unit vector, false if not
	 */

	template<IntType T>
	inline bool IsNormalized(const TIntVector2<T>& v1);

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
	inline bool IsPerpendicular(const TIntVector2<T>& v1, const TIntVector2<T>& v2);

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
	inline bool IsParallel(const TIntVector2<T>& v1, const TIntVector2<T>& v2);

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
	inline bool IsCoincident(const TIntVector2<T>& v1, const TIntVector2<T>& v2);

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


	// ============================================================= //
	//   IntVector2 static function implementation with return values   // 
	// ============================================================= //


	/**
	 * Reflects a vector on a normal
	 *
	 * @param(v1) Vector one
	 * @param(normal) Normal of surface
	 *
	 * @return Reflected vector
	 */

	template<IntType T, RealType Rt = float>
	TVector2<Rt> Reflect(const TIntVector2<T>& v1, const TVector2<Rt>& normal);

	/**
	 * Scales a vector component wise
	 *
	 * @param(v1) Vector one
	 * @param(v2) Vector two
	 *
	 * @return Reflected vector
	 */

	template<IntType T>
	TIntVector2<T> Scale(const TIntVector2<T>& v1, const TIntVector2<T>& v2);

	/**
	 * Componentwise inverse of a vector
	 *
	 * @param(v1) Vector one
	 *
	 * @return Componentwise inverted, floating point vector
	 */

	template<IntType T, RealType Rt = float>
	TVector2<Rt> CompInverse(const TIntVector2<T>& v1);


	/**
	 * Negates Vector
	 *
	 * @param(v1) Vector one
	 *
	 * @return Componentwise inverted vector
	 */

	template<IntType T>
	TIntVector2<T> Negate(const TIntVector2<T>& v1);

	/**
	 * Gets the perpendicular vector of v1
	 *
	 * @param(v1) Vector one
	 *
	 * @return Perpendicular vector
	 */

	template<IntType T>
	TIntVector2<T> GetPerpendicular(const TIntVector2<T>& v1);

	/**
	 * Gets reverse of the perpendicular vector of v1
	 *
	 * @param(v1) Vector one
	 *
	 * @return Reversed perpendicular vector
	 */

	template<IntType T>
	TIntVector2<T> GetReversePerpendicular(const TIntVector2<T>& v1);

	/**
	 * Creates a new Vector by the component wise minimals of both vectors
	 *
	 * @param(v1) Vector one
	 * @param(v2) Vector two
	 *
	 * @return Minimal vector
	 */

	template<IntType T>
	TIntVector2<T> Min(const TIntVector2<T>& v1, const TIntVector2<T>& v2);

	/**
	 * Creates a new Vector by the component wise maxima of both vectors
	 *
	 * @param(v1) Vector one
	 * @param(v2) Vector two
	 *
	 * @return Maximal vector
	 */

	template<IntType T>
	TIntVector2<T> Max(const TIntVector2<T>& v1, const TIntVector2<T>& v2);

	/**
	 * Creates a normalized instance of the vector
	 *
	 * @param(v1) Vector to normalize
	 *
	 * @return Unit vector
	 * @note Returns floating point vector.
	 */

	template<IntType T, RealType Rt = float>
	TVector2<Rt> Normalize(const TIntVector2<T>& v1);

	/**
	 * Creates a normalized instance of the vector
	 *
	 * @param(v1) Vector to normalize
	 *
	 * @return Unit vector
	 * @note Does not test for zero vector
	 * @note Returns floating point vector.
	 */

	template<IntType T, RealType Rt = float>
	TVector2<Rt> UnsafeNormalize(const TIntVector2<T>& v1);

	/**
	 * Returns signs of components in vector: -1 / +1 / 0.
	 *
	 * @param(v1) Vector one
	 *
	 * @return Vector with signs as components
	 */

	template<IntType T>
	TIntVector2<T> SignVector(const TIntVector2<T>& v1);

	/**
	 * Binds a vector to a square with a radius
	 *
	 * @param(v1) Vector one
	 * @param(radius) Radius of square (=> Distance from middle to center of each site.)
	 *
	 * @return Bound, floating point vector
	 */

	template<IntType T, RealType Rt = float>
	TVector2<Rt> BindToSquare(const TIntVector2<T>& v1, T radius);

	/**
	 * Clamps a vector to a square with a radius
	 *
	 * @param(v1) Vector one
	 * @param(radius) Radius of square (=> Distance from middle to center of each site.)
	 *
	 * @return Clamped, floating point vector. If the length of the vector fits the square, then the vector is returned.
	 */

	template<IntType T, RealType Rt = float>
	TVector2<Rt> ClampToSquare(const TIntVector2<T>& v1, T radius);

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

	template<IntType T, RealType Rt = float>
	TVector2<Rt> Lerp(const TIntVector2<T>& startVec, const TIntVector2<T>& destVec, Rt t);

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

	template<IntType T, RealType Rt = float>
	TVector2<Rt> LerpUnclamped(const TIntVector2<T>& startVec, const TIntVector2<T>& destVec, Rt t);

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

	template<IntType T, RealType Rt = float>
	TVector2<Rt> Rotate(const TIntVector2<T>& v1, Rt angle);

	/**
	 * Clockwise vector rotation.
	 *
	 * @param(v1) Vector to rotate
	 *
	 * @return Rotated vector
	 *
	 * @note Angle is not clamped
	 */

	template<IntType T, RealType Rt = float>
	FORCEINLINE TVector2<Rt> ClockwiseRotate(const TIntVector2<T>& v1, Rt angle);

	/**
	 * Component wise division of Vector
	 *
	 * @param(v1) Vector one
	 * @param(s) Vector two
	 *
	 * @note Truncates result instead of rounding
	 * @note Rt is the type of the reciprocal of s.
	 */

	template<IntType T, RealType Rt = float>
	TIntVector2<T> DivideTrunc(const TIntVector2<T>& v1, T s);


	/**
	 * Component wise division of Vector
	 *
	 * @param(v1) Vector one
	 * @param(s) Vector two
	 *
	 * @return Floating point vector
	 */

	template<IntType T, RealType Rt = float>
	TVector2<Rt> DivideFloat(const TIntVector2<T>& v1, T s);

} // phanes::core::math::coretypes

#endif // !INTVECTOR2_H

