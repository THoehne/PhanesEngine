#pragma once

#include "Core/Math/Boilerplate.h"

#include "Core/Math/MathFwd.h"
#include "Core/Math/SIMD/PhanesSIMDTypes.h"
#include "Core/Math/SIMD/Storage.h"
#include "Core/Math/Vector3.hpp"
#include "Core/Math/Vector4.hpp"

#ifndef QUATERNION_H
#	define QUATERNION_H

namespace Phanes::Core::Math
{
	// Quaternion
	template <RealType T, bool S>
	struct TQuaternion
	{
		using Real = T;

	public:
		union
		{
			struct
			{
				float x;
				float y;
				float z;
				float w;
			};
			union
			{
				typename SIMD::Storage<4, Real, SIMD::use_simd<Real, 4, S>::value>::type comp;
				typename SIMD::Storage<4, Real, SIMD::use_simd<Real, 4, S>::value>::type data;
			};
		};

	public:
		/// Default constructor
		TQuaternion() = default;

		/**
		 * Construct quaternion from vector4.
		 * v.w is the scalar part of the quaternion (q.w).
		 */
		explicit TQuaternion(const TVector4<T, S>& v);

		/**
		 * Construct quaternion from vector (x,y,z) and scalar part (w).
		 *
		 * @param x X
		 * @param y Y
		 * @param z Z
		 * @param w W
		 */
		TQuaternion(Real x, Real y, Real z, Real w);

		/**
		 * Construct vector from vector part and scalar part.
		 */
		TQuaternion(const TVector3<Real, S>& v, Real w);

		/**
		 * Construct quaternion from array of length >= four.
		 *
		 * @note If used with SIMD the array will is assumed to be aligned.
		 */
		explicit TQuaternion(const Real* comp);

		/**
		 * Construct from euler angles (yaw, pitch, roll)
		 */
		explicit TQuaternion(const TVector3<Real, S>& euler_angels);

		/**
		 * Construct from Transformation
		 */

		explicit TQuaternion(const TTransform<Real>& t);
		explicit TQuaternion(const TMatrix4<Real, S>& t);
	};
} // namespace Phanes::Core::Math

#endif // QUATERNION_H
