#pragma once

#ifdef P_BUILD_LIB
#	include "PhanesEnginePCH.h"
#else
#	include <vector>
#endif

#ifndef MATH_FWD_H
#	define MATH_FWD_H

#	include "Core/Math/Boilerplate.h"
#	include "Core/Math/SIMD/PhanesSIMDTypes.h"

/**
 * Includes forward declarations, as well as certain useful usings.
 * 
 * @ref OSAL/PlatformTypes.h
 */

namespace Phanes::Core::Math
{

	/**
     * Template forward declarations.
     */

	template <RealType T>
	struct TColor;

	template <RealType T>
	struct TLinearColor;

	template <RealType T>
	struct TLine;

	template <RealType T>
	struct TTransform;

	template <RealType T>
	struct TPoint2;

	template <RealType T>
	struct TPoint3;

	template <RealType T>
	struct TPoint4;

	template <IntType T>
	struct TIntPoint2;

	template <IntType T>
	struct TIntPoint3;

	template <IntType T>
	struct TIntPoint4;

	template <RealType T>
	struct TMatrix2;

	template <RealType T, bool S>
	struct TQuaternion;

	template <RealType T, bool S>
	struct TMatrix3;

	template <RealType T, bool S>
	struct TMatrix4;

	template <RealType T, bool S>
	struct TVector2;

	template <RealType T, bool S>
	struct TVector3;

	template <RealType T, bool S>
	struct TVector4;

	template <IntType T, bool S>
	struct TIntVector2;

	template <IntType T, bool S>
	struct TIntVector3;

	template <IntType T, bool S>
	struct TIntVector4;

	template <RealType T, bool S>
	struct TPlane;

	template <RealType T, bool S>
	struct TRay;

	/**
     * Specific instantiation of forward declarations.
     */

	// TPoint2

	using Point2 = TPoint2<float>;
	using Point2f = TPoint2<float>;
	using Point2d = TPoint2<double>;

	// TPoint3

	using Point3 = TPoint3<float>;
	using Point3f = TPoint3<float>;
	using Point3d = TPoint3<double>;

	// TPoint4

	using Point4 = TPoint4<float>;
	using Point4f = TPoint4<float>;
	using Point4d = TPoint4<double>;

	// TIntPoint2

	using IntPoint2 = TIntPoint2<int>;
	using IntPoint2i = TIntPoint2<int>;
	using IntPoint2l = TIntPoint2<long>;

	// TIntPoint3

	using IntPoint3 = TIntPoint3<int>;
	using IntPoint3i = TIntPoint3<int>;
	using IntPoint3l = TIntPoint3<long>;

	// TIntPoint4

	using IntPoint4 = TIntPoint4<int>;
	using IntPoint4i = TIntPoint4<int>;
	using IntPoint4l = TIntPoint4<long>;

	// IntVetor2

	using IntVector2 = TIntVector2<int, false>;
	using Vector2i = TIntVector2<int, false>;
	using LongVector2 = TIntVector2<long, false>;
	using Vector2l = TIntVector2<long, false>;

	// IntVetor3

	using IntVector3 = TIntVector3<int, false>;
	using Vector3i = TIntVector3<int, false>;
	using LongVector3 = TIntVector3<long, false>;
	using Vector3l = TIntVector3<long, false>;

	// IntVetor4

	using IntVector4 = TIntVector4<int, false>;
	using Vector4i = TIntVector4<int, false>;
	using LongVector4 = TIntVector4<long, false>;
	using Vector4l = TIntVector4<long, false>;

	// Vector2

	using Vector2 = TVector2<float, false>;
	using Vector2f = TVector2<float, false>;
	using Vector2d = TVector2<double, false>;

	using Vector2Regf64 = TVector2<double, SIMD::use_simd<double, 2, true>::value>;
	using Vector2Reg = TVector2<double, SIMD::use_simd<double, 2, true>::value>;
	using Vector2Regd = TVector2<double, SIMD::use_simd<double, 2, true>::value>;

	// Vector3

	using Vector3 = TVector3<float, false>;
	using Vector3f = TVector3<float, false>;
	using Vector3d = TVector3<double, false>;

	using Vector3Reg = TVector3<float, SIMD::use_simd<float, 3, true>::value>;
	using Vector3Regf32 = TVector3<float, SIMD::use_simd<float, 3, true>::value>;
	using Vector3Regd = TVector3<double, SIMD::use_simd<double, 3, true>::value>;
	using Vector3Regf64 = TVector3<double, SIMD::use_simd<double, 3, true>::value>;

	// Vector4

	using Vector4 = TVector4<float, false>;
	using Vector4f = TVector4<float, false>;
	using Vector4d = TVector4<double, false>;

	using Vector4Reg = TVector4<float, SIMD::use_simd<float, 4, true>::value>;
	using Vector4Regf32 = TVector4<float, SIMD::use_simd<float, 4, true>::value>;
	using Vector4Regd = TVector4<double, SIMD::use_simd<double, 4, true>::value>;
	using Vector4Regf64 = TVector4<double, SIMD::use_simd<double, 4, true>::value>;

	// Matrix2

	using Matrix2 = TMatrix2<float>;
	using Matrix2f = TMatrix2<float>;
	using Matrix2d = TMatrix2<double>;

	// Matrix3

	using Matrix3 = TMatrix3<float, false>;
	using Matrix3f = TMatrix3<float, false>;
	using Matrix3d = TMatrix3<double, false>;

	using Matrix3Reg = TMatrix3<float, SIMD::use_simd<float, 3, true>::value>;
	using Matrix3Regf = TMatrix3<float, SIMD::use_simd<float, 3, true>::value>;
	using Matrix3Regd = TMatrix3<double, SIMD::use_simd<double, 3, true>::value>;
	using Matrix3Regf64 = TMatrix3<double, SIMD::use_simd<double, 3, true>::value>;

	// Matrix4

	using Matrix4 = TMatrix4<float, false>;
	using Matrix4f = TMatrix4<float, false>;
	using Matrix4d = TMatrix4<double, false>;

	using Matrix4Reg = TMatrix3<float, SIMD::use_simd<float, 4, true>::value>;
	using Matrix4Regf = TMatrix3<float, SIMD::use_simd<float, 4, true>::value>;
	using Matrix4Regd = TMatrix3<double, SIMD::use_simd<double, 4, true>::value>;
	using Matrix4Regf64 = TMatrix3<double, SIMD::use_simd<double, 4, true>::value>;

	// TPlane

	using Plane = TPlane<float, false>;
	using Planef = TPlane<float, false>;
	using Planed = TPlane<double, false>;

	using PlaneReg = TPlane<float, SIMD::use_simd<float, 4, true>::value>;
	using PlaneRegd = TPlane<float, SIMD::use_simd<double, 4, true>::value>;

} // namespace Phanes::Core::Math

namespace Phanes::Core::Math::Internal
{

	// Internal types

	template <typename T, unsigned int D>
	struct AVector;

	template <typename T, unsigned int n, unsigned int>
	struct AMatrix;
} // namespace Phanes::Core::Math::Internal

#endif // !MATH_FWD_H
