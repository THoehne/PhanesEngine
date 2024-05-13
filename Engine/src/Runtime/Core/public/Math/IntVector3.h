#pragma once

#include "Core/public/Misc/Boilerplate.h"

#include "Core/public/Math/MathCommon.h"
#include "Core/public/Math/MathAbstractTypes.h"
#include "Core/public/Math/MathFwd.h"

#include "Core/public/Math/Vector3.h"

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

		TIntVector3(const TIntVector3<T>& v);

		/**
		 * Move constructor
		 */

		TIntVector3(TIntVector3<T>&& v);

		/**
		 * Convert other type of vector
		 */

		template<IntType OtherIntType>
		explicit TIntVector3(const TIntVector3<OtherIntType>& v) : x((T)v.x), y((T)v.y) {};

		template<RealType Real>
		explicit TIntVector3(const TVector3<Real>& v) : x((T)v.x), y((T)v.y) {};

		/**
		 * Construct Vector from xy components.
		 *
		 * @param x X component
		 * @param y Y component
		 * @param z Z component
		 */

		TIntVector3(const T x, const T y, const T z);

		/**
		 * Construct Vector from two component array.
		 *
		 * @param comp Array of components
		 */

		TIntVector3(const T* comp);

		/**
		 * Construct Vector from 3D integer Vector's xy.
		 *
		 * @param v 3D IntVector to copy from
		 */

		TIntVector3(const TIntVector2<T>& v);

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

		TIntVector3(const TIntPoint3<T>& start, const TIntPoint3<T>& end);

	};


	// ======================== //
	//   IntVector3 operators   //
	// ======================== //


	/**
	 * Coponentwise addition of floating point to 3D vector
	 *
	 * @param(v1) vector to add to
	 * @param(s) floating point to add
	 */

	template<IntType T>
	inline TIntVector3<T> operator+= (TIntVector3<T>& v1, T s);

	/**
	 * Coponentwise addition of 3D vector to 3D vector
	 *
	 * @param(v1) vector to add to
	 * @param(v2) vector to add
	 */

	template<IntType T>
	inline TIntVector3<T> operator+= (TIntVector3<T>& v1, const TIntVector3<T>& v2);

	/**
	 * Coponentwise substraction of floating point of 3D vector
	 *
	 * @param(v1) vector to substract from
	 * @param(s) floating point to substract
	 */

	template<IntType T>
	inline TIntVector3<T> operator-= (TIntVector3<T>& v1, T s);

	/**
	 * Coponentwise substraction of 3D vector to 3D vector
	 *
	 * @param(v1) vector to substract from
	 * @param(v2) vector to substract with
	 */

	template<IntType T>
	inline TIntVector3<T> operator-= (TIntVector3<T>& v1, const TIntVector3<T>& v2);

	/**
	 * Dot product between two 3D Vectors
	 *
	 * @param(v1) vector one
	 * @param(s) floating point
	 */

	template<IntType T>
	inline TIntVector3<T> operator*= (TIntVector3<T>& v1, T s);

	/**
	 * Coponentwise multiplication of 3D Vectors with floating point
	 *
	 * @param(v1) vector one
	 * @param(s) floating point
	 *
	 * @return Resulting vector
	 */

	template<IntType T>
	TIntVector3<T> operator* (const TIntVector3<T>& v1, T s);

	/**
	 * Coponentwise multiplication of 3D Vectors with floating point
	 *
	 * @param(s) floating point
	 * @param(v2) vector
	 *
	 * @return Resultion vector
	 */

	template<IntType T>
	inline TIntVector3<T> operator* (T s, const TIntVector3<T>& v1);

	/**
	 * Dot product between two 3D Vectors
	 *
	 * @param(v1) vector one
	 * @param(v2) vector two
	 *
	 * @return Dot product of Vectors
	 */

	template<IntType T>
	T operator* (const TIntVector3<T>& v1, const TIntVector3<T>& v2);

	/**
	 * Coponentwise addition of floating point to 3D vector
	 *
	 * @param(v1) vector to add to
	 * @param(s) floating point to add
	 *
	 * @return Resulting vector
	 */

	template<IntType T>
	TIntVector3<T> operator+ (const TIntVector3<T>& v1, T s);

	/**
	 * Coponentwise addition of 3D vector to 3D vector
	 *
	 * @param(v1) vector to add to
	 * @param(v2) vector to add
	 *
	 * @return Resulting vector
	 */

	template<IntType T>
	TIntVector3<T> operator+ (const TIntVector3<T>& v1, const TIntVector3<T>& v2);

	/**
	 * Coponentwise substraction of floating point of 3D vector
	 *
	 * @param(v1) vector to substract from
	 * @param(s) floating point to substract
	 *
	 * @return Resulting vector
	 */

	template<IntType T>
	TIntVector3<T> operator- (const TIntVector3<T>& v1, T s);

	/**
	 * Coponentwise substraction of floating point of 3D vector
	 *
	 * @param(v1) vector to substract from
	 * @param(v2) vector to substract with
	 *
	 * @return Resulting vector
	 */

	template<IntType T>
	TIntVector3<T> operator- (const TIntVector3<T>& v1, const TIntVector3<T>& v2);

	/**
	 * Negates vector
	 *
	 * @param(v1) Vector to negate
	 */

	template<IntType T>
	TIntVector3<T> operator- (TIntVector3<T>& v1);

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
	inline bool operator== (const TIntVector3<T>& v1, const TIntVector3<T>& v2);

	/**
	 * Tests two 3D vectors for inequality.
	 *
	 * @param(v1) Vector one
	 * @param(v2) Vector two
	 *
	 * @return True if inequal, false if not.
	 */

	template<IntType T>
	inline bool operator!= (const TIntVector3<T>& v1, const TIntVector3<T>& v2);

	// ============================================== //
	//    IntVector3 static function implementation	  //
	// ============================================== //

	/**
	 * Gets magnitude of vector
	 *
	 * @param(v1) Vector
	 *
	 * @return Magnitude of vector
	 */

	template<IntType T, RealType Rt = float>
	inline Rt Magnitude(const TIntVector3<T>& v1);

	/**
	 * @see [FUNC]Magnitude
	 */

	template<IntType T>
	FORCEINLINE T Length(const TIntVector3<T>& v1) { return Magnitude(v1); };

	/**
	 * Gets square magnitude of vector
	 *
	 * @param(v1) Vector
	 *
	 * @return Square magnitude of vector
	 */

	template<IntType T>
	inline T SqrMagnitude(const TIntVector3<T>& v1);

	/**
	 * @see SqrMagnitude
	 */

	template<IntType T>
	FORCEINLINE T SqrLength(const TIntVector3<T>& v1) { return SqrMagnitude(v1); };

	/**
	 * Gets angle between two vectors
	 *
	 * @param(v1) Vector one
	 * @param(v2) Vector two
	 *
	 * @return Angle between vectors
	 */

	template<IntType T, RealType Rt = float>
	Rt Angle(const TIntVector3<T>& v1, const TIntVector3<T>& v2);

	/**
	 * Dot product of two vectors
	 *
	 * @param(v1) Vector one
	 * @param(v2) Vector two
	 *
	 * @return Dot product of vectors
	 */

	template<IntType T>
	T DotP(const TIntVector3<T>& v1, const TIntVector3<T>& v2);

	/**
	 * Returns signs of components in vector: -1 / +1 / 0.
	 *
	 * @param(v1) Vector one
	 *
	 * @return Vector with signs a components.
	 */

	template<IntType T>
	TIntVector3<T> SignVector(const TIntVector3<T>& v1);

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
	inline bool Equals(const TIntVector3<T>& v1, const TIntVector3<T>& v2, T threshold = P_FLT_INAC);

	/**
	 * Calculates the cross product between two vectors.
	 *
	 * @param(v1) Vector one
	 * @param(v2) Vector two
	 *
	 * @note result is stored in v1.
	 */

	template<IntType T>
	TIntVector3<T> CrossPV(TIntVector3<T>& v1, const TIntVector3<T>& v2);

	/**
	 * Gets the componentwise max of both vectors.
	 *
	 * @param(v1) Vector one
	 * @param(v2) Vector two
	 *
	 * @note result is stored in v1.
	 */

	template<IntType T>
	TIntVector3<T> MaxV(TIntVector3<T>& v1, const TIntVector3<T>& v2);

	/**
	 * Gets the componentwise min of both vectors.
	 *
	 * @param(v1) Vector one
	 * @param(v2) Vector two
	 *
	 * @note result is stored in v1.
	 */

	template<IntType T>
	TIntVector3<T> MinV(TIntVector3<T>& v1, const TIntVector3<T>& v2);

	/**
	 * Gets reversed vector.
	 *
	 * @param(v1) Vector one
	 *
	 * @note result is stored in v1.
	 */

	template<IntType T>
	TIntVector3<T> NegateV(TIntVector3<T>& v1);

	/**
	 * Performes componentwise multiplication of two vectors.
	 *
	 * @param(v1) Vector one
	 * @param(v2) Vector two
	 *
	 * @note result is stored in v1.
	 */

	template<IntType T>
	TIntVector3<T> ScaleV(TIntVector3<T>& v1, const TIntVector3<T>& v2);

	/**
	 * Copies v1 vector
	 *
	 * @param(v1) Vector to copy to
	 * @param(v2) Vector to copy
	 */

	template<IntType T>
	TIntVector3<T> Set(TIntVector3<T>& v1, const TIntVector3<T>& v2);

	/**
	 * Sets vector.
	 *
	 * @param(v1) Vector to copy to
	 * @param(x) X component
	 * @param(y) Y component
	 * @param(z) Z component
	 */

	template<IntType T>
	TIntVector3<T> Set(TIntVector3<T>& v1, T x, T y, T z);

	/**
	 * Returns signs of components in vector: -1 / +1 / 0.
	 *
	 * @param(v1) Vector one
	 */

	template<IntType T>
	TIntVector3<T> SignVectorV(TIntVector3<T>& v1);


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
	T ScalarTriple(const TIntVector3<T>& v1, const TIntVector3<T>& v2, const TIntVector3<T>& v3);

	/**
	 * Gets the cosine of the angle between to vectors.
	 *
	 * @param(v1) Vector one
	 * @param(v2) Vector two
	 *
	 * @return Cosine of angle between vectors.
	 * @note Simply omits acos of angle.
	 */

	template<IntType T>
	T CosineAngle(const TIntVector3<T>& v1, const TIntVector3<T>& v2);

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
	TIntVector3<T> VectorTripleV(TIntVector3<T>& v1, const TIntVector3<T>& v2, const TIntVector3<T>& v3);

	/**
	 * Tests whether two vectors are perpendicular.
	 *
	 * @param(v1) Vector one
	 * @param(v2) Vector two
	 * @param(threshold) Allowed T inaccuracy
	 *
	 * @return True if perpendicular, false if not.
	 */

	template<IntType T>
	inline bool IsPerpendicular(const TIntVector3<T>& v1, const TIntVector3<T>& v2, T threshold = P_FLT_INAC);

	/**
	 * Tests whether two vectors are parallel.
	 *
	 * @param(v1) Vector one
	 * @param(v2) Vector two
	 * @param(threshold) Allowed T inaccuracy from one (e.g. 0.98f)
	 *
	 * @return True if parallel, false if not.
	 */

	template<IntType T>
	inline bool IsParallel(const TIntVector3<T>& v1, const TIntVector3<T>& v2, T threshold = 1.0f - P_FLT_INAC);

	/**
	 * Tests whether two vectors are coincident (Parallel and point in same direction).
	 *
	 * @param(v1) Vector one
	 * @param(v2) Vector two
	 * @param(threshold) Allowed T inaccuracy from one (e.g. 0.98f)
	 *
	 * @return True if coincident, false if not.
	 */

	template<IntType T>
	inline bool IsCoincident(const TIntVector3<T>& v1, const TIntVector3<T>& v2, T threshold = 1.0f - P_FLT_INAC);

	/**
	 * Tests whether v1 vectors is v1 unit vector.
	 *
	 * @param(v1) Vector
	 * @param(threshold) Allowed T inaccuracy
	 *
	 * @return True if unit vector, false if not.
	 */

	template<IntType T>
	inline bool IsNormalized(const TIntVector3<T>& v1, T threshold = P_FLT_INAC);

	/**
	 * Tests if three vectors are coplanar
	 *
	 * @param(v1) Vector one
	 * @param(v2) Vector two
	 * @param(v3) Vector three
	 * @param(threshold) Allowed T inaccuracy
	 *
	 * @return True if coplanar, false if not.
	 */

	template<IntType T>
	inline bool IsCoplanar(const TIntVector3<T>& v1, const TIntVector3<T>& v2, const TIntVector3<T>& v3, T threshold = P_FLT_INAC);


	/**
	 * Gets outer product of to vectors.
	 *
	 * @param a Vector one
	 * @param b Vector two
	 *
	 * @return Resulting matrix
	 */

	//template<IntType T>
	//Matrix3<T> OuterProduct(const IntVector3<T>& a, const IntVector3<T>& b);


	// ================================================================ //
	//   IntVector3 static function implementation with return values   // 
	// ================================================================ //

	/**
	 * Normalized vector
	 *
	 * @param(v1) vector to normalize
	 *
	 * @return Normalized vector
	 */

	template<IntType T, RealType Rt = float>
	TVector3<Rt> Normalize(const TIntVector3<T>& v1);

	/**
	 * Normalizes vector
	 *
	 * @param(v1) Vector
	 *
	 * @note Does not test for zero vector
	 */

	template<IntType T, RealType Rt = float>
	TVector3<Rt> UnsafeNormalize(const TIntVector3<T>& v1);

	/**
	 * Reflects a vector on a surface
	 *
	 * @param(v1) Vector one
	 * @param(normal) Normal of surface
	 *
	 * @return Reflected vector
	 */

	template<IntType T, RealType Rt = float>
	TVector3<Rt> Reflect(const TIntVector3<T>& v1, const TVector3<Rt>& normal);


	/**
	 * Performes perspective divide on vector.
	 *
	 * @param(v1) vector to perspective divide
	 *
	 * @return Perspective divided vector
	 */

	template<IntType T, RealType Rt = float>
	TVector3<Rt> PerspectiveDivide(const TIntVector3<T>& v1);

	/**
	 * Gets cross product between two vectors.
	 *
	 * @param(v1) vector one
	 * @param(v2) vector two
	 *
	 * @return Cross product of v1 and v2
	 */

	template<IntType T>
	TIntVector3<T> CrossP(const TIntVector3<T>& v1, const TIntVector3<T>& v2);

	/**
	 * Linearly interpolates between two vectors.
	 *
	 * @param(start) Starting vector
	 * @param(dest) Destination vector
	 * @param(t) 0.0 to 1.0 interpolation value
	 *
	 * @return Cross product of v1 and v2
	 */

	template<IntType T, RealType Rt = float>
	TVector3<Rt> Lerp(const TIntVector3<T>& start, const TIntVector3<T>& dest, Rt t);

	/**
	 * Linearly interpolates between two vectors.
	 *
	 * @param(v1) Starting vector
	 * @param(dest) Destination vector
	 * @param(t) 0.0 to 1.0 interpolation value
	 *
	 * @return Cross product of v1 and v2
	 * @note Does not clamp t between 0.0 and 1.0.
	 */

	template<IntType T, RealType Rt = float>
	TVector3<Rt> LerpUnclamped(const TIntVector3<T>& start, const TIntVector3<T>& dest, Rt t);

	/**
	 * Creates a new Vector by the componentwise max of both vectors
	 *
	 * @param(v1) Vector one
	 * @param(v2) Vector two
	 *
	 * @return Vector of componentwise max
	 */

	template<IntType T>
	TIntVector3<T> Max(const TIntVector3<T>& v1, const TIntVector3<T>& v2);

	/**
	 * Creates a new Vector by the componentwise min of both vectors
	 *
	 * @param(v1) Vector one
	 * @param(v2) Vector two
	 *
	 * @return Vector of componentwise min
	 */

	template<IntType T>
	TIntVector3<T> Min(const TIntVector3<T>& v1, const TIntVector3<T>& v2);

	/**
	 * Gets reversed vector.
	 *
	 * @param(v1) Vector one
	 *
	 * @note result is stored in v1.
	 */

	template<IntType T>
	TIntVector3<T> Negate(const TIntVector3<T>& v1);

	/**
	 * Multiplies vector componentwise.
	 *
	 * @param(v1) Vector one
	 * @param(v2) Vector two
	 *
	 * @return Vector with componentwise products
	 */

	template<IntType T>
	TIntVector3<T> Scale(const TIntVector3<T>& v1, const TIntVector3<T>& v2);

	/**
	 * Clamps vector to a range of magnitudes.
	 *
	 * @param(v1) Vector to clamp
	 * @param(min) Min magnitude
	 * @param(max) Max magnitude
	 *
	 * @return Clamped vector
	 */

	template<IntType T, RealType Rt = float>
	TVector3<Rt> ClampMagnitude(const TIntVector3<T>& v1, T min, T max);

	/**
	 * Binds vector into cube.
	 *
	 * @param(v1) Vector to clamp
	 * @param(cubeRadius) Radius of the cube
	 *
	 * @result Vector clamped in cube.
	 */

	template<IntType T, RealType Rt = float>
	TVector3<Rt> BoundToCube(const TIntVector3<T> v1, T cubeRadius) {};

	/**
	 * Clamps vector into cube.
	 *
	 * @param(v1) Vector to clamp
	 * @param(cubeRadius) Radius of the cube
	 *
	 * @result Vector clamped in cube.
	 */

	template<IntType T, RealType Rt = float>
	TVector3<Rt> ClampToCube(const TIntVector3<T> v1, T cubeRadius) {};

	/**
	 * Scales vector two specific magnitude.
	 *
	 * @param(v1) Vector
	 *
	 * @note It's faster to use operator* or operator*= for naturaly normalized vectors.
	 */

	template<IntType T, RealType Rt = float>
	TVector3<Rt> ScaleToMagnitude(const TIntVector3<T>& v1, T magnitude);

	/**
	 * Clamps vector into cube.
	 *
	 * @param(v1) Vector
	 *
	 * @result Vector with inverted components.
	 */

	template<IntType T, RealType Rt = float>
	TVector3<Rt> CompInverse(const TIntVector3<T>& v1);

	/**
	 * Reflect by plane
	 *
	 * @param(v1) Vector to mirror
	 * @param(plane) Plane to mirror on
	 *
	 * @return Mirrored vector
	 */

	template<IntType T, RealType Rt = float>
	FORCEINLINE TVector3<Rt> ReflectFromPlane(const TIntVector3<T>& v1, const TPlane<Rt>& plane);

	/**
	 * Reflect by plane
	 *
	 * @param(v1) Vector to mirror
	 * @param(plane) Normal of plane
	 *
	 * @return Mirrored vector
	 */

	template<IntType T, RealType Rt = float>
	FORCEINLINE TVector3<Rt> ReflectFromPlane(const TIntVector3<T>& v1, const TVector3<Rt>& normal);

	/**
	 * Rotates vector around axis
	 *
	 * @param(v1) Vector to mirror
	 * @param(axisNormal) Axis to rotate around
	 *
	 * @return Rotated vector
	 * @note Calculates vector rotation with Rodrigues-Rotation
	 */

	template<IntType T, RealType Rt = float>
	TVector3<Rt> RotateAroundAxis(const TIntVector3<T>& v1, const TVector3<Rt>& axisNormal, Rt angle);

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
	TIntVector3<T> VectorTriple(const TIntVector3<T>& v1, const TIntVector3<T>& v2, const TIntVector3<T>& v3);

	/**
	 * Projects vector v1 onto v2
	 *
	 * @param(v1) Vector to project
	 * @param(v2) Vector to project on
	 *
	 * @return Projected vector
	 */

	template<IntType T, RealType Rt = float>
	TVector3<Rt> Project(const TIntVector3<T>& v1, const TIntVector3<T>& v2);

	/**
	 * Rejects vector v1 from v2
	 *
	 * @param(v1) Vector to reject
	 * @param(v2) Vector to reject from
	 *
	 * @return Rejected vector
	 */

	template<IntType T, RealType Rt = float>
	TVector3<Rt> Reject(const TIntVector3<T>& v1, const TIntVector3<T>& v2);

	/**
	 * Projects vector onto plane
	 *
	 * @param(v1) Vector to reject
	 * @param(normal) Normal of the plane
	 *
	 * @return Projected vector
	 * @note Simply rejects the vector from normal
	 */

	template<IntType T, RealType Rt = float>
	FORCEINLINE TVector3<Rt> ProjectOntoPlane(const TIntVector3<T>& v1, const TVector3<Rt>& normal);

	/**
	 * Projects vector onto plane
	 *
	 * @param(v1) Vector to reject
	 * @param(normal) Plane
	 *
	 * @return Projected vector
	 * @note Simply rejects the vector from normal
	 */

	template<IntType T, RealType Rt = float>
	FORCEINLINE TVector3<Rt> ProjectOntoPlane(const TIntVector3<T>& v1, const TPlane<Rt>& plane);

	/**
	 * Interpolate vector v1 to desitnation v2 using v1 constant s. The magnitude of the vector stays the same throughout the interpolation.
	 *
	 * @param(v1) Starting vector
	 * @param(v2) Destination vector
	 * @param(t) 0.0 to 1.0 interpolation value
	 *
	 * @return Interpolated unit vector
	 */

	template<IntType T, RealType Rt = float>
	TVector3<Rt> Slerp(const TIntVector3<T>& v1, const TIntVector3<T>& v2, Rt t) {};

	/**
	 * Interpolate vector v1 to desitnation v2 using v1 constant s. The magnitude of the vector stays the same throughout the interpolation.
	 *
	 * @param(v1) Starting vector
	 * @param(v2) Destination vector
	 * @param(t) 0.0 to 1.0 interpolation value
	 *
	 * @return Interpolated unit vector.
	 * @note Does not clamp s between 0.0 and 1.0.
	 */

	template<IntType T, RealType Rt = float>
	TVector3<Rt> SlerpUnclamped(const TIntVector3<T>& v1, const TIntVector3<T>& v2, Rt t) {};

} // phanes::core::math::coretypes

#endif // !INTVECTOR3_H

