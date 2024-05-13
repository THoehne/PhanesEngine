#pragma once


#include "Core/public/Math/MathCommon.h"
#include "Core/public/Math/MathAbstractTypes.h"
#include "Core/public/Math/MathFwd.h"

#pragma warning(disable : 4244)

#ifdef P_USE_MATH_CONSTANTS


#endif // P_USE_MATH_CONSTANTS

#ifndef VECTOR4_H
#define VECTOR4_H


namespace phanes {

	namespace core {

		namespace math {

			namespace coretypes {

				// Basis 4D Vector (x, y, z, w)

				template<typename T>
				struct Vector4 {
				public:
					float x, y, z, w;
				};

				// List of Vector3 for DoP and ECS
				typedef std::vector<Vector4<T>> Vector4List;


				Vector4 createVector(float x, float y, float z, float w);


				// ===================== //
				//   Vector4 operators   //
				// ===================== //

				void	operator+= (Vector4& a, float s);
				void operator+= (Vector4& a, const Vector4& b);

				void operator-= (Vector4& a, float s);
				void operator-= (Vector4& a, const Vector4& b);

				void operator*= (Vector4& a, float s);

				void operator/= (Vector4& a, float s);

				Vector4 operator* (const Vector4& a, float s);

				Vector4 operator/ (const Vector4& a, float s);

				Vector4 operator* (float s, const Vector4& a);

				Vector4 operator/ (float s, const Vector4& a);

				// Vector4 dot-product
				float operator* (const Vector4& a, const Vector4& b);

				Vector4 operator+ (const Vector4& a, float s);
				Vector4 operator+ (const Vector4& a, const Vector4& b);

				Vector4 operator- (const Vector4& a, float s);
				Vector4 operator- (const Vector4& a, const Vector4& b);

				void operator- (Vector4& a);

				bool operator== (const Vector4& a, const Vector4& b);


				// ==================================== //
				//    Vector4 function implementation	//
				// ==================================== //

				float magnitude(const Vector4& a);

				float sqrMagnitude(const Vector4& a);

				void normalizeNR(Vector4& a);

				float angle(const Vector4& a, const Vector4& b);

				// dot product between two FVector3. Does the same as operator*
				float dotP(const Vector4& a, const Vector4& b);

				void scaleToMagnitude(Vector4& a, float magnitude);

				bool equals(const Vector4& a, const Vector4& b, float threshold);

				void Set(Vector4& a, const Vector4& b);

				void perpspectiveDivideNR(Vector4& a);

				void maxNR(Vector4& a, const Vector4& b);

				void minNR(Vector4& a, const Vector4& b);

				void scaleNR(Vector4& a, const Vector4& b);

				void orthogonolize(Vector4& a, Vector4& b, Vector4& c);

				void orthoNormalize(Vector4& a, Vector4& b, Vector4& c);

				// projects vector a onto vector b
				void projectNR(Vector4& a, const Vector4& b);

				// rejects vector a from vector b
				void rejectNR(Vector4& a, const Vector4& b);


				// ============ //
				// WITH RETURN: //
				// ============ //

				Vector4 lerp(const Vector4& a, const Vector4& b, float t);

				Vector4 lerpUnclamped(const Vector4& a, const Vector4& b, float t);

				Vector4 slerp(const Vector4& a, const Vector4& b, float t);

				Vector4 slerpUnclamped(const Vector4& a, const Vector4& b, float t);

				Vector4 max(const Vector4& a, const Vector4& b);

				Vector4 min(const Vector4& a, const Vector4& b);

				Vector4 scale(const Vector4& a, const Vector4& b);

				Vector4 perpspectiveDivide(const Vector4& a);

				Vector4 normalize(const Vector4& a);
				
				// projects vector a onto vector b
				Vector4 project(const Vector4& a, const Vector4& b);

				// rejects vector a from vector b
				Vector4 reject(const Vector4& a, const Vector4& b);

			} // phanes::core::math::coretypes

		} // phanes::core::math

	} // phanes::core

} // phanes


#endif // !VECTOR4_H